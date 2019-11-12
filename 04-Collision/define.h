#pragma once
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define MAP_WIDTH 2271
#define MAP_HEIGHT 1138

#define CELL_SIZE 180

#define MAX_FRAME_RATE 120

//Object ID from text
#define GROUND0_ID "Ground0"
#define GOOMBA_ID "goomba_0"

//Aladdin animation
enum AladdinAnimation
{
	ALADDIN = 100,
};

//Map animation

//Enemy animation
enum GoombaAnimation
{
	GOOMBA_WALKING = 701
};

//Texture ID
enum TEX_ID
{
	TEX_BBOX = -100,
	TEX_GROUND = -10,
	TEX_ALADDIN = 0,
	TEX_ALADDIN_LEFT = 1,
	TEX_MAP_DUNGEON = 10,
	TEX_DUNGEON_ENVIRONMENT = 11,
	TEX_MAP_BOSS = 20,
	TEX_APPLE = 30,
	TEX_GUARD = 40,
	TEX_GUARD_LEFT = 41,

};