#include<stdio.h>
int main()
{

    printf("Enter the length of the reference string :");
    int n;
    scanf("%d",&n);

    printf("Enter the reference string : ");
    int i,j,k,rs[n],flag[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&rs[i]);
        flag[i]=0;
    }
    int f;
    printf("Enter the number of frames : ");
    scanf("%d",&f);


    int m[f],count[f];
    for(i=0;i<f;i++)
    {
        count[f]=0;
        m[i]=-1;
    }
    int pagefault=0;
    int next=0,min=0;
    //Page Replacement Process
    for(i=0;i<n;i++)
    {
        //Page hit
        for(j=0;j<f;j++)
        {
            if(m[j]==rs[i])
                {
                    flag[i]=1;
                    count[j]=next;
                    next++;


                }
        }
        if(flag[i]==0)
        {
            if(i<f)
            {
                m[i]=rs[i];
                count[i]=next;
                next++;;
            }
            else
            {
                min=0;
                for(j=1;j<f;j++)
                    if(count[min]>count[j])
                    min=j;
                m[min]=rs[i];
                count[min]=next;
                next++;
            }
            pagefault++;
        }
        for(j=0;j<f;j++)
            printf("%d\t",m[j]);
        if(flag[i]==0)
            printf("PF No. :%d",pagefault);
        printf("\n");

    }
     printf("Number of page faults using LRU are :%d ",pagefault);
}