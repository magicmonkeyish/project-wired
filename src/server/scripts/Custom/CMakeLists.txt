# Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
Custom/beastmaster.cpp
Custom/teleporternpc.cpp
Custom/seasonmultiv.cpp
Custom/battlegmultiv.cpp
Custom/tiergmultiv.cpp
Custom/glyphgemchantmultiv.cpp
Custom/pvprewardmultiv.cpp
Custom/pveweapmultiv.cpp
Custom/pvearmormultiv.cpp
Custom/miscmultiv.cpp
Custom/miscmultiv2.cpp
Custom/profession.cpp
Custom/craftgoodmultiv.cpp
Custom/killstreak.cpp
Custom/killstreak.h
Custom/glyphs.cpp
Custom/mounts.cpp
Custom/enchantnpc.cpp
Custom/Transmogrification.cpp
Custom/Transmogrification.h
Custom/title_system.cpp
Custom/demonspawn.cpp
Custom/player_tools.cpp
Custom/bounty_hunter.cpp
Custom/boss_fafnir.cpp
)

message("  -> Prepared: Custom")
