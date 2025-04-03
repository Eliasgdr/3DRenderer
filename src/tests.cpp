#ifndef TEST_CPP
#define TEST_CPP

#include "../include/tests.hpp"

void testsRenderer(){
	try {
        Renderer renderer(1280, 720, "3D Renderer");

        bool running = true;
        SDL_Event event;

        while (running) {
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    running = false;
                }
            }

            renderer.clear();
            
            renderer.drawLine2D(100, 100, 200, 200);
            renderer.drawPoint2D(150, 150);

            renderer.present();
        }

    } catch (const std::exception& e) {
        SDL_Log("Error: %s", e.what());
        //return -1;
    }
}
void testsVec3(){
	Vec3 v1 = Vec3(1.0f,1.0f,1.0f);
    Vec3 v2 = Vec3(3.0f,4.0f,5.0f);
    Vec3 v3 = v1 + v2;
    v3.print();
    v3 = v1 - v2;
    v3.print();
    v3 = v1 * 2.0f;
    v3.print();
    v3 = v1 ^ v2;
    v3.print();
    float t = v1*v2;
    std::cout << t << std::endl;
    v3 = v3.normalize();
    v3.print();
}
void testsMatrix4(){
    Matrix4 mat;
    mat = Matrix4::translation(1.0f,2.0f,3.0f);
    mat.print();
    mat = Matrix4::rotationX(0.0f);
    mat.print();
    mat = Matrix4::rotationY(0.0f);
    mat.print();
    mat = Matrix4::rotationZ(0.0f);
    mat.print();
    mat = Matrix4::scaling(4.0f,5.0f,6.0f);
    mat.print();
    mat = Matrix4::perspective(16.0f/9.0f, 0.1f, 1000.0f, M_PI/2.0f);
    mat.print();
    mat.m[0][3] = 2.0f;
    mat.print();
    mat = mat*mat;
    mat.print();
}
void testsMesh(){
    Mesh cube;
    cube = Mesh::cube(2.0f);
    cube.print();
}

#endif // TEST_CPP