/*Given a long list of tasks. Each task takes specific time to accomplish it and each task has a
deadline associated with it. You have to design an algorithm and implement it using a program to
find maximum number of tasks that can be completed without crossing their deadlines and also
find list of selected tasks.*/
#include <bits/stdc++.h>
using namespace std;

struct Task {
    int time;
    int deadline;
    int index;

    bool operator<(const Task& other) const {
        return deadline < other.deadline;
    }
};

 vector<int> findMaxTasks(const  vector<int>& times, const  vector<int>& deadlines) {
    int n = times.size();

     vector<Task> tasks(n);
    for (int i = 0; i < n; i++) {
        tasks[i].time = times[i];
        tasks[i].deadline = deadlines[i];
        tasks[i].index = i + 1;
    }

     sort(tasks.begin(), tasks.end());

     vector<int> selectedTasks;
    int maxTasks = 0;
    int currentTime = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime + tasks[i].time <= tasks[i].deadline) {
            selectedTasks.push_back(tasks[i].index);
            maxTasks++;
            currentTime += tasks[i].time;
        }
    }

     cout << "Max number of tasks = " << maxTasks <<  endl;
     cout << "Selected task numbers: ";
    for (int i = 0; i < maxTasks; i++) {
         cout << selectedTasks[i] << " ";
    }
     cout <<  endl;

    return selectedTasks;
}

int main() {
    int n;
     cin >> n;

     vector<int> times(n);
     vector<int> deadlines(n);

    for (int i = 0; i < n; i++) {
         cin >> times[i];
    }

    for (int i = 0; i < n; i++) {
         cin >> deadlines[i];
    }

     vector<int> selectedTasks = findMaxTasks(times, deadlines);

    return 0;
}
