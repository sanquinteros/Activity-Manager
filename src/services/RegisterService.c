Register registerServiceValidateUsername(Register rregister) {
    int usernameExists = 1;

    while (usernameExists == 1) {
        usernameExists = userRepositoryExistsByUsername(rregister.username);

        if (usernameExists == 1) {
            printf("Name already exists, enter another name: ");
            scanfUsername(rregister.username);
        }
    }
    return rregister;
}

Register registerServiceValidatePassword(Register rregister) {
    int passwordsMatch = 0;
    char validationPassword[30];

    while (passwordsMatch != 1) {
        printf("Confirm your password: ");
        scanfPassword(validationPassword);
        
        if (strcmp(rregister.password, validationPassword) == 0) {
            passwordsMatch = 1;
        } else {
            printf("The passwords don't match, enter your password: ");
            scanfPassword(rregister.password);
        }
    }
    return rregister;
}

Register registerServiceValidateRole(Register rregister) {
    int roleIsInvalid = 1;

    while (roleIsInvalid == 1) {
        if (rregister.role == ADMIN_ROLE  || rregister.role == CLIENT_ROLE  || rregister.role == WORKER_ROLE) {
            roleIsInvalid = 0;
        } else {
            printf("You entered role [%i], which is an invalid role.\n", rregister.role);
            printf("Enter your role: ");
            scanf("%i", &rregister.role);
	        getchar();
        }
    }
    return rregister;
}

Register getRegisterFromUser() {
    Register rregister;

    printf("Enter your name: ");
    scanfUsername(rregister.username);
    rregister = registerServiceValidateUsername(rregister);
	printf("Enter your password: ");
	scanfPassword(rregister.password);
	rregister = registerServiceValidatePassword(rregister);
    printf("If you want to register as an \"Administrator\", enter [%i].\n", ADMIN_ROLE);
    printf("If you want to register as a \"Client\", enter [%i].\n", CLIENT_ROLE);
    printf("If you want to register as a \"Worker\", enter [%i].\n", WORKER_ROLE);
    printf("Enter your role: ");
    scanf("%i", &rregister.role);
	getchar();

    rregister = registerServiceValidateRole(rregister);

    return rregister;
}

void registerServiceRegisterUser() {
    int userWasCreated;
    Register rregister;
    User userFromRegister;

    rregister = getRegisterFromUser();
    userFromRegister = constructUserFromRegister(rregister);
    userWasCreated = userRepositoryCreateUser(userFromRegister);

    if (userWasCreated == 1) {
        printf("You have successfully been registered.\n");
    } else {
        printf("An unexpected error occour, your user was not created.\n");
    }
}