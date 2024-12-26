#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "gacha.h"
int32_t num=0,counter=0,now_pull=0,count_plus=0,count_pull10=0,count_0=0,count_1=0;
int32_t group_1_size=0,group_2_size=0,group_3_size=0,group_4_size=0,group_5_size=0,group_6_size=0;
double group_1_odds=0,group_2_odds=0,group_3_odds=0,group_4_odds=0,group_5_odds=0,group_6_odds=0;
void initialize(int32_t n){
	if(n>0){
		num=n;
	}
	else{
		printf("Invalid input,error\n");
	}
}

int32_t set_groups(int32_t g1,int32_t g2,int32_t g3,int32_t g4,int32_t g5){
	if((g1<g2) && (g2<g3) && (g3<g4) && (g4<g5) && (g5<num)){
		group_1_size=g1;
		group_2_size=g2-g1;
		group_3_size=g3-g2;
		group_4_size=g4-g3;
		group_5_size=g5-g4;
		group_6_size=num-g5;
		return 0;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}

}
int32_t set_props(double p1,double p2,double p3,double p4,double p5){
	double p6=1-p1-p2-p3-p4-p5;
	if((p1<p2)&&(p2<p3)&&(p3<p4)&&(p4<p5)&&(p5<p6)&&p1>0&&p2>0&&p3>0&&p4>0&&p5>0&&p6>0){
		group_1_odds=p1;
		group_2_odds=p2;
		group_3_odds=p3;
		group_4_odds=p4;
		group_5_odds=p5;
		group_6_odds=p6;
		return 0;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
}
int32_t set_guarantee(int32_t count){
	if(count>0){
		counter=count;
		return 0;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}

}
int32_t add_pull_number(int32_t add){
	if(add==0){
		printf("you input no pull,but it's available\n");
		return 0;
	}
	else if(add>0){
		now_pull=now_pull+add;
		return 0;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
}
int32_t get_pull_number(void){
	return now_pull;
}
int32_t pull(void){
	if(now_pull>0&&group_1_size>0&&group_2_size>0&&group_3_size>0&&group_4_size>0&&group_5_size>0&&group_6_size>0
	&&(group_1_odds<group_2_odds)&&(group_2_odds<group_3_odds)&&(group_3_odds<group_4_odds)&&(group_4_odds<group_5_odds)
	&&(group_5_odds<group_6_odds)&&group_1_odds>0&&group_2_odds>0&&group_3_odds>0&&group_4_odds>0&&group_5_odds>0
	&&(group_6_odds>0&&num>0&&counter>0)){
		srand(time(NULL)+count_0);
		double odds=((double)rand())/RAND_MAX;
		count_0=count_0+100;
		now_pull--;
		if(odds<=group_1_odds){
			count_pull10++;
			count_plus=0;
			printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
		}
		else if(odds<=group_1_odds+group_2_odds){
			if(count_plus==counter-1){
				count_pull10++;
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else{
				count_pull10++;
				count_plus++;
				printf("Your award is ID %d belongs in group 2\n"
				,rand()%group_2_size+1+group_1_size);
			}
		}
		else if(odds<=group_1_odds+group_2_odds+group_3_odds){
			if(count_plus==counter-1){
				count_pull10++;
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else{
				count_pull10++;
				count_plus++;
				printf("Your award is ID %d belongs in group 3\n"
				,rand()%group_3_size+1+group_1_size+group_2_size);
			}
		}
		else if(odds<=group_1_odds+group_2_odds+group_3_odds+group_4_odds){
			if(count_plus==counter-1){
				count_pull10++;
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else{
				count_plus++;
				printf("Your award is ID %d belongs in group 4\n"
				,rand()%group_4_size+1+group_1_size+group_2_size+group_3_size);
			}
		}
		else if(odds<=group_1_odds+group_2_odds+group_3_odds+group_4_odds+group_5_odds){
			if(count_plus==counter-1){
				count_pull10++;
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else{
				count_plus++;
				printf("Your award is ID %d belongs in group 5\n"
				,rand()%group_5_size+1+group_1_size+group_2_size+group_3_size+group_4_size);
			}
		}
		else{
			if(count_plus==counter-1){
				count_pull10++;
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else{
				count_plus++;
				printf("Your award is ID %d belongs in group 6\n"
				,rand()%group_6_size+1+group_1_size+group_2_size+group_3_size+group_4_size+group_5_size);
			}
		}
		return 0;
	}
	else{
		printf("Invalid initial,error\n");
		return -1;
	}
}
int32_t pull10(void){
	if(now_pull>=10&&group_1_size>0&&group_2_size>0&&group_3_size>0&&group_4_size>0&&group_5_size>0&&group_6_size>0
	&&(group_1_odds<group_2_odds)&&(group_2_odds<group_3_odds)&&(group_3_odds<group_4_odds)&&(group_4_odds<group_5_odds)
	&&(group_5_odds<group_6_odds)&&group_1_odds>0&&group_2_odds>0&&group_3_odds>0&&group_4_odds>0&&group_5_odds>0
	&&(group_6_odds>0&&num>0&&counter>0)){
		count_pull10=0;
		for(int32_t i=1;i<=9;i++){	
			pull();	
		}
		if(count_pull10==0){
			now_pull--;
			srand(time(NULL)+count_1);
			count_1=count_1+100;
			double odds_1=group_1_odds/(group_1_odds+group_2_odds+group_3_odds);
			double odds_2=group_2_odds/(group_1_odds+group_2_odds+group_3_odds);
			double props=rand()/RAND_MAX;
			if(props<=odds_1){
				count_plus=0;
				printf("Your award is ID %d belongs in group 1\n",rand()%group_1_size+1);
			}
			else if(props<=odds_1+odds_2){
				printf("Your award is ID %d belongs in group 2\n"
				,rand()%group_2_size+1+group_1_size);
			}
			else{
				printf("Your award is ID %d belongs in group 3\n"
				,rand()%group_3_size+1+group_1_size+group_2_size);
			}
		}
		else{
			pull();
		}
	}
	else{
		printf("Invalid initial,error\n");
		return -1;
	}
}
