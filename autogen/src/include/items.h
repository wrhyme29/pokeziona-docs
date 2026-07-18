#ifndef GUARD_ITEMS_H
#define GUARD_ITEMS_H

#include "constants/items.h"
#include "constants/tms_hms.h"
#include "item_descriptions.h"

/* Expands to:
* enum_start ITEM_TM01
* enum ITEM_TM_FOCUS_PUNCH
* ...
* enum_start ITEM_HM01
* enum ITEM_HM_CUT
* ... */
#define EQUIV_TM(id) ITEM_TM_ ## id,
#define EQUIV_HM(id) ITEM_HM_ ## id,

enum {
FOREACH_TM(EQUIV_TM) FOREACH_HM(EQUIV_HM)
};
#undef EQUIV_TM
#undef EQUIV_HM

struct Item
{
    u8 name[ITEM_NAME_LENGTH];
    u16 itemId;
    u16 price;
    u8 holdEffectParam;
    const u8 *description;
    u8 importance;
    u8 type;
    u8 battleUsage;
    u8 secondaryId;
};

const struct Item gItems[] =
{
    [ITEM_NONE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Pokeballs

    [ITEM_MASTER_BALL] =
    {
        .name = _("MASTER BALL"),
        .itemId = ITEM_MASTER_BALL,
        .price = 0,
        .description = sMasterBallDesc,
        .type = ITEM_MASTER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_MASTER_BALL - FIRST_BALL,
    },

    [ITEM_ULTRA_BALL] =
    {
        .name = _("ULTRA BALL"),
        .itemId = ITEM_ULTRA_BALL,
        .price = 1200,
        .description = sUltraBallDesc,
        .type = ITEM_ULTRA_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_ULTRA_BALL - FIRST_BALL,
    },

    [ITEM_GREAT_BALL] =
    {
        .name = _("GREAT BALL"),
        .itemId = ITEM_GREAT_BALL,
        .price = 600,
        .description = sGreatBallDesc,
        .type = ITEM_GREAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_GREAT_BALL - FIRST_BALL,
    },

    [ITEM_POKE_BALL] =
    {
        .name = _("POKé BALL"),
        .itemId = ITEM_POKE_BALL,
        .price = 200,
        .description = sPokeBallDesc,
        .type = ITEM_POKE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_POKE_BALL - FIRST_BALL,
    },

    [ITEM_SAFARI_BALL] =
    {
        .name = _("SAFARI BALL"),
        .itemId = ITEM_SAFARI_BALL,
        .price = 0,
        .description = sSafariBallDesc,
        .type = ITEM_SAFARI_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_SAFARI_BALL - FIRST_BALL,
    },

    [ITEM_NET_BALL] =
    {
        .name = _("NET BALL"),
        .itemId = ITEM_NET_BALL,
        .price = 1000,
        .description = sNetBallDesc,
        .type = ITEM_NET_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_NET_BALL - FIRST_BALL,
    },

    [ITEM_DIVE_BALL] =
    {
        .name = _("DIVE BALL"),
        .itemId = ITEM_DIVE_BALL,
        .price = 1000,
        .description = sDiveBallDesc,
        .type = ITEM_DIVE_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_DIVE_BALL - FIRST_BALL,
    },

    [ITEM_NEST_BALL] =
    {
        .name = _("NEST BALL"),
        .itemId = ITEM_NEST_BALL,
        .price = 1000,
        .description = sNestBallDesc,
        .type = ITEM_NEST_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_NEST_BALL - FIRST_BALL,
    },

    [ITEM_REPEAT_BALL] =
    {
        .name = _("REPEAT BALL"),
        .itemId = ITEM_REPEAT_BALL,
        .price = 1000,
        .description = sRepeatBallDesc,
        .type = ITEM_REPEAT_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_REPEAT_BALL - FIRST_BALL,
    },

    [ITEM_TIMER_BALL] =
    {
        .name = _("TIMER BALL"),
        .itemId = ITEM_TIMER_BALL,
        .price = 1000,
        .description = sTimerBallDesc,
        .type = ITEM_TIMER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_TIMER_BALL - FIRST_BALL,
    },

    [ITEM_LUXURY_BALL] =
    {
        .name = _("LUXURY BALL"),
        .itemId = ITEM_LUXURY_BALL,
        .price = 1000,
        .description = sLuxuryBallDesc,
        .type = ITEM_LUXURY_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_LUXURY_BALL - FIRST_BALL,
    },

    [ITEM_PREMIER_BALL] =
    {
        .name = _("PREMIER BALL"),
        .itemId = ITEM_PREMIER_BALL,
        .price = 200,
        .description = sPremierBallDesc,
        .type = ITEM_PREMIER_BALL - FIRST_BALL,
        .battleUsage = ITEM_B_USE_OTHER,
        .secondaryId = ITEM_PREMIER_BALL - FIRST_BALL,
    },

// Medicine

    [ITEM_POTION] =
    {
        .name = _("POTION"),
        .itemId = ITEM_POTION,
        .price = 300,
        .holdEffectParam = 20,
        .description = sPotionDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ANTIDOTE] =
    {
        .name = _("ANTIDOTE"),
        .itemId = ITEM_ANTIDOTE,
        .price = 100,
        .description = sAntidoteDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_BURN_HEAL] =
    {
        .name = _("BURN HEAL"),
        .itemId = ITEM_BURN_HEAL,
        .price = 250,
        .description = sBurnHealDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ICE_HEAL] =
    {
        .name = _("ICE HEAL"),
        .itemId = ITEM_ICE_HEAL,
        .price = 250,
        .description = sIceHealDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_AWAKENING] =
    {
        .name = _("AWAKENING"),
        .itemId = ITEM_AWAKENING,
        .price = 250,
        .description = sAwakeningDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_PARALYZE_HEAL] =
    {
        .name = _("PARLYZ HEAL"),
        .itemId = ITEM_PARALYZE_HEAL,
        .price = 200,
        .description = sParalyzeHealDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_FULL_RESTORE] =
    {
        .name = _("FULL RESTORE"),
        .itemId = ITEM_FULL_RESTORE,
        .price = 3000,
        .holdEffectParam = 255,
        .description = sFullRestoreDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_MAX_POTION] =
    {
        .name = _("MAX POTION"),
        .itemId = ITEM_MAX_POTION,
        .price = 2500,
        .holdEffectParam = 255,
        .description = sMaxPotionDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_HYPER_POTION] =
    {
        .name = _("HYPER POTION"),
        .itemId = ITEM_HYPER_POTION,
        .price = 1200,
        .holdEffectParam = 200,
        .description = sHyperPotionDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_SUPER_POTION] =
    {
        .name = _("SUPER POTION"),
        .itemId = ITEM_SUPER_POTION,
        .price = 700,
        .holdEffectParam = 50,
        .description = sSuperPotionDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_FULL_HEAL] =
    {
        .name = _("FULL HEAL"),
        .itemId = ITEM_FULL_HEAL,
        .price = 600,
        .description = sFullHealDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_REVIVE] =
    {
        .name = _("REVIVE"),
        .itemId = ITEM_REVIVE,
        .price = 1500,
        .description = sReviveDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_MAX_REVIVE] =
    {
        .name = _("MAX REVIVE"),
        .itemId = ITEM_MAX_REVIVE,
        .price = 4000,
        .description = sMaxReviveDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_FRESH_WATER] =
    {
        .name = _("FRESH WATER"),
        .itemId = ITEM_FRESH_WATER,
        .price = 200,
        .holdEffectParam = 50,
        .description = sFreshWaterDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_SODA_POP] =
    {
        .name = _("SODA POP"),
        .itemId = ITEM_SODA_POP,
        .price = 300,
        .holdEffectParam = 60,
        .description = sSodaPopDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_LEMONADE] =
    {
        .name = _("LEMONADE"),
        .itemId = ITEM_LEMONADE,
        .price = 350,
        .holdEffectParam = 80,
        .description = sLemonadeDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_MOOMOO_MILK] =
    {
        .name = _("MOOMOO MILK"),
        .itemId = ITEM_MOOMOO_MILK,
        .price = 500,
        .holdEffectParam = 100,
        .description = sMoomooMilkDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ENERGY_POWDER] =
    {
        .name = _("ENERGYPOWDER"),
        .itemId = ITEM_ENERGY_POWDER,
        .price = 500,
        .description = sEnergyPowderDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ENERGY_ROOT] =
    {
        .name = _("ENERGY ROOT"),
        .itemId = ITEM_ENERGY_ROOT,
        .price = 800,
        .description = sEnergyRootDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_HEAL_POWDER] =
    {
        .name = _("HEAL POWDER"),
        .itemId = ITEM_HEAL_POWDER,
        .price = 450,
        .description = sHealPowderDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_REVIVAL_HERB] =
    {
        .name = _("REVIVAL HERB"),
        .itemId = ITEM_REVIVAL_HERB,
        .price = 2800,
        .description = sRevivalHerbDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ETHER] =
    {
        .name = _("ETHER"),
        .itemId = ITEM_ETHER,
        .price = 1200,
        .holdEffectParam = 10,
        .description = sEtherDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_MAX_ETHER] =
    {
        .name = _("MAX ETHER"),
        .itemId = ITEM_MAX_ETHER,
        .price = 2000,
        .holdEffectParam = 255,
        .description = sMaxEtherDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ELIXIR] =
    {
        .name = _("ELIXIR"),
        .itemId = ITEM_ELIXIR,
        .price = 3000,
        .holdEffectParam = 10,
        .description = sElixirDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_MAX_ELIXIR] =
    {
        .name = _("MAX ELIXIR"),
        .itemId = ITEM_MAX_ELIXIR,
        .price = 4500,
        .holdEffectParam = 255,
        .description = sMaxElixirDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_LAVA_COOKIE] =
    {
        .name = _("LAVA COOKIE"),
        .itemId = ITEM_LAVA_COOKIE,
        .price = 200,
        .description = sLavaCookieDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_BLUE_FLUTE] =
    {
        .name = _("BLUE FLUTE"),
        .itemId = ITEM_BLUE_FLUTE,
        .price = 100,
        .description = sBlueFluteDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_YELLOW_FLUTE] =
    {
        .name = _("YELLOW FLUTE"),
        .itemId = ITEM_YELLOW_FLUTE,
        .price = 200,
        .description = sYellowFluteDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_RED_FLUTE] =
    {
        .name = _("RED FLUTE"),
        .itemId = ITEM_RED_FLUTE,
        .price = 300,
        .description = sRedFluteDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_BLACK_FLUTE] =
    {
        .name = _("BLACK FLUTE"),
        .itemId = ITEM_BLACK_FLUTE,
        .price = 400,
        .holdEffectParam = 50,
        .description = sBlackFluteDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_WHITE_FLUTE] =
    {
        .name = _("WHITE FLUTE"),
        .itemId = ITEM_WHITE_FLUTE,
        .price = 500,
        .holdEffectParam = 150,
        .description = sWhiteFluteDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_BERRY_JUICE] =
    {
        .name = _("BERRY JUICE"),
        .itemId = ITEM_BERRY_JUICE,
        .price = 100,
        .holdEffectParam = 20,
        .description = sBerryJuiceDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_SACRED_ASH] =
    {
        .name = _("SACRED ASH"),
        .itemId = ITEM_SACRED_ASH,
        .price = 200,
        .description = sSacredAshDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

// Collectibles

    [ITEM_SHOAL_SALT] =
    {
        .name = _("SHOAL SALT"),
        .itemId = ITEM_SHOAL_SALT,
        .price = 20,
        .description = sShoalSaltDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SHOAL_SHELL] =
    {
        .name = _("SHOAL SHELL"),
        .itemId = ITEM_SHOAL_SHELL,
        .price = 20,
        .description = sShoalShellDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RED_SHARD] =
    {
        .name = _("RED SHARD"),
        .itemId = ITEM_RED_SHARD,
        .price = 200,
        .description = sRedShardDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLUE_SHARD] =
    {
        .name = _("BLUE SHARD"),
        .itemId = ITEM_BLUE_SHARD,
        .price = 200,
        .description = sBlueShardDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_YELLOW_SHARD] =
    {
        .name = _("YELLOW SHARD"),
        .itemId = ITEM_YELLOW_SHARD,
        .price = 200,
        .description = sYellowShardDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_GREEN_SHARD] =
    {
        .name = _("GREEN SHARD"),
        .itemId = ITEM_GREEN_SHARD,
        .price = 200,
        .description = sGreenShardDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_034] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_035] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_036] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_037] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_038] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_039] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_03A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_03B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_03C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_03D] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_03E] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Vitamins

    [ITEM_HP_UP] =
    {
        .name = _("HP UP"),
        .itemId = ITEM_HP_UP,
        .price = 9800,
        .description = sHPUpDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_PROTEIN] =
    {
        .name = _("PROTEIN"),
        .itemId = ITEM_PROTEIN,
        .price = 9800,
        .description = sProteinDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_IRON] =
    {
        .name = _("IRON"),
        .itemId = ITEM_IRON,
        .price = 9800,
        .description = sIronDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_CARBOS] =
    {
        .name = _("CARBOS"),
        .itemId = ITEM_CARBOS,
        .price = 9800,
        .description = sCarbosDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_CALCIUM] =
    {
        .name = _("CALCIUM"),
        .itemId = ITEM_CALCIUM,
        .price = 9800,
        .description = sCalciumDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_RARE_CANDY] =
    {
        .name = _("RARE CANDY"),
        .itemId = ITEM_RARE_CANDY,
        .price = 4800,
        .description = sRareCandyDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_PP_UP] =
    {
        .name = _("PP UP"),
        .itemId = ITEM_PP_UP,
        .price = 9800,
        .description = sPPUpDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_ZINC] =
    {
        .name = _("ZINC"),
        .itemId = ITEM_ZINC,
        .price = 9800,
        .description = sZincDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_PP_MAX] =
    {
        .name = _("PP MAX"),
        .itemId = ITEM_PP_MAX,
        .price = 9800,
        .description = sPPMaxDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_048] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Battle items

    [ITEM_GUARD_SPEC] =
    {
        .name = _("GUARD SPEC."),
        .itemId = ITEM_GUARD_SPEC,
        .price = 700,
        .description = sGuardSpecDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_DIRE_HIT] =
    {
        .name = _("DIRE HIT"),
        .itemId = ITEM_DIRE_HIT,
        .price = 650,
        .description = sDireHitDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_X_ATTACK] =
    {
        .name = _("X ATTACK"),
        .itemId = ITEM_X_ATTACK,
        .price = 500,
        .description = sXAttackDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_X_DEFEND] =
    {
        .name = _("X DEFEND"),
        .itemId = ITEM_X_DEFEND,
        .price = 550,
        .description = sXDefendDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_X_SPEED] =
    {
        .name = _("X SPEED"),
        .itemId = ITEM_X_SPEED,
        .price = 350,
        .description = sXSpeedDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_X_ACCURACY] =
    {
        .name = _("X ACCURACY"),
        .itemId = ITEM_X_ACCURACY,
        .price = 950,
        .description = sXAccuracyDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_X_SPECIAL] =
    {
        .name = _("X SPECIAL"),
        .itemId = ITEM_X_SPECIAL,
        .price = 350,
        .description = sXSpecialDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_POKE_DOLL] =
    {
        .name = _("POKé DOLL"),
        .itemId = ITEM_POKE_DOLL,
        .price = 1000,
        .description = sPokeDollDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_FLUFFY_TAIL] =
    {
        .name = _("FLUFFY TAIL"),
        .itemId = ITEM_FLUFFY_TAIL,
        .price = 1000,
        .description = sFluffyTailDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_OTHER,
    },

    [ITEM_052] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Field items

    [ITEM_SUPER_REPEL] =
    {
        .name = _("SUPER REPEL"),
        .itemId = ITEM_SUPER_REPEL,
        .price = 500,
        .holdEffectParam = 200,
        .description = sSuperRepelDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MAX_REPEL] =
    {
        .name = _("MAX REPEL"),
        .itemId = ITEM_MAX_REPEL,
        .price = 700,
        .holdEffectParam = 250,
        .description = sMaxRepelDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ESCAPE_ROPE] =
    {
        .name = _("ESCAPE ROPE"),
        .itemId = ITEM_ESCAPE_ROPE,
        .price = 550,
        .description = sEscapeRopeDesc,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_REPEL] =
    {
        .name = _("REPEL"),
        .itemId = ITEM_REPEL,
        .price = 350,
        .holdEffectParam = 100,
        .description = sRepelDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_057] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_058] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_059] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_05A] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_05B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_05C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Evolution stones

    [ITEM_SUN_STONE] =
    {
        .name = _("SUN STONE"),
        .itemId = ITEM_SUN_STONE,
        .price = 2100,
        .description = sSunStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_MOON_STONE] =
    {
        .name = _("MOON STONE"),
        .itemId = ITEM_MOON_STONE,
        .price = 0,
        .description = sMoonStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_FIRE_STONE] =
    {
        .name = _("FIRE STONE"),
        .itemId = ITEM_FIRE_STONE,
        .price = 2100,
        .description = sFireStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_THUNDER_STONE] =
    {
        .name = _("THUNDERSTONE"),
        .itemId = ITEM_THUNDER_STONE,
        .price = 2100,
        .description = sThunderStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_WATER_STONE] =
    {
        .name = _("WATER STONE"),
        .itemId = ITEM_WATER_STONE,
        .price = 2100,
        .description = sWaterStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_LEAF_STONE] =
    {
        .name = _("LEAF STONE"),
        .itemId = ITEM_LEAF_STONE,
        .price = 2100,
        .description = sLeafStoneDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_063] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_064] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_065] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_066] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Valuable items

    [ITEM_TINY_MUSHROOM] =
    {
        .name = _("TINYMUSHROOM"),
        .itemId = ITEM_TINY_MUSHROOM,
        .price = 500,
        .description = sTinyMushroomDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BIG_MUSHROOM] =
    {
        .name = _("BIG MUSHROOM"),
        .itemId = ITEM_BIG_MUSHROOM,
        .price = 5000,
        .description = sBigMushroomDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_069] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_PEARL] =
    {
        .name = _("PEARL"),
        .itemId = ITEM_PEARL,
        .price = 1400,
        .description = sPearlDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BIG_PEARL] =
    {
        .name = _("BIG PEARL"),
        .itemId = ITEM_BIG_PEARL,
        .price = 7500,
        .description = sBigPearlDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_STARDUST] =
    {
        .name = _("STARDUST"),
        .itemId = ITEM_STARDUST,
        .price = 2000,
        .description = sStardustDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_STAR_PIECE] =
    {
        .name = _("STAR PIECE"),
        .itemId = ITEM_STAR_PIECE,
        .price = 9800,
        .description = sStarPieceDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_NUGGET] =
    {
        .name = _("NUGGET"),
        .itemId = ITEM_NUGGET,
        .price = 10000,
        .description = sNuggetDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_HEART_SCALE] =
    {
        .name = _("HEART SCALE"),
        .itemId = ITEM_HEART_SCALE,
        .price = 100,
        .description = sHeartScaleDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_070] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_071] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_072] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_073] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_074] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_075] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_076] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_077] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_078] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Mail
    [ITEM_ORANGE_MAIL] =
    {
        .name = _("ORANGE MAIL"),
        .itemId = ITEM_ORANGE_MAIL,
        .price = 50,
        .description = sOrangeMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_ORANGE_MAIL),
    },

    [ITEM_HARBOR_MAIL] =
    {
        .name = _("HARBOR MAIL"),
        .itemId = ITEM_HARBOR_MAIL,
        .price = 50,
        .description = sHarborMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_HARBOR_MAIL),
    },

    [ITEM_GLITTER_MAIL] =
    {
        .name = _("GLITTER MAIL"),
        .itemId = ITEM_GLITTER_MAIL,
        .price = 50,
        .description = sGlitterMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_GLITTER_MAIL),
    },

    [ITEM_MECH_MAIL] =
    {
        .name = _("MECH MAIL"),
        .itemId = ITEM_MECH_MAIL,
        .price = 50,
        .description = sMechMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_MECH_MAIL),
    },

    [ITEM_WOOD_MAIL] =
    {
        .name = _("WOOD MAIL"),
        .itemId = ITEM_WOOD_MAIL,
        .price = 50,
        .description = sWoodMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_WOOD_MAIL),
    },

    [ITEM_WAVE_MAIL] =
    {
        .name = _("WAVE MAIL"),
        .itemId = ITEM_WAVE_MAIL,
        .price = 50,
        .description = sWaveMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_WAVE_MAIL),
    },

    [ITEM_BEAD_MAIL] =
    {
        .name = _("BEAD MAIL"),
        .itemId = ITEM_BEAD_MAIL,
        .price = 50,
        .description = sBeadMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_BEAD_MAIL),
    },

    [ITEM_SHADOW_MAIL] =
    {
        .name = _("SHADOW MAIL"),
        .itemId = ITEM_SHADOW_MAIL,
        .price = 50,
        .description = sShadowMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_SHADOW_MAIL),
    },

    [ITEM_TROPIC_MAIL] =
    {
        .name = _("TROPIC MAIL"),
        .itemId = ITEM_TROPIC_MAIL,
        .price = 50,
        .description = sTropicMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_TROPIC_MAIL),
    },

    [ITEM_DREAM_MAIL] =
    {
        .name = _("DREAM MAIL"),
        .itemId = ITEM_DREAM_MAIL,
        .price = 50,
        .description = sDreamMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_DREAM_MAIL),
    },

    [ITEM_FAB_MAIL] =
    {
        .name = _("FAB MAIL"),
        .itemId = ITEM_FAB_MAIL,
        .price = 50,
        .description = sFabMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_FAB_MAIL),
    },

    [ITEM_RETRO_MAIL] =
    {
        .name = _("RETRO MAIL"),
        .itemId = ITEM_RETRO_MAIL,
        .price = 0,
        .description = sRetroMailDesc,
        .type = ITEM_USE_MAIL,
        .secondaryId = ITEM_TO_MAIL(ITEM_RETRO_MAIL),
    },

// Berries

    [ITEM_CHERI_BERRY] =
    {
        .name = _("CHERI BERRY"),
        .itemId = ITEM_CHERI_BERRY,
        .price = 20,
        .description = sCheriBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_CHESTO_BERRY] =
    {
        .name = _("CHESTO BERRY"),
        .itemId = ITEM_CHESTO_BERRY,
        .price = 20,
        .description = sChestoBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_PECHA_BERRY] =
    {
        .name = _("PECHA BERRY"),
        .itemId = ITEM_PECHA_BERRY,
        .price = 20,
        .description = sPechaBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_RAWST_BERRY] =
    {
        .name = _("RAWST BERRY"),
        .itemId = ITEM_RAWST_BERRY,
        .price = 20,
        .description = sRawstBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ASPEAR_BERRY] =
    {
        .name = _("ASPEAR BERRY"),
        .itemId = ITEM_ASPEAR_BERRY,
        .price = 20,
        .description = sAspearBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_LEPPA_BERRY] =
    {
        .name = _("LEPPA BERRY"),
        .itemId = ITEM_LEPPA_BERRY,
        .price = 20,
        .holdEffectParam = 10,
        .description = sLeppaBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_ORAN_BERRY] =
    {
        .name = _("ORAN BERRY"),
        .itemId = ITEM_ORAN_BERRY,
        .price = 20,
        .holdEffectParam = 10,
        .description = sOranBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_PERSIM_BERRY] =
    {
        .name = _("PERSIM BERRY"),
        .itemId = ITEM_PERSIM_BERRY,
        .price = 20,
        .description = sPersimBerryDesc,
        .type = ITEM_USE_BAG_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_LUM_BERRY] =
    {
        .name = _("LUM BERRY"),
        .itemId = ITEM_LUM_BERRY,
        .price = 20,
        .description = sLumBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_SITRUS_BERRY] =
    {
        .name = _("SITRUS BERRY"),
        .itemId = ITEM_SITRUS_BERRY,
        .price = 20,
        .holdEffectParam = 30,
        .description = sSitrusBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_FIGY_BERRY] =
    {
        .name = _("FIGY BERRY"),
        .itemId = ITEM_FIGY_BERRY,
        .price = 20,
        .holdEffectParam = 8,
        .description = sFigyBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_WIKI_BERRY] =
    {
        .name = _("WIKI BERRY"),
        .itemId = ITEM_WIKI_BERRY,
        .price = 20,
        .holdEffectParam = 8,
        .description = sWikiBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MAGO_BERRY] =
    {
        .name = _("MAGO BERRY"),
        .itemId = ITEM_MAGO_BERRY,
        .price = 20,
        .holdEffectParam = 8,
        .description = sMagoBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_AGUAV_BERRY] =
    {
        .name = _("AGUAV BERRY"),
        .itemId = ITEM_AGUAV_BERRY,
        .price = 20,
        .holdEffectParam = 8,
        .description = sAguavBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_IAPAPA_BERRY] =
    {
        .name = _("IAPAPA BERRY"),
        .itemId = ITEM_IAPAPA_BERRY,
        .price = 20,
        .holdEffectParam = 8,
        .description = sIapapaBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RAZZ_BERRY] =
    {
        .name = _("RAZZ BERRY"),
        .itemId = ITEM_RAZZ_BERRY,
        .price = 20,
        .description = sRazzBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLUK_BERRY] =
    {
        .name = _("BLUK BERRY"),
        .itemId = ITEM_BLUK_BERRY,
        .price = 20,
        .description = sBlukBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_NANAB_BERRY] =
    {
        .name = _("NANAB BERRY"),
        .itemId = ITEM_NANAB_BERRY,
        .price = 20,
        .description = sNanabBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_WEPEAR_BERRY] =
    {
        .name = _("WEPEAR BERRY"),
        .itemId = ITEM_WEPEAR_BERRY,
        .price = 20,
        .description = sWepearBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_PINAP_BERRY] =
    {
        .name = _("PINAP BERRY"),
        .itemId = ITEM_PINAP_BERRY,
        .price = 20,
        .description = sPinapBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_POMEG_BERRY] =
    {
        .name = _("POMEG BERRY"),
        .itemId = ITEM_POMEG_BERRY,
        .price = 20,
        .description = sPomegBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_KELPSY_BERRY] =
    {
        .name = _("KELPSY BERRY"),
        .itemId = ITEM_KELPSY_BERRY,
        .price = 20,
        .description = sKelpsyBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_QUALOT_BERRY] =
    {
        .name = _("QUALOT BERRY"),
        .itemId = ITEM_QUALOT_BERRY,
        .price = 20,
        .description = sQualotBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HONDEW_BERRY] =
    {
        .name = _("HONDEW BERRY"),
        .itemId = ITEM_HONDEW_BERRY,
        .price = 20,
        .description = sHondewBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_GREPA_BERRY] =
    {
        .name = _("GREPA BERRY"),
        .itemId = ITEM_GREPA_BERRY,
        .price = 20,
        .description = sGrepaBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TAMATO_BERRY] =
    {
        .name = _("TAMATO BERRY"),
        .itemId = ITEM_TAMATO_BERRY,
        .price = 20,
        .description = sTamatoBerryDesc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_CORNN_BERRY] =
    {
        .name = _("CORNN BERRY"),
        .itemId = ITEM_CORNN_BERRY,
        .price = 20,
        .description = sCornnBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MAGOST_BERRY] =
    {
        .name = _("MAGOST BERRY"),
        .itemId = ITEM_MAGOST_BERRY,
        .price = 20,
        .description = sMagostBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RABUTA_BERRY] =
    {
        .name = _("RABUTA BERRY"),
        .itemId = ITEM_RABUTA_BERRY,
        .price = 20,
        .description = sRabutaBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_NOMEL_BERRY] =
    {
        .name = _("NOMEL BERRY"),
        .itemId = ITEM_NOMEL_BERRY,
        .price = 20,
        .description = sNomelBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SPELON_BERRY] =
    {
        .name = _("SPELON BERRY"),
        .itemId = ITEM_SPELON_BERRY,
        .price = 20,
        .description = sSpelonBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_PAMTRE_BERRY] =
    {
        .name = _("PAMTRE BERRY"),
        .itemId = ITEM_PAMTRE_BERRY,
        .price = 20,
        .description = sPamtreBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_WATMEL_BERRY] =
    {
        .name = _("WATMEL BERRY"),
        .itemId = ITEM_WATMEL_BERRY,
        .price = 20,
        .description = sWatmelBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DURIN_BERRY] =
    {
        .name = _("DURIN BERRY"),
        .itemId = ITEM_DURIN_BERRY,
        .price = 20,
        .description = sDurinBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BELUE_BERRY] =
    {
        .name = _("BELUE BERRY"),
        .itemId = ITEM_BELUE_BERRY,
        .price = 20,
        .description = sBelueBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LIECHI_BERRY] =
    {
        .name = _("LIECHI BERRY"),
        .itemId = ITEM_LIECHI_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sLiechiBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_GANLON_BERRY] =
    {
        .name = _("GANLON BERRY"),
        .itemId = ITEM_GANLON_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sGanlonBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SALAC_BERRY] =
    {
        .name = _("SALAC BERRY"),
        .itemId = ITEM_SALAC_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sSalacBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_PETAYA_BERRY] =
    {
        .name = _("PETAYA BERRY"),
        .itemId = ITEM_PETAYA_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sPetayaBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_APICOT_BERRY] =
    {
        .name = _("APICOT BERRY"),
        .itemId = ITEM_APICOT_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sApicotBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LANSAT_BERRY] =
    {
        .name = _("LANSAT BERRY"),
        .itemId = ITEM_LANSAT_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sLansatBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_STARF_BERRY] =
    {
        .name = _("STARF BERRY"),
        .itemId = ITEM_STARF_BERRY,
        .price = 20,
        .holdEffectParam = 4,
        .description = sStarfBerryDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ENIGMA_BERRY] =
    {
        .name = _("ENIGMA BERRY"),
        .itemId = ITEM_ENIGMA_BERRY,
        .price = 20,
        .description = sEnigmaBerryDesc,
        .type = ITEM_USE_BAG_MENU, // Type handled by ItemUseOutOfBattle_EnigmaBerry
        .battleUsage = ITEM_B_USE_MEDICINE,
    },

    [ITEM_UNUSED_BERRY_1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_UNUSED_BERRY_2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_UNUSED_BERRY_3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Hold items

    [ITEM_BRIGHT_POWDER] =
    {
        .name = _("BRIGHTPOWDER"),
        .itemId = ITEM_BRIGHT_POWDER,
        .price = 10,
        .holdEffectParam = 10,
        .description = sBrightPowderDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_WHITE_HERB] =
    {
        .name = _("WHITE HERB"),
        .itemId = ITEM_WHITE_HERB,
        .price = 100,
        .description = sWhiteHerbDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MACHO_BRACE] =
    {
        .name = _("MACHO BRACE"),
        .itemId = ITEM_MACHO_BRACE,
        .price = 3000,
        .description = sMachoBraceDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_EXP_SHARE] =
    {
        .name = _("EXP. SHARE"),
        .itemId = ITEM_EXP_SHARE,
        .price = 3000,
        .description = sExpShareDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_QUICK_CLAW] =
    {
        .name = _("QUICK CLAW"),
        .itemId = ITEM_QUICK_CLAW,
        .price = 100,
        .holdEffectParam = 20,
        .description = sQuickClawDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SOOTHE_BELL] =
    {
        .name = _("SOOTHE BELL"),
        .itemId = ITEM_SOOTHE_BELL,
        .price = 100,
        .description = sSootheBellDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MENTAL_HERB] =
    {
        .name = _("MENTAL HERB"),
        .itemId = ITEM_MENTAL_HERB,
        .price = 100,
        .description = sMentalHerbDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CHOICE_BAND] =
    {
        .name = _("CHOICE BAND"),
        .itemId = ITEM_CHOICE_BAND,
        .price = 100,
        .description = sChoiceBandDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_KINGS_ROCK] =
    {
        .name = _("KING'S ROCK"),
        .itemId = ITEM_KINGS_ROCK,
        .price = 100,
        .holdEffectParam = 10,
        .description = sKingsRockDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SILVER_POWDER] =
    {
        .name = _("SILVERPOWDER"),
        .itemId = ITEM_SILVER_POWDER,
        .price = 100,
        .holdEffectParam = 10,
        .description = sSilverPowderDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_AMULET_COIN] =
    {
        .name = _("AMULET COIN"),
        .itemId = ITEM_AMULET_COIN,
        .price = 100,
        .holdEffectParam = 10,
        .description = sAmuletCoinDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CLEANSE_TAG] =
    {
        .name = _("CLEANSE TAG"),
        .itemId = ITEM_CLEANSE_TAG,
        .price = 200,
        .description = sCleanseTagDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SOUL_DEW] =
    {
        .name = _("SOUL DEW"),
        .itemId = ITEM_SOUL_DEW,
        .price = 200,
        .description = sSoulDewDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DEEP_SEA_TOOTH] =
    {
        .name = _("DEEPSEATOOTH"),
        .itemId = ITEM_DEEP_SEA_TOOTH,
        .price = 200,
        .description = sDeepSeaToothDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DEEP_SEA_SCALE] =
    {
        .name = _("DEEPSEASCALE"),
        .itemId = ITEM_DEEP_SEA_SCALE,
        .price = 200,
        .description = sDeepSeaScaleDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SMOKE_BALL] =
    {
        .name = _("SMOKE BALL"),
        .itemId = ITEM_SMOKE_BALL,
        .price = 200,
        .description = sSmokeBallDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_EVERSTONE] =
    {
        .name = _("EVERSTONE"),
        .itemId = ITEM_EVERSTONE,
        .price = 200,
        .description = sEverstoneDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_FOCUS_BAND] =
    {
        .name = _("FOCUS BAND"),
        .itemId = ITEM_FOCUS_BAND,
        .price = 200,
        .holdEffectParam = 10,
        .description = sFocusBandDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LUCKY_EGG] =
    {
        .name = _("LUCKY EGG"),
        .itemId = ITEM_LUCKY_EGG,
        .price = 200,
        .description = sLuckyEggDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SCOPE_LENS] =
    {
        .name = _("SCOPE LENS"),
        .itemId = ITEM_SCOPE_LENS,
        .price = 200,
        .description = sScopeLensDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_METAL_COAT] =
    {
        .name = _("METAL COAT"),
        .itemId = ITEM_METAL_COAT,
        .price = 100,
        .holdEffectParam = 10,
        .description = sMetalCoatDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LEFTOVERS] =
    {
        .name = _("LEFTOVERS"),
        .itemId = ITEM_LEFTOVERS,
        .price = 200,
        .holdEffectParam = 10,
        .description = sLeftoversDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DRAGON_SCALE] =
    {
        .name = _("DRAGON SCALE"),
        .itemId = ITEM_DRAGON_SCALE,
        .price = 2100,
        .holdEffectParam = 10,
        .description = sDragonScaleDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LIGHT_BALL] =
    {
        .name = _("LIGHT BALL"),
        .itemId = ITEM_LIGHT_BALL,
        .price = 100,
        .description = sLightBallDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SOFT_SAND] =
    {
        .name = _("SOFT SAND"),
        .itemId = ITEM_SOFT_SAND,
        .price = 100,
        .holdEffectParam = 10,
        .description = sSoftSandDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_HARD_STONE] =
    {
        .name = _("HARD STONE"),
        .itemId = ITEM_HARD_STONE,
        .price = 100,
        .holdEffectParam = 10,
        .description = sHardStoneDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MIRACLE_SEED] =
    {
        .name = _("MIRACLE SEED"),
        .itemId = ITEM_MIRACLE_SEED,
        .price = 100,
        .holdEffectParam = 10,
        .description = sMiracleSeedDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLACK_GLASSES] =
    {
        .name = _("BLACKGLASSES"),
        .itemId = ITEM_BLACK_GLASSES,
        .price = 100,
        .holdEffectParam = 10,
        .description = sBlackGlassesDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLACK_BELT] =
    {
        .name = _("BLACK BELT"),
        .itemId = ITEM_BLACK_BELT,
        .price = 100,
        .holdEffectParam = 10,
        .description = sBlackBeltDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MAGNET] =
    {
        .name = _("MAGNET"),
        .itemId = ITEM_MAGNET,
        .price = 100,
        .holdEffectParam = 10,
        .description = sMagnetDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MYSTIC_WATER] =
    {
        .name = _("MYSTIC WATER"),
        .itemId = ITEM_MYSTIC_WATER,
        .price = 100,
        .holdEffectParam = 10,
        .description = sMysticWaterDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SHARP_BEAK] =
    {
        .name = _("SHARP BEAK"),
        .itemId = ITEM_SHARP_BEAK,
        .price = 100,
        .holdEffectParam = 10,
        .description = sSharpBeakDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_POISON_BARB] =
    {
        .name = _("POISON BARB"),
        .itemId = ITEM_POISON_BARB,
        .price = 100,
        .holdEffectParam = 10,
        .description = sPoisonBarbDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_NEVER_MELT_ICE] =
    {
        .name = _("NEVERMELTICE"),
        .itemId = ITEM_NEVER_MELT_ICE,
        .price = 100,
        .holdEffectParam = 10,
        .description = sNeverMeltIceDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SPELL_TAG] =
    {
        .name = _("SPELL TAG"),
        .itemId = ITEM_SPELL_TAG,
        .price = 100,
        .holdEffectParam = 10,
        .description = sSpellTagDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_TWISTED_SPOON] =
    {
        .name = _("TWISTEDSPOON"),
        .itemId = ITEM_TWISTED_SPOON,
        .price = 100,
        .holdEffectParam = 10,
        .description = sTwistedSpoonDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CHARCOAL] =
    {
        .name = _("CHARCOAL"),
        .itemId = ITEM_CHARCOAL,
        .price = 9800,
        .holdEffectParam = 10,
        .description = sCharcoalDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DRAGON_FANG] =
    {
        .name = _("DRAGON FANG"),
        .itemId = ITEM_DRAGON_FANG,
        .price = 100,
        .holdEffectParam = 10,
        .description = sDragonFangDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SILK_SCARF] =
    {
        .name = _("SILK SCARF"),
        .itemId = ITEM_SILK_SCARF,
        .price = 100,
        .holdEffectParam = 10,
        .description = sSilkScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_UP_GRADE] =
    {
        .name = _("UP-GRADE"),
        .itemId = ITEM_UP_GRADE,
        .price = 2100,
        .description = sUpGradeDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SHELL_BELL] =
    {
        .name = _("SHELL BELL"),
        .itemId = ITEM_SHELL_BELL,
        .price = 200,
        .holdEffectParam = 8,
        .description = sShellBellDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SEA_INCENSE] =
    {
        .name = _("SEA INCENSE"),
        .itemId = ITEM_SEA_INCENSE,
        .price = 9600,
        .holdEffectParam = 5,
        .description = sSeaIncenseDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LAX_INCENSE] =
    {
        .name = _("LAX INCENSE"),
        .itemId = ITEM_LAX_INCENSE,
        .price = 9600,
        .holdEffectParam = 5,
        .description = sLaxIncenseDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LUCKY_PUNCH] =
    {
        .name = _("LUCKY PUNCH"),
        .itemId = ITEM_LUCKY_PUNCH,
        .price = 10,
        .description = sLuckyPunchDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_METAL_POWDER] =
    {
        .name = _("METAL POWDER"),
        .itemId = ITEM_METAL_POWDER,
        .price = 10,
        .description = sMetalPowderDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_THICK_CLUB] =
    {
        .name = _("THICK CLUB"),
        .itemId = ITEM_THICK_CLUB,
        .price = 500,
        .description = sThickClubDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_STICK] =
    {
        .name = _("STICK"),
        .itemId = ITEM_STICK,
        .price = 200,
        .description = sStickDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0E9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0EA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0EB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0EC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0ED] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0EE] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0EF] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F0] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F1] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F2] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F3] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F4] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F5] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F6] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F7] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F8] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0F9] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0FA] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0FB] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0FC] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_0FD] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RED_SCARF] =
    {
        .name = _("RED SCARF"),
        .itemId = ITEM_RED_SCARF,
        .price = 100,
        .description = sRedScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLUE_SCARF] =
    {
        .name = _("BLUE SCARF"),
        .itemId = ITEM_BLUE_SCARF,
        .price = 100,
        .description = sBlueScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_PINK_SCARF] =
    {
        .name = _("PINK SCARF"),
        .itemId = ITEM_PINK_SCARF,
        .price = 100,
        .description = sPinkScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_GREEN_SCARF] =
    {
        .name = _("GREEN SCARF"),
        .itemId = ITEM_GREEN_SCARF,
        .price = 100,
        .description = sGreenScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_YELLOW_SCARF] =
    {
        .name = _("YELLOW SCARF"),
        .itemId = ITEM_YELLOW_SCARF,
        .price = 100,
        .description = sYellowScarfDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// Key items

    [ITEM_MACH_BIKE] =
    {
        .name = _("MACH BIKE"),
        .itemId = ITEM_MACH_BIKE,
        .price = 0,
        .description = sMachBikeDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
        .secondaryId = MACH_BIKE,
    },

    [ITEM_COIN_CASE] =
    {
        .name = _("COIN CASE"),
        .itemId = ITEM_COIN_CASE,
        .price = 0,
        .description = sCoinCaseDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ITEMFINDER] =
    {
        .name = _("ITEMFINDER"),
        .itemId = ITEM_ITEMFINDER,
        .price = 0,
        .description = sItemfinderDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_OLD_ROD] =
    {
        .name = _("OLD ROD"),
        .itemId = ITEM_OLD_ROD,
        .price = 0,
        .description = sOldRodDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
        .secondaryId = OLD_ROD,
    },

    [ITEM_GOOD_ROD] =
    {
        .name = _("GOOD ROD"),
        .itemId = ITEM_GOOD_ROD,
        .price = 0,
        .description = sGoodRodDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
        .secondaryId = GOOD_ROD,
    },

    [ITEM_SUPER_ROD] =
    {
        .name = _("SUPER ROD"),
        .itemId = ITEM_SUPER_ROD,
        .price = 0,
        .description = sSuperRodDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
        .secondaryId = SUPER_ROD,
    },

    [ITEM_SS_TICKET] =
    {
        .name = _("S.S. TICKET"),
        .itemId = ITEM_SS_TICKET,
        .price = 0,
        .description = sSSTicketDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CONTEST_PASS] =
    {
        .name = _("CONTEST PASS"),
        .itemId = ITEM_CONTEST_PASS,
        .price = 0,
        .description = sContestPassDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_10B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_WAILMER_PAIL] =
    {
        .name = _("WAILMER PAIL"),
        .itemId = ITEM_WAILMER_PAIL,
        .price = 0,
        .description = sWailmerPailDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_DEVON_GOODS] =
    {
        .name = _("DEVON GOODS"),
        .itemId = ITEM_DEVON_GOODS,
        .price = 0,
        .description = sDevonGoodsDesc,
        .importance = 2,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SOOT_SACK] =
    {
        .name = _("SOOT SACK"),
        .itemId = ITEM_SOOT_SACK,
        .price = 0,
        .description = sSootSackDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BASEMENT_KEY] =
    {
        .name = _("BASEMENT KEY"),
        .itemId = ITEM_BASEMENT_KEY,
        .price = 0,
        .description = sBasementKeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ACRO_BIKE] =
    {
        .name = _("ACRO BIKE"),
        .itemId = ITEM_ACRO_BIKE,
        .price = 0,
        .description = sAcroBikeDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
        .secondaryId = ACRO_BIKE,
    },

    [ITEM_LETTER] =
    {
        .name = _("LETTER"),
        .itemId = ITEM_LETTER,
        .price = 0,
        .description = sLetterDesc,
        .importance = 2,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_EON_TICKET] =
    {
        .name = _("EON TICKET"),
        .itemId = ITEM_EON_TICKET,
        .price = 0,
        .description = sEonTicketDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
        .secondaryId = 1,
    },

    [ITEM_RED_ORB] =
    {
        .name = _("RED ORB"),
        .itemId = ITEM_RED_ORB,
        .price = 0,
        .description = sRedOrbDesc,
        .importance = 2,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BLUE_ORB] =
    {
        .name = _("BLUE ORB"),
        .itemId = ITEM_BLUE_ORB,
        .price = 0,
        .description = sBlueOrbDesc,
        .importance = 2,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SCANNER] =
    {
        .name = _("SCANNER"),
        .itemId = ITEM_SCANNER,
        .price = 0,
        .description = sScannerDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_GO_GOGGLES] =
    {
        .name = _("GO-GOGGLES"),
        .itemId = ITEM_GO_GOGGLES,
        .price = 0,
        .description = sGoGogglesDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_METEORITE] =
    {
        .name = _("METEORITE"),
        .itemId = ITEM_METEORITE,
        .price = 0,
        .description = sMeteoriteDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ROOM_1_KEY] =
    {
        .name = _("RM. 1 KEY"),
        .itemId = ITEM_ROOM_1_KEY,
        .price = 0,
        .description = sRoom1KeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ROOM_2_KEY] =
    {
        .name = _("RM. 2 KEY"),
        .itemId = ITEM_ROOM_2_KEY,
        .price = 0,
        .description = sRoom2KeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ROOM_4_KEY] =
    {
        .name = _("RM. 4 KEY"),
        .itemId = ITEM_ROOM_4_KEY,
        .price = 0,
        .description = sRoom4KeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ROOM_6_KEY] =
    {
        .name = _("RM. 6 KEY"),
        .itemId = ITEM_ROOM_6_KEY,
        .price = 0,
        .description = sRoom6KeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_STORAGE_KEY] =
    {
        .name = _("STORAGE KEY"),
        .itemId = ITEM_STORAGE_KEY,
        .price = 0,
        .description = sStorageKeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_ROOT_FOSSIL] =
    {
        .name = _("ROOT FOSSIL"),
        .itemId = ITEM_ROOT_FOSSIL,
        .price = 0,
        .description = sRootFossilDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CLAW_FOSSIL] =
    {
        .name = _("CLAW FOSSIL"),
        .itemId = ITEM_CLAW_FOSSIL,
        .price = 0,
        .description = sClawFossilDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DEVON_SCOPE] =
    {
        .name = _("DEVON SCOPE"),
        .itemId = ITEM_DEVON_SCOPE,
        .price = 0,
        .description = sDevonScopeDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

// TMs/HMs

    [ITEM_TM_FOCUS_PUNCH] =
    {
        .name = _("TM01"),
        .itemId = ITEM_TM01,
        .price = 3000,
        .description = sTM01Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_DRAGON_CLAW] =
    {
        .name = _("TM02"),
        .itemId = ITEM_TM02,
        .price = 3000,
        .description = sTM02Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_WATER_PULSE] =
    {
        .name = _("TM03"),
        .itemId = ITEM_TM03,
        .price = 3000,
        .description = sTM03Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_CALM_MIND] =
    {
        .name = _("TM04"),
        .itemId = ITEM_TM04,
        .price = 3000,
        .description = sTM04Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_ROAR] =
    {
        .name = _("TM05"),
        .itemId = ITEM_TM05,
        .price = 1000,
        .description = sTM05Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_TOXIC] =
    {
        .name = _("TM06"),
        .itemId = ITEM_TM06,
        .price = 3000,
        .description = sTM06Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_HAIL] =
    {
        .name = _("TM07"),
        .itemId = ITEM_TM07,
        .price = 3000,
        .description = sTM07Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_BULK_UP] =
    {
        .name = _("TM08"),
        .itemId = ITEM_TM08,
        .price = 3000,
        .description = sTM08Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_BULLET_SEED] =
    {
        .name = _("TM09"),
        .itemId = ITEM_TM09,
        .price = 3000,
        .description = sTM09Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_HIDDEN_POWER] =
    {
        .name = _("TM10"),
        .itemId = ITEM_TM10,
        .price = 3000,
        .description = sTM10Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SUNNY_DAY] =
    {
        .name = _("TM11"),
        .itemId = ITEM_TM11,
        .price = 2000,
        .description = sTM11Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_TAUNT] =
    {
        .name = _("TM12"),
        .itemId = ITEM_TM12,
        .price = 3000,
        .description = sTM12Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_ICE_BEAM] =
    {
        .name = _("TM13"),
        .itemId = ITEM_TM13,
        .price = 3000,
        .description = sTM13Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_BLIZZARD] =
    {
        .name = _("TM14"),
        .itemId = ITEM_TM14,
        .price = 5500,
        .description = sTM14Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_HYPER_BEAM] =
    {
        .name = _("TM15"),
        .itemId = ITEM_TM15,
        .price = 7500,
        .description = sTM15Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_LIGHT_SCREEN] =
    {
        .name = _("TM16"),
        .itemId = ITEM_TM16,
        .price = 3000,
        .description = sTM16Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_PROTECT] =
    {
        .name = _("TM17"),
        .itemId = ITEM_TM17,
        .price = 3000,
        .description = sTM17Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_RAIN_DANCE] =
    {
        .name = _("TM18"),
        .itemId = ITEM_TM18,
        .price = 2000,
        .description = sTM18Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_GIGA_DRAIN] =
    {
        .name = _("TM19"),
        .itemId = ITEM_TM19,
        .price = 3000,
        .description = sTM19Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SAFEGUARD] =
    {
        .name = _("TM20"),
        .itemId = ITEM_TM20,
        .price = 3000,
        .description = sTM20Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_FRUSTRATION] =
    {
        .name = _("TM21"),
        .itemId = ITEM_TM21,
        .price = 1000,
        .description = sTM21Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SOLAR_BEAM] =
    {
        .name = _("TM22"),
        .itemId = ITEM_TM22,
        .price = 3000,
        .description = sTM22Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_IRON_TAIL] =
    {
        .name = _("TM23"),
        .itemId = ITEM_TM23,
        .price = 3000,
        .description = sTM23Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_THUNDERBOLT] =
    {
        .name = _("TM24"),
        .itemId = ITEM_TM24,
        .price = 3000,
        .description = sTM24Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_THUNDER] =
    {
        .name = _("TM25"),
        .itemId = ITEM_TM25,
        .price = 5500,
        .description = sTM25Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_EARTHQUAKE] =
    {
        .name = _("TM26"),
        .itemId = ITEM_TM26,
        .price = 3000,
        .description = sTM26Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_RETURN] =
    {
        .name = _("TM27"),
        .itemId = ITEM_TM27,
        .price = 1000,
        .description = sTM27Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_DIG] =
    {
        .name = _("TM28"),
        .itemId = ITEM_TM28,
        .price = 2000,
        .description = sTM28Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_PSYCHIC] =
    {
        .name = _("TM29"),
        .itemId = ITEM_TM29,
        .price = 2000,
        .description = sTM29Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SHADOW_BALL] =
    {
        .name = _("TM30"),
        .itemId = ITEM_TM30,
        .price = 3000,
        .description = sTM30Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_BRICK_BREAK] =
    {
        .name = _("TM31"),
        .itemId = ITEM_TM31,
        .price = 3000,
        .description = sTM31Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_DOUBLE_TEAM] =
    {
        .name = _("TM32"),
        .itemId = ITEM_TM32,
        .price = 2000,
        .description = sTM32Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_REFLECT] =
    {
        .name = _("TM33"),
        .itemId = ITEM_TM33,
        .price = 3000,
        .description = sTM33Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SHOCK_WAVE] =
    {
        .name = _("TM34"),
        .itemId = ITEM_TM34,
        .price = 3000,
        .description = sTM34Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_FLAMETHROWER] =
    {
        .name = _("TM35"),
        .itemId = ITEM_TM35,
        .price = 3000,
        .description = sTM35Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SLUDGE_BOMB] =
    {
        .name = _("TM36"),
        .itemId = ITEM_TM36,
        .price = 1000,
        .description = sTM36Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SANDSTORM] =
    {
        .name = _("TM37"),
        .itemId = ITEM_TM37,
        .price = 2000,
        .description = sTM37Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_FIRE_BLAST] =
    {
        .name = _("TM38"),
        .itemId = ITEM_TM38,
        .price = 5500,
        .description = sTM38Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_ROCK_TOMB] =
    {
        .name = _("TM39"),
        .itemId = ITEM_TM39,
        .price = 3000,
        .description = sTM39Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_AERIAL_ACE] =
    {
        .name = _("TM40"),
        .itemId = ITEM_TM40,
        .price = 3000,
        .description = sTM40Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_TORMENT] =
    {
        .name = _("TM41"),
        .itemId = ITEM_TM41,
        .price = 3000,
        .description = sTM41Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_FACADE] =
    {
        .name = _("TM42"),
        .itemId = ITEM_TM42,
        .price = 3000,
        .description = sTM42Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SECRET_POWER] =
    {
        .name = _("TM43"),
        .itemId = ITEM_TM43,
        .price = 3000,
        .description = sTM43Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_REST] =
    {
        .name = _("TM44"),
        .itemId = ITEM_TM44,
        .price = 3000,
        .description = sTM44Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_ATTRACT] =
    {
        .name = _("TM45"),
        .itemId = ITEM_TM45,
        .price = 3000,
        .description = sTM45Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_THIEF] =
    {
        .name = _("TM46"),
        .itemId = ITEM_TM46,
        .price = 3000,
        .description = sTM46Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_STEEL_WING] =
    {
        .name = _("TM47"),
        .itemId = ITEM_TM47,
        .price = 3000,
        .description = sTM47Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SKILL_SWAP] =
    {
        .name = _("TM48"),
        .itemId = ITEM_TM48,
        .price = 3000,
        .description = sTM48Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_SNATCH] =
    {
        .name = _("TM49"),
        .itemId = ITEM_TM49,
        .price = 3000,
        .description = sTM49Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_TM_OVERHEAT] =
    {
        .name = _("TM50"),
        .itemId = ITEM_TM50,
        .price = 3000,
        .description = sTM50Desc,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_CUT] =
    {
        .name = _("HM01"),
        .itemId = ITEM_HM01,
        .price = 0,
        .description = sHM01Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_FLY] =
    {
        .name = _("HM02"),
        .itemId = ITEM_HM02,
        .price = 0,
        .description = sHM02Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_SURF] =
    {
        .name = _("HM03"),
        .itemId = ITEM_HM03,
        .price = 0,
        .description = sHM03Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_STRENGTH] =
    {
        .name = _("HM04"),
        .itemId = ITEM_HM04,
        .price = 0,
        .description = sHM04Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_FLASH] =
    {
        .name = _("HM05"),
        .itemId = ITEM_HM05,
        .price = 0,
        .description = sHM05Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_ROCK_SMASH] =
    {
        .name = _("HM06"),
        .itemId = ITEM_HM06,
        .price = 0,
        .description = sHM06Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_WATERFALL] =
    {
        .name = _("HM07"),
        .itemId = ITEM_HM07,
        .price = 0,
        .description = sHM07Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_HM_DIVE] =
    {
        .name = _("HM08"),
        .itemId = ITEM_HM08,
        .price = 0,
        .description = sHM08Desc,
        .importance = 1,
        .type = ITEM_USE_PARTY_MENU,
    },

    [ITEM_15B] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_15C] =
    {
        .name = _("????????"),
        .itemId = ITEM_NONE,
        .price = 0,
        .description = sDummyDesc,
        .type = ITEM_USE_BAG_MENU,
    },

// FireRed/LeafGreen key items

    [ITEM_OAKS_PARCEL] =
    {
        .name = _("OAK'S PARCEL"),
        .itemId = ITEM_OAKS_PARCEL,
        .price = 0,
        .description = sOaksParcelDesc,
        .importance = 2,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_POKE_FLUTE] =
    {
        .name = _("POKé FLUTE"),
        .itemId = ITEM_POKE_FLUTE,
        .price = 0,
        .description = sPokeFluteDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SECRET_KEY] =
    {
        .name = _("SECRET KEY"),
        .itemId = ITEM_SECRET_KEY,
        .price = 0,
        .description = sSecretKeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BIKE_VOUCHER] =
    {
        .name = _("BIKE VOUCHER"),
        .itemId = ITEM_BIKE_VOUCHER,
        .price = 0,
        .description = sBikeVoucherDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_GOLD_TEETH] =
    {
        .name = _("GOLD TEETH"),
        .itemId = ITEM_GOLD_TEETH,
        .price = 0,
        .description = sGoldTeethDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_OLD_AMBER] =
    {
        .name = _("OLD AMBER"),
        .itemId = ITEM_OLD_AMBER,
        .price = 0,
        .description = sOldAmberDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_CARD_KEY] =
    {
        .name = _("CARD KEY"),
        .itemId = ITEM_CARD_KEY,
        .price = 0,
        .description = sCardKeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_LIFT_KEY] =
    {
        .name = _("LIFT KEY"),
        .itemId = ITEM_LIFT_KEY,
        .price = 0,
        .description = sLiftKeyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_HELIX_FOSSIL] =
    {
        .name = _("HELIX FOSSIL"),
        .itemId = ITEM_HELIX_FOSSIL,
        .price = 0,
        .description = sHelixFossilDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_DOME_FOSSIL] =
    {
        .name = _("DOME FOSSIL"),
        .itemId = ITEM_DOME_FOSSIL,
        .price = 0,
        .description = sDomeFossilDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SILPH_SCOPE] =
    {
        .name = _("SILPH SCOPE"),
        .itemId = ITEM_SILPH_SCOPE,
        .price = 0,
        .description = sSilphScopeDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BICYCLE] =
    {
        .name = _("BICYCLE"),
        .itemId = ITEM_BICYCLE,
        .price = 0,
        .description = sBicycleDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_TOWN_MAP] =
    {
        .name = _("TOWN MAP"),
        .itemId = ITEM_TOWN_MAP,
        .price = 0,
        .description = sTownMapDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_VS_SEEKER] =
    {
        .name = _("VS SEEKER"),
        .itemId = ITEM_VS_SEEKER,
        .price = 0,
        .description = sVSSeekerDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_FAME_CHECKER] =
    {
        .name = _("FAME CHECKER"),
        .itemId = ITEM_FAME_CHECKER,
        .price = 0,
        .description = sFameCheckerDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_TM_CASE] =
    {
        .name = _("TM CASE"),
        .itemId = ITEM_TM_CASE,
        .price = 0,
        .description = sTMCaseDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_BERRY_POUCH] =
    {
        .name = _("BERRY POUCH"),
        .itemId = ITEM_BERRY_POUCH,
        .price = 0,
        .description = sBerryPouchDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_TEACHY_TV] =
    {
        .name = _("TEACHY TV"),
        .itemId = ITEM_TEACHY_TV,
        .price = 0,
        .description = sTeachyTVDesc,
        .importance = 1,
        .type = ITEM_USE_FIELD,
    },

    [ITEM_TRI_PASS] =
    {
        .name = _("TRI-PASS"),
        .itemId = ITEM_TRI_PASS,
        .price = 0,
        .description = sTriPassDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RAINBOW_PASS] =
    {
        .name = _("RAINBOW PASS"),
        .itemId = ITEM_RAINBOW_PASS,
        .price = 0,
        .description = sRainbowPassDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_TEA] =
    {
        .name = _("TEA"),
        .itemId = ITEM_TEA,
        .price = 0,
        .description = sTeaDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_MYSTIC_TICKET] =
    {
        .name = _("MYSTICTICKET"),
        .itemId = ITEM_MYSTIC_TICKET,
        .price = 0,
        .description = sMysticTicketDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_AURORA_TICKET] =
    {
        .name = _("AURORATICKET"),
        .itemId = ITEM_AURORA_TICKET,
        .price = 0,
        .description = sAuroraTicketDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_POWDER_JAR] =
    {
        .name = _("POWDER JAR"),
        .itemId = ITEM_POWDER_JAR,
        .price = 0,
        .description = sPowderJarDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_RUBY] =
    {
        .name = _("RUBY"),
        .itemId = ITEM_RUBY,
        .price = 0,
        .description = sRubyDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_SAPPHIRE] =
    {
        .name = _("SAPPHIRE"),
        .itemId = ITEM_SAPPHIRE,
        .price = 0,
        .description = sSapphireDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

// Emerald-specific key items

    [ITEM_MAGMA_EMBLEM] =
    {
        .name = _("MAGMA EMBLEM"),
        .itemId = ITEM_MAGMA_EMBLEM,
        .price = 0,
        .description = sMagmaEmblemDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },

    [ITEM_OLD_SEA_MAP] =
    {
        .name = _("OLD SEA MAP"),
        .itemId = ITEM_OLD_SEA_MAP,
        .price = 0,
        .description = sOldSeaMapDesc,
        .importance = 1,
        .type = ITEM_USE_BAG_MENU,
    },
};

#endif // GUARD_ITEMS_H
