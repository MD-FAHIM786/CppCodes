#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> arr;
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Insert Element\n";
        cout << "2. Display Elements\n";
        cout << "3. Search Element (Linear Search)\n";
        cout << "4. Delete Element\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {

            case 1: {
                int value;
                cout << "Enter value to insert: ";
                cin >> value;
                arr.push_back(value);
                cout << "Inserted successfully!\n";
                break;
            }

            case 2: {
                if(arr.empty()) {
                    cout << "Array is empty!\n";
                } else {
                    cout << "Elements: ";
                    for(int x : arr)
                        cout << x << " ";
                    cout << endl;
                }
                break;
            }

            case 3: {
                int key;
                cout << "Enter element to search: ";
                cin >> key;

                auto it = find(arr.begin(), arr.end(), key);

                if(it != arr.end())
                    cout << "Found at index: " << it - arr.begin() << endl;
                else
                    cout << "Element not found!\n";
                break;
            }

            case 4: {
                int value;
                cout << "Enter value to delete: ";
                cin >> value;

                auto it = find(arr.begin(), arr.end(), value);

                if(it != arr.end()) {
                    arr.erase(it);
                    cout << "Deleted successfully!\n";
                } else {
                    cout << "Element not found!\n";
                }
                break;
            }

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 5);

    return 0;
}