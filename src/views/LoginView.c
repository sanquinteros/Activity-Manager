void showLoginView() {
	printf("You are in the \"LOGIN\" window.\n");

    loginServiceAuthenticateUser(&currentUser);

    if (currentUser.id == -1) {
        printf("Your credentials are invalid.\n");
        redirectTo(WELCOME_VIEW);
    } else {
        show(MAIN_VIEW);
    }
}
