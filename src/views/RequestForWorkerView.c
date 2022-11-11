void showCurrentRequestForWorker() {
    ClientRequest clientRequest;

    clientRequest = clientRequestServiceGetCurrentClientRequest();

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

void showRequestForWorkerView() {
	printf("You are in the \"REQUEST FOR WORKER\" window.\n");
	showCurrentRequestForWorker();
    redirectTo(MAIN_VIEW);
}