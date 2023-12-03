

#include "raylib.h"
#include "raymath.h"
#include "enemy.h"
//following player.cpp example

//setting constructor //Defining ball
Enemy::Enemy() :
    x(GetScreenWidth() / 2),
    y(GetScreenHeight() / 2),
    speed_x(1),
    speed_y(1),
    radius(20),
    chasearea(10.f),
    chaseMultiplier(1.0f),
    chaseTimer(0.0f),
    ChaseDuration(3.0f) {}

//Enemy movement
//defining player Position "SEEK"
void Enemy::Update(Vector2 playerPosition) {

x += speed_x;
y += speed_y;

// Enemy ai to chase player (testing with normal Vector2) https://stackoverflow.com/questions/28140867/getting-my-enemy-to-move-toward-my-player-c

 //calculates direction from enemy to player
 static Vector2 direction = Vector2Subtract(playerPosition, (Vector2){x,y});

 //calculates distance between enemy to player
 float distance = Vector2Distance(playerPosition,{x,y});

if (distance <= chasearea)
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

 if (y + radius >= GetScreenHeight() || y - radius <= 0)
    {
            speed_y *= -1;
    }
 if (x + radius >= GetScreenWidth() || x - radius <= 0)
    {
            speed_x *= -1;
    }


}

void Enemy::ResetEnemy () {

    x = GetScreenWidth()/2;
    y = GetScreenHeight()/2;
    chaseMultiplier = 1.0f;
    chaseTimer = 0.0f;
//Random direction after reset
    int speed_choices[2] = {-1,1};
    speed_x *= speed_choices[GetRandomValue(0, 1)];
    speed_y *= speed_choices[GetRandomValue(0, 1)];

}

void Enemy::Draw() {
 DrawCircle(x, y, radius, YELLOW);
}
