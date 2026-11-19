#pragma once

#include <memory>

#include "utils/win_utils.h"
#include "console.h"
#include "detouring.h"

class TimeManager {
	TimeManager(const TimeManager&) = delete;
	TimeManager& operator=(const TimeManager&) = delete;

	static std::unique_ptr<TimeManager> instance;

	bool frozen = false;
	LARGE_INTEGER perfCounterAtFreeze = {0, 0};
	LARGE_INTEGER startPerfCounter;
	DWORD startTimeGetTime;

public:
	TimeManager();

	static TimeManager& get() {
		if(!instance) instance = std::make_unique<TimeManager>();
		return *instance;
	}

	void toggleFreeze();

	BOOL redirectQueryPerformanceCounter(LARGE_INTEGER *lpPerformanceCount);

	DWORD redirectTimeGetTime();
};
