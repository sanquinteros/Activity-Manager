RequestData requestDataServiceGetRequestData() {
    return clientRequestRepositoryGetRequestData();
}

int requestDataServiceGetPendingRequestsPercentage(RequestData requestData) {
    int pendingRequestsPercentage = 0;

    if (requestData.totalRequests != 0) {
        pendingRequestsPercentage = (requestData.pendingRequests * 100.) / requestData.totalRequests;
    }
    return pendingRequestsPercentage;
}

int requestDataServiceGetProcessingRequestsPercentage(RequestData requestData) {
    int processingRequestsPercentage = 0;

    if (requestData.totalRequests != 0) {
        processingRequestsPercentage = (requestData.processingRequests * 100.) / requestData.totalRequests;
    }
    return processingRequestsPercentage;
}

int requestDataServiceGetConcludedRequestsPercentage(RequestData requestData) {
    int concludedRequestsPercentage = 0;

    if (requestData.totalRequests != 0) {
        concludedRequestsPercentage = (requestData.concludedRequests * 100.) / requestData.totalRequests;
    }
    return concludedRequestsPercentage;
}

void requestDataServicePrintRequestData() {
    RequestData requestData = requestDataServiceGetRequestData();
    float percentageStatusList[] = {
        requestDataServiceGetPendingRequestsPercentage(requestData),
        requestDataServiceGetProcessingRequestsPercentage(requestData),
        requestDataServiceGetConcludedRequestsPercentage(requestData)
    };

    printf("Number of requests made: %i.\n", requestData.totalRequests);
	printf("'%i' (%0.2f%c) of them are pending.\n", requestData.pendingRequests, percentageStatusList[0], 37);
	printf("'%i' (%0.2f%c) of them are being processed.\n", requestData.processingRequests, percentageStatusList[1], 37);
	printf("'%i' (%0.2f%c) of them are concluded.\n\n", requestData.concludedRequests, percentageStatusList[2], 37);
}