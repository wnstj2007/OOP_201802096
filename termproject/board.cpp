#include "board.h"
#include "block.h"
#include "cross.h"
#include "fold.h"
#include "tree.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <string>
#include <unistd.h>

extern int b[14][7];

board::board()
{
    for(int i=0; i<14; i++) 
    {
        for(int j=0; j<7; j++)
        {
            if(i==0||i==13||j==0||j==6)
            {
                b[i][j] = -1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }
    srand((unsigned int)time(0));
    type = rand()%3;
}
void board::print_board()
{
    system("clear");
    std::cout << "score : " << score << std::endl;
    std::cout << "next : " << get_type(type) << std::endl;
    for(int i=1; i<13; i++) 
    {
        for(int j=1; j<6; j++)
        {
            if(b[i][j] == 0)
            {
                std::cout << "  .";
            }
            else if(b[i][j] == 1)
            {
                printf("%3d", b[i][j]);
            }
            else if(b[i][j] == 2)
            {
                printf("\x1b[31m%3d", b[i][j]);
                printf("\x1b[0m");
            }
            else if(b[i][j] == 3)
            {
                printf("\x1b[32m%3d", b[i][j]);
                printf("\x1b[0m");
            }
            else if(b[i][j] == 4)
            {
                printf("\x1b[34m%3d", b[i][j]);
                printf("\x1b[0m");
            }
        }
        std::cout << std::endl;
    }
}
std::string board::get_type(int cur)
{
    std::string abc[] = {"fold","cross","tree"};
    return abc[cur];
}
bool board::can_explode(int color)
{
    int cnt = 0;
    bool ret = 0, tmp = 0;
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<6; j++)
        {
            int down = b[i+1][j];
            int right = b[i][j+1];
            int up = b[i-1][j];
            int left = b[i][j-1];
            std::string t = std::to_string(i)+" "+std::to_string(j);
            std::string temp;
            blocks[t] = new std::vector<std::string>;
            if(b[i][j] == color)
            {
                if(up == color || up == 1)
                {
                    temp = std::to_string(i-1)+" "+std::to_string(j);
                    blocks[t]->push_back(temp);
                }
                if(down == color || down == 1)
                {
                    temp = std::to_string(i+1)+" "+std::to_string(j);
                    blocks[t]->push_back(temp);
                }
                if(left == color || left == 1)
                {
                    temp = std::to_string(i)+" "+std::to_string(j-1);
                    blocks[t]->push_back(temp);
                }
                if(right == color || right == 1)
                {
                    temp = std::to_string(i)+" "+std::to_string(j+1);
                    blocks[t]->push_back(temp);
                }
            }
        }
    }
    std::queue<std::string> list;
    for(int i=1; i<13; i++)
    {
        for(int j=1; j<6; j++)
        {
            if(b[i][j] == color)
            {
                list.push(std::to_string(i)+" "+std::to_string(j));
            }
        }
    }
    while(!list.empty())
    {
        cnt = 0;
        std::vector<std::string> visit;
        std::vector<std::string>* li;
        std::queue<std::string> queue;
        std::string abc = list.front();
        list.pop();
        queue.push(abc);
        while (!queue.empty())
        {
            std::string next;
            next = queue.front();
            queue.pop();
            if (std::find(visit.begin(), visit.end(), next) == visit.end())
            {
                visit.push_back(next);
                li = blocks[next];
                for (int i = 0; i < (int)li->size(); i++)
                    queue.push(li->at(i));
            }
        }
        for (auto it = visit.begin(); it != visit.end(); it++)
        {
            int ti = stoi(*it);
            int tj;
            if(ti < 10)
            {
                tj = (*it).at(2)-48; //'0' = 48
            }
            else
            {
                tj = (*it).at(3)-48;
            }
            if(b[ti][tj] == color) cnt++;
        }
        tmp = (cnt>=4);
        if(tmp)
        {
            delete_block(color, visit);
            ret = 1;
        } 
    }
    
    return ret;
}
void board::create()
{
    if(type == 0)
    {
        if(b[1][3] != 0 ||b[2][3] != 0 || b[2][2] != 0) defeat();
        int c1 = rand()%4+1;
        int c2 = rand()%4+1;
        int c3 = rand()%4+1;
        f = new fold(c1, c2, c3);
    }
    else if(type == 1)
    {
        if(b[1][3] != 0 ||b[2][3] != 0 || b[2][2] != 0 || b[3][3] != 0 || b[2][4] != 0) defeat();
        int c1 = rand()%4+1;
        int c2 = rand()%4+1;
        int c3 = rand()%4+1;
        int c4 = rand()%4+1;
        int c5 = rand()%4+1;
        c = new cross(c1,c2,c3,c4,c5);
    }
    else
    {
        if(b[1][3] != 0 ||b[2][3] != 0 || b[3][3] != 0) defeat();
        int c1 = rand()%4+1;
        int c2 = rand()%4+1;
        int c3 = rand()%4+1;
        t = new tree(c1,c2,c3);
    }
    cur = type;
    type = rand()%3;
}
int board::move(char d)
{
    int ret = 0;
    switch (d)
    {
        case 'a':
            if(cur == 0) f->lmove();
            else if(cur == 1) c->lmove();
            else t->lmove();
            break;
        case 's':
            if(cur == 0) ret = f->dline();
            else if(cur == 1) ret = c->dline();
            else ret = t->dline();
            break;
        case 'd':
            if(cur == 0) f->rmove();
            else if(cur == 1) c->rmove();
            else t->rmove();
            break;
        case 'x':
            if(cur == 0) ret = f->down_all();
            else if(cur == 1) ret = c->down_all();
            else ret = t->down_all();
            break;
        case 'e':
            if(cur == 0) f->rotate();
            else if(cur == 1) c->rotate();
            else t->rotate();
            break;
        case 'q':
            if(cur == 0) f->lotate();
            else if(cur == 1) c->lotate();
            else t->lotate();
            break;
        default:
            break;
    }
    print_board();

    return ret;
}
void board::defeat()
{
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score is : " << score << std::endl;
    exit(1);
}
void board::delete_block(int color, std::vector<std::string> visit)
{
    for (auto it = visit.begin(); it != visit.end(); it++)
    {
        int ti = stoi(*it);
        int tj;
        if(ti < 10)
        {
            tj = (*it).at(2)-48;
        }
        else
        {
            tj = (*it).at(3)-48;
        }
        b[ti][tj] = 0;
    }
}
void board::explode()
{
    bool ex1, ex2, ex3, ex4;
    while(1)
    {
        ex2 = can_explode(2);
        ex3 = can_explode(3);
        ex4 = can_explode(4);
        if((ex2 == false) && ex2==ex3 && ex2==ex4)
        {
            break;
        }
        score++;
        sleep(1);
        print_board();
        sleep(1);
        merge();
    }
}
bool board::fall()
{
    switch (cur)
    {
        case 0:
            return f->can_down();
        case 1:
            return c->can_down();
        case 2:
            return t->can_down();
        default:
            break;
    }
}
int board::get_score()
{
    return score;
}
void board::merge()
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
    print_board();
}