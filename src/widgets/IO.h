#ifndef IO_H_
#define IO_H_

#include "../coordinates.h"
#include "../window.h"

typedef struct Win_IO {
  Win *windows[2];
  Cord *pos[2];
  Cord *size[2];
} Win_IO;

Win_IO *Win_IO_New(WINDOW *w);
void Win_IO_Delete(Win_IO *win);
bstring Win_IO_GetString(Win_IO *win, int i, Cord *c);
void Win_IO_Refresh(Win_IO *win, int i);
void Win_IO_Clear(Win_IO *win, int i);
int Win_IO_WriteString(Win_IO *win, int i, Cord *c, bstring data);
#endif // IO_H_
