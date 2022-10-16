#include <stdio.h>

#include "utils/GlobalConstants.c"
#include "views/InitialView.c"

int main() {
    showInitialView();

	int selectedView = getSelectedViewFromInitialView();
}
