#include <stdio.h>
#include <string.h>

void swap(void *first, void *second, size_t numberOfBytes) {
    char temp[numberOfBytes];
    memcpy(temp,first,numberOfBytes);
    memcpy(first,second,numberOfBytes);
    memcpy(second,temp,numberOfBytes);
}

int main() {
    int first = 10;
    int second = 15;
    swap(&first,&second,sizeof(int));
    printf("first = %d, second = %d\n",first,second);

    double frst = 43.53;
    double scnd = 673.44;
    swap(&frst,&scnd, sizeof(double));
    printf("first = %.2f, second = %.2f\n",frst,scnd);
    return 0;
}
