#pragma once
#include "Shape.h"
#include "Vector.h"
#include <vcclr.h>
namespace RayTracingEntering
{
	using namespace System;
	using namespace System::Drawing;


	class Triangle :public Shape {

	private:

		Vector V0;
		Vector V1;
		Vector V2;

	public:

		Triangle(Vector V0, Vector V1, Vector V2, Color shapeColor);
		Triangle(const Triangle& t);

		Vector getV0();
		Vector getV1();
		Vector getV2();
		float Intersect(Vector Ro, Vector Rd);
	};

}