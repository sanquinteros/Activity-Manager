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

float workersStatisticsServiceGetWorkingWorkersPercentages(int totalWorkers, int workingWorkers) {
    float workingWorkersPercentage = 0;

    if (totalWorkers != 0) {
        workingWorkersPercentage = (workingWorkers * 100.) / totalWorkers;
    }
    return workingWorkersPercentage;
}

float workersStatisticsServiceGetWaitingWorkersPercentages(int totalWorkers, int workingWorkers) {
    float waitingWorkersPercentage = 0;

    if (totalWorkers != 0) {
        waitingWorkersPercentage = ((totalWorkers - workingWorkers) * 100.) / totalWorkers;
    }

    return waitingWorkersPercentage;
}

void workersStatisticsServicePrintEachWorkerStatistics(WorkerArray workerArray, float averageWorkingEfficiency) {
    for (int counter = 0; counter < workerArray.length; counter++) {
        float workerWorkingEfficiency = 0;

        if (averageWorkingEfficiency != 0) {
            workerWorkingEfficiency = workerArray.worker[counter].concludedRequests / averageWorkingEfficiency;
        }
        printf("The worker \"%s\" (id \"%i\") concluded \"%i\" requests.\n", workerArray.worker[counter].username, workerArray.worker[counter].id, workerArray.worker[counter].concludedRequests);

        if (workerWorkingEfficiency != 1) {
            printf("This worker working efficiency is %.2f times the average.\n\n", workerWorkingEfficiency);
        } else {
            printf("This worker working efficiency is the same as the average.\n\n");
        }
    }
}

void workersStatisticsServicePrintWorkersStatistics() {
    WorkerArray workerArray = workersStatisticsServiceGetAllWorkers();
    int workingWorkers = workersStatisticsServiceGetWorkingWorkers();
    float averageWorkingEfficiency = workersStatisticsServiceGetAverageWorkingEfficiency(workerArray);
    float percentageStatusList[] = {
        workersStatisticsServiceGetWorkingWorkersPercentages(workerArray.length, workingWorkers),
        workersStatisticsServiceGetWaitingWorkersPercentages(workerArray.length, workingWorkers)
    };

    printf("Number of registered workers: %i.\n", workerArray.length);
    printf("%i (%.2f%c) are currently working on some request.\n", workingWorkers, percentageStatusList[0], '%');
    printf("%i (%.2f%c) are not.\n", workerArray.length - workingWorkers, percentageStatusList[1], '%');
    printf("The average working efficiency is of %.2f requests concluded.\n\n", averageWorkingEfficiency);

    workersStatisticsServicePrintEachWorkerStatistics(workerArray, averageWorkingEfficiency);

    free(workerArray.worker);
}