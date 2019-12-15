#include "block.h"

block::block(int color, int x, int y)
{
    this->color = color;
    this->x = x;
    this->y = y;
}
int block::get_x()
{
    return this->x;               
}
int block::get_y()
{
    return this->y;
}
int block::get_color()
{
    return this->color;
}
void block::left()
{
    this->x = x-1;
}
void block::right()
{
    this->x = x+1;
}
void block::down()
{
    this->y = y+1;
}