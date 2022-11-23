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

int userRepositoryExistsByIdAndRole(int id, int role) {
    int exists = 0;
    FILE *userTable;
    User dbUser;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) != 0) {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (dbUser.id == id) {
                if (dbUser.role == role) {
                    exists = 1;
                }
            }
        }
    }
    fclose(userTable);

    return exists;
}

int userRepositoryCreateUser(User user) {
    FILE *userTable;

    userTable = fopen("../tables/User.txt", "a");
    fprintf(userTable, "%i %s %s %i\n", (userRepositoryGetLastUserId() + 1), user.username, user.password, user.role);
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
                fprintf(newUserTable, "%i %s %s %i\n", dbUser.id, dbUser.username, user.password, dbUser.role);
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

WorkerArray userRepositoryFindAllWorkers() {
    WorkerArray workerArray = {malloc(sizeof(Worker)), 0};
	User dbUser;
    FILE * userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) != 0) {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (dbUser.role == WORKER_ROLE) {
                workerArray.worker = realloc(workerArray.worker, sizeof(Worker) * ++workerArray.length);
                workerArray.worker[workerArray.length - 1].id = dbUser.id;
                strcpy(workerArray.worker[workerArray.length - 1].username, dbUser.username);
                workerArray.worker[workerArray.length - 1].concludedRequests = 0;
            }
        }
    }
    fclose(userTable);

    return workerArray;
}

int userRepositoryDeleteWorker(int workerId) {
    int exists = userRepositoryExistsByIdAndRole(workerId, WORKER_ROLE);

    if (exists == 1) {
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

                if (workerId != dbUser.id) {
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
    return 0;
}

ClientArray userRepositoryFindAllClients() {
    ClientArray clientArray = {malloc(sizeof(Client)), 0};
	User dbUser;
    FILE * userTable;

    userTable = fopen("../tables/User.txt", "r");

    fseek(userTable, 0, SEEK_END);

    if (ftell(userTable) != 0) {
        rewind(userTable);

        while(!feof(userTable)) {
            fscanf(userTable, "%i %s %s %i\n", &dbUser.id, dbUser.username, dbUser.password, &dbUser.role);

            if (dbUser.role == CLIENT_ROLE) {
                clientArray.client = realloc(clientArray.client, sizeof(Client) * ++clientArray.length);
                clientArray.client[clientArray.length - 1].id = dbUser.id;
                strcpy(clientArray.client[clientArray.length - 1].username, dbUser.username);
                clientArray.client[clientArray.length - 1].madeRequests = 0;
            }
        }
    }
    fclose(userTable);

    return clientArray;
}