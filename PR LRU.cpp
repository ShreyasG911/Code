#include <iostream>
using namespace std;

int lruPageReplacement(int referenceString[], int n, int frameCount) {
    int frames[frameCount];   // Array to store the pages in memory
    int time[frameCount];     // Array to track when each frame was last used
    int pageFaults = 0;       // Total page faults
    int currentTime = 0;      // Time counter to track usage

    // Initialize frames and time arrays
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1; // -1 means the frame is empty
        time[i] = 0;    // Initialize time to 0
    }

    for (int i = 0; i < n; i++) {
        int currentPage = referenceString[i];
        bool pageFound = false;

        // Check if the page is already in a frame
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageFound = true;
                time[j] = currentTime; // Update the time for the page
                break;
            }
        }

        // If page is not found, handle the page fault
        if (!pageFound) {
            pageFaults++;
            int lruIndex = 0;

            // Find the least recently used page (smallest time value)
            for (int j = 1; j < frameCount; j++) {
                if (time[j] < time[lruIndex]) {
                    lruIndex = j;
                }
            }

            // Replace the LRU page
            frames[lruIndex] = currentPage;
            time[lruIndex] = currentTime; // Update time for the new page
        }

        currentTime++; // Increment time after each page reference
    }

    return pageFaults;
}

int main() {
    int n, frameCount;

    // Input number of pages and reference string
    cout << "Enter the number of pages: ";
    cin >> n;
    int referenceString[n];

    cout << "Enter the reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> referenceString[i];
    }

    // Input number of frames
    cout << "Enter the number of frames: ";
    cin >> frameCount;

    // Calculate and display page faults
    int pageFaults = lruPageReplacement(referenceString, n, frameCount);
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
