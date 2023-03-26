#pragma once
namespace RayTracingEntering {


	class Vector {

	private:
		float x;
		float y;
		float z;

	public:

		Vector(float x, float y, float z);

		Vector(const Vector& v);

		int getX()const;
		int getY()const;
		int getZ()const;
		float Length();

		Vector Normalize();
		Vector CrossProduct(Vector& v);

		Vector operator + (const Vector& v)const;
		Vector operator - (const Vector& v)const;
		float operator * (const Vector& v)const;
		Vector operator * (float f)const;
		Vector operator /(float f)const;
		
	};


}