#ifndef WINDOW_H
#define WINDOW_H
#include <CSFML/Window.h>

typedef enum {
    CENTER = -1,
    LEFT = -2,
    RIGHT = -3
} PresetPositions;

typedef struct {
    int width;
    int height;
    char* title;
    bool vsync;
} WindowSettings;

typedef struct {
    WindowSettings settings;
    sfVideoMode videoMode;
    sfWindow* backendWindow;
} Window;

WindowSettings windowSettingsCreate(unsigned int width, unsigned int height, char* title, bool vsync);
Window windowCreate(WindowSettings settings);
void windowSetPosition(Window window, int x, int y);
void windowDestroy(Window window);

#endif