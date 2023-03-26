#include "Vector.h"
#include <math.h>
using namespace RayTracingEntering;

Vector::Vector(float x, float y, float z) {

	this->x = x;
	this->y = y;
	this->z = z;

}

Vector::Vector(const Vector& v) {

	this->x = v.x;
	this->y = v.y;
	this->z = v.z;

}
int Vector::getX()const {

	return this->x;
}
int Vector::getY()const {
	return this->y;
}
int Vector::getZ()const {
	return this->z;
}

float Vector::Length() {

	return (float)sqrt(x * x + y * y + z * z);
}

Vector Vector::Normalize() {
	float length = (float)sqrt(x * x + y * y + z * z); // vektör length
	x /= length;
	y /= length;
	z /= length;
	return *this; //normalized vector return
}


Vector Vector::CrossProduct(Vector& v) {
	return Vector(y * v.z - z * v.y , z * v.x - x * v.z , x * v.y - y * v.x);
}

Vector Vector::operator +(const Vector& v)const {
	return Vector(x + v.x, y + v.y, z + v.z);
}
Vector Vector::operator -(const Vector& v)const {
	return Vector(x - v.x, y - v.y, z - v.z);
}

float Vector::operator *(const Vector& v)const {
	return x * v.x, y * v.y, z * v.z;
}

Vector Vector::operator *(float f)const {
	return Vector(f*x,f*y,f*z);
}
Vector Vector::operator /(float f)const {
	return Vector(x/f,y/f,z/f);
}