#ifndef UTILS_MEMORY_H
#define UTILS_MEMORY_H

#include "types/pixel.h"
/**
 * @brief malloc & check if null ptr
 *
 * @param size
 */
void *imalloc(size_t size);

/**
 * @brief Allocate 2D array with the use of config.h
 */
Pixel **allocate_image();

/**
 * @brief Free 2D array image with the use of config.h
 */
void img_free(Pixel **img);

#endif