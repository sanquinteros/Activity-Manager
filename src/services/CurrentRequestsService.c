void currentRequestsServicePrintCurrentRequests() {
    int exists;

    printf("Only requests that are PENDING or PROCESSING will show up.\n\n");

    exists = clientRequestRepositoryExistsCurrentByClientId(currentUser.id);

    if (exists == 1) {
        clientRequestRepositoryPrintCurrentRequestsByClientId(currentUser.id);
    } else {
        printf("You have not created any requests that are currently pending or being processed.\n\n");
    }
}