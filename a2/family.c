#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "family.h"

/* Number of word pointers allocated for a new family.
   This is also the number of word pointers added to a family
   using realloc, when the family is full.
*/
static int family_increment = 0;


/* Set family_increment to size, and initialize random number generator.
   The random number generator is used to select a random word from a family.
   This function should be called exactly once, on startup.
*/
void init_family(int size) {
    family_increment = size;
    srand(time(NULL));
}


/* Given a pointer to the head of a linked list of Family nodes,
   print each family's signature and words.

   Do not modify this function. It will be used for marking.
   You may find it useful for testing.
*/
void print_families(Family* fam_list) {
    int i;
    Family *fam = fam_list;
    
    while (fam) {
        printf("***Family signature: %s Num words: %d\n",
               fam->signature, fam->num_words);
        for(i = 0; i < fam->num_words; i++) {
            printf("     %s\n", fam->word_ptrs[i]);
        }
        printf("\n");
        fam = fam->next;
    }
}


/* Return a pointer to a new family whose signature is 
   a copy of str, and whose fields are initialized as follows:
      - word_ptrs points to family_increment+1 pointers, 
      - numwords is 0, 
      - maxwords is family_increment, 
      - next is NULL.
*/
Family *new_family(char *str) {
    // TODO: complete this function, changing the return value


    Family *new_fam = malloc(sizeof(Family));
    new_fam.signature = malloc(sizeof(char) * strlen(str) + 1);
	
    strcpy(new_fam->signature, str);   
    new_fam->word_ptrs = malloc(sizeof(char *) * (family_increment+1));
    new_fam->num_words = 0;
    new_fam->max_words = family_increment;
    new_fam->next = NULL; 
    
    return new_fam;
}


/* Add word to the next free slot in fam->word_ptrs.
   If fam->word_ptrs is full, first use realloc to allocate family_increment
   more pointers and then add the new pointer.
*/
void add_word_to_family(Family *fam, char *word) {
    // TODO: complete this function

    if (fam->num_words >= fam->max_words) {
	int new_size = fam->max_words + family_increment;
	char **error = realloc(fam->word_ptrs, sizeof(char *) * new_size);

	if (error == NULL) {
	    perror("realloc");
	    exit(1);
	}

	fam->word_ptrs = error;
	fam->max_words = new_size;
    }

    fam->word_ptrs[fam->num_words] = word;
    fam->num_words++;


    return;
}


/* Return a pointer to the family whose signature is sig;
   if there is no such family, return NULL.
   fam_list is a pointer to the head of a list of Family nodes.
*/
Family *find_family(Family *fam_list, char *sig) {
    // TODO: complete this function, changing the return value

    Family *pointer = fam_list;

    while (pointer != NULL) {
    	if (strcmp(pointer->signature, sig) == 0) {
	    return pointer;

	}

        pointer = pointer->next;

    }

    return NULL;
	
}


/* Return a pointer to the family in the list with the most words;
   if the list is empty, return NULL. If multiple families have the most words,
   return a pointer to any of them.
   fam_list is a pointer to the head of a list of Family nodes.
*/
Family *find_biggest_family(Family *fam_list) {
    // TODO: complete this function, changing the return value

    if (fam_list == NULL) {
	return NULL;
    }

    Family *pointer = fam_list;
    Family *largest = fam_list;
 
    while (pointer != NULL) {
	if (pointer->next != NULL) {
	    
	    if( largest->num_words  < pointer->num_words) {
		largest = pointer;
	    }

	}

	pointer = pointer->next;
    }

    return largest;
}


/* Deallocate all memory rooted in the List pointed to by fam_list. */
void deallocate_families(Family *fam_list) {
    // TODO: complete this function

    Family *pointer = fam_list;

    
    while (pointer != NULL) {
	free(pointer->signature);
	
	for (int i = 0; i < pointer->num_words; i++) {
	    free(pointer->word_ptrs[i]);
	
	}

	free(pointer->word_ptrs);

	Family *next_pntr = pointer->next;
	free(pointer)
	pointer = next_pntr;
    }


    return;
}


/* Generate and return a linked list of all families using words pointed to
   by word_list, using letter to partition the words.

   Implementation tips: To decide the family in which each word belongs, you
   will need to generate the signature of each word. Create only the families
   that have at least one word from the current word_list.
*/
Family *generate_families(char **word_list, char letter) {
    // TODO: complete this function, changing the return value

    return NULL;
}


/* Return the signature of the family pointed to by fam. */
char *get_family_signature(Family *fam) {
    // TODO: complete this function, changing the return value

    if (fam == NULL) {
	printf("family pointed to by fam is null.");
	return NULL;
    }

  
    return fam->signature;

}


/* Return a pointer to an array of word pointers, each of which
   points to a word in fam. These pointers should not be the same
   as those used by fam->word_ptrs (i.e. they should be independently malloc'd),
   because fam->word_ptrs can move during a realloc.
   As with fam->word_ptrs, the final pointer should be NULL.
*/
char **get_new_word_list(Family *fam) {
    // TODO: complete this function, changing the return value

    if (fam == NULL) {
	printf("fam is null");
	return NULL;
    }

    char **word_ptrs = malloc(sizeof(char *) * (fam->num_words + 1));
	
    if (word_ptrs == NULL) {
	perror("malloc");
	exit(1);
	
    }

    for (int i = 0; i < fam->num_words; i++) {

	word_ptrs[i] = fam->word_ptrs[i]; 

    }

    word_ptrs[fam->num_words] = NULL;

    return word_ptrs;
}


/* Return a pointer to a random word from fam. 
   Use rand (man 3 rand) to generate random integers.
*/
char *get_random_word_from_family(Family *fam) {
    // TODO: complete this function, changing the return value

    return NULL;
}
