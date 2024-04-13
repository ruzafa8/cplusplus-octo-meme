#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main() {
  {
    std::cout << "Test with std::vector<int>" << std::endl;
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    try {
      std::cout << easyfind(arr, 3) << std::endl;
      std::cout << easyfind(arr, 6) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "Test with std::list<int>" << std::endl;
    std::list<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    try {
      std::cout << easyfind(arr, 3) << std::endl;
      std::cout << easyfind(arr, 6) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  {
    std::cout << "Test with std::list<int> with 0 elements" << std::endl;
    std::list<int> arr;
    try {
      std::cout << easyfind(arr, 3) << std::endl;
    } catch (std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  }
  return 0;
}