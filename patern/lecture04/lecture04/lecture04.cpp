#include <iostream>
#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>

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

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(1.0f,0.0f,1.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		glfwSwapBuffers(window);
		
	}

	glfwTerminate();
	return 0;
}