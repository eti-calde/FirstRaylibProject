#pragma once

#include <string>
#include <raylib.h>

class Ball
{
public:
    Ball(float positionX, float positionY, float speedX, float speedY, float radius, const std::string& name, Color color);

    void Update();
    void Draw() const;
    
    const std::string& GetName() const;
    float GetRadius() const;
    float GetSpeedX() const;
    float GetSpeedY() const;
    Color GetColor() const;


    void SetRadius(float newRadius);
    void SetSpeedX(float newSpeedX);
    void SetSpeedY(float newSpeedY);
    void SetColor(Color newColor);

private:
    float positionX;
    float positionY;
    float speedX;
    float speedY;
    float radius;
    std::string name;
    Color color;
};
