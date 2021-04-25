#include "hot.h"

typedef struct {
  uint8_t offset;
} hot_state;

uint32_t
Pack(uint8_t r, uint8_t g, uint8_t b)
{
  uint32_t result = (uint32_t)((r << 24) | (g << 16) | (b << 8) | 0xff);
  return result;
}

RENDER_FUNC(Render)
{
  hot_state *state = (hot_state *)memory->memory;

  if(!memory->isInitialized) {
    memory->isInitialized = true;

    state->offset = 0;
  }

  typedef uint32_t(*pixels_t)[video->pitch / 4];
  pixels_t pixels = (pixels_t)video->memory;

  for(int y = 0; y < video->height; y++) {
    for(int x = 0; x < video->width; x++) {
      uint8_t r = (uint8_t)x + (uint8_t)y;
      uint8_t g = (uint8_t)x + state->offset;
      uint8_t b = (uint8_t)y;

      pixels[y][x] = Pack(r, g, b);
    }
  }

  state->offset += 3;
}
