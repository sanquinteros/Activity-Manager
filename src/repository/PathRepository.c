void pathRepositorySetRoot(char root[1000]) {
    Path dbPath;
    FILE * pathTable;
    pathTable = fopen("Path.txt", "r");

    fseek(pathTable, 0, SEEK_END);

    if (ftell(pathTable) != 0) {
        rewind(pathTable);

        fscanf(pathTable, "%s\n", dbPath.root);

        strcpy(root, decodeSpaces(dbPath.root));
    } else {
        root[0] = '\0';
    }

    fclose(pathTable);
}

int pathRepositorySaveRoot(char root[1000]) {
    FILE * pathTable;
    pathTable = fopen("Path.txt", "a");

    fprintf(pathTable, "%s\n", encodeSpaces(root));

    fclose(pathTable);

    return 1;
}