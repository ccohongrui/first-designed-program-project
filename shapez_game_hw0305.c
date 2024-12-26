#include "stdint.h"
#include "stdio.h"
#include "encrypt.h"
#include "shapez.h"
int miner(int shape) {
    if(shape==1 || shape==2 || shape==3 || shape==4){	
    	load_shapez(shape*10000000+7000000+shape*100000+70000+shape*1000+700+shape*10+7);	
	return store_shapez();
    }
    else{
	printf("Invalid input,error\n");
	return -1;
    }
}
int rotator(int shapez) {
    load_shapez(shapez);
    if((s1==0&&c1!=0)||(s1!=0&&c1==0)||(s2==0&&c2!=0)||(s2!=0&&c2==0)||(s3==0&&c3!=0)||(s3!=0&&c3==0)||(s4==0&&c4!=0)||
    (s4!=0&&c4==0)){
       	printf("Invalid input,error,both s,c should be equal to 0\n");
	return -1;
    }
    else if(s1>=0&&s1<=4&&s2>=0&&s2<=4&&s3>=0&&s3<=4&&s4>=0&&s4<=4&&c1>=0&&c1<=8&&c2>=0&&c2<=8&&c3>=0&&c3<=8&&c4>=0&&c4<=8){
    	tmpS=s4;s4=s3;s3=s2;s2=s1;s1=tmpS;
	tmpC=c4;c4=c3;c3=c2;c2=c1;c1=tmpC;
	return store_shapez();
    }
    else{
      	printf("Invalid input,error\n");
 	return -1;
    }
}

int cutter(int shapez) {
    load_shapez(shapez);
    if((s1==0&&c1!=0)||(s1!=0&&c1==0)||(s2==0&&c2!=0)||(s2!=0&&c2==0)||(s3==0&&c3!=0)||(s3!=0&&c3==0)||(s4==0&&c4!=0)||
    (s4!=0&&c4==0)){
      	printf("Invalid input,error,both s,c should be equal to 0\n");
	return -1;
    }
    else if(s1>=0&&s1<=4&&s2>=0&&s2<=4&&s3>=0&&s3<=4&&s4>=0&&s4<=4&&c1>=0&&c1<=8&&c2>=0&&c2<=8&&c3>=0&&c3<=8&&c4>=0&&c4<=8){
    	s1=0;s2=0;c1=0;c2=0;
    	return store_shapez();
    }
    else{
    	printf("Invalid input,error\n");
	return -1;
    }
}

int stacker(int shapezA, int shapezB) {
    load_shapez(shapezA);
    if((s1==0&&c1!=0)||(s1!=0&&c1==0)||(s2==0&&c2!=0)||(s2!=0&&c2==0)||(s3==0&&c3!=0)||(s3!=0&&c3==0)||(s4==0&&c4!=0)||
    (s4!=0&&c4==0)){
      	printf("Invalid input,error,both s,c should be equal to 0\n");
	return -1;
    }
    else if(s1>=0&&s1<=4&&s2>=0&&s2<=4&&s3>=0&&s3<=4&&s4>=0&&s4<=4&&c1>=0&&c1<=8&&c2>=0&&c2<=8&&c3>=0&&c3<=8&&c4>=0&&c4<=8){
	load_shapez(shapezB);
	if((s1==0&&c1!=0)||(s1!=0&&c1==0)||(s2==0&&c2!=0)||(s2!=0&&c2==0)||(s3==0&&c3!=0)||(s3!=0&&c3==0)||(s4==0&&c4!=0)||
    	(s4!=0&&c4==0)){
    		printf("Invalid input,error,both s,c should be equal to 0\n");
		return -1;
        }
	else if(s1>=0&&s1<=4&&s2>=0&&s2<=4&&s3>=0&&s3<=4&&s4>=0&&s4<=4&&c1>=0&&c1<=8&&c2>=0&&c2<=8&&c3>=0&&c3<=8&&c4>=0&&c4<=8){
		if(shapezA/10000000%10==0&&shapezB/10000000%10!=0){
			s1=shapezB/10000000%10;
			c1=shapezB/1000000%10;
		}
		else if(shapezA/10000000%10!=0&&shapezB/10000000%10==0){
			s1=shapezA/10000000%10;
			c1=shapezA/1000000%10;
		}
		else if(shapezA/10000000%10==0&&shapezB/10000000%10==0){
			s1=0;
			c1=0;
		}
		else{
			printf("Invalid input,error,overlap\n");
			return -1;
		}
		if(shapezA/100000%10==0&&shapezB/100000%10!=0){
			s2=shapezB/100000%10;
			c2=shapezB/10000%10;
		}
		else if(shapezA/100000%10!=0&&shapezB/100000%10==0){
			s2=shapezA/100000%10;
			c2=shapezA/10000%10;
		}
		else if(shapezA/100000%10==0&&shapezB/100000%10==0){
			s2=0;
			c2=0;
		}
		else{
			printf("Invalid input,error,overlap\n");
			return -1;
		}
		if(shapezA/1000%10==0&&shapezB/1000%10!=0){
			s3=shapezB/1000%10;
			c3=shapezB/100%10;
		}
		else if(shapezA/1000%10!=0&&shapezB/1000%10==0){
			s3=shapezA/1000%10;
			c3=shapezA/100%10;
		}
		else if(shapezA/1000%10==0&&shapezB/1000%10==0){
			s3=0;
			c3=0;
		}
		else{
			printf("Invalid input,error,overlap\n");
			return -1;
		}
		if(shapezA/10%10==0&&shapezB/10%10!=0){
			s4=shapezB/10%10;
			c4=shapezB/1%10;
		}
		else if(shapezA/10%10!=0&&shapezB/10%10==0){
			s4=shapezA/10%10;
			c4=shapezA/1%10;
		}
		else if(shapezA/10%10==0&&shapezB/10%10==0){
			s4=0;
			c4=0;
		}
		else{
			printf("Invalid input,error,overlap\n");
			return -1;
		}
		return store_shapez();
	}
	else{
		printf("Invalid input,error\n");
		return -1;
	}
    }
    else{
	printf("Invalid input,error\n");
	return -1;
    }
}

int mixer(int colorA, int colorB) {
    if(colorA>=1&&colorA<=8&&colorB>=1&&colorB<=8){
    	if((colorA==1&&colorB==2)||(colorA==2&&colorB==1)){return 4;}
    	else if((colorA==1&&colorB==3)||(colorA==3&&colorB==1)){return 5;}
    	else if((colorA==1&&colorB==4)||(colorA==4&&colorB==1)){return 4;}
    	else if((colorA==1&&colorB==5)||(colorA==5&&colorB==1)){return 5;}
   	else if((colorA==1&&colorB==6)||(colorA==6&&colorB==1)){return 8;}
    	else if((colorA==2&&colorB==3)||(colorA==3&&colorB==2)){return 6;}
    	else if((colorA==2&&colorB==4)||(colorA==4&&colorB==2)){return 4;}
    	else if((colorA==2&&colorB==5)||(colorA==5&&colorB==2)){return 8;}
   	else if((colorA==2&&colorB==6)||(colorA==6&&colorB==2)){return 6;}
  	else if((colorA==3&&colorB==4)||(colorA==4&&colorB==3)){return 8;}
 	else if((colorA==3&&colorB==5)||(colorA==5&&colorB==3)){return 5;}
  	else if((colorA==3&&colorB==6)||(colorA==6&&colorB==3)){return 6;}
    	else if((colorA==4&&colorB==5)||(colorA==5&&colorB==4)){return 8;}
    	else if((colorA==4&&colorB==6)||(colorA==6&&colorB==4)){return 8;}
    	else if((colorA==5&&colorB==6)||(colorA==6&&colorB==5)){return 8;}
    	else if(colorA==1&&colorB==1){return 1;}
    	else if(colorA==2&&colorB==2){return 2;}
    	else if(colorA==3&&colorB==3){return 3;}
    	else if(colorA==4&&colorB==4){return 4;}
    	else if(colorA==5&&colorB==5){return 5;}
    	else if(colorA==6&&colorB==6){return 6;}
    }
    else{
	printf("Invalid input,error\n");
	return -1;
    }
}

int painter(int shapeA, int color) {
    load_shapez(shapeA);
    if((s1==0&&c1!=0)||(s1!=0&&c1==0)||(s2==0&&c2!=0)||(s2!=0&&c2==0)||(s3==0&&c3!=0)||(s3!=0&&c3==0)||(s4==0&&c4!=0)||
    (s4!=0&&c4==0)){
       	printf("Invalid input,error,both s,c should be equal to 0\n");
	return -1;
    }
    else if(color<1||color>8){
	printf("Invalid input,error\n");
	return -1;
    }
    else if(s1>=0&&s1<=4&&s2>=0&&s2<=4&&s3>=0&&s3<=4&&s4>=0&&s4<=4&&c1>=0&&c1<=8&&c2>=0&&c2<=8&&c3>=0&&c3<=8&&c4>=0&&c4<=8){
    	if(s1!=0){c1=color;}
	if(s2!=0){c2=color;}
	if(s3!=0){c3=color;}
	if(s4!=0){c4=color;}
	return store_shapez();
    }
    else{
      	printf("Invalid input,error\n");
	return -1;
    }
}

int Target(int task) {
    if(task>=1&&task<=10){
	if(task==1){// 1 CwCwCwCw
		miner(1);
		painter(store_shapez(),mixer(mixer(1,2),3));
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==2){// 2 --RbRb--
		miner(2);
		painter(store_shapez(),3);
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==3){// 3 CwCwCwRb
		miner(2);
		painter(store_shapez(),3);
		cutter(store_shapez());
		tmpZ=store_shapez();
		miner(1);
		painter(store_shapez(),mixer(mixer(1,2),3));
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		rotator(store_shapez());
		cutter(store_shapez());
		tmpZ=store_shapez();
		miner(1);
		painter(store_shapez(),mixer(mixer(1,2),3));
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==4){// 4 RuCwRuCw
		miner(1);
		painter(store_shapez(),mixer(mixer(1,2),3));
		cutter(store_shapez());
		tmpZ=store_shapez();
		miner(2);
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		rotator(store_shapez());
		cutter(store_shapez());
		tmpZ=store_shapez();
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==5){// 5 CcSpSpCc
		miner(1);
		painter(store_shapez(),mixer(2,3));
		cutter(store_shapez());
		tmpZ=store_shapez();
		miner(4);
		painter(store_shapez(),mixer(1,3));
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		rotator(store_shapez());
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==6){// 6 Sr--Sb--
		miner(4);
		painter(store_shapez(),1);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		tmpZ=store_shapez();
		miner(4);
		painter(store_shapez(),3);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());		
		return store_shapez();
	}
	else if(task==7){// 7 CwRp--Sc
		miner(2);
		painter(store_shapez(),mixer(1,3));
		cutter(store_shapez());
		tmpZ=store_shapez();
		miner(1);
		painter(store_shapez(),mixer(mixer(1,2),3));
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		tmpZ=store_shapez();
		miner(4);
		painter(store_shapez(),mixer(2,3));
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());		
		return store_shapez();
	}
	else if(task==8){// 8 SySrWrSc
		miner(4);
		painter(store_shapez(),mixer(1,2));
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		tmpZ=store_shapez();
		miner(4);
		painter(store_shapez(),1);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		tmpZ=store_shapez();
		miner(3);
		painter(store_shapez(),1);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		tmpZ=store_shapez();
		miner(4);
		painter(store_shapez(),mixer(2,3));
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==9){// 9 RpRuWrSu
		miner(2);
		painter(store_shapez(),mixer(1,3));
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		tmpZ=store_shapez();
		miner(2);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		tmpZ=store_shapez();
		miner(3);
		painter(store_shapez(),1);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		tmpZ=store_shapez();
		miner(4);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());	
		return store_shapez();
	}
	else if(task==10){// 10 SgWy--Cr
		miner(4);
		painter(store_shapez(),2);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		tmpZ=store_shapez();
		miner(3);
		painter(store_shapez(),mixer(1,2));
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		rotator(store_shapez());
		rotator(store_shapez());
		stacker(store_shapez(),tmpZ);
		tmpZ=store_shapez();
		miner(1);
		painter(store_shapez(),1);
		cutter(store_shapez());
		rotator(store_shapez());
		cutter(store_shapez());
		stacker(store_shapez(),tmpZ);
		print_shapez(store_shapez());	
		return store_shapez();
	}
    }
    else{
	printf("Invalid input,error\n");
	return -1;
    }
}
