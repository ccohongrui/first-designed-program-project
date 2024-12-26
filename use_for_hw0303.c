#include "mygcd.h"
#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t selection,a,b;
	printf("Input (a,b) of gcd : ");
	scanf("%d,%d",&a,&b);
	printf("Input selection(No print: 0 Mathematical print: 1 Vertical print: 2): ");
	scanf("%d",&selection);
	gcd(selection,a,b);
	return 0;
}
