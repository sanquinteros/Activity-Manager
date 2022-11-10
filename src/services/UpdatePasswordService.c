void updatePasswordServiceValidatePassword(char password[30]) {
    int passwordIsInvalid = 1;
    char validationPassword[30];

    while (passwordIsInvalid == 1) {
        printf("Confirm your password: ");
        scanf("%s", validationPassword);

        if (strcmp(password, validationPassword) == 0) {
            passwordIsInvalid = 0;
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


void updatePasswordServiceUpdatePassword(User * user) {
    updatePasswordServiceSetPassword(user->password);
    userRepositoryUpdateUser(* user);
}