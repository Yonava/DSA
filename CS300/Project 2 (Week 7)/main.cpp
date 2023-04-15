#include "HashTable.h"

void menu() {
  while (true) {
    cout << "1. Load Data Structure" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "4. Exit" << endl;

    int choice;

    cout << "Please enter your choice: ";

    cin >> choice;

    switch (choice) {
      case 1:

        cout << "Data Structure Loaded" << endl;
        break;
      case 2:
        cout << "Delete a student" << endl;
        break;
      case 3:
        cout << "Update a student" << endl;
        break;
      case 4:
        cout << "Exit" << endl;
        return;
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  }
}

int main()
{
  string filename;
  cout << "Please enter the file name: ";
  cin >> filename;

  ifstream file(filename);

  if (!file)
  {
    cerr << "Error opening file" << endl;
    return 1;
  }

  string line;
  while (getline(file, line))
  {
    cout << line << endl;
  }

  file.close();

  menu();

  return 0;
}
