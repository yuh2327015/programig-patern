#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Object.h"
#include "Transform.h"

// 윈도우 사이즈
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

// 배경색 (하늘색: R:0, G:30, B:100)
const float BG_COLOR_R = 0.0f;
const float BG_COLOR_G = 30.0f / 255.0f;
const float BG_COLOR_B = 100.0f / 255.0f;

// 화면의 1px은 기획서 상의 1cm와 동일
const float CM_TO_PIXEL = 1.0f;

// 바닥 높이 (100cm)
const float FLOOR_HEIGHT_CM = 100.0f;

// 장애물 속도 (픽셀/프레임)
const float OBSTACLE_SPEED = 2.0f;

void setupViewport() {
    // 뷰포트 설정
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // 좌표계 설정
    glOrtho(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main() {
    // GLFW 라이브러리 초기화
    if (!glfwInit()) {
        std::cerr << "GLFW 초기화 실패" << std::endl;
        return -1;
    }

    // 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Google Dino Run Copy Game", NULL, NULL);
    if (!window) {
        std::cerr << "윈도우 생성 실패" << std::endl;
        glfwTerminate();
        return -1;
    }

    // OpenGL 컨텍스트를 윈도우로 설정
    glfwMakeContextCurrent(window);

    // 배경색 설정
    glClearColor(BG_COLOR_R, BG_COLOR_G, BG_COLOR_B, 1.0f);

    // 플레이어 객체 생성
    float playerX = WINDOW_WIDTH / 2.0f;
    float playerY = FLOOR_HEIGHT_CM * CM_TO_PIXEL + 50.0f * CM_TO_PIXEL / 2.0f;
    float playerSize = 50.0f * CM_TO_PIXEL;
    float borderThickness = 3.0f * CM_TO_PIXEL;
    Player player(playerX, playerY, playerSize, borderThickness);

    // 바닥 객체 생성
    float floorY = FLOOR_HEIGHT_CM * CM_TO_PIXEL;
    float floorHeight = FLOOR_HEIGHT_CM * CM_TO_PIXEL;
    Floor floor(0.0f, floorY, WINDOW_WIDTH);

    // 장애물 객체 생성
    std::vector<EnemyBlock> obstacles;
    float obstacleWidth = 50.0f * CM_TO_PIXEL;
    float lowObstacleHeight = 100.0f * CM_TO_PIXEL;
    float highObstacleHeight = 300.0f * CM_TO_PIXEL;

    obstacles.emplace_back(1000.0f, floorY, obstacleWidth, lowObstacleHeight); // 낮은 장애물 1
    obstacles.emplace_back(1400.0f, floorY, obstacleWidth, lowObstacleHeight); // 낮은 장애물 2
    obstacles.emplace_back(1800.0f, floorY, obstacleWidth, highObstacleHeight); // 높은 장애물 1

    setupViewport();

    // 메인 루프
    while (!glfwWindowShouldClose(window)) {
        // 이벤트 처리
        glfwPollEvents();

        // 배경색으로 화면 지우기
        glClear(GL_COLOR_BUFFER_BIT);

        // 바닥 그리기
        floor.Draw();

        // 플레이어 그리기
        player.Draw();

        // 장애물 이동 및 재활용
        for (auto& obstacle : obstacles) {
            Transform::Vertex pos = { obstacle.GetX(), obstacle.GetY() };
            Transform::Vector move = { -OBSTACLE_SPEED, 0 };
            Transform::Vertex newPos = Transform::MoveVertex(pos, move);

            if (newPos.x + obstacle.GetWidth() < 0) {
                newPos.x = WINDOW_WIDTH + obstacleWidth; // 장애물이 화면을 벗어나면 우측에서 재활용
            }

            obstacle.SetPosition(newPos.x, newPos.y);
            obstacle.Draw();
        }

        // 버퍼 스왑 (더블 버퍼링)
        glfwSwapBuffers(window);
    }

    // GLFW 자원 해제
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}