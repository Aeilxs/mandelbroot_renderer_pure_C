#include <math.h>

#include "config.h"
#include "types/pixel.h"
#include "utils/infos.h"

void to_complex(int x, int y, double *real, double *imag) {
  *real = (x - IMAGE_WIDTH / 2.0) * 4.0 / IMAGE_WIDTH;
  *imag = (y - IMAGE_HEIGHT / 2.0) * 4.0 / IMAGE_WIDTH;
}

int mandelbrot(double creal, double cimag, int imax) {
  double real = creal;
  double imag = cimag;

  for (int i = 0; i < imax; i++) {
    double r2 = real * real;
    double i2 = imag * imag;

    if (r2 + i2 > 4.0) {
      return i;
    }

    imag = 2 * real * imag + cimag;
    real = r2 - i2 + creal;
  }

  return imax;
}

void generate_mandelbrot(Pixel **image, int imax) {
  printf("Printing 2D array\n");
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    show_progress(y, IMAGE_HEIGHT, y == IMAGE_HEIGHT - 1);
    for (int x = 0; x < IMAGE_WIDTH; x++) {
      double real, imag;
      to_complex(x, y, &real, &imag);

      int iteration = mandelbrot(real, imag, imax);

      image[y][x] = construct_bgr_pixel(
          (int)(sin(0.03 * iteration) * 255),
          (int)(sin(0.02 * iteration) * 255),
          (int)(sin(0.01 * iteration) * 255)
      );
    }
  }
}
