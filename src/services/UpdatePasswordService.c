void updatePasswordServiceValidatePassword(char password[]) {
    int passwordsMatch = 0;
    char validationPassword[30];

    while (passwordsMatch != 1) {
        printf("Confirm your password: ");
        scanf("%s", validationPassword);

        if (strcmp(password, validationPassword) == 0) {
            passwordsMatch = 1;
        } else {
            printf("The passwords don't match, enter you new password again: ");
            scanf("%s", password);
        }
    }
}

void updatePasswordServiceSetPassword(char password[30]) {
	printf("Enter your new password: ");
    scanf("%s", password);

    updatePasswordServiceValidatePassword(password);
}

void updatePasswordServiceUpdatePassword() {
    updatePasswordServiceSetPassword(currentUser.password);
    userRepositoryUpdateUser(currentUser);
}