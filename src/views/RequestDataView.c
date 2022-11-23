void showRequestDataView() {
    RequestData requestData;
    requestData = requestDataServiceGetRequestData();

	printf("You are in the \"REQUEST DATA\" window.\n\n");
    printf("Number of requests made: %i.\n", requestData.totalRequests);
	printf("'%i' (%0.2f%c) of them are pending.\n", requestData.pendingRequests, (requestData.pendingRequests * 100.) / requestData.totalRequests, 37);
	printf("'%i' (%0.2f%c) of them are being processed.\n", requestData.processingRequests, (requestData.processingRequests * 100.) / requestData.totalRequests, 37);
	printf("'%i' (%0.2f%c) of them are concluded.\n\n", requestData.concludedRequests, (requestData.concludedRequests * 100.) / requestData.totalRequests, 37);

	printf("Press [any key] to go back to the \"ADMINISTRATOR TOOLS\" window.\n");
	getch();
}