#include <stdio.h>

#include "types/bmp_header.h"

// clang-format off
BMPHeader construct_bmp_header(uint32_t width, uint32_t height) {
  BMPHeader header;

  // has to be 0x4D42 => BM
  header.signature       = 0x4D42;
  header.headerSize      = 40;     // 40 bytes => BITMAPINFOHEADER
  header.width           = width;
  header.height          = height;
  header.planes          = 1;
  header.bitsPerPixel    = 24;
  header.compression     = 0;
  header.imageSize       = width * height * (header.bitsPerPixel / 8);
  header.xPixelsPerMeter = 0;
  header.yPixelsPerMeter = 0;
  header.colorsUsed      = 0;
  header.colorsImportant = 0;
  header.dataOffset      = sizeof(BMPHeader);
  header.fileSize        = sizeof(BMPHeader) + (width * height * (header.bitsPerPixel / 8));
  return header;
}
// clang-format on

void header_dump(BMPHeader *header) {
  printf("--- BMP HEADER ---\n");
  printf("SIGNATURE:          %x\n", header->signature);
  printf("SIZE:               %d\n", header->fileSize);
  printf("WIDTH:              %d\n", header->width);
  printf("HEIGHT:             %d\n", header->height);
  printf("PLANES:             %d\n", header->planes);
  printf("BITS/PIXEL:         %d\n", header->bitsPerPixel);
  printf("COMPRESSION:        %d\n", header->compression);
  printf("IMAGE SIZE:         %d\n", header->imageSize);
  printf("X PIXELS PER METER: %d\n", header->xPixelsPerMeter);
  printf("Y PIXELS PER METER: %d\n", header->yPixelsPerMeter);
  printf("COLORS USED:        %d\n", header->colorsUsed);
  printf("COLORS IMPORTANT:   %d\n", header->colorsImportant);
  printf("\n");
}
