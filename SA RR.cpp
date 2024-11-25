#include <iostream>
using namespace std;
int main() {
int n, timeQuantum;
cout << "Enter the number of processes: ";
cin >> n;
int pid[n], arrivalTime[n], burstTime[n], remainingTime[n], completionTime[n], 
turnAroundTime[n], waitingTime[n];
for (int i = 0; i < n; i++) {
cout << "Enter Process ID for process " << i + 1 << ": ";
cin >> pid[i];
cout << "Enter Arrival Time for process " << i + 1 << ": ";
cin >> arrivalTime[i];
cout << "Enter Burst Time for process " << i + 1 << ": ";
cin >> burstTime[i];
remainingTime[i] = burstTime[i]; 
}
cout << "Enter Time Quantum: ";
cin >> timeQuantum;
int currentTime = 0, completed = 0;
float totalTAT = 0, totalWT = 0;
while (completed < n) {
bool done = true;
for (int i = 0; i < n; i++) {
if (remainingTime[i] > 0) {
done = false;
if (arrivalTime[i] <= currentTime) {
if (remainingTime[i] <= timeQuantum) {
currentTime += remainingTime[i];
remainingTime[i] = 0;
completionTime[i] = currentTime;
turnAroundTime[i] = completionTime[i] - arrivalTime[i];
waitingTime[i] = turnAroundTime[i] - burstTime[i];
completed++;
totalTAT += turnAroundTime[i];
totalWT += waitingTime[i];
} else {
currentTime += timeQuantum;
remainingTime[i] -= timeQuantum;
}
}
}
}
if (done)
break;
}
cout << "\nPID\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n";
for (int i = 0; i < n; i++) {
cout << pid[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t"
<< completionTime[i] << "\t\t" << turnAroundTime[i] << "\t\t" << waitingTime[i] << endl;
}
cout << "\nAverage Turn Around Time: " << totalTAT / n << endl;
cout << "Average Waiting Time: " << totalWT / n << endl;
return 0;
}