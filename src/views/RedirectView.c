void redirectTo(int view) {
    sleep(REDIRECT_TIME);
    system("cls");

    switch(view) {
        case CREATEREQUEST_VIEW:
            strcpy(windowName, "CREATE REQUEST");
            break;
        case CURRENTREQUESTS_VIEW:
            strcpy(windowName, "CURRENT REQUESTS");
            break;
        case DELETEREQUEST_VIEW:
            strcpy(windowName, "DELETE REQUEST");
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
        case MAIN_VIEW:
        case CLIENT_VIEW:
        case WORKER_VIEW:
            strcpy(windowName, "MAIN");
            break;
        case PROFILE_VIEW:
            strcpy(windowName, "PROFILE");
            break;
        case REGISTER_VIEW:
            strcpy(windowName, "REGISTER");
            break;
        case REQUESTFORWORKER_VIEW:
            strcpy(windowName, "REQUEST FOR WORKER");
            break;
        case REQUESTMENU_VIEW:
            strcpy(windowName, "REQUEST MENU");
            break;
        case SPLASH_VIEW:
            strcpy(windowName, "SPLASH");
            break;
        case UPDATENAME_VIEW:
            strcpy(windowName, "UPDATE NAME");
            break;
        case UPDATEPASSWORD_VIEW:
            strcpy(windowName, "UPDATE PASSWORD");
            break;
        case WELCOME_VIEW:
            strcpy(windowName, "WELCOME");
            break;
    }
    printf("You are being redirected to the \"%s\" window.\n", windowName);

    sleep(REDIRECT_TIME);

    show(view);
}