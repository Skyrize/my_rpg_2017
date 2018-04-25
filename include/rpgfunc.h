/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGFUNC_H_
#define RPGFUNC_H_
#include "rpg.h"

///////////////////////////////////// FUNCTIONS ///////////////////////////////

///temp
int add_to_slot(slot_t *slot, sfVector2i *pos, game_t *game);
int add_helmet(slot_t *slot, game_t *game);
int add_chest(slot_t *slot, game_t *game);
int add_pants(slot_t *slot, game_t *game);
int add_gauntlets(slot_t *slot, game_t *game);
int add_weapon(slot_t *slot, game_t *game);

/////////////////////////// INIT FUNCTIONS

int init_window(window_t *window);
int init_game(game_t *game);
void init_player(game_t *game);
int init_scenes(game_t *game);
int init_audio_lib(game_t *game);
int init_textures_lib(game_t *game);
int init_fonts_lib(game_t *game);
int init_items_lib(game_t *game);
int init_map(game_t *game);
int init_zone(game_t *game);
int init_inventory(game_t *game);
int init_scene_lists(char **infos, game_t *game);
int init_buttons(game_t *game);
int init_a_text(char **infos, game_t *game, hashmap_t *current_list);
int init_an_obj(char **infos, game_t *game, hashmap_t *current_list);

/// Change ZONE_COOR_X and ZONE_COOR_Y and call load_my_zone to fulfill
///AREA maps with asked zone.
int load_my_zone(game_t *game);

///Unload and free the current zone (ZONE_COOR_X/Y)
void unload_my_zone(game_t *game);

/////////////////////////// SAVIOR TRICK FUNCTIONS

void list_savior(game_t *game);
void map_savior(game_t *game);

/////////////////////////// INIT FROM PROG CONFIG FILE

int analyse_pcf(game_t *game, get_infos_t *infos);
int init_from_pcf(char **infos, game_t *game, const key_word_t *keys);

/////////////////////////// KEY WORDS FUNCTIONS

int get_a_scene(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_list(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_index(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_obj(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_text(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_music(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_audio(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_font(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_texture_filepath(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_texture_animated(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_rect_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_rect_max_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_rect_max_offset(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_rect_start_values(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_map(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_zone(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_area(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_tile(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_tile_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_a_priority(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_item(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_an_item_texture(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_item_for_quest(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int is_item_consumable(char **infos, char **type,
				hashmap_t **current_list, game_t *game);
int get_item_stats(char **infos, char **type,
				hashmap_t **current_list, game_t *game);

/////////////////////////// INIT WARNING : UNEXISTING

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(texture_t *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);
int check_unexisting_zone(char *zone_name);
int check_unexisting_scene(bucket_t *scene, char *asked_scene);
int check_unexisting_text(bucket_t *text, char *asked_text, char *scene_name);
int check_unexisting_obj(bucket_t *obj, char *asked_obj, char *scene_name);
int check_unexisting_button(int (*callback)(), char *button_name);

/////////////////////////// INIT WARNING : INVALID

int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type,
				char **infos, int my_errno);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(int fd, char *filename);
int check_invalid_window_init(int my_errno);
int check_invalid_animated(sfBool animated);
int check_invalid_zone_coords(char *name, game_t *game);
int check_invalid_area_coords(char *name, game_t *game);
int check_invalid_tile_coords(char *name, game_t *game);
int check_invalid_priority(int priority, char *texture_name);
int check_invalid_consumable(sfBool consumable);
int check_invalid_quest(sfBool quest);

/////////////////////////// INIT WARNING : ALREADY_EXISTING

int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);
int check_already_existing_zone_name(char *name, game_t *game);
int check_already_existing_zone_coords(char *name, game_t *game);
int check_already_existing_area_name(char *name, game_t *game);
int check_already_existing_area_coords(char *name, game_t *game);
int check_already_existing_tile_coords(game_t *game);
int check_already_existing_item(hashmap_t *hashmap, char *item_name);

/////////////////////////// INIT WARNING : MISSING

int check_missing_args_for_key_word(const key_word_t *keys,
				int index, char **args, int j);
int check_missing_sub_keyword(char *keyword, int nb_keyword,
				char **subwords_tab);
int check_missing_or_invalid_sub_keyword(const key_word_t *keys,
				int index, char **subwords_tab);

/////////////////////////// INIT WARNING : UNDEFINED

int check_undefined_scene(bucket_t *scene, char *asked_list);
int check_undefined_list(hashmap_t *current_list, char *obj);
int check_undefined_texture(bucket_t *texture, char *data);
int check_undefined_area(game_t *game);
int check_undefined_tile(game_t *game);
int check_undefined_item(bucket_t *item, char *data);

/////////////////////////// IN GAME WARNING

int check_scene_not_created(bucket_t *scene, char *file, int line, char *);
int check_invalid_tile_display(tile_list_t *tile, int x,
				int y, game_t *game);
int check_invalid_map_display(game_t *game);

/////////////////////////// LIST CREATING

///Pass an obj_data and window and return a placed object ready to use.
///return NULL on fail
obj_t *create_obj(obj_data_t *data, game_t *game);

///Pass a scene name and the scene itself return a struct used to display a
///linked list of scenes. return NULL on fail
display_list_t *create_display(char *name, scene_t *scene);

///Pass a texture name and window and return a tile_list used to display a
///linked list of tiles. return NULL on fail
tile_list_t *create_tile(char *texture_name, game_t *game);

item_t *create_item(obj_t *obj, item_stat_t *stats);

texture_t *create_texture(texture_data_t *data);

//////////////////////////// LIST ADDING

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_obj_to_list(obj_data_t *data, hashmap_t *list, game_t *game);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_text_to_list(text_data_t *text, hashmap_t *current_list);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_scene_to_display_list(bucket_t *scene, game_t *game);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_tile_to_list(char *texture, game_t *game);

/////////////////////////// LIST READ

///Send window every bucket in a passed hasmap to a passed function pointer.
///Return 0/84 depending on pointer return
int read_hashmap(window_t *window, game_t *game, hashmap_t *hashmap,
				int (*fptr)());

/////////////////////////// LIST GET

///Pass a scene name and the window and return the display node containing
///the asked scene. Return NULL if nothing founded.
display_list_t *get_scene_from_displayed(char *asked, game_t *game);

/////////////////////////// LIST REMOVING

///Clean all displayed scenes.
void clean_displayed_scenes(game_t *game);

///Clean all displayed scenes and if the scene name passed is found, let
///it in the list. If not, create and add it. return 0/84
int clean_displayed_scenes_and_add_back(game_t *game, char *scene_name);

///Clean all displayed tiles.
void clean_displayed_tiles(game_t *game);

///Clean only the scene with the name passed.
void clean_displayed_scene_name(game_t *game, char *name_scenes);

/////////////////////////// MANAGE BUTTONS

int manage_buttons(window_t *window, game_t *game);
int button_display_hide_scene(char *scene_name, void (*update)(),
				game_t *game);
int update_button(char *seek, char *replacement, scene_t *scene,
				game_t *game);

/////////////////////////// BUTTONS FUNCTIONS

int start_game(window_t *window, game_t *game);
int option(window_t *window, game_t *game);
int credits(window_t *window, game_t *game);
int exit_game(window_t *window, game_t *game);
int stats(window_t *window, game_t *game);
int credits(window_t *window, game_t *game);
int inventory(window_t *window, game_t *game);
int load(window_t *window, game_t *game);
int map(window_t *window, game_t *game);
int new_game(window_t *window, game_t *game);
int pause_game(window_t *window, game_t *game);
int quetes(window_t *window, game_t *game);
int quit(window_t *window, game_t *game);
int reload(window_t *window, game_t *game);
int resume(window_t *window, game_t *game);
int save(window_t *window, game_t *game);
int main_menu(window_t *window, game_t *game);
int manage_song(window_t *window, game_t *game);
int frame_rate_more(window_t *window, game_t *game);
int frame_rate_less(window_t *window, game_t *game);
int select_varyan(window_t *window, game_t *game);
int select_jaina(window_t *window, game_t *game);
int select_avelus(window_t *window, game_t *game);
int control_key(window_t *window, game_t *game);
int key_french(window_t *window, game_t *game);
int key_english(window_t *window, game_t *game);
int no_save(window_t *window, game_t *game);
int yes_save(window_t *window, game_t *game);
int launch_game(window_t *window, game_t *game);
int slot(window_t *window, game_t *game);
int helmet_slot(window_t *window, game_t *game);
int chest_slot(window_t *window, game_t *game);
int gauntlets_slot(window_t *window, game_t *game);
int pants_slot(window_t *window, game_t *game);
int weapon_slot(window_t *window, game_t *game);
int display_item_stats(item_t *item, game_t *game);

/////////////////////////// HUD FONCTIONS

int set_hud_opacity(bucket_t *bucket, game_t *game);
int manage_hud_opacity(game_t *game);
int manage_life(game_t *game);
int change_area_hud(game_t *game);
int manage_hit_enemy(game_t *game);
int manage_notif_right(game_t *game, char *);
int manage_notif_left(game_t *game, char *);
void move_and_update(sfRectangleShape *notif, sfText *notif_text,
char *notif_output, int offset);
/////////////////////////// GAME FUNCTIONS

int start_game(window_t *window, game_t *game);

///Pass window, fulfill the timer struct in it.
void get_time(ctime_t *clocker);

///Main game function. return 0/84
int game_lobby(window_t *window, game_t *game);

///Update the 3 stats strings in a given scene with there actual values
///in Window.
void update_stats(scene_t *scene, game_t *game);

/////////////////////////// DISPLAY FUNCTIONS

///Read the linked list of displayed scenes and display there obj and text.
///If the first one is GAME, display map. return (0/84)
int display_scenes(window_t *window, game_t *game);

///Display passed obj and animate it.
int display_obj(obj_t *obj, window_t *window);

///Read the passed hashmap and if the obj priority match the actual priority,
///send the object to display_obj.
int display_objs(hashmap_t *objs, window_t *window);

///Display a passed text via a bucket (call with read_hashmap)
int display_texts(bucket_t *text_bucket, window_t *window);

///Animate a given objetc every given seconds.
void time_animation(obj_t *obj, float seconds, window_t *window);

///Read and display the map (in function of AREA_COOR_X/Y) in function of
///their priorities
int display_map(window_t *window, game_t *game);

/////////////////////////// INPUT

void analyse_events(window_t *window, game_t *game);

/////////////////////////// DESTROY FUNCTIONS

void destroy_and_free(window_t *window, game_t *game);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);
void item_destroy(item_t *item);

/////////////////////////// PLAYER FUNCTIONS

bool set_player_position(sfVector2i pos_tile, sfVector2i pos_aera,
				sfVector2i pos_zone, game_t *game);
bool move_player_zone(direction_t dir, game_t *game, bool check);
bool move_player_area(direction_t dir, game_t *game, bool check);
bool move_player(direction_t dir, game_t *game, bool check);
int anim_player(game_t *game);
void set_anim_side(game_t *game);
void init_movements(game_t *game);
void smooth_move_player(game_t *game);
void set_initial_player_pos(game_t *game);
void set_waiting_player_rect(game_t *game);
bool is_pressing_controls(game_t *game);
void update_moving_state(game_t *game);
bool is_player_moving(game_t *game);

/////////////////////////// END

#endif /* RPGFUNC_H_ */