#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

void TOH(int n, char A, char B, char C) // A is from, B is using , C is to
{
    if (n > 0)
    {
        TOH(n - 1, A, C, B);
        printf("move disk %d from %c to %c\n", n, A, C);
        TOH(n - 1, B, A, C);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    char a, b, c;
    // TOH(n,a,b,c);       //wont print properly
    TOH(n, 'a', 'b', 'c'); // print properly
    return 0;
}