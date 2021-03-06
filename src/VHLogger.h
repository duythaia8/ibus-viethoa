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
#ifndef __VH_LOGGER_H__
#define __VH_LOGGER_H__

// maximum size of the log file
#define __VH_MAX_LOGGER_FILE_SIZE__ 7 * 1024 * 1024 
#include <glib.h>

// mở tập tin log
gboolean vh_logger_open();

// ghi một chuỗi vào tập tin log
void vh_logger_write(const gchar* str);

// write an info string to opening log file
void vh_logger_log(const gchar* format_str, ...);

// write a warning string to opening log file
void vh_logger_warn(const gchar* format_str, ...);

// write an error string to opening log file
void vh_logger_error(const gchar* format_str, ...);

// close the log file
void vh_logger_close();

// reset log file if its size exceeds limit
void vh_logger_backup();

#endif
