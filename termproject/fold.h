#ifndef FOLD
#define FOLD

#include "big_block.h"
#include "block.h"

class fold : public big_block {
protected:
    block* tleft;
    block* tright;
    block* left;
    block* right;
public:
    fold(int c1, int c2, int c3);
    ~fold();
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