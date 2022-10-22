User getUserFromLogin(Login login) {
    int id;
    char username[50];
    char password[30];
    int role;

    FILE *userTable;
    userTable = fopen("../tables/UserTable.txt", "r");
    while(!feof(userTable)) {
        fscanf(userTable, "%i %s %s %i\n", &id, username, password, &role);

        if (strcmp(login.username, username) == 0) {
            if (strcmp(login.password, password) == 0) {
                user.id = id;
                user.isAuthenticated = 1;
                user.role = role;
                return user;
            } else {
                user.id = id;
                user.isAuthenticated = 0;
                user.role = -1;
                return user;
            }
        }
    }
    fclose(userTable);
    user.id = -1;
    user.isAuthenticated = 0;
    user.role = -1;
    return user;
}