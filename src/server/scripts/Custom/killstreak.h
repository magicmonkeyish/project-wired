#include "ScriptPCH.h"

struct KillStreak_Info
                {
                                uint32 killstreak;
                                uint64 lastkill;
                };
                static std::map<uint64, KillStreak_Info> KillStreakData;
				