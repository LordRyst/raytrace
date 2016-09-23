#ifndef _CAMERA_H_
#define _CAMERA_H_
#include "ray.h"
#include "image.h"

typedef struct camera{
  vector3 origin;
  image* screen;
}camera;

void cameraCreate(camera * cam, vector3 origin, image* screen);
void cameraRays(camera* cam, ray* initRays);
  
#endif
