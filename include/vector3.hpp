#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vec3 {
public:
	float x,y,z;
	
	Vec3(float x, float y, float z); // Vector3 constructor

	Vec3 operator+(const Vec3& other); // Add 2 vectors
	Vec3 operator-(const Vec3& other); // Substract 2 vectors
	float operator^(const Vec3& other); // Cross product of 2 vectors
	Vec3 operator*(const Vec3& other); // Dot product of 2 vectors
	Vec3 operator*(float scalar); // Scale a vector with a float

	Vec3 normalize(); // Normalize the vector
	float length(); // Length (or magnitude) of the vector

};

#endif // VECTOR3_HPP