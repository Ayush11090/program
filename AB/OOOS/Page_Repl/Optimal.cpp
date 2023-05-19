# include <iostream>
using namespace std;
class page_rep
{
    public:
        string pagestring;
        int msize;
       void fifo()
       {
            int hit=0,miss=0;
            int *memory = new int[msize],memptr=0;
            for(int i=0;i<msize;i++)
                memory[i]=-1;
            cout<<"FIFO:"<<endl;    
            for(int i=0;i<pagestring.length();i++)
            {
                int curr = pagestring[i]-48;
                int flag=0;
                for(int j=0;j<msize;j++)
                {
                    if(curr==memory[j])
                        flag=1;
                }
                if(flag==1)
                    hit++;
                else
                {
                    miss++;
                    memory[memptr]=curr;
                    memptr++;
                    if(memptr==msize)
                        memptr=0;
                }
                for(int j=0;j<msize;j++)
                    cout<<memory[j]<<"|";
                cout<<endl;
            }
            cout<<"FIFO Hits : "<<hit<<endl;
            cout<<"FIFO Miss : "<<miss<<endl;
       }
       void lru()
       {
            int hit=0,miss=0;
            int *memory = new int[msize],memptr=0;
            for(int i=0;i<msize;i++)
                memory[i]=-1;
            cout<<"LRU:"<<endl;    
            for(int i=0;i<pagestring.length();i++)
            {
                int curr = pagestring[i]-48;
                int flag=0;
                for(int j=0;j<msize;j++)
                {
                    if(curr==memory[j])
                        flag=1;
                }
                if(flag==1)
                    hit++;
                else if(memptr<msize)
                {
                    memory[memptr]=curr;
                    memptr++;
                    miss++;
                }
                else
                {
                    miss++;
                    //lru scan left string, present
                    int *distance = new int[10];
                    int *present = new int[10];
                    for(int j=0;j<10;j++)
                    {
                        present[j]=-1;
                        distance[j]=-1;
                        for(int k=0;k<msize;k++)
                        {
                            if(memory[k]==j)
                                present[j]=k;
                        }
                    }
                    for(int j=0;j<i;j++)
                    {
                        int page = pagestring[j]-48;
                        distance[page] = i-j;
                    }
                    int max=0,num;
                    for(int j=0;j<10;j++)
                    {
                        if(distance[j]>max && present[j]>-1)
                        {
                            max=distance[j];
                            num = present[j];
                        }
                    }
                    memory[num] = curr;
                }
                for(int j=0;j<msize;j++)
                    cout<<memory[j]<<"|";
                cout<<endl;
            }
            cout<<"LRU Hits : "<<hit<<endl;
            cout<<"LRU Miss : "<<miss<<endl;
       }
       void optimal()
       {
            int hit=0,miss=0;
            int *memory = new int[msize],memptr=0;
            for(int i=0;i<msize;i++)
                memory[i]=-1;
            cout<<"Optimal:"<<endl;    
            for(int i=0;i<pagestring.length();i++)
            {
                int curr = pagestring[i]-48;
                int flag=0;
                for(int j=0;j<msize;j++)
                {
                    if(curr==memory[j])
                        flag=1;
                }
                if(flag==1)
                    hit++;
                else if(memptr<msize)
                {
                    memory[memptr]=curr;
                    memptr++;
                    miss++;
                }
                else
                {
                    miss++;
                    //optimal scan right string, present
                    int *distance = new int[10];
                    int *present = new int[10];
                    for(int j=0;j<10;j++)
                    {
                        present[j]=-1;
                        distance[j]=-1;
                        for(int k=0;k<msize;k++)
                        {
                            if(memory[k]==j)
                                present[j]=k;
                        }
                    }
                    for(int j=i+1;j<pagestring.length();j++)
                    {
                        int page = pagestring[j]-48;
                        distance[page] = j-i;
                    }
                    int max=0,num=-1;
                    for(int j=0;j<10;j++)
                    {
                        if(distance[j]>max && present[j]>-1)
                        {
                            max=distance[j];
                            num = present[j];
                        }
                    }
                    if(num>-1)
                        memory[num] = curr;
                }
                for(int j=0;j<msize;j++)
                    cout<<memory[j]<<"|";
                cout<<endl;
            }
            cout<<"Optimal Hits : "<<hit<<endl;
            cout<<"Optimal Miss : "<<miss<<endl;
       }
};

int main()
{
    page_rep obj;
    cout<<"Enter the page string : "<<endl;
    cin>>obj.pagestring;
    cout<<"Enter the memory size : "<<endl;
    cin>>obj.msize;
    obj.fifo();
    obj.lru();
    obj.optimal();
    return 0;
}