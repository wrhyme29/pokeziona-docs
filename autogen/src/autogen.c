#include <stdio.h>
#include <string.h>

#include "include/constants/pokedex.h"
#include "include/constants/pokemon.h"
#include "include/types_aliases.h"
#include "include/utilities.h"
#include "include/abilities.h"
#include "include/species_info.h"
#include "include/species_names.h"
#include "include/type_names.h"
#include "include/move_names.h"
#include "include/pokemon.h"
#include "include/level_up_learnset_pointers.h"
#include "include/battle_moves.h"
#include "include/move_descriptions.h"
#include "include/egg_moves.h"
#include "include/tutor_learnsets.h"
#include "include/tmhm_learnsets.h"
#include "include/evolution.h"
#include "include/items.h"

struct PokemonDocDataAbility
{
    u8 id[ABILITY_NAME_LENGTH + 1];
    u8 name[ABILITY_NAME_LENGTH + 1];
    u8 *description;
    u16 num;
};

struct PokemonDocDataStat
{
    u8 stat[STAT_LENGTH + 1];
    u8 name[STAT_LENGTH + 1];
    u8 amount;
};

struct PokemonDocDataEvolution
{
    u8 species_id[POKEMON_NAME_LENGTH + 1];
    u8 name[POKEMON_NAME_LENGTH + 1];
    u8 method[EVO_LENGTH + 1];
    u8 parameter[ITEM_NAME_LENGTH + 1];
    u16 num;
};

struct PokemonDocDataMove
{
    u8 level;
    u8 id[MOVE_NAME_LENGTH + 1];
    u8 name[MOVE_NAME_LENGTH + 1];
    u8 type[TYPE_NAME_LENGTH + 1];
    u8 category[CATEGORY_LENGTH + 1];
    u8 power;
    u8 pp;
    u8 accuracy;
    u8 *description;
    u16 num;
};

struct PokemonDocData
{
    u8 id[POKEMON_NAME_LENGTH + 1];
    u8 species_id[POKEMON_NAME_LENGTH + 1];
    u8 name[POKEMON_NAME_LENGTH + 1];
    u8 base_name[POKEMON_NAME_LENGTH + 1];
    u16 regional_dex_number;
    u16 national_dex_number;
    u8 types[2][TYPE_NAME_LENGTH + 1];
    struct PokemonDocDataAbility abilities[2];
    u8 baseHP;
    u8 baseAttack;
    u8 baseDefense;
    u8 baseSpeed;
    u8 baseSpAttack;
    u8 baseSpDefense;
    struct PokemonDocDataStat ev_yields[NUM_STATS];
    u8 numEvYields;
    struct PokemonDocDataMove level_up_moves[MAX_LEVEL_UP_MOVES];
    u8 numLevelUpMoves;
    struct PokemonDocDataMove tmhm_moves[NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES];
    u8 numTmHmMoves;
    struct PokemonDocDataMove tutor_moves[TUTOR_MOVE_COUNT];
    u8 numTutorMoves;
    struct PokemonDocDataMove egg_moves[EGG_MOVES_ARRAY_COUNT];
    u8 numEggMoves;
    struct PokemonDocDataEvolution next_evolutions[EVOS_PER_MON];
    u8 numNextEvolutions;
    struct PokemonDocDataEvolution final_evolutions[EVOS_PER_MON];
    u8 numFinalEvolutions;
};

void printPokemonDocData(struct PokemonDocData monData)
{
    printf("{\n");
    printf("\t\"id\": \"%s\",\n", monData.id);
    printf("\t\"species_id\": \"%s\",\n", monData.species_id);
    printf("\t\"name\": \"%s\",\n", monData.name);
    printf("\t\"base_name\": \"%s\",\n", monData.base_name);
    printf("\t\"form_number\": %d,\n", 0); // unused
    printf("\t\"form_name\": \"%s\",\n", ""); // unused
    printf("\t\"regional_dex_number\": %d,\n", monData.regional_dex_number);
    printf("\t\"national_dex_number\": %d,\n", monData.national_dex_number);
    printf("\t\"generation\": %d,\n", 3); // @TODO: calculate gen dynamically
    printf("\t\"types\": [\n");
    printf("\t\t\"%s\"", monData.types[0]);
    if(strcmp(monData.types[0], monData.types[1]) != 0)
    {
        printf(",\n\t\t\"%s\"", monData.types[1]);
    }
    printf("\n");
    printf("\t],\n");

    printf("\t\"abilities\": [\n");
    for(u8 i = 0; i < 2; i++)
    {
        if(monData.abilities[i].num == ABILITY_NONE) continue;
        if(i > 0) printf(",\n");
        printf("\t\t{\n");
        printf("\t\t\t\"id\": \"%s\",\n", monData.abilities[i].id);
        printf("\t\t\t\"name\": \"%s\",\n", monData.abilities[i].name);
        printf("\t\t\t\"description\": \"%s\"\n", monData.abilities[i].description);
        printf("\t\t}");
    }
    printf("\n");
    printf("\t],\n");
    printf("\t\"base_stats\": [\n");
    printf("\t\t%d,\n", monData.baseHP);
    printf("\t\t%d,\n", monData.baseAttack);
    printf("\t\t%d,\n", monData.baseDefense);
    printf("\t\t%d,\n", monData.baseSpeed);
    printf("\t\t%d,\n", monData.baseSpAttack);
    printf("\t\t%d\n", monData.baseSpDefense);
    printf("\t],\n");
    printf("\t\"base_stats_dict\": {\n");
    printf("\t\t\"HP\": %d,\n", monData.baseHP);
    printf("\t\t\"ATK\": %d,\n", monData.baseAttack);
    printf("\t\t\"DEF\": %d,\n", monData.baseDefense);
    printf("\t\t\"SPA\": %d,\n", monData.baseSpAttack);
    printf("\t\t\"SPD\": %d,\n", monData.baseSpDefense);
    printf("\t\t\"SPE\": %d\n", monData.baseSpeed);
    printf("\t},\n");

    u16 baseStatTotal = monData.baseHP
                       + monData.baseAttack
                       + monData.baseDefense
                       + monData.baseSpAttack
                       + monData.baseSpDefense
                       + monData.baseSpeed;
    printf("\t\"base_stat_total\": %d,\n", baseStatTotal);

    printf("\t\"evs\": [\n");
    for(u8 i = 0; i < monData.numEvYields; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t{\n");
        printf("\t\t\t\"stat\": \"%s\",\n", monData.ev_yields[i].stat);
        printf("\t\t\t\"name\": \"%s\",\n", monData.ev_yields[i].name);
        printf("\t\t\t\"amount\": %d\n", monData.ev_yields[i].amount);
        printf("\t\t}");
    }
    printf("\n");
    printf("\t],\n");
     printf("\t\"ev_yield\": [\n");
    for(u8 i = 0; i < monData.numEvYields; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t{\n");
        printf("\t\t\t\"stat\": \"%s\",\n", monData.ev_yields[i].stat);
        printf("\t\t\t\"name\": \"%s\",\n", monData.ev_yields[i].name);
        printf("\t\t\t\"amount\": %d\n", monData.ev_yields[i].amount);
        printf("\t\t}");
    }
    printf("\n");
    printf("\t],\n");

    printf("\t\"ev_yield_text\": \"");
    for(u8 i = 0; i < monData.numEvYields; i++)
    {
        if(i > 0) printf(", ");
        printf("%d %s", monData.ev_yields[i].amount, monData.ev_yields[i].name);
    }
    printf("\",\n");

    printf("\t\"moves\": {\n");
    printf("\t\t\"level_up\": [\n");
    for(u8 i = 0; i < monData.numLevelUpMoves; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t\t{\n");
        printf("\t\t\t\t\"level\": %d,\n", monData.level_up_moves[i].level);
        printf("\t\t\t\t\"id\": \"%s\",\n", monData.level_up_moves[i].id);
        printf("\t\t\t\t\"name\": \"%s\",\n", monData.level_up_moves[i].name);
        printf("\t\t\t\t\"type\": \"%s\",\n", monData.level_up_moves[i].type);
        printf("\t\t\t\t\"category\": \"%s\",\n", monData.level_up_moves[i].category);
        if(monData.level_up_moves[i].power == 0)
        {
            printf("\t\t\t\t\"power\": null,\n");
        } else
        {
            printf("\t\t\t\t\"power\": %d,\n", monData.level_up_moves[i].power);
        }
        printf("\t\t\t\t\"pp\": %d,\n", monData.level_up_moves[i].pp);
        printf("\t\t\t\t\"accuracy\": %d,\n", monData.level_up_moves[i].accuracy);
        printf("\t\t\t\t\"description\": \"%s\"\n", monData.level_up_moves[i].description);
        printf("\t\t\t}");
    }
    printf("\n");
    printf("\t\t],\n");
    printf("\t\t\"tmhm\": [\n");
    for(u8 i = 0; i < monData.numTmHmMoves; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t\t{\n");
        printf("\t\t\t\t\"id\": \"%s\",\n", monData.tmhm_moves[i].id);
        printf("\t\t\t\t\"name\": \"%s\",\n", monData.tmhm_moves[i].name);
        printf("\t\t\t\t\"type\": \"%s\",\n", monData.tmhm_moves[i].type);
        printf("\t\t\t\t\"category\": \"%s\",\n", monData.tmhm_moves[i].category);
        if(monData.tmhm_moves[i].power == 0)
        {
            printf("\t\t\t\t\"power\": null,\n");
        } else
        {
            printf("\t\t\t\t\"power\": %d,\n", monData.tmhm_moves[i].power);
        }
        printf("\t\t\t\t\"pp\": %d,\n", monData.tmhm_moves[i].pp);
        printf("\t\t\t\t\"accuracy\": %d,\n", monData.tmhm_moves[i].accuracy);
        printf("\t\t\t\t\"description\": \"%s\"\n", monData.tmhm_moves[i].description);
        printf("\t\t\t}");
    }
    printf("\n");
    printf("\t\t],\n");
    printf("\t\t\"tutor\": [\n");
    for(u8 i = 0; i < monData.numTutorMoves; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t\t{\n");
        printf("\t\t\t\t\"id\": \"%s\",\n", monData.tutor_moves[i].id);
        printf("\t\t\t\t\"name\": \"%s\",\n", monData.tutor_moves[i].name);
        printf("\t\t\t\t\"type\": \"%s\",\n", monData.tutor_moves[i].type);
        printf("\t\t\t\t\"category\": \"%s\",\n", monData.tutor_moves[i].category);
        if(monData.tutor_moves[i].power == 0)
        {
            printf("\t\t\t\t\"power\": null,\n");
        } else
        {
            printf("\t\t\t\t\"power\": %d,\n", monData.tutor_moves[i].power);
        }
        printf("\t\t\t\t\"pp\": %d,\n", monData.tutor_moves[i].pp);
        printf("\t\t\t\t\"accuracy\": %d,\n", monData.tutor_moves[i].accuracy);
        printf("\t\t\t\t\"description\": \"%s\"\n", monData.tutor_moves[i].description);
        printf("\t\t\t}");
    }
    printf("\n");
    printf("\t\t],\n");
    printf("\t\t\"egg\": [\n");
    for(u8 i = 0; i < monData.numEggMoves; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t\t{\n");
        printf("\t\t\t\t\"id\": \"%s\",\n", monData.egg_moves[i].id);
        printf("\t\t\t\t\"name\": \"%s\",\n", monData.egg_moves[i].name);
        printf("\t\t\t\t\"type\": \"%s\",\n", monData.egg_moves[i].type);
        printf("\t\t\t\t\"category\": \"%s\",\n", monData.egg_moves[i].category);
        if(monData.egg_moves[i].power == 0)
        {
            printf("\t\t\t\t\"power\": null,\n");
        } else
        {
            printf("\t\t\t\t\"power\": %d,\n", monData.egg_moves[i].power);
        }
        printf("\t\t\t\t\"pp\": %d,\n", monData.egg_moves[i].pp);
        printf("\t\t\t\t\"accuracy\": %d,\n", monData.egg_moves[i].accuracy);
        printf("\t\t\t\t\"description\": \"%s\"\n", monData.egg_moves[i].description);
        printf("\t\t\t}");
    }
    printf("\n");
    printf("\t\t]\n");
    printf("\t},\n");
    printf("\t\"evolution\": {\n");
    printf("\t\t\"next\": [\n");
    for(u8 i = 0; i < monData.numNextEvolutions; i++)
    {
        if(i > 0) printf(",\n");
        printf("\t\t\t{\n");
        printf("\t\t\t\t\"species_id\": \"%s\",\n", monData.next_evolutions[i].species_id);
        printf("\t\t\t\t\"name\": \"%s\",\n", monData.next_evolutions[i].name);
        printf("\t\t\t\t\"method\": \"%s\",\n", monData.next_evolutions[i].method);
        printf("\t\t\t\t\"parameter\": \"%s\"\n", monData.next_evolutions[i].parameter);
        printf("\t\t\t}");
    }
    printf("\n");

    printf("\t\t]\n");
    printf("\t},\n");
    printf("\t\"sprites\": {\n");
    printf("\t\t\"regular\": \"images/pokemon/%s.png\",\n", monData.species_id);
    printf("\t\t\"shiny\": \"images/pokemon-shiny/%s.png\"\n", monData.species_id);
    printf("\t},\n");
    printf("\t\"forms\": []\n"); // unused
    printf("}");
}

struct PokemonDocData gPokemonDocs[NUM_SPECIES] = {0};


int main()
{
    printf("[\n");
    for(u16 i = 0; i < NUM_SPECIES; i++)
    {
        if(i == SPECIES_NONE) continue;
        if(i > 1) printf(",\n");

        strcpy(gPokemonDocs[i].id, gSpeciesNames[i]);
        strcpy(gPokemonDocs[i].species_id, gSpeciesNames[i]);
        strcpy(gPokemonDocs[i].name, gSpeciesNames[i]);
        capitalizeString(gPokemonDocs[i].name);
        strcpy(gPokemonDocs[i].base_name, gPokemonDocs[i].name);
        gPokemonDocs[i].regional_dex_number = sSpeciesToHoennPokedexNum[i];
        gPokemonDocs[i].national_dex_number = sSpeciesToNationalPokedexNum[i];
        strcpy(gPokemonDocs[i].types[0], gTypeNames[gSpeciesInfo[i].types[0]]);
        strcpy(gPokemonDocs[i].types[1], gTypeNames[gSpeciesInfo[i].types[1]]);

        for(u8 j = 0; j < 2; j++)
        {
            gPokemonDocs[i].abilities[j].num = gSpeciesInfo[i].abilities[j];
            strcpy(gPokemonDocs[i].abilities[j].id, gAbilityNames[gSpeciesInfo[i].abilities[j]]);
            strcpy(gPokemonDocs[i].abilities[j].name, gPokemonDocs[i].abilities[j].id);
            capitalizeString(gPokemonDocs[i].abilities[j].name);
            gPokemonDocs[i].abilities[j].description = gAbilityDescriptionPointers[gSpeciesInfo[i].abilities[j]];
        }

        gPokemonDocs[i].baseHP = gSpeciesInfo[i].baseHP;
        gPokemonDocs[i].baseAttack = gSpeciesInfo[i].baseAttack;
        gPokemonDocs[i].baseDefense = gSpeciesInfo[i].baseDefense;
        gPokemonDocs[i].baseSpeed = gSpeciesInfo[i].baseSpeed;
        gPokemonDocs[i].baseSpAttack = gSpeciesInfo[i].baseSpAttack;
        gPokemonDocs[i].baseSpDefense = gSpeciesInfo[i].baseSpDefense;

        gPokemonDocs[i].numEvYields = 0;
        for (u8 j = 0; j < NUM_STATS; j++)
        {
            switch (j)
            {
                case STAT_HP:
                    if (!gSpeciesInfo[i].evYield_HP) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "HP");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "HP");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_HP;
                    break;
                case STAT_ATK:
                    if (!gSpeciesInfo[i].evYield_Attack) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "ATTACK");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "Attack");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_Attack;
                    break;
                case STAT_DEF:
                    if (!gSpeciesInfo[i].evYield_Defense) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "DEFENSE");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "Defense");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_Defense;
                    break;
                case STAT_SPEED:
                    if (!gSpeciesInfo[i].evYield_Speed) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "SPEED");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "Speed");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_Speed;
                    break;
                case STAT_SPATK:
                    if (!gSpeciesInfo[i].evYield_SpAttack) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "SPECIAL_ATTACK");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "Special Attack");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_SpAttack;
                    break;
                case STAT_SPDEF:
                    if (!gSpeciesInfo[i].evYield_SpDefense) continue;
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].stat, "SPECIAL_DEFENSE");
                    strcpy(gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].name, "Special Defense");
                    gPokemonDocs[i].ev_yields[gPokemonDocs[i].numEvYields].amount = gSpeciesInfo[i].evYield_SpDefense;
                    break;
            }

            gPokemonDocs[i].numEvYields++;
        }

        gPokemonDocs[i].numLevelUpMoves = 0;
        for (u8 j = 0; j < MAX_LEVEL_UP_MOVES && gLevelUpLearnsets[i][j] != LEVEL_UP_END; j++)
        {
            gPokemonDocs[i].numLevelUpMoves++;
            gPokemonDocs[i].level_up_moves[j].num = gLevelUpLearnsets[i][j] & LEVEL_UP_MOVE_ID;
            gPokemonDocs[i].level_up_moves[j].level = (gLevelUpLearnsets[i][j] & LEVEL_UP_MOVE_LV) >> 9;
            strcpy(gPokemonDocs[i].level_up_moves[j].id, gMoveNames[gPokemonDocs[i].level_up_moves[j].num]);
            strcpy(gPokemonDocs[i].level_up_moves[j].name, gMoveNames[gPokemonDocs[i].level_up_moves[j].num]);
            capitalizeString(gPokemonDocs[i].level_up_moves[j].name);
            strcpy(gPokemonDocs[i].level_up_moves[j].type, gTypeNames[gBattleMoves[gPokemonDocs[i].level_up_moves[j].num].type]);
            strcpy(gPokemonDocs[i].level_up_moves[j].category, gCategoryNames[gBattleMoves[gPokemonDocs[i].level_up_moves[j].num].category]);
            capitalizeString(gPokemonDocs[i].level_up_moves[j].category);
            gPokemonDocs[i].level_up_moves[j].power = gBattleMoves[gPokemonDocs[i].level_up_moves[j].num].power;
            gPokemonDocs[i].level_up_moves[j].pp = gBattleMoves[gPokemonDocs[i].level_up_moves[j].num].pp;
            gPokemonDocs[i].level_up_moves[j].accuracy = gBattleMoves[gPokemonDocs[i].level_up_moves[j].num].accuracy;
            gPokemonDocs[i].level_up_moves[j].description = gMoveDescriptionPointers[gPokemonDocs[i].level_up_moves[j].num - 1];
        }

        gPokemonDocs[i].numTmHmMoves = 0;
        for(u8 j = 0; j < NUM_TECHNICAL_MACHINES + NUM_HIDDEN_MACHINES; j++)
        {
            if(!(canSpeciesLearnTMHM(i, j))) continue;

            gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num = sTMHMMoves[j];
            strcpy(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].id, gMoveNames[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num]);
            strcpy(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].name, gMoveNames[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num]);
            capitalizeString(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].name);
            strcpy(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].type, gTypeNames[gBattleMoves[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num].type]);
            strcpy(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].category, gCategoryNames[gBattleMoves[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num].category]);
            capitalizeString(gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].category);
            gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].power = gBattleMoves[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num].power;
            gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].pp = gBattleMoves[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num].pp;
            gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].accuracy = gBattleMoves[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num].accuracy;
            gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].description = gMoveDescriptionPointers[gPokemonDocs[i].tmhm_moves[gPokemonDocs[i].numTmHmMoves].num - 1];

            gPokemonDocs[i].numTmHmMoves++;
        }


        gPokemonDocs[i].numTutorMoves = 0;
        for(u8 j = 0; j < TUTOR_MOVE_COUNT; j++)
        {
            if(!(sTutorLearnsets[i] & (1 << j))) continue;

            gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num = gTutorMoves[j];
            strcpy(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].id, gMoveNames[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num]);
            strcpy(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].name, gMoveNames[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num]);
            capitalizeString(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].name);
            strcpy(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].type, gTypeNames[gBattleMoves[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num].type]);
            strcpy(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].category, gCategoryNames[gBattleMoves[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num].category]);
            capitalizeString(gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].category);
            gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].power = gBattleMoves[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num].power;
            gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].pp = gBattleMoves[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num].pp;
            gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].accuracy = gBattleMoves[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num].accuracy;
            gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].description = gMoveDescriptionPointers[gPokemonDocs[i].tutor_moves[gPokemonDocs[i].numTutorMoves].num - 1];

            gPokemonDocs[i].numTutorMoves++;
        }

        gPokemonDocs[i].numEggMoves = 0;
        u16 eggMoveIdx = speciesToEggSpeciesIndex(i);
        for (u8 j = 0; j < EGG_MOVES_ARRAY_COUNT; j++)
        {
            if (gEggMoves[eggMoveIdx + j] > EGG_MOVES_SPECIES_OFFSET)
                break;

            gPokemonDocs[i].numEggMoves++;
            gPokemonDocs[i].egg_moves[j].num = gEggMoves[eggMoveIdx + j];
            strcpy(gPokemonDocs[i].egg_moves[j].id, gMoveNames[gPokemonDocs[i].egg_moves[j].num]);
            strcpy(gPokemonDocs[i].egg_moves[j].name, gMoveNames[gPokemonDocs[i].egg_moves[j].num]);
            capitalizeString(gPokemonDocs[i].egg_moves[j].name);
            strcpy(gPokemonDocs[i].egg_moves[j].type, gTypeNames[gBattleMoves[gPokemonDocs[i].egg_moves[j].num].type]);
            strcpy(gPokemonDocs[i].egg_moves[j].category, gCategoryNames[gBattleMoves[gPokemonDocs[i].egg_moves[j].num].category]);
            capitalizeString(gPokemonDocs[i].egg_moves[j].category);
            gPokemonDocs[i].egg_moves[j].power = gBattleMoves[gPokemonDocs[i].egg_moves[j].num].power;
            gPokemonDocs[i].egg_moves[j].pp = gBattleMoves[gPokemonDocs[i].egg_moves[j].num].pp;
            gPokemonDocs[i].egg_moves[j].accuracy = gBattleMoves[gPokemonDocs[i].egg_moves[j].num].accuracy;
            gPokemonDocs[i].egg_moves[j].description = gMoveDescriptionPointers[gPokemonDocs[i].egg_moves[j].num - 1];
        }

        gPokemonDocs[i].numNextEvolutions = 0;
        gPokemonDocs[i].numFinalEvolutions = 0;

        for (u8 j = 0; j < EVOS_PER_MON; j++)
        {
            if (gEvolutionTable[i][j].method == EVO_NONE) break;

            gPokemonDocs[i].next_evolutions[j].num = gEvolutionTable[i][j].targetSpecies;
            strcpy(gPokemonDocs[i].next_evolutions[j].species_id, gSpeciesNames[gPokemonDocs[i].next_evolutions[j].num]);
            strcpy(gPokemonDocs[i].next_evolutions[j].name, gSpeciesNames[gPokemonDocs[i].next_evolutions[j].num]);
            capitalizeString(gPokemonDocs[i].next_evolutions[j].name);
            strcpy(gPokemonDocs[i].next_evolutions[j].method, gEvolutionMethodNames[gEvolutionTable[i][j].method]);
            
            switch(gEvolutionTable[i][j].method)
            {
                case EVO_TRADE_ITEM:
                case EVO_ITEM:
                    sprintf(gPokemonDocs[i].next_evolutions[j].parameter, "%s", gItems[gEvolutionTable[i][j].param].name);
                    break;
                case EVO_LEVEL_ATK_GT_DEF:
                case EVO_LEVEL_ATK_EQ_DEF:
                case EVO_LEVEL_ATK_LT_DEF:
                case EVO_LEVEL_SILCOON:
                case EVO_LEVEL_CASCOON:
                case EVO_LEVEL_NINJASK:
                case EVO_LEVEL_SHEDINJA:
                case EVO_LEVEL:
                    sprintf(gPokemonDocs[i].next_evolutions[j].parameter, "%d", gEvolutionTable[i][j].param);
                    break;
                case EVO_RENAME:
                    sprintf(gPokemonDocs[i].next_evolutions[j].parameter, "%s", gEvolutionRenameTable[i]);
                    break;
                case EVO_FRIENDSHIP:
                case EVO_FRIENDSHIP_DAY:
                case EVO_FRIENDSHIP_NIGHT:
                case EVO_TRADE:
                case EVO_BEAUTY:
                default:
                    strcpy(gPokemonDocs[i].next_evolutions[j].parameter, "");
                    break;
            }
            
            gPokemonDocs[i].numNextEvolutions++;
            

            // printf("%s evolves into %s via %s - %s\n", gPokemonDocs[i].name, gPokemonDocs[i].next_evolutions[j].name, gPokemonDocs[i].next_evolutions[j].method, gPokemonDocs[i].next_evolutions[j].parameter);
        }

        printPokemonDocData(gPokemonDocs[i]);
    }
    printf("\n]\n");

    return 0;
}

