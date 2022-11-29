#ifndef __COMPONENTS__
#define __COMPONENTS__

#include <windows.h>
#include <fstream>
#include <cstdio>

void printLineColor(string line, int color_code)
{
  HANDLE color;
  color = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(color, color_code);
  cout << line;
  SetConsoleTextAttribute(color, 7);
}

// Print notification
void printError(string status)
{
  cout << "\n\t";
  printLineColor(" ERROR ", 67);
  printLineColor(" " + status, 4);
  cout << endl;
}

void printWarning(string status)
{
  cout << "\n\t";
  printLineColor(" WARNING ", 67);
  printLineColor(" " + status, 4);
}

// Print notification
void printSuccess(string status)
{
  cout << "\n\t";
  printLineColor(" SUCCESS ", 37);
  printLineColor(" " + status, 2);
  cout << endl;
}

// get key menu
int getKey(int keyMax)
{
  int key;
  char keyy;
  cout << "\n\tNhap lua chon: ";
  fflush(stdin);
  keyy = getchar();
  // cin >> key;
  while (int(keyy) < 49 || int(keyy) > (keyMax + 48))
  {
    cout << "\n\tVui long nhap lai lua chon!";
    printError("Ban da nhap sai, vui long nhap lai!");
    cout << "\n\tNhap lua chon: ";
    // cin >> key;
    fflush(stdin);
    keyy = getchar();
  }
  return int(keyy) - 48;
}

void printUI(string fileUrl)
{
  fstream fileIn;
  fileIn.open(fileUrl);
  if (fileIn.is_open())
  {
    // cout << "\nmo thanh cong\n";
  }
  else
  {
    // cout << "\nmo that bai\n";
  }
  string line;
  while (getline(fileIn, line))
  {
    cout << line << endl;
  }
  fileIn.close();
}

int findString(string parent, string sub)
{
  for (auto &c : parent)
    c = toupper(c);
  for (auto &c : sub)
    c = toupper(c);
  size_t found = parent.find(sub);
  if (found != string::npos)
  {
    if (parent[found + sub.length()] == ' ' || found + sub.length() == parent.length())
      return found;
  }
  return -1;
}

#endif