//
// Created by arctic on 9/3/21.
//
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//questions will always be added to the file in order!
//calculate based on length of hex string * 4 - remaining spots

/*run this to:
 * 1. find all questions
 * 2. find all answers that have not answered these questions
 * 3. answer these questions via command line
 * 4. update answers file
**/

struct Answer {
    char * name;
    uint8_t * answers;
    int remaining;
};

char * int_to_hex(uint8_t num){
    char * output;
    output = malloc(2);
    sprintf(output,"%x",num);
    printf("%s\n",output);
    return output;
}

int int_pow(int a,int n){
    int init = 1;
    while (n-- > 0){
        init *= a;
    }
    return init;
}

int get_hex_val(char c,int pos){
    if (c >= 48 && c <= 57){
        return (c - 48) * int_pow(16,pos);
    }
    return (c - 87) * int_pow(16,pos);
}



uint8_t hex_to_int(char * hex){
    char first = hex[0];
    char second = hex[1];
    return get_hex_val(first,1) + get_hex_val(second,0);
}

//use buffers
/**
 * Returns the number of questions in the questions file
 * @return
 */
int count_questions(){
    int question_count = 0;
    FILE *fp;
    fp = fopen("questions.txt", "r");
    if (fp == NULL){
        printf("Null file pointer\n");
        return 0;
    }
    char c = 'a';
    while(c != EOF){
        c = fgetc(fp);
        if (c == '\n'){
            question_count++;
        }
    }
    return question_count + 1;
}

/**
 * Displays a question and object to the user, and returns 1 if yes, and 0 if no.
 * Crashes right now if multiple characters
 *
 * @param question
 * @param object
 * @return
 */
int answer_question(char * question, char * object){
    printf("Answer the following question for the thing: %s\n",object);
    printf("%s\n",question);
    printf("y/n: ");
    char selection;
    scanf("%s",&selection);
    printf("%c\n",selection);
    if (selection == 'y' || selection == 'Y'){
        return 1;
    }
    return 0;
}

struct Answer create_answer_from_line(char * line){
    //parse line and build answer
}

int main(){
    printf("%d\n",answer_question("Is it a living thing?","Bird"));
    printf("%d\n",count_questions());
    printf("%d\n",hex_to_int(int_to_hex(255)));
}
