void clientsStatisticsServiceSetRequestQuantityForEachClient(ClientArray * clientArray) {
    clientRequestRepositorySetRequestQuantityForEachClient(clientArray);
}

ClientArray clientsStatisticsServiceGetAllClients() {
    ClientArray clientArray = userRepositoryFindAllClients();
    clientsStatisticsServiceSetRequestQuantityForEachClient(&clientArray);
    return clientArray;
}

float clientsStatisticsServiceGetAverageRequestQuantity(ClientArray clientArray) {
    int madeRequests = 0;
    float averageRequestQuantity;

    for (int counter = 0; counter < clientArray.length; counter++) {
        madeRequests = madeRequests + clientArray.client[counter].madeRequests;
    }
    averageRequestQuantity = (float) madeRequests / clientArray.length;

    return averageRequestQuantity;
}

void clientsStatisticsServicePrintEachClientStatistics(ClientArray clientArray, float averageRequestQuantity) {
    for (int counter = 0; counter < clientArray.length; counter++) {
        float clientRequestQuantity = clientArray.client[counter].madeRequests / averageRequestQuantity;

        printf("The client \"%s\" (id \"%i\") has made \"%i\" requests.\n", clientArray.client[counter].username, clientArray.client[counter].id, clientArray.client[counter].madeRequests);

        if (clientRequestQuantity != 1) {
            printf("This client made %.2f times the average requests quantity.\n\n", clientRequestQuantity);
        } else {
            printf("This client made the same requests quantity as the average.\n\n");
        }
    }
}

void clientsStatisticsServicePrintClientsStatistics() {
    ClientArray clientArray = clientsStatisticsServiceGetAllClients();
    float averageRequestQuantity = clientsStatisticsServiceGetAverageRequestQuantity(clientArray);

    printf("Number of registered clients: %i.\n", clientArray.length);
    printf("The average requests made per client is of %.2f requests.\n\n", averageRequestQuantity);

    clientsStatisticsServicePrintEachClientStatistics(clientArray, averageRequestQuantity);

    free(clientArray.client);
}