void showWorkerView() {
    int selectedView;

	printf("Enter [1] if you want to see the client request you are working on.\n");
	printf("Enter [2] if you want to see your profile.\n");
	printf("Enter [3] if you want to log out.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);

    if (selectedView == 1) {
        show(REQUESTFORWORKER_VIEW);
    } else if (selectedView == 2) {
        show(PROFILE_VIEW);
    } else if (selectedView == 3) {
        show(LOGOUT_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(MAIN_VIEW);
    }
}