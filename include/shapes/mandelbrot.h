#ifndef SHAPES_MANDELBROT_H
#define SHAPES_MANDELBROT_H

#include "config.h"
#include "types/pixel.h"

/**
 * @param Translate coordinate x y to complex numbers
 */
void to_complex(int x, int y, double *real, double *imag);

/**
 * @brief Check if a point is inside mandelbrot structure
 *
 * @param creal
 * @param cimag
 * @param imax
 */
int mandelbrot(double creal, double cimag, int imax);

/**
 * @brief Print pixels in 2D array to generate mandelbrot structure
 *
 * @param image
 * @param imax
 */
void generate_mandelbrot(Pixel **image, int imax);

#endif
