#include "raylib.h"
//adding player class to clean up code 
class Player {
public:

// setting ground position https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s
const int groundYpos = 650;
const int jumpUpFrame = 3;
const int jumpDownFrame = 4;
const int footstepFrame1 = 1;
const int footstepFrame2 = 4;

    void Update();
    void Draw();

    Vector2 GetPosition() const;

private:
    Vector2 position;
    Vector2 velocity;
    int speed;
    int currentFrame;
    int framesCounter;
    int framesSpeed;
    bool isOnGround();
};