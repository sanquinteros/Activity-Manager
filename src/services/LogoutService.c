void logoutServiceLogoutUser() {
    currentUser.id = -1;
    strcpy(currentUser.username, "-1");
    strcpy(currentUser.password, "-1");
    currentUser.role = -1;
}