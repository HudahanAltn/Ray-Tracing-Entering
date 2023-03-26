#pragma once

namespace RayTracingEntering {


	class Vector {

	private:
		float x;
		float y;
		float z;

	public:
		Vector();
		Vector(float x, float y, float z);

		Vector(const Vector& v);

		float getX()const;
		float getY()const;
		float getZ()const;
		float Length();

		Vector Normalize();
		Vector CrossProduct(Vector& v);

		Vector operator + (const Vector& v)const;
		Vector operator - (const Vector& v)const;
		float operator * (const Vector& v)const;
		Vector operator * (float f)const;
		Vector operator /(float f)const;
		/*Vector operator * (float f, Vector v);*/
		
	};

	Vector operator *(float f, Vector v) {

		return Vector(f * v.getX(), f * v.getY(), f * v.getZ());
	}
}