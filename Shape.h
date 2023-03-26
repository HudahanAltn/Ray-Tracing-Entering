#pragma once

#include <vcclr.h>
#include "Vector.h"
namespace RayTracingEntering
{
	using namespace System;
	using namespace System::Drawing;

	class Shape // base class
	{
	public:
		gcroot<Color> shapeColor; // color obejct

		virtual float Intersect(Vector Ro, Vector Rd) = 0; // virtual func
	};
}