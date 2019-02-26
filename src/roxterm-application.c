/*
    roxterm - VTE/GTK terminal emulator with tabs
    Copyright (C) 2019 Tony Houghton <h@realh.co.uk>

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#include "roxterm-application.h"

#define ROXTERM_APPLICATION_ID "uk.co.realh.roxterm"

struct _RoxtermApplication {
    GtkApplication parent_instance;
};

G_DEFINE_TYPE(RoxtermApplication, roxterm_application, GTK_TYPE_APPLICATION);

static void roxterm_application_window_removed(GtkApplication *app,
        GtkWindow *win)
{
    GTK_APPLICATION_CLASS(roxterm_application_parent_class)
            ->window_removed(app, win);
    if (!gtk_application_get_windows(app))
        g_application_quit(G_APPLICATION(app));
}

static void roxterm_application_class_init(RoxtermApplicationClass *klass)
{
    GtkApplicationClass *gapp_klass = GTK_APPLICATION_CLASS(klass);
    gapp_klass->window_removed = roxterm_application_window_removed;
}

static void roxterm_application_init(RoxtermApplication *self)
{
    (void) self;
}

RoxtermApplication *roxterm_application_new(void)
{
    GObject *obj = g_object_new(ROXTERM_TYPE_APPLICATION,
            "application-id", ROXTERM_APPLICATION_ID,
            "flags", G_APPLICATION_HANDLES_COMMAND_LINE
                | G_APPLICATION_SEND_ENVIRONMENT,
            NULL);
    return ROXTERM_APPLICATION(obj);
}

RoxtermWindow *roxterm_application_new_window(RoxtermApplication *app)
{
    RoxtermWindow *win = roxterm_window_new(app);
    gtk_application_add_window(GTK_APPLICATION(app), GTK_WINDOW(win));
}