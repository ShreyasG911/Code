#include <iostream>
using namespace std;

int main() {
    int n, frames;
    
    cout << "Enter the number of pages: ";
    cin >> n;
    int pages[n];
    cout << "Enter the pages: ";
    for (int i = 0; i < n; i++) cin >> pages[i];

    cout << "Enter the number of frames: ";
    cin >> frames;
    int frame[frames], pageFaults = 0, index = 0;

    for (int i = 0; i < frames; i++) frame[i] = -1; // Initialize frames

    for (int i = 0; i < n; i++) {
        bool found = false;

        // Check if the page is already in the frame
        for (int j = 0; j < frames; j++) {
            if (frame[j] == pages[i]) {
                found = true;
                break;
            }
        }

        // If page not found, replace the oldest page
        if (!found) {
            frame[index] = pages[i];
            index = (index + 1) % frames;
            pageFaults++;
        }

        // Display current frame content
        cout << "Frame: ";
        for (int j = 0; j < frames; j++) {
            if (frame[j] != -1)
                cout << frame[j] << " ";
            else
                cout << "- ";
        }
        cout << endl;
    }

    cout << "Total Page Faults: " << pageFaults << endl;
    return 0;
}
