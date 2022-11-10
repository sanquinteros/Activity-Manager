void popInvalidViewMessage() {
    system("cls");

    printf("You have selected an invalid view.\n");
}

char * getRoleName(int role) {
    if (role == ADMIN_ROLE) {
        return "ADMINISTRATOR";
    } else if (role == CLIENT_ROLE) {
        return "CLIENT";
    } else {
        return "WORKER";
    }
}