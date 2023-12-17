#ifndef TYPES_COORDINATES_H
#define TYPES_COORDINATES_H

typedef struct _Pos {
  int x;
  int y;
} Pos;
typedef Pos (*PosConstructor)();

/**
 * @brief Return a position.
 *
 * @param x
 * @param y
 */
Pos constructPos(int x, int y);
/**
 * @brief Return the center pos.
 */
Pos centerPos();

/**
 * @brief Dump pos values in stdout
 *
 * @param pos
 */
void pos_dump(Pos *pos);

#endif
