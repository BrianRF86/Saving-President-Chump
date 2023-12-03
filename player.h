#include "raylib.h"
#ifndef PLAYER_H
#define PLAYER_H
//adding player class to clean up code 
class Player {
public:

//adding constructor https://www.geeksforgeeks.org/constructors-c/

Player();

// setting ground position https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
const int groundYpos = 650;
const int jumpUpFrame = 3;
const int jumpDownFrame = 4;
const int footstepFrame1 = 1;
const int footstepFrame2 = 4;
Texture2D playertex = LoadTexture("resources/scarfy5.png");
    void Update();
    void Draw();

    Vector2 playerPosition() const;
    bool isplayerOnGround() const;
    Rectangle frameRec;


//Sound Effect from <a href="https://pixabay.com/sound-effects/?utm_source=link-attribution&utm_medium=referral&utm_campaign=music&utm_content=6462">Pixabay</a>
Sound Jump = LoadSound("resources/jump.mp3");

private:
    Vector2 position;
    Vector2 playerVelocity;
    int playerSpeed;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
   
    
    
};
//adding to resolve error
#endif