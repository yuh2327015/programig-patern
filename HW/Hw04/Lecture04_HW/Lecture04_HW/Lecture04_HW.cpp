#include <iostream>
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>

bool rightMouseDown = false;
bool leftMouseDown = false;
bool rightMouseDragging = false;
bool leftMouseDragging = false;
int currentColor = 0; // 0: 검정, 1: 빨강, 2: 녹색, 3: 파랑, 4: 마젠타

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
}

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods)
{
    if (button == GLFW_MOUSE_BUTTON_RIGHT)
    {
        if (action == GLFW_PRESS)
        {
            rightMouseDown = true;
            currentColor = 1; // 빨간색
        }
        else if (action == GLFW_RELEASE)
        {
            rightMouseDown = false;
            rightMouseDragging = false;
            currentColor = 0; // 검정색
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            leftMouseDown = true;
            currentColor = 2; // 녹색
        }
        else if (action == GLFW_RELEASE)
        {
            leftMouseDown = false;
            leftMouseDragging = false;
            currentColor = 0; // 검정색
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    static double lastX = xpos;
    static double lastY = ypos;

    if (leftMouseDown && (xpos != lastX || ypos != lastY))
    {
        leftMouseDragging = true;
        currentColor = 4; // 마젠타색
    }
    else if (rightMouseDown && (xpos != lastX || ypos != lastY))
    {
        rightMouseDragging = true;
        currentColor = 3; // 파랑색
    }
    else
    {
        leftMouseDragging = false;
        rightMouseDragging = false;
    }

    lastX = xpos;
    lastY = ypos;
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(1280, 768, "WSYEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);
    glfwSetMouseButtonCallback(window, mouseButtonCallback);
    glfwSetCursorPosCallback(window, cursorPosCallback);

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        switch (currentColor)
        {
        case 1:
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // 빨강색
            break;
        case 2:
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // 녹색
            break;
        case 3:
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f); // 파랑색
            break;
        case 4:
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f); // 마젠타색
            break;
        default:
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // 검정색
            break;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}