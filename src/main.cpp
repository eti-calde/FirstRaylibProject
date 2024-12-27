#include "raylib.h"
#include "ball.h"
#include <vector>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// FUNCTION DECLARATION || FUNCTION DECLARATION || FUNCTION DECLARATION
void DrawMenu(bool showMenu, int screenWidth, int screenHeight, std::vector<Ball>& balls, int& selectedBallIndex, bool& dropdownActive, bool& textboxActive);


// MAIN FUNCTION || MAIN FUNCTION || MAIN FUNCTION
int main(void) {
    // SCREEN SIZE || SCREEN SIZE || SCREEN SIZE
    const int screenWidth = 1200; 
    const int screenHeight = 900; 
    InitWindow(screenWidth, screenHeight, "RayGui - Mostrar menú al presionar T");
    
    SetTargetFPS(60);
    GuiSetStyle(DEFAULT, TEXT_SIZE, 28);

    // INIT BALLS || INIT BALLS || INIT BALLS
    std::vector<Ball> balls;
    balls.emplace_back(100, 100, 3, 2, 20, "Red Ball", RED);
    balls.emplace_back(200, 150, -2, 1, 25, "Blue Ball", BLUE);
    balls.emplace_back(300, 200, 1, -3, 30, "Green Ball", GREEN);

    bool showMenu = false;  
    bool dropdownActive = false; 
    bool textboxActive = false; 
    int selectedBallIndex = 0;  

    while (!WindowShouldClose()) {
        if (IsKeyPressed(KEY_TAB)) {
            showMenu = !showMenu; 
        }

        BeginDrawing();
        ClearBackground(WHITE);

        // DRAW BALLS || DRAW BALLS || DRAW BALLS
        for (auto& ball : balls) {
            ball.Update();
        }
        for (auto& ball : balls) {
            ball.Draw();
        }

        // DRAW MENU || DRAW MENU || DRAW MENU
        if (showMenu) {
            DrawMenu(showMenu, screenWidth, screenHeight, balls, selectedBallIndex, dropdownActive,textboxActive);
        } else {
            // Mostrar mensaje inicial
            DrawText("Press TAB to show the menu", screenWidth / 2 - MeasureText("Press TAB to show the menu", 20) / 2, 100, 20, BLACK);
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}


void DrawMenu(bool showMenu, int screenWidth, int screenHeight, std::vector<Ball>& balls, int& selectedBallIndex, bool& dropdownActive, bool& textboxActive) {
    if (!showMenu) return; 

    float transparency = 0.5f;
    DrawRectangle(0, 0, 450, screenHeight, ColorAlpha(LIGHTGRAY, transparency)); 

    // DRAW TILE || DRAW TILE || DRAW TILE
    const char* menuTitle = "ball's menu";
    int titleFontSize = 30;
    int titleWidth = MeasureText(menuTitle, titleFontSize);
    DrawText(menuTitle, (450 - titleWidth) / 2, 20, titleFontSize, BLACK);

    // GET BALL NAMES || GET BALL NAMES || GET BALL NAMES
    std::string ballNames;
    for (size_t i = 0; i < balls.size(); i++) {
        ballNames += balls[i].GetName();
        if (i < balls.size() - 1) ballNames += ";";
    }

    const char* ballList = ballNames.c_str(); 

    // PARAMETERS || PARAMETERS || PARAMETERS
    Rectangle sliderRadiusBounds = { 125, 200, 200, 30 };
    Rectangle sliderSpeedXBounds = { 125, 300, 200, 30 };
    Rectangle sliderSpeedYBounds = { 125, 350, 200, 30 };
    Rectangle colorPanelBounds = { 125, 450, 200, 200 };

    const char* textLeftRadius = "Small";
    const char* textRightRadius = "Large";
    const char* textSlow = "Slow";
    const char* textFast = "Fast";
        
    // CURRENT VALUES || CURRENT VALUES || CURRENT VALUES
    float currentRadius = balls[selectedBallIndex].GetRadius();
    float currentSpeedX = balls[selectedBallIndex].GetSpeedX();
    float currentSpeedY = balls[selectedBallIndex].GetSpeedY();
    Color currentColor = balls[selectedBallIndex].GetColor();

    float minSpeed = -5.0f;
    float maxSpeed = 5.0f;

    float minRadius = 5.0f;
    float maxRadius = 100.0f;

    // UPTADE SLIDERS || UPTADE SLIDERS || UPTADE SLIDERS
    if (GuiSliderPro(sliderRadiusBounds, textLeftRadius, textRightRadius, &currentRadius, minRadius, maxRadius, 10)) {
        balls[selectedBallIndex].SetRadius(currentRadius);
    } else if (GuiSliderPro(sliderSpeedXBounds, textSlow, textFast, &currentSpeedX, minSpeed, maxSpeed, 10)){
        balls[selectedBallIndex].SetSpeedX(currentSpeedX);
    } else if (GuiSliderPro(sliderSpeedYBounds, textSlow, textFast, &currentSpeedY, minSpeed, maxSpeed, 10)){
        balls[selectedBallIndex].SetSpeedY(currentSpeedY);
    } 
    DrawText(TextFormat("Radius: %.2f", currentRadius), 160, 205, 20, BLACK);
    DrawText(TextFormat("SpeedX: %.2f", currentSpeedX), 160, 305, 20, BLACK);
    DrawText(TextFormat("SpeedY: %.2f", currentSpeedY), 160, 355, 20, BLACK);

    // UPDATE COLOR || UPDATE COLOR || UPDATE COLOR
    GuiColorPicker(colorPanelBounds, NULL, &currentColor); 
    balls[selectedBallIndex].SetColor(currentColor);
        
    // CHANGE NAME || CHANGE NAME || CHANGE NAME
    if (textboxActive){
        if(GuiTextBox(Rectangle{ 125, 700, 200, 30 }, (char*)balls[selectedBallIndex].GetName().c_str(), 64, true)){
            textboxActive = false;
        }
    } else{
        if(GuiTextBox(Rectangle{ 125, 700, 200, 30 }, (char*)balls[selectedBallIndex].GetName().c_str(), 64, false)){
            textboxActive = true;
        }
    }

    // DELETE BALL || DELETE BALL || DELETE BALL
    if (GuiButton(Rectangle{ 50, 750, 150, 30 }, "Delete ball")) {
        if (balls.size() > 1 && selectedBallIndex >= 0 && selectedBallIndex < balls.size()) {
            balls.erase(balls.begin() + selectedBallIndex);
            if (selectedBallIndex >= balls.size()) {
                selectedBallIndex = static_cast<int>(balls.size()) - 1;
            }
        }
    }
    // CREATE BALL || CREATE BALL || CREATE BALL
    if (GuiButton(Rectangle{ 250, 750, 150, 30 }, "Create ball")){
        float positionX = static_cast<float>(rand() % 1200);
        float positionY = static_cast<float>(rand() % 900);

        float speedX = minSpeed + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxSpeed - minSpeed)));
        float speedY = minSpeed + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxSpeed - minSpeed)));
        float radius = minRadius + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (maxRadius - minRadius)));

        Color color = {
            static_cast<unsigned char>(rand() % 256),
            static_cast<unsigned char>(rand() % 256),
            static_cast<unsigned char>(rand() % 256),
            255
        };

        Ball newBall(positionX, positionY, speedX, speedY, radius, "New Ball", color);
        balls.push_back(newBall);
        selectedBallIndex = static_cast<int>(balls.size()) - 1;
    }


    // DRAW DROPDOWN || DRAW DROPDOWN || DRAW DROPDOWN
    Rectangle dropdownBounds = { 125, 100, 200, 30 };
    if (dropdownActive) {
        if (GuiDropdownBox(dropdownBounds, ballList, &selectedBallIndex, true)) {
            dropdownActive = false;
        }
    } else {
        if (GuiDropdownBox(dropdownBounds, ballList, &selectedBallIndex, false)) {
            dropdownActive = true;
        }
    }
}
