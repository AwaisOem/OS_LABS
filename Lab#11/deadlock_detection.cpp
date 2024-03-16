#include<iostream>
using namespace std;

void deadlockDetection(int processes, int resources, int alloc[3][3], int max[3][3], int need[3][3], int avail[3]) {
    int finish[processes] = {0}; // Array to track if a process has finished
    int work[resources];          // Array to represent the available resources

    // Copy the available resources to the work array
    for (int i = 0; i < resources; i++) {
        work[i] = avail[i];
    }

    int count = 0; // Count of finished processes

    while (count < processes) {
        int found = 0; // Flag to check if a process can be allocated resources in the current state

        for (int i = 0; i < processes; i++) {
            if (finish[i] == 0) {
                int j;
                for (j = 0; j < resources; j++) {
                    if (need[i][j] > work[j]) {
                        break;
                    }
                }

                if (j == resources) {
                    // If all resources are available, allocate them to process i
                    for (int k = 0; k < resources; k++) {
                        work[k] += alloc[i][k];
                    }

                    finish[i] = 1; // Mark process i as finished
                    found = 1;
                    count++;
                }
            }
        }

        if (found == 0) {
            // If no process can be allocated, break the loop to avoid an infinite loop
            break;
        }
    }

    if (count < processes) {
        cout << "System is in a deadlock state." << endl;
    } else {
        cout << "System is not in a deadlock state." << endl;
    }
}

int main() {
    int p, r;
    cout << "\t Enter the number of processes: ";
    cin >> p;
    cout << "\n\t Enter the number of resources: ";
    cin >> r;

    int alloc[3][3], max[3][3], avail[3], need[3][3];

    // User input for allocation table, maximum table, and available resources
    // (Same as in the provided code)

    cout << "Enter the available table: \n";
    for (int i = 0; i < r; i++) {
        cout << "\t\tEnter resources R" << i + 1 << "\t";
        cin >> avail[i];
    }

    cout << "The Remaining Needs Are :\n";
    cout << "\t";
    for (int i = 0; i < r; i++) {
        cout << "\tR" << i + 1 << "  ";
    }
    cout << "\n";
    for (int i = 0; i < p; i++) {
        cout << " process p" << i + 1 << "  ";
        for (int j = 0; j < r; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
            cout << need[i][j] << "  ";
        }
        cout << "\n";
    }

    // Call deadlock detection algorithm
    deadlockDetection(p, r, alloc, max, need, avail);

    return 0;
}
