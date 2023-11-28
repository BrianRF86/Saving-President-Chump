#include "raylib.h"
#include "raymath.h"
//https://stackoverflow.com/questions/3746484/why-am-i-getting-this-redefinition-of-class-error

#ifndef hitbox_h
#define hitbox_h

//adding hit box to create conditions for chase event. https://happycoding.io/tutorials/processing/collision-detection


class Hitbox{

        public:
        float x, y;
        float circleRadius;
        

Hitbox(float posX, float posY, float Radius)
: x(posX), y(posY), circleRadius(Radius) {}

bool CheckCirclePointCollision(Vector2 point) const;
    
void Draw () const;

};

#endif //hitbox_h