#include <swc.h>
#include <wayland-server.h>
#include <stdlib.h>

#include "util.h"
#include "window.h"
#include "screen.h"

Screen* currentScreen;
Window* focusedWindow;

static void newWindow(struct swc_window* swc) {
}

static void newScreen(struct swc_screen* swc) {
	Screen* screen;
	screen = malloc(sizeof(*screen));
	if (!screen)
		return;
	screen->swc = swc;
	screen->windowsNum = 0;
	wl_list_init(&screen->windows);
	swc_screen_set_handler(swc, &screenHandler, screen);
	currentScreen = screen;
}

static const struct swc_manager manager = {
	&newScreen, &newWindow
};

u8 main(int argc, char** argv) {
	// NVIDIA stuff...
	#ifdef NVIDIA
	setenv("LIBVA_DRIVER_NAME", "nvidia", 1);
	setenv("GBM_BACKEND", "nvidia-drm", 1);
	setenv("__GLX_VENDOR_LIBRARY_NAME", "nvidia", 1);
	setenv("WLR_NO_HARDWARE_CURSORS", "1", 1);
	printf("NVIDIA\n");
	#endif
	// Other wayland stuff
	setenv("MOZ_ENABLE_WAYLAND", "1", 1);
	setenv("XDG_SESSION_TYPE", "wayland", 1);

	struct wl_display* disp = wl_display_create();
	swc_initialize(disp, NULL, &manager);
	wl_display_run(disp);

	// Close
	wl_display_destroy(disp);

	return 0;
}

