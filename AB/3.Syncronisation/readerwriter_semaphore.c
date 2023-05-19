#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>
sem_t r,w;
int h=23,m=59,s=55;
void *reader(),*writer();
int main()
{
        pthread_t rth,wth;
        void *status;
        sem_init(&r,0,0);
        sem_init(&w,0,1);
        
        pthread_create(&rth,NULL,(void *)&reader,NULL);
        pthread_create(&wth,NULL,(void *)&writer,NULL);
        pthread_join(rth,status);
        pthread_join(wth,status);
        sem_destroy(&w);
        sem_destroy(&r);
}

void *writer()
{
while(1)
{
sem_wait(&w);
s=s+1;
if(s==60)
{
        m++;        s=0;
}
if(m==60)
{
h++; m=0;
}
if(h==24)
{
        h=1;
}
//sleep(1);
sem_post(&r);
}

}


void *reader()
{
while(1)
{
sem_wait(&r);
printf("\n Display:\t");
printf("%d:%d:%d",h,m,s);
sem_post(&w);
}
}
