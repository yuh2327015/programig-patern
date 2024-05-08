#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int render()
{
    //a cos radius - b sin radius ,  a sin radius + b cos radius
    const int numSegments = 100;
    const float radius = 0.5f;
    const float PI = 3.14159265359f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.7f, 0.8f, 0.85f);
    glVertex2f(0.0f, 0.0f); // 중심점
    for (int i = 0; i <= numSegments; ++i)
    {
        float theta = 2.0f * PI * float(i) / float(numSegments); // 각도 계산
        float x = radius * cosf(theta); // x 좌표
        float y = radius * sinf(theta); // y 좌표
        glVertex2f(x, y); // 정점 추가
    }
    glEnd();
    return 0;
}

int main(void)
{
    //glfw라이브러리 초기화
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 800, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

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
