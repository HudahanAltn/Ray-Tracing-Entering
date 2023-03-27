#pragma once

#include <vcclr.h>
#include "Vertex.h"

#ifndef _SHAPE_H
#define _SHAPE_H

	using namespace System;
	using namespace System::Drawing;

	class Shape // base class
	{
	public:
		gcroot<Color> shapeColor; // color obejct

		virtual float Intersect(Vertex Ro, Vertex Rd) = 0; // virtual func
	};

#endif // 

