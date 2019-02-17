#include <cs50.h>
#include <stdio.h>

// automatically returns 0
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("missing command-line argument\n");
        return 1;
    }
    printf("hello, %s\n", argv[1]);
}
