void deleteRequestServiceDeleteRequest() {
    int id;
    int requestWasDeleted;

	printf("In order to delete one of your current requests, you have to provide its identification number.\n");
	printf("Enter the identification number here: ");
    scanf("%i", &id);
	getchar();

    requestWasDeleted = clientRequestRepositoryDeleteRequest(id, currentUser.id);

    if (requestWasDeleted == 1) {
        printf("Request was successfully found and deleted.\n");
    } else {
        printf("An invalid identification number was provided, none requests were deleted.\n");
    }
}