#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include "riemann.h"
static int32_t cal_a,cal_b,cal_c;

void set_polynomial(int32_t a,int32_t b,int32_t c){
	cal_a=a;
	cal_b=b;
	cal_c=c;
	printf("The function f(x)=%dx^2+(%d)x+(%d)\n",a,b,c);
}

double calculate_riemann_integral(int32_t begin,int32_t end){
	if(end<begin){
		printf("Invalid input,error\n");
		return -1.;
	}
	else{
		double cal_end=((cal_a/3.)*end*end*end+(cal_b/2.)*end*end+(cal_c)*end);
		double cal_begin=((cal_a/3.)*begin*begin*begin+(cal_b/2.)*begin*begin+(cal_c)*begin);
		return cal_end-cal_begin;
	}
}

double calculate_riemann_sum(int32_t begin,int32_t end,int32_t n){
	if(end<begin || n<=0){
		printf("Invalid input,error\n");
		return -1.;
	}
	else{
		double sum=0.,interval=((double)(end-begin))/(double)n;
		for(int32_t i=0;i<n;i++){
			double value=interval*(cal_a*(begin+interval*i)*(begin+interval*i)+cal_b*(begin+interval*i)+cal_c);
			sum=sum+value;
		}
		return sum;
	}
}

double calculate_area(int32_t begin,int32_t end){
	if(end<begin){
		printf("Invalid input,error\n");
		return -1.;
	}
	int32_t judge;
	double value_b,value_s,root;
	if(cal_a!=0){
		judge=(cal_b*cal_b-4*cal_a*cal_c);
		if(cal_a>0){
			value_b= ((double)(sqrt(judge)-cal_b))/(2*cal_a);
			value_s= ((double)(-sqrt(judge)-cal_b))/(2*cal_a);
		}
		else{
			value_b= ((double)(-sqrt(judge)-cal_b))/(2*cal_a);
			value_s= ((double)(sqrt(judge)-cal_b))/(2*cal_a);
		}
	}
	else if(cal_b!=0){
		root=((double)(-cal_c))/cal_b;
	}
	else{
		if(cal_c>=0){
			return (end-begin)*cal_c;
		}
		else{
			return -(end-begin)*cal_c;
		}
	}
	if(cal_a!=0 && (judge<=0 || (begin>=value_b || end<=value_s))){
		double cal_end=((cal_a/3.)*end*end*end+(cal_b/2.)*end*end+(cal_c)*end);
		double cal_begin=((cal_a/3.)*begin*begin*begin+(cal_b/2.)*begin*begin+(cal_c)*begin);
		if(cal_a>0){
			return cal_end-cal_begin;
		}
		else if(cal_a<0){
			return -(cal_end-cal_begin);
		}
	}
	else if(cal_a!=0 && judge>0){
		double cal_end_1=((cal_a/3.)*value_s*value_s*value_s+(cal_b/2.)*value_s*value_s+(cal_c)*value_s);
		double cal_begin_1=((cal_a/3.)*begin*begin*begin+(cal_b/2.)*begin*begin+(cal_c)*begin);
		double cal_end_2=((cal_a/3.)*value_b*value_b*value_b+(cal_b/2.)*value_b*value_b+(cal_c)*value_b);
		double cal_begin_2=((cal_a/3.)*value_s*value_s*value_s+(cal_b/2.)*value_s*value_s+(cal_c)*value_s);
		double cal_end_3=((cal_a/3.)*end*end*end+(cal_b/2.)*end*end+(cal_c)*end);
		double cal_begin_3=((cal_a/3.)*value_b*value_b*value_b+(cal_b/2.)*value_b*value_b+(cal_c)*value_b);
		double cal_1=cal_end_1-cal_begin_1,cal_2=cal_end_2-cal_begin_2,cal_3=cal_end_3-cal_begin_3;
		if(cal_a>0){
			if(begin<=value_s && end>=value_s && end<=value_b){
				return cal_1-cal_2-cal_3;
			}
			else if(begin>=value_s && begin<=value_b && end>=value_b){
				return -cal_1-cal_2+cal_3;
			}
			else if(begin>=value_s && begin<=value_b && end>=value_s && end<=value_b){
				return -cal_1-cal_2-cal_3;
			}
			else{
				return cal_1-cal_2+cal_3;
			}
		}
		else if(cal_a<0){
			if(begin<=value_s && end>=value_s && end<=value_b){
				return -cal_1+cal_2+cal_3;
			}
			else if(begin>=value_s && begin<=value_b && end>=value_b){
				return cal_1+cal_2-cal_3;
			}
			else if(begin>=value_s && begin<=value_b && end>=value_s && end<=value_b){
				return cal_1+cal_2+cal_3;
			}
			else{
				return -cal_1+cal_2-cal_3;
			}
		}
	}
	else if(cal_a==0){
		double cal_end_4=(cal_b/2.)*root*root+(cal_c)*root;
		double cal_begin_4=(cal_b/2.)*begin*begin+(cal_c)*begin;
		double cal_end_5=(cal_b/2.)*end*end+(cal_c)*end;
		double cal_begin_5=(cal_b/2.)*root*root+(cal_c)*root;
		double cal_4=cal_end_4-cal_begin_4,cal_5=cal_end_5-cal_begin_5;
		if(cal_b>0){
			if(begin<=root && end>=root){
				return -cal_4+cal_5;
			}
			else if(begin>=root){
				return cal_4+cal_5;
			}
			else if(end<=root){
				return -cal_4-cal_5;
			}
		}
		else if(cal_b<0){
			if(begin<=root && end>=root){
				return cal_4-cal_5;
			}
			else if(begin>=root){
				return -cal_4-cal_5;
			}
			else if(end<=root){
				return cal_4+cal_5;
			}
		}
	}
}

double calculate_area_riemann_sum(int32_t begin,int32_t end,int32_t n){
	if(end<begin || n<=0){
		printf("Invalid input,error\n");
		return -1.;
	}
	else{
		double sum_passive=0.,sum_negative=0.,interval=((double)(end-begin))/(double)n;
		for(int32_t i=0;i<n;i++){
			double value=interval*(cal_a*(begin+interval*i)*(begin+interval*i)+cal_b*(begin+interval*i)+cal_c);
			if(value>=0){
				sum_passive=sum_passive+value;
			}
			else{
				sum_negative=sum_negative+value;
			}
		}
		return sum_passive-sum_negative;
	}
}

