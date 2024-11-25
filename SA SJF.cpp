#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int pid[n], arrivalTime[n], burstTime[n], completionTime[n];
    int turnAroundTime[n], waitingTime[n];
    bool completed[n] = {false};

    for (int i = 0; i < n; i++) {
        cout << "Enter Process ID for process " << i + 1 << ": ";
        cin >> pid[i];
        cout << "Enter Arrival Time for process " << i + 1 << ": ";
        cin >> arrivalTime[i];
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> burstTime[i];
    }

    int currentTime = 0, completedProcesses = 0;
    float totalTAT = 0, totalWT = 0;

    while (completedProcesses < n) {
        int nextProcess = -1; // To identify the process with the shortest burst time

        for (int i = 0; i < n; i++) {
            if (!completed[i] && arrivalTime[i] <= currentTime) {
                if (nextProcess == -1 || burstTime[i] < burstTime[nextProcess]) {
                    nextProcess = i;
                }
            }
        }

        if (nextProcess != -1) {
            currentTime += burstTime[nextProcess];
            completionTime[nextProcess] = currentTime;
            turnAroundTime[nextProcess] = completionTime[nextProcess] - arrivalTime[nextProcess];
            waitingTime[nextProcess] = turnAroundTime[nextProcess] - burstTime[nextProcess];
            completed[nextProcess] = true;

            totalTAT += turnAroundTime[nextProcess];
            totalWT += waitingTime[nextProcess];
            completedProcesses++;
        } else {
            currentTime++; // Increment time if no process is ready
        }
    }

    // Display the results
    cout << "\nPID\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n";
    for (int i = 0; i < n; i++) {
        cout << pid[i] << "\t" << arrivalTime[i] << "\t" << burstTime[i] << "\t"
             << completionTime[i] << "\t\t" << turnAroundTime[i] << "\t\t" << waitingTime[i] << endl;
    }

    cout << "\nAverage Turn Around Time: " << totalTAT / n << endl;
    cout << "Average Waiting Time: " << totalWT / n << endl;

    return 0;
}
