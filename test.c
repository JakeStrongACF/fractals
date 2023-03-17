#include  "FPToolkit.c"

int compute(int n)
{
    if(n == 0)
        return 1;

    return compute(n-1)*2;
}

int main()
{
    int n;

    printf("Type an n \n");

    scanf("%d", &n);

    printf("%d", compute(n));
}