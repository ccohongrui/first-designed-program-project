#include <stdio.h>
#include <stdint.h>
#include "hw0304-1.h"
int32_t hanoi_recursive(void){
	void tower(int32_t n, int32_t from, int32_t to, int32_t buffer){
		if(n==1){
			printf("move disk %d to rod %d\n",n,to);
		}
		else{
			tower(n-1,from,buffer,to);
			printf("move disk %d to rod %d\n",n,to);
			tower(n-1,buffer,to,from);
		}
	}
	int32_t from=1;
	int32_t to=2;
	int32_t buffer=3;
	int32_t n=0;
	printf("Please enter the disk number(2-20): ");
	if(scanf("%d",&n)==1 && n>=2 && n<=20){
		tower(n,from,to,buffer);
		return (1<<n)-1;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
}
