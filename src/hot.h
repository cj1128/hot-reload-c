#include <stdbool.h>
#include <stdint.h>

typedef struct {
  void *memory;
  int width;
  int height;
  int pitch;
} hot_video;

void Render(hot_video *video);
