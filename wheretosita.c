

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 10

int n, p; //number of friends = n and number of pairs tht cant sit together = p
char friends[MAX_N][20]; //array of friends 
bool alreadyUsed[MAX_N]; //array of alreadyUsed friends
int popcorn[MAX_N]; //array of popcorn
char seating[MAX_N][20]; 
int adjacent[MAX_N][MAX_N];
int count = 0;

/* swap function Used to swap the names of the friends */
void swap(char *a, char *b) {
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int countPermutations(char *s, int l, int r) //function to count the permutations of the friends

{
    int count = 0;
    int i;
    if (l == r)
        return 1;
    else
    {
        for (i = l; i <= r; i++)
        {
           //swap the names of the friends
            swap(&s[l], &s[i]);
            
            count += countPermutations(s, l + 1, r);
            swap(&s[l], &s[i]); // swap back
        }
    }
    return count;
}






bool is_valid(int index, int last_index) {
    if (last_index == -1)
        return true;
    int x = index, z = last_index;
    if (adjacent[x][z] || adjacent[z][x])
        return false;
    return true;
}







bool seating_Combinations(int index, int last_index) { //function to generate the seating arrangement
    if (index == n) {
        return true;
    }
    
    for (int i = 0; i < n; i++) { //for loop to iterate through the friends stops at n
        if (!alreadyUsed[i] && is_valid(i, last_index)) {
            alreadyUsed[i] = true; //set the alreadyUsed array to true
            strcpy(seating[index], friends[i]); //copy the friends into the seating array
            if (seating_Combinations(index + 1, i)) { //recursive call to generate the seating arrangement
                count++;
                return true;
            }
            alreadyUsed[i] = false; //set the alreadyUsed array to false
        }
    }
    return false;
}







int main(int argc, char *argv[]) //main function to read from the file
{
    if(argc !=2){
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    //open the file for reading from the command line
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Unable to open file for reading\n");
        return 1;
    }

                          
 fscanf(fp, "%d %d", &n, &p); //scan values for the first two variables

    
    for (int i = 0; i < n; i++) { //scan from file until n is reached
        fscanf(fp, "%s %d", friends[i], &popcorn[i]);

    }

    for (int i = 0; i < p; i++) {
        char name1[20], name2[20];
        //scan from file until p is reached
    }
{
    if(argc !=2){
        printf("Usage: %s <input file>\n", argv[0]);
        return 1;
    }
    //open the file for reading from the command line
    FILE *fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Unable to open file for reading\n");
        return 1;
    }



//scan values for the first two variables
    fscanf(fp, "%d %d", &n, &p);
    for (int i = 0; i < n; i++) {
        //scan from file until n is reached
        fscanf(fp, "%s %d", friends[i], &popcorn[i]);

    }

    for (int i = 0; i < p; i++) {
        char name1[20], name2[20];
        //scan from file until p is reached
        fscanf(fp, "%s %s", name1, name2);

        int x, z;  
        for (int j = 0; j < n; j++) { //for loop to iterate through the friends stops at n
            if (strcmp(friends[j], name1) == 0) x = j; //if the name is found in the array set x to j
            if (strcmp(friends[j], name2) == 0) z = j; //if the name is found in the array set z to j
        }
        adjacent[x][z] = adjacent[z][x] = 1; 
    }

    memset(alreadyUsed, false, sizeof(alreadyUsed));  




    
int countPermutations(char *s, int l, int r)
{
    
    int count = 0;
    int i;
    if (l == r)
        return 1;
    else
    {
        for (i = l; i <= r; i++)
        {
           //swap the names of the friends
            swap(&s[l], &s[i]);
            
            count += countPermutations(s, l + 1, r);
            swap(&s[l], &s[i]); // swap back
        }
    }
    return count;
}
    return 0;
}
}




 