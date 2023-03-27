#pragma once
#include "Shape.h"
#include "Vertex.h"
#include <vcclr.h>


#ifndef _TRIANGLE_H
#define _TRIANGLE_H

	class Triangle :public Shape {

	private:

		Vertex V0;
		Vertex V1;
		Vertex V2;

	public:

		Triangle(Vertex V0, Vertex V1, Vertex V2, Color shapeColor);
	
		Vertex getV0();
		Vertex getV1();
		Vertex getV2();

		float Intersect(Vertex Ro, Vertex Rd);
	};
#endif // !_TRIANGLE_H



