#include <raylib.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;
const char* WINDOW_TITLE = "eeee";

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(GRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}