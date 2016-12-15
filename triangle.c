#include "triangle.h"
#include <math.h>
#include <stdlib.h>

void triangleSplit12(vec3 l, vec3 r1, vec3 r2, char dir, float center, vector* less, vector* more) {
  float a = l[dir];
  float b = r1[dir];
  float c = r2[dir];
  vec3 ab = r1 - l;
  vec3 ac = r2 - l;
  float bx = ab[dir];
  float cx = ac[dir];
  //a + bx * l = center
  //center + - a = bx * l
  //l == (center - a ) / bx
  float l1 = (center - a) / bx;
  float l2 = (center - a) / cx;
  vec3 dv;
  dec3 ev;
  dv[0] = l[0] + bx[0] * l1;
  dv[1] = l[1] + bx[1] * l1;
  dv[2] = l[2] + bx[2] * l1;
  ev[0] = l[0] + cx[0] * l2;
  ev[1] = l[1] + cx[1] * l2;
  ev[2] = l[2] + cx[2] * l2;
  triangle left;
  left[0] = l;
  left[1] = dv;
  left[2] = ev;
  triangle right1;
  triangle right2;
  if(b > c) {
    right1[0] = dv;
    right1[1] = r1;
    right1[2] = ev;
    right2[0] = ev;
    right2[1] = r1;
    right2[2] = r2;
  } else {
    right1[0] = dv;
    right1[1] = r1;
    right1[2] = r2;
    right2[0] = dv;
    right2[1] = ev;
    right2[2] = r2;
  }
  vectorAdd(less, &left);
  vectorAdd(more, &right1);
  vectorAdd(more, &right2);
}

void triangleSplit(vector* triangles, char dir, float center, vector* less, vector* more) {
  if (ax >= center) {
    if (bx >= center) {
      if (cx >= center) {
	vectorAdd(more, &cur);
      } else {
	triangleSplit12(cur.c, cur.a, cur.b, c, center, less, more);
      }
    } else {
      if (cx >= center) {
	triangleSplit12(cur.b, cur.a, cur.c, c, center, less, more);
      } else {
	triangleSplit21(cur.b, cur.c, cur.a, c, center, less, more);
      }
    }
  } else {
    if (bx >= center) {
      if (cx >= center) {
	triangleSplit12(cur.a, cur.b, cur.c, c, center, less, more);
      } else {
	triangleSplit21(cur.a, cur.c, cur.b, c, center, less, more);
      }
    } else {
      if (cx >= center) {
	triangleSplit21(cur.a, cur.b, cur.c, c, center, less, more);
      } else {
	vectorAdd(less, &cur);
      }
    }
  }
}

vector* triangleOct(vector* triangles, vector3* center) {
  vector* buckets = 0;
  vectorNew(buckets, 8, sizeof(triangle));
  vector* left = 0;
  vectorNew(left, triangles->next, sizeof(triangle));
  vector* right = 0;
  vectorNew(right, triangles->next, sizeof(triangle));
  triangle* data = (triangle*)triangles->data;
  triangleSplit(triangles, 0, center, left, right);
  vector* tl = 0;
  vectorNew(tl, left->next, sizeof(triangle));
  vector* bl = 0;
  vectorNew(bl, left->next, sizeof(triangle));
  triangleSplit(left, 1, center, bl, tl);
  free(left);
  vector* tr = 0;
  vectorNew(tr, right->next, sizeof(triangle));
  vector* br = 0;
  vectorNew(br, right->next, sizeof(triangle));
  triangleSplit(right, 1, center, br, tr);
  free(right);
  triangleSplit(tl, 2, center, &buckets[4], &buckets[0]);
  free(tl);
  triangleSplit(bl, 2, center, &buckets[6], &buckets[2]);
  free(bl);
  triangleSplit(tr, 2, center, &buckets[5], &buckets[1]);
  free(tr);
  triangleSplit(br, 2, center, &buckets[7], &buckets[3]);
  }
  free(br);
  return buckets;
}

float triangleHit(ray* rayI, triangle* triI) {
  vector3 e1 = vecSub(triI->b, triI->a);
  vector3 e2 = vecSub(triI->c, triI->a);

  vector3 h = vecCross(rayI->direction, e2);
  float g = vecDot(e1, h);
  if (g == 0) {
    return INFINITY;
  }
  float f = 1 / g;
  vector3 s = vecSub(rayI->origin, triI->a);
  float u = f * vecDot(s, h);
  if (u < 0 || u > 1.0) {
    return INFINITY;
  }
  vector3 q = vecCross(s, e1);
  float v = f * vecDot(rayI->direction, q);
  if (v < 0 || u + v > 1.0) {
    return INFINITY;
  }
  return f * vecDot(e2, q);
}
