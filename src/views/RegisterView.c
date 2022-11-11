void showRegisterView() {
	printf("You are in the \"REGISTER\" window.\n");

    registerServiceRegisterUser();

    redirectTo(WELCOME_VIEW);
}