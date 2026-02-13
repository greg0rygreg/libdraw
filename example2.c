#include <stdio.h>
#include "libdraw.h"
#include <string.h>
#include <stdlib.h>

int main() {
  int h = 3; int w = 3;
  ld_canvas* canvas = ld_docanvas(h, w);
  if (canvas == NULL) return 1;
  char* greg = strdup("gregory greg");
  if (greg != NULL) ld_author(canvas, greg);
  ld_time(canvas, time(NULL));
  ld_fill(canvas, 1, 1, 3, 3, YELLOW);
  ld_setpixel(canvas, 1, 1, GREEN);
  ld_setpixel(canvas, 3, 1, GREEN);
  ld_fill(canvas, 1, 3, 3, 3, RED);
  
  ld_invertall(canvas);

  char s[14];
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      ld_FPbuf(canvas, x+1, y+1, s);
      printf("%s\x1b[0m", s);
    }
    putchar(10); // newline character (10th ASCII character)
  }
  printf("\x1b[0m");
  printf("\nwho: %s\nwhen: %s", canvas->author, ctime(&canvas->time));
  ld_uncanvas(canvas);
  return 0;
}

// gcc example2.c -o example2 libmenu.c