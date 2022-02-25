#include "window.h"

Win *Win_New_Cord(Cord *size,Cord *pos)
{
    check(size!=NULL,"Could not Create window: no size");
    check(pos!=NULL,"Could not Create window: no pos");

    Win *w = calloc(1,sizeof(Win));
    check(w!=NULL,"Could not Create window: no memory");

    w->size=size;
    w->pos=pos;

    w->w = newwin(w->size->y,w->size->x,w->pos->y,w->pos->x);
    check(w->w!=NULL,"Window not created: curses error");
    wrefresh(w->w);
    return w;
error:
    return NULL;
}
Win *Win_New(int wid,int hei,int x,int y,bool box, bstring title){
    Cord *size = Cord_New(wid,hei);
    check(size!=NULL,"Could not create coordinates: size");
    Cord *pos = Cord_New(x,y);
    check(size!=NULL,"Could not create coordinates: pos");

    Win *w = Win_New_Cord(size,pos);
    if(box){
        box(w->w,0,0);
        wrefresh(w->w);
    }

    if(title!=NULL){
        Cord *c = Cord_New(1,0);
        Win_Render_Text(w,c,bformat(" %s ",bdata(title)));
        wrefresh(w->w);
    }
    return w;
error:
    return NULL;
}

void Win_Delete(Win*w){
    delwin(w->w);
    Cord_Delete(w->size);
    Cord_Delete(w->pos);
    free(w);
}

int Win_Render_Text(Win *w,Cord *c,bstring data){
    Cord_Render_Text_W(w->w,c,data);
    return blength(data);
}

void Win_Refresh(Win *w){
    wrefresh(w->w);
}
