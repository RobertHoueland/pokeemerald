#include "global.h"
#include "event_data.h"
#include "research.h"
#include "string_util.h"
#include "constants/species.h"
#include "constants/vars.h"

#define RESEARCH_SAVE_VERSION_1 0x5201
#define RESEARCH_SAVE_VERSION_2 0x5202
#define RESEARCH_SAVE_VERSION_3 0x5203

STATIC_ASSERT(RESEARCH_MUTATION_POKERUS + 1 == RESEARCH_MUTATION_CATEGORY_COUNT, ResearchMutationCategoryCount);
STATIC_ASSERT(RESEARCH_PROTO_LINE_NECROZMA + 1 == RESEARCH_PROTO_LINE_COUNT, ResearchProtoLineCount);
STATIC_ASSERT(sizeof(struct ResearchMutationLogEntry) == 16, ResearchMutationLogEntrySize);
STATIC_ASSERT(offsetof(struct ResearchSaveData, recentMutationCount) == 72, ResearchSaveV1PrefixSize);
STATIC_ASSERT(offsetof(struct ResearchSaveData, recentMutationTimestamps) == 204, ResearchSaveV2PrefixSize);
STATIC_ASSERT(offsetof(struct ResearchSaveData, recentMutationLevels) == 236, ResearchSaveV3PrefixSize);
STATIC_ASSERT(sizeof(struct ResearchSaveData) == 244, ResearchSaveDataSize);

static void ClearRecentMutationLog(void)
{
    gSaveBlock1Ptr->research.recentMutationCount = 0;
    gSaveBlock1Ptr->research.recentMutationNext = 0;
    memset(gSaveBlock1Ptr->research.recentMutations, 0,
           sizeof(gSaveBlock1Ptr->research.recentMutations));
    memset(gSaveBlock1Ptr->research.recentMutationTimestamps, 0,
           sizeof(gSaveBlock1Ptr->research.recentMutationTimestamps));
    memset(gSaveBlock1Ptr->research.recentMutationLevels, 0,
           sizeof(gSaveBlock1Ptr->research.recentMutationLevels));
}

static void EnsureResearchDataInitialized(void)
{
    if (gSaveBlock1Ptr->research.formatVersion == RESEARCH_SAVE_VERSION)
    {
        // Recover only the log if a partially written save left its ring metadata invalid.
        if (gSaveBlock1Ptr->research.recentMutationCount > RESEARCH_RECENT_MUTATION_LOG_CAPACITY
         || gSaveBlock1Ptr->research.recentMutationNext >= RESEARCH_RECENT_MUTATION_LOG_CAPACITY)
            ClearRecentMutationLog();
        return;
    }

    // Older versions added fields at the end of the save data. Clear only those new
    // fields so the counters and registrations already present in the save survive.
    if (gSaveBlock1Ptr->research.formatVersion == RESEARCH_SAVE_VERSION_1)
        ClearRecentMutationLog();
    else if (gSaveBlock1Ptr->research.formatVersion == RESEARCH_SAVE_VERSION_2)
        memset(gSaveBlock1Ptr->research.recentMutationTimestamps, 0,
               sizeof(gSaveBlock1Ptr->research.recentMutationTimestamps));
    else if (gSaveBlock1Ptr->research.formatVersion == RESEARCH_SAVE_VERSION_3)
        memset(gSaveBlock1Ptr->research.recentMutationLevels, 0,
               sizeof(gSaveBlock1Ptr->research.recentMutationLevels));
    else
        memset(&gSaveBlock1Ptr->research, 0, sizeof(gSaveBlock1Ptr->research));

    gSaveBlock1Ptr->research.formatVersion = RESEARCH_SAVE_VERSION;
}

static void IncrementResearchCounter(u16 *counter)
{
    if (*counter != 0xFFFF)
        (*counter)++;
}

static enum ResearchMutationCategory GetResearchCategory(enum Mutation mutation)
{
    switch (mutation)
    {
    case MUTATION_CHOSEN_HP:
    case MUTATION_CHOSEN_ATK:
    case MUTATION_CHOSEN_DEF:
    case MUTATION_CHOSEN_SPATK:
    case MUTATION_CHOSEN_SPDEF:
    case MUTATION_CHOSEN_SPEED:
        return RESEARCH_MUTATION_STAT;
    case MUTATION_CHOSEN_TYPE:
        return RESEARCH_MUTATION_TYPE;
    case MUTATION_CHOSEN_ABILITY:
        return RESEARCH_MUTATION_ABILITY;
    case MUTATION_CHOSEN_NATURE:
        return RESEARCH_MUTATION_NATURE;
    case MUTATION_CHOSEN_MOVE:
        return RESEARCH_MUTATION_MOVE;
    case MUTATION_CHOSEN_FORM:
        return RESEARCH_MUTATION_FORM;
    case MUTATION_CHOSEN_SHINY:
        return RESEARCH_MUTATION_SHINY;
    case MUTATION_CHOSEN_POKERUS:
        return RESEARCH_MUTATION_POKERUS;
    case MUTATION_CHOSEN_NONE:
    default:
        return RESEARCH_MUTATION_CATEGORY_COUNT;
    }
}

static enum Stat GetResearchStat(enum Mutation mutation)
{
    switch (mutation)
    {
    case MUTATION_CHOSEN_HP:
        return STAT_HP;
    case MUTATION_CHOSEN_ATK:
        return STAT_ATK;
    case MUTATION_CHOSEN_DEF:
        return STAT_DEF;
    case MUTATION_CHOSEN_SPATK:
        return STAT_SPATK;
    case MUTATION_CHOSEN_SPDEF:
        return STAT_SPDEF;
    case MUTATION_CHOSEN_SPEED:
        return STAT_SPEED;
    default:
        return NUM_STATS;
    }
}

// Preserve the original save ordering while using the shared Stat enum
static u8 GetResearchStatIndex(enum Stat stat)
{
    static const u8 sStatIndexes[NUM_STATS] =
    {
        [STAT_HP] = 0,
        [STAT_ATK] = 1,
        [STAT_DEF] = 2,
        [STAT_SPATK] = 3,
        [STAT_SPDEF] = 4,
        [STAT_SPEED] = 5,
    };

    return sStatIndexes[stat];
}

static void AddRecentMutation(struct Pokemon *mon, enum Mutation mutation)
{
    struct ResearchMutationLogEntry *entry;

    if (mon == NULL)
        return;

    if (gSaveBlock1Ptr->research.recentMutationNext >= RESEARCH_RECENT_MUTATION_LOG_CAPACITY)
        gSaveBlock1Ptr->research.recentMutationNext = 0;
    if (gSaveBlock1Ptr->research.recentMutationCount > RESEARCH_RECENT_MUTATION_LOG_CAPACITY)
        gSaveBlock1Ptr->research.recentMutationCount = RESEARCH_RECENT_MUTATION_LOG_CAPACITY;

    entry = &gSaveBlock1Ptr->research.recentMutations[gSaveBlock1Ptr->research.recentMutationNext];
    entry->species = GetMonData(mon, MON_DATA_SPECIES);
    entry->mutation = mutation;
    GetMonData(mon, MON_DATA_NICKNAME, entry->nickname);
    StringGet_Nickname(entry->nickname);
    // Store play time + 1 so a legitimate timestamp of zero remains distinguishable
    // from the "zero" used by saves created before timestamps were added.
    gSaveBlock1Ptr->research.recentMutationTimestamps[gSaveBlock1Ptr->research.recentMutationNext]
        = (u32)gSaveBlock2Ptr->playTimeHours * 60 * 60
        + (u32)gSaveBlock2Ptr->playTimeMinutes * 60
        + gSaveBlock2Ptr->playTimeSeconds + 1;
    gSaveBlock1Ptr->research.recentMutationLevels[gSaveBlock1Ptr->research.recentMutationNext]
        = GetMonData(mon, MON_DATA_LEVEL);

    gSaveBlock1Ptr->research.recentMutationNext++;
    if (gSaveBlock1Ptr->research.recentMutationNext >= RESEARCH_RECENT_MUTATION_LOG_CAPACITY)
        gSaveBlock1Ptr->research.recentMutationNext = 0;
    if (gSaveBlock1Ptr->research.recentMutationCount < RESEARCH_RECENT_MUTATION_LOG_CAPACITY)
        gSaveBlock1Ptr->research.recentMutationCount++;
}

void Research_RecordMutation(struct Pokemon *mon, enum Mutation mutation)
{
    enum ResearchMutationCategory category = GetResearchCategory(mutation);
    enum Stat stat;

    if (category >= RESEARCH_MUTATION_CATEGORY_COUNT)
        return; // MUTATION_CHOSEN_NONE and invalid values are not successful mutations

    EnsureResearchDataInitialized();
    IncrementResearchCounter(&gSaveBlock1Ptr->research.lifetimeMutationTotal);
    IncrementResearchCounter(&gSaveBlock1Ptr->research.mutationCategoryCounts[category]);

    stat = GetResearchStat(mutation);
    if (stat < NUM_STATS)
        IncrementResearchCounter(&gSaveBlock1Ptr->research.statMutationCounts[GetResearchStatIndex(stat)]);
    AddRecentMutation(mon, mutation);
}

u16 Research_GetLifetimeMutationTotal(void)
{
    EnsureResearchDataInitialized();
    return gSaveBlock1Ptr->research.lifetimeMutationTotal;
}

u16 Research_GetMutationCategoryCount(enum ResearchMutationCategory category)
{
    EnsureResearchDataInitialized();
    if (category >= RESEARCH_MUTATION_CATEGORY_COUNT)
        return 0;
    return gSaveBlock1Ptr->research.mutationCategoryCounts[category];
}

u16 Research_GetStatMutationCount(enum Stat stat)
{
    EnsureResearchDataInitialized();
    if (stat >= NUM_STATS)
        return 0;
    return gSaveBlock1Ptr->research.statMutationCounts[GetResearchStatIndex(stat)];
}

u8 Research_GetDiscoveredMutationCount(void)
{
    u8 count = 0;
    u32 i;

    EnsureResearchDataInitialized();
    for (i = 0; i < RESEARCH_MUTATION_CATEGORY_COUNT; i++)
    {
        if (gSaveBlock1Ptr->research.mutationCategoryCounts[i] != 0)
            count++;
    }
    return count;
}

u8 Research_GetDiscoveredStatCount(void)
{
    u8 count = 0;
    u32 i;

    EnsureResearchDataInitialized();
    for (i = 0; i < NUM_STATS; i++)
    {
        if (gSaveBlock1Ptr->research.statMutationCounts[i] != 0)
            count++;
    }
    return count;
}

u8 Research_GetRecentMutationCount(void)
{
    EnsureResearchDataInitialized();
    return gSaveBlock1Ptr->research.recentMutationCount;
}

// recentMutationNext points to the next slot to overwrite, so walking backwards
// from it returns entries from newest to oldest.
static u8 GetRecentMutationSlot(u8 index)
{
    return (gSaveBlock1Ptr->research.recentMutationNext
          + RESEARCH_RECENT_MUTATION_LOG_CAPACITY - 1 - index)
          % RESEARCH_RECENT_MUTATION_LOG_CAPACITY;
}

const struct ResearchMutationLogEntry *Research_GetRecentMutation(u8 index)
{
    EnsureResearchDataInitialized();
    if (index >= gSaveBlock1Ptr->research.recentMutationCount)
        return NULL;

    return &gSaveBlock1Ptr->research.recentMutations[GetRecentMutationSlot(index)];
}

u32 Research_GetRecentMutationTimestamp(u8 index)
{
    u8 slot;

    EnsureResearchDataInitialized();
    if (index >= gSaveBlock1Ptr->research.recentMutationCount)
        return RESEARCH_TIMESTAMP_UNKNOWN;

    slot = GetRecentMutationSlot(index);
    if (gSaveBlock1Ptr->research.recentMutationTimestamps[slot] == 0)
        return RESEARCH_TIMESTAMP_UNKNOWN;
    return gSaveBlock1Ptr->research.recentMutationTimestamps[slot] - 1;
}

u8 Research_GetRecentMutationLevel(u8 index)
{
    EnsureResearchDataInitialized();
    if (index >= gSaveBlock1Ptr->research.recentMutationCount)
        return RESEARCH_LEVEL_UNKNOWN;

    return gSaveBlock1Ptr->research.recentMutationLevels[GetRecentMutationSlot(index)];
}

static enum ResearchProtoLine GetProtoLineForSpecies(u16 species)
{
    if (species == SPECIES_MEWTWO_V)
        return RESEARCH_PROTO_LINE_MEWTWO;
    if (species >= SPECIES_ARTICUNO_V && species <= SPECIES_MOLTRES_V)
        return RESEARCH_PROTO_LINE_BIRDS;
    if (species >= SPECIES_RAIKOU_V && species <= SPECIES_SUICUNE_V)
        return RESEARCH_PROTO_LINE_BEASTS;
    if (species >= SPECIES_LUGIA_V && species <= SPECIES_HO_OH_V)
        return RESEARCH_PROTO_LINE_TOWER;
    if (species >= SPECIES_REGIROCK_V && species <= SPECIES_REGISTEEL_V)
        return RESEARCH_PROTO_LINE_REGI;
    if (species >= SPECIES_LATIAS_V && species <= SPECIES_LATIOS_V)
        return RESEARCH_PROTO_LINE_EON;
    if (species >= SPECIES_KYOGRE_V && species <= SPECIES_RAYQUAZA_V)
        return RESEARCH_PROTO_LINE_WEATHER;
    if (species >= SPECIES_UXIE_V && species <= SPECIES_AZELF_V)
        return RESEARCH_PROTO_LINE_LAKE;
    if (species == SPECIES_DIALGA_V || species == SPECIES_PALKIA_V
     || species == SPECIES_DIALGA_V_ORIGIN || species == SPECIES_PALKIA_V_ORIGIN)
        return RESEARCH_PROTO_LINE_CREATION;
    if (species == SPECIES_GIRATINA_V_ALTERED || species == SPECIES_GIRATINA_V_ORIGIN)
        return RESEARCH_PROTO_LINE_DISTORTION;
    if (species >= SPECIES_HEATRAN_V && species <= SPECIES_CRESSELIA_V)
        return RESEARCH_PROTO_LINE_RELIC;
    if (species >= SPECIES_COBALION_V && species <= SPECIES_VIRIZION_V)
        return RESEARCH_PROTO_LINE_SWORDS;
    if (species >= SPECIES_TORNADUS_V_INCARNATE && species <= SPECIES_LANDORUS_V_THERIAN)
        return RESEARCH_PROTO_LINE_FORCES;
    if (species >= SPECIES_RESHIRAM_V && species <= SPECIES_ZEKROM_V)
        return RESEARCH_PROTO_LINE_TAO;
    if (species == SPECIES_KYUREM_V || species == SPECIES_KYUREM_V_WHITE || species == SPECIES_KYUREM_V_BLACK)
        return RESEARCH_PROTO_LINE_KYUREM;
    if (species >= SPECIES_XERNEAS_V_NEUTRAL && species <= SPECIES_ZYGARDE_V)
        return RESEARCH_PROTO_LINE_AURA;
    if (species >= SPECIES_TAPU_KOKO_V && species <= SPECIES_TAPU_FINI_V)
        return RESEARCH_PROTO_LINE_TAPU;
    if (species >= SPECIES_TYPE_NULL_V && species <= SPECIES_SILVALLY_V_FAIRY)
        return RESEARCH_PROTO_LINE_TYPE_NULL;
    if (species >= SPECIES_COSMOG_V && species <= SPECIES_LUNALA_V)
        return RESEARCH_PROTO_LINE_COSMOG;
    if (species == SPECIES_NECROZMA_V
     || species == SPECIES_NECROZMA_V_DUSK_MANE
     || species == SPECIES_NECROZMA_V_DAWN_WINGS)
        return RESEARCH_PROTO_LINE_NECROZMA;
    return RESEARCH_PROTO_LINE_COUNT;
}

bool8 Research_RegisterProtoLegend(u16 species)
{
    enum ResearchProtoLine line = GetProtoLineForSpecies(species);
    if (line >= RESEARCH_PROTO_LINE_COUNT)
        return FALSE;

    EnsureResearchDataInitialized();
    // Keep the first exact species obtained for a line
    if (gSaveBlock1Ptr->research.protoLegendSpecies[line] == SPECIES_NONE)
        gSaveBlock1Ptr->research.protoLegendSpecies[line] = species;
    return TRUE;
}

u16 Research_GetRegisteredProtoSpecies(enum ResearchProtoLine line)
{
    EnsureResearchDataInitialized();
    if (line >= RESEARCH_PROTO_LINE_COUNT)
        return SPECIES_NONE;
    return gSaveBlock1Ptr->research.protoLegendSpecies[line];
}

u8 Research_GetRegisteredProtoLineCount(void)
{
    u8 count = 0;
    u32 i;

    EnsureResearchDataInitialized();
    for (i = 0; i < RESEARCH_PROTO_LINE_COUNT; i++)
    {
        if (gSaveBlock1Ptr->research.protoLegendSpecies[i] != SPECIES_NONE)
            count++;
    }
    return count;
}

void Script_RegisterProtoLegend(void)
{
    Research_RegisterProtoLegend(VarGet(VAR_TEMP_TRANSFERRED_SPECIES));
}
