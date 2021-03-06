#ifndef SRC_ENGINE_UI_UNBOUNDVALUE_H_
#define SRC_ENGINE_UI_UNBOUNDVALUE_H_

#include "ReadWriteable.h"

template <typename T>
class UnboundValue : public ReadWriteable<T> {
 public:
  explicit UnboundValue(const T value) : value_(value) {}

  T GetValue() const override {
    return value_;
  }

  void SetValue(const T value) override {
    value_ = value;
  }

 private:
  T value_;
};

#endif  // SRC_ENGINE_UI_UNBOUNDVALUE_H_
