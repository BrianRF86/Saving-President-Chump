#include "raylib.h"

//including raymath to solve Vector2ADD error
#include "raymath.h"
#include "enemy.h"




// setting ground position https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
const int groundYpos = 650;
const int jumpUpFrame = 3;
const int jumpDownFrame = 4;
const int footstepFrame1 = 1;
const int footstepFrame2 = 4;
// Ground boolean https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
bool isplayerOnGround(Vector2 *playerPosition){
   if (playerPosition->y >= groundYpos){
    return true;
    } else {
    return false;   
    }
    }


//Preventing player from leaving screen copied from https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c


int main() {
    // Determine the Game Window Width and Height
  // setting ground position https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s

    const int screenWidth = 1280;
    const int screenHeight = 800;
    const int gravity = 1;


    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Scarfy's dodgeball survival");


//https://www.youtube.com/watch?v=j0C4ox1gFxk&list=PLORJX3OiHbbMs9AFM5bzpNUychJm1raub
    Texture2D background = LoadTexture("resources/street.png");
    Texture2D playertex = LoadTexture("resources/scarfy5.png");
// Defining objects
    Enemy enemy;


   

//Defining ball
 enemy.radius = 20;
    enemy.x = screenWidth/2;
    enemy.y = screenHeight/2;
    enemy.speed_x = 7;
    enemy.speed_y = 7;
 
unsigned numFrames = 6;
	int frameWidth = playertex.width / numFrames;
	Rectangle frameRec = { 0.0f, 0.0f, (float)frameWidth, (float)playertex.height };
	Vector2 playerPosition = {GetScreenWidth ()/ 2.0f, GetScreenHeight ()/ 2.0f};
    Vector2 playerVelocity = {0.0f,0.0f};
    int playerSpeed = 5;
    int currentFrame = 0;   
    int framesCounter = 0;
    int framesSpeed = 8;



 // Setting the Frames Per Second
    SetTargetFPS(60);

//fix animation speed https://github.com/raysan5/raylib/blob/master/examples/textures/textures_sprite_anim.c



    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {


            //updates


    //updating update call for enemy
    void Update(Vector2 playerPosition);

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

        // Setup Canvas
        BeginDrawing();
        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
      

// stretching background to fit screen https://www.youtube.com/watch?time_continue=11&v=AKTLg1SWfG0&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2F&source_ve_path=Mjg2NjY&feature=emb_logo &
// https://stackoverflow.com/questions/75932497/trouble-drawing-texture-using-drawtexturepro-in-raylib-c-to-centralise-it
       DrawTexturePro(background,(Rectangle){ 0.0f, 0.0f, (float)background.width, (float)background.height },
       (Rectangle){ 0.0f, 0.0f, (float)screenWidth, (float)screenHeight },(Vector2){ 0.0f, 0.0f }, 0.0f,WHITE);

    enemy.Draw();
     DrawTextureRec(playertex, frameRec, playerPosition,WHITE);

        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
