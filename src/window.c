#include <CSFML/Window.h>
#include "window.h"

WindowSettings windowSettingsCreate(unsigned int width, unsigned int height, char* title, bool vsync) {
    return (WindowSettings){
        width,
        height,
        title,
        vsync
    };
}

Window windowCreate(WindowSettings settings) {
    sfContextSettings contextSettings = {
        24, // depth bits
        8,  // stencil bits
        4,  // antialiasing level
        3,  // opengl major version
        3   // opengl minor version
    };

    sfVideoMode videoMode = {{settings.width, settings.height}, 32};
    sfWindow* window = sfWindow_create(videoMode, settings.title, sfClose | sfTitlebar, sfWindowed, &contextSettings);

    sfWindow_setVerticalSyncEnabled(window, settings.vsync);
    sfWindow_setActive(window, true);

    return (Window){settings, videoMode, window};
}

void windowSetPosition(Window window, int x, int y) {
    sfWindow* windowBackend = window.backendWindow;

    int newX = x;
    int newY = y;

    if (x < 0) {
        switch (x) {
            case -1: // PresetPositions.CENTER
                newX = (sfVideoMode_getDesktopMode().size.x / 2) - (window.settings.width / 2); 
                break;
            case -2: // PresetPositions.LEFT
                newX = 0;
                break;
            case -3: // PresetPositions.RIGHT
                newX = sfVideoMode_getDesktopMode().size.x - window.settings.width;
                break;
            default:
                break;
        }
    }

    if (y < 0) {
        switch (y) {
            case -1: // PresetPositions.CENTER
                newY = sfVideoMode_getDesktopMode().size.y / 2 - window.settings.height / 2; 
                break;
            case -2: // PresetPositions.LEFT
                newY = 0;
                break;
            case -3: // PresetPositions.RIGHT
                newY = sfVideoMode_getDesktopMode().size.y - window.settings.height;
                break;
            default:
                break;
        }
    }

    sfWindow_setPosition(windowBackend, (sfVector2i){newX, newY});
}

void windowDestroy(Window window) {
    sfWindow_destroy(window.backendWindow);
}