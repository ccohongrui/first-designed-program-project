#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "myTuringMachine.h"
void TuringMachine(int8_t* ptape1, int8_t** ptape2, size_t *tape2Size) {
	while((*ptape1)!=-1){
		ptape1++;
	}
	ptape1++;
	while((*ptape1)!=-1){
		while((*ptape1)!=-1){
			if((*ptape1)>=10){
				ptape1++;
				continue;
			}
			else if((*ptape1)<10&&(*ptape1)>=0){
				(*ptape1)+=10;
				while((*ptape1)!=-1){ptape1--;}ptape1--;while((*ptape1)!=-1){ptape1--;}ptape1++;
				break;
			}
		}
		if((*ptape1)!=-1){
			while((*ptape1)==0||(*ptape1)==1){
				(*tape2Size)++;
				ptape1++;
			}
			ptape1++;
		}
	}
	ptape1--;while((*ptape1)!=-1){if((*ptape1)>=10){(*ptape1)-=10;}ptape1--;}ptape1--;while((*ptape1)!=-1){ptape1--;}ptape1++;
	(*ptape2)=malloc(((*tape2Size)+2)*sizeof(int8_t));
	*(*ptape2)=-1;
	(*ptape2)++;
	while((*ptape1)!=-1){
		while((*ptape1)!=-1){
			if((*ptape1)==0||(*ptape1)==1){
				(*ptape1)+=10;
				break;
			}
			else if((*ptape1)>=10){
				ptape1++;
				continue;
			}
		}
		if((*ptape1)-10==0){
			while((*ptape1)!=-1){
				ptape1++;
			}
			ptape1++;
			while((*ptape1)!=-1){
				*(*ptape2)=0;
				(*ptape2)++;
				ptape1++;
			}
		}
		else if((*ptape1)-10==1){
			while((*ptape1)!=-1){
				ptape1++;
			}
			ptape1++;
			while((*ptape1)!=-1){
				*(*ptape2)=(*ptape1);
				(*ptape2)++;
				ptape1++;
			}
		}
		if((*ptape1)==-1&&(*(ptape1-1))>=10){
			break;
		}
		else{
			ptape1--;while((*ptape1)!=-1){ptape1--;}ptape1--;while((*ptape1)!=-1){ptape1--;}ptape1++;
		}
	}
	ptape1--;while((*ptape1)!=-1){if((*ptape1)>=10){(*ptape1)-=10;}ptape1--;}ptape1++;
	*(*ptape2)=-1;
	(*ptape2)--;while((*(*ptape2))!=-1){(*ptape2)--;}(*ptape2)++;
} 
