#ifndef VECTOR3_HPP
#define VECTOR3_HPP

class Vec3 {
public:
	float x,y,z;
	
	Vec3(); // Empty vector3 constructor
	Vec3(float x, float y, float z); // Vector3 constructor

	void print(); // Prints the values of the vector

	Vec3 operator+(const Vec3& other); // Add 2 vectors
	Vec3 operator-(const Vec3& other); // Substract 2 vectors
	float operator*(const Vec3& other); // Dot product of 2 vectors
	Vec3 operator^(const Vec3& other); // Cross product of 2 vectors
	Vec3 operator*(float scalar); // Scale a vector with a float


	float length(); // Length (or magnitude) of the vector
	Vec3 normalize(); // Normalize the vector

};

#endif // VECTOR3_HPP