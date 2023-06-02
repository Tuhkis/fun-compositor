#pragma once

#include <swc.h>
#include <wayland-server.h>

#include "util.h"
#include "screen.h"

typedef struct {
	struct swc_window* swc;
	Screen *screen;
	struct wl_list link;
} Window;

