#include "ScriptMgr.h"
#include "ScriptedCreature.h"

#define SPELL_CAPTURESOUL           21054
#define SPELL_TIMELAPSE				36300

enum eEnums
{
    SAY_ENTER           = 0,
    SAY_AGGRO           = 1,
    SAY_BANISH          = 2,
    SAY_SLAY1           = 3,
    SAY_SLAY2           = 3,
    SAY_DEATH           = 4,
    EMOTE_FRENZY        = 5,

    SPELL_CLEAVE        = 68868,
    SPELL_TIMESTOP		= 31422,
    SPELL_SANDBREATH	= 75954,
	SPELL_TAIL_SWEEP    = 69286,
	SPELL_HASTE         = 43139,
    SPELL_MORTAL_WOUND  = 25646,
	SPELL_RAINFIRE		= 59369,
	SPELL_FULLHEAL		= 23965,
	SPELL_DEATHDECAY	= 54531,
	SPELL_ICELANCE		= 72123,
	SPELL_COMBAT		= 59431,
};

class boss_fafnir : public CreatureScript
{

public:
    boss_fafnir() : CreatureScript("boss_fafnir") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_fafnirAI (creature);
    }

    struct boss_fafnirAI : public ScriptedAI
    {
        boss_fafnirAI(Creature* creature) : ScriptedAI(creature) {}

		bool Enraged;

        uint32 SandBreath_Timer;
        uint32 TimeStop_Timer;
        uint32 Frenzy_Timer;
		uint32 Cleave_Timer;
		uint32 TailSweepTimer;
		uint32 MortalWound_Timer;
		uint32 Haste_Timer;
		uint32 RainFire_Timer;
		uint32 TimeLapse_Timer;
		uint32 DeathDecay_Timer;
		uint32 IceLance_Timer;
		

        void Reset()
        {
            SandBreath_Timer = 15000+rand()%13000;
            TimeStop_Timer = 10000+rand()%5000;
            Frenzy_Timer = 30000+rand()%15000;
			Cleave_Timer = 6500;
			TailSweepTimer = 4000;
			MortalWound_Timer = 7000;
			Haste_Timer = 15000+rand()%8000;
			RainFire_Timer = 9000+rand()%7000;
			TimeLapse_Timer = 70000;
			DeathDecay_Timer = 6000;
			IceLance_Timer = 12000+rand()%8000;
			DoCast(me, SPELL_FULLHEAL);
        }

        void EnterCombat(Unit* /*who*/)
        {
			Enraged = false;
            Talk(SAY_AGGRO);
			DoCast(me, SPELL_COMBAT);
        }

		void KilledUnit(Unit* victim)
        {
			if (victim->GetTypeId() != TYPEID_PLAYER)
                    return;

			DoCast(me, SPELL_CAPTURESOUL);
			DoCast(me, SPELL_CAPTURESOUL);
			DoCast(me, SPELL_CAPTURESOUL);
			DoCast(me, SPELL_CAPTURESOUL);
			DoCast(me, SPELL_CAPTURESOUL);
			Talk(RAND(SAY_SLAY1, SAY_SLAY2));
		}
		void JustDied(Unit* /*killer*/)
        {
            Talk(SAY_DEATH);
		}

        void UpdateAI(const uint32 diff)
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

			

             //Sand Breath
            if (SandBreath_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_SANDBREATH);
                SandBreath_Timer = 15000+rand()%10000;
            } else SandBreath_Timer -= diff;

            //Time Stop
            if (TimeStop_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_TIMESTOP);
                TimeStop_Timer = 20000+rand()%15000;
            } else TimeStop_Timer -= diff;

			  //Cleave
            if (Cleave_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_CLEAVE);
                Cleave_Timer = 6500;
            } else Cleave_Timer -= diff;

			if (TailSweepTimer <= diff)
                {
                    DoCastAOE(SPELL_TAIL_SWEEP);
                    TailSweepTimer = 4000;
            } else TailSweepTimer -= diff;

			//dogadedas Haste
            if (Haste_Timer <= diff)
            {
                DoCast(me, SPELL_HASTE);
                Haste_Timer = 20000+rand()%10000;
            } else Haste_Timer -= diff;

            //MortalWound_Timer
            if (MortalWound_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
                MortalWound_Timer = 7000;
            } else MortalWound_Timer -= diff;

			if (RainFire_Timer <= diff)
            {
				if (Enraged == true)
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_RAINFIRE);
					RainFire_Timer = 7000+rand()%5000;
            } else RainFire_Timer -= diff;

			if (DeathDecay_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_DEATHDECAY);
					DeathDecay_Timer = 6000;
            } else DeathDecay_Timer -= diff;

			if (IceLance_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, SPELL_ICELANCE);
					IceLance_Timer = 12000+rand()%8000;
            } else IceLance_Timer -= diff;

			if (TimeLapse_Timer <= diff)
            {
					if (Enraged == true)
                    DoCast(me, SPELL_TIMELAPSE);
					TimeLapse_Timer = 90000;
					Talk(SAY_BANISH);
            } else TimeLapse_Timer -= diff;

			if (!Enraged && HealthBelowPct(50))
            {
                DoCast(me->getVictim(), SPELL_TIMELAPSE, true);
				Talk(SAY_ENTER);
				Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_fafnir()
{
    new boss_fafnir();
}
