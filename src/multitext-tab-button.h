/*
    roxterm4 - VTE/GTK terminal emulator with tabs
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

#ifndef __MULTITEXT_TAB_BUTTON_H
#define __MULTITEXT_TAB_BUTTON_H

#include <glib-object.h>
#include <gtk/gtk.h>

#define MULTITEXT_TYPE_TAB_BUTTON multitext_tab_button_get_type()
G_DECLARE_DERIVABLE_TYPE(MultitextTabButton, multitext_tab_button,
        MULTITEXT, TAB_BUTTON, GtkButton);

struct _MultitextTabButtonClass
{
    GtkButtonClass parent_class;
};

GtkWidget *
multitext_tab_button_new(void);

/* By default it shows a close icon */
void multitext_tab_button_show_close_icon(MultitextTabButton *self);

void
multitext_tab_button_set_pixbuf(MultitextTabButton *btn, GdkPixbuf *pixbuf);

#endif /* __MULTITEXT_TAB_BUTTON_H */