#include "ScriptPCH.h"

#define SPELL_CLONE_PLAYER       57507

class Random_Appearance : public WorldScript
{
public:
	Random_Appearance() : WorldScript("Random_Appearance") {}

	/*uint32 Timer;

	 void SpawnDemon()
	{
		SessionMap Players = sWorld->GetAllSessions();
		if(Players.empty())
			return;
		SessionMap::iterator itr = Players.find(urand(0, Players.size()));
		Player* player = itr->second->GetPlayer();
		Creature* Summoned = player->SummonCreature(30625, player->GetPositionX(), player->GetPositionY(), player->GetPositionZ(), player->GetOrientation(), TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000);
        player->CastSpell(Summoned, SPELL_CLONE_PLAYER, true);
		//const ItemTemplate* rewardedItem = sObjectMgr->GetItemTemplate(RANDOM_ITEM_REWARD_ENTRY);
		std::ostringstream ss;
		ss << "You cannot excape your demons!";
		Summoned->MonsterSay(ss.str().c_str(), LANG_UNIVERSAL, player->GetGUID());
		//player->AddItem(RANDOM_ITEM_REWARD_ENTRY, 1);
		Timer = urand(30000, 30001); 
	}

    void JustSummoned(Creature* summon)
    {
        summon->SelectNearestTarget();
        if (Unit* target = summon->SelectNearestTarget())
            summon->AI()->AttackStart(target);
    }

	void OnStartup()
	{
		Timer = urand(30000, 30001);
	}

	void OnUpdate(uint32 diff)
	{
		if(diff > Timer)
			SpawnDemon();
		else
			Timer -= diff;
	}*/
}; 
void AddSC_Random_Appearance()
{
	new Random_Appearance();
}