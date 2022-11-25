void validateRequest(char request[]) {
    int requestIsInvalid = 1;

    while (requestIsInvalid == 1) {
        if (strlen(request) > 500) {
            printf("Your request is too long (more than 500 characters).\nEnter a shorter request: ");
            scanfWithSpace(request, 500);
        } else {
            requestIsInvalid = 0;
        }
    }
}

void createRequestServiceCreateRequest() {
    ClientRequest clientRequest;
    clientRequest.clientId = currentUser.id;

    printf("Enter your request: ");
    scanfWithSpace(clientRequest.request, 500);
    validateRequest(clientRequest.request);

    clientRequestRepositoryCreateRequest(clientRequest);

    printf("You request was successfully created\n");
}