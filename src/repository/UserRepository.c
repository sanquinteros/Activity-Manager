User userRepositoryFindUser(User user) {
    User dbUser;
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) == 0) {
        user.id = -1;
        user.role = -1;

        fclose(userTable);

        return user;
    } else {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (strcmp(dbUser.username, user.username) == 0) {
                if (strcmp(dbUser.password, user.password) == 0) {
                    fclose(userTable);

                    return dbUser;
                }
            }
        }
    }
    user.id = -1;
    user.role = -1;

    fclose(userTable);

    return user;
}

int userRepositoryGetLastUserId() {
	User user;
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) == 0) {
        fclose(userTable);

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

int userRepositoryCreateUser(User user) {
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "a");
    fprintf(userTable, "%i %s %s %i\n", user.id, user.username, user.password, user.role);
    fclose(userTable);

    return 1;
}

int userRepositoryUpdateUser(User user) {
	User dbUser;
    FILE * userTable;
    FILE * newUserTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) == 0) {
        fclose(userTable);

        return -1;
    } else {
        newUserTable = fopen("../tables/newUser.txt", "w");
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (user.id == dbUser.id) {
                fprintf(newUserTable, "%i %s %s %i\n", user.id, user.username, user.password, user.role);
            } else {
                fprintf(newUserTable, "%i %s %s %i\n", dbUser.id, dbUser.username, dbUser.password, dbUser.role);
            }
        }
    }
    fclose(userTable);
    fclose(newUserTable);

    system("del ..\\tables\\User.txt");
    system("rename ..\\tables\\newUser.txt User.txt");

    return 1;
}