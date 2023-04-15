#include "HashTable.h"

Course parseCourse(string line)
{
  Course course;

  int pos = line.find(",");
  course.courseId = line.substr(0, pos);
  line = line.substr(pos + 1);

  pos = line.find(",");
  course.title = line.substr(0, pos);
  line = line.substr(pos + 1);

  while (line.length() > 0)
  {
    pos = line.find(",");
    if (pos == -1)
    {
      course.prereqs.push_back(line);
      break;
    }
    course.prereqs.push_back(line.substr(0, pos));
    line = line.substr(pos + 1);
  }

  return course;
}

void loadHashTable(HashTable* courseTable)
{
  string filename;
  cout << "Please enter the file name: ";
  cin >> filename;

  ifstream file(filename);

  if (!file)
  {
    cerr << "Error opening file" << endl;
    return;
  }

  string line;
  while (getline(file, line))
  {
    Course course = parseCourse(line);
    courseTable->Insert(course);
  }

  file.close();
}

int main() {

  HashTable* courseTable = new HashTable();

  while (true) {
    cout << "1. Load Data Structure" << endl;
    cout << "2. Print Course List" << endl;
    cout << "3. Print Course" << endl;
    cout << "4. Exit" << endl;

    int choice;
    string courseId;
    Course course;

    cout << "Please enter your choice: ";

    cin >> choice;

    switch (choice) {
      case 1:
        loadHashTable(courseTable);
        cout << "Data Structure (Hash Table) Loaded!" << endl;
        break;
      case 2:
        cout << "Here is a sample schedule:" << endl;
        courseTable->PrintAll();
        break;
      case 3:
        cout << "What course do you want to know about? " << endl;
        cin >> courseId;
        course = courseTable->Search(courseId);
        if (course.courseId == "")
        {
          cout << "Course not found" << endl;
        }
        else
        {
          cout << "Here is what we found - " << endl;
          cout << "Course ID: " << course.courseId << endl;
          cout << "Course Title: " << course.title << endl;
          cout << "Prerequisites: ";
          for (int i = 0; i < course.prereqs.size(); i++)
          {
            cout << course.prereqs[i] << " ";
          }
          cout << endl;
        }
        break;
      case 4:
        cout << "Exit" << endl;
        return 0;
      default:
        cout << "Invalid choice" << endl;
        break;
    }
  }

  return 0;
}