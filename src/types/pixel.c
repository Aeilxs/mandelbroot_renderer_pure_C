#include <stdint.h>
#include <stdlib.h>

#include "types/pixel.h"

Pixel construct_bgr_pixel(uint8_t r, uint8_t g, uint8_t b) {
  Pixel pixel;
  pixel.b = b;
  pixel.g = g;
  pixel.r = r;
  return pixel;
}

// clang-format off
Pixel construct_white_pixel() { return construct_bgr_pixel(255, 255, 255); }
Pixel construct_black_pixel() { return construct_bgr_pixel(0, 0, 0);       }
Pixel construct_blue_pixel()  { return construct_bgr_pixel(255, 0, 0);     }
Pixel construct_green_pixel() { return construct_bgr_pixel(0, 255, 0);     }
Pixel construct_red_pixel()   { return construct_bgr_pixel(0, 0, 255);     }
Pixel construct_rand_pixel()  { return construct_bgr_pixel((uint8_t)rand(), (uint8_t)rand(), (uint8_t)rand()); }
// clang-format on

void pixel_dump(Pixel *px) {
  printf("--- PIXEL DUMP ---\n");
  printf("R: %d\n", px->r);
  printf("G: %d\n", px->g);
  printf("B: %d\n", px->b);
  printf("\n");
}