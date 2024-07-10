#include <stdlib.h>
#include <stdio.h>

void main()
{
    int a[100], a1[100], a2[100], result, n; // remember data tpye defined
    printf("enter the number of elements:\n");
    scanf("%d", &n);
    printf("enter the elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (int i = 0; i < n; i++) // have to redefine i.
    {
        result = a[i] % 10;
        a1[result] = a[i];
        a2[i] = a[i];
        printf("a1[%d] has value : %d\n", result, a1[result]);
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a2[i]);
    }
}