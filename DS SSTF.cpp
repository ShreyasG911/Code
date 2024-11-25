#include <iostream>
using namespace std;

int main() {
    int n, head, total_distance = 0;

    cout << "Enter the number of disk requests: ";
    cin >> n;
    int requests[n], done[n] = {0};

    cout << "Enter the requests: ";
    for (int i = 0; i < n; i++) cin >> requests[i];

    cout << "Enter the initial position of the disk head: ";
    cin >> head;

    for (int count = 0; count < n; count++) {
        int min_distance = 1000000, closest = -1;

        for (int i = 0; i < n; i++) {
            if (done[i] == 0) { 
                int distance = head - requests[i];
                if (distance < 0) distance = -distance; 
                if (distance < min_distance) {
                    min_distance = distance;
                    closest = i;
                }
            }
        }

        total_distance = total_distance + min_distance; 
        head = requests[closest]; 
        done[closest] = 1; 
    }

    cout << "Total distance: " << total_distance << endl;
    return 0;
}
