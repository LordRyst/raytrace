#include "image.h"
#include "math.h"

void colorFlat(rayHit* hits, int numr, image bitmap){
  for (int i = 0; i < numr; i++) {
    if (hits[i].distSqr != INFINITY) {
      bitmap.rgb[i].r = 255;
      bitmap.rgb[i].g = 255;
    }
  }
}
