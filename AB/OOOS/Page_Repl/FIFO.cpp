// #include <stdio.h>

// void main() {
//     int i, j, k, f, pf = 0, count = 0, rs[25], m[10], n;
//     printf("\nEnter the length of the reference string -- ");
//     scanf("%d", &n);
//     printf("\nEnter the reference string -- ");
//     for (i = 0; i < n; i++)
//         scanf("%d", &rs[i]);
//     printf("\nEnter the number of frames -- ");
//     scanf("%d", &f);
//     for (i = 0; i < f; i++)
//         m[i] = -1;
//     printf("\nThe Page Replacement Process is --\n");
//     for (i = 0; i < n; i++) {
//         for (k = 0; k < f; k++) {
//             if (m[k] == rs[i])
//                 break;
//         }
//         if (k == f) {
//             m[count++] = rs[i];
//             pf++;
//         }
//         for (j = 0; j < f; j++)
//             printf("\t%d", m[j]);
//         if (k == f)
//             printf("\tPF No. %d", pf);
//         printf("\n");
//         if (count == f)
//             count = 0;
//     }
//     printf("\nThe number of Page Faults using FIFO is %d\n", pf);
// }



#include <stdio.h>
int main()
{

    int referenceString[10], pageFaults = 0, m, n, s, pages, frames;
    printf("\nEnter the number of Pages: ");
    scanf("%d", &pages);
    printf("\nEnter reference string values:\n");
    for (m = 0; m < pages; m++)
    {
        printf("Value No. [%d]:\t", m + 1);
        scanf("%d", &referenceString[m]);
    }
    printf("\n What are the total number of frames:\t");
    scanf("%d", &frames);

    int temp[frames];
    for (m = 0; m < frames; m++)
    {
        temp[m] = -1;
    }
    for (m = 0; m < pages; m++)
    {
        s = 0;
        for (n = 0; n < frames; n++)
        {
            if (referenceString[m] == temp[n])
            {
                s++;
                pageFaults--;
            }
        }
        pageFaults++;
        if ((pageFaults <= frames) && (s == 0))
        {
            temp[m] = referenceString[m];
        }
        else if (s == 0)
        {
            temp[(pageFaults - 1) % frames] = referenceString[m];
        }
        printf("\n");
        for (n = 0; n < frames; n++)
        {
            printf("%d\t", temp[n]);
        }
    }
    printf("\nTotal Page Faults(page miss):\t%d\n", pageFaults);
    printf("Total page hits: %d", pages - pageFaults);
    return 0;
}