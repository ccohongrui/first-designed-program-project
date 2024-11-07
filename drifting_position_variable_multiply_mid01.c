#include <stdio.h>
#include <stdint.h>
int main(){
	char numf1,numf2,numf3;//輸入
	char nums1,nums2,nums3;//輸入
	char nump1,nump2,nump3,nump4,nump5;//輸入
	int32_t num1,num2,num3,numa,numb,numc,numd;//倍率跟計算
	int32_t e=1;
	printf("Please enter the first operand: ");
	scanf("%c%c%c",&numf1,&numf2,&numf3);
	printf("Please enter the second operand: ");
	scanf(" %c%c%c",&nums1,&nums2,&nums3);
	printf("Please enter the product: ");
	scanf(" %c%c%c%c%c",&nump1,&nump2,&nump3,&nump4,&nump5);
	if(numf1=='a'){numa=100;num1=((int)(numf2-'0'))*10+(int)(numf3-'0');}
	if(numf2=='a'){numa=10;num1=((int)(numf1-'0'))*100+(int)(numf3-'0');}
	if(numf3=='a'){numa=1;num1=((int)(numf1-'0'))*100+((int)(numf2-'0'))*10;}
	if(nums1=='b'){numb=100;num2=((int)(nums2-'0'))*10+(int)(nums3-'0');}
	if(nums2=='b'){numb=10;num2=((int)(nums1-'0'))*100+(int)(nums3-'0');}
	if(nums3=='b'){numb=1;num2=((int)(nums1-'0'))*100+((int)(nums2-'0'))*10;}
	if(nump1=='c' && nump3=='d'){numc=10000;numd=100;num3=((int)(nump2-'0'))*1000+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump1=='d' && nump3=='c'){numc=100;numd=10000;num3=((int)(nump2-'0'))*1000+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump1=='c' && nump4=='d'){numc=10000;numd=10;num3=((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100+(int)(nump5-'0');}
	if(nump1=='d' && nump4=='c'){numc=10;numd=10000;num3=((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100+(int)(nump5-'0');}
	if(nump1=='c' && nump5=='d'){numc=10000;numd=1;num3=((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100+((int)(nump4-'0'))*10;}
	if(nump1=='d' && nump5=='c'){numc=1;numd=10000;num3=((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100+((int)(nump4-'0'))*10;}
	if(nump2=='c' && nump4=='d'){numc=1000;numd=10;num3=((int)(nump1-'0'))*10000+((int)(nump3-'0'))*100+(int)(nump5-'0');}
	if(nump2=='d' && nump4=='c'){numc=10;numd=1000;num3=((int)(nump1-'0'))*10000+((int)(nump3-'0'))*100+(int)(nump5-'0');}
	if(nump2=='c' && nump5=='d'){numc=1000;numd=1;num3=((int)(nump1-'0'))*10000+((int)(nump3-'0'))*100+((int)(nump4-'0'))*10;}
	if(nump2=='d' && nump5=='c'){numc=1;numd=1000;num3=((int)(nump1-'0'))*10000+((int)(nump3-'0'))*100+((int)(nump4-'0'))*10;}
	if(nump3=='c' && nump5=='d'){numc=100;numd=1;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+((int)(nump4-'0'))*10;}
	if(nump3=='d' && nump5=='c'){numc=1;numd=100;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+((int)(nump4-'0'))*10;}
	if(nump1=='c' && nump2=='d'){numc=10000;numd=1000;num3=((int)(nump3-'0'))*100+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump1=='d' && nump2=='c'){numc=1000;numd=10000;num3=((int)(nump3-'0'))*100+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump2=='c' && nump3=='d'){numc=1000;numd=100;num3=((int)(nump1-'0'))*10000+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump2=='d' && nump3=='c'){numc=100;numd=1000;num3=((int)(nump1-'0'))*10000+((int)(nump4-'0'))*10+(int)(nump5-'0');}
	if(nump3=='c' && nump4=='d'){numc=100;numd=10;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+(int)(nump5-'0');}
	if(nump3=='d' && nump4=='c'){numc=10;numd=100;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+(int)(nump5-'0');}
	if(nump4=='c' && nump5=='d'){numc=10;numd=1;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100;}
	if(nump4=='d' && nump5=='c'){numc=1;numd=10;num3=((int)(nump1-'0'))*10000+((int)(nump2-'0'))*1000+((int)(nump3-'0'))*100;}
	printf("Solution :\n");
	for(int32_t a=0;a<=9;a++){
		for(int32_t b=0;b<=9;b++){
			for(int32_t c=0;c<=9;c++){
				for(int32_t d=0;d<=9;d++){
					if((num1+a*numa)*(num2+b*numb)==(num3+d*numd+c*numc)){
						printf("%d. a=%d b=%d c=%d d=%d\n",e,a,b,c,d);
						e++;
					}
				}
			}
		}
	}
	return 0;
}
