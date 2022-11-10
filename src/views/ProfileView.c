void showProfileView() {
    int selectedView;

	printf("You are in the \"PROFILE\" window.\n");
	printf("You are a \"%s\", your name is \"%s\", your password is \"%s\".\n", getRoleName(currentUser.role), currentUser.username, currentUser.password);
	printf("Enter [1] if you want to change your name.\n");
	printf("Enter [2] if you want to change your password.\n");
	printf("Enter [3] if you want to go back to the \"MAIN\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);

    if (selectedView == 1) {
        show(CHANGENAME_VIEW);
    } else if (selectedView == 2) {
        show(CHANGEPASSWORD_VIEW);
    } else if (selectedView == 3) {
        show(MAIN_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(PROFILE_VIEW);
    }
}