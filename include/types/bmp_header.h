#ifndef BMP_TYPE_H
#define BMP_TYPE_H

#include <stdint.h>

#pragma pack(push, 1)
/**
 * @brief Structure for BMP headers.
 *
 * @param signature       Signature "BM" (0x4D42)
 * @param fileSize        Total size of the BMP file in bytes
 * @param reserved        Reserved field (should be 0)
 * @param dataOffset      Offset beginning to the start of the image data
 * @param headerSize      Size of the BMP header (40 bytes for BITMAPINFOHEADER)
 * @param width           Width of the image in pixels
 * @param height          Height of the image in pixels
 * @param planes          Number of color planes (must be 1)
 * @param bitsPerPixel    Number of bits per pixel (usually 24 for RGB)
 * @param compression     Compression method (0 for no compression)
 * @param imageSize       Size of the image data in bytes
 * @param xPixelsPerMeter Horizontal pixels per meter
 * @param yPixelsPerMeter Vertical pixels per meter
 * @param colorsUsed      Number of colors used (0 for no palette)
 * @param colorsImportant Number of important colors (0 for all)
 */
typedef struct _BMPHeader {
  uint16_t signature;
  uint32_t fileSize;
  uint32_t reserved;
  uint32_t dataOffset;
  uint32_t headerSize;
  int32_t  width;
  int32_t  height;
  uint16_t planes;
  uint16_t bitsPerPixel;
  uint32_t compression;
  uint32_t imageSize;
  int32_t  xPixelsPerMeter;
  int32_t  yPixelsPerMeter;
  uint32_t colorsUsed;
  uint32_t colorsImportant;
} BMPHeader;
typedef BMPHeader (*BMPHeaderConstructor)(uint32_t width, uint32_t height);

#pragma pack(pop)

/**
 * @brief Write header.
 *
 * @param width
 * @param height
 */
BMPHeader construct_bmp_header(uint32_t width, uint32_t height);

/**
 * @brief Dump header values in stdout.
 *
 * @param header
 */
void header_dump(BMPHeader *header);

#endif // BMP_TYPE_H