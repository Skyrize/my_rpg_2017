/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

ctime_t init_timer(void)
{
	ctime_t clocker;

	clocker.clock = sfClock_create();
	clocker.seconds = 0;
	return (clocker);
}

int init_inventory(my_w_t *window)
{
	slot_t sweap;
	slot_t shel;
	slot_t schest;
	slot_t sgaunt;
	slot_t spants;
	item_t weap;
	item_t hel;
	item_t chest;
	item_t gaunt;
	item_t pants;
	item_t i00;
	item_t i01;
	sweap.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_BOW_00", 1, V2F(585, 135)}, window);
	shel.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_HELMET_00", 1, V2F(635, 85)}, window);
	schest.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_CHEST_00", 1, V2F(635, 135)}, window);
	sgaunt.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_GAUNTLETS_00", 1, V2F(690, 135)}, window);
	spants.slot = create_obj(&(obj_data_t){"ITEM", "COMMON_PANTS_00", 1, V2F(635, 185)}, window);
	obj_t *w = create_obj(&(obj_data_t){"ITEM", "COMMON_BOW_00", 1, V2F(585, 135)}, window);
	obj_t *h = create_obj(&(obj_data_t){"ITEM", "COMMON_HELMET_00", 1, V2F(635, 85)}, window);
	obj_t *c = create_obj(&(obj_data_t){"ITEM", "COMMON_CHEST_00", 1, V2F(635, 135)}, window);
	obj_t *g = create_obj(&(obj_data_t){"ITEM", "COMMON_GAUNTLETS_00", 1, V2F(690, 135)}, window);
	obj_t *p = create_obj(&(obj_data_t){"ITEM", "COMMON_PANTS_00", 1, V2F(635, 185)}, window);
	obj_t *i0 = create_obj(&(obj_data_t){"ITEM", "MYTHIC_CHEST_01", 1, V2F(635, 185)}, window);
	obj_t *i1 = create_obj(&(obj_data_t){"ITEM", "MYTHIC_HELMET_01", 1, V2F(635, 185)}, window);
	PLAYER_HELMET.item.obj = NULL;
	PLAYER_CHEST.item.obj = NULL;
	PLAYER_GAUNTLETS.item.obj = NULL;
	PLAYER_PANTS.item.obj = NULL;
	PLAYER_WEAPON.item.obj = NULL;
	///to change
	PLAYER_GOLDS = 100;
	for (int x = 0; x != INVENTORY_SIZE_X; x++)
		for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
			PLAYER_ITEMS[y][x].item.obj = NULL;
		}
	PLAYER_ITEMS[0][0].slot = create_obj(&(obj_data_t){"ITEM", "INVENTORY", 1, V2F(635, 185)}, window);
	weap.stats = (item_stat_t){100, 10, 10};
	hel.stats = (item_stat_t){100, 10, 10};
	chest.stats = (item_stat_t){100, 10, 10};
	gaunt.stats = (item_stat_t){100, 10, 10};
	pants.stats = (item_stat_t){100, 10, 10};
	weap.obj = w;
	hel.obj = h;
	chest.obj = c;
	gaunt.obj = g;
	pants.obj = p;
	sweap.item = weap;
	shel.item = hel;
	schest.item = chest;
	sgaunt.item = gaunt;
	spants.item = pants;
	add_helmet(&shel, window);
	add_chest(&schest, window);
	add_pants(&spants, window);
	add_weapon(&sweap, window);
	add_gauntlets(&sgaunt, window);
	return (0);
}

void init_window_values(my_w_t *window)
{
	window->error_no = 0;
	PLAYER_NAME = NULL;
	window->clocker = init_timer();
	MOUSE_POS = (sfVector2i){0, 0};
	window->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL},
	GAME_TITLE, sfClose, NULL);
	window->displayed_scenes = NULL;
	window->click_released = sfTrue;
}

void init_text_values(my_w_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(window->scenes, PAUSE_GAME);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return;
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "VERSION_GAME");
	sfText_setString(bucket_texts->value, VERSION_GAME);
}

void init_key_control(my_w_t *window)
{
	window->key_player = malloc(sizeof(*window->key_player));
	window->key_player->up = (sfKeyCode *)sfKeyZ;
	window->key_player->down = (sfKeyCode *)sfKeyS;
	window->key_player->left = (sfKeyCode *)sfKeyQ;
	window->key_player->right = (sfKeyCode *)sfKeyD;
	window->key_player->up_1 = (sfKeyCode *)sfKeyUp;
	window->key_player->down_1 = (sfKeyCode *)sfKeyDown;
	window->key_player->left_1 = (sfKeyCode *)sfKeyLeft;
	window->key_player->right_1 = (sfKeyCode *)sfKeyRight;
	window->key_player->move = 1;
}

my_w_t init_my_window(void)
{
	my_w_t window;

	init_window_values(&window);
	if (!window.window || init_my_textures_lib(&window) != 0
	|| init_my_audio_lib(&window) != 0 || init_my_fonts_lib(&window) != 0
	|| init_my_scenes(&window) != 0 || init_my_map(&window) != 0
	|| !window.clocker.clock || init_inventory(&window) != 0
	|| init_my_buttons(&window) != 0) {
		window.error_no = 84;
		return (window);
	}
	init_text_values(&window);
	init_key_control(&window);
	init_movements(&window);
	window.current = hm_get_bucket(window.scenes, STARTING_SCENE_NAME);
	if (check_scene_not_created(window.current,
		"my_initializer.c", 42, STARTING_SCENE_NAME) != 0)
		window.error_no = 84;
	return (window);
}
