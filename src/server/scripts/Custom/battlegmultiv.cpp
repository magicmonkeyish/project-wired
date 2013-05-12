#include "ScriptPCH.h"

enum eMenus
{
	SEASONONE_A				= 1,
	SEASONTWO_A				= 2,
	SEASONTHREE_A			= 3,
	SEASONFOUR_A			= 4,
	SEASONFIVE_A			= 5,
	SEASONSIX_A				= 6,
	SEASONSEVEN_A			= 7,
	PVPACC_A				= 8,
	NVM_EXIT				= 9
};

enum eIcons
{
	CHAT_ICON 			= 0,
	VENDOR_ICON 		= 1,
	FLIGHT_ICON 		= 2,
	TRAINER_ICON 		= 3,
	GEAR_ICON 			= 4,
	GEAR_ICON_2 		= 5,
	BANK_ICON 			= 6,
	CHAT_DOTS_ICON 		= 7,
	TABARD_ICON 		= 8,
	SWORDS_ICON 		= 9,
	GOLD_DOT_ICON 		= 10
};


#define SEASONONE_GOSSIP			" Season 1 Weapons"
#define SEASONTWO_GOSSIP			" Season 2 Weapons"
#define SEASONTHREE_GOSSIP			" Season 3 Weapons"
#define SEASONFOUR_GOSSIP			" Season 4 Weapons"
#define SEASONFIVEA_GOSSIP			" Season 5 Weapons"
#define SEASONSIX_GOSSIP			" Season 6 Weapons"
#define SEASONSEVEN_GOSSIP			" Season 7 Weapons"
#define PVPACC_GOSSIP				" PvP Accessories"
#define NVM_GOSSIP					" Nevermind..."

class tc_battleg : public CreatureScript
{
	public:
		tc_battleg()
			: CreatureScript("tc_battleg")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONONE_GOSSIP, GOSSIP_SENDER_MAIN, SEASONONE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONTWO_GOSSIP, GOSSIP_SENDER_MAIN, SEASONTWO_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONTHREE_GOSSIP, GOSSIP_SENDER_MAIN, SEASONTHREE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONFOUR_GOSSIP, GOSSIP_SENDER_MAIN, SEASONFOUR_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONFIVEA_GOSSIP, GOSSIP_SENDER_MAIN, SEASONFIVE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONSIX_GOSSIP, GOSSIP_SENDER_MAIN, SEASONSIX_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONSEVEN_GOSSIP, GOSSIP_SENDER_MAIN, SEASONSEVEN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, PVPACC_GOSSIP, GOSSIP_SENDER_MAIN, PVPACC_A);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
			}
			
			bool OnGossipSelect(Player* player, Creature* creature, uint32 Sender, uint32 Actions)
			{
                 player->PlayerTalkClass->ClearMenus();

				 if (player->isInCombat())
				 {
							player->CLOSE_GOSSIP_MENU();
							creature->MonsterSay("You are in combat!", LANG_UNIVERSAL, NULL);
							return false;
				 }
				
				 if(Sender == GOSSIP_SENDER_MAIN)
				 {
					switch(Actions)
					{

case SEASONONE_A:
							{
creature->SummonCreature(500116, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500116, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONTWO_A:
							{
creature->SummonCreature(500117, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500117, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONTHREE_A:
							{
creature->SummonCreature(500118, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500118, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONFOUR_A:
							{
creature->SummonCreature(500119, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500119, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONFIVE_A:
							{
creature->SummonCreature(500120, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500120, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONSIX_A:
							{
creature->SummonCreature(500121, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500121, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONSEVEN_A:
							{
creature->SummonCreature(500122, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500122, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case PVPACC_A:
							{
creature->SummonCreature(999998, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(999998, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case NVM_EXIT:
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
					}
				}
				return true;
			}
};

void AddSC_tc_battleg()
{
	new tc_battleg();
}