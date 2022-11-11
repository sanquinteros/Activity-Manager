void show(int view){
    system("cls");

    switch (view) {
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
        case LOGIN_VIEW:
            showLoginView();
            break;
        case LOGOUT_VIEW:
            showLogoutView();
            break;
        case MAIN_VIEW:
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
    }
}