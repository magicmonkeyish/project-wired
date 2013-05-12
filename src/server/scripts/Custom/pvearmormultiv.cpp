#include "ScriptPCH.h"

enum eMenus
{
	BOOTS_A					= 1,
	BELT_A					= 2,
	BRACER_A				= 3,
	RING_A					= 4,
	CLOAK_A					= 5,
	NECK_A					= 6,
	RELIC_A					= 7,
	TRINKET_A				= 8,
	SHIELD_A				= 9,
	OFFH_A					= 10,
	NVM_EXIT				= 11
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


#define BOOTS_GOSSIP				" Boots"
#define BELT_GOSSIP					" Belts"
#define BRACER_GOSSIP				" Bracers"
#define RING_GOSSIP					" Rings"
#define CLOAK_GOSSIP				" Cloaks"
#define NECK_GOSSIP					" Necks"
#define RELIC_GOSSIP				" Relics"
#define TRINKET_GOSSIP				" Trinkets"
#define SHIELD_GOSSIP				" Shields"
#define OFFH_GOSSIP					" Offhand"
#define NVM_GOSSIP					" Nevermind..."

class tc_pvearmor : public CreatureScript
{
	public:
		tc_pvearmor()
			: CreatureScript("tc_pvearmor")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BOOTS_GOSSIP, GOSSIP_SENDER_MAIN, BOOTS_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BELT_GOSSIP, GOSSIP_SENDER_MAIN, BELT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BRACER_GOSSIP, GOSSIP_SENDER_MAIN, BRACER_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, RING_GOSSIP, GOSSIP_SENDER_MAIN, RING_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, CLOAK_GOSSIP, GOSSIP_SENDER_MAIN, CLOAK_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, NECK_GOSSIP, GOSSIP_SENDER_MAIN, NECK_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, RELIC_GOSSIP, GOSSIP_SENDER_MAIN, RELIC_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TRINKET_GOSSIP, GOSSIP_SENDER_MAIN, TRINKET_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SHIELD_GOSSIP, GOSSIP_SENDER_MAIN, SHIELD_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, OFFH_GOSSIP, GOSSIP_SENDER_MAIN, OFFH_A);
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
creature->SummonCreature(500139, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500139, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case BELT_A:
							{
creature->SummonCreature(500141, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500141, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case BRACER_A:
							{
creature->SummonCreature(500143, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500143, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case RING_A:
							{
creature->SummonCreature(500094, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500094, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case CLOAK_A:
							{
creature->SummonCreature(500017, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500017, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case NECK_A:
							{
creature->SummonCreature(500001, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500001, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case RELIC_A:
							{
creature->SummonCreature(500093, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500093, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TRINKET_A:
							{
creature->SummonCreature(500105, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500105, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SHIELD_A:
							{
creature->SummonCreature(500098, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500098, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case OFFH_A:
							{
creature->SummonCreature(500063, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500063, 5.0f, true)) 
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

void AddSC_tc_pvearmor()
{
	new tc_pvearmor();
}