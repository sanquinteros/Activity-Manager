void showWelcomeView() {
	int selectedView;
    
	printf("You are in the \"WELCOME\" window.\n");
	printf("Enter [%i] if you want to close the software.\n", CLOSE_VIEW);
	printf("Enter [%i] if you want to login.\n", LOGIN_VIEW);
	printf("Enter [%i] if you want to register.\n", REGISTER_VIEW);
    printf("Enter here: ");
	scanf("%i", &selectedView);

    if (selectedView == CLOSE_VIEW || selectedView == LOGIN_VIEW || selectedView == REGISTER_VIEW) {
        show(selectedView);
    } else {
        showCurrentView(WELCOME_VIEW);
    }
}