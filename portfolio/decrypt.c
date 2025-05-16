#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// prototype decrypt function
char decrypt(char c, int key);
int main(void)
{
    char ciphertext[100];
    printf("Ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);

    // remove the new line fgets can left
    if (ciphertext[strlen(ciphertext) - 1] == '\n')
    {
        ciphertext[strlen(ciphertext) - 1] = '\0';
    }

    if (strlen(ciphertext) <= 1) // just has \n
    {
        printf("Invalid text, type at least one letter\n");
        return 1;
    }

    int key;
    printf("key: ");
    scanf("%d", &key);
    if (key < 0)
    {
        printf("The key must be a positive integer\n");
        return 1;
    }

    //now, make the decrypt loop
    for (int i = 0; i < strlen(ciphertext); i++)
    {
        printf("%c", decrypt(ciphertext[i], key));
    }
    printf("\n");
}



char decrypt(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' - key + 26) % 26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' - key + 26) % 26) + 'a';
    }
    else
    {
        return c;
    }
}