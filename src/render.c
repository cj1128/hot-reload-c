#include "hot.h"

void
Render(hot_video *video)
{
  typedef uint32_t(*pixels_t)[video->pitch / 4];
  pixels_t pixels = (pixels_t)video->memory;

  static uint8_t offset = 0;

  for(int y = 0; y < video->height; y++) {
    for(int x = 0; x < video->width; x++) {
      uint8_t r = 255;
      uint8_t g = (uint8_t)x + offset;
      uint8_t b = (uint8_t)y;
      pixels[y][x] = (uint32_t)((r << 24) | (g << 16) | (b << 8) | 0xff);
    }
  }

  offset += 2;
}
