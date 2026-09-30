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
        gSpecialVar_0x8005 = GetRegionalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetRegionalPokedexCount(FLAG_GET_CAUGHT);
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
    u16 maxDex = REGIONAL_DEX_COUNT - 1;
    // doesNotCountForRegionalPokedex
    for (i = 0; i < REGIONAL_DEX_COUNT; i++)
    {
        j = NationalPokedexNumToSpecies(RegionalToNationalOrder(i + 1));
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

// FRLG
extern const u8 PokedexRating_Text_LessThan10[];
extern const u8 PokedexRating_Text_LessThan20[];
extern const u8 PokedexRating_Text_LessThan30[];
extern const u8 PokedexRating_Text_LessThan40[];
extern const u8 PokedexRating_Text_LessThan50[];
extern const u8 PokedexRating_Text_LessThan60[];
extern const u8 PokedexRating_Text_LessThan70[];
extern const u8 PokedexRating_Text_LessThan80[];
extern const u8 PokedexRating_Text_LessThan90[];
extern const u8 PokedexRating_Text_LessThan100[];
extern const u8 PokedexRating_Text_LessThan110[];
extern const u8 PokedexRating_Text_LessThan120[];
extern const u8 PokedexRating_Text_LessThan130[];
extern const u8 PokedexRating_Text_LessThan140[];
extern const u8 PokedexRating_Text_LessThan150[];
extern const u8 PokedexRating_Text_Complete[];

u16 GetFrlgPokedexCount(void)
{
    if (gSpecialVar_0x8004 == 0)
    {
        gSpecialVar_0x8005 = GetKantoPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetKantoPokedexCount(FLAG_GET_CAUGHT);
    }
    else
    {
        gSpecialVar_0x8005 = GetNationalPokedexCount(FLAG_GET_SEEN);
        gSpecialVar_0x8006 = GetNationalPokedexCount(FLAG_GET_CAUGHT);
    }
    return IsNationalPokedexEnabled();
}

static const u8 *GetProfOaksRatingMessageByCount(u16 count)
{
    gSpecialVar_Result = FALSE;

    if (count > 0 && GetSetPokedexFlag(NATIONAL_DEX_MEW, FLAG_GET_CAUGHT))
        count--;

    if (count < 10)
        return PokedexRating_Text_LessThan10;

    if (count < 20)
        return PokedexRating_Text_LessThan20;

    if (count < 30)
        return PokedexRating_Text_LessThan30;

    if (count < 40)
        return PokedexRating_Text_LessThan40;

    if (count < 50)
        return PokedexRating_Text_LessThan50;

    if (count < 60)
        return PokedexRating_Text_LessThan60;

    if (count < 70)
        return PokedexRating_Text_LessThan70;

    if (count < 80)
        return PokedexRating_Text_LessThan80;

    if (count < 90)
        return PokedexRating_Text_LessThan90;

    if (count < 100)
        return PokedexRating_Text_LessThan100;

    if (count < 110)
        return PokedexRating_Text_LessThan110;

    if (count < 120)
        return PokedexRating_Text_LessThan120;

    if (count < 130)
        return PokedexRating_Text_LessThan130;

    if (count < 140)
        return PokedexRating_Text_LessThan140;

    if (count < KANTO_DEX_COUNT - 1)
        return PokedexRating_Text_LessThan150;

    gSpecialVar_Result = TRUE;
    return PokedexRating_Text_Complete;
}

void GetProfOaksRatingMessage(void)
{
    ShowFieldMessage(GetProfOaksRatingMessageByCount(gSpecialVar_0x8004));
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

