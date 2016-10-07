#ifndef GAME_SCREEN_H_
#define GAME_SCREEN_H_

#include <gb/gb.h>
#include <stdlib.h>

#define GROUND_HEIGHT 8U
#define HASJUMP 0x01
#define TRANSITIONNING 0x04
#define HASKEY 0x08
#define PLAYER_SIZE 16U


//SPRITES INDEX
#define BW_SPR_LEN 92U
#define WF_SPR_LEN 2U
#define SEA_SPR_LEN 16U
#define ENV_SPR_LEN 9U
#define DOG_SPR_LEN 12U

#define BW_INDEX 0U
#define WF_INDEX BW_SPR_LEN
#define SEA_INDEX WF_INDEX+WF_SPR_LEN
#define ENV_INDEX SEA_INDEX+SEA_SPR_LEN
#define DOG_INDEX ENV_INDEX+ENV_SPR_LEN

typedef enum {
	LEVEL1 = 0U,
	LEVEL2 = 1U,
	LEVEL3 = 2U,
	LEVEL4 = 3U,
	LEVEL5 = 4U,
	LEVEL6 = 5U,
	NOLEVEL,
} LEVELID;
typedef struct
{
	UBYTE x;
	UBYTE y;
	UBYTE w;
	UBYTE h;
} Box;
enum AnimationState
{
	IDLE,
	WALK,
	JUMP,
	CROUCH,
	CROUCHWALK,
	CROUCHTRANSITIONIN,
	CROUCHTRANSITIONOUT,
	CLIMB,
	CLIMBWALK,
	JUMPCLIMB,
	DEAD
};
typedef struct
{
	Box box;
	UBYTE originX;
	UBYTE originY;
	LEVELID originLevel;
	UBYTE used;
} KEY;
typedef struct
{
	Box* box;
	UBYTE locked;
} LOCK;
typedef struct{
	Box box;
	enum AnimationState state;//0 right, 1 left, 2 up, 3 down
	UBYTE img_index; //for animations with more than one frame
	BYTE dirX; //for walk and jump
	BYTE dirY;
	UBYTE timer; //for animations
	UBYTE booleanState;//JUMP TRANSITIONNING KEY
	BYTE vely;//y-velocity for jump
	LEVELID nextLevel;
	UBYTE newX;
	UBYTE newY;
	KEY* key;

} PLAYER;
typedef struct
{
	Box box;
	BYTE dirX;
	UBYTE img_index;
	UBYTE timer;
	UBYTE maxX;
	UBYTE minX;
} ENEMY;
typedef struct
{
	Box* boxes;
	size_t boxes_length;
	unsigned char* LvlTileMap;
	LOCK* lock;
	KEY* key;
	ENEMY* enemy;
} Level;





void init_screen();
void game_screen();
void game_over();
void switch_to_level(LEVELID);

#endif
