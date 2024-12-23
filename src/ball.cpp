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

// GET PARAMETERS || GET PARAMETERS || GET PARAMETERS
const std::string& Ball::GetName() const {
    return name;
}

float Ball::GetRadius() const {
    return radius;
}

float Ball::GetSpeedX() const {
    return speedX;
}

float Ball::GetSpeedY() const {
    return speedY;
}

Color Ball::GetColor() const {
    return color;
}

// SET PARAMETERS || SET PARAMETERS || SET PARAMETERS
void Ball::SetRadius(float newRadius) {
    radius = newRadius;
}

void Ball::SetSpeedX(float newSpeedX) {
    speedX = newSpeedX;
}

void Ball::SetSpeedY(float newSpeedY) {
    speedY = newSpeedY;
}

void Ball::SetColor(Color newColor) {
    color = newColor;
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
    DrawCircle(positionX, positionY, radius, color);
    DrawText(name.c_str(), positionX - MeasureText(name.c_str(), 10) / 2, positionY - radius - 20, 10, BLACK);
}