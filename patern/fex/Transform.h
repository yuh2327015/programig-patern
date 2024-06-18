#pragma once

#include <vector>
#include <cstdlib>
#include <ctime>

class Transform {
public:
    float x, y;
    float speedX;
    float width;
    float height;

    Transform(float x, float y, float speedX, float width, float height)
        : x(x), y(y), speedX(speedX), width(width), height(height) {}

    void update(float deltaTime) {
        x += speedX * deltaTime;
        if (x < -width) { // ȭ�� ������ �����
            x = 800 + (std::rand() % 200); // ȭ�� �����ʿ��� �ٽ� ��Ÿ��
            height = (std::rand() % 2 == 0) ? 100.0f : 300.0f; // ���̸� �ٽ� ���� ����
        }
    }
};

class ObstacleManager {
private:
    std::vector<Transform> obstacles;
    int maxObstacles;
    float groundLevel;
    float obstacleSpeed;
    float minGap;
    float maxGap;

public:
    ObstacleManager(int maxObstacles, float groundLevel, float speed, float minGap, float maxGap)
        : maxObstacles(maxObstacles), groundLevel(groundLevel), obstacleSpeed(speed), minGap(minGap), maxGap(maxGap) {
        std::srand(std::time(0));
        float initialX = 800.0f;
        for (int i = 0; i < maxObstacles; ++i) {
            float x = initialX + minGap * i + (std::rand() % static_cast<int>(maxGap - minGap)); // ��ֹ� �ʱ� ��ġ�� �����ϰ� ����
            float height = (std::rand() % 2 == 0) ? 100.0f : 300.0f; // ���̸� 100cm �Ǵ� 300cm�� ���� ����
            obstacles.emplace_back(x, groundLevel, obstacleSpeed, 50.0f, height);
        }
    }

    void update(float deltaTime) {
        for (auto& obstacle : obstacles) {
            obstacle.update(deltaTime);
            if (obstacle.x < -obstacle.width) {
                float lastX = obstacle.x;
                if (!obstacles.empty()) {
                    lastX = obstacles.back().x;
                }
                obstacle.x = lastX + minGap + (std::rand() % static_cast<int>(maxGap - minGap)); // ��ֹ��� ȭ���� ����� �ٽ� �����ʿ��� ���� ��ġ�� ��Ÿ��
                obstacle.height = (std::rand() % 2 == 0) ? 100.0f : 300.0f; // ���̸� �ٽ� ���� ����
            }
        }
    }

    const std::vector<Transform>& getObstacles() const {
        return obstacles;
    }
};

class StarManager {
private:
    std::vector<Transform> stars;
    float starSpeed;
    int windowWidth;
    int windowHeight;

public:
    StarManager(int numStars, float starSpeed, int windowWidth, int windowHeight)
        : starSpeed(starSpeed), windowWidth(windowWidth), windowHeight(windowHeight) {
        std::srand(std::time(0));
        for (int i = 0; i < numStars; ++i) {
            float x = std::rand() % windowWidth;
            float y = windowHeight - (std::rand() % (windowHeight / 2)); // �ϴÿ� ��Ÿ����
            float size = (std::rand() % 40) + 10; // 10cm ~ 50cm ũ��� ���� ����
            stars.emplace_back(x, y, starSpeed, size, size);
        }
    }

    void update(float deltaTime) {
        for (auto& star : stars) {
            star.update(deltaTime);
            if (star.x < -star.width) {
                star.x = windowWidth + (std::rand() % 200);
                star.y = windowHeight - (std::rand() % (windowHeight / 2));
                star.width = star.height = (std::rand() % 40) + 10; // ũ�⸦ �ٽ� ���� ����
            }
        }
    }

    const std::vector<Transform>& getStars() const {
        return stars;
    }
};
