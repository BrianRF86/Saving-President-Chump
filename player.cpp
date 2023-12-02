#include "player.h"
//adding .cpp for player to tidy up and make code more manageable

// using class member access operator https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm to fix errors definition errors.

Player::Player() : position({0.0f, 0.0f}), velocity({0.0f, 0.0f}), speed(5), currentFrame(0), framesCounter(0), framesSpeed(8) {}

Vector2 Player::GetPosition() const {
    return position;
}


bool Player::isOnGround() const {
    // Check if player is on the ground
    return position.y >= groundYpos;
}

void Player::Update() {
}

void Player::Draw() {
    // Implement the draw logic here
}