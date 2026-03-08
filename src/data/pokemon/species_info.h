#include "constants/abilities.h"
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
    .affineAnims = gDummySpriteAffineAnimTable,                                                                                         \
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
        .cryId = CRY_NONE,
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
            .affineAnims = gDummySpriteAffineAnimTable,
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

    // TODO: Descriptions

    // Mini legendaries had their stats lowered to 475 BST
    // Each stat was lowered by a percentage to achieve this
    // Sizes and weights were lowered by the same percentage

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
            "A Pokémon that was created by genetic\n"
            "manipulation. However, even though the\n"
            "scientific power of humans made its body,\n"
            "they failed to give it a warm heart."),
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
            "Articuno is a legendary bird Pokémon that\n"
            "can control ice. The flapping of its wings\n"
            "chills the air. As a result, it is said that\n"
            "when this Pokémon flies, snow will fall."),
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
            "Zapdos is a legendary bird Pokémon that\n"
            "has the ability to control electricity.\n"
            "It usually lives in thunderclouds. It gains\n"
            "power if it is stricken by lightning bolts."),
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
            "Moltres is a legendary bird Pokémon\n"
            "that can control fire. If injured, it is said\n"
            "to dip its body in the molten magma of\n"
            "a volcano to burn and heal itself."),
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
            "Raikou embodies the speed of lightning.\n"
            "Its roars send shock waves shuddering\n"
            "through the air and ground as if\n"
            "lightning bolts were crashing down."),
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
            "Entei embodies the passion of magma.\n"
            "It is thought to have been born in the\n"
            "eruption of a volcano. It blasts fire that\n"
            "consumes all that it touches."),
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
            "Suicune embodies the compassion of\n"
            "a pure spring of water. It runs across\n"
            "the land with gliding elegance. It has the\n"
            "power to purify dirty water."),
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
            "Lugia is so powerful even a light\n"
            "fluttering of its wings can blow apart\n"
            "houses. As a result, it chooses to live out\n"
            "of sight deep under the sea."),
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
            "Its feathers--which glow in seven colors\n"
            "depending on the angle at which they are\n"
            "struck by light--are thought to bring joy.\n"
            "It is said to live at the foot of a rainbow."),
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
            "A Pokemon that is made entirely of rocks\n"
            "and boulders. If parts of its body chip off\n"
            "in battle, Regirock repairs itself by\n"
            "adding new rocks."),
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
            "Its entire body is made of Antarctic ice.\n"
            "After extensive studies, researchers\n"
            "believe the ice was formed during an\n"
            "ice age."),
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
            "Its body is harder than any other kind of\n"
            "metal. The body metal is composed of a\n"
            "mysterious substance. Not only is it hard,\n"
            "it shrinks and stretches flexibly."),
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
            "They make a small herd of only several\n"
            "members. They rarely make contact with\n"
            "people or other Pokemon. They disappear\n"
            "if they sense enemies."),
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
            "Even in hiding, it can detect the locations\n"
            "of others and sense their emotions since\n"
            "it has telepathy. Its intelligence allows\n"
            "it to understand human languages."),
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
            "Kyogre has appeared in mythology as the\n"
            "creator of the sea. After long years of\n"
            "feuding with Groudon, it took to sleep at\n"
            "the bottom of the sea."),
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
            "Groudon has appeared in mythology as the\n"
            "creator of the land. It sleeps in magma\n"
            "underground and is said to make volcanoes\n"
            "erupt on awakening."),
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
            "A Pokemon that flies endlessly in the\n"
            "ozone layer. It is said it would descend\n"
            "to the ground if Kyogre and Groudon\n"
            "were to fight."),
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it still carries the mystical\n"
            "knowledge of its ancestral form."),
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it still possesses the\n"
            "emotional essence of its ancestral form."),
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it still carries the\n"
            "determination of its ancestral form."),
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, the power of time still\n"
            "flows within its ancient form."),
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it retains an innate hold\n"
            "over the fabric of space."),
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
    },

    [SPECIES_GIRATINA_V] =
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
            "A Pokémon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, its violent nature and\n"
            "renegade spirit live on within it."),
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, molten energy still surges\n"
            "through its armored body."),
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, traces of colossal strength\n"
            "remain in its ancient frame."),
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it still carries the calm\n"
            "aura of moonlight and dreams."),
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_Defense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_BLUE,
        .speciesName = _("Cobalion-V"),
        .cryId = CRY_COBALION,
        .natDexNum = NATIONAL_DEX_COBALION_V,
        .categoryName = _("Iron Will"),
        .height = 17,   // was 21
        .weight = 2050, // was 2500
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, its steadfast spirit and\n"
            "iron will still endure."),
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_Attack = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .speciesName = _("Terrakion-V"),
        .cryId = CRY_TERRAKION,
        .natDexNum = NATIONAL_DEX_TERRAKION_V,
        .categoryName = _("Cavern"),
        .height = 16,   // was 19
        .weight = 2132, // was 2600
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, its rock-solid body still\n"
            "holds tremendous defensive might."),
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
        .evYield_SpDefense = 3,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 80,
        .friendship = 35,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_JUSTIFIED, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GREEN,
        .speciesName = _("Virizion-V"),
        .cryId = CRY_VIRIZION,
        .natDexNum = NATIONAL_DEX_VIRIZION_V,
        .categoryName = _("Grassland"),
        .height = 16,   // was 20
        .weight = 1640, // was 2000
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, it still moves with the\n"
            "grace of a bladed whirlwind."),
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

    [SPECIES_TORNADUS_V] =
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
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
        .weight = 517, // was 630
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, fierce gales still gather\n"
            "in the wake of its flight."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 4,   // was 2
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
    },

    [SPECIES_THUNDURUS_V] =
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 290,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 261,
    #else
        .expYield = 210,
    #endif
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, violent thunder still\n"
            "surges from its tail."),
        .pokemonScale = 316,  // was 268
        .pokemonOffset = 4,   // was 2
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
    },

    [SPECIES_LANDORUS_V] =
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 300,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 270,
    #else
        .expYield = 220,
    #endif
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, fertile winds still follow\n"
            "wherever it takes flight."),
        .pokemonScale = 324,  // was 268
        .pokemonOffset = 4,   // was 2
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
        .abilities = { ABILITY_TURBOBLAZE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_WHITE,
        .speciesName = _("Reshiram-V"),
        .cryId = CRY_RESHIRAM,
        .natDexNum = NATIONAL_DEX_RESHIRAM_V,
        .categoryName = _("Vast White"),
        .height = 22,   // was 32
        .weight = 2310, // was 3300
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, white-hot flames still\n"
            "burn in its draconic core."),
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 340,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 306,
    #else
        .expYield = 220,
    #endif
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
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, thunder still crackles\n"
            "through its internal generator."),
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
    #if P_UPDATED_EXP_YIELDS >= GEN_8
        .expYield = 330,
    #elif P_UPDATED_EXP_YIELDS >= GEN_5
        .expYield = 297,
    #else
        .expYield = 220,
    #endif
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_SpAttack = 1,
        .genderRatio = MON_GENDERLESS,
        .eggCycles = 120,
        .friendship = 0,
        .growthRate = GROWTH_SLOW,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_NO_EGGS_DISCOVERED),
        .abilities = { ABILITY_PRESSURE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_GRAY,
        .noFlip = TRUE,
        .speciesName = _("Kyurem-V"),
        .cryId = CRY_KYUREM,
        .natDexNum = NATIONAL_DEX_KYUREM_V,
        .categoryName = _("Boundary"),
        .height = 21,   // was 30
        .weight = 2275, // was 3250
        .description = COMPOUND_STRING(
            "A Pokemon that was created by genetic\n"
            "manipulation. Though it exists as a\n"
            "proto-type, frigid draconic power still\n"
            "lingers in its frozen shell."),
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
    },

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
};
