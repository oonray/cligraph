#include <stdio.h>
#include <stdlib.h>
#include <c/dbg.h>
#include <curses.h>
#include "bstrlib/bstrlib.h"
#include "coordinates.h"
#include "window.h"

static inline WINDOW *init(){WINDOW *w = initscr(); curs_set(0); cbreak();keypad(stdscr,TRUE);noecho(); return w;}
static inline void end(){endwin();}

int x,y;

#define WID x/5
#define HEI y/3

#define WINDOWS 3
Win *windows[WINDOWS];

int main(int argc, char *argv[]){
    WINDOW *w = init();
    getmaxyx(w,y,x);
    wrefresh(w);

    for(int i=0;i<WINDOWS;i++){
        windows[i] = Win_New(20,10,20*i,0,true,bformat("Hello %d",i));
    }

    bstring in = bfromcstr("Input String");
    bstring out = bfromcstr("%c Sendt");


    for(;;){
        int ch = getchar();
        for(int i=0;i<WINDOWS;i++){
            Cord *c = Cord_New(2,1);
            Win_Render_Text(windows[i],c,bformat(bdata(out),ch));
            Win_Refresh(windows[i]);
            Cord_Delete(c);
        }
    }

    for(int i=0;i<WINDOWS;i++){
        Win_Delete(windows[i]);
    }
    end();
    return 0;
}
