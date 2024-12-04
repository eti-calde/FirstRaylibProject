#pragma once

#include <string> // Para usar std::string
#include <raylib.h> // Para usar Color

class Ball
{
public:
    // Constructor actualizado
    Ball(float positionX, float positionY, float speedX, float speedY, float radius, const std::string& name, Color color);

    void Update();
    void Draw() const;
    const std::string& GetName() const;

    // Métodos para el radio
    // float GetRadius() const;
    // void SetRadius(float newRadius);

    // Métodos para el nombre
    // const std::string& GetName() const;
    // void SetName(const std::string& newName);

    // Métodos para el color
    // Color GetColor() const;
    // void SetColor(Color newColor);

private:
    float positionX;
    float positionY;
    float speedX;
    float speedY;
    float radius;
    std::string name; // Nombre de la bola
    Color color;      // Color de la bola
};
