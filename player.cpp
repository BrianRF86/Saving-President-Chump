
#include "raylib.h"
#include "raymath.h"
#include "player.h"
//adding .cpp for player to tidy up and make code more manageable

// using class member access operator https://www.tutorialspoint.com/cplusplus/class_member_access_operator_overloading.htm to fix errors definition errors.

//definining constants
const int screenWidth = 1280;
const int screenHeight = 800;

const int gravity = 1;
const int groundYpos = 650;
const int jumpUpFrame = 3;
const int jumpDownFrame = 4;
const int footstepFrame1 = 1;
const int footstepFrame2 = 4;

int numFrames = 6;


//fixing declaration errors
Player::Player() : 
                position({GetScreenWidth()/ 2.0f, GetScreenHeight()/2.0f}),
                playerVelocity({0.0f, 0.0f}),
                playerSpeed(5),
                currentFrame(0),
                framesCounter(0),
                framesSpeed(8),
                //https://www.reddit.com/r/cpp_questions/comments/lmixkx/problem_with_a_narrowing_conversion/ to solve narrowing conversion error
                frameRec{0.0f, 0.0f, static_cast<float>(GetScreenWidth () / 2.0f), static_cast<float>(GetScreenHeight() /2.0f)} {}
                Texture2D playertex = LoadTexture("resources/scarfy5.png");

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
        if (isplayerOnGround() && (IsKeyDown(KEY_UP) || IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)))
        {
            playerVelocity.y =-playerSpeed *4;
            PlaySound(Jump);
          
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
        if (position.x <=0){
            position.x = 0;
        } else if (position.x >= screenWidth - frameRec.width){
            position.x = screenWidth - frameRec.width;
        }

//https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
        position = Vector2Add(position, playerVelocity);

        if (isplayerOnGround() && (position.y >= groundYpos)) {
            playerVelocity.y = 0;
            position.y = groundYpos;
        } else {
        playerVelocity.y += gravity;
        }
}
Vector2 Player::playerPosition() const {
    return position;
}


bool Player::isplayerOnGround() const {
    // Check if player is on the ground
    return position.y >= groundYpos;
}



void Player::Draw() {
    DrawTextureRec(playertex, frameRec, position, WHITE);
}