void showRequestMenuView() {
    int selectedView;

	printf("You are in the \"REQUEST MENU\" window.\n");
	printf("Enter [1] if you want to see your current requests.\n");
	printf("Enter [2] if you want to create a request.\n");
	printf("Enter [3] if you want to delete a current request.\n");
	printf("Enter [4] if you want to go back to the \"MAIN\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(CURRENTREQUESTS_VIEW);
	    show(REQUESTMENU_VIEW);
    } else if (selectedView == 2) {
        show(CREATEREQUEST_VIEW);
        redirectTo(REQUESTMENU_VIEW);
    } else if (selectedView == 3) {
        show(DELETEREQUEST_VIEW);
        redirectTo(REQUESTMENU_VIEW);
    } else if (selectedView == 4) {
        show(MAIN_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(REQUESTMENU_VIEW);
    }
}