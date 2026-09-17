#ifndef GUARD_RESEARCH_H
#define GUARD_RESEARCH_H

#include "pokemon.h"
#include "constants/research.h"

enum ResearchMutationCategory
{
    RESEARCH_MUTATION_STAT,
    RESEARCH_MUTATION_TYPE,
    RESEARCH_MUTATION_ABILITY,
    RESEARCH_MUTATION_NATURE,
    RESEARCH_MUTATION_MOVE,
    RESEARCH_MUTATION_FORM,
    RESEARCH_MUTATION_SHINY,
    RESEARCH_MUTATION_POKERUS,
};

enum ResearchProtoLine
{
    RESEARCH_PROTO_LINE_MEWTWO,
    RESEARCH_PROTO_LINE_BIRDS,
    RESEARCH_PROTO_LINE_BEASTS,
    RESEARCH_PROTO_LINE_TOWER,
    RESEARCH_PROTO_LINE_REGI,
    RESEARCH_PROTO_LINE_EON,
    RESEARCH_PROTO_LINE_WEATHER,
    RESEARCH_PROTO_LINE_LAKE,
    RESEARCH_PROTO_LINE_CREATION,
    RESEARCH_PROTO_LINE_DISTORTION,
    RESEARCH_PROTO_LINE_RELIC,
    RESEARCH_PROTO_LINE_SWORDS,
    RESEARCH_PROTO_LINE_FORCES,
    RESEARCH_PROTO_LINE_TAO,
    RESEARCH_PROTO_LINE_KYUREM,
    RESEARCH_PROTO_LINE_AURA,
    RESEARCH_PROTO_LINE_TAPU,
    RESEARCH_PROTO_LINE_TYPE_NULL,
    RESEARCH_PROTO_LINE_COSMOG,
    RESEARCH_PROTO_LINE_NECROZMA,
};

void Research_RecordMutation(struct Pokemon *mon, enum Mutation mutation);
u16 Research_GetLifetimeMutationTotal(void);
u16 Research_GetMutationCategoryCount(enum ResearchMutationCategory category);
u16 Research_GetStatMutationCount(enum Stat stat);
u8 Research_GetDiscoveredMutationCount(void);
u8 Research_GetDiscoveredStatCount(void);
u8 Research_GetRecentMutationCount(void);
const struct ResearchMutationLogEntry *Research_GetRecentMutation(u8 index);
u32 Research_GetRecentMutationTimestamp(u8 index);
u8 Research_GetRecentMutationLevel(u8 index);

bool8 Research_RegisterProtoLegend(u16 species);
u16 Research_GetRegisteredProtoSpecies(enum ResearchProtoLine line);
u8 Research_GetRegisteredProtoLineCount(void);
void Script_RegisterProtoLegend(void);

void CB2_InitResearchScreen(void);

#endif // GUARD_RESEARCH_H
