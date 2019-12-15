#ifndef BIGBLOCK
#define BIGBLOCK
class big_block {
protected:
    int state;
public:
    virtual void lotate() = 0;
    virtual void rotate() = 0;
    virtual bool can_left() = 0;
    virtual bool can_right() = 0;
    virtual bool can_down() = 0;
    virtual void lmove() = 0;
    virtual void rmove() = 0;
    virtual int dline() = 0;
    virtual int down_all() = 0;
};
#endif