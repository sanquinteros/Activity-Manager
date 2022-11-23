int fireWorkerServiceGetWorkerId() {
    int workerId;

    printf("Enter the worker id (if you don't know the worker id enter [-1]): ");
    scanf("%i", &workerId);

    return workerId;
}

void fireWorkerServiceFireWorker() {
    int workerId = fireWorkerServiceGetWorkerId();

    if (workerId == -1) {
        printf("None workers were fired.\n");
    } else {
        int response = userRepositoryDeleteWorker(workerId);

        if (response == 1) {
            printf("Worker was successfully fired.\n");
        } else {
            printf("This worker id does not belong to any worker. None workers were fired.\n");
        }
    }
}