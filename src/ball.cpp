#include "ball.h"
#include <raylib.h>

Ball::Ball(float positionX, float positionY, float speedX, float speedY, float radius, const std::string& name, Color color)
    : positionX(positionX)
    , positionY(positionY)
    , speedX(speedX)
    , speedY(speedY)
    , radius(radius)
    , name(name)
    , color(color)
{
}

const std::string& Ball::GetName() const {
    return name;
}

void Ball::Update() 
{
    positionX += speedX;
    positionY += speedY;
    
    const int screenWidth = GetScreenWidth();
    const int screenHeight = GetScreenHeight();
    
    if ((positionX + radius >= screenWidth) || (positionX - radius <= 0)) {
        speedX *= -1;
    }
    
    if ((positionY + radius >= screenHeight) || (positionY - radius <= 0)) {
        speedY *= -1;
    }
}

void Ball::Draw() const {
    DrawCircle(positionX, positionY, radius, color); // Dibuja la bola con su color
    DrawText(name.c_str(), positionX - MeasureText(name.c_str(), 10) / 2, positionY - radius - 20, 10, BLACK); // Dibuja el nombre
}