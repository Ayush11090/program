#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<semaphore.h>

char buffer[20];
void *produce();
void *consume();
pthread_mutex_t mut;

int main()
{
   void *status;
   pthread_t p_thr,c_thr;
   pthread_mutex_init(&mut,0);
   pthread_create(&p_thr,NULL,(void*)&produce,NULL);
   pthread_create(&c_thr,NULL,(void*)&consume,NULL);
   pthread_join(p_thr,&status);
   pthread_join(c_thr,&status);
   return 0;
}

void *produce()
{
   char str[20];

   while(1)
   {    
         
       pthread_mutex_lock(&mut);
         printf("\nENTER A STRING:");
    scanf("%s",str);

        strcpy(buffer,str);
        pthread_mutex_unlock(&mut);
        sleep(1);
  }

}

void *consume()
{
     char str1[20];

     while(1)
     {
         pthread_mutex_lock(&mut);
         strcpy(str1,buffer);
         printf("\nTHE CONSUMED STRING IS :%s",str1);
         pthread_mutex_unlock(&mut);
         sleep(1);
     }
}
