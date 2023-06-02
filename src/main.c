#include <swc.h>
#include <wayland-server.h>
#include <stdlib.h>

#include "util.h"

static void newWindow(struct swc_window* win) {

}

static void newScreen(struct swc_screen* screen) {

}

static const struct swc_manager manager = {
	&newScreen, &newWindow
};

u8 main(int argc, char** argv) {
	// NVIDIA stuff...
	setenv("MOZ_ENABLE_WAYLAND", "1", 1);
	setenv("LIBVA_DRIVER_NAME", "nvidia", 1);
	setenv("XDG_SESSION_TYPE", "wayland", 1);
	setenv("GBM_BACKEND", "nvidia-drm", 1);
	setenv("__GLX_VENDOR_LIBRARY_NAME", "nvidia", 1);
	setenv("WLR_NO_HARDWARE_CURSORS", "1", 1);

	struct wl_display* disp = wl_display_create();
	swc_initialize(disp, NULL, &manager);
	wl_display_run(disp);

	// Close
	wl_display_destroy(disp);

	return 0;
}

