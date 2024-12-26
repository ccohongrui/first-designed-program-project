#include <stdio.h>
#include <stdint.h>
#include "mygcd.h"
uint32_t a_set=0,b_set=0,max=0,c=0;
uint32_t gcd(int32_t print_format,uint32_t a,uint32_t b){
	c++;
	if(((print_format!=0 && print_format!=1 && print_format!=2) || (a<=0 || b<=0) || (b>a)) && c==1){
		printf("Invalid input,error\n");
		return 0;
	}
	if(c==1){
		a_set=a;
		b_set=b;
	}
	if(c==1){
		max=a_set/b_set;
		uint32_t cal_a=a_set,cal_a_1,cal_b=b_set,cal_b_1;
		while(1){
			cal_a_1=cal_a%cal_b;
			cal_b_1=cal_b%(cal_a%cal_b);
			cal_a=cal_a_1;
			cal_b=cal_b_1;
			if(cal_a==0 || cal_b==0 || cal_a%cal_b==0){
				break;
			}
			if(max<cal_a_1/cal_b_1){
				max=cal_a_1/cal_b_1;
			}
		}
	}
	if(print_format==0){
	}
	else if(print_format==1){
		if(c==1){
			printf("Mathematical expression: \n");
		}
		if(b==0){
			return a;
		}
		else{
			printf("%d / %d = %d . . . %d\n",a,b,a/b,a%b);
			return gcd(1,b,a%b);
		}
	}
	else if(print_format==2){
		if(c==1){
			printf("Vertical expression: \n");
		}
		int32_t width_1=0,calculate_1=a_set;
		while(calculate_1!=0){
			calculate_1=calculate_1/10;
			width_1++;
		}
		int32_t width_4=0,calculate_4=max;
		while(calculate_4!=0){
			calculate_4=calculate_4/10;
			width_4++;
		}
		if(b==0 || a==0){
			int32_t width_2=0,calculate_2=0;
			if(b==0){
				calculate_2=a;
			}
			else{
				calculate_2=b;
			}
			while(calculate_2!=0){
				calculate_2=calculate_2/10;
				width_2++;
			}
			for(int32_t i=1;i<=width_4;i++){
				printf(" ");
			}
			printf(" |");
			if(b==0){
				for(int32_t i=1;i<=width_1-width_2;i++){
					printf(" ");
				}
			}
			else{
				for(int32_t i=1;i<=width_1-1;i++){
				printf(" ");
				}
			}
			printf("%d|",a);
			if(b==0){
				for(int32_t i=1;i<=width_1-1;i++){
					printf(" ");
				}
			}
			else{
				for(int32_t i=1;i<=width_1-width_2;i++){
					printf(" ");
				}
			}
			if(b==0){
				printf("%d|",b);
			}
			else{
				printf(" ");
			}
			printf("\n");
			if(b==0){
				return a;
			}
			else{
				return b;
			}
		}
		else{
			uint32_t zero=b;
			if(a%b>0){
				zero=b%(a%b);
			}			
			int32_t width_2=0,calculate_2=a;
			while(calculate_2!=0){
				calculate_2=calculate_2/10;
				width_2++;
			}
			int32_t width_3=0,calculate_3=b;
			while(calculate_3!=0){
				calculate_3=calculate_3/10;
				width_3++;
			}
			int32_t width_0=0,calculate_0=a/b;
			while(calculate_0!=0){
				calculate_0=calculate_0/10;
				width_0++;
			}
			int32_t width_5=0,calculate_5=b*(a/b);
			while(calculate_5!=0){
				calculate_5=calculate_5/10;
				width_5++;
			}
			int32_t width_6=0,calculate_6=0;
			if(a%b!=0){
				calculate_6=(a%b)*(b/(a%b));
				while(calculate_6!=0){
					calculate_6=calculate_6/10;
					width_6++;
				}
			}
			for(int32_t i=1;i<=width_4-width_0;i++){
				printf(" ");
			}
			printf("%d |",a/b);
			for(int32_t i=1;i<=width_1-width_2;i++){
				printf(" ");
			}
			printf("%d|",a);
			for(int32_t i=1;i<=width_1-width_3;i++){
				printf(" ");
			}
			printf("%d|",b);
			if(a%b==0){
				printf("\n");
			}
			else{
				printf(" %d\n",b/(a%b));
			}
			for(int32_t i=1;i<=width_4;i++){
				printf(" ");
			}
			printf(" |");
			for(int32_t i=1;i<=width_1-width_5;i++){
				printf(" ");
			}
			printf("%d|",b*(a/b));
			if(a%b==0){
				for(int32_t i=1;i<=width_1;i++){
					printf(" ");
				}
				printf("|");
			}
			else{
				for(int32_t i=1;i<=width_1-width_6;i++){
					printf(" ");
				}
				printf("%d|",(a%b)*(b/(a%b)));
			}
			printf("\n");
			for(int32_t i=1;i<=width_4+1;i++){
				printf(" ");
			}
			for(int32_t i=1;i<=2*width_1+3;i++){
				printf("-");
			}
			printf("\n");	
			return gcd(2,a%b,zero);
		}
	}
}



