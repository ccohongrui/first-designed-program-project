#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t a,b,c,x,y,z,d,calculate;
	printf("Please enter the first operand : ");
	scanf(" %d %*[x]%n %d",&a,&x,&b);
	printf("Please enter the second operand: ");
	scanf(" %*[y]%n %d %*[z]%n",&y,&c,&z);
	printf("Please enter the sum           : ");
	scanf("%d",&d);
	if(a<0 || b<0 || c<0 || d<0 || a>9 || b>9 || c>9 || d>9 || d>=1999){
		printf("You fill in wrong number\n");
		return 0;
	}
	calculate=d-(a*100)-b-(c*10);
	y=calculate/100;
	x=calculate/10-(calculate/100)*10;
	z=calculate-(calculate/100)*100-((calculate/10-(calculate/100)*10)*10);
	if((x>=0 && x<10) || (y>=0 && y<10) || (z>=0 && z<10)){
		printf("Ans: x=%d, y=%d, z=%d\n",x,y,z);
	}
	else{
		printf("You fill in wrong number\n");
	}
	return 0;
}
