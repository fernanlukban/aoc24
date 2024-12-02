#include <array>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <optional>


static const int INPUT_LINE_COUNT = 1000;

bool dampen_level(std::vector<int> level) {
  bool safe = false;
  std::optional<size_t> skip = std::nullopt;
  if (level[1] == level[0]) {
    skip = 0;
  }
  for (size_t i = 0; i < level.size(); ++i) {
  }
  return safe;
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
    if (level[1] == level[0]) {
      safe = false;
    }
    int difference = std::abs(level[0] - level[1]);
    if (difference < 1 || difference > 3 || difference == 0) {
      safe = false;
    }
    bool decreasing = level[1] - level[0] < 0;
    std::cout << level[0] <<  " " << level[1] << " ";
    for (size_t i = 2; i < level.size(); ++i) {
      std::cout << level[i] << " ";
      int difference = std::abs(level[i] - level[i-1]);
      if (difference < 1 || difference > 3 || difference == 0) {
        safe = false;
      }
      if (decreasing && level[i] - level[i-1] > 0) {
        std::cout << "DECREASING BUT INCREASING ";
        safe = false;
      } else if (!decreasing && level[i] - level[i-1] < 0) {
        std::cout << "INCREASING BUT DECREASING ";
        safe = false;
      }
    }
    if (safe) {
      ++result;
      std::cout << " SAFE";
    } else if (dampen_level(level)) {
      ++result;
      std::cout << " DAMPENED SAFE";
    }
    std::cout << "\n";
  }
  std::cout << result << "\n";
  return 0;
}
