#include <stdio.h>
#include <stdlib.h>

#include "utils/GlobalConstants.c"
#include "models/Login.c"
#include "views/InitialView.c"
#include "views/LoginView.c"

int main() {
    showInitialView();

	int selectedView = getSelectedViewFromInitialView();

	if (selectedView == LOGIN_VIEW) {
	    showLoginView();
	    Login login = getLoginFromLoginView();
	}
}
