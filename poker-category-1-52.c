#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t num1,num2,num3,num4,num5,space;
	printf("Please enter 5 cards: ");
	scanf("%d%d%d%d%d",&num1,&num2,&num3,&num4,&num5);
	if(num1>=num2){
		space=num1;
		num1=num2;
		num2=space;
	}
	if(num1>=num3){
		space=num1;
		num1=num3;
		num3=space;
	}
	if(num1>=num4){
		space=num1;
		num1=num4;
		num4=space;
	}
	if(num1>=num5){
		space=num1;
		num1=num5;
		num5=space;
	}
	if(num2>=num3){
		space=num2;
		num2=num3;
		num3=space;
	}
	if(num2>=num4){
		space=num2;
		num2=num4;
		num4=space;
	}
	if(num2>=num5){
		space=num2;
		num2=num5;
		num5=space;
	}
	if(num3>=num4){
		space=num3;
		num3=num4;
		num4=space;
	}
	if(num3>=num5){
		space=num3;
		num3=num5;
		num5=space;
	}
	if(num4>=num5){
		space=num4;
		num4=num5;
		num5=space;
	}
	if(num1==num2 || num2==num3 || num3==num4 || num4==num5){
		printf("Error\n");
		return 0;
	}
	if(num1>52 || num2>52 || num3>52 || num4>52 || num5>52 || num1<1 || num2<1 || num3<1 || num4<1 || num5<1){
		printf("Error\n");
		return 0;
	}
	if((num1-1)/13==(num2-1)/13 && (num2-1)/13==(num3-1)/13 && (num3-1)/13==(num4-1)/13 && (num4-1)/13==(num5-1)/13){
		if((num1+1)==num2 && (num2+1)==num3 && (num3+1)==num4 && (num4+1)==num5){
			printf("Straight Flush\n");
			return 0;
		}
		else if(num1%13==1 && num2%13==10 && num3%13==11 && num4%13==12 && num5%13==0){
			printf("Straight Flush\n");
			return 0;
		}
		else{
			printf("Flush\n");
			return 0;
		}
	}
	num1=num1%13;
	num2=num2%13;
	num3=num3%13;
	num4=num4%13;
	num5=num5%13;
	if(num1>=num2){
		space=num1;
		num1=num2;
		num2=space;
	}
	if(num1>=num3){
		space=num1;
		num1=num3;
		num3=space;
	}
	if(num1>=num4){
		space=num1;
		num1=num4;
		num4=space;
	}
	if(num1>=num5){
		space=num1;
		num1=num5;
		num5=space;
	}
	if(num2>=num3){
		space=num2;
		num2=num3;
		num3=space;
	}
	if(num2>=num4){
		space=num2;
		num2=num4;
		num4=space;
	}
	if(num2>=num5){
		space=num2;
		num2=num5;
		num5=space;
	}
	if(num3>=num4){
		space=num3;
		num3=num4;
		num4=space;
	}
	if(num3>=num5){
		space=num3;
		num3=num5;
		num5=space;
	}
	if(num4>=num5){
		space=num4;
		num4=num5;
		num5=space;
	}
	if(num1+1==num2 && num2+1==num3 && num3+1==num4 && num4+1==num5){ //順子
		printf("Straight\n");
		return 0;
	}
	else if((num1==0 && num2==1 && num3==10 && num4==11 && num5==12)||(num1==0 && num2==9 && num3==10 && num4==11 && num5==12)){
		printf("Straight\n");
		return 0;
	}
	if(num1==num2 || num2==num3 || num3==num4 || num4==num5){ 
		if(num1==num3 || num2==num4 || num3==num5){ 
			if((num1==num3 && num4==num5) || (num3==num5 && num1==num2)){ //葫蘆
				printf("Full House\n");
				return 0;
			}
			else if(num1==num4 || num2==num5){ //鐵支
				printf("Four Of A Kind\n");
				return 0;
			}
			else{
				printf("Three Of A Kind\n"); //三條
				return 0;
			}
		}
		else if((num1==num2 && num3==num4) || (num1==num2) && (num4==num5) || (num2==num3 && num4==num5)){ //二個二個相同
			printf("Two Pair\n");
			return 0;
		}
		else{
			printf("One Pair\n"); //二個相同
			return 0;
		}
	}
	else{
		printf("High Card\n");//單支
		return 0;
	}
}
		
