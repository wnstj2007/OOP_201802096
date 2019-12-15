#ifndef BLOCK
#define BLOCK
class block {
protected:
    int x;
    int y;
    int color;
public:
    block(int color, int x, int y);
    void down();
    void left();
    void right();
    int get_x();
    int get_y();
    int get_color();
};
#endif