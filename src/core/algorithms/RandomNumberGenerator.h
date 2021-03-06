#ifndef SRC_CORE_ALGORITHMS_RANDOMNUMBERGENERATOR_H_
#define SRC_CORE_ALGORITHMS_RANDOMNUMBERGENERATOR_H_

#include <random>

#include "core/types.h"

class RandomNumberGenerator {
 public:
  RandomNumberGenerator();

  i32 RandomInt(const i32 min, const i32 max);
  u32 RandomUint(const u32 min, const u32 max);
  float RandomFloat(const float min, const float max);

 private:
  std::mt19937 generator;
};

#endif  // SRC_CORE_ALGORITHMS_RANDOMNUMBERGENERATOR_H_
