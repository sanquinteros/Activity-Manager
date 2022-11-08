void showCurrentView(int currentView) {
    system("cls");

    printf("You have selected an invalid view.\n");
    sleep(REDIRECT_TIME);
    printf("You will be redirected to the last view you were on.\n");
    sleep(REDIRECT_TIME);
    show(currentView);
}