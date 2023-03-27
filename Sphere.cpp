#include "Vertex.h"
#include "Sphere.h"
#include <math.h>


Sphere::Sphere(Vertex Center, float radius, Color shapeColor) {
	this->Center = Center;
	this->Radius = radius;
	this->shapeColor = shapeColor;
}

float Sphere::Intersect(Vertex Ro, Vertex Rd) {
	Vertex l = Center - Ro;
	float s = l * Rd;
	float l2 = l * l;
	float r2 = Radius * Radius;
	if (s < 0 && l2 > r2) return 0;//if true there is no intersect because ray beginning point outsite sphere
	float s2 = s * s;
	float m2 = l2 - s2;
	if (m2 > r2) return 0;
	float q = (float)sqrt(r2 - m2);
	if (l2 > r2) return s - q;
	else return s + q;
}

Vertex Sphere::getCenter() {
	return Center;
}

float Sphere::getRadius() {
	return Radius;
}