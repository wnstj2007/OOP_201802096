#include "fold.h"

extern int b[14][7];

fold::fold(int c1, int c2, int c3)
{
    state = 0;
    tright = new block(c1, 3, 1);
    tleft = new block(0, 2, 1);
    right = new block(c2, 3, 2);
    left = new block(c3, 2, 2);
    b[1][3] = c1;
    b[2][3] = c2;
    b[2][2] = c3;
}
fold::~fold()
{
    delete(tleft);
    delete(tright);
    delete(left);
    delete(right);
}
void fold::lotate()
{

    block* t_tleft = new block(tright->get_color(), tleft->get_x(), tleft->get_y());
    block* t_tright = new block(right->get_color(), tright->get_x(), tright->get_y());
    block* t_left = new block(tleft->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(left->get_color(), right->get_x(), right->get_y());
    
    b[t_tright->get_y()][t_tright->get_x()] = t_tright->get_color();
    b[t_tleft->get_y()][t_tleft->get_x()] = t_tleft->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();
    delete(tright);
    delete(tleft);
    delete(left);
    delete(right);
    tright = t_tright;
    tleft = t_tleft;
    left = t_left;
    right = t_right;

    state = (state-1+4)%4;
}
void fold::rotate()
{

    block* t_tleft = new block(left->get_color(), tleft->get_x(), tleft->get_y());
    block* t_tright = new block(tleft->get_color(), tright->get_x(), tright->get_y());
    block* t_left = new block(right->get_color(), left->get_x(), left->get_y());
    block* t_right = new block(tright->get_color(), right->get_x(), right->get_y());
    
    b[t_tright->get_y()][t_tright->get_x()] = t_tright->get_color();
    b[t_tleft->get_y()][t_tleft->get_x()] = t_tleft->get_color();
    b[t_left->get_y()][t_left->get_x()] = t_left->get_color();
    b[t_right->get_y()][t_right->get_x()] = t_right->get_color();
    delete(tright);
    delete(tleft);
    delete(left);
    delete(right);
    tright = t_tright;
    tleft = t_tleft;
    left = t_left;
    right = t_right;

    state = (state+1)%4;
}
bool fold::can_left()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
            if(b[tright->get_y()][tright->get_x()-1] != 0) ret = 0;
            if(b[left->get_y()][left->get_x()-1] != 0) ret = 0;
            break;
        case 1:
        case 2:
            if(b[left->get_y()][left->get_x()-1] != 0) ret = 0;
            if(b[tleft->get_y()][tleft->get_x()-1] != 0) ret = 0;
            break;
        case 3:
            if(b[tleft->get_y()][tleft->get_x()-1] != 0) ret = 0;
            if(b[right->get_y()][right->get_x()-1] != 0) ret = 0;
            break;
        default:
            break;
    }

    return ret;
}
bool fold::can_right()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
            if(b[tright->get_y()][tright->get_x()+1] != 0) ret = 0;
            if(b[right->get_y()][right->get_x()+1] != 0) ret = 0;
            break;
        case 1://ㄴ
            if(b[right->get_y()][right->get_x()+1] != 0) ret = 0;
            if(b[tleft->get_y()][tleft->get_x()+1] != 0) ret = 0;
            break;
        case 2:
            if(b[tright->get_y()][tright->get_x()+1] != 0) ret = 0;
            if(b[left->get_y()][left->get_x()+1] != 0) ret = 0;
            break;
        case 3: //ㄱ
            if(b[right->get_y()][right->get_x()+1] != 0) ret = 0;
            if(b[tright->get_y()][tright->get_x()+1] != 0) ret = 0;
            break;
        default:
            break;
    }

    return ret;
}
bool fold::can_down()
{
    bool ret = 1;
    switch (state)
    {
        case 0:
        case 1:
            if(b[right->get_y()+1][right->get_x()] != 0) ret = 0;
            if(b[left->get_y()+1][left->get_x()] != 0) ret = 0;
            break;
        case 2:
            if(b[left->get_y()+1][left->get_x()] != 0) ret = 0;
            if(b[tright->get_y()+1][tright->get_x()] != 0) ret = 0;
            break;
        case 3:
            if(b[tleft->get_y()+1][tleft->get_x()] != 0) ret = 0;
            if(b[right->get_y()+1][right->get_x()] != 0) ret = 0;
            break;
        default:
            break;
    }

    return ret;
}
void fold::lmove()
{
    if(can_left())
    {
        switch (state)
        {
            case 0:
                b[tright->get_y()][tright->get_x()-1] = b[tright->get_y()][tright->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                b[left->get_y()][left->get_x()-1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                b[right->get_y()][right->get_x()-1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                break;
            case 1:
                b[tleft->get_y()][tleft->get_x()-1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[left->get_y()][left->get_x()-1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                b[right->get_y()][right->get_x()-1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                break;
            case 2:
                b[tleft->get_y()][tleft->get_x()-1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[left->get_y()][left->get_x()-1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                b[tright->get_y()][tright->get_x()-1] = b[tright->get_y()][tright->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                break;
            case 3:
                b[tleft->get_y()][tleft->get_x()-1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[tright->get_y()][tright->get_x()-1] = b[tright->get_y()][tright->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                b[right->get_y()][right->get_x()-1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                break;
            default:
                break;
        }
        tleft->left();
        tright->left();
        left->left();
        right->left();
    }
}
void fold::rmove()
{
    if(can_right())
    {
        switch (state)
        {
            case 0:
                b[tright->get_y()][tright->get_x()+1] = b[tright->get_y()][tright->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                b[right->get_y()][right->get_x()+1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                b[left->get_y()][left->get_x()+1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                break;
            case 1:
                b[tleft->get_y()][tleft->get_x()+1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[right->get_y()][right->get_x()+1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                b[left->get_y()][left->get_x()+1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                break;
            case 2:
                b[tright->get_y()][tright->get_x()+1] = b[tright->get_y()][right->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                b[tleft->get_y()][tleft->get_x()+1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[left->get_y()][left->get_x()+1] = b[left->get_y()][left->get_x()];
                b[left->get_y()][left->get_x()] = 0;
                break;
            case 3:
                b[tright->get_y()][tright->get_x()+1] = b[tright->get_y()][tright->get_x()];
                b[tright->get_y()][tright->get_x()] = 0;
                b[tleft->get_y()][tleft->get_x()+1] = b[tleft->get_y()][tleft->get_x()];
                b[tleft->get_y()][tleft->get_x()] = 0;
                b[right->get_y()][right->get_x()+1] = b[right->get_y()][right->get_x()];
                b[right->get_y()][right->get_x()] = 0;
                break;
            default:
                break;
        }
        tleft->right();
        tright->right();
        left->right();
        right->right();
    }
}
int fold::dline()
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
        tleft->down();
        tright->down();
        left->down();
        right->down();
    }
    if(!can_down())
    {
        return down_all();
    }
    return 0;
}
int fold::down_all()
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