#include <iostream>
using namespace std;
int main() {
int n;
cout << "Enter the number of processes: ";
cin >> n;
int pid[n], arrivalTime[n], burstTime[n], completionTime[n], turnAroundTime[n], waitingTime[n];
for (int i = 0; i < n; i++) {
cout << "Enter Process ID for process " << i + 1 << ": ";
cin >> pid[i];
cout << "Enter Arrival Time for process " << i + 1 << ": ";
cin >> arrivalTime[i];
cout << "Enter Burst Time for process " << i + 1 << ": ";
cin >> burstTime[i];
}
int currentTime = 0;
float totalTAT = 0, totalWT = 0;
for (int i = 0; i < n; i++) {
if (currentTime < arrivalTime[i]) {
currentTime = arrivalTime[i];
}
currentTime += burstTime[i];
completionTime[i] = currentTime;
turnAroundTime[i] = completionTime[i] - arrivalTime[i];
waitingTime[i] = turnAroundTime[i] - burstTime[i];
totalTAT += turnAroundTime[i];
totalWT += waitingTime[i];
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