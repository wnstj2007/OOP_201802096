#include "board.h"
#include <cstdio>
#include <stdio.h>
#include <termio.h>

int getch(void){
    int ch;
    struct termios buf, save;
    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

int b[14][7];

int main()
{
    board* a = new board();
    char input;
    a->print_board();
    while(1)
    {
        a->create();
        a->print_board();
        do
        {
            do
            {
                input = getch();
            }
            while(input!='x'&&input!='a'&&input!='s'&&input!='d'&&input!='e'&&input!='q');
        }
        while(!a->move(input));
        a->explode();
    }

    return 0;
}