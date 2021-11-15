#include <stdio.h>
#include <stdbool.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

struct date{
    int day;
    int month;
    int year;
};

bool isFirstDateAfterSecond(struct date firstDate, struct date secondDate) {
    if(secondDate.year>firstDate.year) return false;
    if(secondDate.year<firstDate.year) return true;
    if(secondDate.month>firstDate.month) return false;
    if(secondDate.month<firstDate.month) return true;
    return firstDate.day>secondDate.day;
}

void printDateDiff(struct date firstDate, struct date secondDate) {
    if(!isFirstDateAfterSecond(firstDate,secondDate)){
        return printDateDiff(secondDate,firstDate);
    }
    struct date diff;
    diff.year = firstDate.year - secondDate.year;
    diff.month = firstDate.month - secondDate.month;
    diff.day = firstDate.day - secondDate.day;
    if(diff.day < 0) {
        diff.day += 30;
        diff.month--;
    }
    if(diff.month < 0) {
        diff.month += 12;
        diff.year--;
    }
    printf("Diff = %d years, %d months and %d days\n",diff.year,diff.month,diff.day);
}

int main() {
//    struct date date1 = {12,9,2003};
//    struct date date2 = {24,8,2001};
//    printDateDiff(date2,date1);\

    int x = 5;
    int y = 10;
    printf("max = %d\n",max(++x,--y));
    printf("x = %d, y = %d",x,y);

    return 0;
}
