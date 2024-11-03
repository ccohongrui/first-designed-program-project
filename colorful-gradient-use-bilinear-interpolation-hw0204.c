#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t width,height,top_r,bottom_r,final_r,top_g,bottom_g,final_g,top_b,bottom_b,final_b;
	int32_t tlr,tlg,tlb,blr,blg,blb,trr,trg,trb,brr,brg,brb;
	while(1){
		printf("Please enter the width (10 -80): ");
		scanf("%d",&width);
		if(width<10 || width>80){
			printf("Invalid range,please re-input\n");
			continue;
		}
		printf("Please enter the height (10 -20): ");
		scanf("%d",&height);
		if(height<10 || height>20){
			printf("Invalid range,please re-input\n");
			continue;
		}
	
		printf("Please enter the top left RGB:  ");
		scanf("%d,%d,%d",&tlr,&tlg,&tlb);
		if(tlr<=255 && tlr>=0 && tlg<=255 && tlg>=0 && tlb<=255 && tlb>=0 ){
		}
		else{
			printf("Invalid range,please re-input\n");
			continue;
		}
	
		printf("Please enter the top right RGB:  ");
		scanf("%d,%d,%d",&trr,&trg,&trb);
		if(trr<=255 && trr>=0 && trg<=255 && trg>=0 && trb<=255 && trb>=0 ){
		}
		else{
			printf("Invalid range,please re-input\n");
			continue;
		}

		printf("Please enter the bottom left RGB: ");
		scanf("%d,%d,%d",&blr,&blg,&blb);
		if(blr<=255 && blr>=0 && blg<=255 && blg>=0 && blb<=255 && blb>=0 ){
		}
		else{
			printf("Invalid range,please re-input\n");
			continue;
		}

		printf("Please enter the bottom right RGB: ");
		scanf("%d,%d,%d",&brr,&brg,&brb);
		if(brr<=255 && brr>=0 && brg<=255 && brg>=0 && brb<=255 && brb>=0 ){
		}
		else{
			printf("Invalid range,please re-input\n");
			continue;
		}

	for(int32_t i=0;i<height;i++){
		for(int32_t j=0;j<width;j++){
			top_r=tlr+((trr-tlr)/(width-1))*j;
			bottom_r=blr+((brr-blr)/(width-1))*j;
			final_r=top_r+((bottom_r-top_r)/(height-1))*i;	
			top_g=tlg+((trg-tlg)/(width-1))*j;
			bottom_g=blg+((brg-blg)/(width-1))*j;
			final_g=top_g+((bottom_g-top_g)/(height-1))*i;
			top_b=tlb+((trb-tlb)/(width-1))*j;
			bottom_b=blb+((brb-blb)/(width-1))*j;
			final_b=top_b+((bottom_b-top_b)/(height-1))*i;
			printf("\033[38;2;%d;%d;%dm*\033[0m",final_r,final_g,final_b);
		}
		printf("\n");
	}
	break;
	}
	return 0;
}
