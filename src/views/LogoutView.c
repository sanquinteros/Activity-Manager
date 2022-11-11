void showLogoutView() {
    logoutServiceLogoutUser();
    printf("You have sucessfully logged out.\n");

    redirectTo(WELCOME_VIEW);
}