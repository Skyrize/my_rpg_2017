/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGDEF_H_
#define RPGDEF_H_
#include "rpg.h"

/////////////////////////////////// MAIN /////////////////////////////////

#define SCENES game->scenes
#define CURRENT_SCENE game->current
#define MANAGED_SCENES game->displayed_scenes
#define FRAMERATE game->tools.framerate
#define CLICK_RELEASED game->tools.click_released
#define KEY_PLAYER game->key_player

#define LIBS game->libraries
#define AUDIO_LIB LIBS.audio
#define FONTS_LIB LIBS.fonts
#define TEXTURES_LIB LIBS.textures
#define ITEMS_LIB LIBS.items

////////////////////////////////// INVENTORY ///////////////////////////////

#define INVENTORY game->inventory
#define GOLDS INVENTORY.golds
#define ITEMS INVENTORY.items
#define WEAPON INVENTORY.weapon
#define HELMET INVENTORY.helmet
#define CHEST INVENTORY.chest
#define GAUNTLETS INVENTORY.gauntlets
#define PANTS INVENTORY.pants

#define ITEM_SELECTOR INVENTORY.selector

///////////////////////////////// MAP ///////////////////////////////////////

#define MAP game->map

#define ZONE_COOR_X MAP.zone_coord.x
#define ZONE_COOR_Y MAP.zone_coord.y
#define AREA_COOR_X MAP.area_coord.x
#define AREA_COOR_Y MAP.area_coord.y
#define TILE_COOR_X MAP.tile_coord.x
#define TILE_COOR_Y MAP.tile_coord.y

#define ZONE MAP.zones[ZONE_COOR_Y][ZONE_COOR_X]
#define AREA MAP.areas[AREA_COOR_Y][AREA_COOR_X]
#define TILE AREA.tiles[TILE_COOR_Y][TILE_COOR_X]

#define ZONE_NAME ZONE.name
#define ZONE_FILEPATH ZONE.filepath
#define AREA_NAME AREA.name
#define AREA_ENCOUTER AREA.encounter
#define TILE_LIST TILE.displayed_tiles
#define TILE_BLOCK TILE.block

#define MOUSE_POS game->tools.mouse_pos

////////////////////////////////////// PLAYER //////////////////////////

#define PLAYER game->player
#define PLAYER_NAME PLAYER.name
#define PLAYER_CHARACTER PLAYER.character
#define PLAYER_STATS PLAYER.stats

#define PLAYER_HEALTH PLAYER_STATS.health
#define PLAYER_MAX_HP PLAYER_STATS.max_health
#define PLAYER_ARMOR PLAYER_STATS.armor
#define PLAYER_SPECIALITY PLAYER_STATS.speciality
#define PLAYER_SPECIALITY_NAME PLAYER_STATS.speciality_name

////////////////////////////////// USED //////////////////////////////

#define MIN(X, Y) X >= Y ? Y : X
#define MAX(X, Y) X >= Y ? X : Y

#define KEY_PRESSED(key) \
sfKeyboard_isKeyPressed((sfKeyCode) game->key_player.key)

#endif /* RPGDEF_H_ */