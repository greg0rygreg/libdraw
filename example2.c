#include <stdio.h>
#include "libdraw.h"
#include <string.h>
#include <stdlib.h>

int main() {
  int h = 3; int w = 3;
  Canvas* canvas = initCanvas(h, w);
  if (canvas == NULL) return 1;
  char* greg = strdup("gregory greg");
  if (greg != NULL) setAuthor(canvas, greg);
  setTime(canvas, time(NULL));
  fillPixels(canvas, 1, 1, 3, 3, YELLOW);
  setPixel(canvas, 1, 1, GREEN);
  setPixel(canvas, 3, 1, GREEN);
  fillPixels(canvas, 1, 3, 3, 3, RED);
  
  char s[14];
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      formatPixelB(canvas, x+1, y+1, s, 14);
      printf("%s\x1b[0m", s);
    }
    putchar(10); // newline character (10th ASCII character)
  }
  printf("\x1b[0m");
  printf("\nwho: %s\nwhen: %s", canvas->author, ctime(&canvas->time));
  delCanvas(canvas);
  return 0;
}

// gcc example2.c -o example2 libmenu.c