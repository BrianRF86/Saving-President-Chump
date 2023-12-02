#include "player.h"
//adding .cpp for player to tidy up and make code more manageable

// using class member access operator https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm to fix errors definition errors.

Player::Player() : 

unsigned numFrames = 6;
	int frameWidth = playertex.width / numFrames;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)playertex.height };
	Vector2 playerPosition = {GetScreenWidth ()/ 2.0f, GetScreenHeight ()/ 2.0f};
    Vector2 playerVelocity = {0.0f,0.0f};
    int playerSpeed = 5;
    int currentFrame = 0;   
    int framesCounter = 0;
    int framesSpeed = 8;

Vector2 Player::GetPosition() const {
    return position;
}


bool Player::isOnGround() const {
    // Check if player is on the ground
    return position.y >= groundYpos;
}

void Player::Update() {

framesCounter++;
        if (framesCounter >= (60/framesSpeed))
        {
            framesCounter = 0;
            currentFrame++;
            if (currentFrame > 5) currentFrame = 0;
            frameRec.x = (float)currentFrame*(float)playertex.width/6;
        
        // Stop walking animation if no button is pressed
        } else if(!IsKeyDown(KEY_RIGHT) && !IsKeyDown(KEY_LEFT) &&
        !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) &&
        !IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
        
        framesCounter = 0;
        }
        // Player movement
        // Jump & checking that player is on ground prior to jump https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
        if (isplayerOnGround(&playerPosition) && (IsKeyDown(KEY_UP)) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT))
        {
            playerVelocity.y =-playerSpeed *4;
          
        }
        if (IsKeyDown(KEY_RIGHT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) {
			playerVelocity.x = framesSpeed;
			if(frameRec.width < 0) {
				frameRec.width = -frameRec.width;
                
			}
        } else if (IsKeyDown(KEY_LEFT) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) {
			playerVelocity.x = -framesSpeed;
			if(frameRec.width > 0) {
				frameRec.width = -frameRec.width;
                
			}
		} else {
			playerVelocity.x = 0;
		}

//keeping player on screen adapated from https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c
        if (playerPosition.x <0){
            playerPosition.x = 0;
        } else if (playerPosition.x >= screenWidth - frameRec.width){
            playerPosition.x = screenWidth - frameRec.width;
        }

//https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
        playerPosition = Vector2Add(playerPosition, playerVelocity);
        if (isplayerOnGround(&playerPosition)){
            playerVelocity.y = 0;
            playerPosition.y = groundYpos;
        } else {
        playerVelocity.y += gravity;
        }


}

void Player::Draw() {
    // Implement the draw logic here
}