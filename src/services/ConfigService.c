void configServiceVerifyRootLength(char root[]) {
    int lastChar = strlen(root) - 1;

    if (lastChar >= 998) {
        printf("\nA custom exception has occurred:\nRoot can not be longer than 998 characters.\n\n");
        printf("Press [any key] to exit the software.\n");
        getch();

        exit(0);
    }
}

void configServiceVerifyRootHasNoneSpaces(char root[]) {
    for(int counter = 0; counter < strlen(root); counter++) {
        if (root[counter] == ' ') {
            printf("\nA custom exception has occurred:\nRoot can not have spaces.\n\n");
            printf("Press [any key] to exit the software.\n");
            getch();

            exit(0);
        }
    }
}

void configServiceVerifyRootHasEndBackslash(char root[]) {
    int lastChar = strlen(root) - 1;

    if (root[lastChar] != '\\') {
        root[lastChar + 1] = '\\';
        root[lastChar + 2] = '\0';
    }
}

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

void configServiceSetAllPaths(Path * path) {
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
        char mode;

        printf("Will you be using this software on default mode? [y]/[n]: ");
        scanf("%c", &mode);
        getchar();

        while(mode != 'y' && mode != 'n') {
            printf("You have entered an invalid response.\nEnter [y] for YES or [n] for NO: ");
            scanf("%c", &mode);
            getchar();
        }

        if (mode == 'y') {
            strcpy(currentPath.root, "DEFAULT_MODE");
        } else {
            printf("\nEnter path from root where tables will be or are located.\n");
            printf("Enter here: ");
            scanfWithSpace(currentPath.root, 1000);

            configServiceVerifyRootLength(currentPath.root);
            configServiceVerifyRootHasNoneSpaces(currentPath.root);
            configServiceVerifyRootHasEndBackslash(currentPath.root);
        }
        pathRepositorySaveRoot(currentPath.root);

        if (strcmp(currentPath.root, "DEFAULT_MODE") == 0) {
            configServiceCreateTables("");
        } else {
            configServiceCreateTables(currentPath.root);
        }
    }

    if (strcmp(currentPath.root, "DEFAULT_MODE") == 0) {
        strcpy(currentPath.root, "");
    }
    configServiceSetAllPaths(&currentPath);
}