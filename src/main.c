#include <CSFML/Window.h>
#include <CSFML/OpenGL.h>
#include "window.h"

int main() {
    WindowSettings settings = windowSettingsCreate(720, 720, "yeah", true);
    Window window = windowCreate(settings);

    windowSetPosition(window, (PresetPositions)CENTER, (PresetPositions)CENTER);

    bool keepWindowOpen = true;

    while (keepWindowOpen) {
        sfEvent* event;

        while (sfWindow_pollEvent(window.backendWindow, event)) {
            if (event->type == sfEvtClosed) keepWindowOpen = false;
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        sfWindow_display(window.backendWindow);
    }

    sfWindow_destroy(window.backendWindow);
    return 0;
}