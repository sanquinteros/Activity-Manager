void popInvalidViewMessage() {
    system("cls");

    printf("You have selected an invalid view.\n");
}

char * getRoleName(int role) {
    if (role == ADMIN_ROLE) {
        return "ADMINISTRATOR";
    } else if (role == CLIENT_ROLE) {
        return "CLIENT";
    } else {
        return "WORKER";
    }
}

char * getRequestStatusName(int status) {
    if (status == PENDING) {
        return "PENDING";
    } else if (status == PROCESSING) {
        return "PROCESSING";
    } else {
        return "DONE";
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