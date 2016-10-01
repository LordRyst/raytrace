#include "camera.h"
#include "ray.h"
#include "main.h"


void cameraRays() {
  int hw = width / 2;
  int hh = height / 2;
  int i = 0;
  for (int y = 0; y < height; y++) {
    for (int x = 0; x < width; x++) {
      ray point;
      point.origin.x = origin.x + x - hw;
      point.origin.y = origin.y + y - hh;
      point.origin.z = origin.z;
      point.direction.x = 0;
      point.direction.y = 0;
      point.direction.z = 1;
      initRays[i] = point;
      i++;
    }
  }
}
