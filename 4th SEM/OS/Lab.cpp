
                                        //FCFS scheduling with n process id
#include<iostream>
using namespace std;

int main(){
    int pid[15], bt[15], wt[15], tat[15];
    int n;

    cout<<"Enter no. of process: ";
    cin>>n;

    cout<<"Enter process id of all process:\n";
    for(int i = 0; i < n; i++){
        cin>>pid[i];
    }

    cout<<"Enter burst time of all process:\n";
    for(int i = 0; i < n; i++){
        cin>>bt[i];
    }

    // Waiting time calculation
    wt[0] = 0;
    for(int i = 1; i < n; i++){
        wt[i] = wt[i-1] + bt[i-1];
    }

    // Turnaround time calculation
    for(int i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];
    }

    float total_wt = 0, total_tat = 0;

    cout<<"\nPID\tBT\tWT\tTAT\n";
    for(int i = 0; i < n; i++){
        cout<<pid[i]<<"\t"<<bt[i]<<"\t"<<wt[i]<<"\t"<<tat[i]<<endl;
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float awt = total_wt / n;
    float att = total_tat / n;

    cout<<"\nAverage Waiting Time = "<<awt;
    cout<<"\nAverage Turnaround Time = "<<att;

    return 0;
}

                                                    //different arrival time
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

                                                            //SJF
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int pid[n], at[n], bt[n], ct[n], wt[n], tat[n];
    bool done[n] = {false};

    // Input
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        cout << "Enter Arrival Time of P" << pid[i] << ": ";
        cin >> at[i];
        cout << "Enter Burst Time of P" << pid[i] << ": ";
        cin >> bt[i];
    }

    int completed = 0, time = 0;

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        // Find process with smallest burst time among arrived
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && !done[i]) {
                if (bt[i] < minBT) {
                    minBT = bt[i];
                    idx = i;
                }
            }
        }

        if (idx == -1) {
            time++; // CPU idle
        } else {
            ct[idx] = time + bt[idx];
            time = ct[idx];

            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            done[idx] = true;
            completed++;
        }
    }

    float total_wt = 0, total_tat = 0;

    cout << "\nP\tAT\tBT\tCT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << pid[i] << "\t"
             << at[i] << "\t"
             << bt[i] << "\t"
             << ct[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;

        total_wt += wt[i];
        total_tat += tat[i];
    }

    cout << "\nAverage Waiting Time = " << total_wt / n;
    cout << "\nAverage Turnaround Time = " << total_tat / n;

    return 0;
}