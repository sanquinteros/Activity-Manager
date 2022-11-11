void currentRequestsServicePrintCurrentRequests() {
    int exists;

    exists = clientRequestRepositoryExistsCurrentByClientId(currentUser.id);

    if (exists == 1) {
        clientRequestRepositoryPrintCurrentRequestsByClientId(currentUser.id);
    } else {
        printf("You have not created any requests that are currently pending or being processed.\n");
    }
}