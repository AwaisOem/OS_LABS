#include<iostream>
#include<algorithm>
using namespace std;

const int n = 5;

class PriorityScheduling {
private:
    int cpu[n], arr_t[n], turn_tm[n], wait_tm[n], priority[n];
    int assign[n], comp[n];
    float avg_turn_around_time, avg_waiting_time;

public:
    void get() {
        for(int i = 0; i < n; i++) {
            cout << "Enter the CPU burst of p" << i << " process: ";
            cin >> cpu[i];

            cout << "Enter the Arrival time of p" << i << " process: ";
            cin >> arr_t[i];

            cout << "Enter the Priority of p" << i << " process: ";
            cin >> priority[i];
        }
        cout << "\n==================================================\n";
    }

    void turn_around_time() {
        float sum = 0;
        for(int i = 0; i < n; i++) {
            turn_tm[i] = comp[i] - arr_t[i];
            sum += turn_tm[i];
        }
        avg_turn_around_time = sum / n;
    }

    void waiting_time() {
        float sum = 0.0;
        for(int i = 0; i < n; i++) {
            wait_tm[i] = assign[i] - arr_t[i];
            sum += wait_tm[i];
        }
        avg_waiting_time = sum / n;
    }

    void show() {
        cout << "Process \tCPU Burst \tArrival Time \tWaiting Time \tTurn Around Time\n";
        for(int i = 0; i < n; i++) {
            cout << "p" << i << "\t\t" << cpu[i] << "\t\t" << arr_t[i] << "\t\t" << wait_tm[i] << "\t\t" << turn_tm[i] << endl;
        }
        cout << "The average waiting time is = " << avg_waiting_time << endl;
        cout << "The average turn around time is = " << avg_turn_around_time << endl;
    }

    void sortByPriority() {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n - i - 1; j++) {
                if(priority[j] > priority[j + 1]) {
                    swap(priority[j], priority[j + 1]);
                    swap(cpu[j], cpu[j + 1]);
                    swap(arr_t[j], arr_t[j + 1]);
                }
            }
        }
    }
};

int main() {
    PriorityScheduling priorityScheduling;
    priorityScheduling.get();
    priorityScheduling.sortByPriority();
    priorityScheduling.waiting_time();
    priorityScheduling.turn_around_time();
    priorityScheduling.show();

    return 0;
}
