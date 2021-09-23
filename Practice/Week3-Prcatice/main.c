#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPasswordValid(char *password) {
    int size = strlen(password);
    bool lower = false;
    bool upper = false;
    bool special = false;
    if(size >= 8){
        for(int i = 0; i < size; i++) {
            if(password[i]  >= 'A' && password[i] <= 'Z'){
                upper = true;
            }
            if(password[i] >= 'a' && password[i] <= 'z'){
                lower = true;
            }
            if(password[i] >= 0 && password[i] <= 9){
                special = true;
            }

        }
        return special && lower && upper;
    }
    return false;
}

void mystery(char *string) {
    if(!*string) {
        return;
    }

    char *begin = string;
    while (*(string+1)) {
        string++;
    }

    while ((string+1) != begin) {
        printf("%c", *string--);
    }
}

char getFirstNonRepeatedCharacter(char *string) {
    char nonRepeatingChar;
    int stringLen = strlen(string);
    for(int i = 0; i < stringLen; i++) {
        char letter = string[i];
        for (int j = i+1; j < stringLen; j++) {
            if(letter == string[j]) {
                break;
            }
        }
    }
}

int main() {
//    char pass[20] = "Aabcyz@123";
//    int sizepass = sizeof(pass)/sizeof(pass[0]);
//    printf("%d\n",strlen(pass));
//    if(isPasswordValid(pass) == true){
//        printf("password is valid");
//    } else {
//        printf("invalid password");
//    }
//    char str[60] = "a";
//    mystery(str);
    return 0;
}
