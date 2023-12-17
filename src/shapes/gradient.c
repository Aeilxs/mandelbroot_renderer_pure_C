#include "shapes/gradient.h"
#include "config.h"
#include "types/pixel.h"

void gradient(Pixel **image) {
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      printf("x: %d / %d, y: %d / %d\n", x, IMAGE_WIDTH, y, IMAGE_HEIGHT);
      int intensity = (y * 255) / IMAGE_WIDTH;
      image[y][x] = construct_bgr_pixel(intensity, intensity, intensity);
    }
  }
}