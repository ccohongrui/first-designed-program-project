#include "riemann.h"
int main(){
	int32_t a,b,c,n,begin,end;
	printf("input a,b,c: ");
	scanf("%d,%d,%d",&a,&b,&c);
	printf("input begin,end,n: ");
	scanf("%d,%d,%d",&begin,&end,&n);
	set_polynomial(a,b,c);
	printf("黎曼積分: %lf\n",calculate_riemann_integral(begin,end));
	printf("黎曼分段積分: %lf\n",calculate_riemann_sum(begin,end,n));
	printf("面積: %lf\n",calculate_area(begin,end));
	printf("分段面積: %lf\n",calculate_area_riemann_sum(begin,end,n));
	return 0;
}

