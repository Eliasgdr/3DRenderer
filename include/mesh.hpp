#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include "matrix4.hpp"

class Mesh{
public:
	std::vector<Vec3> vertices; // List of Vec3 coordinates
	std::vector<int> edges; // List of indexes where 2 of them make an edge
	//std::vector<int> faces; // List of indexes where 3 of them make a face

	Mesh(); // Creates an empty mesh

	void print(); //Prints the value of the mesh

	static Mesh cube(float size); // Creates a cube centered in (0,0,0) of size size

};

#endif // MESH_HPP