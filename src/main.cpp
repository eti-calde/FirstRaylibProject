#include "raylib.h"
#include "ball.h"
#include <vector>
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"

// Declaración de la función DrawMenu
void DrawMenu(bool showMenu, int screenWidth, int screenHeight, const std::vector<Ball>& balls, int& selectedBallIndex, bool& dropdownActive);

int main(void) {
    // Inicialización
    const int screenWidth = 1200;  // Ancho de la ventana
    const int screenHeight = 900; // Alto de la ventana
    InitWindow(screenWidth, screenHeight, "RayGui - Mostrar menú al presionar T");
    SetTargetFPS(60);

    GuiSetStyle(DEFAULT, TEXT_SIZE, 28);

    std::vector<Ball> balls;
    balls.emplace_back(100, 100, 3, 2, 20, "Bola Roja", RED);
    balls.emplace_back(200, 150, -2, 1, 25, "Bola Azul", BLUE);
    balls.emplace_back(300, 200, 1, -3, 30, "Bola Verde", GREEN);

    bool showMenu = false;  // Controla si el menú está visible
    bool dropdownActive = false; // Estado del Dropdown
    int selectedBallIndex = 0;  // Índice de la bola seleccionada (por defecto la primera bola)
    int lastSelectedIndex = -1;

    // Bucle principal
    while (!WindowShouldClose()) {
        // Entrada del usuario
        if (IsKeyPressed(KEY_T)) {
            showMenu = !showMenu; // Alterna entre mostrar/ocultar el menú
        }

        // Actualizar las bolas
        for (auto& ball : balls) {
            ball.Update();
        }

        BeginDrawing();
        ClearBackground(WHITE);

        // DRAW BALLS || DRAW BALLS || DRAW BALLS
        for (auto& ball : balls) {
            ball.Draw();
        }

        // DRAW MENU || DRAW MENU || DRAW MENU
        if (showMenu) {
            DrawMenu(showMenu, screenWidth, screenHeight, balls, selectedBallIndex, dropdownActive);
        } else {
            // Mostrar mensaje inicial
            DrawText("Presione T para mostrar menú", screenWidth / 2 - MeasureText("Presione T para mostrar menú", 20) / 2, screenHeight / 2, 20, BLACK);
        }

        // Acciones adicionales: mostrar la bola seleccionada
        if (selectedBallIndex >= 0 && selectedBallIndex < balls.size()) {
            DrawText(("Seleccionada: " + balls[selectedBallIndex].GetName()).c_str(), 10, screenHeight - 30, 20, BLACK);
        }

        EndDrawing();
    }

    // Finalización
    CloseWindow();

    return 0;
}


void DrawMenu(bool showMenu, int screenWidth, int screenHeight, const std::vector<Ball>& balls, int& selectedBallIndex, bool& dropdownActive) {
    if (!showMenu) return; // Si el menú no está activo, no dibujar nada

    // Dibujar fondo transparente
    DrawRectangle(0, 0, 450, screenHeight, ColorAlpha(LIGHTGRAY, 0.5f)); // 50% de transparencia

    // Dibujar título del menú (centrado y con tipografía aumentada)
    const char* menuTitle = "ball's menu";
    int titleFontSize = 30;
    int titleWidth = MeasureText(menuTitle, titleFontSize);
    DrawText(menuTitle, (450 - titleWidth) / 2, 20, titleFontSize, BLACK);

    // Crear lista de nombres de las bolas para el Dropdown
    std::string ballNames;
    for (size_t i = 0; i < balls.size(); i++) {
        ballNames += balls[i].GetName();
        if (i < balls.size() - 1) ballNames += ";"; // Separar nombres con ';'
    }

    // Dibujar el Dropdown y actualizar el índice seleccionado
    Rectangle dropdownBounds = { 20, 100, 200, 30 }; // Tamaño y posición del Dropdown

    // Control del Dropdown
    const char* ballList = ballNames.c_str(); // Convertir nombres a C-string

    // Si el Dropdown está activo, mantenerlo desplegado (editMode = true)
    if (dropdownActive) {
        // Mantener el menú desplegado y permitir la selección
        if (GuiDropdownBox(dropdownBounds, ballList, &selectedBallIndex, true)) {
            dropdownActive = false; // Cerrar el Dropdown después de la selección
        }
    } else {
        // Dibujar el Dropdown en modo colapsado
        if (GuiDropdownBox(dropdownBounds, ballList, &selectedBallIndex, false)) {
            dropdownActive = true; // Abrir el Dropdown al hacer clic
        }
    }
}

