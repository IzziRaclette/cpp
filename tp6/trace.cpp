#include <iostream>


class M {
 public:
  M() {
    std::cout << "M::M()" << std::endl;
  }
  ~M() {
    std::cout << "M::~M()" << std::endl;
  }
  M(const M&) {
    std::cout << "M::M(const M&)" << std::endl;
  }
  void operator=(M const &) {
    std::cout << "M::operator=(M const &)" << std::endl;
  }
};

class F : public M {
 public:
  F() {
    std::cout << "F::F()" << std::endl;
  }
  ~F() {
    std::cout << "F::~F()" << std::endl;
  }
  F(const F& f) : M(f) {
    std::cout << "F::F(const F&)" << std::endl;
  }
  void operator=(F const & f) {
    M::operator=(f);
    std::cout << "F::operator=(F const &)" << std::endl;
  }
};

class A {
  M m;

 public:
  A() {
    std::cout << "A::A()" << std::endl;
  }
  ~A() {
    std::cout << "A::~A()" << std::endl;
  }
  A(const A & a) {
    m = a.m;
    std::cout << "A::A(const A&)" << std::endl;
  }
  void operator=(A const &) {
    std::cout << "A::operator=(A const &)" << std::endl;
  }
};


int main(int, char**) {
  A a1;
  A a2 = a1;

  return 0;
}
