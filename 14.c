#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *fout1, *fout2, *fout3, *fin1, *fin2, *fin3;
    char data1[30], data2[30], ch1, ch2, ch3; // assign size of data1,2,3   // no assigning ch1,2,3                         // no j

    fout1 = fopen("file1.txt", "w");
    fout2 = fopen("file2.txt", "w");
    if (fout1 == NULL)
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }
    if (fout2 == NULL)
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }

    printf("enter content in file1 :\n"); // from here
    gets(data1);
    printf("enter content in file2 :\n");
    gets(data2);

    fprintf(fout1, "%s", data1);
    fprintf(fout2, "%s", data2);

    fclose(fout1);
    fclose(fout2); // till here , i reffered

    fin1 = fopen("file1.txt", "r");
    fin2 = fopen("file2.txt", "r");
    fout3 = fopen("file3.txt", "w");

    if (fin1 == NULL)
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }
    if (fin2 == NULL)
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }
    if (fout3 == NULL)
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }
    // refered
    ch1 = getc(fin1); // no fgetc, its just getc
    ch2 = getc(fin2);

    while (ch1 != EOF && ch2 != EOF)
    {
        if (ch1 != ch2)
        {
            fputc(ch2, fout3); // remember
        }
        ch1 = getc(fin1);
        ch2 = getc(fin2);
    }

    fclose(fin1);
    fclose(fin2);
    fclose(fout3);

    fin3 = fopen("file3.txt", "r");
    if (fin3 == NULL) // forgot this
    {
        printf("ERROR , file cant open :\n");
        exit(0);
    }

    if ((ch3 = getc(fin3)) == 0)
    {
        printf("no difference present if file 1 and file 2\n");
        exit(0);
    }
    while (ch3 != EOF) // remember this code block
    {
        printf("%c", ch3);
        ch3 = getc(fin3);
    }

    fclose(fin3);
}
