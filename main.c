
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 24

char* getCharset() {
    static char allChars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
    return allChars;
}

char* generatePassword(int length, char* charset) {
    char* password = malloc((length + 1) * sizeof(char));
    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(charset);
        char randomChar = charset[index];
        password[i] = randomChar;
    }
    password[length] = '\0';

    return password;
}

int main() {
    char* charset = getCharset();
    char* password = generatePassword(PASSWORD_LENGTH, charset);

    printf("Your strong password is:\n%s\n", password);

    free(password);

    return 0;
}


