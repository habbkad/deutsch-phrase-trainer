#include <expo-modules-v2/utils/Throw.h>

#include <stdexcept>
#include <string>

namespace expo::modules::v2 {
  namespace {
    // TODO(@lukmccall): research if that's the best way of doing it
    std::string concat(const std::initializer_list<std::string_view> parts) {
      size_t size = 0;
      for (const std::string_view part : parts) {
        size += part.size();
      }

      std::string message;
      message.reserve(size);
      for (const std::string_view part : parts) {
        message.append(part);
      }
      return message;
    }
  } // namespace

  COLD NOINLINE void throwJSError(
    facebook::jsi::Runtime& rt,
    const std::initializer_list<std::string_view> parts
  ) {
    throw facebook::jsi::JSError(rt, concat(parts));
  }

  COLD NOINLINE void throwInvalidArgument(const std::initializer_list<std::string_view> parts) {
    throw std::invalid_argument(concat(parts));
  }

  COLD NOINLINE void throwRuntimeError(const std::initializer_list<std::string_view> parts) {
    throw std::runtime_error(concat(parts));
  }
} // namespace expo::modules::v2
