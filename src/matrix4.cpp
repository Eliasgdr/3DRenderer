#ifndef MATRIX4_CPP
#define MATRIX4_CPP

#include "../include/matrix4.hpp"

Matrix4::Matrix4(){ // Creates an idendity matrix;
	for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            m[i][j] = (i == j) ? 1.0f : 0.0f;
		}
	}
}

void Matrix4::print(){ // Prints the value of the matrix
	for (int i = 0; i < 4; ++i){
		std::cout << "|" << m[i][0];
        for (int j = 1; j < 4; ++j){
            std::cout << ", " << m[i][j];
		}
		std::cout << "|" << std::endl;
	}
	std::cout << "." << std::endl;
}


Matrix4 Matrix4::translation(float tx, float ty, float tz){ // Creates a translation matrix that translates by (tx,ty,tz)
	Matrix4 mat;
	mat.m[0][3]=tx;
	mat.m[0][3]=ty;
	mat.m[0][3]=tz;
	return mat;
}

Matrix4 Matrix4::rotationX(float angle){ // Creates a rotation matrix around the X axis
	Matrix4 mat;
	mat.m[1][1] = cos(angle);
	mat.m[2][2] = cos(angle);
	mat.m[1][2] = -sin(angle);
	mat.m[2][1] = -sin(angle);
	return mat;
}

Matrix4 Matrix4::rotationY(float angle){ // Creates a rotation matrix around the Y axis
	Matrix4 mat;
	mat.m[0][0] = cos(angle);
	mat.m[2][2] = cos(angle);
	mat.m[0][2] = sin(angle);
	mat.m[2][0] = -sin(angle);
	return mat;
	
}

Matrix4 Matrix4::rotationZ(float angle){ // Creates a rotation matrix around the Z axis
	Matrix4 mat;
	mat.m[0][0] = cos(angle);
	mat.m[1][1] = cos(angle);
	mat.m[0][1] = -sin(angle);
	mat.m[1][0] = sin(angle);
	return mat;
}

Matrix4 Matrix4::scaling(float sx, float sy, float sz){ // Creates a scaling matrix that scales by (sx,sy,sz)
	Matrix4 mat;
	mat.m[0][0] = sx;
	mat.m[1][1] = sy;
	mat.m[2][2] = sz;
	return mat;
}


Vec3 Matrix4::operator*(const Vec3& vec){ // Multiplies the matrix by a vector
	return Vec3(m[0][0]*vec.x + m[0][1]*vec.y + m[0][3]*vec.z + m[0][3],
				m[1][0]*vec.x + m[1][1]*vec.y + m[1][3]*vec.z + m[1][3],
				m[2][0]*vec.x + m[2][1]*vec.y + m[2][3]*vec.z + m[2][3]);
}

Matrix4 Matrix4::operator*(const Matrix4& other){ // Multiplies the matrix by an other matrix
	Matrix4 mat;
	for (int i = 0; i < 4; ++i){
        for (int j = 0; j < 4; ++j){
            mat.m[i][j] = m[i][0]*other.m[0][j] + m[i][1]*other.m[1][j] + m[i][2]*other.m[2][j] + m[i][3]*other.m[3][j];
		}
	}
	return mat;
}

Matrix4 Matrix4::perspective(float aspectRatio, float near, float far, float fov){ // Creates a perspective matrix that converts 3D points into 2D points
	Matrix4 mat;
	mat.m[0][0] = 1.0f / (aspectRatio*tan(fov/2.0f));
	mat.m[1][1] = 1.0f / tan(fov/2.0f);
	mat.m[2][2] = (far + near) / (near - far);
	mat.m[2][3] = (2*far*near) / (near - far);
	mat.m[3][2] = -1.0f;
	mat.m[3][2] = 0.0f;
	return mat;
}

	


#endif // MATRIX4_CPP