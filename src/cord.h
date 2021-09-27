#ifndef _CORD_H
#define _CORD_H

#include <curses.h>
#include "bstrlib/bstrlib.h"
#include <stdlib.h>

typedef struct CORD {
    int row, col, crow,ccol;
} CORD;


CORD *CORD_create(WINDOW *w);
CORD *CORD_create_xy(int x, int y);
int CORD_middle_col(CORD *c,bstring data);

#endif //
