#include <stdio.h>
#include <ctype.h>
#include <string.h>

char decrypt(char c, int key);
int main(void)
{
    char ciphertext[100];
    printf("Ciphertext: ");
    fgets(ciphertext, sizeof(ciphertext), stdin);
    // remove the new line fgets can left
    if (ciphertext[strlen(ciphertext) - 1] == '\n')
    {
        ciphertext[strlen(ciphertext) -1] = '\0';
    }

    for (int key = 1; key < 26; key++)
    {
        printf("Key: %d", key);
        for (int i = 0; i < strlen(ciphertext); i++)
        {
            printf("%c", decrypt(ciphertext[i], key));
        }
        printf("\n");
    }
    return 0;
}

char decrypt(char c, int key)
{
    if (isupper(c))
    {
        return ((c - 'A' - key + 26) %26) + 'A';
    }
    else if (islower(c))
    {
        return ((c - 'a' - key + 26) %26) + 'a';
    }
    else
    {
        return c;
    }
}
