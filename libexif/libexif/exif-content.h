/* exif-content.h
 *
 * Copyright (C) 2001 Lutz M�ller <lutz@users.sourceforge.net>
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

#ifndef __EXIF_CONTENT_H__
#define __EXIF_CONTENT_H__

typedef struct _ExifContent        ExifContent;
typedef struct _ExifContentPrivate ExifContentPrivate;

#include <libexif/exif-tag.h>
#include <libexif/exif-entry.h>
#include <libexif/exif-utils.h>

struct _ExifContent {
	ExifByteOrder order;

        ExifEntry **entries;
        unsigned int count;

	ExifEntry *parent;

	ExifContentPrivate *priv;
};

/* Lifecycle */
ExifContent *exif_content_new   (void);
void         exif_content_ref   (ExifContent *content);
void         exif_content_unref (ExifContent *content);
void         exif_content_free  (ExifContent *content);

/* Notification */
typedef enum _ExifContentEvent ExifContentEvent;
enum _ExifContentEvent {
	EXIF_CONTENT_EVENT_ADD    = 1 << 0,
	EXIF_CONTENT_EVENT_REMOVE = 1 << 1
};
typedef void (* ExifContentNotifyFunc)  (ExifContent *content,
					 ExifEntry *entry, void *data);
unsigned int exif_content_add_notify    (ExifContent *content,
					 ExifContentEvent events,
					 ExifContentNotifyFunc func,
					 void *data);
void         exif_content_remove_notify (ExifContent *content,
					 unsigned int id);

void         exif_content_parse (ExifContent *content,
				 const unsigned char *data,
				 unsigned int size,
				 unsigned int offset, ExifByteOrder order);

void         exif_content_add_entry    (ExifContent *content, ExifEntry *e);
void         exif_content_remove_entry (ExifContent *content, ExifEntry *e);
ExifEntry   *exif_content_get_entry    (ExifContent *content, ExifTag tag);

void         exif_content_dump  (ExifContent *content, unsigned int indent);

#endif /* __EXIF_CONTENT_H__ */
