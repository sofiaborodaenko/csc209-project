#include <stdio.h>
#include <stdlib.h>

/* Return a pointer to an array of two dynamically allocated arrays of ints.
   The first array contains the elements of the input array s that are
   at even indices.  The second array contains the elements of the input
   array s that are at odd indices.

   Do not allocate any more memory than necessary. You are not permitted
   to include math.h.  You can do the math with modulo arithmetic and integer
   division.
*/
int **split_array(const int *s, int length) {
	int **twoDArr = malloc(sizeof(int*) * 2);

	if (length == 0) {
		twoDArr[0] = NULL;
		twoDArr[1] = NULL;
		return twoDArr;
	} 

	int odd_size = length / 2;
	int even_size = (length + 1) / 2;

		
	twoDArr[0] = malloc(sizeof(int) * even_size);
	twoDArr[1] = malloc(sizeof(int) * odd_size);	
	
	int i0 = 0;
        int i1 = 0;
        
	for (int i = 0; i < length; i++) {
        	if (i % 2 == 0) {
            		twoDArr[0][i0] = s[i];
                        i0++;
                } else{
                        twoDArr[1][i1] = s[i];
                        i1++;
                 }

	}
	
	return twoDArr;

}

/* Return a pointer to an array of ints with size elements.
   - strs is an array of strings where each element is the string
     representation of an integer.
   - size is the size of the array
 */

int *build_array(char **strs, int size) {
	int *arr_int = malloc(sizeof(int) * size);
	
	for (int i = 0; i < size; i++) {
		arr_int[i] = strtol(strs[i], NULL, 10);
	}

	return arr_int;

}


int main(int argc, char **argv) {
    /* Replace the comments in the next two lines with the appropriate
       arguments.  Do not add any additional lines of code to the main
       function or make other changes.
     */
    int *full_array = build_array(&argv[1], argc - 1);
    int **result = split_array(full_array, argc - 1);

    printf("Original array:\n");
    for (int i = 0; i < argc - 1; i++) {
        printf("%d ", full_array[i]);
    }
    printf("\n");

    printf("result[0]:\n");
    for (int i = 0; i < argc / 2; i++) {
        printf("%d ", result[0][i]);
    }
    printf("\n");

    printf("result[1]:\n");
    for (int i = 0; i < (argc - 1) / 2; i++) {
        printf("%d ", result[1][i]);
    }
    printf("\n");
    free(full_array);
    free(result[0]);
    free(result[1]);
    free(result);
    return 0;
}
