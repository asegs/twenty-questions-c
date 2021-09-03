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

int main(){
    printf("%d\n",hex_to_int(int_to_hex(255)));
}
