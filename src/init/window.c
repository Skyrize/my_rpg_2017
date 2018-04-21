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

int init_inventory(window_t *window)
{
	slot_t sweap;
	slot_t shel;
	slot_t schest;
	slot_t sgaunt;
	slot_t spants;
	slot_t item;
	item_t weap;
	item_t hel;
	item_t chest;
	item_t gaunt;
	item_t pants;
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
	ITEM_SELECTOR.base = NULL;
	ITEM_SELECTOR.dest = NULL;
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
	item.item.obj = create_obj(&(obj_data_t){"ITEM", "MYTHIC_CHEST_01", 1, V2F(635, 185)}, window);
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
	add_to_slot(&item, &V2I(0, 0), window);
	return (0);
}

void init_window_values(window_t *window)
{
	window->error_no = 0;
	PLAYER_NAME = NULL;
	window->clocker = init_timer();
	MOUSE_POS = (sfVector2i){0, 0};
	window->window = sfRenderWindow_create((sfVideoMode){WINDOW_WIDTH,
		WINDOW_HEIGHT, WINDOW_BITS_PER_PIXEL},
	GAME_TITLE, sfClose, NULL);
	DISPLAYED_SCENES = NULL;
	CLICK_RELEASED = sfTrue;
}

void init_text_values(window_t *window)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, PAUSE_GAME);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene)
		return;
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "VERSION_GAME");
	sfText_setString(bucket_texts->value, VERSION_GAME);
}

void init_key_control(window_t *window)
{
	KEY_PLAYER = malloc(sizeof(*KEY_PLAYER));
	KEY_PLAYER->up = (sfKeyCode *)sfKeyZ;
	KEY_PLAYER->down = (sfKeyCode *)sfKeyS;
	KEY_PLAYER->left = (sfKeyCode *)sfKeyQ;
	KEY_PLAYER->right = (sfKeyCode *)sfKeyD;
	KEY_PLAYER->up_1 = (sfKeyCode *)sfKeyUp;
	KEY_PLAYER->down_1 = (sfKeyCode *)sfKeyDown;
	KEY_PLAYER->left_1 = (sfKeyCode *)sfKeyLeft;
	KEY_PLAYER->right_1 = (sfKeyCode *)sfKeyRight;
	KEY_PLAYER->move = 1;
}

window_t init_my_window(void)
{
	window_t window;

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
	window.game.current = hm_get_bucket(window.game.scenes, STARTING_SCENE_NAME);
	if (check_scene_not_created(window.game.current,
		"src/init/window.c", 42, STARTING_SCENE_NAME) != 0)
		window.error_no = 84;
	return (window);
}
