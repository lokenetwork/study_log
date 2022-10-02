#include <stdio.h>
#include <stdlib.h>

typedef unsigned __int64 ULONGLONG;

typedef struct
{
    char * data;
    ULONGLONG length; 
}SECTION_HEAD;

int main(int argc, char * argv[])
{
    int md5[4];
    SECTION_HEAD section;

    printf("hello, this is a trap");

    section.data = "testing data-xxxxxxx";
    section.length = strlen(section.data);

    calc_md5(section.data, 
        section.length, md5);

    return getchar();
}