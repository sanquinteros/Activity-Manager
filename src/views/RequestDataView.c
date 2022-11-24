void showRequestDataView() {
    RequestData requestData;
    requestData = requestDataServiceGetRequestData();
    float percentageStatusList[] = {
        requestDataServiceGetPendingRequestsPercentage(requestData),
        requestDataServiceGetProcessingRequestsPercentage(requestData),
        requestDataServiceGetConcludedRequestsPercentage(requestData)
    };

	printf("You are in the \"REQUEST DATA\" window.\n\n");
    printf("Number of requests made: %i.\n", requestData.totalRequests);
	printf("'%i' (%0.2f%c) of them are pending.\n", requestData.pendingRequests, percentageStatusList[0], 37);
	printf("'%i' (%0.2f%c) of them are being processed.\n", requestData.processingRequests, percentageStatusList[1], 37);
	printf("'%i' (%0.2f%c) of them are concluded.\n\n", requestData.concludedRequests, percentageStatusList[2], 37);

	printf("Press [any key] to go back to the \"ADMINISTRATOR TOOLS\" window.\n");
	getch();
}