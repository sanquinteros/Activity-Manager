void showWelcomeView() {
	int selectedView;
    
	printf("You are in the \"WELCOME\" window.\n");
	printf("Enter [%i] if you want to close the software.\n", CLOSE_VIEW);
	printf("Enter [%i] if you want to login.\n", LOGIN_VIEW);
	printf("Enter [%i] if you want to register.\n", REGISTER_VIEW);
    printf("Enter here: ");
	scanf("%i", &selectedView);

	if (selectedView == LOGIN_VIEW) {
	    show(LOGIN_VIEW);
	} else if (selectedView == REGISTER_VIEW) {
        show(REGISTER_VIEW);
	} else if (selectedView == CLOSE_VIEW) {
	    show(CLOSE_VIEW);
	}
}