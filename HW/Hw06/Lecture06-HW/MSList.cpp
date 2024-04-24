// MSList.cpp

#include <GLFW/glfw3.h>

#include <iostream>
#include "MSList.hpp"

MSList::MSList() {

}

MSList::~MSList() {

}

void MSList::addStar(Star* star) {
    stars.push_back(star);
}

void MSList::renderAllStars() {
    std::cout << "Rendering stars..." << std::endl;


    for (int i = 0; i < 300; ++i) {
        Star* star = new Star();
        std::cout << "Star created: " << star << std::endl;

        float x = (float)(rand() % 1280);
        float y = (float)(rand() % 768);
        float r = (float)(rand() % 256) / 255.0f;
        float g = (float)(rand() % 256) / 255.0f;
        float b = (float)(rand() % 256) / 255.0f;


        star->setPosition(x, y);
        star->setColor(r, g, b);


        stars.push_back(star);
    }

    for (Star* star : stars) {
        star->render();
    }

    GLenum error = glGetError();
    if (error != GL_NO_ERROR) {
        std::cerr << "OpenGL error: " << error << std::endl;
    }
}
