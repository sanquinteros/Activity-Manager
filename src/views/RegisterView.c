Register getRegister() {
    Register rregister;

    printf("Enter your name: ");
    scanf("%s", rregister.username);
    rregister = registerServiceValidateUsername(rregister);
	printf("Enter your password: ");
	scanf("%s", rregister.password);
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

void showRegisterView() {
	printf("You are in the \"REGISTER\" window.\n");

    int userWasCreated = userRepositoryCreateUser(constructUserFromRegister(getRegister()));

    if (userWasCreated == 1) {
        printf("You have successfully been registered.\n");
    } else {
        printf("An unexpected error occour, your user was not created.\n");
    }
    redirectTo(WELCOME_VIEW);
}