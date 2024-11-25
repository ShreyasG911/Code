#include<iostream>
using namespace std;
int main()
{
    int n,head,td=0;
    cout<<"enter the number of disk requests: ";
    cin>>n;
    int requests[n];

    cout<<"enter the disk block numbers :";
    for(int i=0;i<n;i++)
    {
        cin>>requests[i];
    }
  cout<<"enter the intial head postion:";
  cin>>head;

  for(int i=0;i<n;i++){
    int distance=requests[i]-head;
    if(distance<0){
        distance-=distance;
    }
    td+=distance;
    head=requests[i];
  }
  cout<<"total distance travelled by the disk is : "<<td<<endl;
  return 0;
}