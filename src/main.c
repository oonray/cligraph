#include <stdio.h>
#include <stdlib.h>
#include <c/dbg.h>
#include <curses.h>
#include <menu.h>

#include "cord.h"
#include "render.h"
#include "bstrlib/bstrlib.h"


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

static inline WINDOW *init(){WINDOW *w = initscr(); raw();keypad(stdscr,TRUE);noecho(); return w;}
static inline void end(){endwin();}


static struct tagbstring choices[] = {
    bsStatic("Choice 1"),
    bsStatic("Choice 2"),
    bsStatic("Choice 3"),
    bsStatic("Exit"),
    NULL,
};

int main(int argc, char *argv[]){
    WINDOW *w = init();
    CORD *cw = CORD_create(w);
    CORD *ps = CORD_create_xy(25, 10);
    bstring hello = cstr2bstr("Hello World!");

    MENU *my_menu;
    ITEM **my_items;
    ITEM *current;

    int choices_n = ARRAY_SIZE(choices);
    my_items = (ITEM **)calloc(choices_n+1,sizeof(ITEM *));

    for(int i = 0;i < choices_n; ++i){
        my_items[i] = new_item(choices[i].data,choices[i].data);
    }
    my_items[choices_n] = (ITEM*)NULL;
    my_menu = new_menu(my_items);
    post_menu(my_menu);
    refresh();

    char c;
    while((c = getch()) != 'q'){
        switch(c)
            {	case 'j':
                    menu_driver(my_menu, REQ_DOWN_ITEM);
                    break;
                case 'k':
                    menu_driver(my_menu, REQ_UP_ITEM);
                    break;
                case KEY_ENTER:
                    menu_driver(my_menu, REQ_TOGGLE_ITEM);
                    break;
            }
    }

    for(int i = 0;i < choices_n; ++i){
        free_item(my_items[i]);
    }
    free_menu(my_menu);


    getch();

    end();
    return 0;
}
