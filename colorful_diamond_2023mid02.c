#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t n,l,a=0,b=0,c=0,d,e=0,f=1,g=2;
	printf("Please enter n: ");
	scanf("%d",&n);
	printf("Please enter the edge length: ");
	scanf("%d",&l);
for(int32_t m=1;m<=2*n-1;m++){
	for(int32_t k=1;k<=l+2;k++){
		a=0;b=0,e=0,f=1,g=2;
		for(int32_t j=1;j<=2*n-1;j++){
			if((k==1 && m<=n && j<=n) || (k==l+2 && m>=n && j<=n)){
				if(j>=n-c && j<=n+c){printf("+");}
				else{printf(" ");}
			}
			else if((k==1 && m>n) || (k==l+2 && m<n)){}
			else{
				if(j>n){}
				else{
					if(j>=n-c && j<=n+c){printf("|");}
					else{printf(" ");}
				}
			}
			for(int32_t i=1;i<=2*l;i++){
				if((k==1 && m<=n) || (k==l+2 && m>=n)){
					if(j>=n-c && j<=n+c){printf("-");}
					else{printf(" ");}
				}
				else if((k==1 && m>n) || (k==l+2 && m<n)){}
				else if(j>=n-c && j<=n+c){
					if(a/(2*l)==e+b){printf("\033[48;2;255;0;0m \033[0m");}
					if(a/(2*l)==f+b){printf("\033[48;2;0;255;0m \033[0m");}
					if(a/(2*l)==g+b){printf("\033[48;2;0;0;255m \033[0m");}
					a++;
					if(a%(6*l)==0){b=b+3;}
					if(j==n){
						d=((a-1)/(2*l))%3;
						if(d==0){e=0;f=2;g=1;}
						if(d==1){e=2;f=1;g=0;}
						if(d==2){e=1;f=0;g=2;}
					}
				}
				else{printf(" ");}
			}
			if((k==1 && m<=n && j>=n) || (k==l+2 && m>=n && j>=n)){
				if(j>=n-c && j<=n+c){printf("+");}
				else{printf(" ");}
							
			}
			else if((k==1 && m>n) || (k==l+2 && m<n)){}
			else{
				if(j<n){}
				else{
					if(j>=n-c && j<=n+c){printf("|");}
					else{printf(" ");}
				}
			}
		}
		if(!((k==1 && m>n) || (k==l+2 && m<n))){		
			printf("\n");
		}	
	}
	if(m<n){c++;}
	else{c--;}
}
return 0;
}

