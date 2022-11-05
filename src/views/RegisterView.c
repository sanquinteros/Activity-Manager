Register getRegister() {
    Register rregister;

    printf("Enter your name: ");
    scanf("%s", rregister.username);
    rregister = validateUsername(rregister);
	printf("Enter your password: ");
	scanf("%s", rregister.password);
	rregister = validatePassword(rregister);
    printf("If you want to register as an \"Administrator\", enter [%i].\n", ADMIN_ROLE);
    printf("If you want to register as a \"Client\", enter [%i].\n", CLIENT_ROLE);
    printf("If you want to register as a \"Worker\", enter [%i].\n", WORKER_ROLE);
    printf("Enter your role: ");
    scanf("%i", &rregister.role);
    rregister = validateRole(rregister);

    return rregister;
}

void showRegisterView() {
	printf("You are in the \"REGISTER\" window.\n");

    Register rregister = getRegister();
    User user = constructUserFromRegister(getLastUserId() + 1, rregister);
    int userWasCreated = saveUser(user);

    if (userWasCreated == 1) {
        printf("You have been registered sucessfully!\n");
        sleep(REDIRECT_TIME);
        printf("You are being redirected to the \"WELCOME\" window.\n");
    } else {
        printf("An unexpected error occour, your user was not created!\n");
        sleep(REDIRECT_TIME);
        printf("You are being redirected to the \"WELCOME\" window.\n");
    }
    sleep(REDIRECT_TIME);
    show(WELCOME_VIEW);
}