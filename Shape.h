#pragma once

#include <vcclr.h>
namespace RayTracingEntering
{
	using namespace System;
	using namespace System::Drawing;

	class Shape // base class
	{
	public:
		gcroot<Color> ShapeColor; // color obejct

		virtual float Intersect(Vertex Ro, Vertex Rd) = 0; // virtual func
	};
}