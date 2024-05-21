#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

float moveFactor = 0.0f;
float scaleFactor = 1.0f;
float M_PI = 3.14159265358979323846f;

void errorCallback(int error, const char* description)
{
    std::cerr << "GLFW 오류: " << description << std::endl;
}

void drawCircle(float cx, float cy, float r, int num_segments)
{
    // 원의 내부를 그리는 부분
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.843f, 0.0f); // 원의 내부 색깔 (황금색)
    glVertex2f(cx, cy);
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();

    // 원의 테두리를 그리는 부분
    glLineWidth(5.0f); // 테두리 두께 설정
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 0.5f, 0.0f); // 테두리 색깔 (주황색)
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void drawSmallCircle(float cx, float cy, float r, int num_segments, double angle)
{
    // 작은 원의 위치 계산 (크기는 처음 그려지는 원의 1/3 크기)
    float small_radius = r * 0.33f;
    float newX = cx -0.19 * cos(angle);
    float newY = cy -0.19 * sin(angle);

    // 작은 원 그리기
    glColor3f(1.0f, 0.999f, 0.0f); // 황금색
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(newX, newY); // 작은 원의 중심 위치
    for (int i = 0; i <= num_segments; i++)
    {
        float theta = 2.0f * M_PI * float(i) / float(num_segments);
        float x = small_radius * cosf(theta);
        float y = small_radius * sinf(theta);
        glVertex2f(x + newX, y + newY);
    }
    glEnd();
}

void drawSquare(float size, double angle)
{
    // 정사각형의 네 꼭지점 계산
    float halfSize = size / 2.0f;
    float x1 = -halfSize;
    float y1 = -halfSize;
    float x2 = halfSize;
    float y2 = -halfSize;
    float x3 = halfSize;
    float y3 = halfSize;
    float x4 = -halfSize;
    float y4 = halfSize;

    // 회전 변환을 적용하여 각 꼭지점의 새로운 위치 계산
    float newX1 = x1 * cos(angle) - y1 * sin(angle);
    float newY1 = x1 * sin(angle) + y1 * cos(angle);
    float newX2 = x2 * cos(angle) - y2 * sin(angle);
    float newY2 = x2 * sin(angle) + y2 * cos(angle);
    float newX3 = x3 * cos(angle) - y3 * sin(angle);
    float newY3 = x3 * sin(angle) + y3 * cos(angle);
    float newX4 = x4 * cos(angle) - y4 * sin(angle);
    float newY4 = x4 * sin(angle) + y4 * cos(angle);

    // 정사각형 그리기
    glColor3f(0.0f, 0.0f, 1.0f); // 파란색
    glBegin(GL_QUADS);
    glVertex2f(newX1, newY1);
    glVertex2f(newX2, newY2);
    glVertex2f(newX3, newY3);
    glVertex2f(newX4, newY4);
    glEnd();

    // 정사각형의 테두리 그리기
    glLineWidth(2.0f); // 테두리 두께 설정
    glColor3f(0.0f, 0.0f, 0.0f); // 검정색
    glBegin(GL_LINE_LOOP);
    glVertex2f(newX1, newY1);
    glVertex2f(newX2, newY2);
    glVertex2f(newX3, newY3);
    glVertex2f(newX4, newY4);
    glEnd();

    // 별 그리기
    glColor3f(1.0f, 1.0f, 0.0f); 
    glBegin(GL_POLYGON); 
    glVertex2f(newX3 + 0.09f, newY3 + 0.05f); 
    glVertex2f(newX3, newY3 + 0.1f); 
    glVertex2f(newX3 + 0.1f, newY3 + 0.1f);
    glVertex2f(newX3 + 0.15f, newY3 + 0.2f);
    glVertex2f(newX3 + 0.2f, newY3 + 0.1f); 
    glVertex2f(newX3 + 0.3f, newY3 + 0.1f);
    glVertex2f(newX3 + 0.225f, newY3 + 0.05f); 
    glVertex2f(newX3 + 0.25f, newY3 - 0.05f); 
    glVertex2f(newX3 + 0.175f, newY3 - 0.025f);
    glVertex2f(newX3 + 0.15f, newY3 - 0.025f); 
    glVertex2f(newX3 + 0.075f, newY3 - 0.05f); 
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(newX3 + 0.09f, newY3 + 0.05f);
    glVertex2f(newX3, newY3 + 0.1f);
    glVertex2f(newX3 + 0.1f, newY3 + 0.1f);
    glVertex2f(newX3 + 0.15f, newY3 + 0.2f);
    glVertex2f(newX3 + 0.2f, newY3 + 0.1f);
    glVertex2f(newX3 + 0.3f, newY3 + 0.1f);
    glVertex2f(newX3 + 0.225f, newY3 + 0.05f);
    glVertex2f(newX3 + 0.25f, newY3 - 0.05f);
    glVertex2f(newX3 + 0.175f, newY3 - 0.025f);
    glVertex2f(newX3 + 0.15f, newY3 - 0.025f);
    glVertex2f(newX3 + 0.075f, newY3 - 0.05f);
    glEnd();
}

int main(void)
{
    if (!glfwInit())
        return -1;

    GLFWwindow* window;
    window = glfwCreateWindow(800, 800, "MuSoeunEngine", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);

    double startTime = glfwGetTime();

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // 원의 회전 속도
        double circleRotationSpeed = 2 * M_PI / 10.0; // 10초 주기로 회전

        // 정사각형의 회전 속도
        double squareRotationSpeed = 2 * M_PI / 10.0; // 10초 주기로 회전

        // 현재 시간을 기준으로 회전 각도 계산
        double currentTime = glfwGetTime();
        double elapsedTime = currentTime - startTime;
        double circleAngle = circleRotationSpeed * elapsedTime;
        double squareAngle = squareRotationSpeed * elapsedTime;

        // 화면의 1/3 크기로 원 그리기
        float radius = 0.3f;
        float centerX = -0.6f;
        float centerY = moveFactor;
        drawCircle(centerX, centerY, radius * scaleFactor, 100);

        // 작은 원 그리기 (원 안에 위치)
        drawSmallCircle(centerX, centerY, radius * scaleFactor, 100, circleAngle);

        // 화면 중앙에 정사각형 그리기
        drawSquare(radius * scaleFactor, squareAngle);

        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
