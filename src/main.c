#include "bstrlib/bstrlib.h"
#include "coordinates.h"
#include "widgets/IO.h"
#include "window.h"
#include <c/dbg.h>
#include <c/ringbuffer.h>
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>

static inline WINDOW *init() {
  WINDOW *w = initscr();
  curs_set(0);
  cbreak();
  keypad(stdscr, TRUE);
  // noecho();
  return w;
}
static inline void end() { endwin(); }

int x, y;

#define WID x / 5
#define HEI y / 3

#define WINDOWS 2
Win_IO *windows;
FILE *f;
RingBuffer *buffer;
char buff[1024];
char o_buff[1024];

int main(int argc, char *argv[]) {
  WINDOW *w = init();
  getmaxyx(w, y, x);
  wrefresh(w);

  buffer = RingBuffer_New(1024 * 4);
  windows = Win_IO_New(w);

  bstring in = bfromcstr("Input Command:\n");

  for (;;) {
    Cord *c = Cord_New(3, 1);
    Cord *c2 = Cord_New(3, 2);
    Win_IO_WriteString(windows, 1, c, in);

    bstring data = Win_IO_GetString(windows, 1, c2);
    Win_IO_Clear(windows, 0);
    Win_IO_Refresh(windows, 0);

    f = popen(bdata(data), "r");
    for (;;) {
      int l = fread(&buff, 1024, 1, f);
      int ln = strlen((char *)&buff);
      if (ln <= 0) {
        Win_IO_WriteString(windows, 0, c, bformat("No Data Recieved: %d", ln));
        Win_IO_Refresh(windows, 0);
        break;
      }

      c2->x = c2->x + ln;

      Win_IO_WriteString(windows, 0, c2, bfromcstr((char *)&buff));
      Win_IO_Refresh(windows, 0);
      if (l <= 0) {
        break;
      }
    }
    fclose(f);

    Win_IO_Clear(windows, 1);
    Win_IO_Refresh(windows, 1);
    Cord_Delete(c);
    Cord_Delete(c2);
  }

  Win_IO_Delete(windows);
  end();
  return 0;
}
