#include <stdio.h>
#include <string.h>

void createAndWrite(char * str, char * fileName) {
    FILE * file = fopen(fileName,"w");
    if(file == NULL){
        printf("Could not open the file!");
    }
    fputs(str,file);
    printf("Written to file!");
    fclose(file);
}

void readExistingFile(char * fileName) {
    FILE * file = fopen(fileName,"r");
    if(file == NULL) {
        printf("Could not opent");
    }
    char line[100];
    while(fgets(line,100,file)!=NULL){
        printf("%s",line);
    }
}

void readAndStoreInArray(char * fileName, char arr[100][100]) {
    FILE * file = fopen(fileName,"w");
    if(file == NULL) printf("Could not opened");
    int line = 0;
    while(fgets(arr[line],100,file)!=NULL) {
        arr[line][strlen(arr[line])-1] = '\0';
        line++;
    }
    for(int i = 0; i < line; i++){
        printf("%s",arr[i]);
    }
    fclose(file);
}

void getNumberOfLine(char * fileName) {
    FILE * file = fopen(fileName,"r");
    if(file == NULL) printf("Could not open the file");
    int line = 0;
    char str[100];
    while (fgets(str,100,file)!=NULL){
        line++;
    }
    printf("%d lines",line);
    fclose(file);
}

void NumberOfWordsAndChars(char * filename){
    FILE * file = fopen(filename, "r");
    int word = 1,charecters = 1;
    if(file == NULL) printf("Could not open the file");
    char ch = fgetc(file);
    while(ch!=EOF){

        if(ch==' '||ch=='\n'){
            word++;
        } else {
            charecters++;
        }
        ch= fgetc(file);
    }
    printf("words -> %d, char -> %d",word,charecters);
}

void appendToAFile(char * fileName, char * str) {
    FILE * file = fopen(fileName,"a");
    if(file == NULL) printf("could not open file");
    fputc('\n',file);
    while (*str != '\0'){
        fputc(*str,file);
        str++;
    }
}

int main() {

//    char * str = "Hello this is new file\nLets gooo!";
//    createAndWrite(str,"q1.txt");

//    readExistingFile("q1.txt");
//    char arr[100][100];
//    readAndStoreInArray("q1.txt",arr);

//    getNumberOfLine("q1.txt");

//    NumberOfWordsAndChars("q1.txt");

    char str[] = "Yo wtf is up\n bruh LOLLL XD";
    appendToAFile("q1.txt",str);

    return 0;
}
