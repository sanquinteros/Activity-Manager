void showWelcomeView() {
	int selectedView;
    
	printf("You are in the \"WELCOME\" window.\n");
	printf("Enter [1] if you want to log in.\n");
	printf("Enter [2] if you want to register.\n");
	printf("Enter [3] if you want to close the software.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);

    if (selectedView == CLOSE_VIEW || selectedView == LOGIN_VIEW || selectedView == REGISTER_VIEW) {
        show(selectedView);
    } else {
        showCurrentView(WELCOME_VIEW);
    }
}