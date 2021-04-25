#include <stdbool.h>
#include <stdint.h>

typedef struct {
  void *memory;
  int width;
  int height;
  int pitch;
} hot_video;

typedef struct {
  void *memory;
  uint32_t size;
  bool isInitialized;
} hot_memory;

#define RENDER_FUNC(name) void name(hot_memory *memory, hot_video *video)

typedef RENDER_FUNC(render_func);

#define KB(size) (1024 * (size))
#define MB(size) (1024 * KB(size))
#define GB(size) (1024 * MB(size))
