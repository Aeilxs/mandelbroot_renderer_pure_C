#ifndef PIXEL_TYPES_H
#define PIXEL_TYPES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#pragma pack(push, 1)

/**
 * @brief Pixel
 *
 * @param b
 * @param g
 * @param r
 */
typedef struct _Pixel {
  uint8_t b;
  uint8_t g;
  uint8_t r;
} Pixel;
typedef Pixel (*PixelConstructor)();

#pragma pack(pop)

/**
 * @brief Return a pixel.
 * @param r uint8
 * @param g uint8
 * @param b uint8
 */
Pixel construct_bgr_pixel(uint8_t b, uint8_t g, uint8_t r);
/**
 * @brief Return a random pixel.
 */
Pixel construct_rand_pixel();
/**
 * @brief Return a white pixel.
 */
Pixel construct_white_pixel();
/**
 * @brief Return a black pixel.
 */
Pixel construct_black_pixel();
/**
 * @brief Return a red pixel.
 */
Pixel construct_red_pixel();
/**
 * @brief Return a green pixel.
 */
Pixel construct_green_pixel();
/**
 * @brief Return a blue pixel.
 */
Pixel construct_blue_pixel();

/**
 * @brief Dump pixel values in stdout
 *
 * @param px
 */
void pixel_dump(Pixel *px);

#endif // PIXEL_TYPES_H