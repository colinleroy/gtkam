/* gtkam-list.h
 *
 * Copyright (C) 2001 Lutz M�ller <urc8@rz.uni-karlsruhe.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details. 
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTKAM_LIST_H__
#define __GTKAM_LIST_H__

#include <gphoto2/gphoto2-camera.h>
#include <gtkiconlist.h>

#define GTKAM_TYPE_LIST  (gtkam_list_get_type ())
#define GTKAM_LIST(o)    (GTK_CHECK_CAST((o),GTKAM_TYPE_LIST,GtkamList))
#define GTKAM_IS_LIST(o) (GTK_CHECK_TYPE((o),GTKAM_TYPE_LIST))

typedef struct _GtkamList        GtkamList;
typedef struct _GtkamListPrivate GtkamListPrivate;
typedef struct _GtkamListClass   GtkamListClass;

struct _GtkamList
{
	GtkIconList parent;

	GtkamListPrivate *priv;
};

struct _GtkamListClass
{
	GtkIconListClass parent_class;
};

GtkType    gtkam_list_get_type (void);
GtkWidget *gtkam_list_new      (void);

void       gtkam_list_set_camera     (GtkamList *list, Camera *camera);
void       gtkam_list_set_path       (GtkamList *list, const gchar *path);
void       gtkam_list_set_thumbnails (GtkamList *list, gboolean thumbnails);

void       gtkam_list_save_selected  (GtkamList *list);
void       gtkam_list_refresh        (GtkamList *list);

#endif /* __GTKAM_LIST_H__ */
