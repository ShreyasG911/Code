#include<iostream>
#include<unistd.h>
using namespace std;
int main()
{
    int pid;
    pid=getpid();
    cout<<"Pid = "<<pid<<endl<<endl;
    fork();
    fork();
    fork();
    cout<<"Hello World..!"<<endl;
    return 0;;
}
