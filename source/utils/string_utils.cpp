#include "utils/string_utils.h"

#include <algorithm>
#include <cctype>
#include <regex>

#include <dxgi1_2.h>
#include <d3d11_2.h>

namespace {
	char lowerChar(char c) { return static_cast<char>(std::tolower(static_cast<unsigned char>(c))); }
	bool isSpace(char c) { return std::isspace(static_cast<unsigned char>(c)) != 0; }
}

bool matchWildcard(const string& str, const string& pattern) {
	string regex = pattern;
	for(const char* ch : { ".", "+", "(", ")", "[", "]", "^", "$" }) {
		replaceAll(regex, ch, string("\\") + ch);
	}
	replaceAll(regex, "*", ".*");
	replaceAll(regex, "?", ".");
	regex = ".*" + regex;
	std::regex rx(regex, std::regex::icase);
	return std::regex_match(str, rx);
}

string toLower(string text) {
	std::ranges::transform(text, text.begin(), lowerChar);
	return text;
}

bool iequals(std::string_view a, std::string_view b) {
	return std::ranges::equal(a, b, [](char x, char y) { return lowerChar(x) == lowerChar(y); });
}

bool icontains(std::string_view text, std::string_view part) {
	return toLower(string(text)).find(toLower(string(part))) != string::npos;
}

string trim(std::string_view text) {
	while(!text.empty() && isSpace(text.front())) text.remove_prefix(1);
	while(!text.empty() && isSpace(text.back())) text.remove_suffix(1);
	return string(text);
}

std::vector<string> splitAny(std::string_view text, std::string_view separators) {
	std::vector<string> parts;
	size_t start = 0;
	while(true) {
		const size_t end = text.find_first_of(separators, start);
		parts.emplace_back(text.substr(start, end - start));
		if(end == std::string_view::npos) return parts;
		start = end + 1;
	}
}

string join(const std::vector<string>& parts, std::string_view separator) {
	string result;
	for(size_t i = 0; i < parts.size(); ++i) {
		if(i > 0) result += separator;
		result += parts[i];
	}
	return result;
}

void replaceAll(string& text, std::string_view from, std::string_view to) {
	if(from.empty()) return;
	for(size_t pos = text.find(from); pos != string::npos; pos = text.find(from, pos + to.size())) {
		text.replace(pos, from.size(), to);
	}
}

void replaceFirst(string& text, std::string_view from, std::string_view to) {
	const size_t pos = text.find(from);
	if(pos != string::npos) text.replace(pos, from.size(), to);
}

string guidToString(REFGUID guid) {
	string text = std::format("{{{:08x}-{:04x}-{:04x}-{:02x}{:02x}-{:02x}{:02x}{:02x}{:02x}{:02x}{:02x}}}",
		guid.Data1, guid.Data2, guid.Data3, guid.Data4[0], guid.Data4[1],
		guid.Data4[2], guid.Data4[3], guid.Data4[4], guid.Data4[5], guid.Data4[6], guid.Data4[7]);
	#define UUID_OBJECT(__UUID_OBJECT_) \
	if(guid == __uuidof(__UUID_OBJECT_)) text += " (" #__UUID_OBJECT_ ")";
	#include "uuids.def"
	return text;
}
