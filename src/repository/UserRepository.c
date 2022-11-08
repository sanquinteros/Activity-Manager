User userRepositoryFindUser(User user) {
    User dbUser;
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) == 0) {
        user.id = -1;
        user.role = -1;
        return user;
    } else {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (strcmp(dbUser.username, user.username) == 0) {
                if (strcmp(dbUser.password, user.password) == 0) {
                    user.id = dbUser.id;
                    strcpy(user.username, dbUser.username);
                    strcpy(user.password, dbUser.password);
                    user.role = dbUser.role;

                    return user;
                }
            }
        }
    }
    fclose(userTable);

    user.id = -1;
    user.role = -1;
    return user;
}

int userRepositoryGetLastUserId() {
	User user;
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) == 0) {
        return -1;
    } else {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &user.id, user.username, user.password, &user.role);
        }
    }
    fclose(userTable);

    return user.id;
}

int userRepositoryExistsByUsername(char username[50]) {
    int exists = 0;
    FILE *userTable;
    User user;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) != 0) {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &user.id, user.username, user.password, &user.role);

            if (strcmp(user.username, username) == 0) {
                exists = 1;
            }
        }
    }
    fclose(userTable);
    return exists;
}

int userRepositorySaveUser(User user) {
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "a");
    fprintf(userTable, "%i %s %s %i\n", user.id, user.username, user.password, user.role);
    fclose(userTable);

    return 1;
}