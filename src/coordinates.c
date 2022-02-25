#include "coordinates.h"

Cord *Cord_New(int x, int y){
    Cord *c = calloc(1,sizeof(Cord));
    check(c!=NULL,"Could not create Cord");
    c->x = x;
    c->y = y;
    return c;
error:
    return NULL;
}

void Cord_Delete(Cord *c){
    free(c);
}

int Cord_Render_At(Cord *from,char c)
{
    log_error("Not Yet Implemented");
}

int Cord_Render_From(Cord *from,char c,int len)
{
    log_error("Not Yet Implemented");
}
int Cord_Render_To(Cord *from,char c,Cord *to)
{
    log_error("Not Yet Implemented");
}
int Cord_Render_Text(Cord *from, bstring data){
    mvprintw(from->y,from->x,"%s",bdata(data));
}

int Cord_Render_At_W(WINDOW* w, Cord *from,char c)
{
    log_error("Not Yet Implemented");
}
int Cord_Render_From_W(WINDOW* w, Cord *from,char c,int len)
{
    log_error("Not Yet Implemented");
}
int Cord_Render_To_W(WINDOW* w, Cord *from,char c,Cord *to)
{
    log_error("Not Yet Implemented");
}

int Cord_Render_Text_W(WINDOW *w,Cord *from, bstring data){
    mvwprintw(w,from->y,from->x,"%s",bdata(data));
}
