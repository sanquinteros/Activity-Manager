typedef struct User {
    int id;
    char username[50];
    char password[50];
    int role;
} User;

User constructUserFromLogin(Login login) {
    User user;

    user.id = -1;
    strcpy(user.username, login.username);
    strcpy(user.password, login.password);
    user.role = -1;

    return user;
}

User constructUserFromRegister(int userId, Register rregister) {
    User user;

    user.id = userId;
    strcpy(user.username, rregister.username);
    strcpy(user.password, rregister.password);
    user.role = rregister.role;

    return user;
}