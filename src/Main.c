#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

#include "utils/GlobalConstants.c"
#include "utils/GlobalFunctions.c"

#include "dtos/Login.c"
#include "dtos/Register.c"

#include "models/ClientRequest.c"
#include "models/User.c"

#include "utils/GlobalStructsInitializer.c"
#include "utils/GlobalVariablesInitializer.c"
#include "utils/ViewsInitializer.c"

#include "repository/ClientRequestRepository.c"
#include "repository/UserRepository.c"

#include "services/CreateRequestService.c"
#include "services/CurrentRequestsService.c"
#include "services/DeleteRequestService.c"
#include "services/LoginService.c"
#include "services/LogoutService.c"
#include "services/RegisterService.c"
#include "services/RequestForWorkerService.c"
#include "services/UpdatePasswordService.c"
#include "services/UpdateUsernameService.c"

#include "views/ClientView.c"
#include "views/CreateRequestView.c"
#include "views/CurrentRequestsView.c"
#include "views/DeleteRequestView.c"
#include "views/ExitView.c"
#include "views/LoginView.c"
#include "views/LogoutView.c"
#include "views/MainView.c"
#include "views/NexusView.c"
#include "views/ProfileView.c"
#include "views/RedirectView.c"
#include "views/RegisterView.c"
#include "views/RequestForWorkerView.c"
#include "views/RequestMenuView.c"
#include "views/SplashView.c"
#include "views/UpdateNameView.c"
#include "views/UpdatePasswordView.c"
#include "views/WelcomeView.c"
#include "views/WorkerView.c"

int main() {
    show(SPLASH_VIEW);
    show(WELCOME_VIEW);
	return 0;
}
