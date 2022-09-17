#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASH_SIZE 128
#define MAX_NAME 64

//*===----------------------------------- Global ---------------------------------------===*

struct Node
{
    char *key;
    char *value;
    struct Node *next;
};

struct Hash
{
    struct Node *list[HASH_SIZE];
};

//*===-------------------------------- Prototipos --------------------------------------===*

struct Node *create_node(char *key, char *value);
void insert_node(struct Hash *hash, char *key, char *value);
char *search(struct Hash *hash, char *key);
unsigned int hash_code_djb2(char *key);

//*===-----------------------------------  Main  ---------------------------------------===*

int main()
{
    struct Hash *hash = (struct Hash *)malloc(sizeof(struct Hash));

    insert_node(hash, "Flavio", "Vieira");
    insert_node(hash, "Juliany", "Nascimento");

    printf("hash['Flavio']: %s\n", search(hash, "Flavio"));
    printf("hash['Juliany']: %s\n", search(hash, "Juliany"));

    return 0;
}

//*===------------------------------ Sub Funcoes --------------------------------------===*

char *search(struct Hash *hash, char *key)
{
    unsigned int index = hash_code_djb2(key);
    struct Node *node = hash->list[index];

    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return NULL;
}
//*===----------------------------------------------------------------------===*
void insert_node(struct Hash *hash, char *key, char *value)
{
    unsigned int index = hash_code_djb2(key);
    struct Node *node = hash->list[index];

    if (node == NULL)
        hash->list[index] = create_node(key, value);
    else
    {
        do
        {
            if (node->next == NULL)
            {
                node->next = create_node(key, value);
                break;
            }

        } while ((node = node->next));
    }
}
//*===----------------------------------------------------------------------===*
unsigned int hash_code_djb2(char *key)
{
    unsigned long hash = 5381;
    unsigned int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c; // x << 5 == x * 33

    return hash % HASH_SIZE;
}
//*===----------------------------------------------------------------------===*

struct Node *create_node(char *key, char *value)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key; // (*node).key = key
    node->value = value;
    node->next = NULL;
    return node;
}
//*===----------------------------------------------------------------------===*
