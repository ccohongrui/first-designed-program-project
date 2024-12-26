#include <stdio.h>
#include <stdint.h>
#include "poker.h"
int32_t main(){
	int8_t cards[13]={0},select=0;
	while(1){
	printf("select mode(1:input yourself 2:auto other:break): ");
	scanf("%hhd",&select);
	if(select==1){
		printf("Input 13 cards(1-52): \n");
		for(int32_t i=0;i<13;i++){
			printf("%dth card: ",i+1);
			scanf("%hhd",&cards[i]);
		}
		printf("%d\n",big_two_sort(cards));
		for(int32_t j=0;j<13;j++){
			printf("%hhd,",cards[j]);
		}
		printf("\n");
	}
	else if(select==2){
		int8_t cards_1[13]={13,12,11,10,9,8,7,6,5,4,3,2,1};
		printf("%d\n",big_two_sort(cards_1));
		for(int32_t i=0;i<13;i++){
			printf("%hhd,",cards_1[i]);
		}
		printf("\n");
		int8_t cards_2[13]={52,39,26,13,41,28,15,2,3,40,27,14,1};
		printf("%d\n",big_two_sort(cards_2));
		for(int32_t i=0;i<13;i++){
			printf("%hhd,",cards_2[i]);
		}
		printf("\n");
		int8_t cards_3[13]={13,25,37,49,9,21,33,45,5,17,29,41,1};
		printf("%d\n",big_two_sort(cards_3));
		for(int32_t i=0;i<13;i++){
			printf("%hhd,",cards_3[i]);
		}
		printf("\n");
	}
	else{
		break;
	}
	}
	return 0;
}
