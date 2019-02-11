#include <cs50.h>
#include <stdio.h>

int get_positive_int(string prompt);

int main(void)
{
    int i = get_positive_int("Integer: ");
    printf("%i\n", i);
}

int get_positive_int(string prompt)
{
    /* declare here because we need to know n outside of the do loop */
    int n;
    do
    {
        n = get_int("%s",prompt);
    }
    while (n < 1);
    return n;
    
}
