void show(int view){
    system("cls");

    switch (view) {
        case UPDATENAME_VIEW:
            showUpdateNameView();
            break;
        case UPDATEPASSWORD_VIEW:
            showUpdatePasswordView();
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
        case SPLASH_VIEW:
            showSplashView();
            break;
        case WELCOME_VIEW:
            showWelcomeView();
            break;
    }
}