#include <cs50.h>
#include <stdio.h>

int get_one_eight(void);
void print_spaces(int num_spaces);
void print_hash(int num_hash);

int main(void)
{
    int height = get_one_eight();
    
    for(int row = 1; row <= height; row++)
    {   
        int num_space = height - row - 1;
        // could concatenate strings instead of printing through a loop
        print_spaces(num_space);
        print_hash(row);
        printf("  ");
        print_hash(row);
        printf("\n");
    }
}

int get_one_eight(void)
{
    int num;
    do
    {
        num = get_int("Height: ");  
    }
    while (num < 1 || num > 8);
    
    return num;
}

void print_spaces(int num_spaces)
{
    for(int space = 0; space <= num_spaces + 1; space++)
        {
            printf(" ");
        }
}

void print_hash(int num_hash)
{
    for(int hash = 1; hash <= num_hash; hash++)
        {
            printf("#");
        }
}
