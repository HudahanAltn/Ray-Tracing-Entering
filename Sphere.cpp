#include "Vertex.h"
#include "Sphere.h"
#include <math.h>


Sphere::Sphere(Vertex Center, float radius, Color shapeColor) {
	this->Center = Center;
	this->Radius = Radius;
	this->shapeColor = shapeColor;
}

float Sphere::Intersect(Vertex Ro, Vertex Rd) {
	Vertex l = Center - Ro;
	float s = l * Rd;
	float l2 = l * l;
	float r2 = Radius * Radius;
	if (s < 0 && l2 > r2) return 0;
	float s2 = s * s;
	float m2 = l2 - s2;
	if (m2 > r2) return 0;
	float q = (float)Math::Sqrt(r2 - m2);
	if (l2 > r2) return s - q;
	else return s + q;
}

Vertex Sphere::getCenter() {
	return Center;
}

float Sphere::getRadius() {
	return Radius;
}