int clientRequestRepositoryExistsCurrentByClientId(int clientId) {
    ClientRequest dbClientRequest;
    FILE *clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) != 0) {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (clientId == dbClientRequest.clientId) {
                if (PENDING == dbClientRequest.requestStatus || PROCESSING == dbClientRequest.requestStatus) {
                    fclose(clientRequestTable);

                    return 1;
                }
            }
        }
    }
    fclose(clientRequestTable);

    return 0;
}

ClientRequest clientRequestRepositoryFindCurrentRequestByWorkerId(int workerId) {
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
                    decodeSpaces(dbClientRequest.request);
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
                decodeSpaces(dbClientRequest.request);
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

void clientRequestRepositoryPrintCurrentRequestsByClientId(int clientId) {
    ClientRequest dbClientRequest;
    FILE * clientRequestTable;

    clientRequestTable = fopen("../tables/ClientRequest.txt", "r");

    fseek(clientRequestTable, 0, SEEK_END);

    if (ftell(clientRequestTable) != 0) {
        rewind(clientRequestTable);

        while(!feof(clientRequestTable)) {
            fscanf(clientRequestTable, "%i %i %i %i %s\n", &dbClientRequest.id, &dbClientRequest.requestStatus, &dbClientRequest.workerId, &dbClientRequest.clientId, dbClientRequest.request);

            if (clientId == dbClientRequest.clientId) {
                if (PENDING == dbClientRequest.requestStatus || PROCESSING == dbClientRequest.requestStatus) {
                    printf("Request identification number: %i\nRequest status: %s\nRequest description: %s\n\n", dbClientRequest.id, getRequestStatusName(dbClientRequest.requestStatus), decodeSpaces(dbClientRequest.request));
                }
            }
        }
    }
    fclose(clientRequestTable);
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
    fprintf(clientRequestTable, "%i %i %i %i %s\n", clientRequestRepositoryGetLastRequestId() + 1, PENDING, -1, clientRequest.clientId, encodeSpaces(clientRequest.request));
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
                fprintf(newClientRequestTable, "%i %i %i %i %s\n", dbClientRequest.id, clientRequest.requestStatus, clientRequest.workerId, dbClientRequest.clientId, dbClientRequest.request);
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

int clientRequestRepositoryDeleteRequest(int id, int clientId) {
    int deleted = 0;
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

            if (id == dbClientRequest.id) {
                if (clientId == dbClientRequest.clientId) {
                    if (PENDING == dbClientRequest.requestStatus || PROCESSING == dbClientRequest.requestStatus) {
                        deleted = 1;
                    } else {
                        fprintf(newClientRequestTable, "%i %i %i %i %s\n", dbClientRequest.id, dbClientRequest.requestStatus, dbClientRequest.workerId, dbClientRequest.clientId, dbClientRequest.request);
                    }
                } else {
                    fprintf(newClientRequestTable, "%i %i %i %i %s\n", dbClientRequest.id, dbClientRequest.requestStatus, dbClientRequest.workerId, dbClientRequest.clientId, dbClientRequest.request);
                }
            } else {
                fprintf(newClientRequestTable, "%i %i %i %i %s\n", dbClientRequest.id, dbClientRequest.requestStatus, dbClientRequest.workerId, dbClientRequest.clientId, dbClientRequest.request);
            }
        }
    }
    fclose(clientRequestTable);
    fclose(newClientRequestTable);

    system("del ..\\tables\\ClientRequest.txt");
    system("rename ..\\tables\\newClientRequest.txt ClientRequest.txt");

    return deleted;
}