#include <iostream>
using namespace std;

class ArrayOperations {
private:
    int arr[100];
    int size;

public:
    // Constructor to initialize the array size
    ArrayOperations() {
        size = 0;
    }

    // Insert an element at the end of the array
    void insert(int value) {
        if (size < 100) {
            arr[size] = value;
            size++;
            cout << "Element " << value << " inserted successfully.\n";
        } else {
            cout << "Array is full! Cannot insert more elements.\n";
        }
    }

    // Delete an element at a specific index
    void deleteElement(int index) {
        if (index >= 0 && index < size) {
            for (int i = index; i < size - 1; i++) {
                arr[i] = arr[i + 1];
            }
            size--;
            cout << "Element at index " << index << " deleted successfully.\n";
        } else {
            cout << "Invalid index! No element deleted.\n";
        }
    }

    // Check if the array is a palindrome
    bool isPalindrome() {
        int start = 0;
        int end = size - 1;
        while (start < end) {
            if (arr[start] != arr[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    // Search for an element in the array
    void search(int value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                cout << "Element " << value << " found at index " << i << ".\n";
                return;
            }
        }
        cout << "Element " << value << " not found in the array.\n";
    }

    // Display the elements of the array
    void display() {
        if (size == 0) {
            cout << "Array is empty!\n";
            return;
        }
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ArrayOperations arrOps;
    int choice, value, index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Check if Palindrome\n";
        cout << "4. Search Element\n";
        cout << "5. Display Array\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter element to insert: ";
                cin >> value;
                arrOps.insert(value);
                break;
            case 2:
                cout << "Enter index to delete: ";
                cin >> index;
                arrOps.deleteElement(index);
                break;
            case 3:
                if (arrOps.isPalindrome()) {
                    cout << "The array is a palindrome.\n";
                } else {
                    cout << "The array is not a palindrome.\n";
                }
                break;
            case 4:
                cout << "Enter element to search: ";
                cin >> value;
                arrOps.search(value);
                break;
            case 5:
                arrOps.display();
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
