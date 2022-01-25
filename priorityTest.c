#include "types.h"
#include "stat.h"
#include "user.h"


int main(void){
    changePolicy(3);
    int childNumber=0;
    int father=getpid();
    int pids[30]={0};
    int priority,runningTime,sleepingTime,terminationTime,creationTime,readyTime;
    int waitingTimeAverage=0;
    int burstTimeAverage=0;
    int turnaroundTimeAverage=0;
    int waitingArrayAverage[7];
    int burstArrayAverage[7];
    int turnaroundArrayAverage[7];
    for(int i=0;i<30;i++){
        if(getpid()==father){
            fork();
            if(getpid()!=father){
                setPriority(6-i/5);
                childNumber=i+1;
            }
        }
    }
    if(getpid()==father){
        for(int i=0;i<30;i++){
            pids[i]=wait3(&priority,&runningTime,&sleepingTime,&terminationTime,&creationTime,&readyTime);
            int waitingTime=sleepingTime+readyTime;
            int burstTime=runningTime;
            int turnaroundTime=waitingTime+burstTime;
            waitingTimeAverage+=waitingTime;
            burstTimeAverage+=burstTime;
            turnaroundTimeAverage+=turnaroundTime;
            waitingArrayAverage[priority]+=waitingTime;
            burstArrayAverage[priority]+=burstTime;
            turnaroundArrayAverage[priority]+=turnaroundTime;
            sleep(50);
            printf(1,"\nPID : %d | Priority : %d | Waiting : %d | CBT : %d | Turnaround : %d ",pids[i],priority,waitingTime,burstTime,turnaroundTime);
        }
    }else{
        for (int i=1; i<=10; i++) {
            printf(1, "/%d/ : /%d/ \n", childNumber, i);
            sleep(10);
        }
        exit();
    }
    
    waitingTimeAverage/=30;
    burstTimeAverage/=30;
    turnaroundTimeAverage/=30;
    for(int i=1;i<7;i++){
        waitingArrayAverage[i]/=5;
        burstArrayAverage[i]/=5;
        turnaroundArrayAverage[i]/=5;
        printf(1,"\nAverage Waiting Time For Priority %d : %d",i,waitingArrayAverage[i]);
        printf(1,"\nAverage CBT For Priority %d : %d",i,burstArrayAverage[i]);
        printf(1,"\nAverage Turnaround Time For Priority %d : %d",i,turnaroundArrayAverage[i]);
        printf(1,"\n------------------");
    }
    printf(1,"\n****************************************************************");
    printf(1,"\nTotal Results : \n");
    printf(1,"\nAverage Waiting Time : %d",waitingTimeAverage);
    printf(1,"\nAverage CBT : %d",burstTimeAverage);
    printf(1,"\nAverage Turnaround Time : %d",turnaroundTimeAverage);
    
    exit();
}

