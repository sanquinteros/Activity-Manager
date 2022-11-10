Login getLogin() {
    Login login;

	printf("Enter your name: ");
	scanf("%s", login.username);
	printf("Enter your password: ");
	scanf("%s", login.password);

	return login;
}

void showLoginView() {
	printf("You are in the \"LOGIN\" window.\n");

    currentUser = userRepositoryFindUser(constructUserFromLogin(getLogin()));
    if (currentUser.id == -1) {
        printf("Your credentials are invalid!\n");
        sleep(REDIRECT_TIME);
        redirectTo(LOGIN_VIEW);
    } else {
        show(MAIN_VIEW);
    }
}