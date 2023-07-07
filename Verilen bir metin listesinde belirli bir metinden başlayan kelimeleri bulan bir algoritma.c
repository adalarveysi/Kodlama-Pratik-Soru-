#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALPHABET_SIZE 26

// Metin ağacı düğüm yapısı
struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    int isEndOfWord;
};

// Yeni metin ağacı düğümü oluşturma
struct TrieNode* createNode() {
    struct TrieNode* newNode = (struct TrieNode*)malloc(sizeof(struct TrieNode));
    newNode->isEndOfWord = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    return newNode;
}

// Metin ağacına kelime ekleme
void insertWord(struct TrieNode* root, const char* word) {
    int length = strlen(word);
    struct TrieNode* currentNode = root;
    for (int i = 0; i < length; i++) {
        int index = word[i] - 'a';
        if (currentNode->children[index] == NULL) {
            currentNode->children[index] = createNode();
        }
        currentNode = currentNode->children[index];
    }
    currentNode->isEndOfWord = 1;
}

// Metin ağacında belirli bir metinden başlayan kelimeleri bulma
void findWords(struct TrieNode* root, const char* prefix) {
    int length = strlen(prefix);
    struct TrieNode* currentNode = root;
    for (int i = 0; i < length; i++) {
        int index = prefix[i] - 'a';
        if (currentNode->children[index] == NULL) {
            return;
        }
        currentNode = currentNode->children[index];
    }
    printWords(currentNode, prefix);
}

// Metin ağacındaki kelimeleri yazdırma (DFS)
void printWords(struct TrieNode* node, char* prefix) {
    if (node->isEndOfWord) {
        printf("%s\n", prefix);
    }
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i] != NULL) {
            char c = 'a' + i;
            char newPrefix[100];
            strcpy(newPrefix, prefix);
            int length = strlen(newPrefix);
            newPrefix[length] = c;
            newPrefix[length + 1] = '\0';
            printWords(node->children[i], newPrefix);
        }
    }
}

int main() {
    struct TrieNode* root = createNode();

    // Metin ağacına kelimeleri ekleme
    insertWord(root, "apple");
    insertWord(root, "application");
    insertWord(root, "banana");
    insertWord(root, "art");
    insertWord(root, "ball");
    insertWord(root, "cat");

    char prefix[100];
    printf("Aramak istediğiniz metni girin: ");
    scanf("%s", prefix);

    printf("Sonuç:\n");
    findWords(root, prefix);

    return 0;
}
