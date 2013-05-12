#include "ScriptPCH.h"

enum eMenus
{
	SEASONONE_A				= 1,
	SEASONEIGHT_A			= 2,
	SEASONEIGHT_B			= 3,
	TRANSMOG_A				= 4,
	COLLECT_A				= 5,
    BADGE                   = 6,
	NVM_EXIT				= 7
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


#define SEASONONE_GOSSIP			" PvP Accessories"
#define SEASONEIGHTA_GOSSIP			" Season 8 Armor"
#define SEASONEIGHTB_GOSSIP			" Season 8 Weapons"
#define TRANSMOG_GOSSIP				" Transmogrification Items"
#define COLLECT_GOSSIP				" Collectables"
#define BADGE_GOSSIP				" Emblem Rewards"
#define NVM_GOSSIP					" Nevermind..."

class tc_pvpreward : public CreatureScript
{
	public:
		tc_pvpreward()
			: CreatureScript("tc_pvpreward")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONONE_GOSSIP, GOSSIP_SENDER_MAIN, SEASONONE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONEIGHTA_GOSSIP, GOSSIP_SENDER_MAIN, SEASONEIGHT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SEASONEIGHTB_GOSSIP, GOSSIP_SENDER_MAIN, SEASONEIGHT_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TRANSMOG_GOSSIP, GOSSIP_SENDER_MAIN, TRANSMOG_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, COLLECT_GOSSIP, GOSSIP_SENDER_MAIN, COLLECT_A);
                player->ADD_GOSSIP_ITEM(VENDOR_ICON, BADGE_GOSSIP, GOSSIP_SENDER_MAIN, BADGE);
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
creature->SummonCreature(500115, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500115, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONEIGHT_A:
							{
creature->SummonCreature(500114, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500114, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SEASONEIGHT_B:
							{
creature->SummonCreature(500123, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500123, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TRANSMOG_A:
							{
creature->SummonCreature(500056, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500056, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case COLLECT_A:
							{
creature->SummonCreature(500103, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500103, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case BADGE:
							{
creature->SummonCreature(500168, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500168, 5.0f, true)) 
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

void AddSC_tc_pvpreward()
{
	new tc_pvpreward();
}