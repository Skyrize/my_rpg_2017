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
#define STARTING_SCENE_NAME "MENU_PRINCIPAL" /// Name of the starting scene in a string. Will be displayed at the begining of the game.
#define MAP_SCENE_NAME "GAME" /// Name of the scene required to display the map
#define GAME_TITLE "Lands Of Valoran"

//////////////////////////////// WINDOW DEFINES //////////////////////////////

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_BITS_PER_PIXEL 32
#define WINDOW_PIXELS_UNIT 50
#define PRIORITY_MAX 4
#define CLOCK_SPEED_MENU 0.01
#define CLOCK_SPEED_GAME 0.1


///////////////////////////////// MAPS DEFINES //////////////////////////////

#define ZONE_TAB_X 4
#define ZONE_TAB_Y 4
#define AREA_TAB_X 3
#define AREA_TAB_Y 3
#define TILE_TAB_X 16
#define TILE_TAB_Y 12

//////////////////////////////// PLAYER DEFINES /////////////////////////////

#define INVENTORY_SIZE_Y 7
#define INVENTORY_SIZE_X 5

///////////////////////////////// GAME DEFINES //////////////////////////////

#define REGULAR_COLOR ((sfColor){255, 255, 255, 255})
#define OVER_COLOR ((sfColor){120, 210, 210, 255})
#define V2F(x, y) (sfVector2f) {(float) x, (float) y}
#define V2I(x, y) (sfVector2i) {(int) x, (int) y}

//HUD
#define NEW_GAME "NEW_GAME"
#define RESUME_GAME "RESUME"
#define OPTION_GAME "OPTION_GAME"
#define CREDITS_GAME "CREDITS"
#define SAVE_GAME "SAVE"
#define QUIT_GAME "QUIT"
#define QUESTS_GAME "QUESTS"
#define PAUSE_GAME "PAUSE"
#define CHARAC_GAME "CHARACTERISTICS"
#define EXIT_GAME "EXIT"
#define INVENTORY_GAME "INVENTORY"
#define LOAD_GAME "LOAD"
#define MAP_GAME "MAP"
#define HOME "MENU_PRINCIPAL"
#define CONTROL_KEY "CONTROL_KEY"
#define VERSION_GAME "V0.8"

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
	int priority;
	int (*callback)();
	sfRectangleShape *obj;
	sfBool button;
	rect_t obj_rect;
} obj_t;

typedef struct texture_s
{
	int priority;
	sfTexture *texture;
	sfBool animated;
	sfIntRect rect;
	sfVector2i rect_start;
	sfVector2i rect_max;
	sfVector2i rect_offset;
} texture_t;

/////////////////////////////////// MAPPING /////////////////////////////////
typedef struct tile_list_s tile_list_t;

typedef struct tile_list_s
{
	obj_t *tile;
	tile_list_t *next;
} tile_list_t;

typedef struct tile_s
{
	sfBool block;
	tile_list_t *displayed_tiles;
} tile_t;

typedef struct area_s
{
	char *name;
	sfBool encounter;
	tile_t tiles[TILE_TAB_Y][TILE_TAB_X];
} area_t;

typedef struct zone_s
{
	char *name;
	char *filepath;
} zone_t;

typedef struct map_s
{
	sfVector2i zone_coord;
	sfVector2i area_coord;
	sfVector2i tile_coord;
	zone_t zones[ZONE_TAB_Y][ZONE_TAB_X];
	area_t areas[AREA_TAB_Y][AREA_TAB_X];
} map_t;

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
	hashmap_t *objs;
	hashmap_t *texts;
	sfBool play_music;
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

/////////////////////////////////// PLAYER ////////////////////////////////

typedef struct characteristic_s
{
	int vitality;
	int armor;
	char *speciality_name;
	int speciality;
} characteristic_t;

typedef struct inventory_s
{
	int golds;
	obj_t *inventory_items[INVENTORY_SIZE_Y][INVENTORY_SIZE_X];
} inventory_t;

typedef struct act_stats_s
{
	int health;
	int armor;
} act_stats_t;

typedef struct player_s
{
	char *name;
	obj_t *character;
	inventory_t inventory;
	characteristic_t characteristics;
	act_stats_t *act_stats;
} player_t;

typedef enum direction_e {
	UP,
	DOWN,
	LEFT,
	RIGHT
} direction_t;
/////////////////////////////// CONTROLS ///////////////////////////////////

typedef struct key_control_s
{
	sfKeyCode *up;
	sfKeyCode *down;
	sfKeyCode *right;
	sfKeyCode *left;
	sfKeyCode *up_1;
	sfKeyCode *down_1;
	sfKeyCode *right_1;
	sfKeyCode *left_1;
	int move;
} key_control_t;

//////////////////////////////////// DATA DEFINES /////////////////////////////

/////////////////////////////////// WINDOW ////////////////////////////////

typedef struct game_s
{
	player_t player;
} game_t;

typedef struct ctime_s
{
	sfClock *clock;
	sfTime timer;
	float seconds;
} ctime_t;

typedef struct my_window_s
{
	int error_no;
	int framerate_game;
	sfVector2i mouse_pos;
	sfEvent event;
	sfRenderWindow *window;
	sfBool click_released;
	ctime_t clocker;
	map_t map;
	game_t game;
	bucket_t *current;
	hashmap_t *scenes;
	hashmap_t *audio_lib;
	hashmap_t *fonts_lib;
	hashmap_t *textures_lib;
	display_list_t *displayed_scenes;
	key_control_t *key_player;
} my_w_t;

///////////////////////////////// INITIALISATION ////////////////////////////
typedef struct key_word_s key_word_t;

typedef struct get_infos_s
{
	char *filepath;
	char *indicator;
	const key_word_t *keys;
	void (*savior)(my_w_t *);
} get_infos_t;

typedef struct key_word_s
{
	char *key_word;
	int nb_sub_keywords;
	int (*fptr)(char **, char **, hashmap_t **, my_w_t *);
	char **args;
} key_word_t;

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
	char **button;
	char **x;
	char **y;
} obj_infos_t;

/////////////////////////////////////// DATAS //////////////////////////////////

typedef struct obj_data_s
{
	char *name;
	char *type;
	sfBool button;
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


//////////////////////////////////// DATA HUD /////////////////////////////

typedef struct button_s {
	char *balise;
	int (*instruction)();
} button_t;


#define ZONE_COOR_X window->map.zone_coord.x
#define ZONE_COOR_Y window->map.zone_coord.y
#define AREA_COOR_X window->map.area_coord.x
#define AREA_COOR_Y window->map.area_coord.y
#define TILE_COOR_X window->map.tile_coord.x
#define TILE_COOR_Y window->map.tile_coord.y

#define ZONE window->map.zones[ZONE_COOR_Y][ZONE_COOR_X]
#define AREA window->map.areas[AREA_COOR_Y][AREA_COOR_X]
#define TILE AREA.tiles[TILE_COOR_Y][TILE_COOR_X]

#define ZONE_NAME ZONE.name
#define ZONE_FILEPATH ZONE.filepath
#define AREA_NAME AREA.name
#define AREA_ENCOUTER AREA.encounter
#define TILE_LIST TILE.displayed_tiles
#define TILE_BLOCK TILE.block

#define MOUSE_POS window->mouse_pos

////////////////////////////////////// GAME DEFINES //////////////////////////

#define PLAYER window->game.player
#define PLAYER_NAME PLAYER.name
#define PLAYER_CHARACTER PLAYER.character
#define PLAYER_INVENTORY PLAYER.inventory
#define PLAYER_CHARAC PLAYER.characteristics

#define PLAYER_GOLDS PLAYER_INVENTORY.golds
#define PLAYER_ITEMS PLAYER_INVENTORY.inventory_items

#define PLAYER_VITALITY PLAYER_CHARAC.vitality
#define PLAYER_ARMOR PLAYER_CHARAC.armor
#define PLAYER_SPECIALITY_NAME PLAYER_CHARAC.speciality_name
#define PLAYER_SPECIALITY PLAYER_CHARAC.speciality

///////////////////////////////////// FUNCTIONS ///////////////////////////////


/////////////////////////// INIT FUNCTIONS

my_w_t init_my_window(void);
int init_my_scenes(my_w_t *window);
int init_my_audio_lib(my_w_t *window);
int init_my_textures_lib(my_w_t *window);
int init_my_fonts_lib(my_w_t *window);
int init_my_map(my_w_t *window);
int init_my_zone(my_w_t *window);
int init_scene_lists(char **infos, my_w_t *window);
int init_my_buttons(my_w_t *window);
int init_a_text(char **infos, my_w_t *window, hashmap_t *current_list);
int init_an_obj(char **infos, my_w_t *window, hashmap_t *current_list);
int init_my_player(my_w_t *window);

/// Change ZONE_COOR_X and ZONE_COOR_Y and call load_my_zone to fulfill AREA maps with asked zone.
int load_my_zone(my_w_t *window);

///Unload and free the current zone (ZONE_COOR_X/Y)
void unload_my_zone(my_w_t *window);

/////////////////////////// SAVIOR TRICK FUNCTIONS

void list_savior(my_w_t *window);
void map_savior(my_w_t *window);

/////////////////////////// INIT FROM PROG CONFIG FILE

int analyse_my_project_config_file(my_w_t *window, get_infos_t *infos);
int init_from_pcf(char **infos, my_w_t *window, const key_word_t *keys);

/////////////////////////// KEY WORDS FUNCTIONS

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
int get_a_map(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_zone(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_an_area(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_tile(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_tile_texture(char **infos, char **type, hashmap_t **current_list, my_w_t *window);
int get_a_priority(char **infos, char **type, hashmap_t **current_list, my_w_t *window);

/////////////////////////// INIT WARNING : UNEXISTING

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(texture_t *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);
int check_unexisting_zone(char *zone_name);
int check_unexisting_scene(bucket_t *scene, char *asked_scene);

/////////////////////////// INIT WARNING : INVALID

int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type, char **infos, int error_no);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(int fd, char *filename);
int check_invalid_window_init(int error_no);
int check_invalid_animated(sfBool animated);
int check_invalid_zone_coords(char *name, my_w_t *window);
int check_invalid_area_coords(char *name, my_w_t *window);
int check_invalid_tile_coords(char *name, my_w_t *window);
int check_invalid_priority(int priority, char *texture_name);

/////////////////////////// INIT WARNING : ALREADY_EXISTING

int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);
int check_already_existing_zone_name(char *name, my_w_t *window);
int check_already_existing_zone_coords(char *name, my_w_t *window);
int check_already_existing_area_name(char *name, my_w_t *window);
int check_already_existing_area_coords(char *name, my_w_t *window);
int check_already_existing_tile_coords(my_w_t *window);

/////////////////////////// INIT WARNING : MISSING

int check_missing_args_for_key_word(const key_word_t *keys, int index, char **args, int j);
int check_missing_sub_keyword(char *keyword, int nb_keyword, char **subwords_tab);
int check_missing_or_invalid_sub_keyword(const key_word_t *keys, int index, char **subwords_tab);

/////////////////////////// INIT WARNING : UNDEFINED

int check_undefined_scene(bucket_t *scene, char *asked_list);
int check_undefined_list(hashmap_t *current_list, char *obj);
int check_undefined_texture(bucket_t *texture, char *data);
int check_undefined_area(my_w_t *window);
int check_undefined_tile(my_w_t *window);

/////////////////////////// IN GAME WARNING

int check_scene_not_created(bucket_t *scene, char *file, int line, char *asked);
int check_invalid_tile_display(tile_list_t *tile, int x, int y, my_w_t *window);
int check_invalid_map_display(my_w_t *window);

/////////////////////////// LIST CREATING

///Pass an obj_data and window and return a placed object ready to use. return NULL on fail
obj_t *create_obj(obj_data_t *data, my_w_t *window);

///Pass a scene name and the scene itself return a struct used to display a linked list of scenes. return NULL on fail
display_list_t *create_a_display(char *name, scene_t *scene);

///Pass a texture name and window and return a tile_list used to display a linked list of tiles. return NULL on fail
tile_list_t *create_a_tile(char *texture_name, my_w_t *window);

//////////////////////////// LIST ADDING

///Create an obj with passed data and add it to passed hashmap. Pass window too. return 0/84
int add_obj_to_list(obj_data_t *data, hashmap_t *list, my_w_t *window);

///Create an obj with passed data and add it to passed hashmap. Pass window too. return 0/84
int add_text_to_list(text_data_t *text, hashmap_t *current_list);

///Create an obj with passed data and add it to passed hashmap. Pass window too. return 0/84
int add_scene_to_display_list(bucket_t *scene, my_w_t *window);

///Create an obj with passed data and add it to passed hashmap. Pass window too. return 0/84
int add_tile_to_list(char *texture, my_w_t *window);

/////////////////////////// LIST READ

///Send window every bucket in a passed hasmap to a passed function pointer. Return 0/84 depending on pointer return
int read_hashmap(my_w_t *window, hashmap_t *hashmap, int (*fptr)(bucket_t *, my_w_t *));

/////////////////////////// LIST GET

///Pass a scene name and the window and return the display node containing the asked scene. Return NULL if nothing founded.
display_list_t *get_scene_from_displayed(char *asked, my_w_t *window);

/////////////////////////// LIST REMOVING

///Clean all displayed scenes.
void clean_displayed_scenes(my_w_t *window);

///Clean all displayed scenes and if the scene name passed is found, let it in the list. If not, create and add it. return 0/84
int clean_displayed_scenes_and_add_back(my_w_t *window, char *scene_name);

///Clean all displayed tiles.
void clean_displayed_tiles(my_w_t *window);

///Clean only the scene with the name passed.
void clean_displayed_scene_name(my_w_t *window, char *name_scenes);

/////////////////////////// MANAGE BUTTONS

int manage_buttons(my_w_t *window);
int button_display_hide_scene(char *scene_name, void (*update)(), my_w_t *window);
int update_button(char *seek, char *replacement, scene_t *scene, my_w_t *window);

/////////////////////////// BUTTONS FUNCTIONS

int start_game(my_w_t *window);
int option(my_w_t *window);
int credits(my_w_t *window);
int exit_game(my_w_t *window);
int characteristique(my_w_t *window);
int credits(my_w_t *window);
int inventory(my_w_t *window);
int load(my_w_t *window);
int map(my_w_t *window);
int new_game(my_w_t *window);
int pause_game(my_w_t *window);
int quetes(my_w_t *window);
int quit(my_w_t *window);
int re_load(my_w_t *window);
int resume(my_w_t *window);
int save(my_w_t *window);
int menu_principale(my_w_t *window);
int manage_song(my_w_t *window);
int frame_rate_more(my_w_t *window);
int frame_rate_less(my_w_t *window);
int select_varyan(my_w_t *window);
int select_jaina(my_w_t *window);
int select_avelus(my_w_t *window);
int control_key(my_w_t *window);
int key_french(my_w_t *window);
int key_english(my_w_t *window);
int no_save(my_w_t *window);
int yes_save(my_w_t *window);
int game(my_w_t *window);


/////////////////////////// GAME FUNCTIONS

///Pass window, fulfill the timer struct in it.
void get_time(my_w_t *window);

///Main game function. return 0/84
int game_lobby(my_w_t *window);

///Update the 3 characteristics strings in a given scene with there actual values in Window.
void update_characteristics(scene_t *scene, my_w_t *window);

/////////////////////////// DISPLAY FUNCTIONS

///Read the linked list of displayed scenes and display there obj and text. If the first one is GAME, display map. return (0/84)
int display_scenes(my_w_t *window);

///Display passed obj and animate it.
int display_obj(obj_t *obj, my_w_t *window);

///Read the passed hashmap and if the obj priority match the actual priority, send the object to display_obj.
int display_objs(hashmap_t *objs, my_w_t *window);

///Display a passed text via a bucket (call with read_hashmap)
int display_texts(bucket_t *text_bucket, my_w_t *window);

///Animate a given objetc every given seconds.
void time_animation(obj_t *obj, float seconds, my_w_t *window);

///Read and display the map (in function of AREA_COOR_X/Y) in function of their priorities
int display_map(my_w_t *window);

/////////////////////////// INPUT

void analyse_events(my_w_t *window);

/////////////////////////// DESTROY FUNCTIONS

void destroy_and_free(my_w_t *window);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);

/////////////////////////// PLAYER FUNCTIONS

bool set_player_position(sfVector2i pos_tile, sfVector2i pos_aera, sfVector2i pos_zone, my_w_t *window);
bool move_player_zone(direction_t dir, my_w_t *window, bool check);
bool move_player_area(direction_t dir, my_w_t *window, bool check);
bool move_player(direction_t dir, my_w_t *window, bool check);
void anim_player(my_w_t *window);

/////////////////////////// END

#endif /* RPG_H_ */
