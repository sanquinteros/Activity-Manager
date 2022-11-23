void workersStatisticsServiceSetConcludedRequestsForEachClient(WorkerArray * workerArray) {
    clientRequestRepositorySetConcludedRequestsForEachWorker(workerArray);
}

WorkerArray workersStatisticsServiceGetAllWorkers() {
    WorkerArray workerArray = userRepositoryFindAllWorkers();
    workersStatisticsServiceSetConcludedRequestsForEachClient(&workerArray);
    return workerArray;
}

int workersStatisticsServiceGetWorkingWorkers() {
    return clientRequestRepositoryGetWorkingWorkers();
}

float workersStatisticsServiceGetAverageWorkingEfficiency(WorkerArray workerArray) {
    int concludedRequests = 0;
    float averageWorkingEfficiency;

    for (int counter = 0; counter < workerArray.length; counter++) {
        concludedRequests = concludedRequests + workerArray.worker[counter].concludedRequests;
    }
    averageWorkingEfficiency = (float) concludedRequests / workerArray.length;

    return averageWorkingEfficiency;
}

void workersStatisticsServicePrintEachWorkerStatistics(WorkerArray workerArray, float averageWorkingEfficiency) {
    for (int counter = 0; counter < workerArray.length; counter++) {
        float workerWorkingEffciency = workerArray.worker[counter].concludedRequests / averageWorkingEfficiency;

        printf("The worker \"%s\" (id \"%i\") has worked on \"%i\" requests.\n", workerArray.worker[counter].username, workerArray.worker[counter].id, workerArray.worker[counter].concludedRequests);

        if (workerWorkingEffciency != 1) {
            printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEffciency);
        } else {
            printf("This worker working efficiency is the same as the average.\n\n");
        }
    }
}

void workersStatisticsServicePrintWorkersStatistics() {
    WorkerArray workerArray = workersStatisticsServiceGetAllWorkers();
    int workingWorkers = workersStatisticsServiceGetWorkingWorkers();
    int waitingWorkers = workerArray.length - workingWorkers;
    float averageWorkingEfficiency = workersStatisticsServiceGetAverageWorkingEfficiency(workerArray);

    printf("Number of registered workers: %i.\n", workerArray.length);
    printf("%i (%.2f%c) are currently working on some request.\n", workingWorkers, (workingWorkers * 100.) / workerArray.length, '%');
    printf("%i (%.2f%c) are not.\n", waitingWorkers, (waitingWorkers * 100.) / workerArray.length, '%');
    printf("The average working efficiency is of %.2f requests concluded.\n\n", averageWorkingEfficiency);

    workersStatisticsServicePrintEachWorkerStatistics(workerArray, averageWorkingEfficiency);

    free(workerArray.worker);
}