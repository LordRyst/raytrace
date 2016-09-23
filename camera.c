#include "camera.h"
#include "ray.h"

void cameraCreate(camera* cam, vector3 origin, image* bitmap) {
  cam->origin = origin;
  cam->screen = bitmap;
}

void cameraRays(camera* cam,ray* initRays) {
  int width = (*cam).screen->width;
  int height = (*cam).screen->height;
  int hw = width / 2;
  int hh = height / 2;
  int i = 0;
  for (int y = 0; y < width; y++) {
    for (int x = 0; x < height; x++) {
      ray point;
      point.origin.x = x - hw;
      point.origin.y = y - hh;
      point.origin.z = -100;
      point.direction.x = 0;
      point.direction.y = 0;
      point.direction.z = 1;
      initRays[i] = point;
    }
  }
}
