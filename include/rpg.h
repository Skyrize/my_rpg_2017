/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPG_H_
#define RPG_H_
#include "hashify.h"

///////////////////////////////// INIT DEFINES //////////////////////////////

#define TEXT_SEPARATOR_CHAR '_'
#define OBJ_KEYWORD "OBJ"
#define TEXTURE_KEYWORD "TEXTURE"
#define TEXT_KEYWORD "TEXT"
#define STR_KEYWORD "STR"
#define FONT_KEYWORD "FONT"
#define CHARAC_SIZE_KEYWORD "CHARAC_SIZE"
#define X_KEYWORD "X"
#define Y_KEYWORD "Y"

//////////////////////////////// WINDOW DEFINES //////////////////////////////

#define WINDOW_WIDTH 1600
#define WINDOW_HEIGHT 900
#define WINDOW_BITS_PER_PIXEL 32
#define OBJS_TYPE_NB 4

///////////////////////////////// GAME DEFINES //////////////////////////////

#define REGULAR_COLOR ((sfColor){255, 255, 255, 255})
#define OVER_COLOR ((sfColor){255, 100, 100, 255})

////////////////////////////////// OBJECTS //////////////////////////////

typedef struct obj_data_s
{
	char *name;
	char *type;
	sfVector2f position;
} obj_data_t;

typedef struct text_data_s
{
	char *name;
	char *text;
	sfFont *font;
	int charac_size;
	sfVector2f position;
} text_data_t;

typedef struct game_objs_s game_objs_t;

typedef struct game_objs_s
{
	int (*callback)();
	sfRectangleShape *obj;
} game_objs_t;

/////////////////////////////////// MAPPING /////////////////////////////////

typedef struct mapping_s
{
	unsigned int x_size;
	unsigned int y_size;
	unsigned int x_pos;
	unsigned int y_pos;
	char **map;
} mapping_t;

//////////////////////////////////////// SCENES ////////////////////////////

typedef enum
{
	BACKGROUNDS = 0,
	PNJS = 1,
	ITEMS = 2,
	BUTTONS = 3,
} objs_type_t;

typedef struct scene_s {
	hashmap_t *objs[OBJS_TYPE_NB];
	hashmap_t *texts;
	sfMusic *music;
} scene_t;

/////////////////////////////////// WINDOW ////////////////////////////////

typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct my_window_s
{
	char *actual_scene;
	int error_no;
	sfRenderWindow *window;
	sfEvent event;
	ctime_t clocker;
	hashmap_t *textures_lib;
	hashmap_t *audio_lib;
	hashmap_t *fonts_lib;
	hashmap_t *scenes;
} my_w_t;

///////////////////////////////// INITIALISATION ////////////////////////////

typedef struct key_word_s
{
	char *key_word;
	int (*fptr)(char **, char **, hashmap_t **, my_w_t *);
} key_word_t;

typedef struct get_infos_s
{
	char *filepath;
	char *indicator;
	int (*fptr)(char **, my_w_t *);
} get_infos_t;

typedef struct text_infos_s
{
	char **name;
	char **text;
	char **font;
	char **charac_size;
	char **x;
	char **y;
} text_infos_t;

typedef struct obj_infos_s
{
	char **name;
	char **type;
	char **x;
	char **y;
} obj_infos_t;

///////////////////////////////////// FUNCTIONS ///////////////////////////////


//// INIT FUNCTIONS

my_w_t init_my_window(void);
int init_my_scenes(my_w_t *window);
int init_scene_lists(char *scene_name, my_w_t *window);
int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list);
int init_my_audio_lib(my_w_t *window);
int init_my_textures_lib(my_w_t *window);
int init_my_fonts_lib(my_w_t *window);
int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list);

/// INIT FROM PROG CONFIG FILE

int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos);
int init_audio_lib_from_pcf(char **infos, my_w_t *window);
int init_textures_lib_from_pcf(char **infos, my_w_t *window);
int init_audio_lib_from_pcf(char **infos, my_w_t *window);
int init_scenes_from_pcf(char **infos, my_w_t *window);
int init_fonts_lib_from_pcf(char **infos, my_w_t *window);

/// KEY WORDS FUNCTIONS

int get_a_scene(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_list(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_index(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_obj(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_text(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_music(char **infos, char **type, hashmap_t **current_list, my_w_t *window);

/// INIT WARNING

int check_missing_information_for_obj(char **infos);
int check_missing_information_for_text(char **infos);
int check_unexisting_font(sfFont *font, char *font_name);
int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_texture(sfTexture *texture, char *texture_name);
int check_invalid_key_word(char *last_word_used, char *key_word);
int check_invalid_music(sfMusic *music, char *music_name);
int check_missing_args_for_key_word(char **args);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_already_existing_obj(obj_data_t *data, hashmap_t *current_list);
int check_already_existing_text(text_data_t *data, hashmap_t *current_list);

/// IN GAME WARNING

int check_valid_display(scene_t *current_scene, char *scene_seeked);

/// HASHMAP LIST ADDING

int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window);
int add_text_to_list(text_data_t *text, hashmap_t *current_list);

/// DESTROY FUNCTIONS

void destroy_and_free(my_w_t *window);
void obj_destroy(game_objs_t *obj);
void scenes_destroy(scene_t *scene);

/// GAME FUNCTIONS

void get_time(my_w_t *window);
int game_lobby(my_w_t *window, bucket_t *current_scene);

/// DISPLAY FUNCTIONS

int display_scene(my_w_t *window, bucket_t *current_scene);
void display_hashmap_objs(my_w_t *window, hashmap_t *hashmap);
void display_bucket_objs(my_w_t *window, bucket_t *obj);
void display_bucket_texts(my_w_t *window, bucket_t *obj);

/// INPUT

void analyse_events(my_w_t *window);

#endif /* RPG_H_ */
