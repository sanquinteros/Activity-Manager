void showErrorView(int view) {
    printf("A custom exception has occurred:\nThe software tried to navigate to the window \"%i\", this window does not exist.", view);
    exit(0);
}
