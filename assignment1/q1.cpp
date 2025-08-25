#include <iostream>
using namespace std;

int MAX = 50;
int arr[MAX];
int n = 0;

void createArray() {
  cout << "Enter number of elements: ";
  cin >> n;
  if (n > MAX) {
    cout << "Max size exceeded! Setting to " << MAX << endl;
    n = MAX;
  }
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];
}

void displayArray() {
  if (n == 0) {
    cout << "Array is empty.\n";
    return;
  }
  cout << "Array elements: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void insertElement() {
  if (n >= MAX) {
    cout << "Array is full. Cannot insert.\n";
    return;
  }
  int pos, val;
  cout << "Enter position (1 to " << n + 1 << "): ";
  cin >> pos;
  if (pos < 1 || pos > n + 1) {
    cout << "Invalid position.\n";
    return;
  }
  cout << "Enter value: ";
  cin >> val;
  for (int i = n; i >= pos; i--)
    arr[i] = arr[i - 1];
  arr[pos - 1] = val;

  n++;
  cout << "Element inserted.\n";
}

void deleteElement() {
  if (n == 0) {
    cout << "Array is empty.\n";
    return;
  }
  int pos;
  cout << "Enter position to delete (1 to " << n << "): ";
  cin >> pos;
  if (pos < 1 || pos > n) {
    cout << "Invalid position.\n";
    return;
  }
  for (int i = pos - 1; i < n - 1; i++)
    arr[i] = arr[i + 1];
  n--;
  cout << "Element deleted.\n";
}

void linearSearch() {
  if (n == 0) {
    cout << "Array is empty.\n";
    return;
  }
  int key;
  cout << "Enter element to search: ";
  cin >> key;
  for (int i = 0; i < n; i++) {
    if (arr[i] == key) {
      cout << "Element found!" << endl;
      return;
    }
  }
  cout << "Element not found.\n";
}

int main() {
  int choice;
  while (true) {
    cout << "\n----- MENU -----\n";
    cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR "
            "SEARCH\n6.EXIT\n ";
    cout << "Enter choice: ";
    cin >> choice;
    switch (choice) {

    case 1:
      createArray();
      break;
    case 2:
      displayArray();
      break;
    case 3:
      insertElement();
      break;
    case 4:
      deleteElement();
      break;
    case 5:
      linearSearch();
      break;
    case 6:
      return 0;
    default:
      cout << "Invalid choice.\n";
    }
  }
}
