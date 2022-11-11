Login getLoginFromUser() {
    Login login;

	printf("Enter your name: ");
	scanf("%s", login.username);
	printf("Enter your password: ");
	scanfPassword(login.password);

	return login;
}

void loginServiceAuthenticateUser(User * user) {
    Login login = getLoginFromUser();
    User userFromLogin = constructUserFromLogin(login);
    *user = userRepositoryFindUser(userFromLogin);
}