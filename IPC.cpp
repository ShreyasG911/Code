#include<iostream>
#include<unistd.h>
using namespace std;

int main() {
    int pipefds[2];
    int returnstatus;
    int pid;
    char writemessages[2][20] = {"Hi", "Hello"};
    char readmessage[20];

    returnstatus = pipe(pipefds);

    if (returnstatus == -1) {
        cout << "Unable to create pipe\n";
        return 1;
    }

    pid = fork();

    if (pid == 0) {
        // Child process
        read(pipefds[0], readmessage, sizeof(readmessage));
        cout << "Child process - Reading from pipe - message 1 is: " << readmessage << endl;
        read(pipefds[0], readmessage, sizeof(readmessage));
        cout << "Child process - Reading from pipe - message 2 is: " << readmessage << endl;
    } else {
        // Parent process
        cout << "Parent process - Writing to pipe - message 1 is: " << writemessages[0] << endl;
        write(pipefds[1], writemessages[0], sizeof(writemessages[0]));
        cout << "Parent process - Writing to pipe - message 2 is: " << writemessages[1] << endl;
        write(pipefds[1], writemessages[1], sizeof(writemessages[1]));
    }

    return 0;
}