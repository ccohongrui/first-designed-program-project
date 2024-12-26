#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
int32_t main(){
	int8_t player_database[5][5]={0},computer_database[5][5]={0},row=0,column=0;
	for(int32_t i=0;i<25;i++){
		while(1){
			printf("Setup %02d: ",i+1);
			scanf("%hhd,%hhd",&row,&column);
			if(row>=1&&row<=5&&column>=1&&column<=5&&player_database[row-1][column-1]==0){
				player_database[row-1][column-1]=i+1;
				break;
			}
			else{
				printf("Invalid input,re-input\nReapeated position or Out of range\n");
			}
		}
	}
	/*	
	for(int32_t i=0;i<25;i++){
		player_database[i/5][i%5]=i+1;
	}
	int32_t f=777,space01,random01;
	for(int32_t i=0;i<25;i++){
		srand(time(NULL)+f);
		f++;
		random01=rand()%25;
		space01=player_database[i/5][i%5];
		player_database[i/5][i%5]=player_database[random01/5][random01%5];
		player_database[random01/5][random01%5]=space01;	
	}
	*/
	for(int32_t i=0;i<25;i++){
		computer_database[i/5][i%5]=i+1;
	}
	int32_t a=0,space,random;
	for(int32_t i=0;i<25;i++){
		srand(time(NULL)+a);
		a++;
		random=rand()%25;
		space=computer_database[i/5][i%5];
		computer_database[i/5][i%5]=computer_database[random/5][random%5];
		computer_database[random/5][random%5]=space;	
	}
	printf("===\n");
	for(int32_t i=0;i<5;i++){
		for(int32_t j=0;j<5;j++){
			printf("%02hhd ",player_database[i][j]);
		}
		printf("|");
		for(int32_t j=0;j<5;j++){
			printf(" xx");
		}
		printf("\n");
	}
	printf("===\n");
	int8_t choice[25]={0},player_lines[5][5]={0},computer_lines[5][5]={0};
	int32_t b=0,e=0;
	for(int32_t i=0;i<25;i++){
		int32_t c=0,d=0;
		if(i%2==0){
			do{
				b=0;
				printf("Player's choice: ");
				scanf("%02hhd",&choice[i]);
				for(int32_t j=0;j<25;j++){
					if((choice[i]<1||choice[i]>25)||(i!=j&&choice[i]==choice[j])){
						printf("Invalid input,re-input\nReapeated position or Out of range\n");
						b=1;
						break;
					}
				}
			}while(b==1);
		}
		else if(i%2==1){
			do{
				b=0;
				srand(time(NULL)+e);
				e++;
				choice[i]=rand()%25+1;
				for(int32_t j=0;j<25;j++){
					if((i!=j&&choice[i]==choice[j])){
						b=1;
					}
				}
			}while(b==1);
			printf("Computer's choice: %02hhd\n",choice[i]);
		}
		printf("===\n");
		for(int32_t j=0;j<5;j++){
			for(int32_t k=0;k<5;k++){
				int32_t b=0;
				for(int32_t l=0;l<25;l++){
					if(player_database[j][k]==choice[l]){
						printf("\033[38;2;255;255;0m%02hhd \033[0m",player_database[j][k]);
						player_lines[j][k]=1;
						b=1;
					}
				}
				if(b==0){
					printf("%02hhd ",player_database[j][k]);
				}
			}
			printf("|");
			for(int32_t k=0;k<5;k++){
				int32_t b=0;
				for(int32_t l=0;l<25;l++){
					if(computer_database[j][k]==choice[l]){
						printf("\033[38;2;255;255;0m %02hhd\033[0m",computer_database[j][k]);
						computer_lines[j][k]=1;
						b=1;
					}
				}
				if(b==0){
					printf(" xx");
				}
			}
			printf("\n");
		}
		printf("===\n");
		for(int32_t j=0;j<5;j++){
			if(computer_lines[j][0]==1&&computer_lines[j][1]==1&&computer_lines[j][2]==1){
				if(computer_lines[j][3]==1&&computer_lines[j][4]==1){
					d++;
				}
			}
			if(player_lines[j][0]==1&&player_lines[j][1]==1&&player_lines[j][2]==1){
				if(player_lines[j][3]==1&&player_lines[j][4]==1){
					c++;
				}
			}
		}
		for(int32_t j=0;j<5;j++){
			if(computer_lines[0][j]==1&&computer_lines[1][j]==1&&computer_lines[2][j]==1){
				if(computer_lines[3][j]==1&&computer_lines[4][j]==1){
					d++;
				}
			}
			if(player_lines[0][j]==1&&player_lines[1][j]==1&&player_lines[2][j]==1){
				if(player_lines[3][j]==1&&player_lines[4][j]==1){
					c++;
				}
			}
		}
		if(computer_lines[0][0]==1&&computer_lines[1][1]==1&&computer_lines[2][2]==1){
			if(computer_lines[3][3]==1&&computer_lines[4][4]==1){
				d++;
			}
		}
		if(player_lines[0][0]==1&&player_lines[1][1]==1&&player_lines[2][2]==1){
			if(player_lines[3][3]==1&&player_lines[4][4]==1){
				c++;
			}
		}
		if(computer_lines[0][4]==1&&computer_lines[1][3]==1&&computer_lines[2][2]==1){
			if(computer_lines[3][1]==1&&computer_lines[4][0]==1){
				d++;
			}
		}
		if(player_lines[0][4]==1&&player_lines[1][3]==1&&player_lines[2][2]==1){
			if(player_lines[3][1]==1&&player_lines[4][0]==1){
				c++;
			}
		}
		if(c>=3&&d>=3&&c==d){
			printf("Draw\n");
			break;
		}
		else if(c>=3&&c>d){
			printf("The winner is Player\n");
			break;
		}
		else if(d>=3&&d>c){
			printf("The winner is Computer\n");
			break;
		}
	}
	return 0;
}




