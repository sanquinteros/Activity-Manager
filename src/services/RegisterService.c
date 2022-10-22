int isRoleValid(int role) {
    if (role == ADMIN_ROLE) {
        return 1;
    }
    if (role == CLIENT_ROLE) {
        return 1;
    }
    if (role == WORKER_ROLE) {
        return 1;
    }
    0;
}