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

#ifndef MyHTML_MyCSS_DECLARATION_SERIALIZATION_RESOURCES_H
#define MyHTML_MyCSS_DECLARATION_SERIALIZATION_RESOURCES_H
#pragma once

static mycss_declaration_serialization_f mycss_declaration_serialization_map_by_type[] = 
{
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_background,
	mycss_declaration_serialization_type_list,
	mycss_declaration_serialization_type_list,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_background_image,
	mycss_declaration_serialization_type_list,
	mycss_declaration_serialization_background_position,
	mycss_declaration_serialization_background_repeat,
	mycss_declaration_serialization_background_size,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_two_type,
	mycss_declaration_serialization_shorthand_two_type,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_border_radius,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_border_x,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_two_type,
	mycss_declaration_serialization_shorthand_two_type,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_font,
	mycss_declaration_serialization_font_family,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_shorthand_four,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_text_decoration,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_text_decoration_line,
	mycss_declaration_serialization_text_decoration_skip,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef,
	mycss_declaration_serialization_undef
};


#endif /* MyHTML_MyCSS_DECLARATION_SERIALIZATION_RESOURCES_H */
