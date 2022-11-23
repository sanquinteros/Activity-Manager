void show(int view){
    system("cls");

    switch (view) {
        case ADMINTOOLS_VIEW:
            showAdminToolsView();
            break;
        case BESTWORSTCLIENTSSTATISTICS_VIEW:
            showBestWorstClientsStatisticsView();
            break;
        case BESTWORSTWORKERSSTATISTICS_VIEW:
            showBestWorstWorkersStatisticsView();
            break;
        case CLIENTDIVISION_VIEW:
            showClientDivisionView();
            break;
        case CLIENTSSTATISTICS_VIEW:
            showClientsStatisticsView();
            break;
        case CREATEREQUEST_VIEW:
            showCreateRequestView();
            break;
        case CURRENTREQUESTS_VIEW:
            showCurrentRequestsView();
            break;
        case DELETEREQUEST_VIEW:
            showDeleteRequestView();
            break;
        case EXIT_VIEW:
            showExitView();
            break;
        case FIREWORKER_VIEW:
            showFireWorkerView();
            break;
        case LOGIN_VIEW:
            showLoginView();
            break;
        case LOGOUT_VIEW:
            showLogoutView();
            break;
        case MAIN_VIEW:
        case ADMIN_VIEW:
        case CLIENT_VIEW:
        case WORKER_VIEW:
            showMainView();
            break;
        case PROFILE_VIEW:
            showProfileView();
            break;
        case REGISTER_VIEW:
            showRegisterView();
            break;
        case REQUESTDATA_VIEW:
            showRequestDataView();
            break;
        case REQUESTFORWORKER_VIEW:
            showRequestForWorkerView();
            break;
        case REQUESTMENU_VIEW:
            showRequestMenuView();
            break;
        case SPLASH_VIEW:
            showSplashView();
            break;
        case UPDATENAME_VIEW:
            showUpdateNameView();
            break;
        case UPDATEPASSWORD_VIEW:
            showUpdatePasswordView();
            break;
        case WELCOME_VIEW:
            showWelcomeView();
            break;
        case WORKERSSTATISTICS_VIEW:
            showWorkersStatisticsView();
            break;
        case WORKERDIVISION_VIEW:
            showWorkerDivisionView();
            break;
    }
}