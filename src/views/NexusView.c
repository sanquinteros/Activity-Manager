void show(int view){
    system("cls");

    switch (view) {
        case CLOSE_VIEW:
            showCloseView();
            break;
        case LOGIN_VIEW:
            showLoginView();
            break;
        case REGISTER_VIEW:
            showRegisterView();
            break;
        case MAIN_VIEW:
            showMainView();
            break;
        case SPLASH_VIEW:
            showSplashView();
            break;
        case WELCOME_VIEW:
            showWelcomeView();
            break;
        default:
            showWelcomeView();
            break;
    }
}