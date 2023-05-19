#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


pthread_mutex_t wrt,mutex;
int cnt = 1;
int numreader = 0;

void *writer(void *wno)
{   
    pthread_mutex_lock(&wrt);
    cnt = cnt*2;
    printf("Writer %d modified cnt to %d\n",(*((int *)wno)),cnt);
    sleep(1);
    pthread_mutex_unlock(&wrt);
}
void *reader(void *rno)
{   
    pthread_mutex_lock(&mutex);
    numreader++;
    pthread_mutex_unlock(&mutex);
    
    if(numreader == 1) {
        pthread_mutex_lock(&wrt);   
    }
    printf("Reader %d: read cnt as %d\n",*((int *)rno),cnt);
    sleep(1);
    
    pthread_mutex_lock(&mutex);
    numreader--;
    
    pthread_mutex_unlock(&mutex);
    if(numreader == 0) {
        pthread_mutex_unlock(&wrt); 
    }
}

int main()
{   

    pthread_t read[10],write[5];
    pthread_mutex_init(&mutex, NULL);
    pthread_mutex_init(&wrt,NULL);

    int a[10] = {1,2,3,4,5,6,7,8,9,10}; 

    for(int i = 0; i < 10; i++) {
        pthread_create(&read[i], NULL, (void *)reader, (void *)&a[i]);
    }
    for(int i = 0; i < 5; i++) {
        pthread_create(&write[i], NULL, (void *)writer, (void *)&a[i]);
    }

    for(int i = 0; i < 10; i++) {
        pthread_join(read[i], NULL);
    }
    for(int i = 0; i < 5; i++) {
        pthread_join(write[i], NULL);
    }

    pthread_mutex_destroy(&mutex);


    return 0;

}
