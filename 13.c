#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct student // remember this code block
{
    // define size
    int regno;
    char name[20];
};

void main()
{
    struct student stud[20], temp; // initialixing stud in square bracket remember
    FILE *fout, *fin;
    int i, n;                         // no j
                                      // file in caps
    fout = fopen("student.txt", "w"); // double inverted comma in w and (r below)
    if (fout == NULL)                 // rememberr its null
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }
    printf("enter the number of student entry:\n");
    scanf("%d", &n);
    printf("%d", n);
    printf("enter the stuents details: \n");
    i = 0;
    while (i < n)
    {
        printf("%d", i);
        printf("stuents %d details-\n", i + 1);
        printf("Name: ");
        scanf("%s", &stud[i].name); //%s will be there// REMEMBER & IN SCANF EVERYWHERE
        printf("Reg No: ");
        scanf("%d", &stud[i].regno);
        i++;
    }
    fwrite(stud, sizeof(struct student), n, fout); // forgot this , so remember
    fclose(fout);
    fin = fopen("student.txt", "r");
    // fread(&temp,stud,1,fin);not here
    if (fin == NULL) // rememberr its null
    {
        printf("file cant open :\n");
        exit(0);
    }
    printf("data read from file as follows\n");
    // for(j=0;j<n;j++)not like tis
    while (fread(&temp, sizeof(struct student), 1, fin))
    {
        printf("Name: %s\n", temp.name);
        printf("Reg No: %d \n\n", temp.regno); // no arrow here , use . instead
    }
    fclose(fin);
}