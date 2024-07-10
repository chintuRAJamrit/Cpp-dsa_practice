#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[100], a1[100], cnt = 0, n, i, j, result; // remember
    printf("enter the number of elements:\n");
    scanf("%d", &n);
    printf("enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < 10; i++)
        a1[i] = -1;
    for (i = 0; i < n; i++) // this is a long loop
    {
        result = a[i] % 10;

        if (a1[result] == -1) // inside square bracket result to be there
        {
            a1[result] = a[i];                                       // forgot this
            printf("a1[%d] has element : %d\n", result, a1[result]); // use a1 for printing values too
        }
        else
        {
            j = result + 1; // forgot the place to put this
            while (1)
            {
                if (a1[j] == -1)
                {
                    a1[j] = a[i]; // a1[j] i forgot
                    printf("a1[%d] has element : %d\n", j, a1[j]);
                    break;
                }
                if (j > n - 1) // remember to shift it again to 0 if it ends using lesser than sign
                    j = 0;
                if (cnt == n)
                    break;
                cnt++;
                j++;
            }
        }
        result = 0; // forgot this
    }
    printf("hash tabl using open addressing mode\n");
    for (j = 0; j < 10; j++)
    { // use i or j doesnt matter
        if (a1[j] != -1)
            printf("%d ", a1[j]);
    }
}