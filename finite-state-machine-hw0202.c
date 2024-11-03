#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t S0=-1,S1=-1,S2=-1,S3=-1,S4=-1,S5=-1,S6=-1,S7=-1;
	while(1){
		if((S0!=0&&S0!=1&&S0!=2&&S0!=3&&S0!=4)&&(S1!=0&&S1!=1&&S1!=2&&S1!=3&&S1!=4)&&(S2!=0&&S2!=1&&S2!=2&&S2!=3&&S2!=4)
		&&(S3!=0&&S3!=1&&S3!=2&&S3!=3&&S3!=4)&&(S4!=0&&S4!=1&&S4!=2&&S4!=3&&S4!=4)&&(S5!=0&&S5!=1&&S5!=2&&S5!=3&&S5!=4)
		&&(S6!=0&&S6!=1&&S6!=2&&S6!=3&&S6!=4)&&(S7!=0&&S7!=1&&S7!=2&&S7!=3&&S7!=4)){
			printf("(In S0 case)Please enter DNA base: ");
			scanf("%d",&S0);
			if(S0!=0 && S0!=1 && S0!=2 && S0!=3 && S0!=4){ // S0
				printf("Wrong base,please re-input\n");
			}
			if(S0==0){
				printf("The state is in S0 , the sequence does not satisfy the pattern .\n");
				break;
			}
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S0==1 || S0==3){ // S1
			S0=-1;
			printf("(In S1 case)Please enter DNA base: ");
			scanf("%d",&S1);
			if(S1!=0 && S1!=1 && S1!=2 && S1!=3 && S1!=4){
				printf("Wrong base,please re-input\n");
			}
		if(S1==0){
			printf("The state is in S1 , the sequence does not satisfy the pattern .\n");
			break;
		}
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S0==2 || S0==4 || S3==1){
			S0=-1;S3=-1;
			do{ // S2
				printf("(In S2 case)Please enter DNA base: ");
				scanf("%d",&S2);
				if(S2!=0 && S2!=1 && S2!=2 && S2!=3 && S2!=4){
					printf("Wrong base,please re-input\n");
				}
			}while(S2==3);
			if(S2==0){
				printf("The state is in S2 , the sequence does not satisfy the pattern .\n");
				break;
			}
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S1==1 || S1==3 || S1==4 || S6==1){
			S1=-1;S6=-1;
			do{ // S3
				printf("(In S3 case)Please enter DNA base: ");
				scanf("%d",&S3);
				if(S3!=0 && S3!=1 && S3!=2 && S3!=3 && S3!=4){
					printf("Wrong base,please re-input\n");
				}
			}while(S3==2);
			if(S3==0){
				printf("The state is in S3 , the sequence does not satisfy the pattern .\n");
				break;
			}
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S1==2 || S2==1 || S2==2 || S2==4){
			S1=-1;S2=-1;
			// S4
				printf("(In S4 case)Please enter DNA base: ");
				scanf("%d",&S4);
				if(S4!=0 && S4!=1 && S4!=2 && S4!=3 && S4!=4){
					printf("Wrong base,please re-input\n");
				}
			if(S4==0){
				printf("The state is in S4 , the sequence does not satisfy the pattern .\n");
				break;
			}
			continue;
		}	
		/////////////////////////////////////////////////////////////////////////////////////
		if(S3==3 || S3==4 || S4==2 || S4==3 || S6==3){
			S3=-1;S4=-1;S6=-1;
			do{ // S5
				printf("(In S5 case)Please enter DNA base: ");
				scanf("%d",&S5);
				if(S5!=0 && S5!=1 && S5!=2 && S5!=3 && S5!=4){
					printf("Wrong base,please re-input\n");
				}
			}while(S5==1 || S5==4);
			if(S5==0){
				printf("The state is in S5 , the sequence does not satisfy the pattern .\n");
				break;
			}
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S4==1 || S4==4){
			S4=-1;
			do{ // S6
				printf("(In S6 case)Please enter DNA base: ");
				scanf("%d",&S6);
				if(S6!=0 && S6!=1 && S6!=2 && S6!=3 && S6!=4){
					printf("Wrong base,please re-input\n");
				}
			}while(S6==2 || S6==4);
			if(S6==0){
				printf("The state is in S6 , the sequence does not satisfy the pattern .\n");
				break;
			}
			continue;
		}
		/////////////////////////////////////////////////////////////////////////////////////
		if(S5==2 || S5==3){
			S5=-1;
			do{ // S7
				printf("(In S7 case)PPlease enter DNA base: ");
				scanf("%d",&S7);
				if(S7!=0 && S7!=1 && S7!=2 && S7!=3 && S7!=4){
					printf("Wrong base,please re-input\n");
				}		
			}while(S7==1 || S7==2 || S7==3 || S7==4);
			if(S7==0){
				printf("The state is in S7 , the sequence satisfies the pattern .\n");
				break;
			}
		}
	}
	return 0;
}
