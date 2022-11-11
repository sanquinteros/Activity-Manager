void showRegisterView() {
	printf("You are in the \"REGISTER\" window.\n\n");

    registerServiceRegisterUser();

    redirectTo(WELCOME_VIEW);
}