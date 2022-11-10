void updateUsernameServiceValidateUsername(char username[50]) {
    int usernameExists = 1;

    while (usernameExists == 1) {
        usernameExists = userRepositoryExistsByUsername(username);

        if (usernameExists == 1) {
            printf("Name already exists, enter another name: ");
            scanf("%s", username);
        }
    }
}

void updateUsernameServiceSetUsername(char username[50]) {
	printf("Enter your new name: ");
    scanf("%s", username);

    updateUsernameServiceValidateUsername(username);
}

void updateUsernameServiceUpdateUsername(User * user) {
    updateUsernameServiceSetUsername(user->username);
    userRepositoryUpdateUser(* user);
}