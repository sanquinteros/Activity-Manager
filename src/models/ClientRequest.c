typedef struct ClientRequest {
    int id;
    int requestStatus;
    int workerId;
    int clientId;
    char request[500];
} ClientRequest;