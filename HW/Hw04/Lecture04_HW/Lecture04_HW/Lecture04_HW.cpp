#include <iostream>
#include <GLFW/glfw3.h>
#pragma comment(lib, "Opengl32.lib")

bool rightMouseDown = false;
bool leftMouseDown = false;
bool rightMouseDragging = false;
bool leftMouseDragging = false;

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
            rightMouseDragging = false;
        }
        else if (action == GLFW_RELEASE)
        {
            rightMouseDown = false;
            rightMouseDragging = false;
        }
    }
    else if (button == GLFW_MOUSE_BUTTON_LEFT)
    {
        if (action == GLFW_PRESS)
        {
            leftMouseDown = true;
            leftMouseDragging = false;
        }
        else if (action == GLFW_RELEASE)
        {
            leftMouseDown = false;
            leftMouseDragging = false;
        }
    }
}

void cursorPosCallback(GLFWwindow* window, double xpos, double ypos)
{
    static double lastX = xpos;
    static double lastY = ypos;

    if (rightMouseDown && (xpos != lastX || ypos != lastY))
    {
        rightMouseDragging = true;
    }
    else if (leftMouseDown && (xpos != lastX || ypos != lastY))
    {
        leftMouseDragging = true;
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
        if (rightMouseDown && rightMouseDragging)
        {
            glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        }
        else if (leftMouseDown && leftMouseDragging)
        {
            glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
        }
        else if (rightMouseDown)
        {
            glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        }
        else if (leftMouseDown)
        {
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
        }
        else
        {
            glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        }

        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
