#include <stdlib.h>
#include <string.h>
#include "phonebook_opt_v2.h"

int hash(char *name)
{
    int num=0;
    for(int i=0; i<strlen(name); i++) {
        num += (int) name[i];
    }
    return num % 1000;
}


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry **hash_table)
{
    /* TODO: implement */
    int loc = hash(lastName);
    entry *ptr = hash_table[loc];
    while(strcmp(lastName, ptr->lastName))
        ptr = ptr->pNext;
    return ptr;
}

entry **append(char lastName[], entry **hash_table)
{
    entry *e = (entry*) malloc(sizeof(entry));
    e->pNext = NULL;
    strcpy(e->lastName, lastName);
    int loc = hash(lastName);
    /*e->pNext = hash_table[loc];
    hash_table[loc] = e;
    */
    if(hash_table[loc] == NULL)
        hash_table[loc] = e;
    else {
        entry* ptr = hash_table[loc];
        while(ptr->pNext != NULL)
            ptr = ptr->pNext;
        ptr->pNext = e;
    }
    return hash_table;
}


