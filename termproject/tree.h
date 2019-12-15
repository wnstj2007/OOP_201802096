#ifndef TREE
#define TREE

#include "big_block.h"
#include "block.h"

class tree :public big_block {
protected:
    block* top;
    block* mid;
    block* bot;
    block* left;
    block* right;
public:
    tree(int c1, int c2, int c3);
    ~tree();
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