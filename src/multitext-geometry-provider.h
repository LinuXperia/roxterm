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

#ifndef __MULTITEXT_GEOMETRY_PROVIDER_H
#define __MULTITEXT_GEOMETRY_PROVIDER_H

#include <glib-object.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define MULTITEXT_TYPE_GEOMETRY_PROVIDER multitext_geometry_provider_get_type()
G_DECLARE_INTERFACE (MultitextGeometryProvider, multitext_geometry_provider,
        MULTITEXT, GEOMETRY_PROVIDER, GtkWidget)

/**
 * MultitextGeometryProvider:
 *
 * A widget containing text with fixed-width characters that determines the
 * size of the window, or a container for such a widget.
 */
struct _MultitextGeometryProviderInterface
{
    GTypeInterface parent_iface;
    /**
     * MultitextGeometryProviderInterface::get_initial_size:
     *
     * @columns: (out):
     * @rows: (out):
     */
    void (*get_initial_size)(MultitextGeometryProvider *self,
            int *columns, int *rows);
    /**
     * MultitextGeometryProviderInterface::get_current_size:
     *
     * @columns: (out):
     * @rows: (out):
     */
    void (*get_current_size)(MultitextGeometryProvider *self,
            int *columns, int *rows);
    /**
     * MultitextGeometryProviderInterface::get_padding:
     *
     * @width: (out):
     * @height: (out):
     */
    void (*get_padding)(MultitextGeometryProvider *self,
            int *width, int *height);
    /**
     * MultitextGeometryProviderInterface::get_cell_size:
     *
     * @width: (out):
     * @height: (out):
     */
    void (*get_cell_size)(MultitextGeometryProvider *self,
            int *width, int *height);
};

/**
 * multitext_geometry_provider_get_initial_size:
 *
 * Gets the size, in characters, the widget wants to be eg when opening a new
 * window
 *
 * @columns: (out):
 * @rows: (out):
 */
void
multitext_geometry_provider_get_initial_size(MultitextGeometryProvider *self,
        int *columns, int *rows);

/**
 * multitext_geometry_provider_get_current_size:
 *
 * Gets the size, in characters, the widget is at the moment
 *
 * @columns: (out):
 * @rows: (out):
 */
void
multitext_geometry_provider_get_current_size(MultitextGeometryProvider *self,
        int *columns, int *rows);

/**
 * multitext_geometry_provider_get_padding:
 *
 * Get the total size, in pixels, of any additional parts of the widget
 * eg borders
 * 
 * @width: (out):
 * @height: (out):
 */
void multitext_geometry_provider_get_padding(MultitextGeometryProvider *self,
        int *width, int *height);

/**
 * multitext_geometry_provider_get_cell_size:
 *
 * Get the size of each text cell in pixels
 *
 * @width: (out):
 * @height: (out):
 */
void
multitext_geometry_provider_get_cell_size(MultitextGeometryProvider *self,
        int *width, int *height);


#endif /* __MULTITEXT_GEOMETRY_PROVIDER_H */