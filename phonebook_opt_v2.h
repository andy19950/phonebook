#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16
#define TABLE_SIZE 10000

/* TODO: After modifying the original version, uncomment the following
 * line to set OPT properly */
#define OPT 1

typedef struct __BOOK_INDEX_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    //struct __BOOK_INDEX_ENTRY *left, *right;
    //struct __PHONE_BOOK_ENTRY *detail;
    struct __BOOK_INDEX_ENTRY *pNext;
} entry;


typedef struct __PHONE_BOOK_ENTRY {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
};

entry *findName(char lastName[], entry **hash_table);
entry **append(char lastName[], entry **hash_table);

#endif
