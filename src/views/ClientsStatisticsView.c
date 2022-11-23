void showClientsStatisticsView() {
	printf("You are in the \"CLIENTS STATISTICS\" window.\n\n");

	clientsStatisticsServicePrintClientsStatistics();

	printf("Press [any key] to go back to the \"CLIENT DIVISION\" window.\n");
	getch();
}