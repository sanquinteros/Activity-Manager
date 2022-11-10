void show(int view){
    system("cls");

    switch (view) {
        case CHANGENAME_VIEW:
            showChangeNameView();
            break;
        case CHANGEPASSWORD_VIEW:
            showChangePasswordView();
            break;
        case CLIENTSPURCHASES_VIEW:
            showClientsPurchasesView();
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
            showMainView();
            break;
        case MAINWORKER_VIEW:
            showMainWorkerView();
            break;
        case PROFILE_VIEW:
            showProfileView();
            break;
        case REGISTER_VIEW:
            showRegisterView();
            break;
        case SPLASH_VIEW:
            showSplashView();
            break;
        case WELCOME_VIEW:
            showWelcomeView();
            break;
    }
}