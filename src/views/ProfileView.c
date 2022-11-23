void showProfileView() {
	printf("You are in the \"PROFILE\" window.\n\n");
	printf("You are a \"%s\", your name is \"%s\", your password is \"%s\".\n\n", getRoleName(currentUser.role), currentUser.username, currentUser.password);
	printf("Enter [1] if you want to update your name (you can not).\n");
	printf("Enter [2] if you want to update your password.\n");
	printf("Enter [3] if you want to go back to the \"MAIN\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
/*
        In order to update names, I have to update them on ClientRequest table too.
        It could come on a future release, but currently I dont have any plans on doing so.

        function name -> show(UPDATENAME_VIEW);
*/
        redirectTo(PROFILE_VIEW);
    } else if (selectedView == 2) {
        show(UPDATEPASSWORD_VIEW);
        redirectTo(PROFILE_VIEW);
    } else if (selectedView == 3) {
        show(MAIN_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(PROFILE_VIEW);
    }
}