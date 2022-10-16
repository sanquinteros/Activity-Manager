void showInitialView() {
	printf("You are now running the \"Activity Manager\" software!\n\n");
	printf("Welcome to the initial window !\n");
	printf("Enter \"%i\" if you have already created an account.\n", LOGIN_VIEW);
	printf("Enter \"%i\" if you want to register a new account.\n", REGISTER_VIEW);
}

int getSelectedViewFromInitialView() {
	int view;

    printf("Enter here:");
	scanf("%i", &view);

	return view;
}