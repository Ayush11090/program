#include <stdio.h>
#include <stdlib.h>

void fcfs(int requests[], int n, int head) {
    int seek_time = 0;
    int curr_track = head;
    
    printf("FCFS Disk Scheduling Algorithm\n");
    printf("=================================\n");
    printf("Head Position: %d\n", head);
    printf("Requests: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", requests[i]);
        seek_time += abs(curr_track - requests[i]);
        curr_track = requests[i];
    }
    printf("\nTotal Seek Time: %d\n", seek_time);
    printf("=================================\n");
}

int main() {
    int requests;
    printf("Enter no of requests: ");
    scanf("%d", &requests);
  
    int diskQueue[requests];
    printf("Enter Request : \n");
    for (int i = 0; i < requests; i++)
    {
        scanf("%d", &diskQueue[i]);
    }
    printf("Enter current head position\n");
    int currentHeadPosition;
   
    scanf("%d", &currentHeadPosition);
    fcfs(diskQueue, requests, currentHeadPosition);
    return 0;
}
