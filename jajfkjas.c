int compare(const void *a, const void *b){
    char *x = (char *)a;
    char *y = (char *)b;
    return strcmp(x,y);
}