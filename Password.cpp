#include "Password.h"
#include <string>

using std::string;

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(string phrase){
  if (phrase.empty()) return 0;
  int repetition = 1;
  for(int i = 1; i < phrase.length(); i++) {
    if(phrase[0] == phrase[i]) repetition++;
    else break;
  }
  return repetition;
}

bool Password::has_mixed_case(string word) {
  bool upper = false, lower = false;
  for (char c : word) {
    if(islower(c)) lower = true;
    if(isupper(c)) upper = true;
    if(lower && upper) return true;
  }
  return false;
}


