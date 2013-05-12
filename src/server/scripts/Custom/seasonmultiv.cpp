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


#define SEASONONE_GOSSIP			" Season 1 Armor"
#define SEASONTWO_GOSSIP			" Season 2 Armor"
#define SEASONTHREE_GOSSIP			" Season 3 Armor"
#define SEASONFOUR_GOSSIP			" Season 4 Armor"
#define SEASONFIVEA_GOSSIP			" Season 5 Armor"
#define SEASONSIX_GOSSIP			" Season 6 Armor"
#define SEASONSEVEN_GOSSIP			" Season 7 Armor"
#define PVPACC_GOSSIP				" PvP Accessories"
#define NVM_GOSSIP					" Nevermind..."

class tc_seasonmultiv : public CreatureScript
{
	public:
		tc_seasonmultiv()
			: CreatureScript("tc_seasonmultiv")
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
creature->SummonCreature(500002, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500002, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONTWO_A:
							{
creature->SummonCreature(500003, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500003, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONTHREE_A:
							{
creature->SummonCreature(500004, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500004, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONFOUR_A:
							{
creature->SummonCreature(500005, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500005, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONFIVE_A:
							{
creature->SummonCreature(500006, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500006, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONSIX_A:
							{
creature->SummonCreature(500009, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500009, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONSEVEN_A:
							{
creature->SummonCreature(500010, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500010, 5.0f, true)) 
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

void AddSC_tc_seasonmultiv()
{
	new tc_seasonmultiv();
}