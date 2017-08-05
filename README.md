[![Biuild Status](https://travis-ci.org/wuli133144/pthread_pool.svg?branch=master)]
(https://travis-ci.org/wuli133144/pthread_pool)

## About
*this project about pthread pool 
*this project is version 2.0
*add funcion handler like rb_tree 
*make it better 

## Features
* currence create many pthread object 
* like producor and costumer
* high concurrence


## Installation
Run:
```
git clone https://github.com/wuli133144/pthreadpool-last-version.git
```
and copy all files to you source code tree.then find make
Run  ```make``` to compile and run tests.

## Examples


some code:
```
--------------------------------------------------------------------------
>typedef struct _task{
>     int value;
>      void *arg;
>     pthread_mutex_t mutex;
>      //TAILQ_ENTRY(_task)entry;  /*old version*/
>      RB_ENTRY(_task)entry;
>}t_task;
--------------------------------------------------------------------------
--------------------------------------------------------------------------
>int cmp(t_task *a,t_task *b){
>       return (a->value-b->value);
>}

>RB_HEAD(task_type,_task)task_pool\
>=RB_INITIALIZER(&task_pool);

>RB_PROTOTYPE(task_type,_task,entry,cmp);
>RB_GENERATE(task_type,_task,entry,cmp);
--------------------------------------------------------------------------
void init_pthreadpool(){
       pthread_t pid;
       pthread_pool_t *item=NULL;
       create_pthread_pool();
       LIST_FOREACH(item,&pthread_pool,entry){
             pthread_create(&(item->pid),NULL,item->call_back,item->arg);//not modify attrbute pthread
       }

}  
```
```
   void destroy_pool(){
        pthread_pool_t *item=NULL;
        pthread_pool_t *pre=NULL;
         LIST_FOREACH(item,&pthread_pool,entry){
                pre=item;
                pthread_mutex_destroy(&(item->mutex));
                LIST_REMOVE(item,entry);
                info();
                free(pre);
                pre=NULL;
         }
         LIST_FIRST(&pthread_pool)=NULL;

}
                          
```



## Contributing

I will always merge *working* bug fixes. However, if you want to add something new to the API, please create an "issue" on github for this first  if i am free i will merge them if it's right
Remember to follow jackwu's code style and write appropriate tests.

## License
[The MIT License (MIT)](http://opensource.org/licenses/mit-license.php)

