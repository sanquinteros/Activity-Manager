void showProfileView() {
	printf("You are in the \"PROFILE\" window.\n\n");

	printf("You are %s, your name is \"%s\", your password is \"%s\".\n\n", getRoleName(currentUser.role), currentUser.username, currentUser.password);
/*
    The system has to consider various overlooked details in order to update the name of the user,
    we can't support this feature right now.

	printf("Enter [] if you want to update your name.\n");
*/
	printf("Enter [1] if you want to update your password.\n");
	printf("Enter [2] if you want to go back to the \"MAIN\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(UPDATEPASSWORD_VIEW);
        redirectTo(PROFILE_VIEW);
    } else if (selectedView == 2) {
        show(MAIN_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(PROFILE_VIEW);
    }
}