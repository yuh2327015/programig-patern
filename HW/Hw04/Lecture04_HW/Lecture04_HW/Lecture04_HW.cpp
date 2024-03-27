//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색
#include <iostream>
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>

bool rightMouseDown = false;
bool leftMouseDown = false;
bool rightMouseDragging = false;
bool leftMouseDragging = false;

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}
void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mo)
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
			rightMouseDragging = true;
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
			leftMouseDragging = true;
		}
		else if (action == GLFW_RELEASE)
		{
			leftMouseDown = false;
			leftMouseDragging = false;
		}
	}
}

int main(void)
{
	//glfw라이브러리 초기화
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

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		if (rightMouseDown)
		{
			glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		}
		if (leftMouseDown)
		{
			glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		}
		// 마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
		if (rightMouseDown && rightMouseDragging)
		{
			glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		}
		// 마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색
		else if (leftMouseDown && leftMouseDragging)
		{
			glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
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