#include "types.h"
#include "stat.h"
#include "user.h"


int main(void){
    int father=getpid();
    int pids[10]={0};
    int runningTime,sleepingTime,terminationTime,creationTime,readyTime;
    int waitingTimeAverage=0;
    int burstTimeAverage=0;
    int turnaroundTimeAverage=0;
    for(int i=0;i<10;i++){
        if(getpid()==father){
            fork();
        }
    }
    if(getpid()==father){
        for(int i=0;i<10;i++){
            pids[i]=wait2(&runningTime,&sleepingTime,&terminationTime,&creationTime,&readyTime);
            int waitingTime=sleepingTime+readyTime;
            int burstTime=runningTime;
            int turnaroundTime=terminationTime-creationTime;
            waitingTimeAverage+=waitingTime;
            burstTimeAverage+=burstTime;
            turnaroundTimeAverage+=turnaroundTime;
            sleep(10);
            printf(1,"\nPID : %d | Waiting : %d | CBT : %d | Turnaround : %d ",pids[i],waitingTime,burstTime,turnaroundTime);
        }
    }else{
        for (int i=1; i<=10; i++) {
            printf(1, "/%d/ : /%d/ \n", getpid(), i);
        }
        exit();
    }
    printf(1,"\nAverage Waiting Time : %d",waitingTimeAverage);
    printf(1,"\nAverage CBT : %d",burstTimeAverage);
    printf(1,"\nAverage Turnaround Time : %d",turnaroundTimeAverage);
    exit();
}

