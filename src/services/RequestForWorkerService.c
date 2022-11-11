ClientRequest getCurrentRequestOfWorker() {
    ClientRequest clientRequest;

    clientRequest = clientRequestRepositoryFindCurrentRequestByWorkerId(currentUser.id);

    if (clientRequest.id == -1) {
        clientRequest = clientRequestRepositoryFindOldestPendingRequest();

        if (clientRequest.id != -1) {
            clientRequest.requestStatus = PROCESSING;
            clientRequest.workerId = currentUser.id;
            clientRequestRepositoryUpdateRequest(clientRequest);
        }
    }
    return clientRequest;
}

void requestForWorkerServiceInformRequest() {
    ClientRequest clientRequest;

    clientRequest = getCurrentRequestOfWorker();

    if (clientRequest.id == -1) {
        printf("Currently there is not a client request you can work on.\n");
    } else {
        int response;

        printf("Request description: %s\n\n", clientRequest.request);
        printf("Enter [1] if you completed the request.\n");
        printf("Enter [2] if you are working on it.\n");
        printf("Enter here: ");
        scanf("%i", &response);
        getchar();

        if (response == 1) {
            clientRequest.requestStatus = DONE;
            clientRequestRepositoryUpdateRequest(clientRequest);
            printf("This request was marked as finished.\n");
        } else {
            printf("Thank you for keeping on working on this request, the client appreciates it.\n");
        }
    }
}