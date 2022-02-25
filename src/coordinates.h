#ifndef COORDINATES_H_
#define COORDINATES_H_

#include <stdio.h>
#include <stdlib.h>
#include <c/dbg.h>
#include <curses.h>
#include "bstrlib/bstrlib.h"

typedef struct COORDIANTE {
    int x, y;
} Cord;

Cord *Cord_New(int x, int y);
void Cord_Delete(Cord *c);

int Cord_Render_At(Cord *from,char c);
int Cord_Render_From(Cord *from,char c,int len);
int Cord_Render_To(Cord *from,char c,Cord *to);
int Cord_Render_Text(Cord *from, bstring data);

int Cord_Render_At_W(WINDOW* w, Cord *from,char c);
int Cord_Render_From_W(WINDOW* w, Cord *from,char c,int len);
int Cord_Render_To_W(WINDOW* w, Cord *from,char c,Cord *to);
int Cord_Render_Text_W(WINDOW* w, Cord *from, bstring data);
#endif // COORDINATES_H_
