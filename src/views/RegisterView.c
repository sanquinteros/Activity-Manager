void showRegisterView() {
    system("cls");
	printf("Welcome to the \"Register\" window !\n");
	return;
}

int getRole() {
    int role;

    printf("If you want to register as an \"Admin\", enter \"%i\".\n", ADMIN_ROLE);
    printf("If you want to register as a \"Client\", enter \"%i\".\n", CLIENT_ROLE);
    printf("If you want to register as a \"Worker\", enter \"%i\".\n", WORKER_ROLE);
    printf("Enter role here: ");
    scanf("%i", &role);

    return role;
}

void getValidRole(int *role) {
    *role = getRole();

    if (isRoleValid(*role) == 0) {
        printf("You entered role \"%i\", which is an invalid role, enter a valid role.\n", role);
        getValidRole(&*role);
    }
    return;
}

Register getRegisterFromRegisterView() {
    Register rregister;

    printf("Please, enter your name: ");
    scanf("%s", rregister.username);
	printf("Please, enter your password: ");
	scanf("%s", rregister.password);
    getValidRole(&rregister.role);

    return rregister;
}