void showLoginView() {
    system("cls");
	printf("Welcome to the \"Login\" window !\n");
	return;
}

Login getLoginFromLoginView() {
    Login login;

	printf("Please, enter your name: ");
	scanf("%s", login.username);
	printf("Please, enter your password: ");
	scanf("%s", login.password);

    system("cls");

	return login;
}