#include "triangle.h"
#include "ray.h"

float rayboxIntersect(ray r1, vector3 mins, vector3 maxs) {
  floattx1 = (mins.x - r1.origin.x)*r1.direction.x;
  floattx2 = (maxs.x - r1.origin.x)*r1.direction.x;
  floattmin = min(tx1, tx2);
  floattmax = max(tx1, tx2);
  floatty1 = (mins.y - r1.origin.y) * r1.direction.y;
  floatty2 = (maxs.y - r1.origin.y) * r1.direction.y;
  tmin = max(tmin, min(ty1, ty2));
  tmax = min(tmax, max(ty1, ty2));
  floattz1 = (mins.z - r1.origin.z) * r1.direction.z;
  floattz2 = (maxs.z - r1.origin.z) * r1.direction.z;
  tmin = max(tmin, min(tz1, tz2));
  tmax = min(tmax, max(tz1, tz2));
  if (tmax >= tmin) {
    //intersection
    if (tmax >= 0) {
      //origin inside box.
      return tmax;
    } else {
      //origin outside box.
      return 0 - tmax;
    }
  } else {
    return -INFINITY;
  }
}

void triangleClip(int triI, vector3 mins, vector3 maxs) {
  ray r1;
  r1.origin = triangles[triI].a.origin;
  r1.direction = vecNormal(vecSub(triangles[triI].b,
				  triangles[triI].a));
  float dist = rayboxIntersect(r1, mins, maxs);
  if (dist >= 0) {
    //intersect, started inside box;
    //set up r2
    //dist2 = rayboxIntersect(r2, mins, maxs);
    if (dist2 >= 0) {
      
    }
  }
}

void triangleClip(int triI, triangles* tris, vector3 mins, vector3 maxs) {
  //corners have largest area, followed by edges, followed by center.
  //profile to see if we should set center as default,
  //because these triangles will be from an only slightly bigger box.
  char class1 = triangleClass(triI, tris, mins, maxs);
  //class2, class3
  if (class1 == INSIDE) {
    if (class2 == INSIDE) {
      if (class3 == INSIDE) {
	return;//All inside, nothing to clip.
      } else if (class3 % 2 == 1) {
	//edge, split into quad.
	
      }
    }
  }
}
