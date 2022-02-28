#include "IO.h"

Win_IO *Win_IO_New(WINDOW *w) {
  Win_IO *io = calloc(1, sizeof(Win_IO));
  check(io != NULL, "Could not create Win_IO");

  int x,y;
  getmaxyx(w,y,x);
  io->size[0] = Cord_New(x,(y/3)*2);
  io->size[1] = Cord_New(x,(y/3));
  check(io->size[0]!=NULL&&io->size[1]!=NULL,"Could not create size");

  io->pos[0] = Cord_New(0,0);
  io->pos[1] = Cord_New(0,io->size[0]->y);
  check((io->pos[0]!=NULL)&&(io->pos[1]!=NULL),"Could not create pos");

  io->windows[0] = Win_New_Cord(io->size[0],io->pos[0],true,bfromcstr("Output"));
  io->windows[1] = Win_New_Cord(io->size[1],io->pos[1],true,bfromcstr("Input"));
  check(io->windows[0]!=NULL&&io->windows[1]!=NULL,"Could not create windows");

  return io;
error:
  wrefresh(w);
  return NULL;
}

void Win_IO_Delete(Win_IO *win){
    Win_Delete(win->windows[0]);
    Win_Delete(win->windows[1]);
    Cord_Delete(win->pos[0]);
    Cord_Delete(win->pos[1]);
    Cord_Delete(win->size[0]);
    Cord_Delete(win->size[1]);
    free(win);
}

bstring Win_IO_GetString(Win_IO *win,int i,Cord *c){
    char *buf = (char *)calloc(1024,sizeof(char));
    mvwgetstr(win->windows[i]->w,c->y,c->x,buf);
    bstring out = bfromcstr(buf);
    free(buf);
    return out;
}


void Win_IO_Refresh(Win_IO *win, int i){
    wrefresh(win->windows[i]->w);
    Win_Title_Box(win->windows[i]);
}

void Win_IO_Clear(Win_IO *win, int i){
    wclear(win->windows[i]->w);
}

int Win_IO_WriteString(Win_IO *win,int i,Cord *c,bstring data){
    return Win_Render_Text(win->windows[i],c,data);
}

