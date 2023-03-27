#pragma once
#include "Shape.h"
#include "Vertex.h"
#include <vcclr.h>
#ifndef _SPHERE_H
#define _SPHERE_H

class Sphere:public Shape {

private:
	Vertex Center;
	float Radius;
public:

	Sphere(Vertex Center, float radius, Color shapeColor);
	float Intersect(Vertex Ro, Vertex Rd);
	Vertex getCenter();
	float getRadius();
};

#endif // !
