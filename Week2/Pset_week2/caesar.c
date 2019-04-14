#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check to make sure user has input a single command-line argument
    if(argc == 2){
        // and that each character is a decimal digit
        for(int j = 0, n = strlen(argv[1]); j < n; j++){
            if(argv[1][j] > '9' || argv[1][j] < '0'){
                printf("Usage: ./caesar key");
                return 1;
            }
        }
        // convert the argument from a string to an integer
        int integer = atoi(argv[1]);
        
        // prompt the user for a string and shift all characters by 1
        string s = get_string("plaintext: ");
        
        // convert to cipher text by shifting all characters by integer
        for(int i = 0, n = strlen(s); i < n; i++){
            // characters that aren't letters remain unchanged
            if(s[i] >= 65 && s[i] <= 90){
                s[i] = (s[i] + integer);
                if(s[i] > 90){
                    s[i] = (s[i] % 90) + 64;
                }                
            } else if(s[i] >= 97 && s[i] <= 122){
                s[i] = (s[i] + integer);
                if(s[i] > 122){
                    s[i] = (s[i] % 122) + 96;
                }   
            }
        }
        
        printf("ciphertext: %s", s);
        
    } else {
        printf("Usage: ./caesar key");
    }
    printf("\n");
}
