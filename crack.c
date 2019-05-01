//Adamou Moutari Souwaiba
// logical operators

#define _XOPEN_SOURCE
#include <stdio.h>
#include <string.h>
#include <crypt.h>

#define SALT "50"

int main(int argc, char **argv)
{
if (argc == 2)
{
    char *hash = argv[1];

    char alphabet[53] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Creating a password "template". We know the passwords are max 5 characters.

    char passwd[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};

// Loop the iterations "inside-out".

for(int car1 = 0; car1 < 52; car1++) //  character1
    {
    for(int car2= 0; car2 < 52; car2++) //  character2
        {
        for(int car3= 0; car3 < 52;car3++) // character3
            {
            for(int car4= 0; car4< 52; car4++) // character4
                {
                for(int car5= 0; car5 < 52; car5++) //  character5
                    {
                        passwd[0] = alphabet[52];  // First character loop

                        // Compare the hash
                        char *passwdCrypt = crypt(passwd, SALT);
                        if(strcmp(hash, passwdCrypt) == 0)
                        {
                            printf("cracked password is: %s\n", passwd);
                            return 0;
                        }
                    }
                    passwd[1] = alphabet[car4];  // Second character loop
                }
                passwd[2] = alphabet[car3];  // Third character loop
            }
            passwd[3] = alphabet[car2];  // Fourth character loop
        }
        passwd[4] = alphabet[car1];  // Fifth character loop
    }
}
else
{
    printf("Go back after ./crack put your hash here\n");
    return 1;
}
}
