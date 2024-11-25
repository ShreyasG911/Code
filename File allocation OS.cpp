#include <iostream>
using namespace std;

// Function for Sequential Allocation
void sequentialAllocation(int fileSize, int startBlock) {
    cout << "Sequential Allocation:" << endl;
    cout << "Start Block: " << startBlock << endl;
    cout << "Allocated Blocks: ";
    for (int i = startBlock; i < startBlock + fileSize; i++) {
        cout << i << " ";
    }
    cout << endl;
}

// Function for Indexed Allocation
void indexedAllocation(int fileSize, int indexBlock) {
    int blocks[fileSize];
    cout << "Indexed Allocation:" << endl;
    cout << "Index Block: " << indexBlock << endl;
    cout << "Enter " << fileSize << " data block numbers: ";
    for (int i = 0; i < fileSize; i++) {
        cin >> blocks[i];
    }
    cout << "Data blocks stored at index " << indexBlock << ": ";
    for (int i = 0; i < fileSize; i++) {
        cout << blocks[i] << " ";
    }
    cout << endl;
}

// Function for Linked Allocation
void linkedAllocation(int fileSize) {
    int blocks[fileSize];
    cout << "Linked Allocation:" << endl;
    cout << "Enter " << fileSize << " data block numbers in sequence: ";
    for (int i = 0; i < fileSize; i++) {
        cin >> blocks[i];
    }
    cout << "Linked list of blocks: ";
    for (int i = 0; i < fileSize - 1; i++) {
        cout << blocks[i] << " -> ";
    }
    cout << blocks[fileSize - 1] << endl;
}

// Main function
int main() {
    int choice, fileSize, startBlock, indexBlock;

    while (true) {
        cout << "\nFile Allocation Strategies:" << endl;
        cout << "1. Sequential Allocation" << endl;
        cout << "2. Indexed Allocation" << endl;
        cout << "3. Linked Allocation" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }

        cout << "Enter the file size (number of blocks): ";
        cin >> fileSize;

        switch (choice) {
        case 1:
            cout << "Enter the starting block: ";
            cin >> startBlock;
            sequentialAllocation(fileSize, startBlock);
            break;
        case 2:
            cout << "Enter the index block number: ";
            cin >> indexBlock;
            indexedAllocation(fileSize, indexBlock);
            break;
        case 3:
            linkedAllocation(fileSize);
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
