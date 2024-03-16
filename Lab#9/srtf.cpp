#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Process {
    int processNo;
    int arrivalTime;
    int cpuBurst;
    int priority;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int remainingBurst;
    bool completed;
};

bool compareArrival(const Process &a, const Process &b) {
    return a.arrivalTime < b.arrivalTime;
}

bool compareRemainingBurst(const Process &a, const Process &b) {
    return a.remainingBurst < b.remainingBurst;
}

void SRTF(vector<Process> &processes) {
    int n = processes.size();
    int currentTime = 0;
    int completedProcesses = 0;

    while (completedProcesses < n) {
        // Sort processes by remaining burst time
        sort(processes.begin(), processes.end(), compareRemainingBurst);

        // Find the process with the shortest remaining burst time
        int currentProcess = -1;
        for (int i = 0; i < n; ++i) {
            if (!processes[i].completed && processes[i].arrivalTime <= currentTime) {
                currentProcess = i;
                break;
            }
        }

        if (currentProcess == -1) {
            // No process is ready to execute, move to the next arrival time
            currentTime = processes[0].arrivalTime;
        } else {
            // Execute the process for 1 time unit
            processes[currentProcess].remainingBurst--;

            // Check if the process is completed
            if (processes[currentProcess].remainingBurst == 0) {
                processes[currentProcess].completionTime = currentTime + 1;
                processes[currentProcess].turnaroundTime = processes[currentProcess].completionTime - processes[currentProcess].arrivalTime;
                processes[currentProcess].waitingTime = processes[currentProcess].turnaroundTime - processes[currentProcess].cpuBurst;
                processes[currentProcess].completed = true;
                completedProcesses++;
            }

            currentTime++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].processNo = i + 1;
        cout << "Enter arrival time for Process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime;
        cout << "Enter CPU burst for Process " << i + 1 << ": ";
        cin >> processes[i].cpuBurst;
        cout << "Enter priority for Process " << i + 1 << ": ";
        cin >> processes[i].priority;
        processes[i].remainingBurst = processes[i].cpuBurst;
        processes[i].completed = false;
    }

    // Sort processes by arrival time
    sort(processes.begin(), processes.end(), compareArrival);

    SRTF(processes);

    double avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (const Process &p : processes) {
        avgTurnaroundTime += p.turnaroundTime;
        avgWaitingTime += p.waitingTime;
    }

    avgTurnaroundTime /= n;
    avgWaitingTime /= n;

    cout << "\nProcess\tArrival Time\tBurst Time\tPriority\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (const Process &p : processes) {
        cout << "P" << p.processNo << "\t" << p.arrivalTime << "\t\t" << p.cpuBurst << "\t\t" << p.priority << "\t\t"
             << p.completionTime << "\t\t" << p.turnaroundTime << "\t\t" << p.waitingTime << endl;
    }

    cout << "\nAverage Turnaround Time: " << avgTurnaroundTime << endl;
    cout << "Average Waiting Time: " << avgWaitingTime << endl;

    return 0;
}
