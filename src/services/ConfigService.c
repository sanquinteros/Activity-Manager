void configServiceCreateClientTable(char pathForTables[]) {
	FILE * clientRequestTable;

	strcpy(pathForClientRequestTable, pathForTables);
	strcat(pathForClientRequestTable, "ClientRequest.txt");

	strcpy(pathForNewClientRequestTable, pathForTables);
	strcat(pathForNewClientRequestTable, "newClientRequest.txt");

	strcpy(deleteClientRequestTable, "del ");
	strcat(deleteClientRequestTable, pathForClientRequestTable);

	strcpy(renameClientRequestTable, "rename ");
	strcat(renameClientRequestTable, pathForTables);
	strcat(renameClientRequestTable, "newClientRequest.txt ClientRequest.txt");

	clientRequestTable = fopen(pathForClientRequestTable, "a");

	fclose(clientRequestTable);
}

void configServiceCreateUserTable(char pathForTables[]) {
	FILE * userTable;

	strcpy(pathForUserTable, pathForTables);
	strcat(pathForUserTable, "User.txt");

	strcpy(pathForNewUserTable, pathForTables);
	strcat(pathForNewUserTable, "newUser.txt");

	strcpy(deleteUserTable, "del ");
	strcat(deleteUserTable, pathForUserTable);

	strcpy(renameUserTable, "rename ");
	strcat(renameUserTable, pathForTables);
	strcat(renameUserTable, "newUser.txt User.txt");

	userTable = fopen(pathForUserTable, "a");

	fclose(userTable);
}

void configServiceSetPathOfAllTables() {
	printf("Enter relative path where tables will be located OR enter [any number] if you do not have one.\n");
	printf("Enter here: ");
	scanf("%s", pathForTables);
	getchar();

	if (strlen(pathForTables) < 2) {
        configServiceCreateClientTable("");
        configServiceCreateUserTable("");
	} else {
        configServiceCreateClientTable(pathForTables);
        configServiceCreateUserTable(pathForTables);
	}
}
