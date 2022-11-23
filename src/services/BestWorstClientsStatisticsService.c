void bestWorstClientsStatisticsServiceSetRequestQuantityForEachClient(ClientArray * clientArray) {
    clientRequestRepositorySetRequestQuantityForEachClient(clientArray);
}

ClientArray bestWorstClientsStatisticsServiceGetAllClients() {
    ClientArray clientArray = userRepositoryFindAllClients();
    bestWorstClientsStatisticsServiceSetRequestQuantityForEachClient(&clientArray);
    return clientArray;
}

void bestWorstClientsStatisticsServiceSortArray(ClientArray clientArray) {
    Client temp = {0, "0", 0};

    for (int outer = 0; outer < clientArray.length; outer++) {
        for (int inner = 1; inner < (clientArray.length - outer); inner++) {
            if (clientArray.client[inner - 1].madeRequests > clientArray.client[inner].madeRequests){
                temp = clientArray.client[inner - 1];
                clientArray.client[inner - 1] = clientArray.client[inner];
                clientArray.client[inner] = temp;
            }
        }
    }
}

ClientArray bestWorstClientsStatisticsServiceGetBestClients(ClientArray clientArray) {
    ClientArray bestClientArray = { malloc(sizeof(Client)), 0};
    int counter = clientArray.length - 1;

    while (counter >= 0) {
        bestClientArray.client = realloc(bestClientArray.client, sizeof(Client) * ++bestClientArray.length);
        bestClientArray.client[bestClientArray.length - 1].id = clientArray.client[counter].id;
        strcpy(bestClientArray.client[bestClientArray.length - 1].username, clientArray.client[counter].username);
        bestClientArray.client[bestClientArray.length - 1].madeRequests = clientArray.client[counter].madeRequests;

        if (clientArray.client[counter].madeRequests == clientArray.client[counter - 1].madeRequests) {
            counter--;
        } else {
            counter = -1;
        }
    }
    return bestClientArray;
}

ClientArray bestWorstClientsStatisticsServiceGetWorstClients(ClientArray sortedClientArray) {
    ClientArray worstClientArray = { malloc(sizeof(Client)), 0};
    int counter = 0;

    while (counter < sortedClientArray.length) {
        worstClientArray.client = realloc(worstClientArray.client, sizeof(Client) * ++worstClientArray.length);
        worstClientArray.client[worstClientArray.length - 1].id = sortedClientArray.client[counter].id;
        strcpy(worstClientArray.client[worstClientArray.length - 1].username, sortedClientArray.client[counter].username);
        worstClientArray.client[worstClientArray.length - 1].madeRequests = sortedClientArray.client[counter].madeRequests;

        if (sortedClientArray.client[counter].madeRequests == sortedClientArray.client[counter + 1].madeRequests) {
            counter++;
        } else {
            counter = sortedClientArray.length;
        }
    }
    return worstClientArray;
}

float bestWorstClientsStatisticsServiceGetAverageRequestQuantity(ClientArray clientArray) {
    int madeRequests = 0;
    float averageRequestQuantity;

    for (int counter = 0; counter < clientArray.length; counter++) {
        madeRequests = madeRequests + clientArray.client[counter].madeRequests;
    }
    averageRequestQuantity = (float) madeRequests / clientArray.length;

    return averageRequestQuantity;
}

void bestWorstClientsStatisticsServicePrintfBestClients(ClientArray clientArray, float averageRequestQuantity) {
    printf("Currently there are %i best clients, they have the less quantity of requests made.\n", clientArray.length);

    for(int counter = 0; counter < clientArray.length; counter++) {
        float clientRequestQuantity = clientArray.client[counter].madeRequests / averageRequestQuantity;

        printf("The client \"%s\" (id \"%i\") has made \"%i\" requests.\n", clientArray.client[counter].username, clientArray.client[counter].id, clientArray.client[counter].madeRequests);
        printf("This client made %.2f times the average requests quantity.\n\n", clientRequestQuantity);
    }
}

void bestWorstClientsStatisticsServicePrintfBestClient(Client client, float averageRequestQuantity) {
    float clientRequestQuantity = client.madeRequests / averageRequestQuantity;

    printf("The best client, with \"%i\" requests made, is \"%s\" (id \"%i\")\n", client.madeRequests, client.username, client.id);
    printf("This client has %.2f times the average requests quantity.\n\n", clientRequestQuantity);
}

void bestWorstClientsStatisticsServicePrintfWorstClients(ClientArray clientArray, float averageRequestQuantity) {
    printf("Currently there are %i worst clients, they have the less quantity of requests made.\n", clientArray.length);

    for(int counter = 0; counter < clientArray.length; counter++) {
        float clientRequestQuantity = clientArray.client[counter].madeRequests / averageRequestQuantity;

        printf("The client \"%s\" (id \"%i\") has made \"%i\" requests.\n", clientArray.client[counter].username, clientArray.client[counter].id, clientArray.client[counter].madeRequests);
        printf("This client made %.2f times the average requests quantity.\n\n", clientRequestQuantity);
    }
}

void bestWorstClientsStatisticsServicePrintfWorstClient(Client client, float averageRequestQuantity) {
    float clientRequestQuantity = client.madeRequests / averageRequestQuantity;

    printf("The worst client, with \"%i\" requests made, is \"%s\" (id \"%i\")\n", client.madeRequests, client.username, client.id);
    printf("This client has %.2f times the average requests quantity.\n\n", clientRequestQuantity);
}

void bestWorstClientsStatisticsServicePrintBestAndWorstClients() {
    ClientArray clientArray = bestWorstClientsStatisticsServiceGetAllClients();
    bestWorstClientsStatisticsServiceSortArray(clientArray);
    ClientArray bestClientArray = bestWorstClientsStatisticsServiceGetBestClients(clientArray);
    float averageRequestQuantity = bestWorstClientsStatisticsServiceGetAverageRequestQuantity(clientArray);

    printf("The average requests made per client is of %.2f requests.\n\n", averageRequestQuantity);

    if (clientArray.length == bestClientArray.length) {
        printf("All clients have the same quantity of requests made!\n\n");
    } else {
        ClientArray worstClientArray = bestWorstClientsStatisticsServiceGetWorstClients(clientArray);

        if (bestClientArray.length > 1) {
            bestWorstClientsStatisticsServicePrintfBestClients(bestClientArray, averageRequestQuantity);
        } else {
            bestWorstClientsStatisticsServicePrintfBestClient(bestClientArray.client[0], averageRequestQuantity);
        }

        if (worstClientArray.length > 1) {
            bestWorstClientsStatisticsServicePrintfWorstClients(worstClientArray, averageRequestQuantity);
        } else {
            bestWorstClientsStatisticsServicePrintfWorstClient(worstClientArray.client[0], averageRequestQuantity);
        }
        
    	free(worstClientArray.client);
    }
    free(clientArray.client);
    free(bestClientArray.client);
}