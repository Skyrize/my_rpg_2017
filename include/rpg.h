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

/// METTRE UN GNL QUI MARCHE POUR SUPPRIMER CA :
#define END_OF_FILE "### END OF FILE ###"

#define INIT_INDICATOR "-" /// String to put in the begining of the line to indicate that lines below are init informations.
#define TEXT_SEPARATOR_CHAR '_' /// Char used to link words in text string init. Get replaced with spaces.
#define KEYWORD_SEPARATOR_CHAR '=' /// Char used to separate KEYWORD and data.
#define DATASET_SEPARATOR_CHAR ' ' /// Char used to separate KEYWORDS from each other or datas from each other.
#define STARTING_SCENE_NAME "GAME" /// Name of the starting scene in a string. Will be displayed at the begining of the game.
#define GAME_TITLE "We have to choose a title for our rpg."

//////////////////////////////// WINDOW DEFINES //////////////////////////////

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define TILES_X 16
#define TILES_Y 12
#define WINDOW_BITS_PER_PIXEL 32
#define OBJS_TYPE_NB 5

///////////////////////////////// GAME DEFINES //////////////////////////////

#define REGULAR_COLOR ((sfColor){255, 255, 255, 255})
#define OVER_COLOR ((sfColor){120, 210, 210, 130})

////////////////////////////////// OBJECTS //////////////////////////////

typedef struct obj_data_s obj_data_t;
typedef struct text_data_s text_data_t;

typedef struct obj_s obj_t;

typedef struct rect_s
{
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} rect_t;

typedef struct obj_s
{
	int (*callback)();
	sfRectangleShape *obj;
	rect_t obj_rect;
} obj_t;

typedef struct texture_s
{
	sfTexture *texture;
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} texture_t;

/////////////////////////////////// MAPPING /////////////////////////////////

typedef struct tile_s
{
	sfBool block;
	sfRectangleShape *tile;
	sfBool door;
	void (*teleport)();
} tile_t;

typedef struct map_s
{
	tile_t tiles[TILES_X][TILES_Y];
	sfBool encounter;
} map_t;

typedef struct zone_s
{
	map_t **maps;
} zone_t;

//////////////////////////////////////// SCENES ////////////////////////////

typedef enum
{
	BACKGROUNDS = 0,
	PNJS = 1,
	MONSTERS = 2,
	ITEMS = 3,
	BUTTONS = 4,
} objs_type_t;

typedef struct scene_s {
	hashmap_t *objs[OBJS_TYPE_NB];
	hashmap_t *texts;
	sfMusic *music;
	int priority;
} scene_t;

typedef struct display_list_s display_list_t;

typedef struct display_list_s
{
	scene_t *scene;
	char *scene_name;
	display_list_t *next;
} display_list_t;

/////////////////////////////////// WINDOW ////////////////////////////////

typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct my_window_s
{
	int error_no;
	sfEvent event;
	sfRenderWindow *window;
	ctime_t clocker;
	bucket_t *current;
	hashmap_t *textures_lib;
	hashmap_t *audio_lib;
	hashmap_t *fonts_lib;
	hashmap_t *scenes;
	display_list_t *displayed_scenes;
} my_w_t;

///////////////////////////////// INITIALISATION ////////////////////////////

typedef struct key_word_s
{
	char *key_word;
	int nb_sub_keywords;
	int (*fptr)(char **, char **, hashmap_t **, my_w_t *);
	char **args;
} key_word_t;

/////////////////////////////////////// DATAS //////////////////////////////////

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


/////////////////////////////////////// INFOS /////////////////////////////////

typedef struct get_infos_s
{
	char *filepath;
	char *indicator;
	const key_word_t *keys;
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
int init_scene_lists(char **infos, my_w_t *window);
int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list);
int init_my_audio_lib(my_w_t *window);
int init_my_textures_lib(my_w_t *window);
int init_my_fonts_lib(my_w_t *window);
int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list);

/// INIT FROM PROG CONFIG FILE

int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos);
int init_from_pcf(char **infos, my_w_t *window, const key_word_t *keys);

/// KEY WORDS FUNCTIONS

int get_a_scene(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_list(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_index(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_obj(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_text(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_music(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_audio(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_font(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_texture(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_texture_filepath(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_animated(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_rect_values(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_rect_max_values(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_rect_max_offset(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_rect_start_values(char **infos, char **type, hashmap_t **current_list, my_w_t *window);

/// INIT WARNING : UNEXISTING

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(sfTexture *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);

/// INIT WARNING : INVALID

int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type, char **infos, int error_no);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(int fd, char *filename);
int check_invalid_window_init(int error_no);
int check_invalid_animated(sfBool animated);

/// INIT WARNING : ALREADY_EXISTING

int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);

/// INIT WARNING : MISSING

int check_missing_args_for_key_word(const key_word_t *keys, int index, char **args, int j);
int check_missing_sub_keyword(char *keyword, int nb_keyword, char **subwords_tab);
int check_missing_or_invalid_sub_keyword(const key_word_t *keys, int index, char **subwords_tab);

/// INIT WARNING : UNDEFINED

int check_undefined_scene(bucket_t *scene, char *asked_list);
int check_undefined_list(hashmap_t *current_list, char *obj);
int check_undefined_texture(bucket_t *texture, char *data);

/// IN GAME WARNING

int check_scene_not_created(bucket_t *scene, char *file, int line, char *asked);

/// LIST ADDING

int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window);
int add_text_to_list(text_data_t *text, hashmap_t *current_list);
int add_scene_to_list(bucket_t *scene, my_w_t *window);

/// DESTROY FUNCTIONS

void destroy_and_free(my_w_t *window);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);

/// GAME FUNCTIONS

void get_time(my_w_t *window);
int game_lobby(my_w_t *window);

/// DISPLAY FUNCTIONS

int display_scenes(my_w_t *window);
void display_hashmap_objs(my_w_t *window, hashmap_t *hashmap);
void display_bucket_objs(my_w_t *window, bucket_t *obj);
void display_bucket_texts(my_w_t *window, bucket_t *obj);
void move_rect(obj_t *obj);

/// INPUT

void analyse_events(my_w_t *window);

#endif /* RPG_H_ */
