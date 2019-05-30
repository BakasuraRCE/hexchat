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

struct _HexChatApp
{
	GtkApplication parent;
};

G_DEFINE_TYPE(HexChatApp, hex_chat_app, GTK_TYPE_APPLICATION);

static void
hex_chat_app_init (HexChatApp *app)
{

}

static void
hex_chat_app_activate (GApplication *app)
{
	HexChatAppWindow *win;

	win = hex_chat_app_window_new (HEX_CHAT_APP (app));
	gtk_window_present (GTK_WINDOW (win));
}

static void
hex_chat_app_class_init (HexChatAppClass *class)
{
	G_APPLICATION_CLASS (class)->activate = hex_chat_app_activate;
}

HexChatApp *
hex_chat_app_new (void)
{
	return g_object_new (HEX_CHAT_APP_TYPE,
						 "application-id", "io.irc.hexchat",
						 "flags", G_APPLICATION_FLAGS_NONE,
						 NULL);
}
