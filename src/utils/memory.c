#include <stdio.h>
#include <stdlib.h>

#include "config.h"
#include "types/pixel.h"
#include "utils/memory.h"

void *imalloc(size_t size) {
  void *ptr;
  ptr = malloc(size);
  if (ptr == NULL) {
    fprintf(stderr, "Erreur lors de l'allocation de mémoire.\n");
    exit(EXIT_FAILURE);
  }
  return ptr;
}

Pixel **allocate_image() {
  Pixel **image = (Pixel **)imalloc(IMAGE_HEIGHT * sizeof(Pixel *));
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    image[y] = (Pixel *)imalloc(IMAGE_WIDTH * sizeof(Pixel));
  }

  return image;
}

void img_free(Pixel **img) {
  for (int y = 0; y < IMAGE_HEIGHT; y++) {
    free(img[y]);
  }
  free(img);
}