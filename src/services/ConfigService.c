void configServiceCreateTables(char pathForTables[]) {
	FILE * clientRequestTable;
	FILE * userTable;
	char pathForClientRequestTable[1018];
	char pathForUserTable[1007];

	strcpy(pathForClientRequestTable, pathForTables);
    strcat(pathForClientRequestTable, "ClientRequest.txt");

    strcpy(pathForUserTable, pathForTables);
    strcat(pathForUserTable, "User.txt");

	clientRequestTable = fopen(pathForClientRequestTable, "a");
	fclose(clientRequestTable);

	userTable = fopen(pathForUserTable, "a");
	fclose(userTable);
}

void setAllPaths(Path * path) {
	strcpy(path->clientRequestTable, path->root);
	strcat(path->clientRequestTable, "ClientRequest.txt");

	strcpy(path->newClientRequestTable, path->root);
	strcat(path->newClientRequestTable, "newClientRequest.txt");

	strcpy(path->deleteClientRequestTable, "del ");
	strcat(path->deleteClientRequestTable, path->clientRequestTable);

	strcpy(path->renameClientRequestTable, "rename ");
	strcat(path->renameClientRequestTable, path->root);
	strcat(path->renameClientRequestTable, "newClientRequest.txt ClientRequest.txt");

	strcpy(path->userTable, path->root);
	strcat(path->userTable, "User.txt");

	strcpy(path->newUserTable, path->root);
	strcat(path->newUserTable, "newUser.txt");

	strcpy(path->deleteUserTable, "del ");
	strcat(path->deleteUserTable, path->userTable);

	strcpy(path->renameUserTable, "rename ");
	strcat(path->renameUserTable, path->root);
	strcat(path->renameUserTable, "newUser.txt User.txt");
}

void configServiceSetPathOfAllTables() {
    pathRepositorySetRoot(currentPath.root);

    if (currentPath.root[0] == '\0') {
        printf("Enter path of sharing tables OR enter [any number] if you will host the tables on this machine.\n");
        printf("Enter here: ");
        scanfWithSpace(currentPath.root);

        if (strlen(currentPath.root) < 2) {
            strcpy(currentPath.root, "NULL");
        }
        pathRepositorySaveRoot(currentPath.root);

        if (strcmp(currentPath.root, "NULL") == 0) {
            configServiceCreateTables("");
        } else {
            configServiceCreateTables(currentPath.root);
        }
    }

    if (strcmp(currentPath.root, "NULL") == 0) {
        strcpy(currentPath.root, "");
    }
    setAllPaths(&currentPath);
}
