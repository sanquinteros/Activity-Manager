#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>

#include "utils/GlobalConstants.c"
#include "utils/GlobalFunctions.c"

#include "dtos/Client.c"
#include "dtos/ClientArray.c"
#include "dtos/Login.c"
#include "dtos/Register.c"
#include "dtos/RequestData.c"
#include "dtos/Worker.c"
#include "dtos/WorkerArray.c"

#include "models/ClientRequest.c"
#include "models/Path.c"
#include "models/User.c"

#include "utils/GlobalStructsInitializer.c"
#include "utils/GlobalVariablesInitializer.c"
#include "utils/ViewsInitializer.c"

#include "repository/ClientRequestRepository.c"
#include "repository/PathRepository.c"
#include "repository/UserRepository.c"

#include "services/BestWorstClientsStatisticsService.c"
#include "services/BestWorstWorkersStatisticsService.c"
#include "services/ClientsStatisticsService.c"
#include "services/ConfigService.c"
#include "services/CreateRequestService.c"
#include "services/CurrentRequestsService.c"
#include "services/DeleteRequestService.c"
#include "services/FireWorkerService.c"
#include "services/LoginService.c"
#include "services/LogoutService.c"
#include "services/RegisterService.c"
#include "services/RequestDataService.c"
#include "services/RequestForWorkerService.c"
#include "services/UpdatePasswordService.c"
#include "services/UpdateUsernameService.c"
#include "services/WorkersStatisticsService.c"

#include "views/AdminToolsView.c"
#include "views/AdminView.c"
#include "views/BestWorstClientsStatistics.c"
#include "views/BestWorstWorkersStatistics.c"
#include "views/ClientDivisionView.c"
#include "views/ClientsStatisticsView.c"
#include "views/ClientView.c"
#include "views/ConfigView.c"
#include "views/CreateRequestView.c"
#include "views/CurrentRequestsView.c"
#include "views/DeleteRequestView.c"
#include "views/ErrorView.c"
#include "views/ExitView.c"
#include "views/FireWorker.c"
#include "views/LoginView.c"
#include "views/LogoutView.c"
#include "views/MainView.c"
#include "views/NexusView.c"
#include "views/ProfileView.c"
#include "views/RedirectView.c"
#include "views/RegisterView.c"
#include "views/RequestDataView.c"
#include "views/RequestForWorkerView.c"
#include "views/RequestMenuView.c"
#include "views/SplashView.c"
#include "views/UpdateNameView.c"
#include "views/UpdatePasswordView.c"
#include "views/WelcomeView.c"
#include "views/WorkerDivisionView.c"
#include "views/WorkersStatisticsView.c"
#include "views/WorkerView.c"

int main() {
    show(SPLASH_VIEW);
    show(CONFIG_VIEW);
    show(WELCOME_VIEW);
	return 0;
}
