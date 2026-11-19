#pragma once

#include <format>
#include <memory>
#include <string>
#include <string_view>
#include <type_traits>
#include <vector>

#include <guiddef.h>

using std::string;

bool matchWildcard(const string& str, const string& pattern);

// ASCII string helpers
string toLower(string text);
bool iequals(std::string_view a, std::string_view b);
bool icontains(std::string_view text, std::string_view part);
string trim(std::string_view text);
std::vector<string> splitAny(std::string_view text, std::string_view separators);
string join(const std::vector<string>& parts, std::string_view separator);
void replaceAll(string& text, std::string_view from, std::string_view to);
void replaceFirst(string& text, std::string_view from, std::string_view to);

string guidToString(REFGUID guid);

// strFormat() is std::format with a few argument conversions, so callers can pass
// Win32/D3D values directly: pointers print as addresses, enums as numbers, GUIDs in
// registry form and unique_ptrs as the address they own.
namespace format_detail {
	template<typename T>
	struct IsUniquePtr : std::false_type {};
	template<typename T, typename D>
	struct IsUniquePtr<std::unique_ptr<T, D>> : std::true_type {};

	template<typename T>
	constexpr bool isTextPointer = std::is_same_v<std::remove_cv_t<std::remove_pointer_t<T>>, char>;

	template<typename T>
	decltype(auto) adapt(const T& value) {
		if constexpr(std::is_same_v<T, GUID>) return guidToString(value);
		else if constexpr(std::is_enum_v<T>) return static_cast<std::underlying_type_t<T>>(value);
		else if constexpr(IsUniquePtr<T>::value) return static_cast<const void*>(value.get());
		else if constexpr(std::is_pointer_v<T> && std::is_function_v<std::remove_pointer_t<T>>) return reinterpret_cast<const void*>(value);
		else if constexpr(std::is_pointer_v<T> && !isTextPointer<T>) return static_cast<const void*>(value);
		else return (value);
	}

	template<typename T>
	using Adapted = decltype(adapt(std::declval<const T&>()));
}

template<typename... Args>
using FormatString = std::format_string<format_detail::Adapted<Args>...>;

template<typename... Args>
string strFormat(FormatString<Args...> fmt, const Args&... args) {
	return std::format(fmt, format_detail::adapt(args)...);
}
