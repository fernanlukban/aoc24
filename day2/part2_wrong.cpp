#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

static const int INPUT_LINE_COUNT = 1000;

bool dampen(std::vector<int> level) {
  for (size_t j = 0; j < level.size(); ++j) {
    auto levelCopy = level;
    levelCopy.erase(levelCopy.begin() + j);
    bool safe = true;
    bool decreasing = levelCopy[1] - levelCopy[0] < 0;
    for (size_t i = 0; i < levelCopy.size(); ++i) {
      std::cout << levelCopy[i] << " ";
      if (i == 0) {
        continue;
      }
      int difference = levelCopy[i] - levelCopy[i-1];
      if (std::abs(difference) < 1 || std::abs(difference) > 3 || difference == 0) {
        safe = false;
      }
      
      if ((decreasing && difference > 0) || (!decreasing && difference < 0)) {
        safe = false;
      } 
    }
    if (safe) {
      return true;
    }
  }
  return false;
}

/*
*   Sort the lists, then go through the list one by one and then compare
*/
int main() {
  std::ifstream input("input.txt");
  std::array<std::vector<int>, INPUT_LINE_COUNT> levels;
  std::string line;
  for (int i = 0; i < INPUT_LINE_COUNT; ++i) {
    std::getline(input, line);
    std::stringstream lin(std::move(line));
    int val = 0;
    while (lin >> val) {
      levels[i].push_back(val);
    }
  }

  int result = 0;
  for (const auto& level : levels) {
    bool safe = true;
    bool decreasing = level[1] - level[0] < 0;
    for (size_t i = 0; i < level.size(); ++i) {
      std::cout << level[i] << " ";
      if (i == 0) {
        continue;
      }
      int difference = level[i] - level[i-1];
      if (std::abs(difference) < 1 || std::abs(difference) > 3 || difference == 0) {
        safe = false;
      }
      
      if ((decreasing && difference > 0) || (!decreasing && difference < 0)) {
        safe = false;
      } 
    }
    if (safe) {
      ++result;
      std::cout << " SAFE";
    } else {
      result += dampen(level);
      std::cout << " DAMPENED";
    }
    std::cout << "\n";
  }
  std::cout << result << "\n";
  return 0;
}
