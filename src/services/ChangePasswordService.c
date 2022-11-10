char * changePasswordServiceValidatePassword(char * password) {
    int passwordIsInvalid = 1;
    char validationPassword[50];

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
    return password;
}

char * changePasswordServiceGetPassword() {
    char password[50];

	printf("Enter your new password: ");
    scanf("%s", password);

	return changePasswordServiceValidatePassword(password);
}


void changePasswordServiceChangePassword(User * user) {
    strcpy(user->password, changePasswordServiceGetPassword());
    userRepositoryUpdateUserPassword(* user);
}