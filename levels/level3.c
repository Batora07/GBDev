/*
 * level1.c
 *
 *  Created on: 4 Oct 2016
 *      Author: efarhan
 */


#include <stdlib.h>
#include "../game_screen.h"

#define BOX3LENGTH 2

size_t boxes_lvl3_length = BOX3LENGTH;

const Box box_lvl3[BOX3LENGTH] =
{
		{56U,80U, 32U, 32U},
		{24U,144U, 136U, 16U}
};
const unsigned char Lvl3TileMap[] =
{
6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,19,21,27,29,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,20,22,28,30,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,23,25,31,33,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,24,26,32,34,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,3,
5,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,3,
5,12,14,12,2,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,11,13,11,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6
};

void init_lvl3()
{

}
void manage_physics_lvl3(PLAYER* player)
{
	if(player->box.x >= 8U && player->box.x <= 16U && player->box.y >= 144U-8U-8U )

	{
		if((player->state == CLIMBWALK && player->dirY == 1) || player->state == JUMP || player->state == IDLE)
		{
			player->box.x = 8U;
			player->box.y = 8U+PLAYER_SIZE;
			if(player->state == IDLE)
				player->state = JUMP;
			switch_to_level(LEVEL2);
		}
	}
}

Level lvl3 = {
		box_lvl3,
		boxes_lvl3_length,
		Lvl3TileMap,

};


