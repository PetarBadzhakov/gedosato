// GeDoSaTo Copyright 2013-2014 Peter Thoman (Durante)

//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>

#pragma once

#include <cmath>
#include <limits>
#include <string>
using std::string;

#include "utils/string_utils.h"

#ifdef _WIN64
#define EDITION "GENERIC 64 BIT"
#else
#define EDITION "GENERIC"
#endif

#define INTERCEPTOR_NAME "GeDoSaTo"

#define REG_KEY_PATH ("Software\\Durante\\" INTERCEPTOR_NAME)

//#define RELEASE_VER

// SDLOG(level, "std::format string", args...): logged when the logLevel setting is above level.
#ifndef RELEASE_VER
#define SDLOG(_level, ...) { if(Settings::get().getLogLevel() > (_level)) { sdlog(__VA_ARGS__); } }
#define LOG_CHECK(_level, _code) { if(Settings::get().getLogLevel() > _level) { _code; } }
#else
#define SDLOG(_level, ...) {}
#define LOG_CHECK(_level, _code) {}
#endif
#define SAFERELEASE(_p) { if(_p) { \
	auto __retval = (_p)->Release(); \
	SDLOG(10, "Saferelease: {} ({}), loc: {} : {}\n", (_p), __retval, __FILE__, __LINE__); \
	(_p) = NULL; } }
#define SAFEDELETE(_p) { if(_p) { delete (_p); SDLOG(10, "Safedelete: {}, loc: {} : {}\n", (_p), __FILE__, __LINE__); (_p) = nullptr; } }
#define SAFEDELETEARR(_p) { if(_p) { delete [] (_p); SDLOG(10, "Safedeletearr: {}, loc: {} : {}\n", (_p), __FILE__, __LINE__); (_p) = nullptr; } }

#define EPSILON (std::numeric_limits<float>::epsilon()*10)
#define FLT_EQ(__a, __b) (std::abs((__a) - (__b)) <= EPSILON)
#define FLT_EPS(__a, __b, __eps) (std::abs((__a) - (__b)) <= __eps)

#define CHECKHR(__hresult, __message, ...) if(FAILED(__hresult)) { SDLOG(-1, "ERROR: " __message, __VA_ARGS__) }
#define SDASSERT(__cond, __message, ...) if(!(__cond)) { SDLOG(-1, "ERROR: " __message, __VA_ARGS__) }

#include "d3d9/d3d9.h"

bool fileExists(const char *filename);
void messageErrorAndExit(string error);

const string& getInstallDirectory();
const bool getUseBlacklist();
const string& getExeFileName();
string getInstalledFileName(string filename);
string getAssetFileName(string filename);
string getConfigFileName(string filename);
string getTimeString(bool forDisplay = false);
std::wstring strToWStr(const string& input);

extern FILE* g_oFile;

template<typename... Args>
void sdlog(FormatString<Args...> fmt, const Args&... args) {
	if(!g_oFile) return;
	const string text = strFormat(fmt, args...);
	fputs(text.c_str(), g_oFile);
	fflush(g_oFile);
}

extern "C" __declspec(dllexport) const char* GeDoSaToVersion();
