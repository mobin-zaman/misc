#include <iostream>
#include <cstdio>
using namespace std;

void phase1() {
	printf("\n");
	printf("|  5  |  2  |\n");
	printf("|  6  |  1  |\n");
    printf("\n");
}

void phase2() {
	printf("\n");
	printf("|  3  |  4  |\n");
  	printf("|  7  |  8  |\n");
    printf("\n");
}





int main()
{
	char choice;
	int counter;
	printf("-------------\n");
	printf("|yellow| red|\n");
	printf("| green|blue|\n");
    printf("-------------\n");
    printf("\n");
    printf("choice: ");
    scanf("%c", &choice);
    switch (choice) {
    	case 'g':
    		counter=5;
    		break;
    	case 'r':
    		counter=3;
    		break;
    	case 'b':
    		counter=4;
    		break;
    	case 'y':
    		counter=6;
    		break;
    	default:
    		cout <<"fu";
    		return 0; 
    }
    int flag=0;
    if(counter ==5 || counter== 3) {
    	phase1();
    	flag=1;
    }
    else {
    	phase2();
    	flag=2;
    }
    int loop_counter,while_counter=0;
    while(while_counter<4) {
    	printf("choice: ");
    	scanf("%d", &loop_counter);
        if(flag==1) {
        	if((loop_counter==2 || loop_counter==6)) {
        		phase1();
        		flag=1;
			}
			else if(loop_counter==1 || loop_counter==5) {
				phase2();
				flag=2;
			}
            else {
            	printf("fu\n");
            	return 0;
            }
        }
        else if(flag==2) {
        	if(loop_counter==4 || loop_counter==8) {
        		phase2();
        		flag=2;
        	}
            else if(loop_counter==3 || loop_counter==7) {
            	phase1();
            	flag=1;
            }
            else {
            	printf("fu\n");
            	return 0;
            }
        }
        while_counter++;
    }
    int final_choice;
    printf("the final choice: ");
    scanf("%d", &final_choice);
    if(flag==1) {
    	if(final_choice==5) printf("you are going to marry eric cartman\n");
        else if(final_choice==2) printf("you are going to marry stan marsh\n");
        else if(final_choice==1) printf("you are going to marry kenny\n");
        else if(final_choice==6) printf("you are going to marry kyle\n");
        else printf("fu\n");
    }
    else {
    	if(final_choice==3) printf("you are going to marry randy\n");
    	else if(final_choice==4) printf("you are going to marry garrison\n");
    	else if(final_choice==7) printf("you are going to marry linda storch\n");
    	else if(final_choice==8) printf("you are going to marry principle victoria\n");
         else printf("fu\n");
         	
    }
    return 0;
}


