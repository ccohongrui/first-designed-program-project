#include <stdio.h>
#include <stdint.h>
#include "hw0304-2.h"
int32_t hanoi_iterative(void){
	void tower_iterative(int32_t n){
		int32_t rods[3][20];
		int32_t rodCount[3] = {0};

		for (int32_t i = n; i > 0; i--) {
			rods[0][rodCount[0]++] = i;
		}

		int32_t src = 0, dest = 1, aux = 2;

		if (n % 2 == 0) {
			int32_t temp = dest;
			dest = aux;
			aux = temp;
		}

		int32_t moves = (1 << n) - 1;

		for (int32_t i = 1; i <= moves; i++) {
			int32_t from, to;

			if (i % 3 == 1) {
				from = src;
				to = dest;
			} else if (i % 3 == 2) {
				from = src;
				to = aux;
			} else {
				from = aux;
				to = dest;
			}

			if (rodCount[from] == 0) {
				int32_t disk = rods[to][--rodCount[to]];
				rods[from][rodCount[from]++] = disk;
				printf("move disk %d to rod %d\n", disk, from + 1);
			} else if (rodCount[to] == 0) {
				int32_t disk = rods[from][--rodCount[from]];
				rods[to][rodCount[to]++] = disk;
				printf("move disk %d to rod %d\n", disk, to + 1);
			} else if (rods[from][rodCount[from] - 1] > rods[to][rodCount[to] - 1]) {
				int32_t disk = rods[to][--rodCount[to]];
				rods[from][rodCount[from]++] = disk;
				printf("move disk %d to rod %d\n", disk, from + 1);
			} else {
				int32_t disk = rods[from][--rodCount[from]];
				rods[to][rodCount[to]++] = disk;
				printf("move disk %d to rod %d\n", disk, to + 1);
			}
		}
	}
	int32_t num=0;
	printf("Please enter the disk number(2-20): ");
	if(scanf("%d",&num)==1 && num>=2 && num<=20){
		tower_iterative(num);
		return (1<<num)-1;
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
}
