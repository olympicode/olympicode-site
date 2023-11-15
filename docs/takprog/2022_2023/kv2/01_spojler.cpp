#include <iostream>

void write_sol(std::ostream& f, int a, int b, int x, int y) {
  if (a == x && b == y) {
    f << "nijedan" << std::endl;
  } else if (a == x) {
    f << "drugi" << std::endl;
  } else if (b == y) {
    f << "prvi" << std::endl;
  } else {
    f << "?" << std::endl;
  }
}

int main() {
  int a, b, x, y;
  std::cin >> a >> b;
  std::cin >> x >> y;
  write_sol(std::cout, a, b, x, y);
  return 0;
}

