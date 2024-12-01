#include <array>
#include <iostream>
#include <fstream>

static const int INPUT_LINE_COUNT = 1000;

/*
*   Sort the lists, then go through the list one by one and then compare
*/
int main() {
  std::ifstream input("input.txt");
  std::array<int, INPUT_LINE_COUNT> leftArray, rightArray;
  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    input >> leftArray[i] >> rightArray[i];
  }
  std::sort(leftArray.begin(), leftArray.end());
  std::sort(rightArray.begin(), rightArray.end());

  int distance = 0;
  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    distance += std::abs(leftArray[i] - rightArray[i]);
  }
  std::cout << distance << "\n";
  return 0;
}
