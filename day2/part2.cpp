#include <array>
#include <iostream>
#include <fstream>
#include <unordered_map>

static const int INPUT_LINE_COUNT = 1000;

/*
*   Sort the lists, then go through the list one by one and then compare
*/
int main() {
  std::ifstream input("input.txt");
  std::array<int, INPUT_LINE_COUNT> leftArray, rightArray;
  std::unordered_map<int, int> rightArrayFrequency;
  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    input >> leftArray[i] >> rightArray[i];
  }
  std::sort(leftArray.begin(), leftArray.end());
  std::sort(rightArray.begin(), rightArray.end());

  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    ++rightArrayFrequency[rightArray[i]];
  }
  int result = 0;
  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    result += leftArray[i] * rightArrayFrequency[leftArray[i]];
  }
  std::cout << result << "\n";
  return 0;
}
