#include "window.h"

#include <swc.h>
#include <stdlib.h>

#include "screen.h"

void windowDestroy(void* data) {
	Window* w = data;
	screenRemoveWin(w->screen, w);
	free(data);
}
void windowEntered(void* data) {

}

