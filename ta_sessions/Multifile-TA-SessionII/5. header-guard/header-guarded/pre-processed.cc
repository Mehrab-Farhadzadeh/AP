# 1 "main.cc"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "main.cc"
# 1 "A.hh" 1



class A {};
# 2 "main.cc" 2
# 1 "B.hh" 1


class B {
  A a;
};
# 3 "main.cc" 2
# 1 "C.hh" 1


class C {
  A a;
};
# 4 "main.cc" 2

int main() {
  A a;
  B b;
  C c;
  return 0;
}
