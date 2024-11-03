#include <stdio.h>
#include <stdint.h>
int main(){
	double ratio=1;
	uint32_t max;
	printf("Please enter n (16 - bits unsigned ): ");
	scanf("%u",&max);
	if(max==0){
		printf("n = 0: no answer\n");
		return 0;
	}
	printf("n = 1 : 1.00000000000000000000 (0.61803398874989484820)\n");
	for(uint32_t i=1;i<max;i++)
	{
		ratio=1+1/ratio;
		printf("n = %u : %.20lf (%.20lf)\n",i+1,ratio,1.61803398874989484820-ratio);
	}
	return 0;
}
