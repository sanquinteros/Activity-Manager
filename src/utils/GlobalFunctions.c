void popInvalidViewMessage() {
    system("cls");

    printf("You have selected an invalid window.\n");
}

void scanfPassword(char * password) {
    int counter = 0;
    int character = 0;

    do {
        character = getch();

        if (character != 13 && character != 32) {
            if (character == 8) {
                if (counter != 0) {
                    counter--;
                    printf("\b \b");
                }
            } else {
                if (counter < 29) {
                    password[counter] = character;
                    printf("*");
                    counter++;
                } else {
                    password[counter] = '\0';
                    printf("\nPassword can not be longer than 29 characters.\nThe saved password is \"%s\".", password);
                    character = 13;
                }
            }
        }
    } while (character != 13);
    printf("\n");
    password[counter] = '\0';
}

char * getRoleName(int role) {
    if (role == ADMIN_ROLE) {
        return "an \"ADMINISTRATOR\"";
    } else if (role == CLIENT_ROLE) {
        return "a \"CLIENT\"";
    } else {
        return "a \"WORKER\"";
    }
}

char * getRequestStatusName(int status) {
    if (status == PENDING) {
        return "PENDING";
    } else if (status == PROCESSING) {
        return "PROCESSING";
    } else {
        return "CONCLUDED";
    }
}

int containsEncodedSpace(char string[]) {
	int i;
    for (i=0; i < strlen(string); i++) {
		if (string[i] == '&') {
			return 1;
		}
	}
	return 0;
}

char * encodeSpaces(char string[]) {
	int i;
    for (i=0; i < strlen(string); i++) {
		if (string[i] == ' ') {
			string[i]='&';
		}
	}
	return string;
}

char * decodeSpaces(char string[]) {
	int i;
	for (i=0; i < strlen(string); i++) {
		if (string[i] == '&') {
			string[i]=' ';
		}
	}
	return string;
}

void duplicateBackSlashOnString(char string[]) {
    int counterForTemp = 0;
    char temp[1000] = "";

	for (int counter = 0; counter < strlen(string) * 2; counter++) {

	    if (string[counter] == '\0') {
	        counter = strlen(string) * 2;
	    } else {

            if (string[counter] == '\\') {
                temp[counterForTemp] = '\\';
                temp[++counterForTemp] = '\\';
            } else {
                temp[counterForTemp] = string[counter];
            }
	    }
	    counterForTemp++;
	}
	strcpy(string, temp);
}