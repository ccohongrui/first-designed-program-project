#include <stdio.h>
#include <stdint.h>
#include "mirror.h"
static double X1=0.,X2=0.,Y1=0.,Y2=0.;
static double t=0.;
void set_line(double x1,double y1,double x2,double y2){
	if(!(x1==x2&&y1==y2)){
		X1=x1;
		Y1=y1;
		X2=x2;
		Y2=y2;
	}
	else{
		if(X1==0&&Y1==0&&X2==0&&Y2==0){
			printf("Invalid input,error\nNo previous points\n");
		}
		else{
			printf("Invalid input,error\nPrevious point(%lf,%lf),(%lf,%lf)\n",X1,Y1,X2,Y2);
		}
	}

}
int32_t get_mirror(double a,double b,double *c,double *d){
	if(X1==0&&Y1==0&&X2==0&&Y2==0){
			printf("Invalid initial,error\nNo valid line\n");
			return -1;
	}
	else{
		t=((X2-X1)*(Y1-b)+(Y2-Y1)*(a-X1))/((X2-X1)*(X2-X1)+(Y2-Y1)*(Y2-Y1));
		*c=a-2*(Y2-Y1)*t;
		*d=b+2*(X2-X1)*t;
		return 0;
	}
}
