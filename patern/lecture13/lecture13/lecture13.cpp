#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <chrono>
#include <cmath>

// 플레이어의 상태를 나타내는 구조체
struct Player {
    float x, y;         // 위치
    float velocityY;    // 수직 속도
    float velocityX;    // 수평 속도
    bool isJumping;     // 점프 중인지 여부
};

// 전역 변수
Player player = { -0.6f, -0.78f, 0.0f, 0.0f, false }; // 초기 플레이어 위치 및 상태
const float gravity = -0.00981f;                    // 중력 가속도 (픽셀/frame², 9.8 m/s²를 픽셀/frame²로 변환한 값)
const float jumpVelocity = 0.085f;                 // 점프 초기 속도 (픽셀/frame, 2미터 점프 높이에 해당하는 속도)
const float moveSpeed = 0.01f;                    // 이동 속도 (픽셀/frame)

// 바닥의 위치와 크기
const float floorY = -0.9f;
const float floorHeight = 0.1f;
const float floorLeft = -1.0f;
const float floorRight = 1.0f;

void errorCallback(int error, const char* description) {
    std::cerr << "Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);

    if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !player.isJumping) {
        player.isJumping = true;
        player.velocityY = jumpVelocity;
    }

    if (key == GLFW_KEY_LEFT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        player.velocityX = -moveSpeed;
    }
    else if (key == GLFW_KEY_RIGHT && (action == GLFW_PRESS || action == GLFW_REPEAT)) {
        player.velocityX = moveSpeed;
    }
    else if ((key == GLFW_KEY_LEFT || key == GLFW_KEY_RIGHT) && action == GLFW_RELEASE) {
        player.velocityX = 0.0f;
    }
}

void updatePlayer() {
    if (player.isJumping) {
        player.velocityY += gravity;
        player.y += player.velocityY;

        // AABB 충돌 검사
        float playerBottom = player.y - 0.02f;
        if (playerBottom <= floorY + floorHeight) {
            player.y = floorY + floorHeight + 0.02f;
            player.isJumping = false;
            player.velocityY = 0.0f;
        }
    }

    player.x += player.velocityX;
}

void render() {
    glClear(GL_COLOR_BUFFER_BIT);

    // 바닥 그리기 (초록색)
    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(floorLeft, floorY);              // 왼쪽 아래
    glVertex2f(floorRight, floorY);             // 오른쪽 아래
    glVertex2f(floorRight, floorY + floorHeight); // 오른쪽 위
    glVertex2f(floorLeft, floorY + floorHeight);  // 왼쪽 위
    glEnd();

    // 플레이어 그리기 (주황색)
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(player.x - 0.02f, player.y - 0.02f); // 왼쪽 아래
    glVertex2f(player.x + 0.02f, player.y - 0.02f); // 오른쪽 아래
    glVertex2f(player.x + 0.02f, player.y + 0.02f); // 오른쪽 위
    glVertex2f(player.x - 0.02f, player.y + 0.02f); // 왼쪽 위
    glEnd();
}

int main() {
    // GLFW 초기화
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // GLFW 윈도우 생성
    GLFWwindow* window = glfwCreateWindow(1280, 1280, "Square Example", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // 컨텍스트를 현재 스레드에 연결
    glfwMakeContextCurrent(window);

    // GLFW에 오류 콜백 등록
    glfwSetErrorCallback(errorCallback);

    // 키 이벤트 콜백 등록
    glfwSetKeyCallback(window, keyCallback);

    // OpenGL 초기화
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // 좌표계 설정
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1, 1, -1, 1, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // 렌더링 루프
    while (!glfwWindowShouldClose(window)) {
        // 플레이어 업데이트
        updatePlayer();

        // 렌더링
        render();

        // 버퍼 교환
        glfwSwapBuffers(window);

        // 이벤트 처리
        glfwPollEvents();
    }

    // GLFW 종료
    glfwTerminate();
    return 0;
}
