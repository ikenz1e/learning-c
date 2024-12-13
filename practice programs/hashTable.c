#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct HashTable {
    int size;
    char *table[];
};



struct HashTable createTable(){
    int size;
    printf("enter the size:\n");
    scanf("%d", &size);
    fflush(stdin);

    struct HashTable hashTable;

    hashTable.size = size;
    hashTable.table[size];
    printf("%d\n", size);
    int i;
    while(i < size){
        printf("%d", i);
        printf("setting index %d to be \\0\n", i);
        hashTable.table[i] = "\0";
        i++;
    }
    printf("%d\n", i);
    return hashTable;
}

int calcHash(char word[], struct HashTable table){

    int hash;
    int value;

    for (int i = 0; i < strlen(word); i++){
        if (word[i] != ' '){
            value = ((int) word[i]) * (i + 1);
            value = value + (value % 3);
            value /= 3;
            hash += value;
        }
    }

    while(hash > table.size){
        hash /= table.size;
    }
    printf("%d\n", hash);

    return hash;
}

void handleAddItem(struct HashTable table){
    char characters[64];

    printf("enter the data:\n");
    fgets(characters, 64, stdin);
    fflush(stdin);

    int hash = calcHash(characters, table);

    if(table.table[hash] == NULL){
        table.table[hash] = characters;
        printf("succesfully added %s to the table\n", characters);
    }
}

void handleRemoveItem(struct HashTable table){
    printf("enter data to remove:\n");
    char data[16];
    fgets(data, 16, stdin);
    fflush(stdin);
    int hash = calcHash(data, table);
    if(table.table[hash] != NULL){
        table.table[hash] = NULL;
        printf("succesfully removed %s\0 from the table\n", data);
    }else{
        printf("cannot remove %s\0 from the table as it is not in the table\n", data);
    }
}

void handleSearchItem(struct HashTable table){
    printf("enter the data to search for\n");
    char data[16];
    fgets(data, 16, stdin);
    fflush(stdin);
    int hash = calcHash(data, table);
    if(table.table[hash] != "\0"){
        printf("the table contains %s\n", data);
    }else{
        printf("the table does not contain %s\n", data);
    }
}

void mainLoop(struct HashTable table){
    bool run = true;

    while(run){
        printf("would you like to: \nA: add data\nB: remove data\nC: search for data\n");
        char choice;
        scanf("%c", &choice);
        fflush(stdin);

        switch(toupper(choice)){
            case 'A':
                handleAddItem(table);
                break;
            case 'B':
                handleRemoveItem(table);
                break;
            case 'C':
                handleSearchItem(table);
                break;
            case 'Q':
                run = false;
                break;
            default:
                printf("that is invalid\n");
                continue;
        }

    }
}

int main() {

    struct HashTable hashTable = createTable();
    mainLoop(hashTable);
    return 0;
}