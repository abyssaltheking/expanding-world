#include <math.h>
#include <raylib.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
const char* WINDOW_TITLE = "eeee";

typedef struct Sprite {
    Rectangle rect;
    Vector2 origin;
    float rotation;
    Texture2D texture;
    Rectangle source;
} Sprite;

int main(void) {
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(60);

    Sprite player = {
        {400, 300, 50, 50},
        {25, 25},
        0.0f,
        LoadTexture("assets/player.png"),
        {0, 0, 16, 16}
    };

    Vector2 camera = {0, 0};

    while (!WindowShouldClose()) {
        Vector2 mousePos = GetMousePosition();
        Vector2 lookDir = { mousePos.x - player.rect.x, mousePos.y - player.rect.y };
        player.rotation = atan2f(lookDir.y, lookDir.x) * RAD2DEG + 90;

        if (IsKeyDown(KEY_D)) player.rect.x += 250 * GetFrameTime();
        if (IsKeyDown(KEY_A)) player.rect.x -= 250 * GetFrameTime();
        if (IsKeyDown(KEY_S)) player.rect.y += 250 * GetFrameTime();
        if (IsKeyDown(KEY_W)) player.rect.y -= 250 * GetFrameTime();

        BeginDrawing();
        ClearBackground(DARKGREEN);
        DrawTexturePro(player.texture, player.source, player.rect, player.origin, player.rotation, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}