#include "Chaser.hpp"

Chaser::Chaser(const Texture& texture, const Vector2f& startPosition, float initialSpeed)
    : Enemy(texture, startPosition, initialSpeed), playerPosition(nullptr) {
}

void Chaser::update(float deltaTime) {
    if (playerPosition) {
        // Calculate direction vector to the player
        Vector2f direction = *playerPosition - position;

        // Normalize the direction vector
        float magnitude = std::sqrt(direction.x * direction.x + direction.y * direction.y);
        if (magnitude > 0) {
            direction /= magnitude; // Normalize
        }

        // Update velocity based on direction and speed
        velocity = direction * speed;

        // Update position
        position += velocity * deltaTime;
        sprite.setPosition(position);
    }
}

void Chaser::setTarget(const Vector2f& playerPos) {
    playerPosition = &playerPos;
}