#pragma once

#include <initializer_list>
#include <string_view>

#include <jsi/jsi.h>

#include <kolibri/defines.h>

namespace expo::modules::v2 {
  NORETURN void throwJSError(
    facebook::jsi::Runtime& rt,
    std::initializer_list<std::string_view> parts
  );

  NORETURN void throwInvalidArgument(std::initializer_list<std::string_view> parts);

  NORETURN void throwRuntimeError(std::initializer_list<std::string_view> parts);
}
