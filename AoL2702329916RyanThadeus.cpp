//Nama: Ryan Thadeus
//NIM: 2702329916
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define constants for the size of the alphabet and the maximum length of slang and description
#define ALPHABET_SIZE 26
#define MAX_SLANG_LENGTH 100
#define MAX_DESC_LENGTH 1000

// Define a struct for a TrieNode
typedef struct TrieNode {
    // Array of child nodes, each representing a letter of the alphabet
    struct TrieNode *children[ALPHABET_SIZE];
    // Description of the slang word
    char desc[MAX_DESC_LENGTH];
    // Flag to indicate if the node represents the end of a slang word
    bool isEnd;
} TrieNode;

// Function to create a new TrieNode
TrieNode* createNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    newNode->isEnd = false;
    // Initialize all child nodes to NULL
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Function to insert a slang word into the Trie
void insertData(TrieNode *root, const char *slang, char desc[]) {
    TrieNode *curr = root;
    // Iterate through each character in the slang word
    for (int i = 0; i < strlen(slang); i++) {
        int idx = slang[i] - 'a';
        // If the child node for this character does not exist, create it
        if (!curr->children[idx]) {
            curr->children[idx] = createNode();
        }
        // Move to the child node
        curr = curr->children[idx];
    }
    // Store the description of the slang word at the end node
    strcpy(curr->desc, desc);
    curr->isEnd = true;
}

// Function to search for a slang word in the Trie
TrieNode* searchData(TrieNode *root, const char *slang) {
    TrieNode *curr = root;
    // Iterate through each character in the slang word
    for (int i = 0; i < strlen(slang); i++) {
        int idx = slang[i] - 'a';
        // If the child node for this character does not exist, return NULL
        if (!curr->children[idx]) {
            return NULL;
        }
        // Move to the child node
        curr = curr->children[idx];
    }
    // Return the end node if the slang word is found
    return curr;
}

// Function to print all slang words in the Trie
void printAllSlangWords(TrieNode *root, char *prefix) {
    if (root == NULL) {
        return;
    }

    if (root->isEnd) {
        printf("Slang word : %s\n", prefix);
        printf("Description : %s\n", root->desc);
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            char newPrefix[MAX_SLANG_LENGTH];
            strcpy(newPrefix, prefix);
            newPrefix[strlen(prefix)] = i + 'a';
            newPrefix[strlen(prefix) + 1] = '\0';
            printAllSlangWords(root->children[i], newPrefix);
        }
    }
}

// Function to print slang words with a given prefix
void printSlangWordsWithPrefix(TrieNode *root, const char *prefix) {
    TrieNode *curr = root;
    // Iterate through each character in the prefix
    for (int i = 0; i < strlen(prefix); i++) {
        int idx = prefix[i] - 'a';
        // If the child node for this character does not exist, print a message
        if (!curr->children[idx]) {
            printf("There is no prefix \"%s\" in the dictionary.\n", prefix);
            return;
        }
        // Move to the child node
        curr = curr->children[idx];
    }
    // Print slang words starting with the given prefix
    printf("Words starts with \"%s\": \n", prefix);
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (curr->children[i]) {
            char word[MAX_SLANG_LENGTH];
            strcpy(word, prefix);
            word[strlen(prefix)] = i + 'a';
            word[strlen(prefix) + 1] = '\0';
            printAllSlangWords(curr->children[i], word);
        }
    }
}

// Function to clear the screen
void clearScreen() {
    for (int i = 0; i < 30; i++) {
        puts("");
    }
}

int main() {
    TrieNode *root = createNode();

    int choice;
    char slang[MAX_SLANG_LENGTH], desc[MAX_DESC_LENGTH], search[MAX_SLANG_LENGTH], prefix[MAX_SLANG_LENGTH];
    TrieNode *searchResult;

    do {
        clearScreen();
        puts("Hi This is Boogle.\n");
        puts("May I help you?");
        puts("1. Release a new slang word");
        puts("2. Search a slang word");
        puts("3. View all slang words starting with a certain prefix word");
        puts("4. View all slang words");
        puts("5. Exit\n");

        do {
            printf("Your choice: ");
            scanf("%d", &choice);
            getchar();
        } while (choice < 1 || choice > 5);

        switch(choice) {
            case 1:
                do {
                    printf("Enter a new slang word [Must be more than 1 characters and contains no space]: ");
                    scanf("%[^\n]", slang);
                    getchar();
                } while(strlen(slang) < 2 || strchr(slang, ' ') != NULL);

                do {
                    printf("Enter the description of the slang word [Must be more than 2 words]: ");
                    scanf("%[^\n]", desc);
                    getchar();
                } while(strchr(desc, ' ') == NULL || strlen(desc) < 3);

                searchResult = searchData(root, slang);
                if (searchResult) {
                    printf("Updated a slang word.\n");
                } else {
                    printf("Successfully released new slang word.\n");
                }
                insertData(root, slang, desc);
                break;

            case 2:
                do {
                    printf("Enter a slang word to be searched [Must be more than 1 characters and contains no space]: ");
                    scanf("%s", search);
                    getchar();
                } while(strlen(search) < 2 || strchr(search, ' ') != NULL);

                searchResult = searchData(root, search);
                if (!searchResult) {
                    printf("There is no word \"%s\" in the dictionary.\n", search);
                } else {
                    printf("Slang word : %s\n", search);
                    printf("Description : %s\n", searchResult->desc);
                }
                break;

            case 3:
                printf("Enter a prefix to search: ");
                scanf("%s", prefix);
                getchar();
                printSlangWordsWithPrefix(root, prefix);
                break;

            case 4:
    			printAllSlangWords(root, "");
    			break;

            case 5:
                printf("Thank you. . . Have a nice day!");
                break;
        }

        if (choice < 5) {
            printf("\nPress enter to continue...");
            getchar();
        }

    } while (choice != 5);

    return 0;
}
