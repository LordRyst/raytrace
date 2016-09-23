#include "ray.h"

vector3 vecZero() {
  vector3 ret;
  ret.x = 0;
  ret.y = 0;
  ret.z = 0;
  return ret;
}

vector3 vecSub(vector3 first, vector3 second) {
  vector3 ret;
  ret.x = first.x - second.x;
  ret.y = first.y - second.y;
  ret.z = first.z - second.z;
  return ret;
}

float vecDot(vector3 first, vector3 second) {
  float ans = first.x * second.x + first.y * second.y + first.z * second.z;
}

vector3 vecScale(float scale, vector3 vec) {
  vector3 ret;
  ret.x = vec.x * scale;
  ret.y = vec.y * scale;
  ret.z = vec.z * scale;
}
