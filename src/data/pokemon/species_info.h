#include "constants/abilities.h"
#include "constants/teaching_types.h"
#include "species_info/shared_dex_text.h"
#include "species_info/shared_front_pic_anims.h"

// Macros for ease of use.

#define EVOLUTION(...) (const struct Evolution[]) { __VA_ARGS__, { EVOLUTIONS_END }, }
#define CONDITIONS(...) ((const struct EvolutionParam[]) { __VA_ARGS__, {CONDITIONS_END} })

#define ANIM_FRAMES(...) (const union AnimCmd *const[]) { sAnim_GeneralFrame0, (const union AnimCmd[]) { __VA_ARGS__ ANIMCMD_END, }, }

#if P_FOOTPRINTS
#define FOOTPRINT(sprite) .footprint = gMonFootprint_## sprite,
#else
#define FOOTPRINT(sprite)
#endif

#if B_ENEMY_MON_SHADOW_STYLE >= GEN_4 && P_GBA_STYLE_SPECIES_GFX == FALSE
#define SHADOW(x, y, size)  .enemyShadowXOffset = x, .enemyShadowYOffset = y, .enemyShadowSize = size,
#define NO_SHADOW           .suppressEnemyShadow = TRUE,
#else
#define SHADOW(x, y, size)  .enemyShadowXOffset = 0, .enemyShadowYOffset = 0, .enemyShadowSize = 0,
#define NO_SHADOW           .suppressEnemyShadow = FALSE,
#endif

#define SIZE_32x32 1
#define SIZE_64x64 0

// Set .compressed = OW_GFX_COMPRESS
#define COMP OW_GFX_COMPRESS

#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
#define OVERWORLD_PAL(...)                                  \
    .overworldPalette = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPalette = DEFAULT_2(NULL, __VA_ARGS__),
#if P_GENDER_DIFFERENCES
#define OVERWORLD_PAL_FEMALE(...)                                 \
    .overworldPaletteFemale = DEFAULT(NULL, __VA_ARGS__),         \
    .overworldShinyPaletteFemale = DEFAULT_2(NULL, __VA_ARGS__),
#else
#define OVERWORLD_PAL_FEMALE(...)
#endif //P_GENDER_DIFFERENCES
#else
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE

#define OVERWORLD_DATA(picTable, _size, shadow, _tracks, _anims)                                                                     \
{                                                                                                                                       \
    .tileTag = TAG_NONE,                                                                                                                \
    .paletteTag = OBJ_EVENT_PAL_TAG_DYNAMIC,                                                                                            \
    .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,                                                                                     \
    .size = (_size == SIZE_32x32 ? 512 : 2048),                                                                                         \
    .width = (_size == SIZE_32x32 ? 32 : 64),                                                                                           \
    .height = (_size == SIZE_32x32 ? 32 : 64),                                                                                          \
    .paletteSlot = PALSLOT_NPC_1,                                                                                                       \
    .shadowSize = shadow,                                                                                                               \
    .inanimate = FALSE,                                                                                                                 \
    .compressed = COMP,                                                                                                                 \
    .tracks = _tracks,                                                                                                                  \
    .oam = (_size == SIZE_32x32 ? &gObjectEventBaseOam_32x32 : &gObjectEventBaseOam_64x64),                                             \
    .subspriteTables = (_size == SIZE_32x32 ? sOamTables_32x32 : sOamTables_64x64),                                                     \
    .anims = _anims,                                                                                                                    \
    .images = picTable,                                                                                                                 \
}

#define OVERWORLD(objEventPic, _size, shadow, _tracks, _anims, ...)                                 \
    .overworldData = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),                   \
    OVERWORLD_PAL(__VA_ARGS__)

#if P_GENDER_DIFFERENCES
#define OVERWORLD_FEMALE(objEventPic, _size, shadow, _tracks, _anims, ...)                          \
    .overworldDataFemale = OVERWORLD_DATA(objEventPic, _size, shadow, _tracks, _anims),             \
    OVERWORLD_PAL_FEMALE(__VA_ARGS__)
#else
#define OVERWORLD_FEMALE(...)
#endif //P_GENDER_DIFFERENCES

#else
#define OVERWORLD(...)
#define OVERWORLD_FEMALE(...)
#define OVERWORLD_PAL(...)
#define OVERWORLD_PAL_FEMALE(...)
#endif //OW_POKEMON_OBJECT_EVENTS

// Maximum value for a female Pokémon is 254 (MON_FEMALE) which is 100% female.
// 255 (MON_GENDERLESS) is reserved for genderless Pokémon.
#define PERCENT_FEMALE(percent) min(254, ((percent * 255) / 100))

#define MON_TYPES(type1, ...) { type1, DEFAULT(type1, __VA_ARGS__) }
#define MON_EGG_GROUPS(group1, ...) { group1, DEFAULT(group1, __VA_ARGS__) }

#define FLIP    0
#define NO_FLIP 1

const struct SpeciesInfo gSpeciesInfo[] =
{
    [SPECIES_NONE] =
    {
        .speciesName = _("??????????"),
        .cryId = CRY_PORYGON,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = gFallbackPokedexText,
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        FOOTPRINT(QuestionMark)
        SHADOW(-1, 0, SHADOW_SIZE_M)
    #if OW_POKEMON_OBJECT_EVENTS
        .overworldData = {
            .tileTag = TAG_NONE,
            .paletteTag = OBJ_EVENT_PAL_TAG_SUBSTITUTE,
            .reflectionPaletteTag = OBJ_EVENT_PAL_TAG_NONE,
            .size = 512,
            .width = 32,
            .height = 32,
            .paletteSlot = PALSLOT_NPC_1,
            .shadowSize = SHADOW_SIZE_M,
            .inanimate = FALSE,
            .compressed = COMP,
            .tracks = TRACKS_FOOT,
            .oam = &gObjectEventBaseOam_32x32,
            .subspriteTables = sOamTables_32x32,
            .anims = sAnimTable_Following,
            .images = sPicTable_Substitute,
        },
    #endif
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .eggMoveLearnset = sNoneEggMoveLearnset,
    },

    #include "species_info/gen_1_families.h"
    #include "species_info/gen_2_families.h"
    #include "species_info/gen_3_families.h"
    #include "species_info/gen_4_families.h"
    #include "species_info/gen_5_families.h"
    #include "species_info/gen_6_families.h"
    #include "species_info/gen_7_families.h"
    #include "species_info/gen_8_families.h"
    #include "species_info/gen_9_families.h"

    [SPECIES_EGG] =
    {
        .frontPic = gMonFrontPic_Egg,
        .frontPicSize = MON_COORDS_SIZE(24, 24),
        .frontPicYOffset = 20,
        .backPic = gMonFrontPic_Egg,
        .backPicSize = MON_COORDS_SIZE(24, 24),
        .backPicYOffset = 20,
        .palette = gMonPalette_Egg,
        .shinyPalette = gMonPalette_Egg,
        .iconSprite = gMonIcon_Egg,
        .iconPalIndex = 1,
    },

    //
    // Mini legendaries had their stats lowered to 475 BST
    // Each stat was lowered by a percentage to achieve this
    // Sizes and weights were lowered by the same percentage
    //

    [SPECIES_MEWTWO_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 74,   // was 106
        .baseAttack    = 77,   // was 110
        .baseDefense   = 63,   // was 90
        .baseSpeed     = 91,   // was 130
        .baseSpAttack  = 107,  // was 154
        .baseSpDefense = 63,   // was 90
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INNER_FOCUS, ABILITY_NONE, ABILITY_NEUROFORCE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Mewtwo-V"),
        .cryId = CRY_MEWTWO,
        .natDexNum = NATIONAL_DEX_MEWTWO_V,
        .categoryName = _("Genetic"),
        .height = 14,   // was 20
        .weight = 854,  // was 1220
        .description = COMPOUND_STRING(
            "Created from carefully tempered genes,\n"
            "it lacks the cruelty of its predecessor.\n"
            "Its immense psychic power stirs only\n"
            "when those it trusts are threatened."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 5,   // was 0
        .trainerScale = 309,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Mewtwo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Mewtwo,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Mewtwo,
        .shinyPalette = gMonShinyPalette_Mewtwo,
        .iconSprite = gMonIcon_Mewtwo,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(6, 12, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Mewtwo)
        OVERWORLD(
            sPicTable_Mewtwo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mewtwo,
            gShinyOverworldPalette_Mewtwo
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sMewtwoLevelUpLearnset,
        .teachableLearnset = sMewtwoTeachableLearnset,
    },

    [SPECIES_ARTICUNO_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 73,   // was 90
        .baseAttack    = 70,   // was 85
        .baseDefense   = 82,   // was 100
        .baseSpeed     = 70,   // was 85
        .baseSpAttack  = 78,   // was 95
        .baseSpDefense = 102,  // was 125
        .types = MON_TYPES(TYPE_ICE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ICE_BODY, ABILITY_NONE, ABILITY_SNOW_CLOAK },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Articuno-V"),
        .cryId = CRY_ARTICUNO,
        .natDexNum = NATIONAL_DEX_ARTICUNO_V,
        .categoryName = _("Freeze"),
        .height = 14,   // was 17
        .weight = 454,  // was 554
        .description = COMPOUND_STRING(
            "Reconstructed genes let its wings seed\n"
            "the air with glittering diamond dust.\n"
            "It cannot summon a blizzard for long,\n"
            "but snow lingers wherever it rests."),
        .pokemonScale = 351,  // was 270
        .pokemonOffset = 6,   // was 0
        .trainerScale = 309,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Articuno,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 25),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 0,
        .backPic = gMonBackPic_Articuno,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(48, 40) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 12 : 5,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Articuno,
        .shinyPalette = gMonShinyPalette_Articuno,
        .iconSprite = gMonIcon_Articuno,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_M)
        FOOTPRINT(Articuno)
        OVERWORLD(
            sPicTable_Articuno,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Articuno,
            gShinyOverworldPalette_Articuno
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sArticunoLevelUpLearnset,
        .teachableLearnset = sArticunoTeachableLearnset,
    },

    [SPECIES_ZAPDOS_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 73,   // was 90
        .baseAttack    = 74,   // was 90
        .baseDefense   = 70,   // was 85
        .baseSpeed     = 82,   // was 100
        .baseSpAttack  = 102,  // was 125
        .baseSpDefense = 74,   // was 90
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_RATTLED, ABILITY_NONE, ABILITY_STATIC },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Zapdos-V"),
        .cryId = CRY_ZAPDOS,
        .natDexNum = NATIONAL_DEX_ZAPDOS_V,
        .categoryName = _("Electric"),
        .height = 13,   // was 16
        .weight = 431,  // was 526
        .description = COMPOUND_STRING(
            "Static leaks from its unstable feathers,\n"
            "drawing dark thunderclouds overhead.\n"
            "A direct lightning strike restores the\n"
            "energy its small frame quickly spends."),
        .pokemonScale = 351,  // was 270
        .pokemonOffset = 7,   // was 0
        .trainerScale = 318,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Zapdos,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_FLASH_YELLOW,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_Zapdos,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 48) : MON_COORDS_SIZE(64, 40),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 11 : 12,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Zapdos,
        .shinyPalette = gMonShinyPalette_Zapdos,
        .iconSprite = gMonIcon_Zapdos,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 15, SHADOW_SIZE_M)
        FOOTPRINT(Zapdos)
        OVERWORLD(
            sPicTable_Zapdos,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Zapdos,
            gShinyOverworldPalette_Zapdos
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sZapdosLevelUpLearnset,
        .teachableLearnset = sZapdosTeachableLearnset,
    },

    [SPECIES_MOLTRES_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 73,   // was 90
        .baseAttack    = 82,   // was 100
        .baseDefense   = 74,   // was 90
        .baseSpeed     = 74,   // was 90
        .baseSpAttack  = 102,  // was 125
        .baseSpDefense = 70,   // was 85
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Moltres-V"),
        .cryId = CRY_MOLTRES,
        .natDexNum = NATIONAL_DEX_MOLTRES_V,
        .categoryName = _("Flame"),
        .height = 16,   // was 20
        .weight = 491,  // was 600
        .description = COMPOUND_STRING(
            "Fragments of legendary DNA keep its\n"
            "wings alight with tireless flames.\n"
            "When wounded, it bathes in magma and\n"
            "emerges with its bright plumage restored."),
        .pokemonScale = 351,  // was 270
        .pokemonOffset = 6,   // was 0
        .trainerScale = 387,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Moltres,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
            ANIMCMD_FRAME(1, 3),
            ANIMCMD_FRAME(0, 3),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 5 : 0,
        .backPic = gMonBackPic_Moltres,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 5,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Moltres,
        .shinyPalette = gMonShinyPalette_Moltres,
        .iconSprite = gMonIcon_Moltres,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Moltres)
        OVERWORLD(
            sPicTable_Moltres,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Moltres,
            gShinyOverworldPalette_Moltres
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sMoltresLevelUpLearnset,
        .teachableLearnset = sMoltresTeachableLearnset,
    },

    [SPECIES_RAIKOU_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 74,   // was 90
        .baseAttack    = 70,   // was 85
        .baseDefense   = 61,   // was 75
        .baseSpeed     = 94,   // was 115
        .baseSpAttack  = 94,   // was 115
        .baseSpDefense = 82,   // was 100
        .types = MON_TYPES(TYPE_ELECTRIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_Speed = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_VOLT_ABSORB, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Raikou-V"),
        .cryId = CRY_RAIKOU,
        .natDexNum = NATIONAL_DEX_RAIKOU_V,
        .categoryName = _("Thunder"),
        .height = 16,   // was 19
        .weight = 1458, // was 1780
        .description = COMPOUND_STRING(
            "Electricity races through its unstable\n"
            "muscles, giving it astonishing speed.\n"
            "Its roar arrives with a thunderclap that\n"
            "rattles windows far beyond its path."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 9,   // was 0
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Raikou,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FLASH_YELLOW : ANIM_V_STRETCH,
        .backPic = gMonBackPic_Raikou,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 10 : 6,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_Raikou,
        .shinyPalette = gMonShinyPalette_Raikou,
        .iconSprite = gMonIcon_Raikou,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-4, 7, SHADOW_SIZE_L)
        FOOTPRINT(Raikou)
        OVERWORLD(
            sPicTable_Raikou,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Raikou,
            gShinyOverworldPalette_Raikou
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRaikouLevelUpLearnset,
        .teachableLearnset = sRaikouTeachableLearnset,
    },

    [SPECIES_ENTEI_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 94,   // was 115
        .baseAttack    = 94,   // was 115
        .baseDefense   = 70,   // was 85
        .baseSpeed     = 82,   // was 100
        .baseSpAttack  = 74,   // was 90
        .baseSpDefense = 61,   // was 75
        .types = MON_TYPES(TYPE_FIRE),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_HP = 1,
        .evYield_Attack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Entei-V"),
        .cryId = CRY_ENTEI,
        .natDexNum = NATIONAL_DEX_ENTEI_V,
        .categoryName = _("Volcano"),
        .height = 17,   // was 21
        .weight = 1622, // was 1980
        .description = COMPOUND_STRING(
            "Stabilized at volcanic temperatures,\n"
            "its body grows hotter when excited.\n"
            "Every forceful bark spits sparks and\n"
            "makes the ground beneath its paws steam."),
        .pokemonScale = 337,  // was 259
        .pokemonOffset = 7,   // was 0
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Entei,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Entei,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 6 : 11,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Entei,
        .shinyPalette = gMonShinyPalette_Entei,
        .iconSprite = gMonIcon_Entei,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 8, SHADOW_SIZE_L)
        FOOTPRINT(Entei)
        OVERWORLD(
            sPicTable_Entei,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Entei,
            gShinyOverworldPalette_Entei
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sEnteiLevelUpLearnset,
        .teachableLearnset = sEnteiTeachableLearnset,
    },

    [SPECIES_SUICUNE_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 82,   // was 100
        .baseAttack    = 61,   // was 75
        .baseDefense   = 94,   // was 115
        .baseSpeed     = 70,   // was 85
        .baseSpAttack  = 74,   // was 90
        .baseSpDefense = 94,   // was 115
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_Defense = 1,
        .evYield_SpDefense = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_WATER_ABSORB, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Suicune-V"),
        .cryId = CRY_SUICUNE,
        .natDexNum = NATIONAL_DEX_SUICUNE_V,
        .categoryName = _("Aurora"),
        .height = 16,   // was 20
        .weight = 1532, // was 1870
        .description = COMPOUND_STRING(
            "Engineered to mimic a northern wind,\n"
            "it glides across the ground without sound.\n"
            "Even polluted water turns crystal clear\n"
            "after a brush from its flowing ribbons."),
        .pokemonScale = 337,  // was 269
        .pokemonOffset = 7,   // was 0
        .trainerScale = 345,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Suicune,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 0 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Suicune,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Suicune,
        .shinyPalette = gMonShinyPalette_Suicune,
        .iconSprite = gMonIcon_Suicune,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 0 : 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Suicune)
        OVERWORLD(
            sPicTable_Suicune,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Suicune,
            gShinyOverworldPalette_Suicune
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sSuicuneLevelUpLearnset,
        .teachableLearnset = sSuicuneTeachableLearnset,
    },

    [SPECIES_LUGIA_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 74,   // was 106
        .baseAttack    = 63,   // was 90
        .baseDefense   = 91,   // was 130
        .baseSpeed     = 77,   // was 110
        .baseSpAttack  = 63,   // was 90
        .baseSpDefense = 107,  // was 154
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CLOUD_NINE, ABILITY_NONE, ABILITY_MULTISCALE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Lugia-V"),
        .cryId = CRY_LUGIA,
        .natDexNum = NATIONAL_DEX_LUGIA_V,
        .categoryName = _("Diving"),
        .height = 36,   // was 52
        .weight = 1510, // was 2160
        .description = COMPOUND_STRING(
            "Its wings were deliberately made small\n"
            "to curb their ruinous wind pressure.\n"
            "Even so, one startled wingbeat can whip\n"
            "the sea into waves as high as houses."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 5,   // was 0
        .trainerScale = 721,
        .trainerOffset = 19,
        .frontPic = gMonFrontPic_Lugia,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_IN_STAGES,
        .frontAnimDelay = 20,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Lugia,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Lugia,
        .shinyPalette = gMonShinyPalette_Lugia,
        .iconSprite = gMonIcon_Lugia,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_L)
        FOOTPRINT(Lugia)
        OVERWORLD(
            sPicTable_Lugia,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Lugia,
            gShinyOverworldPalette_Lugia
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLugiaLevelUpLearnset,
        .teachableLearnset = sLugiaTeachableLearnset,
    },

    [SPECIES_HO_OH_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 74,   // was 106
        .baseAttack    = 91,   // was 130
        .baseDefense   = 63,   // was 90
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 77,   // was 110
        .baseSpDefense = 107,  // was 154
        .types = MON_TYPES(TYPE_FIRE, TYPE_FLYING),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_HARVEST, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Ho-Oh-V"),
        .cryId = CRY_HO_OH,
        .natDexNum = NATIONAL_DEX_HO_OH_V,
        .categoryName = _("Rainbow"),
        .height = 27,   // was 38
        .weight = 1391, // was 1990
        .description = COMPOUND_STRING(
            "Seven colors ripple across its feathers,\n"
            "though their glow flickers when it tires.\n"
            "Those who see the full rainbow report\n"
            "a strange joy that lingers for days."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 6,   // was 0
        .trainerScale = 610,
        .trainerOffset = 17,
        .frontPic = gMonFrontPic_HoOh,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_HoOh,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 2,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_HoOh,
        .shinyPalette = gMonShinyPalette_HoOh,
        .iconSprite = gMonIcon_HoOh,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 17, SHADOW_SIZE_L)
        FOOTPRINT(HoOh)
        OVERWORLD(
            sPicTable_HoOh,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_HoOh,
            gShinyOverworldPalette_HoOh
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sHoOhLevelUpLearnset,
        .teachableLearnset = sHoOhTeachableLearnset,
    },

    [SPECIES_REGIROCK_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 80
        .baseAttack    = 82,   // was 100
        .baseDefense   = 164,  // was 200
        .baseSpeed     = 41,   // was 50
        .baseSpAttack  = 41,   // was 50
        .baseSpDefense = 82,   // was 100
        .types = MON_TYPES(TYPE_ROCK),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 217,
    #endif
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ROCK_HEAD, ABILITY_NONE, ABILITY_STURDY },
        .bodyColor = BODY_COLOR_BROWN,
        .noFlip = TRUE,
        .speciesName = _("Regirock-V"),
        .cryId = CRY_REGIROCK,
        .natDexNum = NATIONAL_DEX_REGIROCK_V,
        .categoryName = _("Rock Peak"),
        .height = 14,   // was 17
        .weight = 1884, // was 2300
        .description = COMPOUND_STRING(
            "Built from mineral samples and unstable\n"
            "DNA, it replaces shattered body parts\n"
            "with nearby stone. Each repair leaves its\n"
            "composition less like the original."),
        .pokemonScale = 313,  // was 256
        .pokemonOffset = 2,
        .trainerScale = 309,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Regirock,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 3,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_CIRCULAR_STRETCH_TWICE,
        .backPic = gMonBackPic_Regirock,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 48) : MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Regirock,
        .shinyPalette = gMonShinyPalette_Regirock,
        .iconSprite = gMonIcon_Regirock,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_L)
        FOOTPRINT(Regirock)
        OVERWORLD(
            sPicTable_Regirock,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regirock,
            gShinyOverworldPalette_Regirock
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRegirockLevelUpLearnset,
        .teachableLearnset = sRegirockTeachableLearnset,
    },

    [SPECIES_REGICE_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 80
        .baseAttack    = 41,   // was 50
        .baseDefense   = 82,   // was 100
        .baseSpeed     = 41,   // was 50
        .baseSpAttack  = 82,   // was 100
        .baseSpDefense = 164,  // was 200
        .types = MON_TYPES(TYPE_ICE),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 216,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SNOW_WARNING, ABILITY_NONE, ABILITY_ICE_BODY },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Regice-V"),
        .cryId = CRY_REGICE,
        .natDexNum = NATIONAL_DEX_REGICE_V,
        .categoryName = _("Iceberg"),
        .height = 15,   // was 18
        .weight = 1433, // was 1750
        .description = COMPOUND_STRING(
            "Ice formed around its engineered core at\n"
            "temperatures far below any winter storm.\n"
            "Warm air refreezes on contact, preserving\n"
            "its body even beneath the desert sun."),
        .pokemonScale = 313,  // was 256
        .pokemonOffset = 4,   // was 0
        .trainerScale = 301,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_Regice,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 18),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_FOUR_PETAL : ANIM_H_SLIDE_SLOW,
        .backPic = gMonBackPic_Regice,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Regice,
        .shinyPalette = gMonShinyPalette_Regice,
        .iconSprite = gMonIcon_Regice,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 10, SHADOW_SIZE_L)
        FOOTPRINT(Regice)
        OVERWORLD(
            sPicTable_Regice,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regice,
            gShinyOverworldPalette_Regice
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRegiceLevelUpLearnset,
        .teachableLearnset = sRegiceTeachableLearnset,
    },

    [SPECIES_REGISTEEL_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 66,   // was 80
        .baseAttack    = 61,   // was 75
        .baseDefense   = 123,  // was 150
        .baseSpeed     = 41,   // was 50
        .baseSpAttack  = 61,   // was 75
        .baseSpDefense = 123,  // was 150
        .types = MON_TYPES(TYPE_STEEL),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 215,
    #endif
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_HEAVY_METAL, ABILITY_NONE, ABILITY_LIGHT_METAL },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Registeel-V"),
        .cryId = CRY_REGISTEEL,
        .natDexNum = NATIONAL_DEX_REGISTEEL_V,
        .categoryName = _("Iron"),
        .height = 16,   // was 19
        .weight = 1679, // was 2050
        .description = COMPOUND_STRING(
            "Forged around an unstable genetic core,\n"
            "its hollow metal shell is both harder\n"
            "and more flexible than any known alloy.\n"
            "No tool has taken a sample from it."),
        .pokemonScale = 313,  // was 256
        .pokemonOffset = 5,   // was 0
        .trainerScale = 359,
        .trainerOffset = 6,
        .frontPic = gMonFrontPic_Registeel,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Registeel,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 40) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 14 : 11,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Registeel,
        .shinyPalette = gMonShinyPalette_Registeel,
        .iconSprite = gMonIcon_Registeel,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 8, SHADOW_SIZE_L)
        FOOTPRINT(Registeel)
        OVERWORLD(
            sPicTable_Registeel,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Registeel,
            gShinyOverworldPalette_Registeel
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRegisteelLevelUpLearnset,
        .teachableLearnset = sRegisteelTeachableLearnset,
    },

    [SPECIES_LATIAS_V] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 64,   // was 80
        .baseAttack    = 63,   // was 80
        .baseDefense   = 71,   // was 90
        .baseSpeed     = 87,   // was 110
        .baseSpAttack  = 87,   // was 110
        .baseSpDefense = 103,  // was 130
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 211,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Latias-V"),
        .cryId = CRY_LATIAS,
        .natDexNum = NATIONAL_DEX_LATIAS_V,
        .categoryName = _("Eon"),
        .height = 11,  // was 14
        .weight = 317, // was 400
        .description = COMPOUND_STRING(
            "Its reconstructed down bends light into\n"
            "a crude but convincing human disguise.\n"
            "It approaches only kindhearted people,\n"
            "whose emotions it senses from afar."),
        .pokemonScale = 384,  // was 304
        .pokemonOffset = 3,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Latias,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(64, 48),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 8,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_SWING_CONCAVE_FAST_SHORT : ANIM_ZIGZAG_SLOW,
        .enemyMonElevation = P_GBA_STYLE_SPECIES_GFX ? 6 : 12,
        .backPic = gMonBackPic_Latias,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Latias,
        .shinyPalette = gMonShinyPalette_Latias,
        .iconSprite = gMonIcon_Latias,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 15, SHADOW_SIZE_M)
        FOOTPRINT(Latias)
        OVERWORLD(
            sPicTable_Latias,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Latias,
            gShinyOverworldPalette_Latias
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLatiasLevelUpLearnset,
        .teachableLearnset = sLatiasTeachableLearnset,
    },

    [SPECIES_LATIOS_V] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 64,   // was 80
        .baseAttack    = 71,   // was 90
        .baseDefense   = 63,   // was 80
        .baseSpeed     = 87,   // was 110
        .baseSpAttack  = 103,  // was 130
        .baseSpDefense = 87,   // was 110
        .types = MON_TYPES(TYPE_DRAGON, TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 211,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Latios-V"),
        .cryId = CRY_LATIOS,
        .natDexNum = NATIONAL_DEX_LATIOS_V,
        .categoryName = _("Eon"),
        .height = 16,  // was 20
        .weight = 475, // was 600
        .description = COMPOUND_STRING(
            "Engineered for empathy as well as speed,\n"
            "it reads a trusted Trainer's intentions.\n"
            "By folding its forelegs, it can outpace a\n"
            "jet for a few breathtaking moments."),
        .pokemonScale = 323,  // was 256
        .pokemonOffset = 1,   // was 0
        .trainerScale = 294,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Latios,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 2 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = P_GBA_STYLE_SPECIES_GFX ? ANIM_V_SHAKE : ANIM_CIRCLE_C_CLOCKWISE_SLOW,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Latios,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 64) : MON_COORDS_SIZE(56, 64),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 3 : 0,
        .backAnimId = BACK_ANIM_H_VIBRATE,
        .palette = gMonPalette_Latios,
        .shinyPalette = gMonShinyPalette_Latios,
        .iconSprite = gMonIcon_Latios,
        .iconPalIndex = P_GBA_STYLE_SPECIES_ICONS ? 2 : 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 17, SHADOW_SIZE_M)
        FOOTPRINT(Latios)
        OVERWORLD(
            sPicTable_Latios,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Latios,
            gShinyOverworldPalette_Latios
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLatiosLevelUpLearnset,
        .teachableLearnset = sLatiosTeachableLearnset,
    },

    [SPECIES_KYOGRE_V] =
    {
        // BST was 670, lowered by ~29%
        .baseHP        = 71,   // was 100
        .baseAttack    = 71,   // was 100
        .baseDefense   = 64,   // was 90
        .baseSpeed     = 64,   // was 90
        .baseSpAttack  = 106,  // was 150
        .baseSpDefense = 99,   // was 140
        .types = MON_TYPES(TYPE_WATER),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 335,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 302,
    #else
        .expYield = 218,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DRIZZLE, ABILITY_NONE, ABILITY_WATER_ABSORB },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Kyogre-V"),
        .cryId = CRY_KYOGRE,
        .natDexNum = NATIONAL_DEX_KYOGRE_V,
        .categoryName = _("Sea Basin"),
        .height = 32,   // was 45
        .weight = 2496, // was 3520
        .description = COMPOUND_STRING(
            "Despite carrying only a fragment of the\n"
            "sea creator's power, its cries bring rain.\n"
            "It sleeps in deep water while its body\n"
            "slowly replenishes the moisture it spends."),
        .pokemonScale = 361,  // was 256
        .pokemonOffset = 3,   // was 0
        .trainerScale = 614,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_Kyogre,
        .frontPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 4 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE_FAST_SHORT,
        .frontAnimDelay = 60,
        .backPic = gMonBackPic_Kyogre,
        .backPicSize = MON_COORDS_SIZE(64, 32),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 19 : 18,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Kyogre,
        .shinyPalette = gMonShinyPalette_Kyogre,
        .iconSprite = gMonIcon_Kyogre,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Kyogre)
        OVERWORLD(
            sPicTable_Kyogre,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Kyogre,
            gShinyOverworldPalette_Kyogre
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sKyogreLevelUpLearnset,
        .teachableLearnset = sKyogreTeachableLearnset,
    },

    [SPECIES_GROUDON_V] =
    {
        // BST was 670, lowered by ~29%
        .baseHP        = 71,   // was 100
        .baseAttack    = 106,  // was 150
        .baseDefense   = 99,   // was 140
        .baseSpeed     = 64,   // was 90
        .baseSpAttack  = 71,   // was 100
        .baseSpDefense = 64,   // was 90
        .types = MON_TYPES(TYPE_GROUND),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 335,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 302,
    #else
        .expYield = 218,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DROUGHT, ABILITY_NONE, ABILITY_FLASH_FIRE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Groudon-V"),
        .cryId = CRY_GROUDON,
        .natDexNum = NATIONAL_DEX_GROUDON_V,
        .categoryName = _("Continent"),
        .height = 25,   // was 35
        .weight = 6735, // was 9500
        .description = COMPOUND_STRING(
            "Legendary genes give it dominion over\n"
            "heat, but its young body tires quickly.\n"
            "After expanding a patch of land, it buries\n"
            "itself in magma to recover its strength."),
        .pokemonScale = 361,  // was 256
        .pokemonOffset = 7,   // was 0
        .trainerScale = 515,
        .trainerOffset = 14,
        .frontPic = gMonFrontPic_Groudon,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 1 : 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Groudon,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(64, 56) : MON_COORDS_SIZE(64, 48),
        .backPicYOffset = P_GBA_STYLE_SPECIES_GFX ? 7 : 8,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Groudon,
        .shinyPalette = gMonShinyPalette_Groudon,
        .iconSprite = gMonIcon_Groudon,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Groudon)
        OVERWORLD(
            sPicTable_Groudon,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Groudon,
            gShinyOverworldPalette_Groudon
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sGroudonLevelUpLearnset,
        .teachableLearnset = sGroudonTeachableLearnset,
    },

    [SPECIES_RAYQUAZA_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 73,   // was 105
        .baseAttack    = 105,  // was 150
        .baseDefense   = 63,   // was 90
        .baseSpeed     = 66,   // was 95
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 63,   // was 90
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FLYING),
        .catchRate = 45,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_AIR_LOCK, ABILITY_NONE, ABILITY_UNBURDEN },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Rayquaza-V"),
        .cryId = CRY_RAYQUAZA,
        .natDexNum = NATIONAL_DEX_RAYQUAZA_V,
        .categoryName = _("Sky High"),
        .height = 49,   // was 70
        .weight = 1442, // was 2065
        .description = COMPOUND_STRING(
            "Designed to restrain two warring genetic\n"
            "lines, it patrols the upper atmosphere.\n"
            "It feeds on meteoric dust until a distant\n"
            "clash calls it streaking toward the earth."),
        .pokemonScale = 367,  // was 256
        .pokemonOffset = 7,   // was 0
        .trainerScale = 448,
        .trainerOffset = 12,
        .frontPic = gMonFrontPic_Rayquaza,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 8),
            ANIMCMD_FRAME(0, 22),
            ANIMCMD_FRAME(1, 6),
            ANIMCMD_FRAME(0, 6),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .frontAnimDelay = 60,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Rayquaza,
        .backPicSize = P_GBA_STYLE_SPECIES_GFX ? MON_COORDS_SIZE(56, 64) : MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_Rayquaza,
        .shinyPalette = gMonShinyPalette_Rayquaza,
        .iconSprite = gMonIcon_Rayquaza,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_L)
        FOOTPRINT(Rayquaza)
        OVERWORLD(
            sPicTable_Rayquaza,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_Rayquaza,
            gShinyOverworldPalette_Rayquaza
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRayquazaLevelUpLearnset,
        .teachableLearnset = sRayquazaTeachableLearnset,
    },

    [SPECIES_UXIE_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 61,   // was 75
        .baseAttack    = 61,   // was 75
        .baseDefense   = 107,  // was 130
        .baseSpeed     = 78,   // was 95
        .baseSpAttack  = 61,   // was 75
        .baseSpDefense = 107,  // was 130
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_Defense = 2,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Uxie-V"),
        .cryId = CRY_UXIE,
        .natDexNum = NATIONAL_DEX_UXIE_V,
        .categoryName = _("Knowledge"),
        .height = 2,    // was 3
        .weight = 2,    // was 3
        .description = COMPOUND_STRING(
            "Researchers copied the neural pattern\n"
            "said to have gifted knowledge to humans.\n"
            "Those who meet its gaze briefly recall\n"
            "answers to questions they never studied."),
        .pokemonScale = 625,  // was 530
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Uxie,
        .frontPicSize = MON_COORDS_SIZE(56, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_SWING_CONCAVE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Uxie,
        .backPicSize = MON_COORDS_SIZE(56, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Uxie,
        .shinyPalette = gMonShinyPalette_Uxie,
        .iconSprite = gMonIcon_Uxie,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_S)
        FOOTPRINT(Uxie)
        OVERWORLD(
            sPicTable_Uxie,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Uxie,
            gShinyOverworldPalette_Uxie
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sUxieLevelUpLearnset,
        .teachableLearnset = sUxieTeachableLearnset,
    },

    [SPECIES_MESPRIT_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 66,   // was 80
        .baseAttack    = 86,   // was 105
        .baseDefense   = 85,   // was 105
        .baseSpeed     = 66,   // was 80
        .baseSpAttack  = 86,   // was 105
        .baseSpDefense = 86,   // was 105
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Mesprit-V"),
        .cryId = CRY_MESPRIT,
        .natDexNum = NATIONAL_DEX_MESPRIT_V,
        .categoryName = _("Emotion"),
        .height = 2,    // was 3
        .weight = 2,    // was 3
        .description = COMPOUND_STRING(
            "Its unstable psychic waves resonate with\n"
            "strong emotions in anyone nearby.\n"
            "It laughs and weeps without warning as\n"
            "it learns to separate those feelings."),
        .pokemonScale = 625,  // was 530
        .pokemonOffset = 13,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Mesprit,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 30),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 12),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Mesprit,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Mesprit,
        .shinyPalette = gMonShinyPalette_Mesprit,
        .iconSprite = gMonIcon_Mesprit,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_S)
        FOOTPRINT(Mesprit)
        OVERWORLD(
            sPicTable_Mesprit,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Mesprit,
            gShinyOverworldPalette_Mesprit
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sMespritLevelUpLearnset,
        .teachableLearnset = sMespritTeachableLearnset,
    },

    [SPECIES_AZELF_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 61,   // was 75
        .baseAttack    = 102,  // was 125
        .baseDefense   = 58,   // was 70
        .baseSpeed     = 94,   // was 115
        .baseSpAttack  = 102,  // was 125
        .baseSpDefense = 58,   // was 70
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_Attack = 2,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 140,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Azelf-V"),
        .cryId = CRY_AZELF,
        .natDexNum = NATIONAL_DEX_AZELF_V,
        .categoryName = _("Willpower"),
        .height = 2,    // was 3
        .weight = 2,    // was 3
        .description = COMPOUND_STRING(
            "The willpower encoded in its genes makes\n"
            "this small prototype fiercely resolute.\n"
            "When its Trainer falters, a touch from its\n"
            "tails restores the courage to continue."),
        .pokemonScale = 625,  // was 530
        .pokemonOffset = 12,  // was 13
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Azelf,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Azelf,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_CONCAVE_ARC_SMALL,
        .palette = gMonPalette_Azelf,
        .shinyPalette = gMonShinyPalette_Azelf,
        .iconSprite = gMonIcon_Azelf,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 17, SHADOW_SIZE_S)
        FOOTPRINT(Azelf)
        OVERWORLD(
            sPicTable_Azelf,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Azelf,
            gShinyOverworldPalette_Azelf
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sAzelfLevelUpLearnset,
        .teachableLearnset = sAzelfTeachableLearnset,
    },

    [SPECIES_DIALGA_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 69,   // was 100
        .baseAttack    = 84,   // was 120
        .baseDefense   = 84,   // was 120
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 70,   // was 100
        .types = MON_TYPES(TYPE_STEEL, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FILTER, ABILITY_NONE, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Dialga-V"),
        .cryId = CRY_DIALGA,
        .natDexNum = NATIONAL_DEX_DIALGA_V,
        .categoryName = _("Temporal"),
        .height = 38,   // was 54
        .weight = 4771, // was 6830
        .description = COMPOUND_STRING(
            "Its incomplete temporal genes bend time\n"
            "for only a few heartbeats at once.\n"
            "Clocks run wild whenever its chest crystal\n"
            "pulses, then agree when the glow fades."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 6,   // was 0
        .trainerScale = 721,
        .trainerOffset = 19,
        .frontPic = gMonFrontPic_Dialga,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_Dialga,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_Dialga,
        .shinyPalette = gMonShinyPalette_Dialga,
        .iconSprite = gMonIcon_Dialga,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 12, SHADOW_SIZE_L)
        FOOTPRINT(Dialga)
        OVERWORLD(
            sPicTable_Dialga,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Dialga,
            gShinyOverworldPalette_Dialga
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sDialgaLevelUpLearnset,
        .teachableLearnset = sDialgaTeachableLearnset,
        .formSpeciesIdTable = sDialgaVFormSpeciesIdTable,
        .formChangeTable = sDialgaVFormChangeTable,
    },

    [SPECIES_DIALGA_V_ORIGIN] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 69,   // was 100
        .baseAttack    = 70,   // was 100
        .baseDefense   = 84,   // was 120
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 84,   // was 120
        .types = MON_TYPES(TYPE_STEEL, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FILTER, ABILITY_NONE, ABILITY_ADAPTABILITY },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Dialga-V"),
        .cryId = CRY_DIALGA,
        .natDexNum = NATIONAL_DEX_DIALGA_V,
        .categoryName = _("Temporal"),
        .height = 49,   // was 70
        .weight = 5950, // was 8500
        .description = COMPOUND_STRING(
            "An Adamant Crystal awakens ancient code\n"
            "buried deep within its unstable genome.\n"
            "In this form, each heartbeat makes time\n"
            "shudder before settling into rhythm."),
        .pokemonScale = 333,
        .pokemonOffset = 6,
        .trainerScale = 721,
        .trainerOffset = 19,
        .frontPic = gMonFrontPic_DialgaOrigin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .backPic = gMonBackPic_DialgaOrigin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .palette = gMonPalette_DialgaOrigin,
        .shinyPalette = gMonShinyPalette_DialgaOrigin,
        .iconSprite = gMonIcon_DialgaOrigin,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 11, SHADOW_SIZE_L)
        FOOTPRINT(Dialga)
        OVERWORLD(
            sPicTable_DialgaOrigin,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_DialgaOrigin,
            gShinyOverworldPalette_DialgaOrigin
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sDialgaLevelUpLearnset,
        .teachableLearnset = sDialgaTeachableLearnset,
        .formSpeciesIdTable = sDialgaVFormSpeciesIdTable,
        .formChangeTable = sDialgaVFormChangeTable,
    },

    [SPECIES_PALKIA_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 62,   // was 90
        .baseAttack    = 84,   // was 120
        .baseDefense   = 70,   // was 100
        .baseSpeed     = 70,   // was 100
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 84,   // was 120
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_FILTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Palkia-V"),
        .cryId = CRY_PALKIA,
        .natDexNum = NATIONAL_DEX_PALKIA_V,
        .categoryName = _("Spatial"),
        .height = 29,   // was 42
        .weight = 2347, // was 3360
        .description = COMPOUND_STRING(
            "Space wrinkles around its reconstructed\n"
            "pearls whenever its emotions surge.\n"
            "It can cross a locked room in one step,\n"
            "but distant dimensions remain beyond it."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 4,   // was 0
        .trainerScale = 650,
        .trainerOffset = 16,
        .frontPic = gMonFrontPic_Palkia,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Palkia,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Palkia,
        .shinyPalette = gMonShinyPalette_Palkia,
        .iconSprite = gMonIcon_Palkia,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 10, SHADOW_SIZE_L)
        FOOTPRINT(Palkia)
        OVERWORLD(
            sPicTable_Palkia,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Palkia,
            gShinyOverworldPalette_Palkia
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sPalkiaLevelUpLearnset,
        .teachableLearnset = sPalkiaTeachableLearnset,
        .formSpeciesIdTable = sPalkiaVFormSpeciesIdTable,
        .formChangeTable = sPalkiaVFormChangeTable,
    },

    [SPECIES_PALKIA_V_ORIGIN] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 62,   // was 90
        .baseAttack    = 70,   // was 100
        .baseDefense   = 70,   // was 100
        .baseSpeed     = 84,   // was 120
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 84,   // was 120
        .types = MON_TYPES(TYPE_WATER, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ADAPTABILITY, ABILITY_NONE, ABILITY_FILTER },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Palkia-V"),
        .cryId = CRY_PALKIA,
        .natDexNum = NATIONAL_DEX_PALKIA_V,
        .categoryName = _("Spatial"),
        .height = 44,   // was 63
        .weight = 4620, // was 6600
        .description = COMPOUND_STRING(
            "A Lustrous Globe unlocks the form hidden\n"
            "in its reconstructed spatial genes.\n"
            "It gallops through folded space, leaving\n"
            "silver cracks that quietly seal behind it."),
        .pokemonScale = 333,
        .pokemonOffset = 4,
        .trainerScale = 650,
        .trainerOffset = 16,
        .frontPic = gMonFrontPic_PalkiaOrigin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .backPic = gMonBackPic_PalkiaOrigin,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .palette = gMonPalette_PalkiaOrigin,
        .shinyPalette = gMonShinyPalette_PalkiaOrigin,
        .iconSprite = gMonIcon_PalkiaOrigin,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 14, SHADOW_SIZE_L)
        FOOTPRINT(Palkia)
        OVERWORLD(
            sPicTable_PalkiaOrigin,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_NONE,
            sAnimTable_Following,
            gOverworldPalette_PalkiaOrigin,
            gShinyOverworldPalette_PalkiaOrigin
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sPalkiaLevelUpLearnset,
        .teachableLearnset = sPalkiaTeachableLearnset,
        .formSpeciesIdTable = sPalkiaVFormSpeciesIdTable,
        .formChangeTable = sPalkiaVFormChangeTable,
    },

    [SPECIES_GIRATINA_V_ALTERED] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 104,  // was 150
        .baseAttack    = 70,   // was 100
        .baseDefense   = 84,   // was 120
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 70,   // was 100
        .baseSpDefense = 84,   // was 120
        .types = MON_TYPES(TYPE_GHOST, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_CURSED_BODY, ABILITY_NONE, ABILITY_ANGER_POINT },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Giratina-V"),
        .cryId = CRY_GIRATINA,
        .natDexNum = NATIONAL_DEX_GIRATINA_V,
        .categoryName = _("Renegade"),
        .height = 31,   // was 45
        .weight = 5239, // was 7500
        .description = COMPOUND_STRING(
            "Engineered from forbidden genetic data,\n"
            "it casts a shadow into another world.\n"
            "Violent impulses emerge when that shadow\n"
            "moves out of step with its own body."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 2,   // was 0
        .trainerScale = 614,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_GiratinaAltered,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_GiratinaAltered,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_GiratinaAltered,
        .shinyPalette = gMonShinyPalette_GiratinaAltered,
        .iconSprite = gMonIcon_GiratinaAltered,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 11, SHADOW_SIZE_L)
        FOOTPRINT(GiratinaAltered)
        OVERWORLD(
            sPicTable_GiratinaAltered,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GiratinaAltered,
            gShinyOverworldPalette_GiratinaAltered
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sGiratinaLevelUpLearnset,
        .teachableLearnset = sGiratinaTeachableLearnset,
        .formSpeciesIdTable = sGiratinaVFormSpeciesIdTable,
        .formChangeTable = sGiratinaVFormChangeTable,
    },

    [SPECIES_GIRATINA_V_ORIGIN] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 104,  // was 150
        .baseAttack    = 84,   // was 120
        .baseDefense   = 70,   // was 100
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 84,   // was 120
        .baseSpDefense = 70,   // was 100
        .types = MON_TYPES(TYPE_GHOST, TYPE_DRAGON),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Giratina-V"),
        .cryId = CRY_GIRATINA,
        .natDexNum = NATIONAL_DEX_GIRATINA_V,
        .categoryName = _("Renegade"),
        .height = 48,   // was 69
        .weight = 4550, // was 6500
        .description = COMPOUND_STRING(
            "The Griseous Core draws its unstable body\n"
            "halfway into the world behind its shadow.\n"
            "There it sheds its legs and swims freely\n"
            "through warped gravity like a serpent."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 2,   // was 0
        .trainerScale = 614,
        .trainerOffset = 13,
        .frontPic = gMonFrontPic_GiratinaOrigin,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 11),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_LUNGE_GROW,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_GiratinaOrigin,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_GiratinaOrigin,
        .shinyPalette = gMonShinyPalette_GiratinaOrigin,
        .iconSprite = gMonIcon_GiratinaOrigin,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 18, SHADOW_SIZE_L)
        FOOTPRINT(GiratinaOrigin)
        OVERWORLD(
            sPicTable_GiratinaOrigin,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_GiratinaOrigin,
            gShinyOverworldPalette_GiratinaOrigin
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sGiratinaLevelUpLearnset,
        .teachableLearnset = sGiratinaTeachableLearnset,
        .formSpeciesIdTable = sGiratinaVFormSpeciesIdTable,
        .formChangeTable = sGiratinaVFormChangeTable,
    },

    [SPECIES_HEATRAN_V] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 72,   // was 91
        .baseAttack    = 71,   // was 90
        .baseDefense   = 84,   // was 106
        .baseSpeed     = 61,   // was 77
        .baseSpAttack  = 103,  // was 130
        .baseSpDefense = 84,   // was 106
        .types = MON_TYPES(TYPE_FIRE, TYPE_STEEL),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 215,
    #endif
        .evYield_SpAttack = 3,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 10,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FLASH_FIRE, ABILITY_NONE, ABILITY_FLAME_BODY },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Heatran-V"),
        .cryId = CRY_HEATRAN,
        .natDexNum = NATIONAL_DEX_HEATRAN_V,
        .categoryName = _("Lava Dome"),
        .height = 13,   // was 17
        .weight = 3404, // was 4300
        .description = COMPOUND_STRING(
            "Molten material circulates around the\n"
            "unstable core that serves as its heart.\n"
            "Cross-shaped claws melt stone into glass\n"
            "as it climbs across cavern ceilings."),
        .pokemonScale = 313,  // was 259
        .pokemonOffset = 8,   // was 0  
        .trainerScale = 290,
        .trainerOffset = 1,
        .frontPic = gMonFrontPic_Heatran,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 30),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_GLOW_ORANGE,
        .backPic = gMonBackPic_Heatran,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Heatran,
        .shinyPalette = gMonShinyPalette_Heatran,
        .iconSprite = gMonIcon_Heatran,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 2, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Heatran)
        OVERWORLD(
            sPicTable_Heatran,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Heatran,
            gShinyOverworldPalette_Heatran
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sHeatranLevelUpLearnset,
        .teachableLearnset = sHeatranTeachableLearnset,
    },

    [SPECIES_REGIGIGAS_V] =
    {
        // BST was 670, lowered by ~29%
        .baseHP        = 78,   // was 110
        .baseAttack    = 113,  // was 160
        .baseDefense   = 78,   // was 110
        .baseSpeed     = 71,   // was 100
        .baseSpAttack  = 57,   // was 80
        .baseSpDefense = 78,   // was 110
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 335,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 302,
    #else
        .expYield = 220,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STEADFAST, ABILITY_NONE, ABILITY_NORMALIZE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Regigigas-V"),
        .cryId = CRY_REGIGIGAS,
        .natDexNum = NATIONAL_DEX_REGIGIGAS_V,
        .categoryName = _("Colossal"),
        .height = 26,   // was 37
        .weight = 2978, // was 4200
        .description = COMPOUND_STRING(
            "Modeled on the master of three golems,\n"
            "it awakens with agonizing slowness.\n"
            "Once its ancient genes begin to stir,\n"
            "even bedrock shifts beneath its grip."),
        .pokemonScale = 330,  // was 256
        .pokemonOffset = 2,
        .trainerScale = 4610,
        .trainerOffset = 17,
        .frontPic = gMonFrontPic_Regigigas,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 4,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Regigigas,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 13,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Regigigas,
        .shinyPalette = gMonShinyPalette_Regigigas,
        .iconSprite = gMonIcon_Regigigas,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 10, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Regigigas)
        OVERWORLD(
            sPicTable_Regigigas,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Regigigas,
            gShinyOverworldPalette_Regigigas
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sRegigigasLevelUpLearnset,
        .teachableLearnset = sRegigigasTeachableLearnset,
    },

    [SPECIES_CRESSELIA_V] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 95,   // was 120
        .baseAttack    = 55,   // was 70
        .baseDefense   = 95,   // was 120
        .baseSpeed     = 67,   // was 85
        .baseSpAttack  = 60,   // was 75
        .baseSpDefense = 103,  // was 130
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 210,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_FEMALE,
        .eggCycles = 120,
        .friendship = 100,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_LEVITATE, ABILITY_NONE, ABILITY_NATURAL_CURE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Cresselia-V"),
        .cryId = CRY_CRESSELIA,
        .natDexNum = NATIONAL_DEX_CRESSELIA_V,
        .categoryName = _("Lunar"),
        .height = 12,  // was 15
        .weight = 678, // was 856
        .description = COMPOUND_STRING(
            "Its feathers were engineered to pulse\n"
            "with a soothing imitation of moonlight.\n"
            "Sleeping near one quiets recurring\n"
            "nightmares with vivid, joyful dreams."),
        .pokemonScale = 324,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cresselia,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_H_SLIDE_WOBBLE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Cresselia,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_CONVEX_DOUBLE_ARC,
        .palette = gMonPalette_Cresselia,
        .shinyPalette = gMonShinyPalette_Cresselia,
        .iconSprite = gMonIcon_Cresselia,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_M)
        FOOTPRINT(Cresselia)
        OVERWORLD(
            sPicTable_Cresselia,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cresselia,
            gShinyOverworldPalette_Cresselia
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sCresseliaLevelUpLearnset,
        .teachableLearnset = sCresseliaTeachableLearnset,
    },

    [SPECIES_COBALION_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 75,   // was 91
        .baseAttack    = 74,   // was 90
        .baseDefense   = 106,  // was 129
        .baseSpeed     = 89,   // was 108
        .baseSpAttack  = 74,   // was 90
        .baseSpDefense = 59,   // was 72
        .types = MON_TYPES(TYPE_STEEL, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cobalion-V"),
        .cryId = CRY_COBALION,
        .natDexNum = NATIONAL_DEX_COBALION_V,
        .categoryName = _("Iron Will"),
        .height = 17,   // was 21
        .weight = 2050, // was 2500
        .description = COMPOUND_STRING(
            "Steel-type genes reinforce both its body\n"
            "and its instinct to shield the helpless.\n"
            "Though lab-grown, it leads other Pokémon\n"
            "with a calm no machine could instill."),
        .pokemonScale = 302,  // was 256
        .pokemonOffset = 2,   // was 0
        .trainerScale = 365,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Cobalion,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 36),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_Cobalion,
        .backPicSize = MON_COORDS_SIZE(48, 64),
        .backPicYOffset = 6,
        .backAnimId = BACK_ANIM_V_STRETCH,
        .palette = gMonPalette_Cobalion,
        .shinyPalette = gMonShinyPalette_Cobalion,
        .iconSprite = gMonIcon_Cobalion,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_M)
        FOOTPRINT(Cobalion)
        OVERWORLD(
            sPicTable_Cobalion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cobalion,
            gShinyOverworldPalette_Cobalion
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sCobalionLevelUpLearnset,
        .teachableLearnset = sCobalionTeachableLearnset,
    },

    [SPECIES_TERRAKION_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 75,   // was 91
        .baseAttack    = 106,  // was 129
        .baseDefense   = 74,   // was 90
        .baseSpeed     = 89,   // was 108
        .baseSpAttack  = 59,   // was 72
        .baseSpDefense = 74,   // was 90
        .types = MON_TYPES(TYPE_ROCK, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Terrakion-V"),
        .cryId = CRY_TERRAKION,
        .natDexNum = NATIONAL_DEX_TERRAKION_V,
        .categoryName = _("Cavern"),
        .height = 16,   // was 19
        .weight = 2132, // was 2600
        .description = COMPOUND_STRING(
            "Its stocky frame recreates only a share\n"
            "of the strength recorded in old legends.\n"
            "When Pokémon are threatened, it can still\n"
            "shatter a stone wall with one charge."),
        .pokemonScale = 302,  // was 256
        .pokemonOffset = 5,   // was 1
        .trainerScale = 336,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Terrakion,
        .frontPicSize = MON_COORDS_SIZE(64, 56),
        .frontPicYOffset = 5,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .backPic = gMonBackPic_Terrakion,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Terrakion,
        .shinyPalette = gMonShinyPalette_Terrakion,
        .iconSprite = gMonIcon_Terrakion,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 6, SHADOW_SIZE_L)
        FOOTPRINT(Terrakion)
        OVERWORLD(
            sPicTable_Terrakion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Terrakion,
            gShinyOverworldPalette_Terrakion
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTerrakionLevelUpLearnset,
        .teachableLearnset = sTerrakionTeachableLearnset,
    },

    [SPECIES_VIRIZION_V] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 75,   // was 91
        .baseAttack    = 74,   // was 90
        .baseDefense   = 59,   // was 72
        .baseSpeed     = 89,   // was 108
        .baseSpAttack  = 74,   // was 90
        .baseSpDefense = 106,  // was 129
        .types = MON_TYPES(TYPE_GRASS, TYPE_FIGHTING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_INNER_FOCUS },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Virizion-V"),
        .cryId = CRY_VIRIZION,
        .natDexNum = NATIONAL_DEX_VIRIZION_V,
        .categoryName = _("Grassland"),
        .height = 16,   // was 20
        .weight = 1640, // was 2000
        .description = COMPOUND_STRING(
            "The blades on its head were grown from\n"
            "genes recovered from a legendary line.\n"
            "Though their edges are imperfect, its\n"
            "footwork is too swift for eyes to follow."),
        .pokemonScale = 308,  // was 261
        .pokemonOffset = 3,   // was 1
        .trainerScale = 344,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_Virizion,
        .frontPicSize = MON_COORDS_SIZE(48, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 20),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Virizion,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 8,
        .backAnimId = BACK_ANIM_H_SHAKE,
        .palette = gMonPalette_Virizion,
        .shinyPalette = gMonShinyPalette_Virizion,
        .iconSprite = gMonIcon_Virizion,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 12, SHADOW_SIZE_M)
        FOOTPRINT(Virizion)
        OVERWORLD(
            sPicTable_Virizion,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Virizion,
            gShinyOverworldPalette_Virizion
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sVirizionLevelUpLearnset,
        .teachableLearnset = sVirizionTeachableLearnset,
    },

    [SPECIES_TORNADUS_V_INCARNATE] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 79
        .baseAttack    = 94,   // was 115
        .baseDefense   = 57,   // was 70
        .baseSpeed     = 91,   // was 111
        .baseSpAttack  = 102,  // was 125
        .baseSpDefense = 66,   // was 80
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Tornadus-V"),
        .cryId = CRY_TORNADUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_TORNADUS_V,
        .categoryName = _("Cyclone"),
        .height = 12,  // was 15
        .weight = 424, // was 630
        .description = COMPOUND_STRING(
            "An unstable organ in its tail compresses\n"
            "air until it bursts into sudden storms.\n"
            "Riding its own winds, this light prototype\n"
            "can circle Hoenn without touching ground."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TornadusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_TornadusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_TornadusIncarnate,
        .shinyPalette = gMonShinyPalette_TornadusIncarnate,
        .iconSprite = gMonIcon_TornadusIncarnate,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Tornadus)
        OVERWORLD(
            sPicTable_TornadusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TornadusIncarnate,
            gShinyOverworldPalette_TornadusIncarnate
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTornadusLevelUpLearnset,
        .teachableLearnset = sTornadusTeachableLearnset,
        .formSpeciesIdTable = sTornadusVFormSpeciesIdTable,
        .formChangeTable = sTornadusVFormChangeTable,
    },

    [SPECIES_TORNADUS_V_THERIAN] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 79
        .baseAttack    = 82,   // was 100
        .baseDefense   = 65,   // was 80
        .baseSpeed     = 99,   // was 121
        .baseSpAttack  = 90,  // was 110
        .baseSpDefense = 74,   // was 90
        .types = MON_TYPES(TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_REGENERATOR, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Tornadus-V"),
        .cryId = CRY_TORNADUS_THERIAN,
        .natDexNum = NATIONAL_DEX_TORNADUS_V,
        .categoryName = _("Cyclone"),
        .height = 12,  // was 14
        .weight = 517, // was 630
        .description = COMPOUND_STRING(
            "The Reveal Glass reorganizes its genes\n"
            "into a body built for ocean crossings.\n"
            "Its wings skim the waves while its tail\n"
            "trails a roaring storm in its wake."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TornadusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 35),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_STRETCH,
        .backPic = gMonBackPic_TornadusTherian,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHRINK_GROW_VIBRATE,
        .palette = gMonPalette_TornadusTherian,
        .shinyPalette = gMonShinyPalette_TornadusTherian,
        .iconSprite = gMonIcon_TornadusTherian,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-5, 12, SHADOW_SIZE_L)
        FOOTPRINT(Tornadus)
        OVERWORLD(
            sPicTable_TornadusTherian,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TornadusTherian,
            gShinyOverworldPalette_TornadusTherian
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTornadusLevelUpLearnset,
        .teachableLearnset = sTornadusTeachableLearnset,
        .formSpeciesIdTable = sTornadusVFormSpeciesIdTable,
        .formChangeTable = sTornadusVFormChangeTable,
    },

    [SPECIES_THUNDURUS_V_INCARNATE] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 79
        .baseAttack    = 94,   // was 115
        .baseDefense   = 57,   // was 70
        .baseSpeed     = 91,   // was 111
        .baseSpAttack  = 102,  // was 125
        .baseSpDefense = 66,   // was 80
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRANKSTER, ABILITY_NONE, ABILITY_DEFIANT },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Thundurus-V"),
        .cryId = CRY_THUNDURUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_THUNDURUS_V,
        .categoryName = _("Bolt Strike"),
        .height = 12,  // was 15
        .weight = 500, // was 610
        .description = COMPOUND_STRING(
            "Excess charge beads along its spiked tail\n"
            "and discharges without warning.\n"
            "Scorched instruments litter the chamber\n"
            "where this prototype was stabilized."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ThundurusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_ThundurusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_ThundurusIncarnate,
        .shinyPalette = gMonShinyPalette_ThundurusIncarnate,
        .iconSprite = gMonIcon_ThundurusIncarnate,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Thundurus)
        OVERWORLD(
            sPicTable_ThundurusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ThundurusIncarnate,
            gShinyOverworldPalette_ThundurusIncarnate
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sThundurusLevelUpLearnset,
        .teachableLearnset = sThundurusTeachableLearnset,
        .formSpeciesIdTable = sThundurusVFormSpeciesIdTable,
        .formChangeTable = sThundurusVFormChangeTable,
    },

    [SPECIES_THUNDURUS_V_THERIAN] =
    {
        // BST was 580, lowered by ~18%
        .baseHP        = 65,   // was 79
        .baseAttack    = 86,   // was 105
        .baseDefense   = 57,   // was 70
        .baseSpeed     = 82,   // was 101
        .baseSpAttack  = 119,  // was 145
        .baseSpDefense = 66,   // was 80
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 290 : 261,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_REGENERATOR, ABILITY_NONE, ABILITY_REGENERATOR },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Thundurus-V"),
        .cryId = CRY_THUNDURUS_THERIAN,
        .natDexNum = NATIONAL_DEX_THUNDURUS_V,
        .categoryName = _("Bolt Strike"),
        .height = 25,  // was 30
        .weight = 500, // was 610
        .description = COMPOUND_STRING(
            "The Reveal Glass reshapes its volatile\n"
            "genes into a long, predatory body.\n"
            "Lightning fired from its tail orbs strikes\n"
            "before thunder can betray its approach."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_ThundurusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
            ANIMCMD_FRAME(1, 5),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_ThundurusTherian,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 5,
        .backAnimId = BACK_ANIM_SHAKE_FLASH_YELLOW,
        .palette = gMonPalette_ThundurusTherian,
        .shinyPalette = gMonShinyPalette_ThundurusTherian,
        .iconSprite = gMonIcon_ThundurusTherian,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(5, 16, SHADOW_SIZE_M)
        FOOTPRINT(Thundurus)
        OVERWORLD(
            sPicTable_ThundurusTherian,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ThundurusTherian,
            gShinyOverworldPalette_ThundurusTherian
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sThundurusLevelUpLearnset,
        .teachableLearnset = sThundurusTeachableLearnset,
        .formSpeciesIdTable = sThundurusVFormSpeciesIdTable,
        .formChangeTable = sThundurusVFormChangeTable,
    },

    [SPECIES_LANDORUS_V_INCARNATE] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 70,  // was 89
        .baseAttack    = 99,  // was 125
        .baseDefense   = 71,  // was 90
        .baseSpeed     = 80,  // was 101
        .baseSpAttack  = 91,  // was 115
        .baseSpDefense = 63,  // was 80
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_SpAttack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SAND_FORCE, ABILITY_NONE, ABILITY_SHEER_FORCE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Landorus-V"),
        .cryId = CRY_LANDORUS_INCARNATE,
        .natDexNum = NATIONAL_DEX_LANDORUS_V,
        .categoryName = _("Abundance"),
        .height = 12,  // was 15
        .weight = 537, // was 680
        .description = COMPOUND_STRING(
            "Energy leaking from its tail enriches\n"
            "soil, though the effect fades within days.\n"
            "Farmers still welcome this prototype as\n"
            "a young Guardian of the Fields."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LandorusIncarnate,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
            ANIMCMD_FRAME(1, 2),
            ANIMCMD_FRAME(0, 2),
        ),
        .frontAnimId = ANIM_FIGURE_8,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_LandorusIncarnate,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_V_SHAKE,
        .palette = gMonPalette_LandorusIncarnate,
        .shinyPalette = gMonShinyPalette_LandorusIncarnate,
        .iconSprite = gMonIcon_LandorusIncarnate,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 17, SHADOW_SIZE_M)
        FOOTPRINT(Landorus)
        OVERWORLD(
            sPicTable_LandorusIncarnate,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_LandorusIncarnate,
            gShinyOverworldPalette_LandorusIncarnate
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLandorusLevelUpLearnset,
        .teachableLearnset = sLandorusTeachableLearnset,
        .formSpeciesIdTable = sLandorusVFormSpeciesIdTable,
        .formChangeTable = sLandorusVFormChangeTable,
    },
    
    [SPECIES_LANDORUS_V_THERIAN] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 71,   // was 89
        .baseAttack    = 115,  // was 145
        .baseDefense   = 71,   // was 90
        .baseSpeed     = 72,   // was 91
        .baseSpAttack  = 83,   // was 105
        .baseSpDefense = 63,   // was 80
        .types = MON_TYPES(TYPE_GROUND, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_Attack = 3,
        .genderRatio = MON_MALE,
        .eggCycles = 120,
        .friendship = 90,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_INTIMIDATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BROWN,
        .speciesName = _("Landorus-V"),
        .cryId = CRY_LANDORUS_THERIAN,
        .natDexNum = NATIONAL_DEX_LANDORUS_V,
        .categoryName = _("Abundance"),
        .height = 10,  // was 13
        .weight = 537, // was 680
        .description = COMPOUND_STRING(
            "The Reveal Glass awakens genes suited to\n"
            "a powerful, four-legged form.\n"
            "Where it races, exhausted soil soon yields\n"
            "an unexpectedly abundant harvest."),
        .pokemonScale = 324,  // was 268
        .pokemonOffset = 2,
        .trainerScale = 271,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_LandorusTherian,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .backPic = gMonBackPic_LandorusTherian,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_GROW_STUTTER,
        .palette = gMonPalette_LandorusTherian,
        .shinyPalette = gMonShinyPalette_LandorusTherian,
        .iconSprite = gMonIcon_LandorusTherian,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Landorus)
        OVERWORLD(
            sPicTable_LandorusTherian,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_LandorusTherian,
            gShinyOverworldPalette_LandorusTherian
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLandorusLevelUpLearnset,
        .teachableLearnset = sLandorusTeachableLearnset,
        .formSpeciesIdTable = sLandorusVFormSpeciesIdTable,
        .formChangeTable = sLandorusVFormChangeTable,
    },

    [SPECIES_RESHIRAM_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 70,   // was 100
        .baseAttack    = 84,   // was 120
        .baseDefense   = 70,   // was 100
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 105,  // was 150
        .baseSpDefense = 84,   // was 120
        .types = MON_TYPES(TYPE_DRAGON, TYPE_FIRE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Reshiram-V"),
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_RESHIRAM_V,
        .categoryName = _("Vast White"),
        .height = 22,   // was 32
        .weight = 2310, // was 3300
        .description = COMPOUND_STRING(
            "Fragments of the Vast White Pokémon's\n"
            "genes burn like a furnace in its tail.\n"
            "It instinctively follows honest people,\n"
            "but its young flames sputter around lies."),
        .pokemonScale = 366,  // was 256
        .pokemonOffset = 5,   // was 0
        .trainerScale = 445,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Reshiram,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Reshiram,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Reshiram,
        .shinyPalette = gMonShinyPalette_Reshiram,
        .iconSprite = gMonIcon_Reshiram,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-2, 12, SHADOW_SIZE_L)
        FOOTPRINT(Reshiram)
        OVERWORLD(
            sPicTable_Reshiram,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Reshiram,
            gShinyOverworldPalette_Reshiram
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sReshiramLevelUpLearnset,
        .teachableLearnset = sReshiramTeachableLearnset,
    },

    [SPECIES_ZEKROM_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 70,   // was 100
        .baseAttack    = 105,  // was 150
        .baseDefense   = 84,   // was 120
        .baseSpeed     = 63,   // was 90
        .baseSpAttack  = 84,   // was 120
        .baseSpDefense = 70,   // was 100
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ELECTRIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("Zekrom-V"),
        .cryId = CRY_ZEKROM,
        .natDexNum = NATIONAL_DEX_ZEKROM_V,
        .categoryName = _("Deep Black"),
        .height = 20,   // was 29
        .weight = 2415, // was 3450
        .description = COMPOUND_STRING(
            "A compact generator grown within its tail\n"
            "turns conviction into electricity.\n"
            "It lends its lightning only to people who\n"
            "pursue their ideals without hesitation."),
        .pokemonScale = 393,  // was 275
        .pokemonOffset = 9,  // was 2
        .trainerScale = 412,
        .trainerOffset = 10,
        .frontPic = gMonFrontPic_Zekrom,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_Zekrom,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_Zekrom,
        .shinyPalette = gMonShinyPalette_Zekrom,
        .iconSprite = gMonIcon_Zekrom,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(2, 14, SHADOW_SIZE_L)
        FOOTPRINT(Zekrom)
        OVERWORLD(
            sPicTable_Zekrom,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Zekrom,
            gShinyOverworldPalette_Zekrom
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sZekromLevelUpLearnset,
        .teachableLearnset = sZekromTeachableLearnset,
    },

    [SPECIES_KYUREM_V] =
    {
        // BST was 660, lowered by ~30%
        .baseHP        = 87,  // was 125
        .baseAttack    = 91,  // was 130
        .baseDefense   = 63,  // was 90
        .baseSpeed     = 66,  // was 95
        .baseSpAttack  = 91,  // was 130
        .baseSpDefense = 63,  // was 90
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 330 : 297,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_REFRIGERATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Kyurem-V"),
        .cryId = CRY_KYUREM,
        .natDexNum = NATIONAL_DEX_KYUREM_V,
        .categoryName = _("Boundary"),
        .height = 21,   // was 30
        .weight = 2275, // was 3250
        .description = COMPOUND_STRING(
            "An incomplete genome left gaps throughout\n"
            "its body from which vital energy escapes.\n"
            "The cold freezes those wounds shut as it\n"
            "waits for compatible genes to fill them."),
        .pokemonScale = 393,  // was 275
        .pokemonOffset = 6,   // was 7
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Kyurem,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 20),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
        ),
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_Kyurem,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_V_SHAKE_LOW,
        .palette = gMonPalette_Kyurem,
        .shinyPalette = gMonShinyPalette_Kyurem,
        .iconSprite = gMonIcon_Kyurem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_Kyurem,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Kyurem,
            gShinyOverworldPalette_Kyurem
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sKyuremLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremVFormSpeciesIdTable,
    },

    [SPECIES_KYUREM_V_WHITE] =
    {
        // BST was 700, lowered by ~32%
        .baseHP        = 85,   // was 125
        .baseAttack    = 82,   // was 120
        .baseDefense   = 61,   // was 90
        .baseSpeed     = 65,   // was 95
        .baseSpAttack  = 116,  // was 170
        .baseSpDefense = 66,   // was 100
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Kyurem-V"),
        .cryId = CRY_KYUREM_WHITE,
        .natDexNum = NATIONAL_DEX_KYUREM_V,
        .categoryName = _("Boundary"),
        .height = 24,   // was 36
        .weight = 2210, // was 3250
        .description = COMPOUND_STRING(
            "Absorbing Reshiram-V lets matching genes\n"
            "weave together across its frozen wounds.\n"
            "Truth feeds the new furnace in its tail,\n"
            "mingling searing flame with bitter cold."),
        .pokemonScale = 393,
        .pokemonOffset = 6,
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KyuremWhite,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_KyuremWhite,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_KyuremWhite,
        .shinyPalette = gMonShinyPalette_KyuremWhite,
        .iconSprite = gMonIcon_KyuremWhite,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-8, 14, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_KyuremWhite,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_KyuremWhite,
            gShinyOverworldPalette_KyuremWhite
        )
        .cannotBeTraded = TRUE,
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sKyuremWhiteLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremVFormSpeciesIdTable,
    },

    [SPECIES_KYUREM_V_BLACK] =
    {
        // BST was 700, lowered by ~32%
        .baseHP        = 85,   // was 125
        .baseAttack    = 116,  // was 170
        .baseDefense   = 66,   // was 100
        .baseSpeed     = 65,   // was 95
        .baseSpAttack  = 82,   // was 120
        .baseSpDefense = 61,   // was 90
        .types = MON_TYPES(TYPE_DRAGON, TYPE_ICE),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 350 : 315,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_TERAVOLT, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Kyurem-V"),
        .cryId = CRY_KYUREM_BLACK,
        .natDexNum = NATIONAL_DEX_KYUREM_V,
        .categoryName = _("Boundary"),
        .height = 22,   // was 33
        .weight = 2210, // was 3250
        .description = COMPOUND_STRING(
            "Absorbing Zekrom-V lets matching genes\n"
            "bridge the empty spaces in its body.\n"
            "Ideals drive its new tail generator,\n"
            "mingling fierce lightning with bitter cold."),
        .pokemonScale = 393,
        .pokemonOffset = 6,
        .trainerScale = 356,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_KyuremBlack,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 5),
        ),
        .frontAnimId = ANIM_V_SHAKE,
        .backPic = gMonBackPic_KyuremBlack,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_KyuremBlack,
        .shinyPalette = gMonShinyPalette_KyuremBlack,
        .iconSprite = gMonIcon_KyuremBlack,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 14, SHADOW_SIZE_L)
        FOOTPRINT(Kyurem)
        OVERWORLD(
            sPicTable_KyuremBlack,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_KyuremBlack,
            gShinyOverworldPalette_KyuremBlack
        )
        .cannotBeTraded = TRUE,
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sKyuremBlackLevelUpLearnset,
        .teachableLearnset = sKyuremTeachableLearnset,
        .formSpeciesIdTable = sKyuremVFormSpeciesIdTable,
    },

    [SPECIES_XERNEAS_V_NEUTRAL] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 88,   // was 126
        .baseAttack    = 91,   // was 131
        .baseDefense   = 66,   // was 95
        .baseSpeed     = 69,   // was 99
        .baseSpAttack  = 91,   // was 131
        .baseSpDefense = 70,   // was 98
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FAIRY_AURA, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Xerneas-V"),
        .cryId = CRY_XERNEAS,
        .natDexNum = NATIONAL_DEX_XERNEAS_V,
        .categoryName = _("Life"),
        .height = 21,    // was 30
        .weight = 1505,  // was 2150
        .description = COMPOUND_STRING(
            "In its resting form, the copied life-giving\n"
            "genes in its antlers remain dormant.\n"
            "They glimmer faintly near injured Pokémon,\n"
            "as though dreaming of their true purpose."),
        .pokemonScale = 358,  // was 275
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_XerneasNeutral,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Xerneas,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_XerneasNeutral,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_XerneasNeutral,
        .shinyPalette = gMonShinyPalette_XerneasNeutral,
        .iconSprite = gMonIcon_XerneasNeutral,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 14, SHADOW_SIZE_M)
        FOOTPRINT(Xerneas)
        OVERWORLD(
            sPicTable_XerneasNeutral,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_XerneasNeutral,
            gShinyOverworldPalette_XerneasNeutral
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sXerneasLevelUpLearnset,
        .teachableLearnset = sXerneasTeachableLearnset,
        .formSpeciesIdTable = sXerneasVFormSpeciesIdTable,
        .formChangeTable = sXerneasVFormChangeTable,
    },

    [SPECIES_XERNEAS_V_ACTIVE] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 88,   // was 126
        .baseAttack    = 91,   // was 131
        .baseDefense   = 66,   // was 95
        .baseSpeed     = 69,   // was 99
        .baseSpAttack  = 91,   // was 131
        .baseSpDefense = 70,   // was 98
        .types = MON_TYPES(TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FAIRY_AURA, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Xerneas-V"),
        .cryId = CRY_XERNEAS,
        .natDexNum = NATIONAL_DEX_XERNEAS_V,
        .categoryName = _("Life"),
        .height = 21,    // was 30
        .weight = 1505,  // was 2150
        .description = COMPOUND_STRING(
            "When battle awakens its engineered aura,\n"
            "its antlers blaze in seven vivid colors.\n"
            "The light cannot grant eternal life, but\n"
            "wilting flowers rise wherever it passes."),
        .pokemonScale = 358,  // was 275
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_XerneasActive,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_Xerneas,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_XerneasActive,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_BLUE,
        .palette = gMonPalette_XerneasActive,
        .shinyPalette = gMonShinyPalette_XerneasActive,
        .iconSprite = gMonIcon_XerneasActive,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(3, 14, SHADOW_SIZE_M)
        FOOTPRINT(Xerneas)
        OVERWORLD(
            sPicTable_XerneasActive,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_XerneasNeutral,
            gShinyOverworldPalette_XerneasNeutral
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sXerneasLevelUpLearnset,
        .teachableLearnset = sXerneasTeachableLearnset,
        .formSpeciesIdTable = sXerneasVFormSpeciesIdTable,
        .formChangeTable = sXerneasVFormChangeTable,
    },

    [SPECIES_YVELTAL_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 88,   // was 126
        .baseAttack    = 91,   // was 131
        .baseDefense   = 66,   // was 95
        .baseSpeed     = 69,   // was 99
        .baseSpAttack  = 91,   // was 131
        .baseSpDefense = 70,   // was 98
        .types = MON_TYPES(TYPE_DARK, TYPE_FLYING),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_DARK_AURA, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Yveltal-V"),
        .cryId = CRY_YVELTAL,
        .natDexNum = NATIONAL_DEX_YVELTAL_V,
        .categoryName = _("Destruction"),
        .height = 41,    // was 58
        .weight = 1421,  // was 2030
        .description = COMPOUND_STRING(
            "Made from genes linked to destruction,\n"
            "it drains only the energy it needs.\n"
            "When exhausted, it draws in its wings and\n"
            "enters a brief sleep inside a dark cocoon."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 3,   // was 0
        .trainerScale = 360,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Yveltal,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 20),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 15),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_FRONT_FLIP,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_Yveltal,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_RED,
        .palette = gMonPalette_Yveltal,
        .shinyPalette = gMonShinyPalette_Yveltal,
        .iconSprite = gMonIcon_Yveltal,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 16, SHADOW_SIZE_L)
        FOOTPRINT(Yveltal)
        OVERWORLD(
            sPicTable_Yveltal,
            SIZE_64x64,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Yveltal,
            gShinyOverworldPalette_Yveltal
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sYveltalLevelUpLearnset,
        .teachableLearnset = sYveltalTeachableLearnset,
    },

    [SPECIES_ZYGARDE_V] =
    {
        // Based off complete form, other forms are boring
        // BST was 708, lowered by ~33%
        .baseHP        = 145,  // was 216
        .baseAttack    = 67,   // was 100
        .baseDefense   = 81,   // was 121
        .baseSpeed     = 57,   // was 85
        .baseSpAttack  = 61,   // was 91
        .baseSpDefense = 64,   // was 95
        .types = MON_TYPES(TYPE_DRAGON, TYPE_GROUND),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 354 : 319,
        .evYield_HP = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STAMINA, ABILITY_NONE, ABILITY_GOOEY },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Zygarde-V"),
        .cryId = CRY_ZYGARDE_COMPLETE,
        .natDexNum = NATIONAL_DEX_ZYGARDE_V,
        .categoryName = _("Order"),
        .height = 30,    // was 45
        .weight = 4087,  // was 6100
        .description = COMPOUND_STRING(
            "Artificial Cells assembled around a Core\n"
            "imitate the guardian of the ecosystem.\n"
            "They sense disturbances across Hoenn and\n"
            "gather where nature's balance is at risk."),
        .pokemonScale = 310,  // was 256
        .pokemonOffset = 4,   // was 0
        .trainerScale = 721,
        .trainerOffset = 19,
        .frontPic = gMonFrontPic_ZygardeComplete,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 12),
            ANIMCMD_FRAME(1, 45),
            ANIMCMD_FRAME(0, 15),
        ),
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_ZygardeComplete,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_SHAKE_GLOW_GREEN,
        .palette = gMonPalette_ZygardeComplete,
        .shinyPalette = gMonShinyPalette_ZygardeComplete,
        .iconSprite = gMonIcon_ZygardeComplete,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-3, 13, SHADOW_SIZE_L)
        FOOTPRINT(Zygarde)
        OVERWORLD(
            sPicTable_ZygardeComplete,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_ZygardeComplete,
            gShinyOverworldPalette_ZygardeComplete
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sZygardeLevelUpLearnset,
        .teachableLearnset = sZygardeTeachableLearnset,
    },

    [SPECIES_TAPU_KOKO_V] =
    {
        // BST was 570, lowered by ~17%
        .baseHP        = 58,   // was 70
        .baseAttack    = 96,   // was 115
        .baseDefense   = 71,   // was 85
        .baseSpeed     = 108,  // was 130
        .baseSpAttack  = 79,   // was 95
        .baseSpDefense = 63,   // was 75
        .types = MON_TYPES(TYPE_ELECTRIC, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 285 : 257,
        .evYield_Speed = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_ELECTRIC_SURGE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_YELLOW,
        .speciesName = _("Tapu Koko-V"),
        .cryId = CRY_TAPU_KOKO,
        .natDexNum = NATIONAL_DEX_TAPU_KOKO_V,
        .categoryName = _("Land Spirit"),
        .height = 15,   // was 18
        .weight = 171,  // was 205
        .description = COMPOUND_STRING(
            "Recreated instincts drive it to patrol\n"
            "every power line near its home.\n"
            "It moves as a yellow blur, repairing some\n"
            "outages and gleefully causing others."),
        .pokemonScale = 287,  // was 267
        .pokemonOffset = 3,
        .trainerScale = 310,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_TapuKoko,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 1,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 10),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_TRIANGLE_DOWN_TWICE,
        .enemyMonElevation = 9,
        .backPic = gMonBackPic_TapuKoko,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .palette = gMonPalette_TapuKoko,
        .shinyPalette = gMonShinyPalette_TapuKoko,
        .iconSprite = gMonIcon_TapuKoko,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 19, SHADOW_SIZE_M)
        FOOTPRINT(TapuKoko)
        OVERWORLD(
            sPicTable_TapuKoko,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TapuKoko,
            gShinyOverworldPalette_TapuKoko
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTapuKokoLevelUpLearnset,
        .teachableLearnset = sTapuKokoTeachableLearnset,
    },

    [SPECIES_TAPU_LELE_V] =
    {
        // BST was 570, lowered by ~17%
        .baseHP        = 58,   // was 70
        .baseAttack    = 71,   // was 85
        .baseDefense   = 63,   // was 75
        .baseSpeed     = 79,   // was 95
        .baseSpAttack  = 108,  // was 130
        .baseSpDefense = 96,   // was 115
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 285 : 257,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PSYCHIC_SURGE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PINK,
        .speciesName = _("Tapu Lele-V"),
        .cryId = CRY_TAPU_LELE,
        .natDexNum = NATIONAL_DEX_TAPU_LELE_V,
        .categoryName = _("Land Spirit"),
        .height = 10,   // was 12
        .weight = 155,  // was 186
        .description = COMPOUND_STRING(
            "Engineered scales drift from its shell\n"
            "with the scent of freshly opened flowers.\n"
            "They close small wounds, but careless use\n"
            "leaves the recipient weak and giddy."),
        .pokemonScale = 338,  // was 282
        .pokemonOffset = 7,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_TapuLele,
        .frontPicSize = MON_COORDS_SIZE(48, 56),
        .frontPicYOffset = 6,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(1, 50),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SLIDE_WOBBLE_SMALL,
        .enemyMonElevation = 8,
        .backPic = gMonBackPic_TapuLele,
        .backPicSize = MON_COORDS_SIZE(56, 56),
        .backPicYOffset = 6,
        .palette = gMonPalette_TapuLele,
        .shinyPalette = gMonShinyPalette_TapuLele,
        .iconSprite = gMonIcon_TapuLele,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 13, SHADOW_SIZE_S)
        FOOTPRINT(TapuLele)
        OVERWORLD(
            sPicTable_TapuLele,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TapuLele,
            gShinyOverworldPalette_TapuLele
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTapuLeleLevelUpLearnset,
        .teachableLearnset = sTapuLeleTeachableLearnset,
    },

    [SPECIES_TAPU_BULU_V] =
    {
        // BST was 570, lowered by ~17%
        .baseHP        = 58,   // was 70
        .baseAttack    = 108,  // was 130
        .baseDefense   = 96,   // was 115
        .baseSpeed     = 63,   // was 75
        .baseSpAttack  = 71,   // was 85
        .baseSpDefense = 79,   // was 95
        .types = MON_TYPES(TYPE_GRASS, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 285 : 257,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_GRASSY_SURGE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("Tapu Bulu-V"),
        .cryId = CRY_TAPU_BULU,
        .natDexNum = NATIONAL_DEX_TAPU_BULU_V,
        .categoryName = _("Land Spirit"),
        .height = 16,   // was 19
        .weight = 379,  // was 455
        .description = COMPOUND_STRING(
            "Plant cells woven through its prototype\n"
            "body let it coax seedlings into trees.\n"
            "It drains some growth back for energy,\n"
            "then uproots the trees and swings them."),
        .pokemonScale = 304,  // was 256
        .pokemonOffset = 2,
        .trainerScale = 390,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_TapuBulu,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(0, 1),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 10),
            ANIMCMD_FRAME(1, 40),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_V_SHAKE_TWICE,
        .enemyMonElevation = 5,
        .backPic = gMonBackPic_TapuBulu,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 1,
        .palette = gMonPalette_TapuBulu,
        .shinyPalette = gMonShinyPalette_TapuBulu,
        .iconSprite = gMonIcon_TapuBulu,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 16, SHADOW_SIZE_M)
        FOOTPRINT(TapuBulu)
        OVERWORLD(
            sPicTable_TapuBulu,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TapuBulu,
            gShinyOverworldPalette_TapuBulu
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTapuBuluLevelUpLearnset,
        .teachableLearnset = sTapuBuluTeachableLearnset,
    },

    [SPECIES_TAPU_FINI_V] =
    {
        // BST was 570, lowered by ~17%
        .baseHP        = 58,   // was 70
        .baseAttack    = 63,   // was 75
        .baseDefense   = 96,   // was 115
        .baseSpeed     = 71,   // was 85
        .baseSpAttack  = 79,   // was 95
        .baseSpDefense = 108,  // was 130
        .types = MON_TYPES(TYPE_WATER, TYPE_FAIRY),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 285 : 257,
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 15,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_MISTY_SURGE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Tapu Fini-V"),
        .cryId = CRY_TAPU_FINI,
        .natDexNum = NATIONAL_DEX_TAPU_FINI_V,
        .categoryName = _("Land Spirit"),
        .height = 11,   // was 13
        .weight = 177,  // was 212
        .description = COMPOUND_STRING(
            "Its artificial shell distills pure water\n"
            "from the moisture in the air.\n"
            "Unable to judge human character, it hides\n"
            "everyone alike within bewildering mist."),
        .pokemonScale = 321,  // was 272
        .pokemonOffset = 5,
        .trainerScale = 302,
        .trainerOffset = 2,
        .frontPic = gMonFrontPic_TapuFini,
        .frontPicSize = MON_COORDS_SIZE(56, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = ANIM_FRAMES(
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(1, 60),
            ANIMCMD_FRAME(0, 1),
        ),
        .frontAnimId = ANIM_SHAKE_GLOW_BLUE_SLOW,
        .frontAnimDelay = 5,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_TapuFini,
        .backPicSize = MON_COORDS_SIZE(64, 56),
        .backPicYOffset = 4,
        .palette = gMonPalette_TapuFini,
        .shinyPalette = gMonShinyPalette_TapuFini,
        .iconSprite = gMonIcon_TapuFini,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 15, SHADOW_SIZE_M)
        FOOTPRINT(TapuFini)
        OVERWORLD(
            sPicTable_TapuFini,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TapuFini,
            gShinyOverworldPalette_TapuFini
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTapuFiniLevelUpLearnset,
        .teachableLearnset = sTapuFiniTeachableLearnset,
    },

    [SPECIES_COSMOG_V] =
    {
        // Solgaleo/Lunala were lowered by ~30%,
        // so we'll do the same
        .baseHP        = 30,  // was 43
        .baseAttack    = 20,  // was 29
        .baseDefense   = 22,  // was 31
        .baseSpeed     = 26,  // was 37
        .baseSpAttack  = 20,  // was 29
        .baseSpDefense = 22,  // was 31
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 40,
        .evYield_HP = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_UNAWARE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cosmog-V"),
        .cryId = CRY_COSMOG,
        .natDexNum = NATIONAL_DEX_COSMOG_V,
        .categoryName = _("Nebula"),
        .height = 2,
        .weight = 1,
        .description = COMPOUND_STRING(
            "A wisp of unstable cells suspended in gas,\n"
            "it resembles a tiny piece of deep space.\n"
            "Innocently, it gathers dust and light,\n"
            "unaware of what its genes may become."),
        .pokemonScale = 887,  // was 682
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cosmog,
        .frontPicSize = MON_COORDS_SIZE(56, 48),
        .frontPicYOffset = 10,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_H_JUMPS_V_STRETCH,
        .enemyMonElevation = 7,
        .backPic = gMonBackPic_Cosmog,
        .backPicSize = MON_COORDS_SIZE(64, 48),
        .backPicYOffset = 10,
        .palette = gMonPalette_Cosmog,
        .shinyPalette = gMonShinyPalette_Cosmog,
        .iconSprite = gMonIcon_Cosmog,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 8, SHADOW_SIZE_S)
        FOOTPRINT(Cosmog)
        OVERWORLD(
            sPicTable_Cosmog,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cosmog,
            gShinyOverworldPalette_Cosmog
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sCosmogLevelUpLearnset,
        .teachableLearnset = sCosmogTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 43, SPECIES_COSMOEM_V}),
    },

    [SPECIES_COSMOEM_V] =
    {
        // Solgaleo/Lunala were lowered by ~30%,
        // so we'll do the same
        .baseHP        = 30,   // was 43
        .baseAttack    = 20,   // was 29
        .baseDefense   = 92,  // was 131
        .baseSpeed     = 26,   // was 37
        .baseSpAttack  = 20,   // was 29
        .baseSpDefense = 92,  // was 131
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 45,
        .expYield = 140,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_STURDY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cosmoem-V"),
        .cryId = CRY_COSMOEM,
        .natDexNum = NATIONAL_DEX_COSMOEM_V,
        .categoryName = _("Protostar"),
        .height = 1,
        .weight = 7000,  // was 9999
        .description = COMPOUND_STRING(
            "Its gaseous cells collapsed into a shell\n"
            "whose core is impossibly dense.\n"
            "It remains warm and still as stellar energy\n"
            "rewrites every strand of its young genome."),
        .pokemonScale = 887,  // was 682
        .pokemonOffset = 24,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_Cosmoem,
        .frontPicSize = MON_COORDS_SIZE(48, 48),
        .frontPicYOffset = 9,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_RISING_WOBBLE,
        .enemyMonElevation = 3,
        .backPic = gMonBackPic_Cosmoem,
        .backPicSize = MON_COORDS_SIZE(64, 40),
        .backPicYOffset = 17,
        .palette = gMonPalette_Cosmoem,
        .shinyPalette = gMonShinyPalette_Cosmoem,
        .iconSprite = gMonIcon_Cosmoem,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(0, 5, SHADOW_SIZE_M)
        FOOTPRINT(Cosmoem)
        OVERWORLD(
            sPicTable_Cosmoem,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Cosmoem,
            gShinyOverworldPalette_Cosmoem
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sCosmoemLevelUpLearnset,
        .teachableLearnset = sCosmoemTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 53, SPECIES_SOLGALEO_V, CONDITIONS({IF_NOT_TIME, TIME_NIGHT})},
                                {EVO_LEVEL, 53, SPECIES_LUNALA_V, CONDITIONS({IF_TIME, TIME_NIGHT})}),
    },

    [SPECIES_SOLGALEO_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 95,   // was 137
        .baseAttack    = 96,   // was 137
        .baseDefense   = 75,   // was 107
        .baseSpeed     = 68,   // was 97
        .baseSpAttack  = 79,   // was 113
        .baseSpDefense = 62,   // was 89
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_STEEL),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_FULL_METAL_BODY, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Solgaleo-V"),
        .cryId = CRY_SOLGALEO,
        .natDexNum = NATIONAL_DEX_SOLGALEO_V,
        .categoryName = _("Sunne"),
        .height = 24,    // was 34
        .weight = 1610,  // was 2300
        .description = COMPOUND_STRING(
            "Solar energy ignites the legendary genes\n"
            "that slept throughout its youth.\n"
            "Its metal body shines like a small sun,\n"
            "turning midnight into a silver dawn."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 3,   // was 0
        .trainerScale = 405,
        .trainerOffset = 8,
        .frontPic = gMonFrontPic_Solgaleo,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .backPic = gMonBackPic_Solgaleo,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 3,
        .palette = gMonPalette_Solgaleo,
        .shinyPalette = gMonShinyPalette_Solgaleo,
        .iconSprite = gMonIcon_Solgaleo,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 11, SHADOW_SIZE_XL_BATTLE_ONLY)
        FOOTPRINT(Solgaleo)
        OVERWORLD(
            sPicTable_Solgaleo,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Solgaleo,
            gShinyOverworldPalette_Solgaleo
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sSolgaleoLevelUpLearnset,
        .teachableLearnset = sSolgaleoTeachableLearnset,
    },

    [SPECIES_LUNALA_V] =
    {
        // BST was 680, lowered by ~30%
        .baseHP        = 95,   // was 137
        .baseAttack    = 79,   // was 113
        .baseDefense   = 62,   // was 89
        .baseSpeed     = 68,   // was 97
        .baseSpAttack  = 96,   // was 137
        .baseSpDefense = 75,   // was 107
        .types = MON_TYPES(TYPE_PSYCHIC, TYPE_GHOST),
        .catchRate = 45,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 340 : 306,
        .evYield_SpAttack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_SHADOW_SHIELD, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_PURPLE,
        .speciesName = _("Lunala-V"),
        .cryId = CRY_LUNALA,
        .natDexNum = NATIONAL_DEX_LUNALA_V,
        .categoryName = _("Moone"),
        .height = 28,   // was 40
        .weight = 840,  // was 1200
        .description = COMPOUND_STRING(
            "Lunar energy awakens dormant genes and\n"
            "spreads its wings into a starry veil.\n"
            "It drinks in surrounding light to open a\n"
            "brief, wavering path to another world."),
        .pokemonScale = 333,  // was 256
        .pokemonOffset = 0,
        .trainerScale = 411,
        .trainerOffset = 5,
        .frontPic = gMonFrontPic_Lunala,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_CIRCULAR_VIBRATE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Lunala,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 2,
        .palette = gMonPalette_Lunala,
        .shinyPalette = gMonShinyPalette_Lunala,
        .iconSprite = gMonIcon_Lunala,
        .iconPalIndex = 2,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(4, 17, SHADOW_SIZE_L)
        FOOTPRINT(Lunala)
        OVERWORLD(
            sPicTable_Lunala,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Lunala,
            gShinyOverworldPalette_Lunala
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sLunalaLevelUpLearnset,
        .teachableLearnset = sLunalaTeachableLearnset,
    },

    [SPECIES_NECROZMA_V] =
    {
        // BST was 600, lowered by ~21%
        .baseHP        = 77,   // was 97
        .baseAttack    = 85,   // was 107
        .baseDefense   = 80,   // was 101
        .baseSpeed     = 62,   // was 79
        .baseSpAttack  = 101,  // was 127
        .baseSpDefense = 70,   // was 89
        .types = MON_TYPES(TYPE_PSYCHIC),
        .catchRate = 3,
        .expYield = (P_UPDATED_EXP_YIELDS >= GEN_8) ? 300 : 270,
        .evYield_Attack = 1,
        .evYield_SpAttack = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRISM_ARMOR, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLACK,
        .noFlip = TRUE,
        .speciesName = _("Necrozma-V"),
        .cryId = CRY_NECROZMA,
        .natDexNum = NATIONAL_DEX_NECROZMA_V,
        .categoryName = _("Prism"),
        .height = 19,    // was 24
        .weight = 1817,  // was 2300
        .description = COMPOUND_STRING(
            "Prismatic cells reject the artificial bonds\n"
            "used to stabilize this life-form.\n"
            "Starved of light, it claws at every bright\n"
            "object as cracks spread across its body."),
        .pokemonScale = 362,  // was 256
        .pokemonOffset = 7,   // was 3
        .trainerScale = 369,
        .trainerOffset = 7,
        .frontPic = gMonFrontPic_Necrozma,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_GROW_VIBRATE,
        .enemyMonElevation = 6,
        .backPic = gMonBackPic_Necrozma,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 4,
        .palette = gMonPalette_Necrozma,
        .shinyPalette = gMonShinyPalette_Necrozma,
        .iconSprite = gMonIcon_Necrozma,
        .iconPalIndex = 1,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(-1, 15, SHADOW_SIZE_M)
        FOOTPRINT(Necrozma)
        OVERWORLD(
            sPicTable_Necrozma,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_Necrozma,
            gShinyOverworldPalette_Necrozma
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sNecrozmaLevelUpLearnset,
        .teachableLearnset = sNecrozmaTeachableLearnset,
    },

    [SPECIES_TYPE_NULL_V] =
    {
        // BST was 534, lowered by ~11%
        .baseHP        = 85,   // was 95
        .baseAttack    = 85,   // was 95
        .baseDefense   = 84,   // was 95
        .baseSpeed     = 52,   // was 59
        .baseSpAttack  = 84,   // was 95
        .baseSpDefense = 85,   // was 95
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 3,
        .expYield = 107,
        .evYield_HP = 2,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_BATTLE_ARMOR, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Type: Null-V"),
        .cryId = CRY_TYPE_NULL,
        .natDexNum = NATIONAL_DEX_TYPE_NULL_V,
        .categoryName = _("Synthetic"),
        .height = 17,    // was 19
        .weight = 1072,  // was 1205
        .description = COMPOUND_STRING(
            "Built from many legendary gene samples,\n"
            "it reacts violently when they clash.\n"
            "Its heavy control mask calms the conflict\n"
            "until trust teaches its mind to master it."),
        .pokemonScale = 288,  // was 256
        .pokemonOffset = 1,
        .trainerScale = 326,
        .trainerOffset = 4,
        .frontPic = gMonFrontPic_TypeNull,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 2,
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,
        .frontAnimId = ANIM_H_SHAKE,
        .backPic = gMonBackPic_TypeNull,
        .backPicSize = MON_COORDS_SIZE(56, 64),
        .backPicYOffset = 1,
        .palette = gMonPalette_TypeNull,
        .shinyPalette = gMonShinyPalette_TypeNull,
        .iconSprite = gMonIcon_TypeNull,
        .iconPalIndex = 0,
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,
        SHADOW(1, 11, SHADOW_SIZE_L)
        FOOTPRINT(Type_Null)
        OVERWORLD(
            sPicTable_TypeNull,
            SIZE_32x32,
            SHADOW_SIZE_M,
            TRACKS_FOOT,
            sAnimTable_Following,
            gOverworldPalette_TypeNull,
            gShinyOverworldPalette_TypeNull
        )
        .isFrontierBanned = FALSE,
        .levelUpLearnset = sTypeNullLevelUpLearnset,
        .teachableLearnset = sTypeNullTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 0, SPECIES_SILVALLY_V_NORMAL, CONDITIONS({IF_MIN_FRIENDSHIP, FRIENDSHIP_EVO_THRESHOLD})}),
    },

#define SILVALLY_V_SPECIES_INFO(type, _palette)                                       \
    {                                                                                 \
        .baseHP        = 80,   /* was 95 */                                           \
        .baseAttack    = 79,   /* was 95 */                                           \
        .baseDefense   = 79,   /* was 95 */                                           \
        .baseSpeed     = 79,   /* was 95 */                                           \
        .baseSpAttack  = 79,   /* was 95 */                                           \
        .baseSpDefense = 79,   /* was 95 */                                           \
        .types = MON_TYPES(TYPE_NORMAL),                                              \
        .catchRate = 3,                                                               \
        .expYield = 257,                                                              \
        .evYield_HP = 3,                                                              \
        .genderRatio = MON_GENDERLESS,                                                \
        .eggCycles = 120,                                                             \
        .friendship = 0,                                                              \
        .growthRate = GROWTH_SLOW,                                                    \
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),                    \
        .abilities = { ABILITY_RKS_SYSTEM, ABILITY_NONE, ABILITY_NONE },              \
        .bodyColor = BODY_COLOR_GRAY,                                                 \
        .speciesName = _("Silvally-V"),                                               \
        .cryId = CRY_SILVALLY,                                                        \
        .natDexNum = NATIONAL_DEX_SILVALLY_V_NORMAL,                                  \
        .categoryName = _("Synthetic"),                                               \
        .height = 19,   /* was 23 */                                                  \
        .weight = 838,  /* was 1005 */                                                \
        .description = (type == TYPE_NORMAL                                           \
            ? gSilvallyVNormalPokedexText                                             \
            : gSilvallyVMemoryPokedexText),                                           \
        .pokemonScale = 307,  /* was 256 */                                           \
        .pokemonOffset = 0,                                                           \
        .trainerScale = 342,                                                          \
        .trainerOffset = 7,                                                           \
        .frontPic = gMonFrontPic_Silvally,                                            \
        .frontPicSize = MON_COORDS_SIZE(64, 64),                                      \
        .frontPicYOffset = 0,                                                         \
        .frontAnimFrames = sAnims_SingleFramePlaceHolder,                             \
        .frontAnimId = ANIM_V_SHAKE,                                                  \
        .backPic = gMonBackPic_Silvally,                                              \
        .backPicSize = MON_COORDS_SIZE(56, 64),                                       \
        .backPicYOffset = 0,                                                          \
        .palette = gMonPalette_SilvallyNormal,                                        \
        .shinyPalette = gMonShinyPalette_SilvallyNormal,                              \
        .iconSprite = gMonIcon_Silvally,                                              \
        .iconPalIndex = 0,                                                            \
        .pokemonJumpType = PKMN_JUMP_TYPE_NONE,                                       \
        SHADOW(1, 13, SHADOW_SIZE_L)                                                  \
        FOOTPRINT(Silvally)                                                           \
        OVERWORLD(                                                                    \
            sPicTable_Silvally,                                                       \
            SIZE_32x32,                                                               \
            SHADOW_SIZE_M,                                                            \
            TRACKS_FOOT,                                                              \
            sAnimTable_Following,                                                     \
            gOverworldPalette_Silvally,                                               \
            gShinyOverworldPalette_Silvally                                           \
        )                                                                             \
        .isFrontierBanned = FALSE,                                                    \
        .levelUpLearnset = sSilvallyLevelUpLearnset,                                  \
        .teachableLearnset = sSilvallyTeachableLearnset,                              \
        .formSpeciesIdTable = sSilvallyVFormSpeciesIdTable,                           \
        .formChangeTable = sSilvallyVFormChangeTable,                                 \
    }

    [SPECIES_SILVALLY_V_NORMAL]   = SILVALLY_V_SPECIES_INFO(TYPE_NORMAL,   Normal),
    [SPECIES_SILVALLY_V_FIGHTING] = SILVALLY_V_SPECIES_INFO(TYPE_FIGHTING, Fighting),
    [SPECIES_SILVALLY_V_FLYING]   = SILVALLY_V_SPECIES_INFO(TYPE_FLYING,   Flying),
    [SPECIES_SILVALLY_V_POISON]   = SILVALLY_V_SPECIES_INFO(TYPE_POISON,   Poison),
    [SPECIES_SILVALLY_V_GROUND]   = SILVALLY_V_SPECIES_INFO(TYPE_GROUND,   Ground),
    [SPECIES_SILVALLY_V_ROCK]     = SILVALLY_V_SPECIES_INFO(TYPE_ROCK,     Rock),
    [SPECIES_SILVALLY_V_BUG]      = SILVALLY_V_SPECIES_INFO(TYPE_BUG,      Bug),
    [SPECIES_SILVALLY_V_GHOST]    = SILVALLY_V_SPECIES_INFO(TYPE_GHOST,    Ghost),
    [SPECIES_SILVALLY_V_STEEL]    = SILVALLY_V_SPECIES_INFO(TYPE_STEEL,    Steel),
    [SPECIES_SILVALLY_V_FIRE]     = SILVALLY_V_SPECIES_INFO(TYPE_FIRE,     Fire),
    [SPECIES_SILVALLY_V_WATER]    = SILVALLY_V_SPECIES_INFO(TYPE_WATER,    Water),
    [SPECIES_SILVALLY_V_GRASS]    = SILVALLY_V_SPECIES_INFO(TYPE_GRASS,    Grass),
    [SPECIES_SILVALLY_V_ELECTRIC] = SILVALLY_V_SPECIES_INFO(TYPE_ELECTRIC, Electric),
    [SPECIES_SILVALLY_V_PSYCHIC]  = SILVALLY_V_SPECIES_INFO(TYPE_PSYCHIC,  Psychic),
    [SPECIES_SILVALLY_V_ICE]      = SILVALLY_V_SPECIES_INFO(TYPE_ICE,      Ice),
    [SPECIES_SILVALLY_V_DRAGON]   = SILVALLY_V_SPECIES_INFO(TYPE_DRAGON,   Dragon),
    [SPECIES_SILVALLY_V_DARK]     = SILVALLY_V_SPECIES_INFO(TYPE_DARK,     Dark),
    [SPECIES_SILVALLY_V_FAIRY]    = SILVALLY_V_SPECIES_INFO(TYPE_FAIRY,    Fairy),

    /*
    [SPECIES_NONE] =
    {
        .baseHP        = 1,
        .baseAttack    = 1,
        .baseDefense   = 1,
        .baseSpeed     = 1,
        .baseSpAttack  = 1,
        .baseSpDefense = 1,
        .types = MON_TYPES(TYPE_MYSTERY),
        .catchRate = 255,
        .expYield = 67,
        .evYield_HP = 1,
        .evYield_Defense = 1,
        .evYield_SpDefense = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_NONE, ABILITY_CURSED_BODY, ABILITY_DAMP },
        .bodyColor = BODY_COLOR_BLACK,
        .speciesName = _("??????????"),
        .cryId = CRY_NONE,
        .natDexNum = NATIONAL_DEX_NONE,
        .categoryName = _("Unknown"),
        .height = 0,
        .weight = 0,
        .description = COMPOUND_STRING(
            "This is a newly discovered Pokémon.\n"
            "It is currently under investigation.\n"
            "No detailed information is available\n"
            "at this time."),
        .pokemonScale = 256,
        .pokemonOffset = 0,
        .trainerScale = 256,
        .trainerOffset = 0,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_None,
        //.frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 7,
#if P_GENDER_DIFFERENCES
        .frontPicFemale = gMonFrontPic_CircledQuestionMark,
        .frontPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .backPicFemale = gMonBackPic_CircledQuestionMarkF,
        .backPicSizeFemale = MON_COORDS_SIZE(64, 64),
        .paletteFemale = gMonPalette_CircledQuestionMarkF,
        .shinyPaletteFemale = gMonShinyPalette_CircledQuestionMarkF,
        .iconSpriteFemale = gMonIcon_QuestionMarkF,
        .iconPalIndexFemale = 1,
#endif //P_GENDER_DIFFERENCES
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
        .evolutions = EVOLUTION({EVO_LEVEL, 100, SPECIES_NONE},
                                {EVO_ITEM, ITEM_MOOMOO_MILK, SPECIES_NONE}),
        //.formSpeciesIdTable = sNoneFormSpeciesIdTable,
        //.formChangeTable = sNoneFormChangeTable,
        //.perfectIVCount = NUM_STATS,
    },
    */

    //
    // Notes for other parameters https://rh-hideout.github.io/pokeemerald-expansion/tutorials/how_to_new_pokemon.html
    // isLegendary - does nothing
    // isMythical - skipped during pokedex evals, cannot obtain gigantamax factor
    // isUltraBeast - sets catch multipler to 5x beast ball, 0.1x for rest
    // isParadox - booster energy can't be knocked from 
    // isTotem - does nothing
    // isMegaEvolution - only for megas
    // isPrimalReversion - only for primals
    // isUltraBurst - only for ultra burst forms
    // isGigantamax - only for gigantamax forms
    // isAlolanForm, isGalarianForm, isHisuianForm, isPaldeanForm - regionals
    // tmIlliterate - can't learn universal TMs
    //
};

const struct EggData gEggDatas[EGG_ID_COUNT] =
{
#include "egg_data.h"
};
