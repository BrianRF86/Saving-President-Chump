#include "raylib.h"
#include "raymath.h"

//updating enemy to include chase range https://jeannoelseneque.medium.com/game-development-with-raylib-c-day-5-87c6876eaba5

//Ball https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c

class Enemy {
public: 
float x, y;
int speed_x, speed_y;
int radius;
float chasearea = 10.0f;
float chaseMultiplier;

 //concept from https://www.youtube.com/watch?time_continue=2&v=vGlvTWUctTQ&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2F&source_ve_path=MzY4NDIsMjg2NjY&feature=emb_logo
//adding chase timer
float chaseTimer = 0.0f;
//defining chase time for 5 seconds
float ChaseDuration = 3.0f;



void update();

void Draw () {

    DrawCircle(x, y, radius, YELLOW);
    }


//Enemy movement
//defining player Position "SEEK"
void Update(Vector2 playerPosition) {
x += speed_x;
y += speed_y;

// Enemy ai to chase player (testing with normal Vector2) https://stackoverflow.com/questions/28140867/getting-my-enemy-to-move-toward-my-player-c

 //calculates direction from enemy to player
 Vector2 direction = Vector2Subtract(playerPosition, (Vector2){x,y});

 //calculates distance between enemy to player
 float distance = Vector2Distance (playerPosition,{x,y});

if (distance < chasearea)
{
        //defining chase multiplier
 chaseMultiplier = 1.5f;
}

chaseTimer += GetFrameTime();

if(chaseTimer >= ChaseDuration){

//stopping the ball from chasing player
direction.x *= -1;
direction.y *= -1;
chaseTimer = 0.0f;

}

 //Normalize the direction of the enemy
 direction = Vector2Normalize(direction);

 x += direction.x * speed_x * chaseMultiplier;
 y += direction.y * speed_y * chaseMultiplier;

// Border collision

 if (y + radius >= GetScreenHeight() || y - radius <=0)
    {
            speed_y *= -1;
    }
 if (x + radius >= GetScreenWidth() || x - radius <=0)
    {
            speed_x *= -1;
    }
}

void ResetEnemy()
{
    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;
    chaseMultiplier = 1.0f;
    chaseTimer = 0.0f;
//Random direction after reset
    int speed_choices[2] = {-1,1};
    speed_x *= speed_choices[GetRandomValue(0,1)];
    speed_y *= speed_choices[GetRandomValue(0,1)];
}
};

