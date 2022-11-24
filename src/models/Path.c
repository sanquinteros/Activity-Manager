typedef struct Path {
    char root[1000];
    char clientRequestTable[1017];
    char newClientRequestTable[1020];
    char deleteClientRequestTable[1021];
    char renameClientRequestTable[1024];
    char userTable[1007];
    char newUserTable[10010];
    char deleteUserTable[1011];
    char renameUserTable[1014];
} Path;