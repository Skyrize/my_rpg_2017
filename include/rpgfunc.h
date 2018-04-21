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
int add_to_slot(slot_t *slot, sfVector2i *pos, window_t *window);
int add_helmet(slot_t *slot, window_t *window);
int add_chest(slot_t *slot, window_t *window);
int add_pants(slot_t *slot, window_t *window);
int add_gauntlets(slot_t *slot, window_t *window);
int add_weapon(slot_t *slot, window_t *window);


/////////////////////////// INIT FUNCTIONS

window_t init_my_window(void);
int init_my_scenes(window_t *window);
int init_my_audio_lib(window_t *window);
int init_my_textures_lib(window_t *window);
int init_my_fonts_lib(window_t *window);
int init_my_map(window_t *window);
int init_my_zone(window_t *window);
int init_scene_lists(char **infos, window_t *window);
int init_my_buttons(window_t *window);
int init_a_text(char **infos, window_t *window, hashmap_t *current_list);
int init_an_obj(char **infos, window_t *window, hashmap_t *current_list);
int init_my_player(window_t *window);

/// Change ZONE_COOR_X and ZONE_COOR_Y and call load_my_zone to fulfill
///AREA maps with asked zone.
int load_my_zone(window_t *window);

///Unload and free the current zone (ZONE_COOR_X/Y)
void unload_my_zone(window_t *window);

/////////////////////////// SAVIOR TRICK FUNCTIONS

void list_savior(window_t *window);
void map_savior(window_t *window);

/////////////////////////// INIT FROM PROG CONFIG FILE

int analyse_my_project_config_file(window_t *window, get_infos_t *infos);
int init_from_pcf(char **infos, window_t *window, const key_word_t *keys);

/////////////////////////// KEY WORDS FUNCTIONS

int get_a_scene(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_list(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_an_index(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_an_obj(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_text(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_music(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_an_audio(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_font(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_texture(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_texture_filepath(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_an_animated(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_rect_values(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_rect_max_values(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_rect_max_offset(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_rect_start_values(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_map(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_zone(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_an_area(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_tile(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_tile_texture(char **infos, char **type,
				hashmap_t **current_list, window_t *window);
int get_a_priority(char **infos, char **type,
				hashmap_t **current_list, window_t *window);

/////////////////////////// INIT WARNING : UNEXISTING

int check_unexisting_font(sfFont *font, char *font_name);
int check_unexisting_texture(texture_t *texture, char *texture_name);
int check_unexisting_music(sfMusic *music, char *music_name);
int check_unexisting_zone(char *zone_name);
int check_unexisting_scene(bucket_t *scene, char *asked_scene);

/////////////////////////// INIT WARNING : INVALID

int check_invalid_obj_init(obj_infos_t *obj);
int check_invalid_key_word(char *last_word_used, char **type,
				char **infos, int error_no);
int check_invalid_text_init(text_infos_t *text);
int check_invalid_index(int index);
int check_invalid_file(int fd, char *filename);
int check_invalid_window_init(int error_no);
int check_invalid_animated(sfBool animated);
int check_invalid_zone_coords(char *name, window_t *window);
int check_invalid_area_coords(char *name, window_t *window);
int check_invalid_tile_coords(char *name, window_t *window);
int check_invalid_priority(int priority, char *texture_name);

/////////////////////////// INIT WARNING : ALREADY_EXISTING

int check_already_existing_obj(char *obj_name, hashmap_t *current_list);
int check_already_existing_text(char *text_name, hashmap_t *current_list);
int check_already_existing_texture(hashmap_t *hashmap, char *texture_name);
int check_already_existing_audio(sfMusic *audio, char *audio_name);
int check_already_existing_font(sfFont *font, char *font_name);
int check_already_existing_scene(bucket_t *scene, char *scene_name);
int check_already_existing_music(sfMusic *music, char *music_name);
int check_already_existing_zone_name(char *name, window_t *window);
int check_already_existing_zone_coords(char *name, window_t *window);
int check_already_existing_area_name(char *name, window_t *window);
int check_already_existing_area_coords(char *name, window_t *window);
int check_already_existing_tile_coords(window_t *window);

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
int check_undefined_area(window_t *window);
int check_undefined_tile(window_t *window);

/////////////////////////// IN GAME WARNING

int check_scene_not_created(bucket_t *scene, char *file, int line, char *asked);
int check_invalid_tile_display(tile_list_t *tile, int x,
				int y, window_t *window);
int check_invalid_map_display(window_t *window);

/////////////////////////// LIST CREATING

///Pass an obj_data and window and return a placed object ready to use.
///return NULL on fail
obj_t *create_obj(obj_data_t *data, window_t *window);

///Pass a scene name and the scene itself return a struct used to display a
///linked list of scenes. return NULL on fail
display_list_t *create_a_display(char *name, scene_t *scene);

///Pass a texture name and window and return a tile_list used to display a
///linked list of tiles. return NULL on fail
tile_list_t *create_a_tile(char *texture_name, window_t *window);

//////////////////////////// LIST ADDING

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_obj_to_list(obj_data_t *data, hashmap_t *list, window_t *window);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_text_to_list(text_data_t *text, hashmap_t *current_list);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_scene_to_display_list(bucket_t *scene, window_t *window);

///Create an obj with passed data and add it to passed hashmap. Pass window
///too. return 0/84
int add_tile_to_list(char *texture, window_t *window);

/////////////////////////// LIST READ

///Send window every bucket in a passed hasmap to a passed function pointer.
///Return 0/84 depending on pointer return
int read_hashmap(window_t *window, hashmap_t *hashmap,
				int (*fptr)(bucket_t *, window_t *));

/////////////////////////// LIST GET

///Pass a scene name and the window and return the display node containing
///the asked scene. Return NULL if nothing founded.
display_list_t *get_scene_from_displayed(char *asked, window_t *window);

/////////////////////////// LIST REMOVING

///Clean all displayed scenes.
void clean_displayed_scenes(window_t *window);

///Clean all displayed scenes and if the scene name passed is found, let
///it in the list. If not, create and add it. return 0/84
int clean_displayed_scenes_and_add_back(window_t *window, char *scene_name);

///Clean all displayed tiles.
void clean_displayed_tiles(window_t *window);

///Clean only the scene with the name passed.
void clean_displayed_scene_name(window_t *window, char *name_scenes);

/////////////////////////// MANAGE BUTTONS

int manage_buttons(window_t *window);
int button_display_hide_scene(char *scene_name, void (*update)(),
				window_t *window);
int update_button(char *seek, char *replacement, scene_t *scene,
				window_t *window);

/////////////////////////// BUTTONS FUNCTIONS

int start_game(window_t *window);
int option(window_t *window);
int credits(window_t *window);
int exit_game(window_t *window);
int stats(window_t *window);
int credits(window_t *window);
int inventory(window_t *window);
int load(window_t *window);
int map(window_t *window);
int new_game(window_t *window);
int pause_game(window_t *window);
int quetes(window_t *window);
int quit(window_t *window);
int reload(window_t *window);
int resume(window_t *window);
int save(window_t *window);
int main_menu(window_t *window);
int manage_song(window_t *window);
int frame_rate_more(window_t *window);
int frame_rate_less(window_t *window);
int select_varyan(window_t *window);
int select_jaina(window_t *window);
int select_avelus(window_t *window);
int control_key(window_t *window);
int key_french(window_t *window);
int key_english(window_t *window);
int no_save(window_t *window);
int yes_save(window_t *window);
int game(window_t *window);
int slot(window_t *window);
int helmet_slot(window_t *window);
int chest_slot(window_t *window);
int gauntlets_slot(window_t *window);
int pants_slot(window_t *window);
int weapon_slot(window_t *window);

/////////////////////////// HUD FONCTIONS

int set_hud_opacity(bucket_t *bucket, window_t *window);
int manage_hud_opacity(window_t *window);
int manage_life(window_t *window);
int change_area_hud(window_t *window);
int manage_hit_enemy(window_t *window);
int manage_notif(window_t *window, char *);
/////////////////////////// GAME FUNCTIONS

///Pass window, fulfill the timer struct in it.
void get_time(window_t *window);

///Main game function. return 0/84
int game_lobby(window_t *window);

///Update the 3 stats strings in a given scene with there actual values
///in Window.
void update_stats(scene_t *scene, window_t *window);

/////////////////////////// DISPLAY FUNCTIONS

///Read the linked list of displayed scenes and display there obj and text.
///If the first one is GAME, display map. return (0/84)
int display_scenes(window_t *window);

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
int display_map(window_t *window);

/////////////////////////// INPUT

void analyse_events(window_t *window);

/////////////////////////// DESTROY FUNCTIONS

void destroy_and_free(window_t *window);
void obj_destroy(obj_t *obj);
void scenes_destroy(scene_t *scene);
void texture_destroy(texture_t *texture);

/////////////////////////// PLAYER FUNCTIONS

bool set_player_position(sfVector2i pos_tile, sfVector2i pos_aera,
				sfVector2i pos_zone, window_t *window);
bool move_player_zone(direction_t dir, window_t *window, bool check);
bool move_player_area(direction_t dir, window_t *window, bool check);
bool move_player(direction_t dir, window_t *window, bool check);
void anim_player(window_t *window);
void set_anim_side(window_t *window);
void init_movements(window_t *window);
void smooth_move_player(window_t *window);
void set_initial_player_pos(window_t *window);
void set_waiting_player_rect(window_t *window);
bool is_pressing_controls(window_t *window);
void update_moving_state(window_t *window);
bool is_player_moving(window_t *window);

/////////////////////////// END

#endif /* RPGFUNC_H_ */