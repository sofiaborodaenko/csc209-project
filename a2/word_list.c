#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "word_list.h"


/* Starting with words (returned by read_words), generate and return
   a new word list with only those words of length len. 

   Allocate exactly enough memory to store only those words of length len.

   Note: Do not make copies of the words.
*/
char **prune_word_list(char **word_list, int len) {
    // TODO: complete this function, replacing the return statement

    if (word_list == NULL) {
	return NULL;

    }


    int intAll = 0;	

    for (int i = 0; word_list[i] != NULL; i++) {
	if (strlen(word_list[i]) == len) {
 	    intAll++;
   	}
    }

    char **prune_list = malloc(sizeof(char *) * (intAll + 1));

    if (


    int index = 0;

    for (int j = 0; word_list[j] != NULL; j++) {
	if (strlen(word_list[j]) == len) {
	    prune_list[index] = word_list[j];
            index++;
	
	}
	
    }

    prune_list[index] = NULL;

    return prune_list;
}


/* Free memory acquired by prune_word_list.
*/
void deallocate_pruned_word_list(char **word_list) {
    free(word_list);
}
