#include "global.h"
#include "event_data.h"
#include "field_message_box.h"
#include "pokedex.h"
#include "strings.h"
#include "string_util.h"
#include "battle_main.h"

bool16 ScriptGetPokedexInfo(void)
{
    if (gSpecialVar_0x8004 == 0) // is national dex not present?
    {
        gSpecialVar_0x8005 = GetHoennPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetHoennPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }

    return IsNationalPokedexEnabled();
}

#define BIRCH_DEX_STRINGS 21

static const u8 *const sBirchDexRatingTexts[BIRCH_DEX_STRINGS] =
{
    gBirchDexRatingText_LessThan10,
    gBirchDexRatingText_LessThan20,
    gBirchDexRatingText_LessThan30,
    gBirchDexRatingText_LessThan40,
    gBirchDexRatingText_LessThan50,
    gBirchDexRatingText_LessThan60,
    gBirchDexRatingText_LessThan70,
    gBirchDexRatingText_LessThan80,
    gBirchDexRatingText_LessThan90,
    gBirchDexRatingText_LessThan100,
    gBirchDexRatingText_LessThan110,
    gBirchDexRatingText_LessThan120,
    gBirchDexRatingText_LessThan130,
    gBirchDexRatingText_LessThan140,
    gBirchDexRatingText_LessThan150,
    gBirchDexRatingText_LessThan160,
    gBirchDexRatingText_LessThan170,
    gBirchDexRatingText_LessThan180,
    gBirchDexRatingText_LessThan190,
    gBirchDexRatingText_LessThan200,
    gBirchDexRatingText_DexCompleted,
};

// This shows your Hoenn Pokédex rating and not your National Dex.
const u8 *GetPokedexRatingText(u32 count)
{
    u32 i, j;
    u16 maxDex = HOENN_DEX_COUNT - 1;
    // doesNotCountForRegionalPokedex
    for(i = 0; i < HOENN_DEX_COUNT; i++)
    {
        j = NationalPokedexNumToSpecies(HoennToNationalOrder(i + 1));
        if (gSpeciesInfo[j].isMythical && !gSpeciesInfo[j].dexForceRequired)
        {
            if (GetSetPokedexFlag(j, FLAG_GET_CAUGHT))
                count--;
            maxDex--;
        }
    }
    return sBirchDexRatingTexts[(count * (BIRCH_DEX_STRINGS - 1)) / maxDex];
}

void ShowPokedexRatingMessage(void)
{
    ShowFieldMessage(GetPokedexRatingText(gSpecialVar_0x8004));
}

static const u16 sMemoryItems[NUMBER_OF_MON_TYPES] = {
    [TYPE_FIGHTING] = ITEM_FIGHTING_MEMORY,
    [TYPE_FLYING]   = ITEM_FLYING_MEMORY,
    [TYPE_POISON]   = ITEM_POISON_MEMORY,
    [TYPE_GROUND]   = ITEM_GROUND_MEMORY,
    [TYPE_ROCK]     = ITEM_ROCK_MEMORY,
    [TYPE_BUG]      = ITEM_BUG_MEMORY,
    [TYPE_GHOST]    = ITEM_GHOST_MEMORY,
    [TYPE_STEEL]    = ITEM_STEEL_MEMORY,
    [TYPE_FIRE]     = ITEM_FIRE_MEMORY,
    [TYPE_WATER]    = ITEM_WATER_MEMORY,
    [TYPE_GRASS]    = ITEM_GRASS_MEMORY,
    [TYPE_ELECTRIC] = ITEM_ELECTRIC_MEMORY,
    [TYPE_PSYCHIC]  = ITEM_PSYCHIC_MEMORY,
    [TYPE_ICE]      = ITEM_ICE_MEMORY,
    [TYPE_DRAGON]   = ITEM_DRAGON_MEMORY,
    [TYPE_DARK]     = ITEM_DARK_MEMORY,
    [TYPE_FAIRY]    = ITEM_FAIRY_MEMORY,
};

static const u16 sMemoryFlags[NUMBER_OF_MON_TYPES] = {
    [TYPE_FIGHTING] = FLAG_RECEIVED_FIGHTING_MEMORY,
    [TYPE_FLYING]   = FLAG_RECEIVED_FLYING_MEMORY,
    [TYPE_POISON]   = FLAG_RECEIVED_POISON_MEMORY,
    [TYPE_GROUND]   = FLAG_RECEIVED_GROUND_MEMORY,
    [TYPE_ROCK]     = FLAG_RECEIVED_ROCK_MEMORY,
    [TYPE_BUG]      = FLAG_RECEIVED_BUG_MEMORY,
    [TYPE_GHOST]    = FLAG_RECEIVED_GHOST_MEMORY,
    [TYPE_STEEL]    = FLAG_RECEIVED_STEEL_MEMORY,
    [TYPE_FIRE]     = FLAG_RECEIVED_FIRE_MEMORY,
    [TYPE_WATER]    = FLAG_RECEIVED_WATER_MEMORY,
    [TYPE_GRASS]    = FLAG_RECEIVED_GRASS_MEMORY,
    [TYPE_ELECTRIC] = FLAG_RECEIVED_ELECTRIC_MEMORY,
    [TYPE_PSYCHIC]  = FLAG_RECEIVED_PSYCHIC_MEMORY,
    [TYPE_ICE]      = FLAG_RECEIVED_ICE_MEMORY,
    [TYPE_DRAGON]   = FLAG_RECEIVED_DRAGON_MEMORY,
    [TYPE_DARK]     = FLAG_RECEIVED_DARK_MEMORY,
    [TYPE_FAIRY]    = FLAG_RECEIVED_FAIRY_MEMORY,
};

u16 GetNextMemoryItemToGive(void)
{
    u32 i;
    u16 typeCounts[NUMBER_OF_MON_TYPES] = {0};

    // Count registered types
    for (i = 1; i < NUM_SPECIES; i++)
    {
        // Only caught mons count
        if (GetSetPokedexFlag(i, FLAG_GET_CAUGHT))
        {
            u16 type1 = gSpeciesInfo[i].types[0];
            u16 type2 = gSpeciesInfo[i].types[1];

            if (type1 < NUMBER_OF_MON_TYPES)
            {
                typeCounts[type1]++;
            }
            
            if (type1 != type2 && type2 < NUMBER_OF_MON_TYPES)
            {
                typeCounts[type2]++;
            }
        }
    }

    // Check if we can give a memory (>= 5 registered and not already given)
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (sMemoryItems[i] != 0 && sMemoryItems[i] != ITEM_NONE)
        {
            if (typeCounts[i] >= 5 && !FlagGet(sMemoryFlags[i]))
            {
                gSpecialVar_0x8005 = i;
                return sMemoryItems[i];
            }
        }
    }

    return ITEM_NONE;
}

void BufferNextMemoryItemType(void)
{
    StringCopy(gStringVar1, gTypesInfo[gSpecialVar_0x8005].name);
}

bool16 SetNextMemoryItemFlag(void)
{
    u32 i;
    u16 typeCounts[NUMBER_OF_MON_TYPES] = {0};

    for (i = 1; i < NUM_SPECIES; i++)
    {
        if (GetSetPokedexFlag(i, FLAG_GET_CAUGHT))
        {
            u16 type1 = gSpeciesInfo[i].types[0];
            u16 type2 = gSpeciesInfo[i].types[1];

            if (type1 < NUMBER_OF_MON_TYPES)
                typeCounts[type1]++;
            
            if (type1 != type2 && type2 < NUMBER_OF_MON_TYPES)
                typeCounts[type2]++;
        }
    }

    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (sMemoryItems[i] != 0 && sMemoryItems[i] != ITEM_NONE)
        {
            if (typeCounts[i] >= 5 && !FlagGet(sMemoryFlags[i]))
            {
                FlagSet(sMemoryFlags[i]);
                return TRUE;
            }
        }
    }

    return FALSE;
}

bool16 CheckHasAllMemories(void)
{
    // Check if player has recieved all memory types for Silvally
    u32 i;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (sMemoryItems[i] != 0 && sMemoryItems[i] != ITEM_NONE)
        {
            if (!FlagGet(sMemoryFlags[i]))
            {
                return FALSE;
            }
        }
    }
    return TRUE;
}

