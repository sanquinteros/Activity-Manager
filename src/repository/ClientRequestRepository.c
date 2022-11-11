ClientRequest clientRequestRepositoryFindRequestById(int requestId) {
    ClientRequest dbClientRequest;
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) != 0) {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (requestId == dbClientRequest.id) {
                fclose(clientRequestTable);

                return dbClientRequest;
            }
        }
    }
    dbClientRequest.id = -1;
    dbClientRequest.requestStatus= -1;
    dbClientRequest.workerId = -1;
    dbClientRequest.clientId= -1;
    strcpy(dbClientRequest.request, " ");

    fclose(clientRequestTable);

    return dbClientRequest;
}

ClientRequest clientRequestRepositoryFindCurrentRequestByWorker(int workerId) {
    ClientRequest dbClientRequest;
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) != 0) {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (workerId == dbClientRequest.workerId) {
                if (PROCESSING == dbClientRequest.requestStatus) {
                    fclose(clientRequestTable);

                    return dbClientRequest;
                }
            }
        }
    }
    dbClientRequest.id = -1;
    dbClientRequest.requestStatus= -1;
    dbClientRequest.workerId = -1;
    dbClientRequest.clientId= -1;
    strcpy(dbClientRequest.request, " ");

    fclose(clientRequestTable);

    return dbClientRequest;
}

ClientRequest clientRequestRepositoryFindOldestPendingRequest() {
    ClientRequest dbClientRequest;
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) != 0) {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (PENDING == dbClientRequest.requestStatus) {
                fclose(clientRequestTable);

                return dbClientRequest;
            }
        }
    }
    dbClientRequest.id = -1;
    dbClientRequest.requestStatus= -1;
    dbClientRequest.workerId = -1;
    dbClientRequest.clientId= -1;
    strcpy(dbClientRequest.request, " ");

    fclose(clientRequestTable);

    return dbClientRequest;
}

int clientRequestRepositoryGetLastRequestId() {
	ClientRequest dbClientRequest;
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) == 0) {
        fclose(clientRequestTable);

        return -1;
    } else {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);
        }
    }
    fclose(clientRequestTable);

    return dbClientRequest.id;
}

int clientRequestRepositoryCreateRequest(ClientRequest clientRequest) {
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "a");
    fprintf(clientRequestTable, "%i %i %i %i %s\n", clientRequestRepositoryGetLastRequestId() + 1, PENDING, -1, clientRequest.clientId, clientRequest.request);
    fclose(clientRequestTable);

    return 1;
}

int clientRequestRepositoryUpdateRequest(ClientRequest clientRequest) {
	ClientRequest dbClientRequest;
    FILE * clientRequestTable;
    FILE * newClientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) == 0) {
        fclose(clientRequestTable);

        return -1;
    } else {
        newClientRequestTable = fopen("../tables/newClientRequest.txt", "w");
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (clientRequest.id == dbClientRequest.id) {
                fprintf(newClientRequestTable, "%i %i %i %i %s\n", clientRequest.id, clientRequest.requestStatus, clientRequest.workerId, clientRequest.clientId, clientRequest.request);
            } else {
                fprintf(newClientRequestTable, "%i %i %i %i %s\n", dbClientRequest.id, dbClientRequest.requestStatus, dbClientRequest.workerId, dbClientRequest.clientId, dbClientRequest.request);
            }
        }
    }
    fclose(clientRequestTable);
    fclose(newClientRequestTable);

    system("del ..\\tables\\ClientRequest.txt");
    system("rename ..\\tables\\newClientRequest.txt ClientRequest.txt");

    return 1;
}