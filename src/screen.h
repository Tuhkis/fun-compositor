#pragma once

#include <swc.h>
#include <wayland-server.h>

#include "util.h"

typedef struct {
	struct swc_screen* swc;
	struct wl_list windows;
	u8 windowsNum;
} Screen;

static const struct swc_screen_handler screenHandler = {0};

