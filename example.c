#include "libdraw.h"
#include <string.h>
#include <stdio.h>

int main() {
  int h = 3; int w = 3;
  struct canvas* canvas = initCanvas(h, w);
  if (canvas == NULL) return 1;
  char* greg = strdup("gregory greg");
  if (greg != NULL) setAuthor(canvas, greg);
  setTime(canvas, time(NULL));
  invertPixels(canvas);
  togglePixel(canvas, 2, 2);
  togglePixel(canvas, 1, 2);
  togglePixel(canvas, 2, 1);
  togglePixel(canvas, 3, 2);

  for (int y = 0; y < h; y++) {
    for (int x = 0; x < w; x++) {
      printf("%s", getPixel(canvas, x+1, y+1) ? "@ " : ". ");
    }
    putchar(0xa); // newline character in hex (10th ASCII character)
  }
  printf("\nby: %s\ntime made: %s", canvas->author, ctime(&canvas->time));
  delCanvas(canvas);
  return 0;
}
