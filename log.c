#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "log.h"

//HISTORY OF THE PLAYS

//Create a log txt file
void new_file(){

    FILE* input = fopen("log.txt", "w");
}

//Open the txt file to edit
FILE* open_file_edit(){

    FILE* input = fopen("log.txt", "a");

    return input;
}

//Open the txt file to read
FILE* open_file_read(){

    FILE* input = fopen("log.txt", "r");

    return input;
}

//Close the txt file
void close_file(FILE *file){
    fclose(file);
}


//Update the file log.txt with the history of the board acoording with the plays until the end of the game
void edit_history(HISTORY info_plays, int nlin, int nCol){

    FILE* input = open_file_edit();

    //Identifying the positions of the columns
    fprintf(input, "    ");

    for(int cont = 0; cont  < nCol; cont++){
        
        if(cont < 9){
            fprintf(input, " %d  ", cont+1);
        }
        else{
            fprintf(input, " %d ", cont+1);
        }
    }
    putc('\n', input);


    for(int i = 0; i < nlin; i++){

        //Identifying the positions of the lines
        if(i < 9){
            fprintf(input, "%d  ", i+1);
        }
        else{
            fprintf(input, "%d ", i+1);
        }


        for(int j = 0; j < nCol; j++){

            putc('|', input);
            fprintf(input, " %c ", info_plays.mat[i][j]);//erro
        }

        putc('|', input);
        putc('\n', input);
    }
    putc('\n', input);

    close_file(input);
}

//Update the file log.txt with the template when the game it's over
void editFinal_history(HISTORY info_plays, int nlin, int nCol){

    FILE* input = open_file_edit();

    fprintf(input, "*#*# Game over *#*#\n\n");


    //Identifying the positions of the columns
    fprintf(input, "    ");

    for(int cont = 0; cont  < nCol; cont++){
        
        if(cont < 9){
            fprintf(input, " %d  ", cont+1);
        }
        else{
            fprintf(input, " %d ", cont+1);
        }
    }
    putc('\n', input);
    
    for(int i = 0; i < nlin; i++){

        //Identifying the positions of the lines
        if(i < 9){
            fprintf(input, "%d  ", i+1);
        }
        else{
            fprintf(input, "%d ", i+1);
        }

        for(int j = 0; j < nCol; j++){

            putc('|', input);
            
            if((info_plays.finalMat[i*nCol+j] < 0) || (info_plays.finalMat[i*nCol+j] > 9)){

                fprintf(input, "%d ",info_plays.finalMat[i*nCol+j]);  
            }
            else{
                fprintf(input, " %d ",info_plays.finalMat[i*nCol+j]); 
            }
        }

        putc('|', input);
        putc('\n', input);
    }

    close_file(input);
}

//Calculates the game start time
void login_time(){

    int hour, min, sec, day, month, year;

    time_t currentTime;
    time(&currentTime);

    struct tm *local_time = localtime(&currentTime);

    day = local_time-> tm_mday;
    month = local_time-> tm_mon +1;
    year = local_time-> tm_year + 1900;

    sec = local_time-> tm_sec;
    min = local_time-> tm_min;
    hour = local_time-> tm_hour;

    //Prints the game start time
    recordTime(day, month, year, hour, min, sec);

}

//Prints the date and time of the game start
void recordTime(int day, int month, int year, int hour, int min, int sec){

    FILE* input = fopen("log.txt", "w"); //We open with the mode 'w' to refresh the log(since append mode accumulates the history)
    
    fprintf(input, "---Game Start : %d/%d/%d \n", day, month, year);
    fprintf(input, "time-> %.2d:%.2d:%.2d \n\n\n", hour, min, sec);

    close_file(input);
}

//Prints a message to the player according with the chosen coordinates
void print_message_history(int valid, int lin){

    FILE* input = open_file_edit();

    if(valid == 1){
        fprintf(input, "- Digite uma coordenada no formato \"x,y\" que esteja entre 1 e %d:\n", lin);
    }
    else if(valid == 2){
        fprintf(input, "- Essa coordenada já foi escolhida..\n- Por favor, digite outra coordenada  no formato \"x,y\" que esteja dentro do intervalo de 1 a %d!!\n", lin);
    }
    else if (!valid){
        fprintf(input, "- Coordenada inválida!\n- Por favor, digite novamente uma coordenada no formato \"x y\" que esteja dentro do intervalo de 1 a %d!!\n", lin);
    }
    else if(valid == -1){
      fprintf(input, "- Fim do arquivo..\n");
    }
    
    close_file(input);
}

void print_chosen_coord(HISTORY info_plays){

    FILE * input = open_file_edit();

    fprintf(input, "Chosen coordinate: %d,%d\n\n\n\n", info_plays.coordX, info_plays.coordY);

    close_file(input);
}
//EndFile
