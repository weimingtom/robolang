#ifndef _ROBOT_LABIRINTH_H_
#define _ROBOT_LABIRINTH_H_ 1

#include <glib-object.h>
#include "robot_sprite.h"

G_BEGIN_DECLS

/* Type conversion macroses: */
#define ROBOT_TYPE_LABIRINTH                   (robot_labirinth_get_type())
#define ROBOT_LABIRINTH(obj)                   (G_TYPE_CHECK_INSTANCE_CAST((obj),  ROBOT_TYPE_LABIRINTH, RobotLabirinth))
#define ROBOT_IS_LABIRINTH(obj)                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), ROBOT_TYPE_LABIRINTH))
#define ROBOT_LABIRINTH_CLASS(klass)           (G_TYPE_CHECK_CLASS_CAST ((klass),  ROBOT_TYPE_LABIRINTH, RobotLabirinthClass))
#define ROBOT_IS_LABIRINTH_CLASS(klass)        (G_TYPE_CHECK_CLASS_TYPE ((klass),  ROBOT_TYPE_LABIRINTH))
#define ROBOT_LABIRINTH_GET_CLASS(obj)         (G_TYPE_INSTANCE_GET_CLASS ((obj),  ROBOT_TYPE_LABIRINTH, RobotLabirinthClass))

/* get_type prototype: */
GType robot_labirinth_get_type(void);

/** Each sell could be free to go or the wall. */
typedef guint RobotLabirinthCell;

/* Structures definitions: */
typedef struct _RobotLabirinth RobotLabirinth;
typedef struct _RobotLabirinthClass RobotLabirinthClass;
typedef struct _RobotLabirinthPrivate RobotLabirinthPrivate;

struct _RobotLabirinth {
	GObject parent_instance;

	RobotLabirinthPrivate *priv;
};

struct _RobotLabirinthClass {
	GObjectClass parent_class;
};

RobotLabirinth* robot_labirinth_new(void);
void robot_labirinth_set_rect(RobotLabirinth *self, const SDL_Rect *rect);
void robot_labirinth_set_size(RobotLabirinth *self, guint width, guint height);
RobotLabirinthCell robot_labirinth_get_cell(RobotLabirinth *self, guint x, guint y);
gboolean robot_labirinth_is_wall(RobotLabirinth *self, RobotLabirinthCell cell);
gboolean robot_labirinth_is_exit(RobotLabirinth *self, RobotLabirinthCell cell);
gboolean robot_labirinth_can_walk(RobotLabirinth *self, guint x, guint y);
void robot_labirinth_set_cell(RobotLabirinth *self, guint x, guint y, RobotLabirinthCell cell);
gboolean robot_labirinth_load(RobotLabirinth *self, const char *filename, SDL_Renderer *renderer, GError **error);
void robot_labirinth_set_sprite_for_cell(RobotLabirinth *self, guint cell, RobotSprite *sprite);
void robot_labirinth_render(RobotLabirinth *self, SDL_Renderer *renderer);
gboolean robot_labirinth_is_finish(RobotLabirinth *self);

/* Robot commands (Thread-safe): */

gboolean robot_labirinth_check(RobotLabirinth *self);
gboolean robot_labirinth_walk(RobotLabirinth *self);
gboolean robot_labirinth_rotate_left(RobotLabirinth *self);
gboolean robot_labirinth_rotate_right(RobotLabirinth *self);

gboolean robot_labirinth_is_done(RobotLabirinth *self);
gboolean robot_labirinth_get_result(RobotLabirinth *self);

G_END_DECLS

#endif /* ROBOT_LABIRINTH_H */
