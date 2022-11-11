void showCurrentRequestsView() {
	printf("You are in the \"CURRENT REQUESTS\" window.\n");

    currentRequestsServicePrintCurrentRequests();

	printf("Press [any key] to go back to the \"REQUEST MENU\" window.\n");
	getch();
}