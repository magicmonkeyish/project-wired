#include "ScriptPCH.h"

enum eMenus
{
	MY_CITIES_MENU			= 1,
	NVM_EXIT				= 2,
	PLAYER_MENU				= 3,
	HEAL_MENU				= 4,
	BUFF_MENU				= 5,
	CUSTOM_AREAS_MENU		= 6,
	REZ_MENU				= 7,
	A_CITIES_MENU			= 8,
	H_CITIES_MENU			= 9,
	DARNASSUS_PORT 			= 10,
	THE_EXODAR_PORT 		= 11,
	STORMWIND_PORT			= 12,
	IRONFORGE_PORT 			= 13,
	ORGRIMMAR_PORT 			= 14,
	THUNDER_BLUFF_PORT 		= 15,
	UNDERCITY_PORT			= 16,
	SILVERMOON_CITY_PORT 	= 17,
	MY_LOCATIONS_MENU		= 18,
	SERVICES_MENU			= 19,
	DALARAN_PORT			= 20,
	SHATTRATH_CITY_PORT		= 21,
	THE_MALL_PORT			= 22,
	PVP_ARENA_PORT			= 23,
	DUEL_ARENA_PORT			= 24,
	//BSB_ARENA_PORT		= 25,
	//ALTER_STORM_PORT		= 26
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

enum Spells
{
	SPELL_PROTECT		= 13007
};

/* Gossip Colors */
#define TEXT_CUSTOM_ORANGE 			"|cff873600"
#define TEXT_CUSTOM_RED 			"|cffA40000"
#define TEXT_CUSTOM_BLUE 			"|cff00479E"
#define TEXT_CUSTOM_GREEN 			"|cff065600"
#define TEXT_CUSTOM_PURPLE 			"|cff5A005B"
#define TEXT_CUSTOM_GREY			"|cff515151"
#define TEXT_CUSTOM_CYAN			"|cff005853"
#define TEXT_CUSTOM_BROWN			"|cff584200"
/* Gossip Strings */
#define IN_COMBAT					" Leave combat first!"
#define SERVICES_GOSSIP				" -> Services"
#define MY_LOCATIONS_GOSSIP			" My Cities"

/* Add your own locations */
#define THE_MALL_GOSSIP				" The Mall"
#define PVP_ARENA_GOSSIP			" PvP Arena"
//#define DUEL_ARENA_GOSSIP			" Duel Arena"
//#define BSB_ARENA_GOSSIP			" BSB Arena"

#define NVM_GOSSIP					" Nevermind..."
#define GO_BACK_GOSSIP				" ...Go Back"
#define CITIES_GOSSIP				" My Cities"
/* Alliance Cities */
#define DARNASSUS_GOSSIP     		" Darnassus"
#define IRONFORGE_GOSSIP    		" Ironforge"
#define STORMWIND_GOSSIP			" Stormwind"
#define THE_EXODAR_GOSSIP			" The Exodar"
/* Horde Cities */
#define ORGRIMMAR_GOSSIP			" Orgrimmar"
#define SILVERMOON_CITY_GOSSIP		" Silvermoon City"
#define THUNDER_BLUFF_GOSSIP		" Thunder Bluff"
#define UNDERCITY_GOSSIP			" Undercity"
#define DALARAN_GOSSIP				" Dalaran"
#define SHATTRATH_CITY_GOSSIP		" Shattrath"
//#define ALTER_STORM_GOSSIP		" Alter of Storms"

class tc_teleporter : public CreatureScript
{
	public:
		tc_teleporter()
			: CreatureScript("tc_teleporter")
			{}

			bool OnGossipHello(Player* player, Creature* creature)
			{
				player->ADD_GOSSIP_ITEM(FLIGHT_ICON, THE_MALL_GOSSIP, GOSSIP_SENDER_MAIN, THE_MALL_PORT);
				player->ADD_GOSSIP_ITEM(FLIGHT_ICON, PVP_ARENA_GOSSIP, GOSSIP_SENDER_MAIN, PVP_ARENA_PORT);
				//player->ADD_GOSSIP_ITEM(FLIGHT_ICON, DUEL_ARENA_GOSSIP, GOSSIP_SENDER_MAIN, DUEL_ARENA_PORT);
				//player->ADD_GOSSIP_ITEM(FLIGHT_ICON, BSB_ARENA_GOSSIP, GOSSIP_SENDER_MAIN, BSB_ARENA_PORT);
				//player->ADD_GOSSIP_ITEM(FLIGHT_ICON, ALTER_STORM_GOSSIP, GOSSIP_SENDER_MAIN, ALTER_STORM_PORT);
				player->ADD_GOSSIP_ITEM(FLIGHT_ICON, MY_LOCATIONS_GOSSIP, GOSSIP_SENDER_MAIN, MY_LOCATIONS_MENU);
				player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
				player->PlayerTalkClass->SendGossipMenu(50005, creature->GetGUID());
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
						
						case MY_LOCATIONS_MENU:
							if(player->GetTeam() == ALLIANCE){
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, DALARAN_GOSSIP, GOSSIP_SENDER_MAIN, DALARAN_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, DARNASSUS_GOSSIP, GOSSIP_SENDER_MAIN, DARNASSUS_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, IRONFORGE_GOSSIP, GOSSIP_SENDER_MAIN, IRONFORGE_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, SHATTRATH_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SHATTRATH_CITY_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, STORMWIND_GOSSIP, GOSSIP_SENDER_MAIN, STORMWIND_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, THE_EXODAR_GOSSIP, GOSSIP_SENDER_MAIN, THE_EXODAR_PORT);
								player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
								player->PlayerTalkClass->SendGossipMenu(50005, creature->GetGUID());
							}else{
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, DALARAN_GOSSIP, GOSSIP_SENDER_MAIN, DALARAN_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, ORGRIMMAR_GOSSIP, GOSSIP_SENDER_MAIN, ORGRIMMAR_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, SHATTRATH_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SHATTRATH_CITY_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, SILVERMOON_CITY_GOSSIP, GOSSIP_SENDER_MAIN, SILVERMOON_CITY_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, THUNDER_BLUFF_GOSSIP, GOSSIP_SENDER_MAIN, THUNDER_BLUFF_PORT);
								player->ADD_GOSSIP_ITEM(FLIGHT_ICON, UNDERCITY_GOSSIP, GOSSIP_SENDER_MAIN, UNDERCITY_PORT);
								player->ADD_GOSSIP_ITEM(CHAT_DOTS_ICON, NVM_GOSSIP, GOSSIP_SENDER_MAIN, NVM_EXIT);
								player->PlayerTalkClass->SendGossipMenu(50005, creature->GetGUID());
						}break;
						
						case NVM_EXIT:
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case THE_MALL_PORT:
							player->TeleportTo(1, -10737.082f, 2461.409f, 6.8215f, 4.64f);
							player->PlayerTalkClass->SendCloseGossip();
						break;

						case PVP_ARENA_PORT:
							player->TeleportTo(0, -13226.884766f, 231.130249f, 33.243835f, 1.122707f);
							if(player->GetZoneId() != 33)
                            {
							    player->CastSpell(player, SPELL_PROTECT, 2);
                            }
							player->PlayerTalkClass->SendCloseGossip();
						break;

						//case DUEL_ARENA_PORT:
							//player->TeleportTo(571, 5777.124023f, 607.494385f, 609.886292f, 0.882637f);
							//player->PlayerTalkClass->SendCloseGossip();
						//break;

						//case BSB_ARENA_PORT:
						//	player->TeleportTo(650, 801.109802f, 618.136658f, 412.393097f, 3.112614f);
						//	player->PlayerTalkClass->SendCloseGossip();
						//break;
						
						case DALARAN_PORT:
							player->TeleportTo(571, 5804.149902f, 624.770996f,648.747009f, 1.640000f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case SHATTRATH_CITY_PORT:
							player->TeleportTo(530, -1833.544312f, 5312.579590f, -9.536835f, 1.349267f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case DARNASSUS_PORT:
							player->TeleportTo(1, 9949.559570f, 2284.20996f, 1342.969482f, 1.595870f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case IRONFORGE_PORT:
							player->TeleportTo(0, -4918.879883f, -940.406006f, 504.854126f, 5.423470f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case STORMWIND_PORT:
							player->TeleportTo(0, -8833.379883f, 628.627991f, 95.826599f, 1.065350f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case THE_EXODAR_PORT:
							player->TeleportTo(530, -3965.699951f, -11653.599609f, -137.184998f, 0.852154f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case ORGRIMMAR_PORT:
							player->TeleportTo(1, 1629.359985f, -4373.390137f, 33.097401f, 3.548390f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case SILVERMOON_CITY_PORT:
							player->TeleportTo(530, 9482.883789f, -7278.637207f, 18.480778f, 6.040224f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case THUNDER_BLUFF_PORT:
							player->TeleportTo(1, -1277.369995f, 124.804001f, 134.094009f, 5.222740f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						case UNDERCITY_PORT:
							player->TeleportTo(0, 1584.069946f, 241.987000f, -51.075413f, 1.296860f);
							player->PlayerTalkClass->SendCloseGossip();
						break;
						
						//case ALTER_STORM_PORT:
						//	player->TeleportTo(0, -7616.580566f, -747.940063f, 190.789841f, 4.97502f);
						//	player->PlayerTalkClass->SendCloseGossip();
						//break;
					}
				}
				return true;
			}
};

void AddSC_tc_teleporter()
{
	new tc_teleporter();
}