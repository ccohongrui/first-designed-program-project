#include "knn.h"
#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t a=0,label[20],x[20],y[20],xx,yy,k;
	double distance[20];
	for(int32_t i=0;i<20;i++){
		srand(time(NULL)+a);
		label[i]=rand()%6;
		a++;
		x[i]=rand()%51;
		a++;
		y[i]=rand()%51;
	}
	for(int32_t i=0;i<20;i++){
		printf("label %d: %d   ",i+1,label[i]);
		printf("x%d: %d   ",i+1,x[i]);
		printf("y%d: %d\n",i+1,y[i]);
	}
	printf("Input x,y : ");
	scanf("%d,%d",&xx,&yy);
	for(int32_t i=0;i<20;i++){
		distance[i]=sqrt(pow(x[i]-xx,2)+pow(y[i]-yy,2));
		printf("distance %d: %lf and its label: %d\n",i+1,distance[i],label[i]);
	}
	printf("k nearest: ");
	scanf("%d",&k);
	printf("0 valid,-1 invalid: %d\n",inputDataset(20,label,x,y));
	printf("The answer is %d of label\n",classify(k,xx,yy));
	return 0;
}
