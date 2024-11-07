#include <stdio.h>
#include <math.h>
#include <stdint.h>
void drive(double *x,double *y,double *degree);
void reverse(double *x,double *y,double *degree);
void turn_right(double *x,double *y,double *degree);
void turn_left(double *x,double *y,double *degree);

int main(){
	double x=0.,y=0.,degree=M_PI/2,end_x,end_y;
	int32_t choice;
	printf("Please enter the destination x,y : ");
	scanf("%lf,%lf",&end_x,&end_y);
	while (1) {
        	printf("Car is at (%.2lf, %.2lf)\n",x,y);
        	printf("Control Panel:\n");
        	printf("1) Parking\n");
		printf("2) Drive\n");
		printf("3) Reverse\n");
		printf("4) Turn Right\n");
		printf("5) Turn Left\n");
		printf("Your Choice: ");
		scanf("%d", &choice);
		switch(choice){
			case 2:drive(&x,&y,&degree);break;
			case 3:reverse(&x,&y,&degree);break;
			case 4:turn_right(&x,&y,&degree);break;
			case 5:turn_left(&x,&y,&degree);break;
		}
		printf("=====\n");
		if((x>=end_x-0.5 && x<=end_x+0.5) && (y>=end_y-0.5 && y<=end_y+0.5)){
			printf("Arrived\n");
			break;
		}
	}
	return 0;
}
void drive(double *x,double *y,double *degree){
	double velocity,hour;
	printf("Velocity (km/hr): ");
	scanf("%lf",&velocity);
	printf("Duration (hr): ");
	scanf("%lf",&hour);
	*x=*x+velocity*hour*cos(*degree);
	*y=*y+velocity*hour*sin(*degree);
	return;
}
void reverse(double *x,double *y,double *degree){
	double velocity,hour;
	printf("Velocity (km/hr): ");
	scanf("%lf",&velocity);
	printf("Duration (hr): ");
	scanf("%lf",&hour);
	*x=*x+velocity*hour*cos(*degree-M_PI);
	*y=*y+velocity*hour*sin(*degree-M_PI);
	return;
}
void turn_right(double *x,double *y,double *degree){
	double deg;
	printf("Degree: ");
	scanf("%lf",&deg);
	*degree=*degree-deg/180*M_PI;
	return;
}
void turn_left(double *x,double *y,double *degree){
	double deg;
	printf("Degree: ");
	scanf("%lf",&deg);
	*degree=*degree+deg/180*M_PI;
	return;
}

