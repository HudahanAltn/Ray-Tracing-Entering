#include "Vertex.h"
#include <math.h>

Vertex::Vertex() {

}
Vertex::Vertex(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;

}


float Vertex::getX()const {

	return this->x;
}
float Vertex::getY()const {
	return this->y;
}
float Vertex::getZ()const {
	return this->z;
}

float Vertex::Length() {

	return (float)sqrt(x * x + y * y + z * z);
}

Vertex Vertex::Normalize() {
	float length = (float)sqrt(x * x + y * y + z * z); // vektör length
	x /= length;
	y /= length;
	z /= length;
	return *this; //normalized vector return
}


Vertex Vertex::CrossProduct(Vertex v) {
	return Vertex(y * v.z - z * v.y,
		          z * v.x - x * v.z, 
		          x * v.y - y * v.x);
}

Vertex Vertex::operator +(Vertex v) {
	return Vertex(x + v.x, y + v.y, z + v.z);
}
Vertex Vertex::operator -(Vertex v) {
	return Vertex(x - v.x, y - v.y, z - v.z);
}

float Vertex::operator *(Vertex v) {
	return x * v.x + y* v.y + z* v.z;
}

Vertex Vertex::operator *(float f) {
	return Vertex(f * x, f * y, f * z);
}
Vertex Vertex::operator /(float f) {
	return Vertex(x / f, y / f, z / f);
}

Vertex Vertex::floatProduct(float f, Vertex v) {

	return Vertex(f * v.getX(), f * v.getY(), f * v.getZ());
}
