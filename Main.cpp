#include "raylib.h"

//including raymath to solve Vector2ADD error
#include "raymath.h"
#include "enemy.h"
#include "player.h"
#include "enemy.cpp"
#include "player.cpp"




//adding bool to allow player input to reset game https://www.youtube.com/watch?v=LGqsnM_WEK4
bool running = true;



int main() {
    // Determine the Game Window Width and Height
  // setting ground position https://www.youtube.com/watch?v=_JjPo8rE8a8&t=29s

    const int screenWidth = 1280;
    const int screenHeight = 800;


InitAudioDevice ();
//Sound Effect from <a href="https://pixabay.com/sound-effects/?utm_source=link-attribution&utm_medium=referral&utm_campaign=music&utm_content=6462">Pixabay</a>
Sound Jump = LoadSound("resources/jump.mp3");
//Sound Effect from <a href="https://pixabay.com/?utm_source=link-attribution&utm_medium=referral&utm_campaign=music&utm_content=6082">Pixabay</a>
Sound GameM = LoadSound("resources/gamem.mp3");

    // Initialize the Window
    InitWindow(screenWidth, screenHeight, "Scarfy's dodgeball survival");


//https://www.youtube.com/watch?v=j0C4ox1gFxk&list=PLORJX3OiHbbMs9AFM5bzpNUychJm1raub
    Texture2D background = LoadTexture("resources/street.png");

// Defining objects
    Enemy enemy;
    Player player;

//scoreboard https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c 
// Scoreboard based on time playing
int Playerscore = 0.f;

 // Setting the Frames Per Second
    SetTargetFPS(60);

//fix animation speed https://github.com/raysan5/raylib/blob/master/examples/textures/textures_sprite_anim.c

    // The Game Loop
    while (!WindowShouldClose() /*WindowShouldClose returns true if esc is clicked and closes the window*/) {


  //updates


Playerscore += GetTime();

    //updating update call for enemy
    // resetting scoreboard upon reset
 if (!running){
    enemy.Update(player.playerPosition());
 }
  if (CheckCollisionCircleRec((Vector2){enemy.x, enemy.y}, enemy.radius, (Rectangle){player.playerPosition().x, player.playerPosition().y, player.frameRec.width, player.frameRec.height}))
        {
            running = false;            
            Playerscore = 0;
            enemy.ResetEnemy();
        }

 



        // Setup Canvas
        BeginDrawing();
// adding player enemy collision. //adding reset function https://github.com/BrianRF86/Git-hub-project/commit/ae34663f72f7e8ede5a7a12281c4a4ca0339929c



        // Clear canvas to a specific color to avoid flicker
        ClearBackground(RAYWHITE);
      

// stretching background to fit screen https://www.youtube.com/watch?time_continue=11&v=AKTLg1SWfG0&embeds_referring_euri=https%3A%2F%2Fwww.google.com%2F&source_ve_path=Mjg2NjY&feature=emb_logo &
// https://stackoverflow.com/questions/75932497/trouble-drawing-texture-using-drawtexturepro-in-raylib-c-to-centralise-it
       DrawTexturePro(background,(Rectangle){ 0.0f, 0.0f, (float)background.width, (float)background.height },
       (Rectangle){ 0.0f, 0.0f, (float)screenWidth, (float)screenHeight },(Vector2){ 0.0f, 0.0f }, 0.0f,WHITE);

    enemy.Draw();
    player.Draw();
     
if(running == false){
     DrawText(TextFormat("Game Over, PlayerScore: %i"), 2.5 * screenWidth / 4 - 20, 20, 80, RED);
    DrawText(TextFormat("Press any button to start again"), 2.5 * screenWidth / 4 - 20, 80, 80, BLUE);
}

//adding scoreboard update
    DrawText(TextFormat("Score: %i" ,Playerscore), 1.75 * screenWidth/4 -20, 20, 80, WHITE);
        // Here goes all the Game Logic

        // teardown Canvas
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
