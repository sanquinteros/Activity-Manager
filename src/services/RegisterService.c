Register validateUsername(Register rregister) {
    int usernameExists = 1;

    while (usernameExists == 1) {
        usernameExists = existsByUsername(rregister.username);

        if (usernameExists == 1) {
            printf("Name already exists, enter another name: ");
            scanf("%s", rregister.username);
        }
    }
    return rregister;
}

Register validatePassword(Register rregister) {
    int passwordIsInvalid = 1;
    char validationPassword[50];

    while (passwordIsInvalid == 1) {
        printf("Confirm your password: ");
        scanf("%s", validationPassword);
        
        if (strcmp(rregister.password, validationPassword) == 0) {
            passwordIsInvalid = 0;
        } else {
            printf("The passwords don't match, enter again your password: ");
            scanf("%s", rregister.password);
        }
    }
    return rregister;
}

Register validateRole(Register rregister) {
    int roleIsInvalid = 1;

    while (roleIsInvalid == 1) {
        if (rregister.role == ADMIN_ROLE  || rregister.role == CLIENT_ROLE  || rregister.role == WORKER_ROLE) {
            roleIsInvalid = 0;
        } else {
            printf("You entered role [%i], which is an invalid role.\n", rregister.role);
            printf("Enter your role: ");
            scanf("%i", &rregister.role);
        }
    }
    return rregister;
}