void showCloseView();
void showLoginView();
void showMainView();
void showRegisterView();
void showSplashView();
void showWelcomeView();

void show(int view){
    system("cls");

    switch (view) {
        case CLOSE_VIEW:
            showCloseView();
            break;
        case LOGIN_VIEW:
            showLoginView();
            break;
        case MAIN_VIEW:
            showMainView();
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
        default:
            showWelcomeView();
            break;
    }
}