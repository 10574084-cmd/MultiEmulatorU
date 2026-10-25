#include <cstdio>
#include <whb/proc.h>
#include <whb/log.h>
#include <whb/log_console.h>
#include <vpad/input.h>

int main(int, char**) {
    WHBProcInit();
    WHBLogConsoleInit();

    const char* systems[] = {
        "NES", "SNES", "Game Boy", "Game Boy Advance",
        "Nintendo 64", "Nintendo DS", "PlayStation 1", "PSP"
    };
    int selected = 0;

    WHBLogPrintf("MultiEmulatorU - Aroma prototype\n");
    WHBLogPrintf("Frontend only: emulator cores are not integrated yet.\n\n");

    for (int i = 0; i < 8; ++i) {
        WHBLogPrintf("%c %s\n", i == selected ? '>' : ' ', systems[i]);
    }
    WHBLogPrintf("\nD-pad: select | A: open system | HOME: exit\n");

    while (WHBProcIsRunning()) {
        VPADStatus status{};
        VPADReadError error;
        VPADRead(VPAD_CHAN_0, &status, 1, &error);

        if (error == VPAD_READ_SUCCESS) {
            if (status.trigger & VPAD_BUTTON_DOWN) selected = (selected + 1) % 8;
            if (status.trigger & VPAD_BUTTON_UP) selected = (selected + 7) % 8;
            if (status.trigger & VPAD_BUTTON_A) {
                WHBLogPrintf("\nSelected: %s\nNo emulator core is linked in this prototype.\n", systems[selected]);
            }
        }
        WHBProcSleep();
    }

    WHBLogConsoleFree();
    WHBProcShutdown();
    return 0;
}
