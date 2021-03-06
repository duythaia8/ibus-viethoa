/*
 * ibus-viethoa - The Viethoa engine for IBus
 *
 * Copyright (c) 2020-2021 Duy Thai, ngocduy.thai@yahoo.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA.
 */
#ifndef _VH_PROPERTY_LIST_H_
#define _VH_PROPERTY_LIST_H_

#include "engine.h"

void vh_property_list_init();
void vh_property_list_destroy();
void vh_property_list_load();
void vh_property_list_register(IBusViethoaEngine* viethoa);
void vh_property_list_update(IBusViethoaEngine* viethoa);
void vh_property_list_update_symbol(IBusViethoaEngine* viethoa);

#endif
