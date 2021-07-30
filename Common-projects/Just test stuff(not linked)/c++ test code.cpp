#include <iostream>
using namespace std;

bool valSum = true;
string testArray[10] = {"aa", "ab", "ac", "ad", "ae"};
string Array[10] = {"aa", "ab", "ac", "ad", "ae"};

bool boolFunction(string ArrayVal, int i);



int main() {
  for (int n=0; n<5; n++) {
  valSum = boolFunction(Array[n], n) && valSum;
  }
  
  if (valSum) {
  cout << "noice\n";
  }
  else {
  cout << "shit\n";
  }
  return 0;
}

bool boolFunction(string ArrayVal, int i) {
    bool boolAnswer = true;
	if (ArrayVal == testArray[i]) {}
    else {boolAnswer = false;}
	return boolAnswer;
}

