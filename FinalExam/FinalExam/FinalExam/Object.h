#pragma once
#include <GLFW/glfw3.h>

// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) = 0;
    virtual void Draw() = 0;
};

// Derived classes
class Player : public Object {
public:
    Player(float x, float y, float size, float borderThickness)
        : x(x), y(y), size(size), borderThickness(borderThickness) {}

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }

    void Draw() override {
        float halfSize = size / 2.0f;
        float halfBorder = borderThickness / 2.0f;

        // 바깥 테두리 그리기
        glColor3f(0.0f, 0.0f, 0.0f); // 검정색
        glBegin(GL_QUADS);
        glVertex2f(x - halfSize - halfBorder, y - halfSize - halfBorder);
        glVertex2f(x + halfSize + halfBorder, y - halfSize - halfBorder);
        glVertex2f(x + halfSize + halfBorder, y + halfSize + halfBorder);
        glVertex2f(x - halfSize - halfBorder, y + halfSize + halfBorder);
        glEnd();

        // 플레이어 사각형 그리기
        glColor3f(1.0f, 0.0f, 0.0f); // 빨강색
        glBegin(GL_QUADS);
        glVertex2f(x - halfSize, y - halfSize);
        glVertex2f(x + halfSize, y - halfSize);
        glVertex2f(x + halfSize, y + halfSize);
        glVertex2f(x - halfSize, y + halfSize);
        glEnd();
    }

private:
    float x, y;
    float size;
    float borderThickness;
};

class EnemyBlock : public Object {
public:
    EnemyBlock(float x, float y, float width, float height)
        : x(x), y(y), width(width), height(height) {}

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }

    void Draw() override {
        // 장애물 그리기 (녹색: R:0, G:255, B:0)
        glColor3f(0.0f, 1.0f, 0.0f); // 녹색
        glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
        glEnd();
    }

    float GetX() const {
        return x;
    }

    float GetY() const {
        return y;
    }

    float GetWidth() const {
        return width;
    }

    void SetPosition(float newX, float newY) {
        x = newX;
        y = newY;
    }

private:
    float x, y;
    float width, height;
};

class Floor : public Object {
public:
    Floor(float y, float height, float width)
        : y(y), height(height), width(width) {}

    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }

    void Draw() override {
        // 바닥 그리기 (황색: R:255, G:200, B:15)
        glColor3f(1.0f, 200.0f / 255.0f, 15.0f / 255.0f); // 황색
        glBegin(GL_QUADS);
        glVertex2f(0.0f, y);
        glVertex2f(width, y);
        glVertex2f(width, y + height);
        glVertex2f(0.0f, y + height);
        glEnd();
    }

private:
    float y;
    float height;
    float width;
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
        // 충돌 처리 로직
    }

    void Draw() override {
        // 별 그리기
    }
};

int PhysicsAABB(Object& A, Object& B) {
    // AABB 충돌 검사 로직
    return 0;
}