#include "cross.h"

extern int b[14][7];

cross::cross(int c1, int c2, int c3, int c4, int c5)
{
    up = new block(c1, 3, 1);
    down = new block(c2, 3, 3);
    left = new block(c3, 2, 2);
    right = new block(c4, 4, 2);
    mid = new block(c5, 3, 2);
    b[1][3] = c1;
    b[3][3] = c2;
    b[2][2] = c3;
    b[2][4] = c4;
    b[2][3] = c5;
}
cross::~cross()
{
    delete(mid);
    delete(up);
    delete(down);
    delete(left);
    delete(right);
}
void cross::lotate()
{
    block* t_up = new block(right->get_color(), up->get_x(), up->get_y());
    block* t_down = new block(left->get_color(), down->get_x(), down->get_y());
    block* t_left = new block(up->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(down->get_color(), right->get_x(), right->get_y());
    b[t_up->get_y()][t_up->get_x()] = t_up->get_color();
    b[t_down->get_y()][t_down->get_x()] = t_down->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();
    delete(up);
    delete(down);
    delete(left);
    delete(right);
    up = t_up;
    down = t_down;
    left = t_left;
    right = t_right;
}
void cross::rotate()
{
    block* t_up = new block(left->get_color(), up->get_x(), up->get_y());
    block* t_down = new block(right->get_color(), down->get_x(), down->get_y());
    block* t_left = new block(down->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(up->get_color(), right->get_x(), right->get_y());
    b[t_up->get_y()][t_up->get_x()] = t_up->get_color();
    b[t_down->get_y()][t_down->get_x()] = t_down->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();
    delete(up);
    delete(down);
    delete(left);
    delete(right);
    up = t_up;
    down = t_down;
    left = t_left;
    right = t_right;
}
bool cross::can_left()
{
    bool ret = 1;

    if(b[up->get_y()][up->get_x()-1] != 0) ret = 0;
    if(b[down->get_y()][down->get_x()-1] != 0) ret = 0;
    if(b[left->get_y()][left->get_x()-1] != 0) ret = 0;

    return ret;
}
bool cross::can_right()
{
    bool ret = 1;

    if(b[up->get_y()][up->get_x()+1] != 0) ret = 0;
    if(b[right->get_y()][right->get_x()+1] != 0) ret = 0;
    if(b[down->get_y()][down->get_x()+1] != 0) ret = 0;

    return ret;
}
bool cross::can_down()
{
    bool ret = 1;

    if(b[down->get_y()+1][down->get_x()] != 0) ret = 0;
    if(b[left->get_y()+1][left->get_x()] != 0) ret = 0;
    if(b[right->get_y()+1][right->get_x()] != 0) ret = 0;

    return ret;
}
void cross::lmove()
{
    if(can_left())
    {
        b[up->get_y()][up->get_x()-1] = b[up->get_y()][up->get_x()];
        b[up->get_y()][up->get_x()] = 0;
        b[down->get_y()][down->get_x()-1] = b[down->get_y()][down->get_x()];
        b[down->get_y()][down->get_x()] = 0;
        b[left->get_y()][left->get_x()-1] = b[left->get_y()][left->get_x()];
        b[left->get_y()][left->get_x()] = 0;
        b[mid->get_y()][mid->get_x()-1] = b[mid->get_y()][mid->get_x()];
        b[mid->get_y()][mid->get_x()] = 0;
        b[right->get_y()][right->get_x()-1] = b[right->get_y()][right->get_x()];
        b[right->get_y()][right->get_x()] = 0;
        
        up->left();
        down->left();
        mid->left();
        left->left();
        right->left();
    }
}
void cross::rmove()
{
    if(can_right())
    {
        b[up->get_y()][up->get_x()+1] = b[up->get_y()][up->get_x()];
        b[up->get_y()][up->get_x()] = 0;
        b[down->get_y()][down->get_x()+1] = b[down->get_y()][down->get_x()];
        b[down->get_y()][down->get_x()] = 0;
        b[right->get_y()][right->get_x()+1] = b[right->get_y()][right->get_x()];
        b[right->get_y()][right->get_x()] = 0;
        b[mid->get_y()][mid->get_x()+1] = b[mid->get_y()][mid->get_x()];
        b[mid->get_y()][mid->get_x()] = 0;
        b[left->get_y()][left->get_x()+1] = b[left->get_y()][left->get_x()];
        b[left->get_y()][left->get_x()] = 0;
        
        up->right();
        down->right();
        mid->right();
        left->right();
        right->right();
    }
}
int cross::dline()
{
    if(can_down())
    {
        for(int i=11; i>0; i--)
        {
            for(int j=1; j<6; j++)
            {
                if(b[i+1][j] == 0)
                {
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }
            }
        }
        up->down();
        down->down();
        mid->down();
        left->down();
        right->down();
    }
    if(!can_down())
    {
        return down_all();
    }
    return 0;
}
int cross::down_all()
{
    for(int n=0; n<11; n++)
    {
        for(int i=11; i>0; i--)
        {
            for(int j=1; j<6; j++)
            {
                if(b[i+1][j] == 0)
                {
                    b[i+1][j] = b[i][j];
                    b[i][j] = 0;
                }
            }
        }
    }
    delete(this);
    return 1;
}