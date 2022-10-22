#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils/GlobalConstants.c"
#include "models/Login.c"
#include "models/Register.c"
#include "models/User.c"
#include "repository/UserRepository.c"
#include "services/LoginService.c"
#include "views/InitialView.c"
#include "views/LoginView.c"
#include "views/RegisterView.c"

int main() {
    showInitialView();

	int selectedView = getSelectedViewFromInitialView();

	if (selectedView == LOGIN_VIEW) {
	    showLoginView();
	    Login login = getLoginFromLoginView();
        User user = getUserFromLogin(login);
        if (user.id == -1) {
            printf("usuario nao existe!");
        } else if (user.isAuthenticated == 0) {
            printf("usuario existe mas senha errada!");
        } else {
            printf("usuario existe, senha correta!");
        }
	} else if (selectedView == REGISTER_VIEW) {
        showRegisterView();
        Register rregister = getRegisterFromRegisterView();
	}
}
