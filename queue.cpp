#include<iostream>
using namespace std;

#define MAX 20

template<class T>
class Queue {
    T data[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isqueueFULL();
    bool isqueueEMPTY();
    void addqueue(T d);
    T delqueue();
    T peek();
    void disqueue(); // Updated function to display the queue in a formatted way
};

template<class T>
bool Queue<T>::isqueueFULL() {
    if (rear >= MAX - 1)
        return true;
    else
        return false;
}

template<class T>
bool Queue<T>::isqueueEMPTY() {
    if (front == -1 || front > rear)
        return true;
    else
        return false;
}

template<class T>
void Queue<T>::addqueue(T d) {
    if (!isqueueFULL()) {
        rear++;
        data[rear] = d;
        if (front == -1)
            front = 0;
    } else {
        cout << "Queue is FULL!\n";
    }
}

template<class T>
T Queue<T>::delqueue() {
    if (!isqueueEMPTY()) {
        T temp = data[front];
        front++;
        return temp;
    } else {
        cout << "Queue is EMPTY!\n";
        return T(); // Return default value of T
    }
}

template<class T>
T Queue<T>::peek() {
    if (!isqueueEMPTY()) {
        return data[front];
    } else {
        cout << "Queue is EMPTY!\n";
        return T(); // Return default value of T
    }
}

template<class T>
void Queue<T>::disqueue() {
    if (!isqueueEMPTY()) {
        cout << "Queue elements: [ ";
        for (int i = front; i <= rear; i++) {
            cout << data[i];
            if (i != rear) {
                cout << " | ";  // Separator between elements
            }
        }
        cout << " ]" << endl;
    } else {
        cout << "Queue is EMPTY!\n";
    }
}

int main() {
    int k;
    char ch, innerCh;

    do {
        cout << "Choose data Type:\n1.int\n2.float\n3.double\n4.char\n5.Exit\nINPUT: ";
        cin >> k;

        switch (k) {
        case 1: {
            Queue<int> q1;
            do {
                cout << "choice\n1.ADD in QUEUE\n2.Delete in QUEUE\n3.Value at PEEK\n4.Display QUEUE\n5.Exit\nINPUT: ";
                cin >> k;

                switch (k) {
                case 1: {
                    cout << "Enter size of queue: ";
                    cin >> k;
                    int d[k];
                    cout << "Enter elements in data type: ";
                    for (int i = 0; i < k; i++) {
                        cin >> d[i];
                        q1.addqueue(d[i]);
                    }
                    q1.disqueue(); // Display queue after adding elements
                    break;
                }
                case 2:
                    cout << "Deleted element: " << q1.delqueue() << endl;
                    q1.disqueue(); // Display queue after deletion
                    break;
                case 3:
                    cout << "Value at PEEK: " << q1.peek() << endl;
                    break;
                case 4:
                    q1.disqueue();
                    break;
                case 5:
                    break;
                default:
                    cout << "Enter valid choice!!\n";
                }

                cout << "Do you want to perform another operation in this queue type (Y or N): ";
                cin >> innerCh;
            } while (innerCh == 'Y' || innerCh == 'y');
        }
        break;

        case 2: {
            Queue<float> q1;
            do {
                cout << "choice\n1.ADD in QUEUE\n2.Delete in QUEUE\n3.Value at PEEK\n4.Display QUEUE\n5.Exit\nINPUT: ";
                cin >> k;

                switch (k) {
                case 1: {
                    cout << "Enter size of queue: ";
                    cin >> k;
                    float d[k];
                    cout << "Enter elements in data type: ";
                    for (int i = 0; i < k; i++) {
                        cin >> d[i];
                        q1.addqueue(d[i]);
                    }
                    q1.disqueue(); // Display queue after adding elements
                    break;
                }
                case 2:
                    cout << "Deleted element: " << q1.delqueue() << endl;
                    q1.disqueue(); // Display queue after deletion
                    break;
                case 3:
                    cout << "Value at PEEK: " << q1.peek() << endl;
                    break;
                case 4:
                    q1.disqueue();
                    break;
                case 5:
                    break;
                default:
                    cout << "Enter valid choice!!\n";
                }

                cout << "Do you want to perform another operation in this queue type (Y or N): ";
                cin >> innerCh;
            } while (innerCh == 'Y' || innerCh == 'y');
        }
        break;

        case 3: {
            Queue<double> q1;
            do {
                cout << "choice\n1.ADD in QUEUE\n2.Delete in QUEUE\n3.Value at PEEK\n4.Display QUEUE\n5.Exit\nINPUT: ";
                cin >> k;

                switch (k) {
                case 1: {
                    cout << "Enter size of queue: ";
                    cin >> k;
                    double d[k];
                    cout << "Enter elements in data type: ";
                    for (int i = 0; i < k; i++) {
                        cin >> d[i];
                        q1.addqueue(d[i]);
                    }
                    q1.disqueue(); // Display queue after adding elements
                    break;
                }
                case 2:
                    cout << "Deleted element: " << q1.delqueue() << endl;
                    q1.disqueue(); // Display queue after deletion
                    break;
                case 3:
                    cout << "Value at PEEK: " << q1.peek() << endl;
                    break;
                case 4:
                    q1.disqueue();
                    break;
                case 5:
                    break;
                default:
                    cout << "Enter valid choice!!\n";
                }

                cout << "Do you want to perform another operation in this queue type (Y or N): ";
                cin >> innerCh;
            } while (innerCh == 'Y' || innerCh == 'y');
        }
        break;

        case 4: {
            Queue<char> q1;
            do {
                cout << "choice\n1.ADD in QUEUE\n2.Delete in QUEUE\n3.Value at PEEK\n4.Display QUEUE\n5.Exit\nINPUT: ";
                cin >> k;

                switch (k) {
                case 1: {
                    cout << "Enter size of queue: ";
                    cin >> k;
                    char d[k];
                    cout << "Enter elements in data type: ";
                    for (int i = 0; i < k; i++) {
                        cin >> d[i];
                        q1.addqueue(d[i]);
                    }
                    q1.disqueue(); // Display queue after adding elements
                    break;
                }
                case 2:
                    cout << "Deleted element: " << q1.delqueue() << endl;
                    q1.disqueue(); // Display queue after deletion
                    break;
                case 3:
                    cout << "Value at PEEK: " << q1.peek() << endl;
                    break;
                case 4:
                    q1.disqueue();
                    break;
                case 5:
                    break;
                default:
                    cout << "Enter valid choice!!\n";
                }

                cout << "Do you want to perform another operation in this queue type (Y or N): ";
                cin >> innerCh;
            } while (innerCh == 'Y' || innerCh == 'y');
        }
        break;

        case 5:
            break;

        default:
            cout << "Enter valid choice!!\n";
        }

        cout << "Do you want to choose another queue type (Y or N): ";
        cin >> ch;

    } while (ch == 'Y' || ch == 'y');

    return 0;
}
