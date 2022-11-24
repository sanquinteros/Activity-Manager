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