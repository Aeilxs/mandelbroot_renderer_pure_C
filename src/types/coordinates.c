#include <stdio.h>

#include "config.h"
#include "types/coordinates.h"

Pos constructPos(int x, int y) {
  Pos p;
  p.x = x;
  p.y = y;
  return p;
}

Pos centerPos() {
  Pos p;
  p.x = IMAGE_WIDTH / 2;
  p.y = IMAGE_HEIGHT / 2;
  return p;
}

void pos_dump(Pos *pos) {
  printf("--- POS ---\n");
  printf("X: %d\n", pos->x);
  printf("Y: %d\n", pos->y);
}
