#include<iostream>
#include<stdlib.h>
#define true 1
using namespace std;

int main() {
	int n;
	int a[30];
    int choice;
    cout << "Press 1 to CREATE a list." << endl;
    cout << "Press 2 to INSERT data at a specific position." << endl;
    cout << "Press 3 to DELETE data from a specific position." << endl;
    cout << "Press 4 to TRAVERSE the elements in the list." << endl;
    cout << "Press 5 to MERGE two lists." << endl;
    cout << "Press 6 to EXIT." << endl;

    while(true) {
	    cout << endl << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter the size of the list: ";
                cin >> n;
                
                cout << "Enter elements of the list: ";
                for(int i = 0; i < n; i++) {
                    cin >> a[i];
                }
                break;

            case 2:
                int insElem, pos;
                cout << "\nEnter the element to be inserted: ";
                cin >> insElem;
                cout << "Enter the position: ";
                cin >> pos;

                for(int i = n - 1; i >= pos - 1; i--) {
                    a[i + 1] = a[i];
                }
                a[pos - 1] = insElem;
                n++;
                
                cout << "The elements of the list after insertion are: ";
                for(int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                break;

            case 3:
                int delPos;
                cout << "Enter the position to delete the element: ";
                cin >> delPos;
                if(delPos >= 1 && delPos <= n) {
                    for(int i = delPos - 1; i < n - 1; i++) {
                        a[i] = a[i + 1];
                    }
                    n--;

                    cout << "The elements of the list after deletion are: " << endl;
                    for(int i = 0; i < n; i++) {
                        cout << a[i] << " ";
                    }
                }
                else {
                    cout << "Invalid position!" << endl;
                }
                break;

            case 4:
                cout << "The current elements of the list are: ";
                for(int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                break;

            case 5:
                int m, b[30];
                cout << "Enter the size of the second list: ";
                cin >> m;

                cout << "Enter elements of the second list: ";
                for(int i = 0; i < m; i++) {
                    cin >> b[i];
                }

                // Merge the two lists
                for(int i = 0; i < m; i++) {
                    a[n + i] = b[i];
                }
                n += m;

                cout << "The elements of the merged list are: ";
                for(int i = 0; i < n; i++) {
                    cout << a[i] << " ";
                }
                break;

            case 6:
                exit(0);
                break;

            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    }
    
    return 0;
}
