#include <stdio.h>
#include <stdint.h>
int main(){
	double input_x=0.,n=0.,sumx=0.,sumy=0.,sumx_x=0.;
	double input_y=0.,sum_xy=0.,average_x,average_y,forecast;
	int32_t a=0;
	do{
		printf("Please enter the year: ");
		scanf("%lf",&input_x);
		if(input_x<1 && input_x!=-1){
			printf("no data before Christ,input>=1 please re-input\n");
			continue;
		}
		input_x=input_x/100;
		if(input_x==-0.01){
			break;
		}
		printf("Temperature: ");
		scanf("%lf",&input_y);
		if(input_y<-273.15){
			printf("no temperature under absolute zero,input>=-273.15 please re-input\n");
			continue;
		}
		a++;
		n++;
		sumx_x=sumx_x+input_x*input_x;
		sumx=sumx+input_x;
		sum_xy=sum_xy+input_y*input_x;
		sumy=sumy+input_y;
	}while(1);
	if(a==0){
		printf("You don't fill in any answer,error :( \n");
		return 0;
	}
	else if(a==1){
		printf("You just fill in one answer,error :( \n");
		return 0;
	}
	average_x=(double)sumx/n;
	average_y=(double)sumy/n;
	printf("Please enter the prediction year: ");
	scanf("%lf",&input_x);
	forecast=sum_xy-(n*average_x*average_y);
        printf("Temperature: %.6lf\n",forecast/(sumx_x-n*average_x*average_x)*(input_x/100.-average_x)+average_y);
	return 0;
}
