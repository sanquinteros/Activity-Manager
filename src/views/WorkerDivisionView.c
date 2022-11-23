void showWorkerDivisionView() {
	printf("You are in the \"WORKER DIVISION\" window.\n\n");

	printf("Enter [1] if you want to see workers statistics.\n");
	printf("Enter [2] if you want to see the best and worst workers statistics.\n");
/*
    The system has to consider various overlooked details in order to fire some worker,
    we can't support this feature right now.

	printf("Enter [] if you want to fire some worker.\n");
*/
	printf("Enter [3] if you want to go back to the \"ADMINISTRATOR TOOLS\" window.\n");
    printf("Enter here: ");
	scanf("%i", &selectedView);
	getchar();

    if (selectedView == 1) {
        show(WORKERSSTATISTICS_VIEW);
        show(WORKERDIVISION_VIEW);
    } else if (selectedView == 2) {
        show(BESTWORSTWORKERSSTATISTICS_VIEW);
        show(WORKERDIVISION_VIEW);
    } else if (selectedView == 3) {
        show(ADMINTOOLS_VIEW);
    } else {
        popInvalidViewMessage();
        redirectTo(WORKERDIVISION_VIEW);
    }
}