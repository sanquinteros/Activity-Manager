Login getLogin() {
    Login login;

	printf("Enter your name: ");
	scanf("%s", login.username);
	printf("Enter your password: ");
	scanf("%s", login.password);

	return login;
}

void loginServiceAuthenticateUser(User * user) {
    Login login = getLogin();
    User userFromLogin = constructUserFromLogin(login);
    *user = userRepositoryFindUser(userFromLogin);
}