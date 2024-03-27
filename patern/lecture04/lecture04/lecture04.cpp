#include <iostream>
#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>

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
	glfwSetErrorCallback();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		
	}

	glfwTerminate();
	return 0;
}