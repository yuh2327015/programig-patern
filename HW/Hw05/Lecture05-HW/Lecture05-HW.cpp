﻿#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;
double lastX = 0.0;
double lastY = 0.0;
bool mouseLeftPressed = false;
bool mouseRightPressed = false;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    if (key == GLFW_KEY_UP && action == GLFW_PRESS)
    {
        moveFactor += 0.01f;
    }
    if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
    {
        scaleFactor += 0.1f;
    }
}

void cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
{
    if (mouseLeftPressed)
    {
        float dx = xpos - lastX;
        float dy = ypos - lastY;
        moveFactor += dy * 0.01f;
    }
    if (mouseRightPressed)
    {
        float dx = xpos - lastX;
        scaleFactor += dx * 0.001f;
    }
    lastX = xpos;
    lastY = ypos;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        mouseLeftPressed = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE)
    {
        mouseLeftPressed = false;
    }
    if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
    {
        mouseRightPressed = true;
    }
    else if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_RELEASE)
    {
        mouseRightPressed = false;
    }
}

int render()
{
    glBegin(GL_TRIANGLES);
    //점1
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f * scaleFactor, (0.0f + moveFactor) * scaleFactor);
    //점2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f * scaleFactor, (0.5f + moveFactor) * scaleFactor);
    //점3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f * scaleFactor, (0.5f + moveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.0f * scaleFactor, (1.0f + moveFactor) * scaleFactor);
    //점2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.25f * scaleFactor, (0.25f + moveFactor) * scaleFactor);
    //점3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f * scaleFactor, (-0.5f + moveFactor) * scaleFactor);

    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.15f * scaleFactor, (0.5f + moveFactor) * scaleFactor);
    //점2
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-0.5f * scaleFactor, (0.5f + moveFactor) * scaleFactor);
    //점3
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(0.5f * scaleFactor, (-0.5f + moveFactor) * scaleFactor);


    glEnd();

    return 0;
}


int main(void)
{
    //glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        render();

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;

}
