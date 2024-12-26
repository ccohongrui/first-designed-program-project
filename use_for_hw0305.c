#include "shapez.h"
int main(){
	int tasks,select,m,c,r,s,mr,p,ing;
	do{
		printf("please enter the task(1-10) you want(task=10 stop): ");
		scanf("%d",&tasks);
		Target(tasks);
	}while(tasks!=10);
	for(;;){
		printf("please choose function(1:miner 2:cutter 3:rotator 4:stacker(X) 5:mixer(X) 6:painter other:break): ");
		scanf("%d",&select);
		if(select==1){
			printf("Input the shape you want(1:circle 2:rectangle 3:fan 4:star): ");
			scanf("%d",&m);
			ing=miner(m);
			continue;
		}
		else if(select==2){
			ing=cutter(ing);
			continue;
		}
		else if(select==3){
			ing=rotator(ing);
			continue;
		}
		else if(select==6){
			printf("select a color(1:R 2:G 3:B): ");
			scanf("%d",&p);
			ing=painter(ing,p);
			continue;
		}
		else{
			break;
		}
	}
	print_shapez(ing);
	return 0;
}

