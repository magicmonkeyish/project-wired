#include "ScriptPCH.h"

enum eMenus
{
	CLOTH_A					= 1,
	COOKING_A				= 2,
	HERBS_A					= 3,
	METAL_A					= 4,
	GEMS_A					= 5,
	ENCHANT_A				= 6,
	JEWEL_A					= 7,
	LEATHER_A				= 8,
	INSCRIPTION_A			= 9,
	ELEMENTAL_A				= 10,
	CRAFT_A					= 11,
	NVM_EXIT				= 12
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


#define CLOTH_GOSSIP				" Cloth"
#define COOKING_GOSSIP				" Cooking"
#define HERBS_GOSSIP				" Herbs"
#define METAL_GOSSIP				" Metal and Stone"
#define GEMS_GOSSIP					" Gems"
#define ENCHANT_GOSSIP				" Enchanting"
#define JEWEL_GOSSIP				" Jewelcrafting"
#define LEATHER_GOSSIP				" Leather"
#define INSCRIPTION_GOSSIP			" Inscription"
#define ELEMENTAL_GOSSIP			" Elemental"
#define CRAFT_GOSSIP				" Crafting"
#define NVM_GOSSIP					" Nevermind..."

class tc_tradegood : public CreatureScript
{
	public:
		tc_tradegood()
			: CreatureScript("tc_tradegood")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, CLOTH_GOSSIP, GOSSIP_SENDER_MAIN, CLOTH_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, COOKING_GOSSIP, GOSSIP_SENDER_MAIN, COOKING_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, HERBS_GOSSIP, GOSSIP_SENDER_MAIN, HERBS_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, METAL_GOSSIP, GOSSIP_SENDER_MAIN, METAL_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, GEMS_GOSSIP, GOSSIP_SENDER_MAIN, GEMS_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ENCHANT_GOSSIP, GOSSIP_SENDER_MAIN, ENCHANT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, JEWEL_GOSSIP, GOSSIP_SENDER_MAIN, JEWEL_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, LEATHER_GOSSIP, GOSSIP_SENDER_MAIN, LEATHER_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, INSCRIPTION_GOSSIP, GOSSIP_SENDER_MAIN, INSCRIPTION_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ELEMENTAL_GOSSIP, GOSSIP_SENDER_MAIN, ELEMENTAL_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, CRAFT_GOSSIP, GOSSIP_SENDER_MAIN, CRAFT_A);
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

case CLOTH_A:
							{
creature->SummonCreature(500018, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500018, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case COOKING_A:
							{
creature->SummonCreature(500058, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500058, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case HERBS_A:
							{
creature->SummonCreature(500043, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500043, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case METAL_A:
							{
creature->SummonCreature(500060, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500060, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case GEMS_A:
							{
creature->SummonCreature(500040, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500040, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ENCHANT_A:
							{
creature->SummonCreature(500031, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500031, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case JEWEL_A:
							{
creature->SummonCreature(500052, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500052, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case LEATHER_A:
							{
creature->SummonCreature(500054, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500054, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case INSCRIPTION_A:
							{
creature->SummonCreature(500048, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500048, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ELEMENTAL_A:
							{
creature->SummonCreature(500028, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500028, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case CRAFT_A:
							{
creature->SummonCreature(500022, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500022, 5.0f, true)) 
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

void AddSC_tc_tradegood()
{
	new tc_tradegood();
}