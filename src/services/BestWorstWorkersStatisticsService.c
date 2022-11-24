void bestWorstWorkersStatisticsServiceSetConcludedRequestsForEachClient(WorkerArray * workerArray) {
    clientRequestRepositorySetConcludedRequestsForEachWorker(workerArray);
}

WorkerArray bestWorstWorkersStatisticsServiceGetAllWorkers() {
    WorkerArray workerArray = userRepositoryFindAllWorkers();
    bestWorstWorkersStatisticsServiceSetConcludedRequestsForEachClient(&workerArray);
    return workerArray;
}

void bestWorstWorkersStatisticsServiceSortArray(WorkerArray workerArray) {
    Worker temp = {0, "0", 0};

    for (int outer = 0; outer < workerArray.length; outer++) {
        for (int inner = 1; inner < (workerArray.length - outer); inner++) {
            if (workerArray.worker[inner - 1].concludedRequests > workerArray.worker[inner].concludedRequests){
                temp = workerArray.worker[inner - 1];
                workerArray.worker[inner - 1] = workerArray.worker[inner];
                workerArray.worker[inner] = temp;
            }
        }
    }
}

WorkerArray bestWorstWorkersStatisticsServiceGetBestWorkers(WorkerArray workerArray) {
    WorkerArray bestWorkerArray = { malloc(sizeof(Worker)), 0};
    int counter = workerArray.length - 1;

    while (counter >= 0) {
        bestWorkerArray.worker = realloc(bestWorkerArray.worker, sizeof(Worker) * ++bestWorkerArray.length);
        bestWorkerArray.worker[bestWorkerArray.length - 1].id = workerArray.worker[counter].id;
        strcpy(bestWorkerArray.worker[bestWorkerArray.length - 1].username, workerArray.worker[counter].username);
        bestWorkerArray.worker[bestWorkerArray.length - 1].concludedRequests = workerArray.worker[counter].concludedRequests;

        if (workerArray.worker[counter].concludedRequests == workerArray.worker[counter - 1].concludedRequests) {
            counter--;
        } else {
            counter = -1;
        }
    }
    return bestWorkerArray;
}

WorkerArray bestWorstWorkersStatisticsServiceGetWorstWorkers(WorkerArray sortedWorkerArray) {
    WorkerArray worstWorkerArray = { malloc(sizeof(Worker)), 0};
    int counter = 0;

    while (counter < sortedWorkerArray.length) {
        worstWorkerArray.worker = realloc(worstWorkerArray.worker, sizeof(Worker) * ++worstWorkerArray.length);
        worstWorkerArray.worker[worstWorkerArray.length - 1].id = sortedWorkerArray.worker[counter].id;
        strcpy(worstWorkerArray.worker[worstWorkerArray.length - 1].username, sortedWorkerArray.worker[counter].username);
        worstWorkerArray.worker[worstWorkerArray.length - 1].concludedRequests = sortedWorkerArray.worker[counter].concludedRequests;

        if (sortedWorkerArray.worker[counter].concludedRequests == sortedWorkerArray.worker[counter + 1].concludedRequests) {
            counter++;
        } else {
            counter = sortedWorkerArray.length;
        }
    }
    return worstWorkerArray;
}

float bestWorstWorkersStatisticsServiceGetPopulationWorkingEfficiency(WorkerArray workerArray) {
    float averageWorkingEfficiency = 0;

    if (workerArray.length != 0) {
        int concludedRequests = 0;

        for (int counter = 0; counter < workerArray.length; counter++) {
            concludedRequests = concludedRequests + workerArray.worker[counter].concludedRequests;
        }
        averageWorkingEfficiency = (float) concludedRequests / workerArray.length;
    }
    return averageWorkingEfficiency;
}

void bestWorstWorkersStatisticsServicePrintfBestWorkers(WorkerArray workerArray, float averageWorkingEfficiency) {
    printf("Currently there are %i best workers, they have the same best working efficiency.\n", workerArray.length);

    for(int counter = 0; counter < workerArray.length; counter++) {
        float workerWorkingEfficiency = workerArray.worker[counter].concludedRequests / averageWorkingEfficiency;

        printf("The worker \"%s\" (id \"%i\") concluded \"%i\" requests.\n", workerArray.worker[counter].username, workerArray.worker[counter].id, workerArray.worker[counter].concludedRequests);
        printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEfficiency);
    }
}

void bestWorstWorkersStatisticsServicePrintfBestWorker(Worker worker, float averageWorkingEfficiency) {
    float workerWorkingEfficiency = worker.concludedRequests / averageWorkingEfficiency;

    printf("The best worker, with \"%i\" concluded requests, is \"%s\" (id \"%i\").\n", worker.concludedRequests, worker.username, worker.id);
    printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEfficiency);
}

void bestWorstWorkersStatisticsServicePrintfWorstWorkers(WorkerArray workerArray, float averageWorkingEfficiency) {
    printf("Currently there are %i worst workers, they have the same worst working efficiency.\n", workerArray.length);

    for(int counter = 0; counter < workerArray.length; counter++) {
        float workerWorkingEfficiency = workerArray.worker[counter].concludedRequests / averageWorkingEfficiency;

        printf("The worker \"%s\" (id \"%i\") concluded \"%i\" requests.\n", workerArray.worker[counter].username, workerArray.worker[counter].id, workerArray.worker[counter].concludedRequests);
        printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEfficiency);
    }
}

void bestWorstWorkersStatisticsServicePrintfWorstWorker(Worker worker, float averageWorkingEfficiency) {
    float workerWorkingEfficiency = worker.concludedRequests / averageWorkingEfficiency;

    printf("The worst worker, with \"%i\" concluded requests, is \"%s\" (id \"%i\").\n", worker.concludedRequests, worker.username, worker.id);
    printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEfficiency);
}

void bestWorstWorkersStatisticsServicePrintBestAndWorstWorkers() {
    WorkerArray workerArray = bestWorstWorkersStatisticsServiceGetAllWorkers();
    bestWorstWorkersStatisticsServiceSortArray(workerArray);
    WorkerArray bestWorkerArray = bestWorstWorkersStatisticsServiceGetBestWorkers(workerArray);
    float averageWorkingEfficiency = bestWorstWorkersStatisticsServiceGetPopulationWorkingEfficiency(workerArray);

    printf("The average working efficiency is of %.2f requests concluded.\n\n", averageWorkingEfficiency);

    if (workerArray.length == bestWorkerArray.length) {
        printf("All workers have the same working efficiency!\n\n");
    } else {
        WorkerArray worstWorkerArray = bestWorstWorkersStatisticsServiceGetWorstWorkers(workerArray);

        if (bestWorkerArray.length > 1) {
            bestWorstWorkersStatisticsServicePrintfBestWorkers(bestWorkerArray, averageWorkingEfficiency);
        } else {
            bestWorstWorkersStatisticsServicePrintfBestWorker(bestWorkerArray.worker[0], averageWorkingEfficiency);
        }

        if (worstWorkerArray.length > 1) {
            bestWorstWorkersStatisticsServicePrintfWorstWorkers(worstWorkerArray, averageWorkingEfficiency);
        } else {
            bestWorstWorkersStatisticsServicePrintfWorstWorker(worstWorkerArray.worker[0], averageWorkingEfficiency);
        }
    	free(worstWorkerArray.worker);
    }
    free(workerArray.worker);
    free(bestWorkerArray.worker);
}