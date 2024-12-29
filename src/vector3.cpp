#ifndef VECTOR3_CPP
#define VECTOR3_CPP

#include "../include/vector3.hpp"
	
Vec3::Vec3() : x(0), y(0), z(0){} // Empty vector3 constructor

Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z){} // Vector3 constructor

void Vec3::print(){ // Prints the values of the vector
	std::cout << "("<< x << ", " << y << ", " << z << ")" << std::endl;
}

Vec3 Vec3::operator+(const Vec3& other){ // Add 2 vectors
	return Vec3(x + other.x,
				y + other.y,
				z + other.z);
}

Vec3 Vec3::operator-(const Vec3& other){ // Substract 2 vectors
	return Vec3(x - other.x,
				y - other.y,
				z - other.z);
}

float Vec3::operator*(const Vec3& other){ // Dot product of 2 vectors
	return x*other.x + y*other.y + z*other.z;
}

Vec3 Vec3::operator^(const Vec3& other){ // Cross product of 2 vectors
	return Vec3(y*other.z - z*other.y,
				z*other.x - x*other.z,
				x*other.y - y*other.x);
}

Vec3 Vec3::operator*(float scalar){ // Scale a vector with a float
	 return Vec3(scalar*x, scalar*y, scalar*z);
}

float Vec3::length(){ // Length (or magnitude) of the vector
	return sqrt(pow(x,2)+pow(y,2)+pow(z,2));
}

Vec3 Vec3::normalize(){ // Normalize the vector
	float magnitude = length();
	return Vec3(x/magnitude, y/magnitude, z/magnitude);
}

#endif // VECTOR3_CPP