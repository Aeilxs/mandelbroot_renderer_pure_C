#ifndef UTILS_INFOS_H
#define UTILS_INFOS_H

#include <stdbool.h>

/**
 * @brief Show progress
 *
 * @param current
 * @param max
 * @param last (e.g. index == max - 1)
 */
void show_progress(int current, int max, bool last);

#endif