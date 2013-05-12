#include "ScriptPCH.h"

enum eMenus
{
	TIERONE_A				= 1,
	TIERTWO_A				= 2,
    TIERTWO_B               = 3,
	TIERTHREE_A				= 4,
	TIERFOUR_A				= 5,
	TIERFIVE_A				= 6,
	TIERSIX_A				= 7,
	TIERSEVEN_A				= 8,
	TIERSEVEN_B				= 9,
	TIEREIGHT_A				= 10,
	TIEREIGHT_B				= 11,
	TIERNINE_A				= 12,
	TIERNINE_B				= 13,
	NVM_EXIT				= 14
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


#define TIERONE_GOSSIP				" Tier 1"
#define TIERTWO_GOSSIP				" Tier 2"
#define TIERTWOB_GOSSIP				" Tier 2.5"
#define TIERTHREE_GOSSIP			" Tier 3"
#define TIERFOUR_GOSSIP				" Tier 4"
#define TIERFIVE_GOSSIP				" Tier 5"
#define TIERSIX_GOSSIP				" Tier 6"
#define TIERSEVEN_GOSSIP			" Tier 7"
#define TIERSEVENB_GOSSIP			" Tier 7.5"
#define TIEREIGHT_GOSSIP			" Tier 8"
#define TIEREIGHTB_GOSSIP			" Tier 8.5"
#define TIERNINE_GOSSIP				" Tier 9"
#define TIERNINEB_GOSSIP			" Tier 9"
#define NVM_GOSSIP					" Nevermind..."

class tc_tierg : public CreatureScript
{
	public:
		tc_tierg()
			: CreatureScript("tc_tierg")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				if(player->GetTeam() == ALLIANCE){
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERONE_GOSSIP, GOSSIP_SENDER_MAIN, TIERONE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTWO_GOSSIP, GOSSIP_SENDER_MAIN, TIERTWO_A);
                player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTWOB_GOSSIP, GOSSIP_SENDER_MAIN, TIERTWO_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTHREE_GOSSIP, GOSSIP_SENDER_MAIN, TIERTHREE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERFOUR_GOSSIP, GOSSIP_SENDER_MAIN, TIERFOUR_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERFIVE_GOSSIP, GOSSIP_SENDER_MAIN, TIERFIVE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSIX_GOSSIP, GOSSIP_SENDER_MAIN, TIERSIX_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSEVEN_GOSSIP, GOSSIP_SENDER_MAIN, TIERSEVEN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSEVENB_GOSSIP, GOSSIP_SENDER_MAIN, TIERSEVEN_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIEREIGHT_GOSSIP, GOSSIP_SENDER_MAIN, TIEREIGHT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIEREIGHTB_GOSSIP, GOSSIP_SENDER_MAIN, TIEREIGHT_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERNINE_GOSSIP, GOSSIP_SENDER_MAIN, TIERNINE_A);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}else{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERONE_GOSSIP, GOSSIP_SENDER_MAIN, TIERONE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTWO_GOSSIP, GOSSIP_SENDER_MAIN, TIERTWO_A);
                player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTWOB_GOSSIP, GOSSIP_SENDER_MAIN, TIERTWO_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERTHREE_GOSSIP, GOSSIP_SENDER_MAIN, TIERTHREE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERFOUR_GOSSIP, GOSSIP_SENDER_MAIN, TIERFOUR_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERFIVE_GOSSIP, GOSSIP_SENDER_MAIN, TIERFIVE_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSIX_GOSSIP, GOSSIP_SENDER_MAIN, TIERSIX_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSEVEN_GOSSIP, GOSSIP_SENDER_MAIN, TIERSEVEN_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERSEVENB_GOSSIP, GOSSIP_SENDER_MAIN, TIERSEVEN_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIEREIGHT_GOSSIP, GOSSIP_SENDER_MAIN, TIEREIGHT_A);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIEREIGHTB_GOSSIP, GOSSIP_SENDER_MAIN, TIEREIGHT_B);
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, TIERNINEB_GOSSIP, GOSSIP_SENDER_MAIN, TIERNINE_B);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
				return true;
				}
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

case TIERONE_A:
							{
creature->SummonCreature(500075, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500075, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERTWO_A:
							{
creature->SummonCreature(500076, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500076, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERTWO_B:
							{
creature->SummonCreature(500169, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500169, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERTHREE_A:
							{
creature->SummonCreature(500077, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500077, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERFOUR_A:
							{
creature->SummonCreature(500078, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500078, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERFIVE_A:
							{
creature->SummonCreature(500079, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500079, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERSIX_A:
							{
creature->SummonCreature(500080, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500080, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERSEVEN_A:
							{
creature->SummonCreature(500081, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500081, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERSEVEN_B:
							{
creature->SummonCreature(500082, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500082, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIEREIGHT_A:
							{
creature->SummonCreature(500083, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500083, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIEREIGHT_B:
							{
creature->SummonCreature(500084, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500084, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERNINE_A:
							{
creature->SummonCreature(500086, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500086, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case TIERNINE_B:
							{
creature->SummonCreature(500133, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500133, 5.0f, true)) 
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

void AddSC_tc_tierg()
{
	new tc_tierg();
}