#define _XOPEN_SOURCE 600  
#include <cs50.h>
#include <stdio.h>    
#include <unistd.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check to make sure arguments are correct
    if (argc != 2)
    {
        printf("Usage: crack <hash>\n");
        return 1;
    }
    
    string hash = argv[1];
    
    // use that salt = 50
    char salt[3];
    salt[0] = hash[0];
    salt[1] = hash[1];
    
    const char ASCII[53] = "\0ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    
    char password[5];
    
    for(int firstchar = 0; firstchar < 53; firstchar ++){
        password[4] = ASCII[firstchar];
        for(int secondchar = 0; secondchar < 53; secondchar ++){
            password[3] = ASCII[secondchar];
            for(int thirdchar = 0; thirdchar < 53; thirdchar ++){
                password[2] = ASCII[thirdchar];
                for(int fourthchar = 0; fourthchar < 53; fourthchar ++){
                    password[1] = ASCII[fourthchar];
                    for(int fifthchar = 1; fifthchar < 53; fifthchar ++){
                        password[0] = ASCII[fifthchar];
                        
                        if (strcmp(crypt(password, salt), hash) == 0)
                        {
                            printf("%s\n", password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Password couldn't be cracked!");

    return 2;
    
}
