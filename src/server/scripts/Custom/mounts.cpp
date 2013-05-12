#include "ScriptPCH.h"

enum eMenus
{
	MOUNT					= 1,
	FMOUNT					= 2,
	NVM_EXIT				= 3
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

#define MOUNT_GOSSIP				" Mounts"
#define FMOUNT_GOSSIP				" Flying Mounts"
#define NVM_GOSSIP					" Nevermind..."

class hunterglyph : public CreatureScript
{
	public:
		hunterglyph()
			: CreatureScript("hunterglyph")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, MOUNT_GOSSIP, GOSSIP_SENDER_MAIN, MOUNT);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, FMOUNT_GOSSIP, GOSSIP_SENDER_MAIN, FMOUNT);
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

case MOUNT:
							{
creature->SummonCreature(500033, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500033, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case FMOUNT:
							{
creature->SummonCreature(500039, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500039, 5.0f, true)) 
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

void AddSC_hunterglyph()
{
	new hunterglyph();
}