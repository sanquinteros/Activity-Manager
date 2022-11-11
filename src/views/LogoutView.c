void showLogoutView() {
    logoutServiceLogoutUser();
    printf("You have successfully logged out.\n");

    redirectTo(WELCOME_VIEW);
}