#pragma once
	
#ifndef _VERTEX_H
#define _VERTEX_H


	class Vertex {

	private:
		float x;
		float y;
		float z;

	public:
		Vertex();
		Vertex(float x, float y, float z);


		float getX()const;
		float getY()const;
		float getZ()const;
		float Length();

		Vertex Normalize();
		Vertex CrossProduct(Vertex v);

		Vertex operator + (Vertex v);
		Vertex operator - (Vertex v);
		float operator * (Vertex v);
		Vertex operator * (float f);
		Vertex operator /(float f);

		Vertex floatProduct(float f, Vertex v);
	};

	//Vector operator *(float f, Vector v) {

	//	return Vector(f * v.getX(), f * v.getY(), f * v.getZ());
	//}

#endif // !_VECTOR_H


