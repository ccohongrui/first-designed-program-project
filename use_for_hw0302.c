#include "gacha.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
	int32_t n1,g1,g2,g3,g4,g5,count,add;
	double p1,p2,p3,p4,p5;
	printf("set card number: ");
	scanf("%d",&n1);
	initialize(n1);
	do{
		printf("set group(g1,g2,g3,g4,g5): ");
		scanf("%d,%d,%d,%d,%d",&g1,&g2,&g3,&g4,&g5);
	}while(set_groups(g1,g2,g3,g4,g5)==-1);
	do{
		printf("set odds(p1,p2,p3,p4,p5): ");
		scanf("%lf,%lf,%lf,%lf,%lf",&p1,&p2,&p3,&p4,&p5);
	}while(set_props(p1,p2,p3,p4,p5)==-1);	
	do{
		printf("set guarantee for group_1: ");
		scanf("%d",&count);
	}while(set_guarantee(count)==-1);
	for(;;){
		int32_t select;
		printf("select function( add: 1 get_left: 2 pull_1: 3 pull10: 4 ): ");
		scanf("%d",&select);
		if(select==1){
			do{
				printf("add : ");
				scanf("%d",&add);
			}while(add_pull_number(add)==-1);
		}
		else if(select==2){
			printf("You have ");
			printf("%d",get_pull_number());
			printf(" cards now\n");
		}
		else if(select==3){
			pull();
		}
		else if(select==4){
			pull10();
		}
		else{
			break;
		}
	}
	return 0;
}
