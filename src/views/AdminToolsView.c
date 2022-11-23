void showAdminToolsView() {
	printf("You are in the \"ADMINISTRATOR TOOLS\" window.\n\n");

	printf("Enter [1] if you want to see request data.\n");
	printf("Enter [2] if you want to go to the worker division.\n");
	printf("Enter [3] if you want to go to the client division.\n");
	printf("Enter [4] if you want to go back to the \"MAIN\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(REQUESTDATA_VIEW);
        show(ADMINTOOLS_VIEW);
    } else if (selectedView == 2) {
        show(WORKERDIVISION_VIEW);
    } else if (selectedView == 3) {
        show(CLIENTDIVISION_VIEW);
    } else if (selectedView == 4) {
        show(MAIN_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(ADMINTOOLS_VIEW);
    }
}