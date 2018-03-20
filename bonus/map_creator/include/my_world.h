/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** My world header
*/

#ifndef MY_WORLD_2017
	#define MY_WORLD_2017

/* INCLUDES */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include "my.h"
#include "rpg.h"

typedef sfVector2f v2f;
typedef sfVector2i v2i;

struct map_draw_s;
struct camera_s;
struct textures_s;

/* STUCTURE */
typedef struct ressources_s {
	sfRenderWindow *window;
	sfVideoMode mode;
	struct map_draw_s *map;
	struct camera_s *cam;
	struct textures_s *textures;
	struct sound_s *sounds;
	struct gui_s *gui;
	my_w_t *init;
} ressources_t;

typedef struct textures_s {
	sfTexture *grass;
	sfTexture *stone;
	sfTexture *dirt;
	sfTexture *panel;
	sfTexture *editing_panel;
	sfTexture *background;
} textures_t;

typedef struct menu_s {
	int state;
	sfRectangleShape *rec;
	sfSprite *sprite;
	sfTexture *texture;
	sfVector2f pos;
	struct menu_s *next;
} menu_t;

typedef struct gui_s {
	sfSprite *background;
	sfSprite *panel;
	sfSprite *editing_panel;
	bool grid;
	int mode;
	bool click;
} gui_t;

typedef struct tile_coord_s {
	v2i first_point;
	v2i second_point;
	v2i third_point;
	v2i fourth_point;
} tile_coord_t;

typedef struct map_draw_s {
	float **height_map;
	v2f **points_2d;
	v2i size;
	v2i selected_point;
	struct tile_coord_s selected_tile;
} map_draw_t;

typedef struct camera_s {
	float x;
	float y;
	v2f scale;
} camera_t;

typedef struct sound_s {
	sfMusic *pop;
} sound_t;

#define V2F(x, y) (sfVector2f) {(float) x, (float) y}
#define V2I(x, y) (sfVector2i) {(int) x, (int) y}

/* PROTOTYPES */

char *int_to_str(int);

/// Event handler
/// \param rsces
/// \param event
void on_event(ressources_t *rsces, sfEvent event);

/// create a ressource structure
/// \return ressources_t
ressources_t *create_ressources(void);

/// create a sfRenderWindow object (modify ressources)
/// \param rsces
/// \return the window
sfRenderWindow *create_window(ressources_t *rsces);

/// start the main loop
/// \param rsces
void main_loop(ressources_t *rsces);

/// create a line
/// \param point_1 first point of the line
/// \param point_2 second point of the line
/// \param color color of the line
/// \return sfVertexArray of the line
sfVertexArray *create_line(sfVector2f *point_1, sfVector2f *point_2,
			   sfColor color);

/// create a 4-side polygon
/// \param p_1 first point
/// \param p_2 second point
/// \param p_3 third point
/// \param p_4 fourth point
/// \return sfVertexArray
sfVertexArray *create_poly(v2f *p_1, v2f *p_2, v2f *p_3, v2f *p_4);

/// malloc a float 2d map and put it in a map_draw_t structure
/// \param x size in x
/// \param y size in y
/// \return map_draw_t
map_draw_t *generate_float_map(int x, int y);

/// project 3d point to 2d screen space in isometric
/// \param rsces ressouces
/// \param x position in x
/// \param y position in y
/// \param z position in z
/// \return sfVector2f position in screen
sfVector2f project_iso_point(ressources_t *rsces, float x, float y, float z);

/// convert map to 2d screen space map
/// \param rsces
/// \param map
/// \return sfVector2f**
sfVector2f **create_2d_map(ressources_t *rsces, map_draw_t *map);

/// draw the map
/// \param rsces
/// \param map map_draw_t
/// \param window renderWindow
void draw_map(ressources_t *rsces, map_draw_t *map, sfRenderWindow *window);

/// create a camera
/// \param x angle x
/// \param y angle y
/// \return camera_t
camera_t *create_camera(float x, float y);

/// free a 2d map
/// \param rsces
/// \param map
void free_2d_v2f_map(ressources_t *rsces, sfVector2f **map);

/// draw a quad and wireframes
/// \param rsces
/// \param coords Screen coordiantes
/// \param window renderWindow
/// \param v position in map
void draw_element(ressources_t *rsces, sfVector2f **coords,
		  sfRenderWindow *window, sfVector2i v);

/// draw with the painter algo
/// \param rsces
/// \param coords screen position
/// \param map
void draw_with_rotation(ressources_t *rsces, sfVector2f **coords, map_draw_t *map);

/// render a point with quad
/// \param rsces
/// \param map
/// \param coords
/// \param i v2f
void render_element(ressources_t *rsces, map_draw_t *map, v2f **coords, v2i i);

/// create the texture of the texture structure
/// \param rsces
/// \return created textures_t
textures_t *create_textures(ressources_t *rsces);

/// create the sounds of the sound structure
sound_t *create_sounds(ressources_t *rsces);

/// create the gui of the game
gui_t *create_gui(ressources_t *rsces);

/// create a sfRenderState with the texture
/// \param text
/// \return
sfRenderStates *create_state(sfTexture *text);

/// Draw nearest point from mouse
void draw_near_point(ressources_t *rsces);

/// Draw gui
void draw_gui(ressources_t *rsces, gui_t *gui);

/// Draw Background
void draw_background(ressources_t *rsces, gui_t *gui);

/// start menu init
int start_menu(ressources_t *rsces);

/// start menu loop
int menu_loop(menu_t *objects, ressources_t *rsces, sfText *text);

/// Checks the mouse position
int check_mouse(menu_t *objects, ressources_t *rsces, sfClock *my_clock);

/// event handler of menu
int menu_events(ressources_t *rsces);

/// find nearest point next to the mouse
v2i find_point(ressources_t *rsces, v2i mouse_pos);

/// absolute value in float
float absolute_value(float x);

/// compute near tile
tile_coord_t compute_near_tile(ressources_t *rsces);

/// draw the nearest thing between point / tile
void draw_nearest_thing(ressources_t *rsces);

/// increase or decrease the size of the map of one point
void edit_map_point(ressources_t *rsces);

/// increase or decrease the size of the map of one tile
void edit_map_draw_tile(ressources_t *rsces);

/// egenerate a zero map (reset map)
float **generate_zero_float_map(v2i size);

#endif /* !MY_WORLD_2017 */
