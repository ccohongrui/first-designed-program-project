#include <stdio.h>
#include "mahjong.h"
int main(){
	size_t size;
	int32_t select;
	printf("How many consequence of files will you input: ");
	scanf("%zu",&size);
	int8_t cards[size];
	for(int32_t i=0;i<size;i++){
		printf("The %dth file: ",i);
		scanf("%hhd",&cards[i]);
	}
	select=check(cards,size);
	if(select==0){
		printf("Lose in hand\n");	
	}
	else if(select==1){
		printf("Win in hand\n");
	}
	return 0;
}
