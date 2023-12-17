#include <stdio.h>

#include "config.h"
#include "shapes/fill.h"
#include "shapes/gradient.h"
#include "shapes/mandelbrot.h"
#include "shapes/vertical_flag.h"
#include "types/bmp_header.h"
#include "types/coordinates.h"
#include "types/pixel.h"
#include "utils/fs.h"
#include "utils/infos.h"
#include "utils/memory.h"

int main() {
  FILE *file = open(OUTPUT_FILE, "wb");
  BMPHeader header = construct_bmp_header(IMAGE_WIDTH, IMAGE_HEIGHT);
  fwrite(&header, sizeof(header), 1, file);

  Pixel **image = allocate_image();

  generate_mandelbrot(image, MAX_ITERATION);

  printf("Printing data in file\n");
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    show_progress(y, IMAGE_HEIGHT, y == IMAGE_HEIGHT - 1);
    fwrite(image[y], sizeof(Pixel), IMAGE_WIDTH, file);
  }

  img_free(image);
  fclose(file);
  return 0;
}
