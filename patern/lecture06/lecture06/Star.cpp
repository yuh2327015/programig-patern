// Star.cpp

#include "Star.hpp"
#include <GLFW/glfw3.h>

Star::Star() {
    // ������ ������ �ʿ信 ���� �߰��� �� �ֽ��ϴ�.
}

Star::~Star() {
    // �Ҹ��� ������ �ʿ信 ���� �߰��� �� �ֽ��ϴ�.
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
    // ���� ����
    glColor3f(m_R, m_G, m_B);

    // ��ġ ����
    glTranslatef(m_X, m_Y, 0.0f);

    // �� �׸���
    glBegin(GL_POINTS);
    glVertex2f(0.0f, 0.0f);
    glEnd();
}
