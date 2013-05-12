#include "ScriptPCH.h"

enum eMenus
{
	META_A					= 1,
	RED_A					= 2,
	BLUE_A					= 3,
	YELLOW_A				= 4,
	ORANGE_A				= 5,
	PURPLE_A				= 6,
	GREEN_A					= 7,
	WEAPONENCHANT_A			= 8,
	ARMORENCHANT_A			= 9,
	ITEMENCHANT_A			= 10,
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


#define META_GOSSIP					" Meta Gems"
#define RED_GOSSIP					" Red Gems"
#define BLUE_GOSSIP					" Blue Gems"
#define YELLOW_GOSSIP				" Yellow Gems"
#define ORANGE_GOSSIP				" Orange Gems"
#define PURPLE_GOSSIP				" Purple Gems"
#define GREEN_GOSSIP				" Green Gems"
#define WEAPONENCHANT_GOSSIP		" Weapon Enchants"
#define ARMORENCHANT_GOSSIP			" Armor Enchants"
#define ITEMENCHANT_GOSSIP			" Item Enchants"
#define NVM_GOSSIP					" Nevermind..."

class tc_glyphgemchant : public CreatureScript
{
	public:
		tc_glyphgemchant()
			: CreatureScript("tc_glyphgemchant")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, META_GOSSIP, GOSSIP_SENDER_MAIN, META_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, RED_GOSSIP, GOSSIP_SENDER_MAIN, RED_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BLUE_GOSSIP, GOSSIP_SENDER_MAIN, BLUE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, YELLOW_GOSSIP, GOSSIP_SENDER_MAIN, YELLOW_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ORANGE_GOSSIP, GOSSIP_SENDER_MAIN, ORANGE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, PURPLE_GOSSIP, GOSSIP_SENDER_MAIN, PURPLE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, GREEN_GOSSIP, GOSSIP_SENDER_MAIN, GREEN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, WEAPONENCHANT_GOSSIP, GOSSIP_SENDER_MAIN, WEAPONENCHANT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ARMORENCHANT_GOSSIP, GOSSIP_SENDER_MAIN, ARMORENCHANT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ITEMENCHANT_GOSSIP, GOSSIP_SENDER_MAIN, ITEMENCHANT_A);
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

case META_A:
							{
creature->SummonCreature(500059, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500059, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case RED_A:
							{
creature->SummonCreature(500092, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500092, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case BLUE_A:
							{
creature->SummonCreature(500014, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500014, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case YELLOW_A:
							{
creature->SummonCreature(500112, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500112, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ORANGE_A:
							{
creature->SummonCreature(500067, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500067, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case PURPLE_A:
							{
creature->SummonCreature(500073, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500073, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case GREEN_A:
							{
creature->SummonCreature(500041, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500041, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case WEAPONENCHANT_A:
							{
creature->SummonCreature(500136, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500136, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ARMORENCHANT_A:
							{
creature->SummonCreature(500137, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500137, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ITEMENCHANT_A:
							{
creature->SummonCreature(500049, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500049, 5.0f, true)) 
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

void AddSC_tc_glyphgemchant()
{
	new tc_glyphgemchant();
}