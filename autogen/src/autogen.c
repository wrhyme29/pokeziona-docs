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

struct PokemonDocDataAbility
{
    u8 id[ABILITY_NAME_LENGTH + 1];
    u8 name[ABILITY_NAME_LENGTH + 1];
    u8 *description;
    u8 num;
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
    u8 num;
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
    struct PokemonDocDataMove level_up_moves[MAX_LEVEL_UP_MOVES];
    u8 numLevelUpMoves;
};

void printPokemonDocData(struct PokemonDocData monData)
{
    printf("{\n");
    printf("\t\"id\": \"%s\",\n", monData.id);
    printf("\t\"species_id\": \"%s\",\n", monData.species_id);
    printf("\t\"name\": \"%s\",\n", monData.name);
    printf("\t\"base_name\": \"%s\",\n", monData.base_name);
    printf("\t\"regional_dex_number\": %d,\n", monData.regional_dex_number);
    printf("\t\"national_dex_number\": %d,\n", monData.national_dex_number);
    
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
        printf("\t\t\t\"description\": \"%s\",\n", monData.abilities[i].description);
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
        printf("\t\t\t\t\"description\": \"%s\",\n", monData.level_up_moves[i].description);
        printf("\t\t\t}");
    }
    printf("\n");
    printf("\t\t]\n");

    printf("\t}\n");





    printf("},\n");
}

struct PokemonDocData gPokemonDocs[NUM_SPECIES] = {0};


int main()
{
    printf("[\n");
    for(u16 i = 0; i < NUM_SPECIES; i++)
    {
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
        
        printPokemonDocData(gPokemonDocs[i]);
    }
    printf("]\n");

    return 0;
}

