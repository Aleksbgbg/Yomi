#ifndef SRC_ENGINE_COMPOSITION_PARAMETER_UTILS_H_
#define SRC_ENGINE_COMPOSITION_PARAMETER_UTILS_H_

#define PARAMETER_TYPE(type, name) \
 private:                          \
  type* name##_;                   \
                                   \
 public:                           \
  auto& Set##name(type& value) {   \
    name##_ = &value;              \
    return *this;                  \
  }                                \
                                   \
  type& Get##name() const {        \
    return *name##_;               \
  }

#define PARAMETER_VALUE(type, name)   \
 private:                             \
  type name##_;                       \
                                      \
 public:                              \
  auto& Set##name(const type value) { \
    name##_ = value;                  \
    return *this;                     \
  }                                   \
                                      \
  type Get##name() const {            \
    return name##_;                   \
  }

#define PARAMETER_PACK_BEGIN class ParameterPack {
#define PARAMETER_PACK_END \
  }                        \
  ;

#endif  // SRC_ENGINE_COMPOSITION_PARAMETER_UTILS_H_
