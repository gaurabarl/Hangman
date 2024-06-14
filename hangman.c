#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void displayWord(char word[], char guessed[]);
int isWordGuessed(char word[], char guessed[]);
int isCharInWord(char c, char word[]);

int main() {
    char word[] = "hangman";  // The word to guess
    char guessed[] = "_______";  // The guessed word, initially all underscores
    int chances = 3;  // Num
	//ber of chances
    char guess;
    int i;

    printf("Welcome to Hangman Game!\n");

    while (chances > 0) {
        printf("\nYou have %d chance(s) left.\n", chances);
        displayWord(word, guessed);
        printf("Enter a character to guess: ");
        scanf(" %c", &guess);

        if (isCharInWord(guess, word)) {
            for (i = 0; i < strlen(word); i++) {
                if (word[i] == guess) {
                    guessed[i] = guess;
                }
            }
        } else {
            printf("Wrong guess! You lose a chance.\n");
            chances--;
        }

        if (isWordGuessed(word, guessed)) {
            printf("\nCongratulations! You've guessed the word: %s\n", word);
            break;
        }
    }

    if (chances == 0) {
        printf("\nSorry, you've run out of chances. The word was: %s\n", word);
    }

    printf("Game over. Thanks for playing!\n");
    return 0;
}

void displayWord(char word[], char guessed[]) {
    int i;
    printf("Word: ");
    for (i = 0; i < strlen(word); i++) {
        printf("%c ", guessed[i]);
    }
    printf("\n");
}

int isWordGuessed(char word[], char guessed[]) {
    return strcmp(word, guessed) == 0;
}

int isCharInWord(char c, char word[]) {
    int i;
    for (i = 0; i < strlen(word); i++) {
        if (word[i] == c) {
            return 1;
        }
    }
    return 0;
}

