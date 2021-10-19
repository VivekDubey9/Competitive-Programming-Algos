
#include <iostream>
#define MAX 10
using namespace std;

int graph[MAX][MAX];
void getdata(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            graph[i][j]=0;
            else
            {
            cout<<"Enter edge from vertex "<<i+1<<" to vertex "<<j+1;
            cin>>graph[i][j];
            graph[j][i]=graph[i][j];
            }
            

            
        } 
    }
}

void showdata(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<graph[i][j];
        } 
            cout<<endl;
    }
}

void sortbyedge(int n)
{
    int i,j, min=graph[1][2];
    for(i=0;i<n;i++)
    for(j=i;j<n;j++)
    {
    if(i == j)
        continue;
    if(min>graph[i][j])
        min = graph[i][j];
    }
    cout<<"minimum is"<<min;
        
}



int main()
{
    int n;
    
    cout<<"Enter number of vertex ";
    cin>>n;
    getdata(n);
    showdata(n);
    sortbyedge(n);


    return 0;
}
