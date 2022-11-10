void showMainView() {
    if (currentUser.role == ADMIN_ROLE) {
        printf("You are an \"Administrator\".\n");
    } else if (currentUser.role == CLIENT_ROLE) {
        printf("You are a \"Client\".\n");
    } else {
        show(MAINWORKER_VIEW);
    }
    return;
}
