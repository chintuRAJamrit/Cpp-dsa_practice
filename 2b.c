#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    int a[20];
    int i, k, j, n;
    printf("Enter total elemeents for array a\n");
    scanf("%d", &n);
    printf("enter elemeents in array a\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    for (i = 1; i < n; i++)
    {
        k = a[i];
        for (j = i - 1; j >= 0 && k < a[j]; j--) // here it will be a[j]
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = k;
    }
    printf("after sorting\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", a[i]);
    }
}