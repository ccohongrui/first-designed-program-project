#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t num1,num2,num3,num4,num1a,num1b,num1c,num1d,num2a,num2b,num2c,num2d,num3a,num3b,num3c,num3d,num4a,num4b,num4c,num4d;
	int32_t type,calculate,index,consequence;
	float decimal;
	printf("Please input a hex: ");
	scanf("%1X%1X%1X%1X",&num1,&num2,&num3,&num4);
	num1d=num1%2;
	num1c=(num1/2)%2;
	num1b=(num1/4)%2;
	num1a=(num1/8)%2;
	num2d=num2%2;
	num2c=(num2/2)%2;
	num2b=(num2/4)%2;
	num2a=(num2/8)%2;
	num3d=num3%2;
	num3c=(num3/2)%2;
	num3b=(num3/4)%2;
	num3a=(num3/8)%2;
	num4d=num4%2;
	num4c=(num4/2)%2;
	num4b=(num4/4)%2;
	num4a=(num4/8)%2;
	calculate=num1a*32768+num1b*16384+num1c*8192+num1d*4096+num2a*2048+num2b*1024+num2c*512+num2d*256;
	calculate=calculate+num3a*128+num3b*64+num3c*32+num3d*16+num4a*8+num4b*4+num4c*2+num4d;
	printf("Please choose the output type(1:integer ,2:unsigned integer ,3:float): ");
	scanf("%d",&type);
	printf("Binary of %X%X%X%X is: %d%d%d%d ",num1,num2,num3,num4,num1a,num1b,num1c,num1d);
	printf("%d%d%d%d %d%d%d%d %d%d%d%d\n",num2a,num2b,num2c,num2d,num3a,num3b,num3c,num3d,num4a,num4b,num4c,num4d);
	if(type==1){
		if(calculate>32767 && calculate<65536){
			printf("Converted integer is: %d\n",calculate-65536);
			return 0;
		}
		else if(calculate<=32767 && calculate>=0){
			printf("Converted integer is: %d\n",calculate);
			return 0;
		}
		else{
			printf("Error");
			return 0;
		}	
	}
	if(type==2){
		printf("Converted unsigned integer is: %d\n",calculate);
		return 0;
	}
	if(type==3){
		index=num1b*16+num1c*8+num1d*4+num2a*2+num2b-15;
		decimal=num2c*(1/2.)+num2d*(1/4.)+num3a*(1/8.)+num3b*(1/16.)+num3c*(1/32.)+num3d*(1/64.);
		decimal=decimal+num4a*(1/128.)+num4b*(1/256.)+num4c*(1/512.)+num4d*(1/1024.);
		if(num2==0 && num3==0 && num4==0){
			if(num1==0){
				printf("Converted float is: +0.000000\n");
				return 0;
			}
			if(num1==8){
				printf("Converted float is: -0.000000\n");
				return 0;
			}
		}
		if(num1b==1 && num1c==1 && num1d==1 && num2a==1 && num2b==1){
			if(num1a==0 && num2c==0 && num2d==0 && num3==0 && num4==0){
				printf("Converted float is: +INT\n");
				return 0;
			}
			else if(num1a==1 && num2c==0 && num2d==0 && num3==0 && num4==0) {
				printf("Converted float is: -INT\n");
				return 0;
			}
			else{
				printf("Converted float is: NAN\n");
				return 0;
			}
		}
		else if(num1a==0){
			printf("Converted float is: %.6f*2^%d\n",1+decimal,index);
			return 0;
		}
		else if(num1a==1){
			printf("Converted float is: -%.6f*2^%d\n",1+decimal,index);
			return 0;
		}
	}
	else{
		printf("Fill in error type\n");
		return 0;
	}

}
