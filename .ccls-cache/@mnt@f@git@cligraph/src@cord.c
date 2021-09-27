#include "cord.h"

CORD *CORD_create(WINDOW *w){
    CORD *c = calloc(1,sizeof(CORD));
    getmaxyx(w, c->row, c->col);
    c->crow = c->row/2;
    c->ccol = c->col/2;
    return c;
}

CORD *CORD_create_xy(int x, int y){
    CORD *c = calloc(1,sizeof(CORD));
    c->row = y;
    c->col = x;
    c->crow = c->row/2;
    c->ccol = c->col/2;
    return c;
}

int CORD_middle_col(CORD *c,bstring data){
    return c->ccol-(blength(data)/2);
}
