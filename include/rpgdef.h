/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#ifndef RPGDEF_H_
#define RPGDEF_H_
#include "rpg.h"

#define GAME window->game
#define SCENES GAME.scenes
#define CURRENT_SCENE GAME.current
#define DISPLAYED_SCENES GAME.displayed_scenes
#define FRAMERATE GAME.tools.framerate
#define CLICK_RELEASED GAME.tools.click_released
#define KEY_PLAYER GAME.key_player

#define LIBS GAME.libraries
#define AUDIO_LIB LIBS.audio
#define FONTS_LIB LIBS.fonts
#define TEXTURES_LIB LIBS.textures
#define ITEMS_LIB LIBS.items

#define MAP GAME.map

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

#define MOUSE_POS GAME.tools.mouse_pos

////////////////////////////////////// GAME DEFINES //////////////////////////

#define PLAYER GAME.player
#define PLAYER_NAME PLAYER.name
#define PLAYER_CHARACTER PLAYER.character
#define PLAYER_INVENTORY PLAYER.inventory
#define PLAYER_CHARAC PLAYER.stats

#define PLAYER_GOLDS PLAYER_INVENTORY.golds
#define PLAYER_ITEMS PLAYER_INVENTORY.items
#define PLAYER_WEAPON PLAYER_INVENTORY.weapon
#define PLAYER_HELMET PLAYER_INVENTORY.helmet
#define PLAYER_CHEST PLAYER_INVENTORY.chest
#define PLAYER_GAUNTLETS PLAYER_INVENTORY.gauntlets
#define PLAYER_PANTS PLAYER_INVENTORY.pants

#define ITEM_SELECTOR PLAYER_INVENTORY.selector

#define PLAYER_HEALTH PLAYER_CHARAC.health
#define PLAYER_ARMOR PLAYER_CHARAC.armor
#define PLAYER_SPECIALITY_NAME PLAYER_CHARAC.speciality_name
#define PLAYER_SPECIALITY PLAYER_CHARAC.speciality

#define MIN(X, Y) X >= Y ? Y : X
#define MAX(X, Y) X >= Y ? X : Y

#define KEY_PRESSED(key) \
sfKeyboard_isKeyPressed((sfKeyCode) GAME.key_player->key)

#endif /* RPGDEF_H_ */