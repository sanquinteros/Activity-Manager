#include <stdio.h>
#include <stdlib.h>

#include "utils/GlobalConstants.c"
#include "models/Login.c"
#include "models/Register.c"
#include "views/InitialView.c"
#include "views/LoginView.c"
#include "views/RegisterView.c"

int main() {
    showInitialView();

	int selectedView = getSelectedViewFromInitialView();

	if (selectedView == LOGIN_VIEW) {
	    showLoginView();
	    Login login = getLoginFromLoginView();
	} else if (selectedView == REGISTER_VIEW) {
        showRegisterView();
        Register rregister = getRegisterFromRegisterView();
	}
}
