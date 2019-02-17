#include <cs50.h>
#include <stdio.h>

// capitalized variable means it's global
const int NUM_SCORES = 3;

void chart(int count, int scores[]);

int main(void)
{
    int scores[NUM_SCORES];
    
    for (int i = 0; i < NUM_SCORES; i++)
    {
        scores[i] = get_int("Score %i: ", i + 1);
    }
    
    chart(NUM_SCORES, scores);
    
}

// bar chart
void chart(int count, int scores[])
{
    for (int i = 0; i < count; i++)
    {
        printf("Score %i: ", i + 1);
        for (int j = 0; j < scores[i]; j++)
        {
            printf("#");
        }
    printf("\n");
        
    }
}

