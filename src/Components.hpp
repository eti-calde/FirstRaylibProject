#pragma once

#include "Vec2.hpp"
#include <raylib.h>

class Components 
{
public:
    bool exists = false;
};

class CTransform : public Components
{
public:
    Vec2f position  = {0.0, 0.0};
    Vec2f velocity  = {0.0, 0.0};
    float angle     = 0;

    CTransform() = default;
    CTransform(const Vec2f &pos, const Vec2f &vel, float ang)
        : position(pos), velocity(vel), angle(ang) {}
};

class CShape : public Components
{
public:
    Vec2f center    = {0.0, 0.0};
    int   sides     = 3;
    float radius    = 10.0;
    float rotation  = 0.0;
    Color color     = GREEN;

    CShape() = default;
    CShape(const Vec2f &cen, int sid, float rad, float rot, Color col)
        : center(cen), sides(sid), radius(rad), rotation(rot), color(col) {}
};

class CCollision : public Components
{
public:
    float radius = 0.0;

    CCollision() = default;
    CCollision(float rad) 
        : radius(rad) {}

};

class CScore : public Components
{
public:
    int score = 0;

    CScore() = default;
    CScore(int sc) 
        : score(sc) {}
};

class CLifeSpan : public Components
{
public:
    int lifeSpan    = 0;
    int remaining   = 0;
    
    CLifeSpan() = default;
    CLifeSpan(int life) 
        : lifeSpan(life), remaining(life) {}
};

class CInput : public Components
{
public:
    bool up     = false;
    bool down   = false;
    bool left   = false;
    bool right  = false;

    CInput() = default;
    CInput(bool u, bool d, bool l, bool r) 
        : up(u), down(d), left(l), right(r) {}
};