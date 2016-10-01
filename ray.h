#ifndef _RAY_H_
#define _RAY_H_

typedef struct vector3 {
  float x;
  float y;
  float z;
}vector3;

vector3 vecAdd(vector3 first, vector3 second);
vector3 vecSub(vector3 first, vector3 second);
float vecDot(vector3 first, vector3 second);
vector3 vecCross(vector3 first, vector3 second);
vector3 vecScale(float scale, vector3 vec);
vector3 vecZero();
vector3 vecNew(float a, float b, float c);

typedef struct ray {
  vector3 origin;
  vector3 direction;
}ray;

#endif
