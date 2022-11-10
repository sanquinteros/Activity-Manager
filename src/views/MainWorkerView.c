void showMainWorkerView() {
    int selectedView;

	printf("You are in the \"MAIN\" window.\n");
	printf("Enter [1] if you want to take charge of a client's purchase.\n");
	printf("Enter [2] if you want to see your profile.\n");
	printf("Enter [3] if you want to log out.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);

    if (selectedView == 1) {
        show(CLIENTSPURCHASES_VIEW);
    } else if (selectedView == 2) {
        show(PROFILE_VIEW);
    } else if (selectedView == 3) {
        show(LOGOUT_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(MAINWORKER_VIEW);
    }
}