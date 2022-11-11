ClientRequest clientRequestServiceGetCurrentClientRequest() {
    ClientRequest clientRequest;

    clientRequest = clientRequestRepositoryFindCurrentRequestByWorkerId(currentUser.id);

    if (clientRequest.id == -1) {
        clientRequest = clientRequestRepositoryFindOldestPendingRequest();
        clientRequest.requestStatus = PROCESSING;
        clientRequest.workerId = currentUser.id;

        clientRequestRepositoryUpdateRequest(clientRequest);
    }
    return clientRequest;
}