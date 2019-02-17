#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string s = get_string("String: ");
    
    // get the ascii for each character
    for (int i = 0; i < strlen(s); i++)
    {
//         int c = (int) s[i];
        // can also do it implicitly with int c = s[i]
        printf("%c %i\n", s[i], s[i]);
    }
}
