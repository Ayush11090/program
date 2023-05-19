#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int sstf(int arr[], int size, int head) {
    int sum = 0;
    while (size > 0) {
        int min_dist = abs(arr[0] - head);
        int min_idx = 0;
        for (int i = 1; i < size; i++) {
            int dist = abs(arr[i] - head);
            if (dist < min_dist) {
                min_dist = dist;
                min_idx = i;
            }
        }
        sum += min_dist;
        head = arr[min_idx];
        for (int i = min_idx; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }
        size--;
    }
    return sum;
}

int main() {
    int track_no[100];
    int num_track;
    printf("Enter the number of tracks: ");
    scanf("%d", &num_track);
    printf("Enter the track numbers between 0-200:\n");
    for (int i = 0; i < num_track; i++) {
        scanf("%d", &track_no[i]);
    }
    printf("Enter the value of head pointer: ");
    int curr_pos_head;
    scanf("%d", &curr_pos_head);
    int ans = sstf(track_no, num_track, curr_pos_head);
    printf("Total number of track movements: %d\n", ans);
    return 0;
}