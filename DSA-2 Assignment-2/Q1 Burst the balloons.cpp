/*
#include<bits/stdc++.h>
using namespace std;

struct Activity {
    int name;
    int start;
    int finish;
};


bool compare_activities(Activity a1, Activity a2) {
    return a1.finish <= a2.finish;
}

void activity_selection(int start_times[], int finish_times[], int nActivities) {
    Activity all_activities[nActivities];
    for(int i=0; i<nActivities; i++) {
        all_activities[i].name = i;
        all_activities[i].start = start_times[i];
        all_activities[i].finish = finish_times[i];
    }

    sort(all_activities, all_activities+nActivities, compare_activities);
    /*
    sort(all_activities, all_activities + nActivities, [](const Activity& a1, const Activity& a2) {
    if (a1.finish == a2.finish) {
        return a1.start < a2.start;
    }
    return a1.finish < a2.finish;
});
/

    cout << "\nActivities after sorting " << endl;
    for(int j = 0; j < nActivities; j++) {
        cout << "Activity: " << all_activities[j].name
        << "   Start: " << all_activities[j].start
        << "    Finish: " << all_activities[j].finish << endl;
    }

    vector<Activity> selected_activities;

    int current = 0;
    selected_activities.push_back(all_activities[current]);
    int count = 1;
    for (int k = current+1; k < nActivities; k++) {
        if(all_activities[k].start >= all_activities[current].finish) {
            selected_activities.push_back(all_activities[k]);
            current = k;
            count++;
        }
    }
    printf("\nThe balloons can be burst by %d arrows:", count);

    cout << "\nSelected Activities: " << endl;
    for(Activity a : selected_activities) {
        cout << "Activity: " << a.name
        << "   Start: " << a.start
        << "    Finish: " << a.finish << endl;
    }

    return;
}


int main() {
    int n;
    printf("Enter How many no of Activities you use: ");
    cin >> n;

    int start_times[n];
    int finish_times[n];

for (int i = 0; i < n; i++)
{
    printf("Activity %d Stat & Finish times: ", i);
    cin>>start_times[i]>>finish_times[i];
}

    activity_selection(start_times, finish_times, n);

    return 0;

}
*/

/*
Trail-1:
4
10 16
2 8
1 6
7 12

Trail-2:
4
1 2
3 4
5 6
7 8
*/





#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long target;
    cin >> target;

    vector<pair<long long, int>> v;
    for (int i = 0; i < n; i++) {
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        long long need = target - v[i].first;
        int l = i + 1, r = n - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (v[mid].first == need) {
                cout << v[i].second << " " << v[mid].second;
                return 0;
            }
            else if (v[mid].first < need) {
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
    }

    return 0;
}
