#ifndef WINDOW_H_
#define WINDOW_H_

#include <stdbool.h>
#include "coordinates.h"

typedef struct WIN {
    WINDOW *w;
    Cord *size;
    Cord *pos;
    Cord *max;
}Win;

Win *Win_New_Cord(Cord *size,Cord *pos);
Win *Win_New(int wid,int hei,int x,int y, bool box, bstring title);
void Win_Delete(Win*w);

int Win_Render_Text(Win *w,Cord *c,bstring data);
void Win_Refresh(Win *w);

#endif // WINDOW_H_
