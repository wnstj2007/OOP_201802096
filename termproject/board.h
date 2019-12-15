#ifndef BOARD
#define BOARD

#include <map>
#include <vector>
#include "fold.h"
#include "cross.h"
#include "tree.h"

//int b[14][7];

class board {
protected:
    fold* f;
    cross* c;
    tree* t;
    int type;
    int cur;
    int score;
    std::map<std::string, std::vector<std::string>* > blocks;
public:
    board();
    void print_board();
    std::string get_type(int cur);
    bool can_explode(int color);
    void delete_block(int color, std::vector<std::string> visit);
    void explode();
    void defeat();
    void create();
    int move(char d);
    bool fall();
    int get_score();
    void merge();
};

#endif