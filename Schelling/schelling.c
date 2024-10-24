#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * A simulation of the Schelling's Segregation Model
 * 
 * Time spent: 12 hours 
 * 
 * Authors: Maureen Wang, David Zhang
 * 
 */

/**
 * @brief This is the helper function to convert the two dimentional index 
 * (row,col) to the index of the one-dimentional representation of the grid.
 * 
 * @param row 
 * @param col 
 * @param col_size 
 * @return the index of the 1-d grid.
 */
int convert_index(int row, int col, int col_size){
    int index_1d=row*col_size+col;
    return index_1d;
}

/**
 * @brief This is the helper function to build a integer array for storing
 * the indices of the neighbors of a specific cell. Invalid indices are represented
 * with -1.
 * 
 * @param array 
 * @param row_size 
 * @param col_size 
 * @param index 
 * @return the integer array storing the neighbors' indices.
 */
int* find_neighbor(char* array, int row_size, int col_size, int index){
    //Initialize the neighboring arrey to be all -1.
    int* neighboring_agent = malloc(sizeof(int)*8);
    for (int i=0; i<8; i++){
        neighboring_agent[i]=-1;
    }
    // If it is not in the first row
    if (index>=col_size){
        neighboring_agent[0]=index-col_size;
        // If it is not the firt column, add the left neighbor
        if (index % col_size !=0){
            neighboring_agent[1]=index-col_size-1;
        }
        // If it is not the last folumn, add the right neighbor
        if ((index+1) % col_size !=0){
            neighboring_agent[2]=index-col_size+1;
        }
    }
    if (index % col_size !=0){
        neighboring_agent[3]=index-1;
    }
    if ((index+1) % col_size !=0){
        neighboring_agent[4]=index+1;
    }
    // If it is not in the last row 
    if (index<(row_size-1)*col_size){
        neighboring_agent[5]=index+col_size;
        // If it is not the firt column, add the left neighbor
        if (index % col_size !=0){
            neighboring_agent[6]=index+col_size-1;
        }
        // If it is not the last folumn, add the right neighbor
        if ((index+1) % col_size !=0){
            neighboring_agent[7]=index+col_size+1;
        }
    }
    return neighboring_agent;
}

/**
 * @brief This is the helper function to build an integer array to store the indices
 * of all the dissatisfied agents in one round.
 * 
 * @param array 
 * @param row_size 
 * @param col_size 
 * @param threshold 
 * @param agent_count 
 * @return the integer array storing the indices of dissatisfied agents.
 */
int* find_dissatisfied(char* array, int row_size, int col_size, float threshold, int* agent_count){
    int* dissatisfied_agent=malloc(sizeof(int)* (row_size*col_size));
    for (int i=0; i<row_size*col_size; i++){
        if (array[i]!=' '){
            int sum_same=0;
            int sum_different=0;
            int* neighboring_agent;
            neighboring_agent=find_neighbor(array, row_size, col_size, i);
            for (int j=0; j<8; j++){
                if (neighboring_agent[j]!= -1){
                    int neighbor_index =neighboring_agent[j];
                    // If the cell is occupied
                    if (array[neighbor_index]!=' '){
                        if (array[neighbor_index]==array[i]){
                            sum_same++;
                        }
                        if (array[neighbor_index]!=array[i]){
                            sum_different++;
                        }
                    }
                }
            }
            free(neighboring_agent);
            neighboring_agent=NULL;
            // if the agent is dissatisfied, add to the array.
            if (!(sum_same+sum_different==0)){
                float ratio = (float )sum_same/ (float) (sum_same+sum_different);
                if (ratio<threshold){
                    // printf("%f\n",ratio);
                    dissatisfied_agent[*agent_count]=i;
                    (*agent_count)++;
                }
            }
        }
    }
    return dissatisfied_agent;
}

/**
 * @brief This is the helper function to put a dissatisfied agent
 * to the nearest vacant space.
 * 
 * @param array 
 * @param size 
 * @param index 
 */
void put_new_house(char* array, int size, int index){
    for (int i=index; i<size; i++){
        if (array[i]==' '){
            array[i]=array[index];
            array[index]=' ';
            return;
        }
    }
    // If the function is still executing now, that means
    // we don't find an empty cell yet, so starting from 0
    for (int i=0; i<index; i++){
        if (array[i]==' '){
            array[i]=array[index];
            array[index]=' ';
            return;
        }
    }
}

/**
 * @brief This is the helper function to print the grid 
 * in the desired style
 * 
 * @param array 
 * @param row_size 
 * @param col_size 
 */
void print_grid(char* array, int row_size, int col_size){
    for (int i=0; i<row_size*col_size; i++){
        printf("%c", array[i]);
        if ( (i+1) % col_size ==0){
            printf("\n");
        }
    }
}

/**
 * @brief This is the helper function for the actual algorithm, performing the schelling 
 * model recursively. 
 * 
 * @param array 
 * @param round 
 * @param row_size 
 * @param col_size 
 * @param threshold 
 * @param verbosity 
 */
void do_schelling(char* array, int round, int row_size, int col_size, float threshold, int verbosity){
    // if limit is reached, stop
    if (round<=0){
        // If we reach the limit, need to print the grid if verbosity is not 0.
        if (verbosity!=0){
            print_grid(array, row_size, col_size);
        }
        return;
    }
    int agent_count=0;
    int* count=&agent_count;
    int *dissatisfied_agent=find_dissatisfied(array, row_size, col_size, threshold, count);
    // if all agents are satisfied, stop.
    if (agent_count==0){
        // If we find the desired result, need to print the grid if verbosity is not 0.
        if (verbosity!=0){
            print_grid(array, row_size, col_size);
        }
        free(dissatisfied_agent);
        dissatisfied_agent=NULL;
        return;
    }
    // For each dissatisfied cell in the round, put them in to new position
    for (int i=0; i<agent_count; i++){
        int index=dissatisfied_agent[i];
        put_new_house(array, row_size*col_size, index);
    }
    // If verbosity is 2. Need to print at every step including the initial state.
    if (verbosity==2){
        print_grid(array, row_size, col_size);
        usleep(200000);
        system("clear");
    }
    // Do the schelling recursively.
    free(dissatisfied_agent);
    dissatisfied_agent=NULL;
    return do_schelling(array, round-1, row_size, col_size, threshold,verbosity);
}

/**
 * @brief The main function read the file for the required information 
 * to set the grid and then perform the schelling using helper function.
 * 
 * @param argc need to be exactly 3.
 * @param argv 
 * @return 0
 */
int main(int argc, char** argv){
    if (argc!=3){
        printf("ERROR! User forgot to provide *two* arguments when running the program");
        exit(1);
    }
    // If the argument number is correct, start reading the file.
    FILE *infile;
    infile=fopen(argv[1], "r");
    // If file couldn't be read, exit with 1 immediately.
    if (infile == NULL) {
        printf("Error: unable to open file %s\n", argv[1]);
        exit(1);
    }
    // Transform the verbosity to integer
    int verbosity = atoi(argv[2]);
    // We need to rule out the case where the string itself is "0".
    if (strcmp(argv[2],"0")!=0){
        if (verbosity !=1 && verbosity !=2){
            printf("Error: invalid verbosity level");
            exit(1);
        }
    }
    int row_size; 
    int col_size; 
    // Read the first two integers
    if (fscanf(infile, "%d %d", &row_size, &col_size)!=2){
        printf("Error: The input file is miformatted!");
        exit(2);
    }
    int size=row_size*col_size;
    // Creating the two-dimensional array representing the housing market
    char* housing_array;
    // Need to include the terminating \0
    housing_array=malloc(sizeof(int) * (size));
    if (housing_array == NULL) {
        printf("ERROR: malloc failed!\n");
        exit(3);
    }
    // Initilize the array to all white space
    for (int i=0;i<size;i++){
        housing_array[i]=' ';
    }
    int round;
    // Read the round
    if (fscanf(infile, "%d", &round)!=1){
        printf("Error: The input file is miformatted!");
        exit(2);
    }
    float threshold;
    // Read the threshold
    if (fscanf(infile, "%f", &threshold)!=1){
        printf("Error: The input file is miformatted!");
        exit(2);
    }
    if (threshold<=0 || threshold>=1){
        printf("Error: invalid value for threshold");
        exit(2);
    }
    int dollar;
    // Set the dollars
    if (fscanf(infile, "%d", &dollar)==1){
        for (int i=0; i<dollar; i++){
            int row;
            int col;
            if (fscanf(infile, "%d %d", &row, &col)==2){
                if (row>=row_size || col>=col_size){
                    printf("Error: cell specification out of bound!");
                    exit(2);
                }
                int position=convert_index(row,col,col_size);
                housing_array[position]='$';
            }
            else {
                printf("Error: invalid index on the array!");
                exit(2);
            }
        }
    }
    else {
        printf("Missing cell specification");
        exit(2);
    }
    int dot;
    // Set the dots
    if (fscanf(infile, "%d", &dot)==1){
        for (int i=0; i<dot; i++){
            int row;
            int col;
            if (fscanf(infile, "%d %d", &row, &col)==2){
                if (row>=row_size || col>=col_size){
                    printf("Error: cell specification out of bound!");
                    exit(2);
                }
                int position=convert_index(row,col,col_size);
                housing_array[position]='.';
            }
            else {
                printf("Error: invalid index on the array!");
                exit(2);
            }
        }
    }
    else {
        printf("Missing cell specification");
        exit(2);
    }
    // Close the file since we don't need it anymore.
    fclose(infile);
    // Perform the schelling model
    do_schelling(housing_array, round, row_size, col_size, threshold, verbosity);
    // Free the grid.
    free(housing_array);
    housing_array=NULL;
    return 0;
}