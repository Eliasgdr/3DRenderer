#ifndef MESH_CPP
#define MESH_CPP

#include "../include/mesh.hpp"

Mesh::Mesh(){ // Creates an empty mesh
}

void Mesh::print(){
	int len=vertices.size();
	for (int i=0;i<len;i++){
		vertices[i].print();
	}

}

Mesh Mesh::cube(float size){ // Creates a cube centered in (0,0,0) of size size
	size=size/2.0f;
	Mesh cube;
	for(int i=-1;i<=1;i+=2){
		for(int j=-1;j<=1;j+=2){
			for(int k=-1;k<=1;k+=2){
				cube.vertices.push_back(Vec3(i*size,j*size,k*size));
			}
		}
	}
	
    // Liste des arêtes sous forme de paires d'indices
    std::vector<int> edges = {
        0, 1,  1, 3,  3, 2,  2, 0,  // Arêtes de la face gauche
        4, 5,  5, 7,  7, 6,  6, 4,  // Arêtes de la face droite
        0, 4,  1, 5,  2, 6,  3, 7   // Arêtes reliant les faces gauche et droite
    };

    cube.edges = edges;
	return cube;
}



#endif //MESH_CPP