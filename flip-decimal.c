#include <stdio.h>
#include <stdint.h>
int main(){
	uint32_t num,a,b,c,d,e,f,num1;
	printf("Please enter an unsigned 16-bits number: ");
	scanf("%d",&num);
	printf("Before Flip: \n");
	a=num%8;
	b=(num/8)%8;
	c=(num/64)%8;
	d=(num/512)%8;
	e=(num/4096)%8;
	f=(num/32768)%8;
	num1=f*100000+e*10000+d*1000+c*100+b*10+a;
	printf("%d_10 = %d_8\n",num,num1);
	printf("After Flip: \n");
	if(b==0 && c==0 && d==0 && e==0 && f==0){
		num=num1=a;
	}
	else if(c==0 && d==0 && e==0 && f==0){
		num1=a*10+b;
		num=a*8+b;
	}
	else if(d==0 && e==0 && f==0){
		num1=a*100+b*10+c;
		num=a*64+b*8+c;
	}
	else if(e==0 && f==0){
		num1=a*1000+b*100+c*10+d;
		num=a*512+b*64+c*8+d;
	}
	else if(f==0){
		num1=a*10000+b*1000+c*100+d*10+e;
		num=a*4096+b*512+c*64+d*8+e;
	}
	else{
		num1=a*100000+b*10000+c*1000+d*100+e*10+f;
		num=a*32768+b*4096+c*512+d*64+e*8+f;
	}
	if(num<=65536 && num>=0)
		printf("%d_8 = %d_10\n",num1,num);
	else{
		printf("Flip overflow 16bit\n");
		printf("%d_8 = %d_10\n",num1,num);
	}
	return 0;
}

		
