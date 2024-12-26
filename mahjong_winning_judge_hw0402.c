#include <stdio.h>
#include <stdint.h>
#include "mahjong.h"
int32_t chow_problem(int32_t chow,int32_t kong,int32_t pongs,int32_t pair);
int8_t cards_count[34]={0};
int32_t consequence,quadra=0;
int32_t check(int8_t cards[], size_t size){
	for(int32_t i=0;i<size;i++){
		if(cards[i]>34||cards[i]<1){
			printf("Invalid input,Out of range\n");
			return -1;
		}
		cards_count[cards[i]-1]++;
	}
	for(int32_t i=0;i<34;i++){
		if(cards_count[i]>4){
			printf("Invalid input,More than 4 copies\n");
			return -1;
		}
	}
	consequence=chow_problem(0,0,0,0);
	if(consequence==0){
		for(int32_t i=0;i<34;i++){
			if(cards_count[i]==4){
				quadra++;
			}
		}
	}
	if((size<17||size>17+quadra)&&consequence==0){
		printf("Invalid input,Xianggong\n");
		return -1;
	}
	else{
		return consequence;
	}
}
int32_t chow_problem(int32_t chow,int32_t kong,int32_t pongs,int32_t pair){
	int32_t find=0;
	for(int32_t i=0;i<34;i++){
		if(cards_count[i]!=0){
			find=1;
		}
	}
	if(pongs+kong+chow==5&&pair==1&&find==0){
		return 1;
	}
	for(int32_t i=0;i<34;i++){
		if(i<25&&i!=7&&i!=8&&i!=16&&i!=17){
			if(cards_count[i]>0&&cards_count[i+1]>0&&cards_count[i+2]>0){
				cards_count[i]--;
				cards_count[i+1]--;
				cards_count[i+2]--;
				if(chow_problem(chow+1,kong,pongs,pair)){
					return 1;
				}
				cards_count[i]++;
				cards_count[i+1]++;
				cards_count[i+2]++;
			}
		}
		if(cards_count[i]==4){
			cards_count[i]-=4;
			if(chow_problem(chow,kong+1,pongs,pair)){
				return 1;
			}
			cards_count[i]+=4;
		}
		if(cards_count[i]==3){
			cards_count[i]-=3;
			if(chow_problem(chow,kong,pongs+1,pair)){
				return 1;
			}
			cards_count[i]+=3;
		}
		if(cards_count[i]==2){
			cards_count[i]-=2;
			if(chow_problem(chow,kong,pongs,pair+1)){
				return 1;
			}
			cards_count[i]+=2;
		}
	}
	return 0;
}


