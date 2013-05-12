#include "ScriptPCH.h"
#include "killstreak.h"

class System_OnKill : public PlayerScript
{
public:
        System_OnKill() : PlayerScript("System_OnKill") {}

		/*void alertServer(Player * killer, Player * victim, int32 killstreak, int code)
		{
        char msg[200];
 
		switch(code)
			{
				case 0:
                        sprintf(msg, "|cffff0000[Killstreak] |cffffffff%s's |cff00ffffkillstreak of %d has been ended by |cffffffff%s", victim->GetName(), killstreak, killer->GetName());
                        break;
				case 1:
                        sprintf(msg, "|cffff0000[Killstreak] |cffffffff%s|cff00ffff has a killstreak of %d", killer->GetName(), killstreak);
                        break;
				case 2:
                        sprintf(msg, "|cffff0000[Killstreak] |cffffffff%s|cff00ffff has a killstreak of %d. A bounty worth 50 arena points has been placed for their head.", killer->GetName(), killstreak);
                        break;
			}
 
			sWorld->SendServerMessage(SERVER_MSG_STRING, msg, 0);
		} */

        void OnPVPKill(Player * Killer, Player * Victim)
        {
                if(Killer->GetZoneId() != 33) // zone not STV, return
                        return;

                uint64 KillerGUID = Killer->GetGUID();
                uint64 VictimGUID = Victim->GetGUID();

                if( KillerGUID == VictimGUID || KillStreakData[KillerGUID].lastkill == VictimGUID )
                        return;

				int reward = 100;

                if(Killer->GetTeam() == Victim->GetTeam()) 
                {
                    Killer->ModifyHonorPoints(100);
                }

				KillStreakData[KillerGUID].killstreak++;
                KillStreakData[KillerGUID].lastkill = VictimGUID;
                KillStreakData[VictimGUID].killstreak = 0;
                KillStreakData[VictimGUID].lastkill = 0;
                
                if(KillStreakData[VictimGUID].killstreak >= 5) // victim has 5 or more kills, announce end of their killstreak
                {
                        char msg[200];
                        snprintf(msg, 200, "|cFF00FF00[PvP System]: %s has ended %s's killstreak of %u!", Killer->GetName(), Victim->GetName(), KillStreakData[VictimGUID].killstreak);
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

                if( KillStreakData[KillerGUID].killstreak % 1 == 0 ) // get 1 badge per kill
                {
                        Killer->AddItem(49426, 1);
                }
          
                if( KillStreakData[KillerGUID].killstreak % 5 == 0 ) // send killstreak message every 5 kills
                {
                        char msg[200];
						//alertServer(Killer, Victim, KillStreakData[KillerGUID].killstreak, 1);
                        snprintf(msg, 200, "|cFF00FF00[PvP System]: %s is on a killstreak of %u!", Killer->GetName(), KillStreakData[KillerGUID].killstreak);
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

                if( KillStreakData[KillerGUID].killstreak >= 10 ) // reward an extra badge after 10 kills
                        Killer->AddItem(49426, 1);

				if( KillStreakData[KillerGUID].killstreak == 5 ) // send killstreak message on the 5th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: KILLING SPREE!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

				if( KillStreakData[KillerGUID].killstreak == 10 ) // send killstreak message on the 10th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: KILLING FRENZY!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

				if( KillStreakData[KillerGUID].killstreak == 20 ) // send killstreak message on the 20th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: RUNNING RIOT!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

				if( KillStreakData[KillerGUID].killstreak == 30 ) // send killstreak message on the 30th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: RAMPAGE!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
				}

				if( KillStreakData[KillerGUID].killstreak == 45 ) // send killstreak message on the 45th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: UNTOUCHABLE!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

				if( KillStreakData[KillerGUID].killstreak == 60 ) // send killstreak message on the 60th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: INVINCIBLE!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);
                }

				if( KillStreakData[KillerGUID].killstreak == 100 ) // send killstreak message on the 100th kill
                {
                        char msg[250];
                        snprintf(msg, 250, "|cFF00FF00[PvP System]: GODMODE!");
                        sWorld->SendServerMessage(SERVER_MSG_STRING, msg);

                }
        }

        void OnLogin(Player* player)
        {
                KillStreakData.erase(player->GetGUID());
        }
        void OnLogout(Player* player)
        {
                KillStreakData.erase(player->GetGUID());
        }
        
};
void AddSC_PvP_System()
{
        new System_OnKill;
}