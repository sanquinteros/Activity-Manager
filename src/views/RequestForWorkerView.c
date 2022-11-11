void showCurrentRequestForWorker() {
    ClientRequest clientRequest;

    clientRequest = clientRequestServiceGetCurrentClientRequest();

    if (clientRequest.id == -1) {
        printf("Currently there is not a client request you can work on.\n");
    } else {
        char response;

        printf("Your current request is: \n%s\n\n", clientRequest.request);
        printf("Did you complete this request? [y/n] : ");
        scanf("%c", response);
        getchar();

        if (response == 'y') {
            clientRequest.requestStatus = DONE;
            clientRequestRepositoryUpdateRequest(clientRequest);
            printf("This request was marked as finished.");
        }
    }
}

void showRequestForWorkerView() {
	printf("You are in the \"REQUEST FOR WORKER\" window.\n");
	showCurrentRequestForWorker();
    redirectTo(MAIN_VIEW);
}