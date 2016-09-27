#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "phonebook_opt_v2.h"

unsigned int hash(char *name)
{
    unsigned int num=0;
    for(int i=1; i<strlen(name); i++) {
        num += (name[i]) ;
    }
    num %= (TABLE_SIZE / 26);
    num += (name[0] - 'a') * (TABLE_SIZE / 26);
    return num % TABLE_SIZE;
}


/* FILL YOUR OWN IMPLEMENTATION HERE! */
entry *findName(char lastName[], entry **hash_table)
{
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

    /*  Version 1 append immediately  */
//    e->pNext = hash_table[loc];
//    hash_table[loc] = e;

    /*  Version 2 append at the end of lined list  */
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
