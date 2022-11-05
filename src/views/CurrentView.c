void showCurrentView(int currentView) {
    printf("You have selected a view that does not exists!\n");
    sleep(REDIRECT_TIME);
    printf("You will be redirected to the last view you were on.\n");
    sleep(REDIRECT_TIME);
    show(currentView);
}