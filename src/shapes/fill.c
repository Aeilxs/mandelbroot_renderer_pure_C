#include "config.h"
#include "types/pixel.h"

void fill_image(Pixel **image, Pixel bg_color) {
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      printf("x: %d / %d, y: %d / %d\n", x, IMAGE_WIDTH, y, IMAGE_HEIGHT);
      image[y][x] = bg_color;
    }
  }
}