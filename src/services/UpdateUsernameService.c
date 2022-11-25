void updateUsernameServiceValidateUsername(char username[50]) {
    int usernameExists = 1;

    while (usernameExists == 1) {
        usernameExists = userRepositoryExistsByUsername(username);

        if (usernameExists == 1) {
            printf("Name already exists, enter another name: ");
            scanfWithSpace(username, 50);
        }
    }
}

void updateUsernameServiceSetUsername(char username[50]) {
	printf("Enter your new name: ");
    scanfWithSpace(username, 50);

    updateUsernameServiceValidateUsername(username);
}

void updateUsernameServiceUpdateUsername() {
    updateUsernameServiceSetUsername(currentUser.username);
    userRepositoryUpdateUser(currentUser);
}