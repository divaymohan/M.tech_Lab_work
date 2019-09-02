#include<stdio.h>
#include<stdlib.h>

int main(int argv,char *argc[]){
	FILE *ifp; // to get input file
	FILE *ofp; //to out the output

	int nProc;
	int nRes;
	int sts=1;
	int stsSat = 1;
	ifp = fopen(argc[1],"r");
	fscanf(ifp,"%d",&nProc);
	fscanf(ifp,"%d",&nRes);
	//ofp = fopen(argc[2],"w");
	int totle[nRes];
	int seq[nProc];
	int bit[nProc];
	int available[nRes];
	int allocated[nProc][nRes];
	int request[nProc][nRes];
	int max[nProc][nRes];
	int need[nProc][nRes];
	//taking totle resources
	for(int i=0;i<nRes;i++){
		fscanf(ifp,"%d",&totle[i]);
	}
	//taking allocated matrix from file
	for(int i=0;i<nProc;i++){
		for(int j=0;j<nRes;j++){
			fscanf(ifp,"%d",&allocated[i][j]);
		}
	}
	//taking request matrix from file
	for(int i=0;i<nProc;i++){
		for(int j=0;j<nRes;j++){
			fscanf(ifp,"%d",&request[i][j]);
		}
	}
	//taking max from file
	for(int i=0;i<nProc;i++){ 
                for(int j=0;j<nRes;j++){ 
                        fscanf(ifp,"%d",&max[i][j]);
                }
        }
	//calculating available resources
	for(int i=0;i<nRes;i++){
                available[i]=totle[i];
        }
	//initialoze bit vector
	for(int i=0;i<nProc;i++){
		bit[i]=0;
	}
        for(int i=0;i<nProc;i++){
                for(int j=0;j<nRes;j++){
                        available[j] = available[j] - allocated[i][j]; 
                }
        }
	//calculating nees resources

	for(int i=0;i<nProc;i++){
                for(int j=0;j<nRes;j++){
                        need[i][j] = max[i][j]-allocated[i][j];
                }
        }
	printf("********Available**********\n");
	for(int i=0;i<nRes;i++){
                printf("%d\t",available[i]);
        }

	//printing need
	printf("\n******Calculated need********\n");
	for(int i=0;i<nProc;i++){
		for(int j=0;j<nRes;j++){
			printf("%d\t",need[i][j]);
		}
		printf("\n");
	}

	printf("\n");
	int count = 0;
	int nCount = 0;
	int f = 1;
	//checking if any process demand resources more then their need
	for(int i=0;i<nProc;i++){
		for(int j=0;j<nRes;j++){
			if(need[i][j]<request[i][j]){
				printf("\n deadLock may occur..!");
				return 0;
			}
		}
	}
	while(f==1){
		f=0;
		//let's satisfy the need
		for(int i=0;i<nProc;i++){
			if(bit[i]==1){
			}
			else{
				for(int j=0;j<nRes;j++){
						if(need[i][j]>available[j]){
							stsSat = 0;
						}
				}
				if(stsSat!=0){
					seq[count++]=i;
					bit[i]=1;
					nCount =0;
					for(int k=0;k<nRes;k++){
						available[k] = available[k]+ allocated[i][k];
						allocated[i][k]=0;
						need[i][k]=0;
						//back to for loop again
						f =1;
					}
					printf("\n*******After Allocating %d Available is:\n",i);
					for(int k=0;k<nRes;k++){
						printf("%d ",available[k]);
					}
				}
				else{
					nCount++;
					stsSat=1;
				}
			}
			if(f==1){
				break;
			}
			if(nCount>nProc){
				printf("\nDeadLock occurs..!!");
			}
		}
	}




	return 0;
}

