#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdio>
#include "workplace.h"
using namespace std;

int main() {
  int tNum = 0; // variable - task number
  int tCNum = 4; // variable - number of test cases
  bool solved = true;
  for (int i=0; i<tCNum; i++) { 
    ofstream ipt; ipt.open("input.in", ios::out | ios::trunc);
    ifstream opt; opt.open("output.out", ios::out | ios::trunc);
    string tCFile = "tC/tC" + to_string(i) + ".in";
    ifstream tCRead(tCFile);
    string tCAFile = "tCA/tCA" + to_string(i) + ".out";
    ifstream tCARead(tCAFile);

    string tCContent;
    while (getline(tCRead, tCContent)) {
      ipt << tCContent << endl;
    }

    cout << "-------------------<test-case-" << i << ">-------------------" << endl;
    workplace(); 

    string tCA;
    while (getline(tCARead, tCA)) {};
    string userOpt;
    while (getline(opt, userOpt)) {};

    if (tCA == userOpt) {
      cout << "              ##< TESTCASE SOLVED >##" << endl << endl << endl;
    } else {
      solved = false;
      cout << "                    you failed" << endl << endl << endl;
    }

    ipt.close();
    tCRead.close();
  }

  if (solved == true) {
    cout << "Congratulations! You completed the task!";
  }
}
