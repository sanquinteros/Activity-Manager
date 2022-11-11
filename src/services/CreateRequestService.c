void validateRequest(char request[]) {
    int requestIsInvalid = 1;

    while (requestIsInvalid == 1) {
        if (strlen(request) > 500) {
            printf("Your request is too long (more than 500 characters).\nEnter a shorter request: ");
            scanf("%[^\n]%*c", request);
        } else if (containsEncodedSpace(request) == 1){
            printf("Your request contains the invalid character \"&\".\nEnter a request without that character: ");
            scanf("%[^\n]%*c", request);
        } else {
            requestIsInvalid = 0;
        }
    }
}

void createRequestServiceCreateRequest() {
    ClientRequest clientRequest;
    clientRequest.clientId = currentUser.id;

    printf("Enter your request: ");
    scanf("%[^\n]%*c", clientRequest.request);
    validateRequest(clientRequest.request);

    clientRequestRepositoryCreateRequest(clientRequest);

    printf("You request was created with sucess!\n");
}