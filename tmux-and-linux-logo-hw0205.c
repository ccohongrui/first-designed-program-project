#include <stdio.h>
#include <stdint.h>
int main(){
	int32_t width,height,pane,job,vr=1,hr=1,count_vr=6,count_hr=4,triangle;
	int32_t a=0,b=0,c=0,f=0,g=0,h=0,m=0,n=0;//計次變數
	printf("Please input the window size (width)x(height): ");
	scanf("%dx%d",&width,&height);
	height=height-1;
	printf("Please input the total pane number: ");
	scanf("%d",&pane);
	printf("Please input the pane for the job (0=all,-1=none): ");
	scanf("%d",&job);
	if(pane==0){width=0;height=0;printf("no screen can use\n");}
	if(pane==1){vr=0;hr=0;}
	if(pane==2){vr=1;hr=0;}
	while(count_vr<pane){ //計算幾條直線
		vr=vr+1;
		count_vr=6+count_vr+a;
		a=a+2;
	}
	a=0;
	while(count_hr<pane){ //計算幾條橫線
		hr=hr+1;
		count_hr=5+count_hr+a;
		a=a+2;
	}
	if(height/(hr+1)-2<3){
		triangle=0;
	}
	else{
		triangle=height/(hr+1)-1;
	}
	int32_t bottom_sec=c=pane%(vr+1)-1,d=pane,e=pane*9,pane_new=pane%(vr+1),job_vr=job%(vr+1),job_hr=job/(vr+1)+1;
	if(pane%(vr+1)==0){bottom_sec=vr;c=vr;pane_new=vr+1;}
	if(job_vr==0){job_vr=vr+1;}
	if(job%(vr+1)==0){job_hr=job/(vr+1);}
	int32_t each_w=width/(vr+1)+1,each_h=height/(hr+1)+1,intersection=vr*(hr-1)+bottom_sec; //預設寬高
	for(int32_t i=1;i<=hr+1;i++){ //直的幾次
		for(int32_t j=1;j<=each_h;j++){ //多高
			if(i>(height%(hr+1))){each_h=height/(hr+1);}
			else{each_h=height/(hr+1);} //改變高誤差小於1
			for(int32_t k=1;k<=vr+1;k++){ //橫的幾次
				for(int32_t l=1;l<=each_w;l++){ //多寬
					if(k>(width%(vr+1))){each_w=width/(vr+1);}
					else{each_w=width/(vr+1);}
					if(l==each_w &&j==each_h &&intersection>0 &&k!=vr+1 &&i!=hr+1){printf("┼");intersection--;}
					else if(l==each_w && j==each_h && k!=vr+1 && i!=hr+1){printf("┴");b++;}
					else if(l==each_w && k!=vr+1 && b==0){printf("│");}
					else if(l==each_w && k!=vr+1 && c>0){printf("│");c--;}
					else if(j==each_h && i!=hr+1){printf("─");}
					else if(l==1 && j==1 && d>0){printf("$");d--;}
					else if(l>=3 && l<=11 && j==1 && e>0 && (k==job_vr && i==job_hr || job==0)){
						if(l==3){printf("f");}if(l==4){printf("a");}if(l==5){printf("s");}
						if(l==6){printf("t");}if(l==7){printf("f");}if(l==8){printf("e");}
						if(l==9){printf("t");}if(l==10){printf("c");}if(l==11){printf("h");}
						e--;
					}
					else if((k==job_vr && i==job_hr || job==0) && l>=1 && l<=triangle*2 
						&& j>=2 && j<=triangle+1 && !(i==hr+1 && k>pane_new)){
						        if((l==triangle-f && j==2+f) || l==triangle-g && j==2+triangle*2/3+g){
								printf("\033[38;2;%d;%d;%dm/\033[0m",23,147,209);
							
							}
							else if((l==triangle+1+h &&j==2+h) ||l==triangle+1+m &&j==2+triangle*2/3+m){
								printf("\033[38;2;%d;%d;%dm\\\033[0m",23,147,209);
							
							}
							else if((l>triangle-f &&l<triangle+1+h) &&!(l>triangle-g &&l<triangle+1+m)){
								printf("\033[38;2;%d;%d;%dmo\033[0m",23,147,209);
							}   
							else{printf(" ");}
					
					}
					else{printf(" ");}
					if(l>=1 && l<=triangle*2 && j>=2 && j<=triangle+1 && k==vr+1){
						if(l==triangle-f && j==2+f){f++;} 
						if(l==triangle-g && j==2+triangle*2/3+g){g++;}
						if(l==triangle+1+h &&j==2+h){h++;}
						if(l==triangle+1+m &&j==2+triangle*2/3+m){m++;}
					}	 
				}
			}
			printf("\n");
			c=bottom_sec;	
		}
		h=0;f=0;g=0;m=0;
	}
	printf("\033[48;2;0;255;0;30m[0] 0:bash*\033[0m");
	for(int32_t i=1;i<=width-11;i++){
		printf("\033[48;2;0;255;0m \033[0m");
	}
	printf("\n");
	if(triangle==0){printf("Screen is too small to type linux logo\n");}
	return 0;
}











