#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time of P" << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time of P" << pid[i] << ": ";
        cin >> bt[i];
    }

    // Sorting by Arrival Time (FCFS rule)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                swap(at[i], at[j]);
                swap(bt[i], bt[j]);
                swap(pid[i], pid[j]);
            }
        }
    }

    // Calculate Completion Time
    ct[0] = at[0] + bt[0];

    for (int i = 1; i < n; i++) {
        if (ct[i-1] < at[i]) {
            ct[i] = at[i] + bt[i];  // CPU idle case
        } else {
            ct[i] = ct[i-1] + bt[i];
        }
    }

    // Calculate TAT and WT
    float total_wt = 0, total_tat = 0;

    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_wt += wt[i];
        total_tat += tat[i];
    }

    // Output
    cout << "\nP\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turnaround Time = " << total_tat / n;

    return 0;
}