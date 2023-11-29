#include "player.h"
//adding .cpp for player to tidy up and make code more manageable
void update();

void Draw();
    

Vector2 Player.GetPosition() const {
    return position;
}
bool isplayerOnGround() {
       if (playerPosition->y >= groundYpos){
    return true;
    } else {
    return false;   
    }
    }



bool Player::isOnGround() {
    // Check if player is on the ground
    return position.y >= groundYpos;
}