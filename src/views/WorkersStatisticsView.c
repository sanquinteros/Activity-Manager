void showWorkersStatisticsView() {
	printf("You are in the \"WORKERS STATISTICS\" window.\n\n");

	workersStatisticsServicePrintWorkersStatistics();

	printf("Press [any key] to go back to the \"WORKER DIVISION\" window.\n");
	getch();
}