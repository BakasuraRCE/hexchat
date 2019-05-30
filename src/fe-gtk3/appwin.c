/* HexChat
 * Copyright (C) 2019 Nahuel Gomez Castro
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <gtk/gtk.h>

#include "app.h"
#include "appwin.h"

struct _HexChatAppWindow
{
	GtkApplicationWindow parent;
};

G_DEFINE_TYPE(HexChatAppWindow, hex_chat_app_window, GTK_TYPE_APPLICATION_WINDOW);

static void
hex_chat_app_window_init (HexChatAppWindow *win)
{
	
}

static void
hex_chat_app_window_class_init (HexChatAppWindowClass *class)
{
	
}

HexChatAppWindow *
hex_chat_app_window_new (HexChatApp *app)
{
	return g_object_new (HEX_CHAT_APP_WINDOW_TYPE, "application", app, NULL);
}
