#include "config.h"
#include "types/pixel.h"
// #include <stdio.h>

void vertical_flag(Pixel **img, Pixel c1, Pixel c2, Pixel c3) {
  int third = IMAGE_WIDTH / 3;

  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      // printf("x: %d / 2000, y: %d / 1000\n", x, y);
      if (x < third) {
        // pixel_dump(&c3);
        img[y][x] = c3;
      } else if (x > third - 1 && x < 2 * third) {
        // pixel_dump(&c2);
        img[y][x] = c2;
      } else {
        // pixel_dump(&c1);
        img[y][x] = c1;
      }
    }
  }
}