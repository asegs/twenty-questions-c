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
    int questions;
};

int str_len(char * str){
    int pos = 0;
    while (str[pos] != 0){
        pos++;
    }
    return pos;
}

int round_up(int num,int step){
    return ((num/step) + 1) * step;
}

char * int_to_hex(uint8_t num){
    char * output = malloc(2);
    sprintf(output,"%x",num);
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



uint8_t hex_to_int(char h0,char h1){
    return get_hex_val(h0,1) + get_hex_val(h1,0);
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

uint8_t * build_num_arr_from_hex_str(char * hex,int questions){

    int cells_count = questions / 8 + 1;

    uint8_t * cells;
    cells = malloc(cells_count);


    for (int i = 0;i<cells_count;i++){
        cells[i] = hex_to_int(hex[2*i],hex[2*i + 1]);
    }
    return cells;

}

char * build_hex_str_from_num_arr(uint8_t * nums,int questions){
    int nums_len = (questions/8) + (questions % 8 == 0);
    int hex_len = nums_len * 2;
    char * hex;
    hex = malloc(hex_len * sizeof('a'));
    for (int i = 0;i<nums_len;i++){
        char * hexes = int_to_hex(nums[i]);
        hex[2*i] = hexes[0];
        hex[2*i+1] = hexes[1];
    }
    return hex;
}

char * answer_to_line(struct Answer answer){
    char * output;
    sprintf(output,"%s,",answer.name);
    return output;

}

int main(){
    printf("%d\n",answer_question("Is it a living thing?","Bird"));
    printf("%d\n",count_questions());
    printf("%d\n",hex_to_int(int_to_hex(255)[0],int_to_hex(255)[1]));
    char a[4];
    a[0] = 'a';
    a[1] = 'b';
    a[2] = EOF;
    a[3] = 'c';
    printf("%d\n",str_len("hello"));
    uint8_t b[4];
    b[0] = 129;
    b[1] = 127;
    b[2] = 125;
    b[3] = 123;
    char * m = build_hex_str_from_num_arr(b,24);
    uint8_t * n = build_num_arr_from_hex_str(m,24);
    printf("%s\n",m);
    printf("%d\n",n[0]);
}
