#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
struct MarksData
{
    char name[200];
    char RegNo[100];
    float sub1;
    float sub2;
    float sub3;
    float sub4;
    float sub5;
    float sub6;
    float sub7;
    float avg;
};
int main(int argc, char *argv[])
{
    FILE *fp;
    fp = fopen(argv[1], "r");
    // struct MarksData md[2];
    //fscanf(fp,"%s %s %f %f %f %f %f %f %f",&(md[0].name),&(md[0].RegNo),&(md[0].sub1),&(md[0].sub2),&(md[0].sub3),&(md[0].sub4),&(md[0].sub5),$
    //fscanf(fp,"%s %s %f %f %f %f %f %f %f",&(md[1].name),&(md[1].RegNo),&(md[1].sub1),&(md[1].sub2),&(md[1].sub3),&(md[1].sub4),&(md[1].sub5),$
    //printf("%s, %s\n",md[0].name,md[0].RegNo);

    key_t k = ftok("sharedFile", 65);
    //key_t k = 999;
    int shmid = shmget(k, sizeof(struct MarksData) * 2, 0666 | IPC_CREAT);
    struct MarksData *md = (struct MarksData *)shmat(shmid, (void *)0, 0);
    printf("Write Data:: ");
        fscanf(fp,"%s %s %f %f %f %f %f %f %f",&(md[0].name),&(md[0].RegNo),&(md[0].sub1),&(md[0].sub2),&(md[0].sub3),&(md[0].sub4),&(md[0].sub5),&(m$
         fscanf(fp,"%s %s %f %f %f %f %f %f %f",&(md[1].name),&(md[1].RegNo),&(md[1].sub1),&(md[1].sub2),&(md[1].sub3),&(md[1].sub4),&(md[1].sub5),&($
        printf("\nData Written By Parent..!!");
//scanf("%s",str);
        //printf("Data written in memory :: %s\n",str);
        shmdt(md);
        if(fork()==0){
        //code for child process
        key_t key = ftok("sharedFile", 65);
        int shm_id = shmget(key, sizeof(struct MarksData) * 2, 0666 | IPC_CREAT);
        struct MarksData *mdc = (struct MarksData *)shmat(shm_id, (void *)0, 0);
        mdc[0].avg = (mdc[0].sub1 + mdc[0].sub2 + mdc[0].sub3 + mdc[0].sub4 + mdc[0].sub5 + mdc[0].sub6 + mdc[0].sub7) / 7;
        mdc[1].avg = (mdc[1].sub1 + mdc[1].sub2 + mdc[1].sub3 + mdc[1].sub4 + mdc[1].sub5 + mdc[1].sub6 + mdc[1].sub7) / 7;
        printf("\nAvg Calculated By child and sent to parent..!!\n");

        //printf("\nChange the Data to :: ");
        //strcpy(strc,"divay");
        //printf("\nData Change by child to:: %s",strc);

        }
        else{
        sleep(3);
        //code for child process
        //key_t key = ftok("sharedFile",65);
        key_t k = ftok("sharedFile", 65);
        printf("\nValue Come From Parent..!!\n");
        //key_t k = 999;
        int shmid = shmget(k, sizeof(struct MarksData) * 2, 0666);
        struct MarksData *mdp = (struct MarksData *)shmat(shmid, (void *)0, 0);
        printf("\nAvg of %s :: %f", mdp[0].RegNo, mdp[0].avg);
        if (mdp[0].avg > 75)
        {
            printf(" Granteed");
        }
        else
        {
            printf(" Not Granteed");
        }
        printf("\nAvg of %s :: %f", mdp[1].RegNo, mdp[1].avg);
        if (mdp[1].avg > 75)
        {
            printf(" Granteed\n");
        }
        else
        {
            printf(" Not Granteed\n");
        }

        shmdt(mdp);
        shmctl(shmid, IPC_RMID, NULL);

        //code for parent process
        }
        return 0;
}
