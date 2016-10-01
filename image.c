#include "image.h"
#include "math.h"
#include "main.h"

void colorFlat(){
  for (int i = 0; i < numR; i++) {
    if (hits[i].distSqr != INFINITY) {
      bitmap.rgb[i].r = 255;
      bitmap.rgb[i].g = 255;
    }
    else {
      bitmap.rgb[i].b = 255;
    }
  }
}
