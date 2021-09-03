#include <stdio.h>
#include <stdint.h>

//remove question from pool after use
//simple code to convert simple binary string to char string
//write command line util to update answers for all questions

int getQuestionAnswer(uint8_t* answers,int questionNumber){
	return (answers[questionNumber/8] >> (questionNumber % 8)) & 1;
}

//pick question with most yes * no scores
int idxOfBestQuestion(uint8_t* answers,int objectCount,int questionCount){
	int maxScore = 0;
	int maxIdx = -1;
	int yesScore;
	int noScore;
	for (int i = 0;i<questionCount;i++){
		yesScore = 0;
		noScore = 0;
		for (int j = 0;j<objectCount;j++){
			if (getQuestionAnswer(&answers[i],j)){
				yesScore ++;
			}else{
				noScore ++;
			}
		}
		if (yesScore * noScore > maxScore) {
			maxScore = yesScore * noScore;
			maxIdx = i;
		}
	}
	return maxIdx;
}

int main(){
	uint8_t numbers [2];
	numbers[0] = 129;
	numbers[1] = 129;

	for (int i = 0;i<16;i++){
		printf("%d\n",getQuestionAnswer(numbers,i));
	}
}
