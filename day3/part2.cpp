#include <iostream>
#include <fstream>
#include <optional>

/*
*   Two state machines
*   - One for checking whether or not we're in a valid sequence
*   - One to check the multiplication valid sequence
*/
class MultiplicationParser {
 public:
  std::optional<int> parse_input(const char letter) {
    switch (letter) {
      case 'm':
        state_ = State::M;
        break;
      case 'u':
        if (state_ == State::M) {
          state_ = State::U;
        } else {
          state_ = State::INVALID;
        }
        break;
      case 'l':
        if (state_ == State::U) {
          state_ = State::L;
        } else {
          state_ = State::INVALID;
        }
        break;
      case '(':
        if (state_ == State::L) {
          state_ = State::LEFT_PARENS;
          firstNumber_ = 0;
        } else {
          state_ = State::INVALID;
        }
        break;
      case ',':
        if (state_ == State::FIRST_NUMBER) {
          state_ = State::COMMA;
          secondNumber_ = 0;
        } else {
          state_ = State::INVALID;
        }
        break;
      case ')':
        if (state_ == State::SECOND_NUMBER) {
          state_ = State::RIGHT_PARENS;
        } else {
          state_ = State::INVALID;
        }
        break;
      default:
        if (is_digit(letter)) {
          parse_digit(letter);
        } else {
          reset_state();
        }
        break;
    }
    if (state_ == State::RIGHT_PARENS) {
      if (!firstNumber_.has_value() && !secondNumber_.has_value()) {
        return std::nullopt;
      }
      int total = *firstNumber_ * *secondNumber_;
      reset_state();
      return total;
    }
    return std::nullopt;
  }
 private:
  enum class State {
    INVALID,
    M,
    U,
    L,
    LEFT_PARENS,
    FIRST_NUMBER,
    COMMA,
    SECOND_NUMBER,
    RIGHT_PARENS,
  };
  void reset_state() {
    state_ = State::INVALID;
    firstNumber_ = std::nullopt;
    secondNumber_ = std::nullopt;

  }
  bool is_digit(const char letter) {
    return letter >= '0' && letter <= '9';
  }
  void parse_digit(const char letter) {
    switch (state_) {
      case State::LEFT_PARENS:
        state_ = State::FIRST_NUMBER;
      case State::COMMA:
        state_ = State::SECOND_NUMBER;
      case State::FIRST_NUMBER:
        firstNumber_ = *firstNumber_ * 10 + letter - '0';
        break;
      case State::SECOND_NUMBER:
        secondNumber_ = *secondNumber_ * 10 + letter - '0';
        break;
      default:
        std::cout << "SHOULD NOT BE HERE\n";
        break;
    }
  }
  std::optional<int> firstNumber_;
  std::optional<int> secondNumber_;
  State state_;
};

int main() {
  std::ifstream input("input.txt");
  MultiplicationParser parser;
  char letter;
  int result = 0;
  while (input >> letter) {
    auto possible_number = parser.parse_input(letter);
    if (possible_number.has_value()) {
      result += *possible_number;
    }
  }
  std::cout << result << "\n";
  return 0;
}
