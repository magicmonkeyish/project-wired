#include "ScriptPCH.h"

enum eMenus
{
	WARRIOR					= 1,
	ROGUE					= 2,
	SHAMAN					= 3,
	HUNTER					= 4,
	DRUID					= 5,
	PALADIN					= 6,
	WARLOCK					= 7,
	MAGE					= 8,
	PRIEST					= 9,
	DEATHKNIGHT				= 10,
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


#define WARRIOR_GOSSIP				" Warrior Glyphs"
#define ROGUE_GOSSIP				" Rogue Glyphs"
#define SHAMAN_GOSSIP				" Shaman Glyphs"
#define HUNTER_GOSSIP				" Hunter Glyphs"
#define DRUID_GOSSIP				" Druid Glyphs"
#define PALADIN_GOSSIP				" Paladin Glyphs"
#define WARLOCK_GOSSIP				" Warlock Glyphs"
#define MAGE_GOSSIP					" Mage Glyphs"
#define DEATHKNIGHT_GOSSIP			" Death Knight Glyphs"
#define PRIEST_GOSSIP				" Priest Glyphs"
#define NVM_GOSSIP					" Nevermind..."

class deathknightglyph : public CreatureScript
{
	public:
		deathknightglyph()
			: CreatureScript("deathknightglyph")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				if(player->getClass() == CLASS_WARRIOR)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, WARRIOR_GOSSIP, GOSSIP_SENDER_MAIN, WARRIOR);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_ROGUE)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, ROGUE_GOSSIP, GOSSIP_SENDER_MAIN, ROGUE);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_MAGE)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, MAGE_GOSSIP, GOSSIP_SENDER_MAIN, MAGE);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_DRUID)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, DRUID_GOSSIP, GOSSIP_SENDER_MAIN, DRUID);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_WARLOCK)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, WARLOCK_GOSSIP, GOSSIP_SENDER_MAIN, WARLOCK);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_SHAMAN)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, SHAMAN_GOSSIP, GOSSIP_SENDER_MAIN, SHAMAN);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_PALADIN)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, PALADIN_GOSSIP, GOSSIP_SENDER_MAIN, PALADIN);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_PRIEST)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, PRIEST_GOSSIP, GOSSIP_SENDER_MAIN, PRIEST);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_HUNTER)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, HUNTER_GOSSIP, GOSSIP_SENDER_MAIN, HUNTER);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(1, creature->GetGUID());
                return true;
				}

				if(player->getClass() == CLASS_DEATH_KNIGHT)
				{
				player->ADD_GOSSIP_ITEM(VENDOR_ICON, DEATHKNIGHT_GOSSIP, GOSSIP_SENDER_MAIN, DEATHKNIGHT);
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

case WARRIOR:
							{
creature->SummonCreature(500111, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500111, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case ROGUE:
							{
creature->SummonCreature(500095, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500095, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case SHAMAN:
							{
creature->SummonCreature(500097, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500097, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case MAGE:
							{
creature->SummonCreature(500057, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500057, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case PRIEST:
							{
creature->SummonCreature(500113, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500113, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case PALADIN:
							{
creature->SummonCreature(500068, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500068, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case WARLOCK:
							{
creature->SummonCreature(500110, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500110, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case DRUID:
							{
creature->SummonCreature(500027, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500027, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case HUNTER:
							{
creature->SummonCreature(500046, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500046, 5.0f, true)) 
player->GetSession()->SendListInventory(c->GetGUID());
else
player->PlayerTalkClass->SendCloseGossip();
}
break;

case DEATHKNIGHT:
							{
creature->SummonCreature(500026, creature->GetPositionX(), creature->GetPositionY(), creature->GetPositionZ(), creature->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 300*IN_MILLISECONDS);
if(Creature * c = creature->FindNearestCreature(500026, 5.0f, true)) 
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

void AddSC_deathknightglyph()
{
	new deathknightglyph();
}