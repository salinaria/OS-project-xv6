#include "types.h"
#include "stat.h"
#include "user.h"

void childPrint(void* args){
    printf(1, "hi, childs function executed properly with argument : %d\n", *(int*)args);
}
void childPrint2(void* args){
    printf(1, "hi, childs function executed properly with argument : %d\n", *(int*)args);
}
void childPrint3(void* args){
    printf(1, "hi, childs function executed properly with argument : %d\n", *(int*)args);
}

int main(void){
    int argument = 0x0F01; //3041 in decimal
    int thread_id = thread_creator(&childPrint, (void*)&argument);
    int thread_id_2 = thread_creator(&childPrint2, (void*)&argument);
    int thread_id_3 = thread_creator(&childPrint3, (void*)&argument);

    if(thread_id < 0)
        printf(1, "thread_create failed");
   if(thread_id_2 < 0)
        printf(1, "thread_create failed");
   if(thread_id_3 < 0)
        printf(1, "thread_create failed");

    thread_wait();
    //printf(1,"1\n");
    thread_wait();
    //printf(1,"2\n");
    thread_wait();

    printf(1, "thread_id is : %d\n", thread_id);
    printf(1, "thread_id is : %d\n", thread_id_2);
    printf(1, "thread_id is : %d\n", thread_id_3);
    exit();
}