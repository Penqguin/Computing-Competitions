#include <iostream>
#include <string>
#include <vector>
#include <cctype>
using namespace std;

// Function to parse and format tuning instructions
vector<string> parseTuningInstructions(const string& input) {
  vector<string> result;
  string letters = "";
  char sign = '\0';
  string number = "";

  for (size_t i = 0; i < input.size(); ++i) {
    char ch = input[i];

    if (isalpha(ch)) {
      // Collect letters
      if (sign != '\0') {
        // Previous instruction completed
        string action = (sign == '+') ? "tighten" : "loosen";
        result.push_back(letters + " " + action + " " + number);
        letters = "";
        number = "";
        sign = '\0';
      }
      letters += ch;
    } else if (ch == '+' || ch == '-') {
      // Sign encountered
      sign = ch;
    } else if (isdigit(ch)) {
      // Collect digits
      number += ch;
    }
  }

  // Add the last instruction
  if (!letters.empty() && sign != '\0' && !number.empty()) {
    string action = (sign == '+') ? "tighten" : "loosen";
    result.push_back(letters + " " + action + " " + number);
  }

  return result;
}

int main() {
  string input;
  cin >> input;

  vector<string> output = parseTuningInstructions(input);

  for (const string& line : output) {
    cout << line << endl;
  }

  return 0;
}
