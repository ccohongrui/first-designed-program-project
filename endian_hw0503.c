#include "endian.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
int32_t endian_convert(uint8_t *pSrc,uint32_t size,uint8_t **ppDst){
	if(pSrc==NULL||ppDst==NULL){
        	return -1;
   	}
	if(size<=0){
        	return -1;
   	}
	*ppDst=malloc(sizeof(uint8_t)*size);
	for(int32_t i=0;i<size;i++){
		(*ppDst)[i]=pSrc[size-1-i];
	}
	return 0;
}
int32_t endian_quality_test(uint8_t *pNum1,uint32_t size1,uint8_t type1,uint8_t *pNum2,uint32_t size2,uint8_t type2){
	if(pNum1==NULL||pNum2==NULL){
      		printf("Invalid input,pNum==NULL\n");
    	}
	if(size1<=0||size2<=0) {
        	printf("Invalid input,size<=0\n");
    	}
	if((type1!=0&&type1!=1)||(type2!=0&&type2!=1)){
        	printf("Invalid input,type!=0 or 1\n");
    	}
	uint8_t *copy1=NULL;
	uint8_t *copy2=NULL;
	if(type1==0){
		if(endian_convert(pNum1,size1,&copy1)!=0){
			printf("Invalid input,endian_convert\n");
		}
	}
	else if(type1==1){
		copy1=malloc(sizeof(uint8_t)*size1);
		for(int32_t i=0;i<size1;i++){
			copy1[i]=pNum1[i];
		}
	}
	if(type2==0){
		if(endian_convert(pNum2,size2,&copy2)!=0){
			printf("Invalid input,endian_convert\n");
		}
	}
	else if(type2==1){
		copy2=malloc(sizeof(uint8_t)*size2);
		for(int32_t i=0;i<size2;i++){
			copy2[i]=pNum2[i];
		}
	}
	if(size1==size2){
		for(int32_t i=0;i<size1;i++){
			if(copy1[i]>copy2[i]){
				return 1;
			}
			if(copy1[i]<copy2[i]){
				return -1;
			}
		}
		return 0;
	}
	if(size1>size2){
		for(int32_t i=0;i<size2;i++){
			if(copy1[i]>copy2[i]){
				return 1;
			}
			if(copy1[i]<copy2[i]){
				return -1;
			}
		}
		for(int32_t i=size2;i<size1;i++){
			if(copy1[i]!=0){
				return 1;
			}
		}
		return 0;
	}
	if(size1<size2){
		for(int32_t i=0;i<size1;i++){
			if(copy1[i]>copy2[i]){
				return 1;
			}
			if(copy1[i]<copy2[i]){
				return -1;
			}
		}
		for(int32_t i=size1;i<size2;i++){
			if(copy2[i]!=0){
				return -1;
			}
		}
		return 0;
	}
	free(copy1);
	free(copy2);
}
 
