#include "mirror.h"
int main(){
	double X1=0,X2=0,Y1=0,Y2=0,a=0,b=0,c=0,d=0;
	int32_t select=0;
	while(1){
		printf("Selection(1:set line 2: get mirror 3:continue other: break): ");
		scanf("%d",&select);
		if(select==1){
			printf("Please input first point to create line (x1,y1): ");
			scanf("%lf,%lf",&X1,&Y1);
			printf("Please input second point to create line (x2,y2): ");
			scanf("%lf,%lf",&X2,&Y2);
			set_line(X1,Y1,X2,Y2);
		}
		else if(select==2){
			printf("Please input a point (a,b): ");
			scanf("%lf,%lf",&a,&b);
			if(get_mirror(a,b,&c,&d)==0){
				printf("Valid input of get_mirror\n");
				printf("The ans of mirror is (%lf,%lf)\n",c,d);
			}
			else{
				printf("Invalid input of get_mirror\n");
			}
		}
		else if(select==3){
			continue;
		}
		else{
			break;
		}
	}
	return 0;
}
