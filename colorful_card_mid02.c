#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t width,height,n;
	int32_t a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0;
	printf("Please enter the card size (width,height): ");
	scanf("%d,%d",&width,&height);
	printf("Please enter the card number: ");
	scanf("%d",&n);
	for(int32_t i=1;i<=height+n-1;i++){
		for(int32_t j=1;j<=width+n-1;j++){
			if(j>=n-a && j<=width+n-1-a && i<=n){
				if((j==n-a || j==width+n-1-a)&&(i-1)%4==0){printf("\033[38;2;255;0;0m+\033[0m");}
				else if((i-1)%4==0){printf("\033[38;2;255;0;0m-\033[0m");}
				if((j==n-a || j==width+n-1-a)&&(i-2)%4==0){printf("\033[38;2;0;0;255m+\033[0m");}
				else if((i-2)%4==0){printf("\033[38;2;0;0;255m-\033[0m");}
				if((j==n-a || j==width+n-1-a)&&(i-3)%4==0){printf("\033[38;2;0;255;0m+\033[0m");}
				else if((i-3)%4==0){printf("\033[38;2;0;255;0m-\033[0m");}
				if((j==n-a || j==width+n-1-a)&&(i-4)%4==0){printf("\033[38;2;255;165;0m+\033[0m");}
				else if((i-4)%4==0){printf("\033[38;2;255;165;0m-\033[0m");}
			}
			else if(j==width+n-1-b && j>=width){
				if(i==height+c){printf("\033[38;2;255;0;0m+\033[0m");}
				else{printf("\033[38;2;255;0;0m|\033[0m");}
			}
			else if(j==width+n-2-d && j>=width){
				if(i==height+1+e){printf("\033[38;2;0;0;255m+\033[0m");}
				else{printf("\033[38;2;0;0;255m|\033[0m");}
			}
			else if(j==width+n-3-f && j>=width){
				if(i==height+2+g){printf("\033[38;2;0;255;0m+\033[0m");}
				else{printf("\033[38;2;0;255;0m|\033[0m");}
			}
			else if(j==width+n-4-h && j>=width){
				if(i==height+3+k){printf("\033[38;2;255;165;0m+\033[0m");}
				else{printf("\033[38;2;255;165;0m|\033[0m");}
			}
			else if(i>=n+1 && i<=height+n-2 &&j==1 && (n-1)%4==0){printf("\033[38;2;255;0;0m|\033[0m");}
			else if(i>=n+1 && i<=height+n-2 &&j==1 && (n-2)%4==0){printf("\033[38;2;0;0;255m|\033[0m");}
			else if(i>=n+1 && i<=height+n-2 &&j==1 && (n-3)%4==0){printf("\033[38;2;0;255;0m|\033[0m");}
			else if(i>=n+1 && i<=height+n-2 &&j==1 && (n-4)%4==0){printf("\033[38;2;255;165;0m|\033[0m");}
			else if(i==height+n-1 && j<=width && (n-1)%4==0){
				if(j==1 || j==width){printf("\033[38;2;255;0;0m+\033[0m");}
				else{printf("\033[38;2;255;0;0m-\033[0m");}
			}
			else if(i==height+n-1 && j<=width && (n-2)%4==0){
				if(j==1 || j==width){printf("\033[38;2;0;0;255m+\033[0m");}
				else{printf("\033[38;2;0;0;255m-\033[0m");}
			}
			else if(i==height+n-1 && j<=width && (n-3)%4==0){
				if(j==1 || j==width){printf("\033[38;2;0;255;0m+\033[0m");}
				else{printf("\033[38;2;0;255;0m-\033[0m");}
			}
			else if(i==height+n-1 && j<=width && (n-4)%4==0){
				if(j==1 || j==width){printf("\033[38;2;255;165;0m+\033[0m");}
				else{printf("\033[38;2;255;165;0m-\033[0m");}
			}
			else{printf(" ");}
		}
		printf("\n");
		a++;
		if(i==height+c){b=b+4;c=c+4;}
		if(i==height+1+e){d=d+4;e=e+4;}
		if(i==height+2+g){f=f+4;g=g+4;}
		if(i==height+3+k){h=h+4;k=k+4;}
	}







	return 0;
}
