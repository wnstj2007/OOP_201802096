#ifndef CROSS
#define CROSS

#include "big_block.h"
#include "block.h"

class cross : public big_block {
protected:
    block* mid;
    block* up;
    block* down;
    block* left;
    block* right;
public:
    cross(int c1, int c2, int c3, int c4, int c5);
    ~cross();
    void lotate();
    void rotate();
    bool can_left();
    bool can_right();
    bool can_down();
    void lmove();
    void rmove();
    int dline();
    int down_all();
};
#endif