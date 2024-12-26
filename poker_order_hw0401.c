#include <stdio.h>
#include <stdint.h>
#include "poker.h"
int32_t big_two_sort(int8_t cards[]){
	int32_t wrong_judge=0;
	for(int32_t k=0;k<13;k++){
		if(cards[k]<1 || cards[k]>52){
			wrong_judge=-1;
			break;
		}
		for(int32_t l=k+1;l<13;l++){
			if(cards[k]==cards[l]){
				wrong_judge=-1;
				break;
			}
		}
	}
	if(wrong_judge==0){
		 for(int32_t i=0;i<13;i++){
			for(int32_t j=i+1;j<13;j++){
				int32_t alter_i=cards[i]%13,alter_j=cards[j]%13;
				if(alter_i==0){
					alter_i=13;
				}
				if(alter_j==0){
					alter_j=13;
				}
				if(alter_i==2){
					alter_i=15;
				}
				if(alter_j==2){
					alter_j=15;
				}
				if(alter_i==1){
					alter_i=14;
				}
				if(alter_j==1){
					alter_j=14;
				}
				if(alter_i==alter_j){
					if(cards[i]>cards[j]){
						int32_t space=cards[i];
						cards[i]=cards[j];
						cards[j]=space;
					}
				}
				else if(alter_i>alter_j){
					int32_t space=cards[i];
					cards[i]=cards[j];
					cards[j]=space;
				}
			}
		}
		return 0;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
}
