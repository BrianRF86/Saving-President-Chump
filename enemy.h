#include "raylib.h"
#include "raymath.h"

//updating enemy to include chase range https://jeannoelseneque.medium.com/game-development-with-raylib-c-day-5-87c6876eaba5

//Ball https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c

class Enemy {
public: 
float x, y;
int speed_x, speed_y;
int radius;


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
 float distance = Vector2Distance (playerPosition,{ x, y});

//defining chase multiplier
 float chaseMultiplier = 1.5f;



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
};
