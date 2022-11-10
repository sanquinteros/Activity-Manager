void redirectTo(int view) {
    system("cls");

    char windowName[18];

    switch(view) {
        case CHANGENAME_VIEW:
            strcpy(windowName, "CHANGE NAME");
            break;
        case CHANGEPASSWORD_VIEW:
            strcpy(windowName, "CHANGE PASSWORD");
            break;
        case CLIENTSPURCHASES_VIEW:
            strcpy(windowName, "CLIENTS PURCHASES");
            break;
        case EXIT_VIEW:
            strcpy(windowName, "EXIT");
            break;
        case LOGIN_VIEW:
            strcpy(windowName, "LOGIN");
            break;
        case LOGOUT_VIEW:
            strcpy(windowName, "LOGOUT");
            break;
        case MAINWORKER_VIEW:
        case MAIN_VIEW:
            strcpy(windowName, "MAIN");
            break;
        case REGISTER_VIEW:
            strcpy(windowName, "REGISTER");
            break;
        case SPLASH_VIEW:
            strcpy(windowName, "SPLASH");
            break;
        case WELCOME_VIEW:
            strcpy(windowName, "WELCOME");
            break;
        case WORKERPROFILE_VIEW:
            strcpy(windowName, "PROFILE");
            break;
    }

    printf("You are being redirected to the \"%s\" window.\n", windowName);
    sleep(REDIRECT_TIME);
    show(view);
}