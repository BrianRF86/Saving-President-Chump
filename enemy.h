#ifndef ENEMY_H
#define ENEMY_H

#include "raylib.h"
#include "raymath.h"

//updating enemy to include chase range https://jeannoelseneque.medium.com/game-development-with-raylib-c-day-5-87c6876eaba5

//Ball https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c

class Enemy {
public: 

//adding constructor
Enemy();

float x, y;
int speed_x, speed_y;
int radius;
float chasearea;
float chaseMultiplier;
 //concept from https://www.youtube.com/watch?time_continue=2&v=vGlvTWUctTQ&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2F&source_ve_path=MzY4NDIsMjg2NjY&feature=emb_logo
//adding chase timer
float chaseTimer;
//defining chase time for 5 seconds
float ChaseDuration;
//adding bool to allow player input to reset game https://www.youtube.com/watch?v=LGqsnM_WEK4


//Enemy movement
//defining player Position "SEEK"
void Update(Vector2 playerPosition);

void Draw ();
//adding reset function https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c

void ResetEnemy();
};

#endif // ENEMY_H
