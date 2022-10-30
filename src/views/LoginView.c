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

    Login login = getLogin();
    User user = constructUserFromLogin(login);
    user = findUser(user);
    if (user.id == -1) {
        printf("Name or password is invalid!\n");
        sleep(REDIRECT_TIME);
        printf("You are being redirected to the \"LOGIN\" window.\n");
        sleep(REDIRECT_TIME);
        show(LOGIN_VIEW);
        return;
    } else {
        currentUser = user;
        show(MAIN_VIEW);
        return;
    }
}