


#include "pthread_pool.h"


/*
typedef struct __node_task{
 int tid;
 int value;
 RB_ENTRY(__node_task)entry;
}task_t;


/*comp a and b*/
/*note:com must return >0 value and <0 value*/
// int cmp(task_t *a,task_t *b){
//       return a->value>b->value?1:-1;
// }



// RB_HEAD(exp,__node_task)st_task=RB_INITIALIZER(NULL);

// RB_PROTOTYPE(exp,__node_task,entry,cmp);
// RB_GENERATE(exp,__node_task,entry,cmp);


// void append(task_t *a){
//       return RB_INSERT(exp,&st_task,a);
// }



// void print(void)
// {
// 	task_t *item;
     
// 	RB_FOREACH(item, exp, &st_task) {
// 		printf("%d\n", item->value);
// 	}

// }





void * hand(void *arg){
     printf("hello world\n");
     return NULL;
}


int main(int argc,char **argv){
      
      int i=0;
      int j=0;
      init_pthreadpool();
      
       for(i=0,j=0;i<10&&j<10;i++,j++)
        insert_task(&j,i);
       

    
       destroy_pool();
       return 0;
}
