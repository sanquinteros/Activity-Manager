void showRegisterView() {
    system("cls");
	printf("Welcome to the \"Register\" window !\n");
	return;
}

void forceUserToSelectValidRole(int *role) {
    printf("You entered role \"%i\", which is an invalid role, enter a valid role.\n", *role);
    printf("Enter role here: ");
    scanf("%i", &*role);

    if (*role == ADMIN_ROLE) {
        return;
    }
    if (*role == CLIENT_ROLE) {
        return;
    }
    if (*role == WORKER_ROLE) {
        return;
    }
    forceUserToSelectValidRole(role);
}

Register getRegisterFromRegisterView() {
    Register rregister;

	printf("Please, enter your name: ");
	scanf("%s", rregister.username);
	printf("Please, enter your password: ");
	scanf("%s", rregister.password);
    printf("If you want to register as an \"Admin\", enter \"%i\".\n", ADMIN_ROLE);
    printf("If you want to register as a \"Client\", enter \"%i\".\n", CLIENT_ROLE);
    printf("If you want to register as a \"Worker\", enter \"%i\".\n", WORKER_ROLE);
    printf("Enter role here: ");
    scanf("%i", &rregister.role);

    if (rregister.role == ADMIN_ROLE) {
        return rregister;
    }
    if (rregister.role == CLIENT_ROLE) {
        return rregister;
    }
    if (rregister.role == WORKER_ROLE) {
        return rregister;
    }
    forceUserToSelectValidRole(&rregister.role);
    return rregister;
}