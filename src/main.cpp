#include "raylib.h"
#include "Game.h"
//#define RAYGUI_IMPLEMENTATION
//#include "raygui.h"

int main(void) 
{
    Game g("./src/config");
    g.run();
}