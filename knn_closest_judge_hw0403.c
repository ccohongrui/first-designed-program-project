#include <stdio.h>
#include <stdint.h>
#include "knn.h"
#include <math.h>
uint32_t size_cp=0;
int32_t label_cp[10000]={0};
int32_t x_cp[10000]={0};
int32_t y_cp[10000]={0};
double distance[10000]={0};
int32_t space;
int32_t inputDataset(uint32_t size, int32_t label[], int32_t x[], int32_t y[]){
	if(size<10||size>10000){
		printf("Invalid input,error\nOut of range\n");
		return -1;
	}
	else{
		for(int32_t i=0;i<size;i++){
			for(int32_t j=0;j<size;j++){
				if(i!=j&&x[i]==x[j]&&y[i]==y[j]){
					printf("Invalid input,error\nRepeated points\n");
					return -1;
				}
			}
		}
		size_cp=size;
		for(int32_t i=0;i<size;i++){
			label_cp[i]=label[i];
		}
		for(int32_t i=0;i<size;i++){
			x_cp[i]=x[i];
		}
		for(int32_t i=0;i<size;i++){
			y_cp[i]=y[i];
		}
		return 0;
	}

}
int32_t classify(int32_t k, int32_t x, int32_t y){
	if(k<1||k>10000){
		printf("Invalid input,error\nk out of range\n");
		return -1;
	}
	for(int32_t i=0;i<size_cp;i++){
		if(x_cp[i]==x&&y_cp[i]==y){
			return label_cp[i];
		}
	}
	for(int32_t i=0;i<size_cp;i++){
		distance[i]=sqrt(pow(x_cp[i]-x,2)+pow(y_cp[i]-y,2));
	}
	for(int32_t i=0;i<size_cp;i++){
		for(int32_t j=i+1;j<size_cp;j++){
			if(distance[i]==distance[j]){
				if(label_cp[i]>label_cp[j]){
					space=label_cp[i];
					label_cp[i]=label_cp[j];
					label_cp[j]=space;
				}
			}
			else if(distance[i]>distance[j]){
				space=distance[i];
				distance[i]=distance[j];
				distance[j]=space;
				space=label_cp[i];
				label_cp[i]=label_cp[j];
				label_cp[j]=space;
			}
		}
	}
	int32_t count_num[k];
	int32_t a;
	for(int32_t i=0;i<k;i++){
		count_num[i]=0;
	}
	for(int32_t i=0;i<k;i++){
		for(int32_t j=0;j<k;j++){
			if(label_cp[i]==label_cp[j]){
				count_num[i]++;
			}
		}
	}
	int32_t b=0;
	int32_t max=count_num[b];
	for(int32_t i=0;i<k;i++){
		if(count_num[i]==max){
			if(label_cp[i]<label_cp[b]){
				b=i;
			}
		}
		if(count_num[i]>max){
			max=count_num[i];
			b=i;
		}
	}
	return label_cp[b];
}
