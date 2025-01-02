#ifndef MATRIX4_HPP
#define MATRIX4_HPP

#include <iostream>
#include <cmath>

#include "vector3.hpp"
#include "constants.hpp"

class Matrix4{
public:
	float m[4][4];

	Matrix4(); // Creates an idendity matrix;

	void print(); // Prints the value of the matrix

	static Matrix4 translation(float tx, float ty, float tz); // Creates a translation matrix that translates by (tx,ty,tz)
	static Matrix4 rotationX(float angle); // Creates a rotation matrix around the X axis
	static Matrix4 rotationY(float angle); // Creates a rotation matrix around the Y axis
	static Matrix4 rotationZ(float angle); // Creates a rotation matrix around the Z axis
	static Matrix4 scaling(float sx, float sy, float sz); // Creates a scaling matrix that scales by (sx,sy,sz)

	Vec3 operator*(const Vec3& vec); // Multiplies the matrix by a vector
	Matrix4 operator*(const Matrix4& other); // Multiplies the matrix by an other matrix

	static Matrix4x4 perspective(float aspectRatio, float near, float far, float fov); // Creates a perspective matrix that converts 3D points into 2D points

	
};

#endif // MATRIX4_HPP