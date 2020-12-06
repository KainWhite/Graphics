#ifndef STRINGEXTENSIONS
#define STRINGEXTENSIONS

#include <vector>
#include <sstream>

std::vector<std::wstring> Split(std::wstring const &str,
                                wchar_t delimiter,
                                bool splitWhenMultipleDelimiterInARow = true) {
  std::vector<std::wstring> result;
  result.push_back(L"");
  for (auto i = 0; i < str.size(); i++) {
    if (str[i] == delimiter) {
      if (!splitWhenMultipleDelimiterInARow) {
        while (str[i] == delimiter) {
          i++;
        }
      }
      result.push_back(L"");
    }
    if (str[i] != delimiter) {
      result.back().push_back(str[i]);
    }
  }
  return result;
}

double StringToDouble(std::wstring const &str) {
  std::wstringstream ss(str);
  double result;
  ss >> result;
  return result;
}

#endif  // !STRINGEXTENSIONS
