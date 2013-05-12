#include "ScriptPCH.h"

enum eMenus
{
	BOOTS_A					= 1,
	BELT_A					= 2,
	BRACER_A				= 3,
	RING_A					= 4,
	RELIC_A					= 5,
	NVM_EXIT				= 6
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


#define BOOTS_GOSSIP				" Food, Potions and Flasks"
#define RING_GOSSIP					" Tabards"
#define RELIC_GOSSIP				" Pets"
#define NVM_GOSSIP					" Nevermind..."

class tc_misc : public CreatureScript
{
	public:
		tc_misc()
			: CreatureScript("tc_misc")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BOOTS_GOSSIP, GOSSIP_SENDER_MAIN, BOOTS_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, RING_GOSSIP, GOSSIP_SENDER_MAIN, RING_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, RELIC_GOSSIP, GOSSIP_SENDER_MAIN, RELIC_A);
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

case BOOTS_A:
							{
creature->SummonCreature(500153, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500153, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case RING_A:
							{
creature->SummonCreature(500101, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500101, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case RELIC_A:
							{
creature->SummonCreature(500069, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500069, 5.0f, true)) 
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

void AddSC_tc_misc()
{
	new tc_misc();
}