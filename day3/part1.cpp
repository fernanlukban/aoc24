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
    std::cout << "old_state " << static_cast<int>(state_) << "\n";
    std::cout << "letter " << letter << "\n";
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
        } else if (state_ == State::O || state_ == State::T) {
          state_ = State::DO_OR_DONT_LEFT_PARENS;
        } else {
          state_ = State::INVALID;
        }
        break;
      case ',':
        if (state_ == State::FIRST_NUMBER) {
          state_ = State::COMMA;
        } else {
          state_ = State::INVALID;
        }
        break;
      case ')':
        if (state_ == State::SECOND_NUMBER) {
          state_ = State::RIGHT_PARENS;
        } else if (state_ == State::DO_OR_DONT_LEFT_PARENS) {
          state_ = State::DO_OR_DONT_RIGHT_PARENS;
          if (inDo_.has_value()) {
            enableMultiplcations_ = *inDo_;
          }
        } else {
          state_ = State::INVALID;
        }
        break;
      case 'd':
        state_ = State::D;
        break;
      case 'o':
        if (state_ == State::D) {
          state_ = State::O;
          inDo_ = true;
        } else {
          state_ = State::INVALID;
        }
        break;
      case 'n':
        if (state_ == State::O) {
          state_ = State::N;
        } else {
          state_ = State::INVALID;
        }
        break;
      case '\'':
        if (state_ == State::N) {
          state_ = State::APOSTROPHE;
        } else {
          state_ = State::INVALID;
        }
        break;
      case 't': 
        if (state_ == State::APOSTROPHE) {
          state_ = State::T;
          inDo_ = false;
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
    if (state_ == State::INVALID) {
      inDo_ = std::nullopt;
    }
    std::cout << "new_state " << static_cast<int>(state_) << "\n";
    if (state_ == State::RIGHT_PARENS) {
      if (!firstNumber_.has_value() && !secondNumber_.has_value()) {
        return std::nullopt;
      }
      if (!enableMultiplcations_) {
        std::cout << "DISABLING " << *firstNumber_ << " " << *secondNumber_ << "\n";
        return std::nullopt;
      }
      std::cout << *firstNumber_ << " " << *secondNumber_ << "\n";
      int total = *firstNumber_ * *secondNumber_;
      reset_state();
      return total;
    }
    return std::nullopt;
  }
 private:
  enum class State: int {
    INVALID,
    M,
    U,
    L,
    LEFT_PARENS,
    FIRST_NUMBER,
    COMMA,
    SECOND_NUMBER,
    RIGHT_PARENS,
    D,
    O,
    N,
    APOSTROPHE,
    T,
    DO_OR_DONT_LEFT_PARENS,
    DO_OR_DONT_RIGHT_PARENS,
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
        firstNumber_ = letter - '0';
        state_ = State::FIRST_NUMBER;
        break;
      case State::COMMA:
        secondNumber_ = letter - '0';
        state_ = State::SECOND_NUMBER;
        break;
      case State::FIRST_NUMBER:
        firstNumber_ = *firstNumber_ * 10 + letter - '0';
        break;
      case State::SECOND_NUMBER:
        secondNumber_ = *secondNumber_ * 10 + letter - '0';
        break;
      default:
        //std::cout << static_cast<int>(state_) << " " << letter << " SHOULD NOT BE HERE\n";
        break;
    }
  }
  std::optional<int> firstNumber_;
  std::optional<int> secondNumber_;
  std::optional<bool> inDo_;
  bool enableMultiplcations_ = true;
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
      std::cout << "new number " << *possible_number << "\n";
      result += *possible_number;
    }
  }
  std::cout << result << "\n";
  return 0;
}
