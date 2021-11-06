#include <stdio.h>
#include <stdlib.h>

// Creating structure of type Student
struct Student
{
    // required variables
    char name[50];
    float GPA;
};

int main(int argc, char *argv[])
{
    // opening file passed as command line argument
    FILE *file = fopen(argv[1], "r");

    // creating array of type student which will store students information
    struct Student *student = (struct Student *)malloc(sizeof(struct Student) * 100000);

    // to assign values to student information at index i in student array
    int i = 0;

    // reading contents of file
    while (!feof(file))
    {
        fscanf(file, "%s", &student[i].name);
        fscanf(file, "%f", &student[i].GPA);

        // incrementing i
        i++;
    }
    // n contains number of students
    int n = i;

    // sorting student array according to their GPA in descending order
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (student[j].GPA < student[j + 1].GPA)
            {
                struct Student temp = student[j];
                student[j] = student[j + 1];
                student[j + 1] = temp;
            }
        }
    }

    // printing students having GPA greater than 3.9
    for (int i = 0; i < n; i++)
    {
        if (student[i].GPA > 3.9)
        {
            printf("%s %0.2f\n", student[i].name, student[i].GPA);
        }
    }

    // closing file
    fclose(file);

    return 0;
}