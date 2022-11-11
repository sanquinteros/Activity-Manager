void showRequestForWorkerView() {
	printf("You are in the \"REQUEST FOR WORKER\" window.\n");

	requestForWorkerServiceInformRequest();

    redirectTo(MAIN_VIEW);
}