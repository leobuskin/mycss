/*
 Copyright (C) 2016 Alexander Borisov
 
 This library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 This library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with this library; if not, write to the Free Software
 Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 
 Author: lex.borisov@gmail.com (Alexander Borisov)
*/

#include "mycss/entry.h"
#include "mycss/selectors/function_resource.h"

mycss_entry_t * mycss_entry_create(void)
{
    return (mycss_entry_t*)myhtml_calloc(1, sizeof(mycss_entry_t));
}

mycss_status_t mycss_entry_init(mycss_t* mycss, mycss_entry_t* entry)
{
    entry->mycss           = mycss;
    entry->parser          = mycss_parser_token;
    entry->parser_switch   = mycss_parser_token;
    entry->parser_original = NULL;
    entry->parser_state    = NULL;
    
    // Other init
    entry->mchar = mchar_async_create(128, (4096 * 5));
    entry->mchar_node_id = mchar_async_node_add(entry->mchar);
    entry->mchar_value_node_id = mchar_async_node_add(entry->mchar);
    
    /* String Entries */
    entry->mcobject_string_entries = mcobject_create();
    if(entry->mcobject_string_entries == NULL)
        return MyCSS_STATUS_ERROR_STRING_CREATE;
    
    myhtml_status_t myhtml_status = mcobject_init(entry->mcobject_string_entries, 256, sizeof(myhtml_string_t));
    if(myhtml_status)
        return MyCSS_STATUS_ERROR_STRING_INIT;
    
    /* Selectors */
    entry->selectors = mycss_selectors_create();
    if(entry->selectors == NULL)
        return MyCSS_STATUS_ERROR_SELECTORS_CREATE;
    
    mycss_status_t status = mycss_selectors_init(entry, entry->selectors);
    if(status != MyCSS_STATUS_OK)
        return status;
    
    /* Namespace */
    entry->ns = mycss_namespace_create();
    if(entry->ns == NULL)
        return MyCSS_STATUS_ERROR_NAMESPACE_CREATE;
    
    status = mycss_namespace_init(entry, entry->ns);
    if(status != MyCSS_STATUS_OK)
        return status;
    
    /* Rules */
    entry->rules = mycss_rules_create();
    if(entry->rules == NULL)
        return MyCSS_STATUS_ERROR_RULES_CREATE;
    
    status = mycss_rules_init(entry, entry->rules);
    if(status != MyCSS_STATUS_OK)
        return status;
    
    /* Media */
    entry->media = mycss_media_create();
    if(entry->media == NULL)
        return MyCSS_STATUS_ERROR_RULES_CREATE;
    
    status = mycss_media_init(entry, entry->media);
    if(status != MyCSS_STATUS_OK)
        return status;
    
    /* An+B */
    entry->anb = mycss_an_plus_b_create();
    if(entry->ns == NULL)
        return MyCSS_STATUS_ERROR_AN_PLUS_B_CREATE;
    
    status = mycss_an_plus_b_init(entry, entry->anb);
    if(status != MyCSS_STATUS_OK)
        return status;
        
    /* Incoming Buffer */
    entry->mcobject_incoming_buffer = mcobject_create();
    if(entry->mcobject_incoming_buffer == NULL)
        return MyCSS_STATUS_ERROR_ENTRY_INCOMING_BUFFER_CREATE;
    
    myhtml_status = mcobject_init(entry->mcobject_incoming_buffer, 256, sizeof(myhtml_incoming_buffer_t));
    if(myhtml_status)
        return MyCSS_STATUS_ERROR_ENTRY_INCOMING_BUFFER_INIT;
    
    /* callbacks */
    entry->token_ready_callback = mycss_parser_token_ready_callback_function;
    
    return MyCSS_STATUS_OK;
}

mycss_status_t mycss_entry_clean_all(mycss_entry_t* entry)
{
    mcobject_clean(entry->mcobject_incoming_buffer);
    mchar_async_node_clean(entry->mchar, entry->mchar_node_id);
    mchar_async_node_clean(entry->mchar, entry->mchar_value_node_id);
    
    mcobject_clean(entry->mcobject_string_entries);
    
    /* CSS Modules */
    mycss_selectors_clean_all(entry->selectors);
    mycss_namespace_clean_all(entry->ns);
    mycss_rules_clean_all(entry->rules);
    mycss_media_clean_all(entry->media);
    mycss_an_plus_b_clean_all(entry->anb);
    
    entry->parser               = mycss_parser_token;
    entry->parser_switch        = mycss_parser_token;
    entry->parser_original      = NULL;
    entry->parser_state         = NULL;
    entry->token                = NULL;
    entry->state                = MyCSS_TOKENIZER_STATE_DATA;
    entry->state_back           = MyCSS_TOKENIZER_STATE_DATA;
    entry->first_buffer         = NULL;
    entry->current_buffer       = NULL;
    entry->token_counter        = 0;
    entry->help_counter         = 0;
    entry->type                 = MyCSS_ENTRY_TYPE_CLEAN;
    
    if(entry->token) {
        myhtml_free(entry->token);
        entry->token = NULL;
    }
    
    return MyCSS_STATUS_OK;
}

mycss_entry_t * mycss_entry_destroy(mycss_entry_t* entry, bool self_destroy)
{
    if(entry == NULL)
        return NULL;
    
    entry->mchar = mchar_async_destroy(entry->mchar, 1);
    entry->mcobject_string_entries = mcobject_destroy(entry->mcobject_string_entries, true);
    
    /* CSS Modules */
    entry->selectors = mycss_selectors_destroy(entry->selectors, true);
    entry->ns        = mycss_namespace_destroy(entry->ns, true);
    entry->rules     = mycss_rules_destroy(entry->rules, true);
    entry->media     = mycss_media_destroy(entry->media, true);
    entry->anb       = mycss_an_plus_b_destroy(entry->anb, true);
    
    entry->mcobject_incoming_buffer = mcobject_destroy(entry->mcobject_incoming_buffer, true);
    
    if(entry->token) {
        myhtml_free(entry->token);
        entry->token = NULL;
    }
    
    if(self_destroy) {
        myhtml_free(entry);
        return NULL;
    }
    
    return entry;
}

void mycss_entry_end(mycss_entry_t* entry)
{
    mycss_selectors_end(entry->stylesheet->sel_list_last, entry->selectors, false);
}

mycss_selectors_list_t * mycss_entry_get_parent_set_parser(mycss_entry_t* entry, mycss_selectors_list_t* selectors_list)
{
    if(selectors_list->parent == NULL) {
        if(entry->parser != mycss_parser_token)
            entry->parser = mycss_parser_token;
        
        if(entry->parser_switch != mycss_parser_token)
            entry->parser_switch = mycss_parser_token;
        
        return selectors_list;
    }
    
    selectors_list = selectors_list->parent;
    
    if(selectors_list->parent) {
        mycss_selectors_entry_t* selector = selectors_list->parent->selector;
        
        if(selector->type == MyCSS_SELECTORS_TYPE_PSEUDO_CLASS_FUNCTION) {
            const mycss_selectors_function_index_t *findex = &mycss_selectors_function_parser_map_by_sub_type[ selector->sub_type ];
            
            entry->parser = findex->parser;
            entry->parser_switch = findex->switch_parser;
        }
        else {
            entry->parser = mycss_parser_token;
            entry->parser_switch = mycss_parser_token;
        }
    }
    else {
        if(entry->parser != mycss_parser_token)
            entry->parser = mycss_parser_token;
        
        if(entry->parser_switch != mycss_parser_token)
            entry->parser_switch = mycss_parser_token;
    }
    
    return selectors_list;
}

myhtml_string_t * mycss_entry_string_create_and_init(mycss_entry_t* entry, size_t string_size)
{
    myhtml_string_t *str = mcobject_malloc(entry->mcobject_string_entries, NULL);
    
    if(str == NULL)
        return NULL;
    
    myhtml_string_init(entry->mchar, entry->mchar_node_id, str, (string_size + 1));
    
    return str;
}

/* Print */

void mycss_entry_print(mycss_entry_t* entry, mycss_selectors_list_t* selectors_list, FILE* fh)
{
    while(selectors_list) {
        for(size_t i = 0; i < selectors_list->selector_list_length; i++) {
            mycss_selectors_print_chain(entry->selectors, selectors_list->selector_list[i], fh);
            
            if((i + 1) != selectors_list->selector_list_length)
                fprintf(fh, ", ");
        }
        
        if(selectors_list->next)
            fprintf(fh, " {}\n");
        
        selectors_list = selectors_list->next;
    }
}

mycss_token_ready_callback_f mycss_entry_token_ready_callback(mycss_entry_t* entry, mycss_token_ready_callback_f callback_f)
{
    if(callback_f)
        entry->token_ready_callback = callback_f;
    
    return entry->token_ready_callback;
}

size_t mycss_entry_token_count(mycss_entry_t* entry)
{
    return entry->token_counter;
}

myhtml_incoming_buffer_t * mycss_entry_incoming_buffer_current(mycss_entry_t* entry)
{
    return entry->current_buffer;
}

myhtml_incoming_buffer_t * mycss_entry_incoming_buffer_first(mycss_entry_t* entry)
{
    return entry->first_buffer;
}

mycss_stylesheet_t * mycss_entry_stylesheet(mycss_entry_t* entry)
{
    return entry->stylesheet;
}


