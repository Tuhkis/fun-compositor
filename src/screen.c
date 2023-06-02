#include "screen.h"

#include "window.h"

void screenAddWin(Screen* screen, void* win) {
	Window* w = win;
	w->screen = screen;
	wl_list_insert(&screen->windows, &w->link);
	++screen->windowsNum;
	swc_window_show(w->swc);
}

void screenRemoveWin(Screen* screen, void* win) {
	Window* w = win;
	w->screen = NULL;
	wl_list_remove(&w->link);
	--screen->windowsNum;
	swc_window_hide(w->swc);
}

