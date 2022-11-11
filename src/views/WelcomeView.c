void showWelcomeView() {
	int selectedView;
    
	printf("You are in the \"WELCOME\" window.\n\n");
	printf("Enter [1] if you want to log in.\n");
	printf("Enter [2] if you want to register.\n");
	printf("Enter [3] if you want to close the software.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(LOGIN_VIEW);
    } else if (selectedView == 2) {
        show(REGISTER_VIEW);
    } else if (selectedView == 3) {
        show(EXIT_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(WELCOME_VIEW);
    }
}