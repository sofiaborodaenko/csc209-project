#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "parentWorker.h"


// cleans up the filename 
char *clean_filename(char *filename) {
    // find the first occurence of the underscore, and subtract that from the entire filename, then use the find char function to find the first . and store that in a seperate variable, concatinate the two and return 


}

char *create_target_path(char *filename) {
    //split the filename based on the underscores, , use a while loop and have it continuosuly call the find character until it retuns a 0 or -1, 

    // use while lop, outside of while loop find the first underscore and set it to a variable, in while loop find the next one, subtract the tewo then we have the first word, save it to an array, keep going until no more underscores found. at the end just find the . and subtract that from the last word and add it to the array
}



char *categorize_file(char *filename){
    // find where the period is using the find char function, and then check if the text matches a buncnh of options, can either have set arrays for each category, so text array would contain pdf or txt and if it matches that then set category to text and return, or just have a bunch of orr statements but that seems like hardcoding 
}
int count_lines(char *filename){
    // check if the category is a text, would need to call the above function, if yes then open the file, read fgets until the end while counting the number of lines, close the file
}
int count_words(char *filename){
    // check if categoy is a text, then use fscanf and fscanf(f, "%99s", word) == 1 then add it to a counter 
}
long count_size(char *filename){}

bool check_file_name(const char *filename){
    // check if file contains at least one underscore and exactly one period 
} // can be used to check if the file is valid before sending it to the worker

void create_go_directory(char **dir_name, int size){
    // given the size traverse through each, add the first to a new string, first check if directory exists if not create it, then add a / and then the second one, and same thing.  
}
void print_summary(char *original_filenames, char *clean_filenames, char *target_paths, char *categorys, int lines, int words, long size){
    // print a nicley formated summary given all of the details 
}

