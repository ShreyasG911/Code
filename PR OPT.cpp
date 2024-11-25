#include <iostream>
using namespace std;

int optimalPageReplacement(int referenceString[], int n, int frameCount) {
    int frames[frameCount];  // Array to hold the pages in memory
    int pageFaults = 0;      // Counter for page faults

    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < frameCount; i++) {
        frames[i] = -1;
    }

    // Process each page in the reference string
    for (int i = 0; i < n; i++) {
        int currentPage = referenceString[i];
        bool pageFound = false;

        // Check if the page is already in a frame
        for (int j = 0; j < frameCount; j++) {
            if (frames[j] == currentPage) {
                pageFound = true;
                break;
            }
        }

        // If page is not found, handle the page fault
        if (!pageFound) {
            pageFaults++;

            // If there is an empty frame, insert the page there
            bool emptyFrameFound = false;
            for (int j = 0; j < frameCount; j++) {
                if (frames[j] == -1) {
                    frames[j] = currentPage;
                    emptyFrameFound = true;
                    break;
                }
            }

            // If no empty frame, replace the optimal page
            if (!emptyFrameFound) {
                int replaceIndex = 0; // Index of the page to replace
                int farthest = -1;

                // Check future use of each page in the frames
                for (int j = 0; j < frameCount; j++) {
                    int nextUse = -1;
                    for (int k = i + 1; k < n; k++) {
                        if (frames[j] == referenceString[k]) {
                            nextUse = k;
                            break;
                        }
                    }

                    // If the page is never used again, replace it
                    if (nextUse == -1) {
                        replaceIndex = j;
                        break;
                    }

                    // Track the page used farthest in the future
                    if (nextUse > farthest) {
                        farthest = nextUse;
                        replaceIndex = j;
                    }
                }

                // Replace the page
                frames[replaceIndex] = currentPage;
            }
        }
    }

    return pageFaults;
}

int main() {
    int n, frameCount;

    // Input: Number of pages and the reference string
    cout << "Enter the number of pages: ";
    cin >> n;

    int referenceString[n];
    cout << "Enter the reference string: ";
    for (int i = 0; i < n; i++) {
        cin >> referenceString[i];
    }

    // Input: Number of frames
    cout << "Enter the number of frames: ";
    cin >> frameCount;

    // Calculate page faults
    int pageFaults = optimalPageReplacement(referenceString, n, frameCount);

    // Output total page faults
    cout << "Total page faults: " << pageFaults << endl;

    return 0;
}
