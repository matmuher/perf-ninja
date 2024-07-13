// NOTE: this lab is currently broken.
// After migrating to a new compiler version the speedup is no longer measurable consistently.
// You can still try to solve it to learn the concept, but the result is not guaranteed.

#include <array>

#define CHECK_SIZE
#undef CHECK_SIZE

// Assume those constants never change
constexpr int N = 10000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
struct S {
  float d;
  long long l:16;
  int i:8;
  short s:7;
  bool b:1;

  bool operator<(const S &s) const { return this->i < s.i; }
};

#ifdef CHECK_SIZE
template<int N>
class TD;
TD<sizeof(S)> td1; // S
TD<sizeof(long long)> td1; // long long
TD<sizeof(double)> td5; // double
TD<sizeof(float)> td2; // float
TD<sizeof(short)> td3; // short
TD<sizeof(bool)> td4; // bool
#endif

void init(std::array<S, N> &arr);
S create_entry(int first_value, int second_value);
void solution(std::array<S, N> &arr);
