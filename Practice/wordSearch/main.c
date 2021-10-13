#include <stdio.h>
#include <string.h>

int search(char * str, char * wrd) {
    char * string = str;
    char * word = wrd;
    int stringLength = strlen(str);
    int wordLength = strlen(wrd);
    for (int i = 0; i < stringLength; i++) {
        if(*string == *word) {
            char * temp = string;
            int flag = 0;
            for(int j = 0; j < wordLength; j++) {
                if(*temp != *word) {
                    flag = 1;
                }
                temp++;
                word++;
            }
            word = wrd;
            if(flag == 0) {
                return i;
            }
            string++;
        }
        string++;
    }
    return -1;
}

int main() {
    printf("Hello, World!\n");
    char str[] = "Hi everyone. This is a test file that I created for assignment 2.";
    char wrd[] = "ass";
    int index = search(str,wrd);
    printf("Index is -> %d",index+1);
//    printf("\n%c%c",str[index],str[index+1]);
    return 0;
}
