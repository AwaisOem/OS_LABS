#include<iostream>
using namespace std;

const int n = 5;

class FIFOScheduling {
private:
    int cpu[n], arr_t[n], turn_tm[n], wait_tm[n];
    int assign[n], comp[n];
    float avg_turn_around_time, avg_waiting_time;

public:
    void get() {
        for(int i = 0; i < n; i++) {
            cout << "Enter the CPU burst of p" << i << " process: ";
            cin >> cpu[i];

            cout << "Enter the Arrival time of p" << i << " process: ";
            cin >> arr_t[i];

            if(i == 0) {
                assign[i] = arr_t[i];
                comp[i] = arr_t[i] + cpu[i];
            } else {
                assign[i] = comp[i - 1];
                comp[i] = comp[i - 1] + cpu[i];
            }
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
};

int main() {
    FIFOScheduling fifo;
    fifo.get();
    fifo.waiting_time();
    fifo.turn_around_time();
    fifo.show();

    return 0;
}
