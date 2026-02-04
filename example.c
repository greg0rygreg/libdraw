#include "libdraw.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
  int h = 3; int w = 27; int i = 0;
  struct canvas* canvas = initCanvas(h, w);
  if (canvas == NULL) return 1;
  char* greg = strdup("gregory greg");
  if (greg != NULL) setAuthor(canvas, greg);
  setTime(canvas, time(NULL));
  for (i = 0; i < h-1; i++) setPixel(canvas, 1, i+1, BLACK);
  for (i = 0; i < 3; i++) setPixel(canvas, i+1, 3, BLACK);
  for (i = 0; i < 3; i++) setPixel(canvas, 6, i+1, RED);
  for (i = 0; i < 3; i++) setPixel(canvas, i+5, 1, RED);
  for (i = 0; i < 3; i++) setPixel(canvas, i+5, 3, RED);
  for (i = 0; i < 3; i++) setPixel(canvas, 9, i+1, GREEN);
  for (i = 0; i < 2; i++) setPixel(canvas, 10, i+2, GREEN);
  for (i = 0; i < 3; i++) setPixel(canvas, 13, i+1, YELLOW);
  for (i = 0; i < 3; i++) setPixel(canvas, i!=1? 14:15, i+1, YELLOW);
  for (i = 0; i < 3; i++) setPixel(canvas, 17, i+1, BLUE);
  for (i = 0; i < 3; i++) setPixel(canvas, i!=2? 18:19, i+1, BLUE);
  for (i = 0; i < 3; i++) setPixel(canvas, 21, i+1, MAGENTA);
  for (i = 0; i < 3; i++) setPixel(canvas, 23, i+1, MAGENTA);
  for (i = 0; i < 3; i++) { if (i != 2) setPixel(canvas, 22, i+1, MAGENTA); }
  for (i = 0; i < 3; i++) setPixel(canvas, 25, i+1, CYAN);
  for (i = 0; i < 3; i++) setPixel(canvas, 27, i+1, CYAN);
  for (i = 0; i < 3; i++) { if (i != 0) setPixel(canvas, 26, i+1, CYAN); }

  
  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      char* s = formatPixel(canvas, x+1, y+1);
      printf("%s", s);
      free(s);
    }
    putchar(10); // newline character (10th ASCII character)
  }
  printf("\x1b[0m");
  printf("\nwho: %s\nwhen: %s", canvas->author, ctime(&canvas->time));
  delCanvas(canvas);
  return 0;
}

// gcc example.c -o example libmenu.c