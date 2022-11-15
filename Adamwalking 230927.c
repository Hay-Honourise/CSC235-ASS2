
/*1. Read the first line of the file, which indicates the number of tries we'll be reading and store it somewhere
2. For each try we'll be reading, we'll then output the number of times Adam walked before falling and store the result in an array
3. After that, we'll then print the result out to the console and/or write it into another file (Adamwalk_out.txt)
*/
/*
Adamwalk_in.txt is the file where we'll be reading the number of tries and each try that adam did
Adamwalk_out.txt is the file where we'll be writing output to
*/


#include <stdio.h>
#include <stdlib.h>

int num_test_cases(char walk[100]); // function prototyping


int main()
{
    // opening the input file, reading and storing the number of tries Adam made
    FILE *read_pointer;
    read_pointer = fopen("Adamwalk_in.txt", "r");
    int num_tried = 0; // I set it to zero, incase the file is empty it will won't print out anything, since this is the variable used in the loops
    fscanf(read_pointer, "%d", &num_tried);


    // creating variables to store the tries and the number of steps Adam made before falling
    char tries[num_tried][100];
    int steps[num_tried];


    // reads each try Adam made and stores the number of steps he made into the variable step
    for (int i = 0; i < num_tried; i++){
        fscanf(read_pointer, "%s", tries[i]);
        steps[i] = num_test_cases(tries[i]); // num_test_cases is a function that takes in a try Adam made and outputs the number of steps he made
    }

    fclose(read_pointer); // closes the file


    // prints out the result (number of steps for each try) out to the console and also write it to Adam_out
    FILE *write_pointer = fopen("Adamwalk_out.txt", "w");
    for (int i = 0; i < sizeof(steps) / sizeof(steps[0]); i++){
        fprintf(write_pointer,"%d\n", steps[i]);
        printf("%d\n", steps[i]);
    }


    fclose(write_pointer); // closes Adamwalk_out



    return 0;
}


int num_test_cases(char try[100]){
    /*

   FUNCTION THAT TAKES IN THE num_test_cases AND RETURN THE NUMBER OF STEPS HE MADE BEFORE FALLING DOWN

    */

    int n = strlen(try); // getting the length of the try i.e. the overall number of steps he made for that try
    //checking to see if the number of characters is more than 100
    if (n > 100){
        printf("THE CHARACTER ENTERED IS MORE THAN 100 (ERROR!)");
        return 0;
    }

    for (int a=0; a<n; a++){
        char step = try[a];


        if (step == 'U'){
                if ((a+1) == n){
                    // special case if the entire string is just Us i.e UUUUUUUUUUUUUUUUUUUUUUU
                    return a + 1;
                }
          continue;
        }
        else if (step == 'D') {
            return a;
        }
        else {
            printf("YOU TYPED IN WRONG CHARACTER %c DECLINED\n", step); // any other character apart from UD
            return a;
        }


    }


}
