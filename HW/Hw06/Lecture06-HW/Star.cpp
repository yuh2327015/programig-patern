// Star.cpp

#include "Star.hpp"
#include <GLFW/glfw3.h>

Star::Star() {
    // 생성자 내용은 필요에 따라 추가할 수 있습니다.
}

Star::~Star() {
    // 소멸자 내용은 필요에 따라 추가할 수 있습니다.
}

void Star::setPosition(float x, float y) {
    m_X = x;
    m_Y = y;
}

void Star::setColor(float r, float g, float b) {
    m_R = r;
    m_G = g;
    m_B = b;
}

void Star::render() {
    // 색상 설정
    glColor3f(m_R, m_G, m_B);

    // 위치 설정
    glTranslatef(m_X, m_Y, 0.0f);

    // 별 그리기
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
}
