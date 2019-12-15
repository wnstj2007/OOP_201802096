#include "tree.h"

extern int b[14][7];

tree::tree(int c1, int c2, int c3)
{
    state = 0;
    top = new block(c1, 3, 1);
    mid = new block(c2, 3, 2);
    bot = new block(c3, 3, 3);
    left = new block(0, 2, 2);
    right = new block(0, 4, 2);
    b[1][3] = c1;
    b[2][3] = c2;
    b[3][3] = c3;
}
tree::~tree()
{
    delete(top);
    delete(mid);
    delete(bot);
}
void tree::lotate()
{
    if(state == 0)
        if(b[left->get_y()][left->get_x()] != 0 || b[right->get_y()][right->get_x()] != 0) return;
    block* t_top = new block(right->get_color(), top->get_x(), top->get_y());
    block* t_bot = new block(left->get_color(), bot->get_x(), bot->get_y());
    block* t_left = new block(top->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(bot->get_color(), right->get_x(), right->get_y());
    b[t_top->get_y()][t_top->get_x()] = t_top->get_color();
    b[t_bot->get_y()][t_bot->get_x()] = t_bot->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();

    delete(top);
    delete(bot);
    delete(left);
    delete(right);
    
    top = t_top;
    bot = t_bot;
    left = t_left;
    right = t_right;

    state = (state-1+2)%2;
}
void tree::rotate()
{
    if(state == 0)
        if(b[left->get_y()][left->get_x()] != 0 || b[right->get_y()][right->get_x()] != 0) return;
    block* t_top = new block(left->get_color(), top->get_x(), top->get_y());
    block* t_bot = new block(right->get_color(), bot->get_x(), bot->get_y());
    block* t_left = new block(bot->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(top->get_color(), right->get_x(), right->get_y());
    b[t_top->get_y()][t_top->get_x()] = t_top->get_color();
    b[t_bot->get_y()][t_bot->get_x()] = t_bot->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();

    delete(top);
    delete(bot);
    delete(left);
    delete(right);
    
    top = t_top;
    bot = t_bot;
    left = t_left;
    right = t_right;

    state = (state+1)%2;
}
bool tree::can_left()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
            if(b[top->get_y()][top->get_x()-1] != 0) ret = 0;
            if(b[mid->get_y()][mid->get_x()-1] != 0) ret = 0;
            if(b[bot->get_y()][bot->get_x()-1] != 0) ret = 0;
            break;
        case 1:
            if(b[left->get_y()][left->get_x()-1] != 0) ret = 0;
        default:
            break;
    }

    return ret;
}
bool tree::can_right()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
            if(b[top->get_y()][top->get_x()+1] != 0) ret = 0;
            if(b[mid->get_y()][mid->get_x()+1] != 0) ret = 0;
            if(b[bot->get_y()][bot->get_x()+1] != 0) ret = 0;
            break;
        case 1:
            if(b[right->get_y()][right->get_x()+1] != 0) ret = 0;
        default:
            break;
    }

    return ret;
}
bool tree::can_down()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
            if(b[bot->get_y()+1][bot->get_x()] != 0) ret = 0;
            break;
        case 1:
            if(b[left->get_y()+1][left->get_x()] != 0) ret = 0;
            if(b[mid->get_y()+1][mid->get_x()] != 0) ret = 0;
            if(b[right->get_y()+1][right->get_x()] != 0) ret = 0;
        default:
            break;
    }

    return ret;
}
void tree::lmove()
{
    if(can_left())
    {
        switch (state)
        {
            case 0:
                b[top->get_y()][top->get_x()-1] = b[top->get_y()][top->get_x()];
                b[top->get_y()][top->get_x()] = 0;
                b[mid->get_y()][mid->get_x()-1] = b[mid->get_y()][mid->get_x()];
                b[mid->get_y()][mid->get_x()] = 0;
                b[bot->get_y()][bot->get_x()-1] = b[bot->get_y()][bot->get_x()];
                b[bot->get_y()][bot->get_x()] = 0;
                break;
            case 1:
                b[left->get_y()][left->get_x()-1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                b[mid->get_y()][mid->get_x()-1] = b[mid->get_y()][mid->get_x()];
                b[mid->get_y()][mid->get_x()] = 0;
                b[right->get_y()][right->get_x()-1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                break;
            default:
                break;
        }
        top->left();
        bot->left();
        mid->left();
        left->left();
        right->left();
    }
}
void tree::rmove()
{
    if(can_right())
    {
        switch (state)
        {
            case 0:
                b[top->get_y()][top->get_x()+1] = b[top->get_y()][top->get_x()];
                b[top->get_y()][top->get_x()] = 0;
                b[mid->get_y()][mid->get_x()+1] = b[mid->get_y()][mid->get_x()];
                b[mid->get_y()][mid->get_x()] = 0;
                b[bot->get_y()][bot->get_x()+1] = b[bot->get_y()][bot->get_x()];
                b[bot->get_y()][bot->get_x()] = 0;
                break;
            case 1:
                b[right->get_y()][right->get_x()+1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                b[mid->get_y()][mid->get_x()+1] = b[mid->get_y()][mid->get_x()];
                b[mid->get_y()][mid->get_x()] = 0;
                b[left->get_y()][left->get_x()+1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                break;
            default:
                break;
        }
        
        top->right();
        bot->right();
        mid->right();
        left->right();
        right->right();
    }
}
int tree::dline()
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
        top->down();
        mid->down();
        bot->down();
        left->down();
        right->down();
    }
    if(!can_down())
    {
        return down_all();
    }
    return 0;
}
int tree::down_all()
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