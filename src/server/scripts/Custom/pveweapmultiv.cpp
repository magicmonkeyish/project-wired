#include "ScriptPCH.h"

enum eMenus
{
	ONEHSWORD_A				= 1,
	TWOHSWORD_A				= 2,
	ONEHMACE_A				= 3,
	TWOHMACE_A				= 4,
	ONEHAXE_A				= 5,
	TWOHAXE_A				= 6,
	DAGGER_A				= 7,
	FISTW_A					= 8,
	POLE_A					= 9,
	THROWN_A				= 10,
	GUN_A					= 11,
	BOW_A					= 12,
	CBOW_A					= 13,
	WAND_A					= 14,
	STAVE_A					= 15,
	NVM_EXIT				= 21
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


#define ONEHSWORD_GOSSIP			" One-Handed Swords"
#define TWOHSWORD_GOSSIP			" Two-Handed Swords"
#define ONEHMACE_GOSSIP				" One-Handed Maces"
#define TWOHMACE_GOSSIP				" Two-Handed Maces"
#define ONEHAXE_GOSSIP				" One-Handed Axes"
#define TWOHAXE_GOSSIP				" Two-Handed Axes"
#define DAGGER_GOSSIP				" Daggers"
#define FISTW_GOSSIP				" Fist Weapons"
#define POLE_GOSSIP					" Polearms"
#define THROWN_GOSSIP				" Thrown Weapons"
#define GUN_GOSSIP					" Guns"
#define BOW_GOSSIP					" Bows"
#define CBOW_GOSSIP					" Crossbows"
#define WAND_GOSSIP					" Wands"
#define STAVE_GOSSIP				" Staves"
#define NVM_GOSSIP					" Nevermind..."

class tc_pveweapon : public CreatureScript
{
	public:
		tc_pveweapon()
			: CreatureScript("tc_pveweapon")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ONEHSWORD_GOSSIP, GOSSIP_SENDER_MAIN, ONEHSWORD_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TWOHSWORD_GOSSIP, GOSSIP_SENDER_MAIN, TWOHSWORD_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ONEHMACE_GOSSIP, GOSSIP_SENDER_MAIN, ONEHMACE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TWOHMACE_GOSSIP, GOSSIP_SENDER_MAIN, TWOHMACE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ONEHAXE_GOSSIP, GOSSIP_SENDER_MAIN, ONEHAXE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TWOHAXE_GOSSIP, GOSSIP_SENDER_MAIN, TWOHAXE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, DAGGER_GOSSIP, GOSSIP_SENDER_MAIN, DAGGER_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, FISTW_GOSSIP, GOSSIP_SENDER_MAIN, FISTW_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, POLE_GOSSIP, GOSSIP_SENDER_MAIN, POLE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, THROWN_GOSSIP, GOSSIP_SENDER_MAIN, THROWN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, GUN_GOSSIP, GOSSIP_SENDER_MAIN, GUN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, BOW_GOSSIP, GOSSIP_SENDER_MAIN, BOW_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, CBOW_GOSSIP, GOSSIP_SENDER_MAIN, CBOW_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, WAND_GOSSIP, GOSSIP_SENDER_MAIN, WAND_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, STAVE_GOSSIP, GOSSIP_SENDER_MAIN, STAVE_A);
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

case ONEHSWORD_A:
							{
creature->SummonCreature(500066, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500066, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TWOHSWORD_A:
							{
creature->SummonCreature(500108, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500108, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ONEHMACE_A:
							{
creature->SummonCreature(500065, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500065, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TWOHMACE_A:
							{
creature->SummonCreature(500107, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500107, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ONEHAXE_A:
							{
creature->SummonCreature(500064, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500064, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TWOHAXE_A:
							{
creature->SummonCreature(500106, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500106, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case DAGGER_A:
							{
creature->SummonCreature(500025, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500025, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case FISTW_A:
							{
creature->SummonCreature(500037, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500037, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case POLE_A:
							{
creature->SummonCreature(500070, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500070, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case THROWN_A:
							{
creature->SummonCreature(500104, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500104, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case GUN_A:
							{
creature->SummonCreature(500042, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500042, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case BOW_A:
							{
creature->SummonCreature(500016, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500016, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case CBOW_A:
							{
creature->SummonCreature(500023, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500023, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case WAND_A:
							{
creature->SummonCreature(500109, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500109, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case STAVE_A:
							{
creature->SummonCreature(500100, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500100, 5.0f, true)) 
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

void AddSC_tc_pveweapon()
{
	new tc_pveweapon();
}