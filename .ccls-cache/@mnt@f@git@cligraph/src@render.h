#ifndef _RENDER_H
#define _RENDER_H

#include <curses.h>
#include <stdlib.h>
#include "cord.h"
#include "bstrlib/bstrlib.h"

int RENDER_middle_screen(WINDOW *w,CORD *c,bstring data){
    wrefresh(w);
    mvwprintw(w,c->crow,CORD_middle_col(c,data),bdata(data));
    wrefresh(w);
    return 0;
}

int RENDER_CORD_screen(WINDOW *w,CORD *c,bstring data){
    wrefresh(w);
    mvwprintw(w,c->crow,c->ccol,bdata(data));
    wrefresh(w);
    return 0;
}


#endif //
