#include <stdio.h>

int max(int a,int b){
    return (a>b) ? a : b;
}

void runner(char *name, int a, int b, int(*function)(int ,int )){
    printf("%s(%d,%d) = %d\n",name,a,b,function(a,b));
}

int main() {
    printf("Hello, World!\n");
    runner("max",7,10,&max);
    return 0;
}
