#include "libdraw.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int h = 3; int w = 27; int i = 0;
  ld_canvas* canvas = ld_docanvas(h, w);
  if (canvas == NULL) return 1;
  char* greg = strdup("gregory greg");
  if (greg != NULL) ld_author(canvas, greg);
  ld_time(canvas, time(NULL));
  for (i=0; i<h; i++)
    ld_setpixel(canvas, 1, i+1, BLACK);
  for (i=0; i<3; i++) {
    ld_setpixel(canvas, i+1, 3, BLACK);
    ld_setpixel(canvas, 6, i+1, RED);
    ld_setpixel(canvas, i+5, 1, RED);
    ld_setpixel(canvas, i+5, 3, RED);
    ld_setpixel(canvas, 9, i+1, GREEN);
    ld_setpixel(canvas, 10, i+2, GREEN);
    ld_setpixel(canvas, 13, i+1, YELLOW);
    ld_setpixel(canvas, i!=1? 14:15, i+1, YELLOW);
    ld_setpixel(canvas, 17, i+1, BLUE);
    ld_setpixel(canvas, i!=2? 18:19, i+1, BLUE);
    ld_setpixel(canvas, 21, i+1, MAGENTA);
    ld_setpixel(canvas, 23, i+1, MAGENTA);
    if (i != 2)
      ld_setpixel(canvas, 22, i+1, MAGENTA);
    ld_setpixel(canvas, 25, i+1, CYAN);
    ld_setpixel(canvas, 27, i+1, CYAN);
    if (i != 0)
      ld_setpixel(canvas, 26, i+1, CYAN);
  }


  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      char* s = ld_fmtpixel(canvas, x+1, y+1);
      printf("%s\x1b[0m", s);
      free(s);
    }
    putchar(10); // newline character (10th ASCII character)
  }
  printf("\x1b[0m");
  printf("\nwho: %s\nwhen: %s", canvas->author, ctime(&canvas->time));
  ld_uncanvas(canvas);
  return 0;
}

// gcc example.c -o example libmenu.c