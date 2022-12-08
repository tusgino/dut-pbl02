#ifndef __COMPONENTS__
#define __COMPONENTS__

#include <windows.h>
#include <fstream>
#include <cstdio>
#include "ConsoleTable.cpp"
#include "List.cpp"
#include "Node.cpp"

using namespace std;

const string tabtab = "\n\t\t";
const string center = "\t\t\t\t\t";

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
  printLineColor(" WARNING ", 96);
  printLineColor(" " + status, 6);
}

// Print notification
void printSuccess(string status)
{
  cout << "\n\t";
  printLineColor(" SUCCESS ", 37);
  printLineColor(" " + status, 2);
  cout << endl;
}

void printRes(string request)
{
  cout << "\t";
  cout << request;
}

void printOpt(string *arr, int n)
{
  printRes(*arr);
  // cout << endl;
  for (int i = 1; i <= n; ++i)
  {
    cout << tabtab << i << ". " << *(arr + i);
  }
}

// get key menu
int getKey(int keyMax)
{
  char key;
  cout << "\n\tNhap lua chon: ";
  fflush(stdin);
  key = getchar();
  while (int(key) < 49 || int(key) > (keyMax + 48))
  {
    cout << "\n\tVui long nhap lai lua chon!";
    string error = "Hinh nhu ban da nhap sai lua chon(ki tu hoac so luon hon " + to_string(keyMax) + " hoac so be hon 0, vui long nhap dung lua chon!";
    printError(error);
    cout << "\n\tNhap lua chon: ";
    fflush(stdin);
    key = getchar();
  }
  return int(key) - 48;
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
  // cout << parent << " " << sub << endl;
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
  // cout << parent.length() << " " << sub.length() << " " << found << endl;
  return -1;
}

bool checkSDT(string &soDienThoai)
{
  if (soDienThoai.length() != 10 || soDienThoai.at(0) != '0')
    return false;
  for (int i = 0; i < soDienThoai.length(); i++)
  {
    char c = soDienThoai.at(i);
    if ((int(c) - 48) < 0 || (int(c) - 48) > 9)
      return false;
  }
  return true;
}

void pauseScreen()
{
  fflush(stdin);
  char c;
  c = getchar();
}

#endif