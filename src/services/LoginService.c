Login getLoginFromUser() {
    Login login;

	printf("Enter your name: ");
	scanfWithSpace(login.username, 50);
	printf("Enter your password: ");
	scanfPassword(login.password);

	return login;
}

void loginServiceAuthenticateUser(User * user) {
    Login login = getLoginFromUser();
    User userFromLogin = constructUserFromLogin(login);
    *user = userRepositoryFindUser(userFromLogin);
}