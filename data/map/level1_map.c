#include "../../src/game_screen.h"
# include <stdlib.h>
const unsigned char Lvl1TileMap[] = {6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
5,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,12,3,
5,13,15,17,11,13,11,13,11,13,11,13,11,13,11,13,15,17,11,13,
5,14,16,18,12,14,12,14,12,14,12,14,12,14,12,14,16,18,12,14,
5,13,11,13,5,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,
5,14,12,14,5,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,
5,13,11,13,5,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,
5,14,12,14,5,14,12,14,12,14,12,14,3,14,12,14,12,14,12,14,
5,13,11,13,5,13,11,13,11,13,11,13,3,13,11,13,11,13,11,13,
5,14,12,14,5,14,12,14,12,14,12,14,3,14,12,14,12,14,12,14,
5,13,11,13,5,13,11,13,11,13,11,13,3,13,11,13,11,13,11,13,
5,14,12,14,5,14,12,14,12,14,12,14,6,6,6,6,6,6,6,3,
5,13,11,13,5,13,11,13,11,13,11,13,11,13,11,13,11,13,11,13,
5,14,15,17,5,14,12,14,12,14,12,14,12,14,12,14,15,17,12,14,
5,13,16,18,5,13,11,13,11,13,11,13,11,13,11,13,16,18,11,13,
5,14,12,14,5,14,12,14,12,14,12,14,12,14,12,14,12,14,12,14,
5,13,11,13,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,
6,14,12,14,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6,6};
size_t boxes_lvl1_length = 5;
Box box_lvl1[5] = 
{
{95U,96U,8U,40U},
{32U,144U,128U,16U},
{104U,96U,56U,8U},
{96U,128U,16U,32U},
{32U,152U,8U,120U}
};
LOCK locks_lvl1[1] =
{
    {&(box_lvl1[3]), 1U}
};
/*Level lvl1 = {
&box_lvl1,
 boxes_lvl1_length,
 Lvl1TileMap, locks_lvl1 };*/
