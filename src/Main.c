#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils/GlobalConstants.c"

#include "dtos/Login.c"
#include "dtos/Register.c"

#include "models/User.c"

#include "utils/GlobalStructsInitializer.c"
#include "utils/ViewsInitializer.c"

#include "repository/UserRepository.c"

#include "services/RegisterService.c"

#include "views/NexusView.c"
#include "views/CloseView.c"
#include "views/CurrentView.c"
#include "views/LoginView.c"
#include "views/MainView.c"
#include "views/RegisterView.c"
#include "views/SplashView.c"
#include "views/WelcomeView.c"

int main() {
    show(SPLASH_VIEW);
    show(WELCOME_VIEW);
	return 0;
}
