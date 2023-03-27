#include "Vertex.h"
#include "Triangle.h"
#include <math.h>


Triangle::Triangle(Vertex V0, Vertex V1, Vertex V2, Color shapeColor) {

	this->V0 = V0;
	this->V1 = V1;
	this->V2 = V2;
	this->shapeColor = shapeColor;

}


Vertex Triangle::getV0() {
	return V0;
}
Vertex Triangle::getV1() {
	return V1;
}
Vertex Triangle::getV2() {
	return V2;
}

float Triangle::Intersect(Vertex Ro, Vertex Rd) { // t = -((N*Ro + D)/N*Rd)  we need to t value to calculate ýntersect test


	Vertex normal; // normal vector
	Vertex R;
	float S, s1, s2, s3; // we need to traingle area variables

	normal = (V1 - V0).CrossProduct(V2 - V1); // we got normal vector N = (V1-V0) * (V2-V1);

	float D = -(normal * V0);
	float t = -(normal * Ro + D) / (normal * Rd);

	if (t > 0) // if t is bigger than 0 that means there is a intersect
	{
		R = Ro + Vertex().floatProduct(t, Rd); //calculate R point which is ýnstersect point

		//we need the answer that question. is R point inside or outside triangle

		S = (V1 - V0).CrossProduct(V2 - V1).Length();//triangle area


		s1 = (R - V0).CrossProduct(V2 - R).Length();
		s2 = (V1 - V0).CrossProduct(R - V1).Length();
		s3 = (V1 - R).CrossProduct(V2 - V1).Length();

		float difference = (float)Math::Abs(S - (s1 + s2 + s3));
		float epsilon = 0.005F;

		if (difference <= epsilon) return t; else return 0;
	}
	else return 0;


}

