void showClientDivisionView() {
	printf("You are in the \"CLIENT DIVISION\" window.\n\n");

	printf("Enter [1] if you want to see clients statistics.\n");
	printf("Enter [2] if you want to see the best and worst clients statistics.\n");
	printf("Enter [3] if you want to go back to the \"ADMINISTRATOR TOOLS\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(CLIENTSSTATISTICS_VIEW);
        show(WORKERDIVISION_VIEW);
    } else if (selectedView == 2) {
        show(BESTWORSTCLIENTSSTATISTICS_VIEW);
        show(WORKERDIVISION_VIEW);
    } else if (selectedView == 3) {
        show(ADMINTOOLS_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(WORKERDIVISION_VIEW);
    }
}