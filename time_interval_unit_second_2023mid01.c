#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t year_s,month_s,day_s,hour_s,min_s,sec_s;
	int32_t year_e,month_e,day_e,hour_e,min_e,sec_e;
	int32_t duration,year,year_1,year_2,month_1,month_2,month,day,hour,min,sec;
	int32_t a=0,b=0,c=0;
	printf("Start time: ");
	scanf("%d-%d-%d %d:%d:%d",&year_s,&month_s,&day_s,&hour_s,&min_s,&sec_s);
	printf("End time: ");
	scanf("%d-%d-%d %d:%d:%d",&year_e,&month_e,&day_e,&hour_e,&min_e,&sec_e);
	if(year_e>=year_s){year_2=year_e;year_1=year_s;}
	else{year_2=year_s;year_1=year_e;}
	for(int32_t i=year_1;i<year_2;i++){
		if(i%4==0){
			if(i%100!=0){a++;}
			else if(i%400==0){a++;}
		}
	}
	if(year_e%4==0){
		if(year_e%100!=0){c++;}
		else if(year_e%400==0){c++;}
	}
	if(year_s%4==0){
		if(year_s%100!=0){b++;}
		else if(year_s%400==0){b++;}
	}
	if(year_e-year_s<0){year=(year_e-year_s+a)*365*24*60*60-a*366*24*60*60;}
	else{year=(year_e-year_s-a)*365*24*60*60+a*366*24*60*60;}
	for(int32_t i=1;i<month_s;i++){
		if(i==2 && b==1){month_1=month_1+29;}
		else if(i==2){month_1=month_1+28;}
		else if(i==8){month_1=month_1+31;}
		else if(i%2==0){month_1=month_1+30;}
		else if(i%2==1){month_1=month_1+31;}
	}
	for(int32_t i=1;i<month_e;i++){
		if(i==2 && c==1){month_2=month_2+29;}
		else if(i==2){month_2=month_2+28;}
		else if(i==8){month_2=month_2+31;}
		else if(i%2==0){month_2=month_2+30;}
		else if(i%2==1){month_2=month_2+31;}
	}
	month=(month_2-month_1)*24*60*60;
	day=(day_e-day_s)*24*60*60;
	hour=(hour_e-hour_s)*60*60;
	min=(min_e-min_s)*60;
	sec=(sec_e-sec_s);
	duration=year+month+day+hour+min+sec;
	if(duration<0){duration=-duration;}
	printf("Duration: %d sec\n",duration);
	return 0;
}
