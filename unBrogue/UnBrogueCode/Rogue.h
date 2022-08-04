/*
 *  Rogue.h
 *  UnBrogue
 *
 *  Brogue created by Brian Walker on 1/10/09.
 *  Copyright 2012. All rights reserved.
 *
 *  UnBrogue created by Andrew Doull on 1/8/12.
 *  Copyright 2013. All rights reserved.
 *
 *  This file is part of UnBrogue, a 'variant' of Brogue in the
 *  tradition of Angband variants.
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Affero General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Affero General Public License for more details.
 *
 *  You should have received a copy of the GNU Affero General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlatformDefines.h"

// unicode: comment this line to revert to ASCII

#define USE_UNICODE

// version string -- no more than 16 bytes:
#define BROGUE_VERSION_STRING "un1.1.3"

// debug macros -- define DEBUGGING as 1 to enable debugging.

#define DEBUGGING						0
#define DEBUG							if (DEBUGGING)
#define MONSTERS_ENABLED				(!DEBUGGING || 1) // Quest room monsters can be generated regardless.
#define ITEMS_ENABLED					(!DEBUGGING || 1)

#define D_BULLET_TIME					(DEBUGGING && 0)
#define D_SAFETY_VISION					(DEBUGGING && 0)
#define D_EMPHASIZE_LIGHTING_LEVELS		(DEBUGGING && 0)
#define D_WORMHOLING					(DEBUGGING && 1)
#define D_IMMORTAL						(DEBUGGING && 1)
#define D_INSPECT_LEVELGEN				(DEBUGGING && 0)
#define D_INSPECT_MACHINES				(DEBUGGING && 0)

// set to false to allow multiple loads from the same saved file:
#define DELETE_SAVE_FILE_AFTER_LOADING	true

//#define BROGUE_ASSERTS		// introduces several assert()s -- useful to find certain array overruns
//#define AUDIT_RNG			// VERY slow, but sometimes necessary to debug out-of-sync recording errors
//#define GENERATE_FONT_FILES	// Displays font in grid upon startup, which can be screen-captured into font files for PC.

#ifdef BROGUE_ASSERTS
#include <assert.h>
#endif

#define boolean					char

#define false					0
#define true					1

#define Fl(N)					(1 << (N))

#define PI 3.14159265

// recording and save filenames
#define LAST_GAME_PATH			"LastGame.broguesave"
#define LAST_GAME_NAME          "LastGame"
#define RECORDING_SUFFIX		".broguerec"
#define GAME_SUFFIX				".broguesave"
#define ANNOTATION_SUFFIX		".txt"
#define RNG_LOG					"RNGLog.txt"

#define BROGUE_FILENAME_MAX		(min(1024*4, FILENAME_MAX))

// Allows unicode characters:
#define uchar					unsigned short

#define MESSAGE_LINES			3
#define MESSAGE_ARCHIVE_LINES	ROWS

// Size of the entire terminal window. These need to be hard-coded here and in Viewport.h
#define COLS					100
#define ROWS					(31 + MESSAGE_LINES)

// Size of the portion of the terminal window devoted to displaying the dungeon:
#define DCOLS					(COLS - STAT_BAR_WIDTH - 1)
#define DROWS					(ROWS - MESSAGE_LINES - 2)	// n lines at the top for messages;
															// one line at the bottom for flavor text;
															// another line at the bottom for the menu bar.

#define STAT_BAR_WIDTH			20			// number of characters in the stats bar to the left of the map

#define LOS_SLOPE_GRANULARITY	32768		// how finely we divide up the squares when calculating slope;
											// higher numbers mean fewer artifacts but more memory and processing
#define INTERFACE_OPACITY		95

#define MAX_BOLT_LENGTH			DCOLS*10

#define VISIBILITY_THRESHOLD	50			// how bright cumulative light has to be before the cell is marked visible

#define AMULET_LEVEL			26			// how deep before the amulet appears

#define MACHINES_FACTOR         1.0         // use this to adjust machine frequency

#define MACHINES_BUFFER_LENGTH  100

#define DEFENSE_FACTOR			0.987		// Each point of armor multiplies enemy attackers' accuracy by this value.
											// (displayed armor value is 10% of the real value)
#define WEAPON_ENCHANT_DAMAGE_FACTOR        1.065		// Each marginal point of weapon enchantment
														// multiplies damage by this factor.
#define WEAPON_ENCHANT_ACCURACY_FACTOR      1.065		// Each marginal point of weapon enchantment
														// multiplies accuracy by this factor.

#define WEAPON_KILLS_TO_AUTO_ID	20
#define ARMOR_DELAY_TO_AUTO_ID	1000
#define SHIELD_DELAY_TO_AUTO_ID	500
#define RING_DELAY_TO_AUTO_ID	1500

#define FALL_DAMAGE_MIN         6
#define FALL_DAMAGE_MAX         12

#define INPUT_RECORD_BUFFER		1000		// how many bytes of input data to keep in memory before vomiting it to disk
#define DEFAULT_PLAYBACK_DELAY	50

#define HIGH_SCORES_COUNT		30

// color escapes
#define COLOR_ESCAPE			25
#define COLOR_VALUE_INTERCEPT	25

// display characters:

#ifdef USE_UNICODE

#define FLOOR_CHAR		0x00b7
#define LIQUID_CHAR		'~'
#define CHASM_CHAR		0x2237
#define TRAP_CHAR		0x25c7
#define FIRE_CHAR		0x22CF
#define GRASS_CHAR		'"'
#define BRIDGE_CHAR		'='
#define DESCEND_CHAR	'>'
#define ASCEND_CHAR		'<'
#define WALL_CHAR		'#'
#define DOOR_CHAR		'+'
#define OPEN_DOOR_CHAR	'\''
#define ASH_CHAR		'\''
#define BONES_CHAR		','
#define MUD_CHAR		','
#define WEB_CHAR		':'
//#define FOLIAGE_CHAR	0x03A8 // lower-case psi
//#define FOLIAGE_CHAR	0x2648 // Aries symbol
#define FOLIAGE_CHAR 0x03C8
#define ALTAR_CHAR		'|'
#define LEVER_CHAR      '/'
#define LEVER_PULLED_CHAR '\\'
#define STATUE_CHAR		0x00df
#define VENT_CHAR		'='

#define TRAMPLED_FOLIAGE_CHAR	'"'		// 0x2034 // 0x2037

#define PLAYER_CHAR		'@'

#define AMULET_CHAR		0x2640
#define FOOD_CHAR		':'
#define SCROLL_CHAR		0x266A//'?'		// 0x039E
#define TOME_CHAR		0x00BF
//#define RING_CHAR		0x26AA //0xffee
#define RING_CHAR		'o'
//#define CHARM_CHAR      0x03DE
#define CHARM_CHAR      0x03DF
#define TALISMAN_CHAR	'$'
#define POTION_CHAR		'!'
#define ELIXIR_CHAR		0x00A1
#define ARMOR_CHAR		'['
#define SHIELD_CHAR		'{'
#define WEAPON_CHAR		0x2191
#define STAFF_CHAR		'\\'
#define WAND_CHAR		'~'
#define GOLD_CHAR		'*'
#define GEM_CHAR		0x25cf
#define TOTEM_CHAR		0x26b2
#define TURRET_CHAR		0x25cf
#define UNICORN_CHAR    0x00da
#define KEY_CHAR		'-'
#define GRAFFITI_CHAR	','

#define UP_ARROW_CHAR		0x2191
#define DOWN_ARROW_CHAR		0x2193
#define LEFT_ARROW_CHAR		0x2190
#define RIGHT_ARROW_CHAR	0x2192
#define UP_TRIANGLE_CHAR	0x2206
#define DOWN_TRIANGLE_CHAR	0x2207
#define OMEGA_CHAR			0x03A9
#define THETA_CHAR			0x03B8
#define LAMDA_CHAR			0x03BB
//#define KOPPA_CHAR			0x03DE
//#define LOZENGE_CHAR		0x29EB
#define KOPPA_CHAR            0x03DF
#define LOZENGE_CHAR          0x25C6
#define CROSS_PRODUCT_CHAR	0x2A2F

#define CHAIN_TOP_LEFT		'\\'
#define CHAIN_BOTTOM_RIGHT	'\\'
#define CHAIN_TOP_RIGHT		'/'
#define CHAIN_BOTTOM_LEFT	'/'
#define CHAIN_TOP			'|'
#define CHAIN_BOTTOM		'|'
#define CHAIN_LEFT			'-'
#define CHAIN_RIGHT			'-'

#define IMPALE_UPLEFT		'\\'
#define IMPALE_DOWNRIGHT	'\\'
#define IMPALE_UPRIGHT		'/'
#define IMPALE_DOWNLEFT		'/'
#define IMPALE_UP			0x2191
#define IMPALE_DOWN			0x2193
#define IMPALE_LEFT			0x2190
#define IMPALE_RIGHT		0x2192

#define BAD_MAGIC_CHAR		0x29F2
#define GOOD_MAGIC_CHAR		0x29F3

#else

#define FLOOR_CHAR		'.'
#define LIQUID_CHAR		'~'
#define CHASM_CHAR		':'
#define TRAP_CHAR		'%'
#define FIRE_CHAR		'^'
#define GRASS_CHAR		'"'
#define BRIDGE_CHAR		'='
#define DESCEND_CHAR	'>'
#define ASCEND_CHAR		'<'
#define WALL_CHAR		'#'
#define DOOR_CHAR		'+'
#define OPEN_DOOR_CHAR	'\''
#define ASH_CHAR		'\''
#define BONES_CHAR		','
#define MUD_CHAR		','
#define WEB_CHAR		':'
#define FOLIAGE_CHAR	'&'
#define ALTAR_CHAR		'|'
#define LEVER_CHAR      '/'
#define LEVER_PULLED_CHAR '\\'
#define STATUE_CHAR		'&'
#define VENT_CHAR		'='

#define TRAMPLED_FOLIAGE_CHAR	'"'

#define PLAYER_CHAR		'@'

#define AMULET_CHAR		','
#define FOOD_CHAR		':'
#define SCROLL_CHAR		'?'
#define TOME_CHAR		'?'
#define RING_CHAR		'='
#define RING_CHAR		'+'
#define TALISMAN_CHAR	'$'
#define POTION_CHAR		'!'
#define ELIXIR_CHAR		'!'
#define ARMOR_CHAR		'['
#define SHIELD_CHAR		'{'
#define WEAPON_CHAR		'('
#define STAFF_CHAR		'\\'
#define WAND_CHAR		'~'
#define GOLD_CHAR		'*'
#define GEM_CHAR		'+'
#define TOTEM_CHAR		'0'
#define TURRET_CHAR		'*'
#define UNICORN_CHAR    'U'
#define KEY_CHAR		'-'
#define GRAFFITI_CHAR	','

#define UP_ARROW_CHAR		'^'
#define DOWN_ARROW_CHAR		'v'
#define LEFT_ARROW_CHAR		'<'
#define RIGHT_ARROW_CHAR	'>'
#define UP_TRIANGLE_CHAR	'^'
#define DOWN_TRIANGLE_CHAR	'v'
#define OMEGA_CHAR			'^'
#define THETA_CHAR			'0'
#define LAMDA_CHAR			'\\'
#define KOPPA_CHAR			'k'
#define LOZENGE_CHAR		'+'
#define CROSS_PRODUCT_CHAR	'x'

#define CHAIN_TOP_LEFT		'\\'
#define CHAIN_BOTTOM_RIGHT	'\\'
#define CHAIN_TOP_RIGHT		'/'
#define CHAIN_BOTTOM_LEFT	'/'
#define CHAIN_TOP			'|'
#define CHAIN_BOTTOM		'|'
#define CHAIN_LEFT			'-'
#define CHAIN_RIGHT			'-'

#define IMPALE_UPLEFT		'\\'
#define IMPALE_DOWNRIGHT	'\\'
#define IMPALE_UPRIGHT		'/'
#define IMPALE_DOWNLEFT		'/'
#define IMPALE_UP			'|'
#define IMPALE_DOWN			'|'
#define IMPALE_LEFT			'-'
#define IMPALE_RIGHT		'-'

#define BAD_MAGIC_CHAR		'+'
#define GOOD_MAGIC_CHAR		'$'

#endif

enum eventTypes {
	KEYSTROKE,
	MOUSE_UP,
	MOUSE_DOWN,
	RIGHT_MOUSE_DOWN,
	RIGHT_MOUSE_UP,
	MOUSE_ENTERED_CELL,
	RNG_CHECK,
	SAVED_GAME_LOADED,
	END_OF_RECORDING,
	EVENT_ERROR,
	NUMBER_OF_EVENT_TYPES, // unused
};

enum notificationEventTypes {
	GAMEOVER_QUIT,
	GAMEOVER_DEATH,
	GAMEOVER_VICTORY,
	GAMEOVER_SUPERVICTORY,
	GAMEOVER_RECORDING
};

typedef struct rogueEvent {
	enum eventTypes eventType;
	signed long param1;
	signed long param2;
	boolean controlKey;
	boolean shiftKey;
} rogueEvent;

typedef struct rogueHighScoresEntry {
	signed long score;
	char date[100];
	char description[DCOLS];
} rogueHighScoresEntry;

typedef struct fileEntry {
	char *path;
	char date[100];
} fileEntry;

enum RNGs {
	RNG_SUBSTANTIVE,
	RNG_COSMETIC,
	NUMBER_OF_RNGS,
};

enum displayDetailValues {
	DV_UNLIT = 0,
	DV_LIT,
	DV_DARK,
};

enum directions {
	NO_DIRECTION	= -1,
	// Cardinal directions; must be 0-3:
	UP				= 0,
	DOWN			= 1,
	LEFT			= 2,
	RIGHT			= 3,
	// Secondary directions; must be 4-7:
	UPLEFT			= 4,
	DOWNLEFT		= 5,
	UPRIGHT			= 6,
	DOWNRIGHT		= 7
};

enum textEntryTypes {
	TEXT_INPUT_NORMAL = 0,
	TEXT_INPUT_NUMBERS,
	TEXT_INPUT_TYPES,
};

#define NUMBER_DYNAMIC_COLORS	6

enum tileType {
	NOTHING = 0,
	GRANITE,
	FLOOR,
	FLOOR_FLOODABLE,
	CARPET,
	TOP_WALL,
	BOTTOM_WALL,
	LEFT_WALL,
	RIGHT_WALL,
	PERM_WALL, // e.g. corners of rooms: any tiles that should show up as '#' but cannot be cut into a door.
	DOOR,
	OPEN_DOOR,
	SECRET_DOOR,
	LOCKED_DOOR,
	OPEN_IRON_DOOR_INERT,
	OPEN_IRON_DOOR_OFF,
	OPEN_IRON_DOOR_ON,
	VAULT_DOOR,
	OPEN_VAULT_DOOR,
	ADD_OBSIDIAN_WALL,
	DOWN_STAIRS,
	UP_STAIRS,
	DUNGEON_EXIT,
	TORCH_WALL, // wall lit with a torch
	CRYSTAL_WALL,
	PORTCULLIS_CLOSED,
	PORTCULLIS_DORMANT,
	ADD_WOODEN_BARRICADE,
	WOODEN_BARRICADE,
	PILOT_LIGHT_DORMANT,
	PILOT_LIGHT,
    HAUNTED_TORCH_DORMANT,
    HAUNTED_TORCH_TRANSITIONING,
    HAUNTED_TORCH,
    WALL_LEVER_HIDDEN,
    WALL_LEVER,
    WALL_LEVER_PULLED,
    WALL_LEVER_HIDDEN_DORMANT,
	STATUE_INERT,
	STATUE_DORMANT,
	STATUE_CRACKING,
	PORTAL,
	TURRET_DORMANT,
	WALL_MONSTER_DORMANT,
	DARK_FLOOR_DORMANT,
	DARK_FLOOR_DARKENING,
	DARK_FLOOR,
	MACHINE_TRIGGER_FLOOR,
	ALTAR_INERT,
	ALTAR_FLOODABLE,
	ALTAR_CAGE_INERT,
	ALTAR_KEYHOLE,
	ALTAR_CAGE_OPEN,
	ALTAR_CAGE_CLOSED,
	ALTAR_SWITCH_OFF,
	ALTAR_SWITCH_ON,
	ALTAR_SWITCH_OPEN,
	ALTAR_SWITCH_CLOSED,
	ALTAR_DOOR_OPEN,
	ALTAR_DOOR_CLOSED,
	ALTAR_STOLEN,
	ALTAR_SWITCH,
	ALTAR_SWITCH_RETRACTING,
	ALTAR_CAGE_RETRACTABLE,
	ALTAR_CAGE_REVEAL,
	ALTAR_CAGE_REWARD,
	ALTAR_CAGE_PUNISH,
	ALTAR_ITEM_GAMBLE,
	ALTAR_ITEM_GAMBLED,
	GRAFFITI_1,
	GRAFFITI_2,
	GRAFFITI_3,
	GRAFFITI_4,
	PEDESTAL,
	MONSTER_CAGE_OPEN,
	MONSTER_CAGE_CLOSED,
	COFFIN_CLOSED,
	COFFIN_OPEN,
	ALEMBIC_POTION_OPEN,
	ALEMBIC_POTION_BURNED,
	CONTAINER_DARTS_CLOSED,
	CONTAINER_DARTS_OPEN,
	ALEMBIC_POTION_UNUSED,
	ALEMBIC_POTION_BURN_UNUSED,
	ALEMBIC_POTION_LOADED,
	ALEMBIC_POTION_BURN_LOADED,
	ALEMBIC_POTION_USED,
	PRESS_SCROLL_OPEN,
	PRESS_SCROLL_UNUSED,
	PRESS_SCROLL_BURN_UNUSED,
	PRESS_WEAPON_UNUSED,
	PRESS_ARMOR_UNUSED,
	PRESS_SHIELD_UNUSED,
	PRESS_WAND_UNUSED,
	PRESS_STAFF_UNUSED,
	PRESS_RUNE_UNUSED,
	PRESS_RUNE_WAND_UNUSED,
	PRESS_RUNE_STAFF_UNUSED,
	PRESS_SCROLL_LOADED,
	PRESS_SCROLL_BURN_LOADED,
	PRESS_WEAPON_LOADED,
	PRESS_ARMOR_LOADED,
	PRESS_SHIELD_LOADED,
	PRESS_RUNE_LOADED,
	PRESS_WAND_LOADED,
	PRESS_STAFF_LOADED,
	PRESS_RUNE_WAND_LOADED,
	PRESS_RUNE_STAFF_LOADED,
	PRESS_USED,
	ALTAR_STAFF_SACRIFICE,
	ALTAR_FOOD_SACRIFICE,
	ALTAR_RING_SACRIFICE,
	ALTAR_GEM_SACRIFICE,
	ALTAR_SACRIFICE_REWARD,
	ALTAR_SACRIFICED,
	ALTAR_CHARM_LOADED,
	ARENA_CAGE_OPEN,
	ARENA_CAGE_CLOSED,
	CRYSTAL_PRISM,
	CHAMBER_OPEN,
	CHAMBER_CLOSED,
	CAPACITOR_UNCHARGED,
	CAPACITOR_CHARGED,
	CAPACITOR_DISCHARGED,

	GAS_TRAP_POISON_HIDDEN,
	GAS_TRAP_POISON,
	TRAP_DOOR_HIDDEN,
	TRAP_DOOR,
	GAS_TRAP_PARALYSIS_HIDDEN,
	GAS_TRAP_PARALYSIS,
    MACHINE_PARALYSIS_VENT_HIDDEN,
    MACHINE_PARALYSIS_VENT,
	GAS_TRAP_CONFUSION_HIDDEN,
	GAS_TRAP_CONFUSION,
	FLAMETHROWER_DORMANT,	// unlike the vents, this isn't searchable first
	FLAMETHROWER_HIDDEN,
	FLAMETHROWER,
	FLOOD_TRAP_HIDDEN,
	FLOOD_TRAP,
	MACHINE_POISON_GAS_VENT_HIDDEN,
	MACHINE_POISON_GAS_VENT_DORMANT,
	MACHINE_POISON_GAS_VENT,
	MACHINE_METHANE_VENT_HIDDEN,
	MACHINE_METHANE_VENT_DORMANT,
	MACHINE_METHANE_VENT,
	STEAM_VENT,
	WIND_VENT,
	MACHINE_PRESSURE_PLATE,
    MACHINE_PRESSURE_PLATE_USED,
    MACHINE_GLYPH,
    MACHINE_GLYPH_INACTIVE,

	DEEP_WATER,
	SHALLOW_WATER,
	MUD,
	CHASM,
	CHASM_EDGE,
	MACHINE_COLLAPSE_EDGE_DORMANT,
	MACHINE_COLLAPSE_EDGE_SPREADING,
	LAVA,
	LAVA_RETRACTABLE,
	LAVA_RETRACTING,
	SUNLIGHT_POOL,
	DARKNESS_PATCH,
	ACTIVE_BRIMSTONE,
	INERT_BRIMSTONE,
	OBSIDIAN,
	OBSIDIAN_SHELL,
	OBSIDIAN_CRACKING,
	OBSIDIAN_RUPTURING,
	BRIDGE,
	BRIDGE_EDGE,
	STONE_BRIDGE,
	MACHINE_FLOOD_WATER_DORMANT,
	MACHINE_FLOOD_WATER_SPREADING,
	MACHINE_MUD_DORMANT,

	HOLE,
	HOLE_GLOW,
	HOLE_EDGE,
	FLOOD_WATER_DEEP,
	FLOOD_WATER_SHALLOW,
	GRASS,
	DEAD_GRASS,
	GRAY_FUNGUS,
	LUMINESCENT_FUNGUS,
	LICHEN,
	HAY,
	RED_BLOOD,
	GREEN_BLOOD,
	PURPLE_BLOOD,
	ACID_SPLATTER,
	VOMIT,
	URINE,
	UNICORN_POOP,
	WORM_BLOOD,
	ASH,
	BURNED_CARPET,
	PUDDLE,
	BONES,
	RUBBLE,
	JUNK,
	ECTOPLASM,
	EMBERS,
	SPIDERWEB,
	FOLIAGE,
	DEAD_FOLIAGE,
	TRAMPLED_FOLIAGE,
	FUNGUS_FOREST,
	TRAMPLED_FUNGUS_FOREST,
	CREEPER_FUNGUS,
	TRAMPLED_CREEPER_FUNGUS,
	FORCEFIELD,
	MANACLE_TL,
	MANACLE_BR,
	MANACLE_TR,
	MANACLE_BL,
	MANACLE_T,
	MANACLE_B,
	MANACLE_L,
	MANACLE_R,
	PORTAL_LIGHT,
    GUARDIAN_GLOW,
	STICKY_BUNDLE_DORMANT,
	STICKY_BUNDLE_EMPTY,
	BURNING_BUNDLE,
	SPIDERWEB_DORMANT,
	GRAPPLE_CHAIN,

	PLAIN_FIRE,
	BRIMSTONE_FIRE,
	FLAMEDANCER_FIRE,
	GAS_FIRE,
	GAS_EXPLOSION,
	DART_EXPLOSION,
	POISON_GAS,
	CONFUSION_GAS,
	ROT_GAS,
	PARALYSIS_GAS,
	METHANE_GAS,
	STEAM,
	SUNLIGHT_CLOUD,
	DARKNESS_CLOUD,
    HEALING_CLOUD,
	WIND,
	EXTINGUISH_GAS,

	WITCH_HAZEL_FLOWER,

	MANDRAKE_ROOT_MACHINE,
	DEAD_MANDRAKE_ROOT,
	MANDRAKE_SAC_MACHINE,
	SPLIT_MANDRAKE_SAC,
	MANDRAKE_ROOT_NATURE,
	MANDRAKE_SAC_NATURE,

	STINKFRUIT_STALK,
	STINKFRUIT_POD,
    STINKFRUIT_STALK_DYING,

    BLOODFLOWER_STALK,
    BLOODFLOWER_POD,
    BLOODFLOWER_STALK_DYING,

    DEEP_WATER_ALGAE_WELL,
    DEEP_WATER_ALGAE_1,
    DEEP_WATER_ALGAE_2,

	CHASM_WITH_HIDDEN_BRIDGE,
	CHASM_WITH_HIDDEN_BRIDGE_ACTIVE,
	MACHINE_CHASM_EDGE,

    RAT_TRAP_WALL_DORMANT,
    RAT_TRAP_WALL_CRACKING,

    WORM_TUNNEL_MARKER_DORMANT,
    WORM_TUNNEL_MARKER_ACTIVE,
    WORM_TUNNEL_OUTER_WALL,

	NUMBER_TILETYPES,
	UNFILLED_LAKE = 120	// used to mark lakes not yet assigned a liquid type
};

enum lightType {
	NO_LIGHT,
	MINERS_LIGHT,
	BURNING_CREATURE_LIGHT,
	WISP_LIGHT,
	SALAMANDER_LIGHT,
	IMP_LIGHT,
	PIXIE_LIGHT,
	LICH_LIGHT,
	FLAMEDANCER_LIGHT,
	SENTINEL_LIGHT,
	UNICORN_LIGHT,
	IFRIT_LIGHT,
	PHOENIX_LIGHT,
	PHOENIX_EGG_LIGHT,
	SPECTRAL_BLADE_LIGHT,
	SPECTRAL_IMAGE_LIGHT,
	SPARK_TURRET_LIGHT,
	BOLT_LIGHT_SOURCE,
	TELEPATHY_LIGHT,
	MARKED_LIGHT,
	REFLECTIVE_CREATURE_LIGHT,

	TORCH_LIGHT,
	LAVA_LIGHT,
	SUN_LIGHT,
	DARKNESS_PATCH_LIGHT,
	FUNGUS_LIGHT,
	FUNGUS_FOREST_LIGHT,
    LUMINESCENT_ALGAE_BLUE_LIGHT,
    LUMINESCENT_ALGAE_GREEN_LIGHT,
	ECTOPLASM_LIGHT,
	UNICORN_POOP_LIGHT,
	EMBER_LIGHT,
	FIRE_LIGHT,
	BRIMSTONE_FIRE_LIGHT,
	EXPLOSION_LIGHT,
	INCENDIARY_DART_LIGHT,
	PORTAL_ACTIVATE_LIGHT,
	CONFUSION_GAS_LIGHT,
	SUNLIGHT_CLOUD_LIGHT,
	DARKNESS_CLOUD_LIGHT,
	FORCEFIELD_LIGHT,
	CRYSTAL_WALL_LIGHT,
	CANDLE_LIGHT,
    HAUNTED_TORCH_LIGHT,
    GLYPH_LIGHT_DIM,
    GLYPH_LIGHT_BRIGHT,
    DESCENT_LIGHT,
	NUMBER_LIGHT_KINDS
};

// Item categories
enum itemCategory {
	FOOD				= Fl(0),
	WEAPON				= Fl(1),
	ARMOR				= Fl(2),
	SHIELD				= Fl(3),
	POTION				= Fl(4),
	ELIXIR				= Fl(5),
	SCROLL				= Fl(6),
	TOME				= Fl(7),
	STAFF				= Fl(8),
	WAND				= Fl(9),
	RING				= Fl(10),
	CHARM				= Fl(11),
	TALISMAN			= Fl(12),
	GOLD				= Fl(13),
	AMULET				= Fl(14),
	GEM					= Fl(15),
	KEY					= Fl(16),
	SUMMONING_STAFF		= Fl(17),	// Fake category to display all summoning staffs as one item.
	COATING_DARTS		= Fl(18),	// Fake category to only allow darts to be coated with a potion.
	ENCHANT_TALISMAN	= Fl(19),	// Fake category to only allow certain talismans to be enchanted.
	DUPLICATE_SCROLL	= Fl(20),	// Fake category to prevent scrolls of duplication from duplicating themselves.
	DUPLICATE_TOME		= Fl(21),	// Fake category to prevent tomes of triplication from duplicating themselves.
	APPLY_TALISMAN		= Fl(22),	// Fake category to allow talismans of shape change, alchemy to be activated.
	ENCHANT_POTION		= Fl(23),	// Fake category to only allow potions of life to be enchanted when you have a lumenstone.
	COMBINE_2_POTION_OR_SCROLL = Fl(24),	// Fake category to piles of two potions or scrolls to be combined if you have talisman of alchemy.
	CHARMING_CHARM		= Fl(25),	// Fake category for enchanting charms with less enchantments than a charm of charming

	CAN_BE_DETECTED		= (WEAPON|ARMOR|SHIELD|POTION|ELIXIR|SCROLL|TOME|RING|CHARM|TALISMAN|WAND|STAFF|AMULET),
	PRENAMED_CATEGORY	= (FOOD | GOLD | AMULET | GEM | KEY),
	ALL_ITEMS			= (FOOD|POTION|ELIXIR|WEAPON|ARMOR|SHIELD|STAFF|WAND|SCROLL|TOME|RING|CHARM|TALISMAN|GOLD|AMULET|GEM|KEY),
};

#define NUMBER_ITEM_CATEGORIES	17

enum keyKind {
	KEY_DOOR,
	KEY_VAULT,
	KEY_CAGE,
	KEY_PORTAL,
	KEY_RUNE_ARMOR,
	KEY_RUNE_WEAPON,
	KEY_RUNE_WAND,
	KEY_RUNE_STAFF,
	NUMBER_KEY_TYPES
};

enum foodKind {
	RATION,
	FRUIT,
	NUMBER_FOOD_KINDS
};

enum potionKind {
	POTION_LIFE,
	POTION_STRENGTH,
	POTION_TELEPATHY,
	POTION_LEVITATION,
	POTION_DETECT_MAGIC,
	POTION_HASTE_SELF,
	POTION_FIRE_IMMUNITY,
	POTION_INVISIBILITY,
	POTION_WINDS,
	POTION_POISON,
	POTION_PARALYSIS,
	POTION_HALLUCINATION,
	POTION_CONFUSION,
	POTION_INCINERATION,
	POTION_DARKNESS,
	POTION_DESCENT,
	POTION_LICHEN,
	POTION_WATER,
	POTION_STENCH,
	POTION_EXPLOSION,
	NUMBER_POTION_KINDS
};

#define NUMBER_POTION_KINDS_SHOWN (NUMBER_POTION_KINDS - 2)

enum elixirKind {
	ELIXIR_LIFE,
	ELIXIR_STRENGTH,
	ELIXIR_TELEPATHY,
	ELIXIR_LEVITATION,
	ELIXIR_DETECT_MAGIC,
	ELIXIR_HASTE_SELF,
	ELIXIR_FIRE_IMMUNITY,
	ELIXIR_INVISIBILITY,
	ELIXIR_WINDS,
	ELIXIR_POISON,
	ELIXIR_PARALYSIS,
	ELIXIR_HALLUCINATION,
	ELIXIR_CONFUSION,
	ELIXIR_INCINERATION,
	ELIXIR_DARKNESS,
	ELIXIR_DESCENT,
	ELIXIR_LICHEN,
	ELIXIR_WATER,
	ELIXIR_STENCH,
	ELIXIR_EXPLOSION,
	NUMBER_ELIXIR_KINDS
};

enum weaponKind {
	DAGGER,
	SWORD,
	BROADSWORD,

	RAPIER,
	SABRE,

	MACE,
	HAMMER,

	SPEAR,
	PIKE,

	AXE,
	WAR_AXE,

	DART,
	INCENDIARY_DART,
	POISON_DART,
	DISCORD_DART,
	CONFUSING_DART,
	DARKNESS_DART,
	MARKING_DART,
	WEAKNESS_DART,
	SLOWING_DART,
	GRAPPLING_DART,
	EXTINGUISHING_DART,
	JAVELIN,
	NUMBER_WEAPON_KINDS
};

enum weaponEnchants {
	W_SPEED,
	W_QUIETUS,
	W_PARALYSIS,
	W_MULTIPLICITY,
	W_SLOWING,
	W_CONFUSION,
	W_FORCE,
	W_SLAYING,
	W_MERCY,
	NUMBER_GOOD_WEAPON_ENCHANT_KINDS = W_MERCY,
	W_PLENTY,
	NUMBER_WEAPON_RUNIC_KINDS
};

enum armorKind {
	LEATHER_ARMOR,
	SCALE_MAIL,
	CHAIN_MAIL,
	BANDED_MAIL,
	SPLINT_MAIL,
	PLATE_MAIL,
	NUMBER_ARMOR_KINDS
};

enum armorEnchants {
	A_MULTIPLICITY,
	A_MUTUALITY,
	A_ABSORPTION,
	A_REPRISAL,
	A_IMMUNITY,
	A_REFLECTION,
	A_DAMPENING,
	A_REPULUSION,
	A_BURDEN,
	NUMBER_GOOD_ARMOR_ENCHANT_KINDS = A_BURDEN,
	A_VULNERABILITY,
    A_IMMOLATION,
	NUMBER_ARMOR_ENCHANT_KINDS,
};

enum shieldKind {
	ROUND_SHIELD,
	KNIGHT_SHIELD,
	TOWER_SHIELD,
	NUMBER_SHIELD_KINDS,
};

enum wandKind {
	WAND_FORCE,
	WAND_LIGHTNING,
	WAND_FIRE,
	WAND_POISON,
	WAND_TUNNELING,
	WAND_DETONATION,
	WAND_BLINKING,
	WAND_CONJURATION,
	WAND_TELEPORT,
	WAND_SLOW,
	WAND_NEGATION,
	WAND_DOMINATION,
	WAND_ENTRANCEMENT,
	WAND_OBSTRUCTION,
	WAND_DISCORD,
	WAND_NATURE,
	WAND_PLENTY,
	WAND_POLYMORPH,
	WAND_BECKONING,
	WAND_INVISIBILITY,
	WAND_HEALING,
	WAND_HASTE,
	WAND_PROTECTION,
	WAND_REFLECTION,
	WAND_SENTRY,
	//	WAND_PHANTOM,
	WAND_ZOMBIE,
	WAND_BLOAT,
	WAND_SPIDER,
	WAND_NAGA,
	WAND_PIXIE,
	WAND_TOAD,
	WAND_UNDERWORM,
	WAND_MANDRAKE,
	WAND_DEAD_MANS_EAR,
	WAND_CRIMSON_CAP,
	WAND_MIRRORED_TOTEM,
	NUMBER_WAND_KINDS
};

#define NUMBER_WAND_KINDS_SHOWN (WAND_SENTRY + 1)

enum staffKind {
	STAFF_FORCE,
	STAFF_LIGHTNING,
	STAFF_FIRE,
	STAFF_POISON,
	STAFF_TUNNELING,
	STAFF_DETONATION,
	STAFF_BLINKING,
	STAFF_CONJURATION,
	STAFF_TELEPORT,
	STAFF_SLOW,
	STAFF_NEGATION,
	STAFF_DOMINATION,
	STAFF_ENTRANCEMENT,
	STAFF_OBSTRUCTION,
	STAFF_DISCORD,
	STAFF_NATURE,
	STAFF_PLENTY,
	STAFF_POLYMORPH,
	STAFF_BECKONING,
	STAFF_INVISIBILITY,
	STAFF_HEALING,
	STAFF_HASTE,
	STAFF_PROTECTION,
	STAFF_REFLECTION,
	STAFF_SENTRY,
//	STAFF_PHANTOM,
	STAFF_ZOMBIE,
	STAFF_BLOAT,
	STAFF_SPIDER,
	STAFF_NAGA,
	STAFF_PIXIE,
	STAFF_TOAD,
	STAFF_UNDERWORM,
	STAFF_MANDRAKE,
	STAFF_DEAD_MANS_EAR,
	STAFF_CRIMSON_CAP,
	STAFF_MIRRORED_TOTEM,
	NUMBER_STAFF_KINDS
};

#define NUMBER_STAFF_KINDS_SHOWN (STAFF_SENTRY + 1)

// these must match wand and staff ordering:
enum boltType {
	BOLT_FORCE,
	BOLT_LIGHTNING,
	BOLT_FIRE,
	BOLT_POISON,
	BOLT_TUNNELING,
	BOLT_DETONATION,
	BOLT_BLINKING,
	BOLT_CONJURATION,
	BOLT_TELEPORT,
	BOLT_SLOW,
	BOLT_NEGATION,
	BOLT_DOMINATION,
	BOLT_ENTRANCEMENT,
	BOLT_OBSTRUCTION,
	BOLT_DISCORD,
	BOLT_NATURE,
	BOLT_PLENTY,
	BOLT_POLYMORPH,
	BOLT_BECKONING,
	BOLT_INVISIBILITY,
	BOLT_HEALING,
	BOLT_HASTE,
	BOLT_SHIELDING,
	BOLT_REFLECTION,
	BOLT_SENTRY,
//	BOLT_PHANTOM,
	BOLT_ZOMBIE,
	BOLT_BLOAT,
	BOLT_SPIDER,
	BOLT_NAGA,
	BOLT_PIXIE,
	BOLT_TOAD,
	BOLT_UNDERWORM,
	BOLT_MANDRAKE,
	BOLT_DEAD_MANS_EAR,
	BOLT_CRIMSON_CAP,
	BOLT_MIRRORED_TOTEM,
	NUMBER_BOLT_KINDS
};

enum boltEnchants {
	B_QUICK,
	B_SLOW,
	B_RECEPTIVE,
	B_SELECTIVE,
	B_PRECISION,
	B_DISTANCE,
	B_X_RAY,
	NUMBER_GOOD_BOLT_ENCHANT_KINDS = B_X_RAY, // runics from here onwards are restricted from appearing on some wands/staffs
	B_II,
	B_CHAINING,
	B_BOUNCES,
	B_PENETRATING,
	B_EXPLODES,
	NUMBER_BOLT_ENCHANT_KINDS,
};

enum ringKind {
	RING_CLAIRVOYANCE,
	RING_STEALTH,
	RING_REGENERATION,
	RING_TRANSFERENCE,
	RING_LIGHT,
	RING_AWARENESS,
	RING_WISDOM,
	RING_MIGHT,
	RING_TELEPATHY,
	NUMBER_RING_KINDS
};

#define NUMBER_RING_KINDS_SHOWN (NUMBER_RING_KINDS)

enum charmKind {
	CHARM_HEALTH,
	CHARM_STRENGTH,
    CHARM_TELEPATHY,
    CHARM_LEVITATION,
	CHARM_DETECT_MAGIC,
    CHARM_HASTE,
    CHARM_FIRE_IMMUNITY,
    CHARM_INVISIBILITY,
	CHARM_WINDS,
	CHARM_POISONOUS_GAS,
	CHARM_PARALYSIS,
	CHARM_DISCORD,
	CHARM_CONFUSION,
	CHARM_INCINERATION,
	CHARM_DARKNESS,
	CHARM_DESCENT,
	CHARM_CREEPING_DEATH,
	CHARM_WATER,
	CHARM_STENCH,
	CHARM_EXPLOSIVE_GAS,
	CHARM_CHARMING,
	CHARM_IDENTIFY,
    CHARM_TELEPORTATION,
    CHARM_RECHARGING,
    CHARM_PROTECTION,
	CHARM_PROTECTION_2,
	CHARM_MAGIC_MAPPING,
    CHARM_CAUSE_FEAR,
    CHARM_NEGATION,
    CHARM_SHATTERING,
	CHARM_DUPLICATION,
	CHARM_AGGRAVATE_MONSTERS,
	CHARM_SUMMON_MONSTERS,
    NUMBER_CHARM_KINDS
};

enum scrollKind {
	SCROLL_ENCHANTING,
	SCROLL_IDENTIFY,
	SCROLL_TELEPORT,
	SCROLL_RECHARGING,
	SCROLL_PROTECT_ARMOR,
	SCROLL_PROTECT_WEAPON,
	SCROLL_MAGIC_MAPPING,
	SCROLL_CAUSE_FEAR,
	SCROLL_NEGATION,
	SCROLL_SHATTERING,
	SCROLL_DUPLICATION,
	SCROLL_AGGRAVATE_MONSTER,
	SCROLL_SUMMON_MONSTER,
	NUMBER_SCROLL_KINDS
};

#define NUMBER_SCROLL_KINDS_SHOWN (NUMBER_SCROLL_KINDS)

enum tomeKind {
	TOME_ENCHANTING,
	TOME_IDENTIFY,
	TOME_TELEPORT,
	TOME_RECHARGING,
	TOME_PROTECT_ARMOR,
	TOME_PROTECT_WEAPON,
	TOME_MAGIC_MAPPING,
	TOME_CAUSE_FEAR,
	TOME_NEGATION,
	TOME_SHATTERING,
	TOME_DUPLICATION,
	TOME_AGGRAVATE_MONSTER,
	TOME_SUMMON_MONSTER,
	NUMBER_TOME_KINDS
};

enum talismanKind {
	TALISMAN_MADNESS,
	TALISMAN_SPIDER,
	TALISMAN_FLAMESPIRIT,
//	TALISMAN_TRAP_MASTERY,
//	TALISMAN_CHAOS,
//  TALISMAN_JACKALS,
	TALISMAN_SACRIFICE,
	TALISMAN_WIZARDRY,
	TALISMAN_BALANCE,
	TALISMAN_DUNGEONEERING,
	TALISMAN_RUNE_MASTERY,
	TALISMAN_SHAPE_CHANGING,
	TALISMAN_ALCHEMY,
	TALISMAN_WITCHCRAFT,
	TALISMAN_SINISTER,
	TALISMAN_THIRD_EYE,
	TALISMAN_ASSASSIN,
	NUMBER_TALISMAN_KINDS,
	TALISMAN_MAX_ENCHANT = /*TALISMAN_TRAP_MASTERY,*/ TALISMAN_FLAMESPIRIT,
	TALISMAN_MIN_AUTOIDENTIFY = TALISMAN_BALANCE,
};

#define NUMBER_TALISMAN_KINDS_SHOWN (TALISMAN_MIN_AUTOIDENTIFY)

#define MAX_PACK_ITEMS				26

enum monsterTypes {
	MK_YOU,
	MK_RAT,
	MK_KOBOLD,
	MK_JACKAL,
	MK_EEL,
	MK_MONKEY,
	MK_BLOAT,
	MK_PIT_BLOAT,
	MK_GOBLIN,
	MK_GOBLIN_CONJURER,
	MK_GOBLIN_MYSTIC,
	MK_GOBLIN_TOTEM,
	MK_PINK_JELLY,
	MK_TOAD,
	MK_VAMPIRE_BAT,
	MK_ARROW_TURRET,
	MK_ACID_MOUND,
	MK_CENTIPEDE,
	MK_OGRE,
	MK_BOG_MONSTER,
	MK_OGRE_TOTEM,
	MK_SPIDER,
	MK_SPARK_TURRET,
	MK_WILL_O_THE_WISP,
	MK_HARPY,
	MK_WRAITH,
	MK_LAMIA,
	MK_ZOMBIE,
	MK_TROLL,
	MK_OGRE_SHAMAN,
	MK_NAGA,
	MK_SALAMANDER,
	MK_EXPLOSIVE_BLOAT,
	MK_DAR_BLADEMASTER,
	MK_DAR_PRIESTESS,
	MK_DAR_BATTLEMAGE,
	MK_ACID_JELLY,
	MK_CENTAUR,
	MK_UNDERWORM,
	MK_SENTINEL,
	MK_ACID_TURRET,
	MK_DART_TURRET,
	MK_KRAKEN,
	MK_LICH,
	MK_PHYLACTERY,
	MK_PIXIE,
	MK_PHANTOM,
	MK_FLAME_TURRET,
	MK_IMP,
	MK_FURY,
	MK_REVENANT,
	MK_TENTACLE_HORROR,
	MK_GOLEM,
	MK_DRAGON,
	MK_SHY_DRAGON,
	MK_REVENANT_TOTEM,
	MK_DAR_TOTEM,
	MK_DRAGON_TOTEM,

	MK_GOBLIN_CHIEFTAN,
	MK_BLACK_JELLY,
	MK_VAMPIRE,
	MK_FLAMESPIRIT,
	MK_MINOTAUR,

	MK_IRON_GOLEM,

	MK_SPECTRAL_BLADE,
	MK_SPECTRAL_IMAGE,
    MK_GUARDIAN,
    MK_WINGED_GUARDIAN,
    MK_ELDRITCH_TOTEM,
    MK_MIRRORED_TOTEM,
	MK_MANDRAKE,
	MK_DEAD_MANS_EAR,
	MK_CRIMSON_CAP,

	MK_UNICORN,
	MK_IFRIT,
	MK_PHOENIX,
	MK_PHOENIX_EGG,

	MK_JELLY,
	MK_DAR,

	NUMBER_MONSTER_KINDS
};

#define	NUMBER_HORDES				202

// flavors

#define NUMBER_ITEM_COLORS			28
#define NUMBER_ITEM_CHEMISTRY		28
#define NUMBER_TITLE_PHONEMES		17
#define NUMBER_COVER_PHRASES		17
#define NUMBER_ITEM_WOODS			44
#define NUMBER_ITEM_METALS			36
#define NUMBER_ITEM_GEMS			38
#define NUMBER_ITEM_MATERIALS		23

// Dungeon flags
enum tileFlags {
	DISCOVERED					= Fl(0),
	VISIBLE						= Fl(1),	// cell has sufficient light and is in field of view, ready to draw.
	HAS_PLAYER					= Fl(2),
	HAS_MONSTER					= Fl(3),
	HAS_DORMANT_MONSTER			= Fl(4),	// hidden monster on the square
	HAS_ITEM					= Fl(5),
	IN_FIELD_OF_VIEW			= Fl(6),	// player has unobstructed line of sight whether or not there is enough light
	WAS_VISIBLE					= Fl(7),
	HAS_STAIRS					= Fl(8),
	MARKED_VISIBLE				= Fl(9),	// darts of marking and assassination targets let you see through other creatures' eyes
	IS_IN_SHADOW				= Fl(10),	// so that a player gains an automatic stealth bonus
	MAGIC_MAPPED				= Fl(11),
	ITEM_DETECTED				= Fl(12),
	CLAIRVOYANT_VISIBLE			= Fl(13),
	WAS_CLAIRVOYANT_VISIBLE		= Fl(14),
	CLAIRVOYANT_DARKENED		= Fl(15),	// magical blindness from a cursed ring of clairvoyance
	CAUGHT_FIRE_THIS_TURN		= Fl(16),	// so that fire does not spread asymmetrically
	PRESSURE_PLATE_DEPRESSED	= Fl(17),	// so that traps do not trigger repeatedly while you stand on them
	DOORWAY						= Fl(18),	// so that waypoint paths don't cross open doorways
	STABLE_MEMORY				= Fl(19),	// redraws will simply be pulled from the memory array, not recalculated
	KNOWN_TO_BE_TRAP_FREE		= Fl(20),	// keep track of where the player has stepped as he knows no traps are there
	IS_IN_PATH					= Fl(21),	// the yellow trail leading to the cursor
	IN_LOOP						= Fl(22),	// this cell is part of a terrain loop
	IS_CHOKEPOINT				= Fl(23),	// if this cell is blocked, part of the map will be rendered inaccessible
	IS_GATE_SITE				= Fl(24),	// consider placing a locked door here
	IS_IN_ROOM_MACHINE			= Fl(25),
	IS_IN_AREA_MACHINE			= Fl(26),
	IS_POWERED					= Fl(27),	// has been activated by machine power this turn (can probably be eliminated if needed)
	IMPREGNABLE					= Fl(28),	// no tunneling allowed!
	TERRAIN_COLORS_DANCING		= Fl(29),	// colors here will sparkle when the game is idle
	TELEPATHIC_VISIBLE			= Fl(30),	// potions of telepathy let you see through other creatures' eyes
	WAS_TELEPATHIC_VISIBLE		= Fl(31),	// potions of telepathy, darts of marking and assassination targets let you see through other creatures' eyes

	IS_IN_MACHINE				= (IS_IN_ROOM_MACHINE | IS_IN_AREA_MACHINE), 	// sacred ground; don't spawn monsters here, or generate items, or teleport randomly to it

	PERMANENT_TILE_FLAGS = (DISCOVERED | MAGIC_MAPPED | ITEM_DETECTED | HAS_ITEM | HAS_DORMANT_MONSTER
							| HAS_STAIRS | DOORWAY | PRESSURE_PLATE_DEPRESSED
							| STABLE_MEMORY | KNOWN_TO_BE_TRAP_FREE | IN_LOOP
							| IS_CHOKEPOINT | IS_GATE_SITE | IS_IN_MACHINE | IMPREGNABLE),

	ANY_KIND_OF_VISIBLE			= (VISIBLE | CLAIRVOYANT_VISIBLE | TELEPATHIC_VISIBLE | MARKED_VISIBLE),
};

#define TURNS_FOR_FULL_REGEN				300
#define STOMACH_SIZE						2150
#define HUNGER_THRESHOLD					(STOMACH_SIZE - 1800)
#define WEAK_THRESHOLD						150
#define FAINT_THRESHOLD						50
#define MAX_EXP_LEVEL						20
#define MAX_EXP								100000000L

#define XPXP_NEEDED_FOR_ABSORB				4000 // XPXP required for your allies to be eligible to absorb an enemy ability/behavior
#define XPXP_NEEDED_FOR_LEVELUP				1300 // XPXP required per increase in your allies' stats

#define ROOM_MIN_WIDTH						4
#define ROOM_MAX_WIDTH						20
#define ROOM_MIN_HEIGHT						3
#define ROOM_MAX_HEIGHT						7
#define HORIZONTAL_CORRIDOR_MIN_LENGTH		5
#define HORIZONTAL_CORRIDOR_MAX_LENGTH		15
#define VERTICAL_CORRIDOR_MIN_LENGTH		2
#define VERTICAL_CORRIDOR_MAX_LENGTH		10
#define CROSS_ROOM_MIN_WIDTH				3
#define CROSS_ROOM_MAX_WIDTH				12
#define CROSS_ROOM_MIN_HEIGHT				2
#define CROSS_ROOM_MAX_HEIGHT				5
#define MIN_SCALED_ROOM_DIMENSION			2

#define CORRIDOR_WIDTH						1

#define MAX_WAYPOINTS						200
#define WAYPOINT_SIGHT_RADIUS				10

#define MAX_ITEMS_IN_MONSTER_ITEMS_HOPPER   100

typedef struct levelSpecProfile {
	short roomMinWidth;
	short roomMaxWidth;
	short roomMinHeight;
	short roomMaxHeight;
	short horCorrMinLength;
	short horCorrMaxLength;
	short vertCorrMinLength;
	short vertCorrMaxLength;
	short crossRoomMinWidth;
	short crossRoomMaxWidth;
	short crossRoomMinHeight;
	short crossRoomMaxHeight;
	short secretDoorChance;
	short numberOfTraps;
} levelSpecProfile;

// Making these larger means cave generation will take more trials; set them too high and the program will hang.
#define CAVE_MIN_WIDTH						50
#define CAVE_MIN_HEIGHT						20

// Keyboard commands:
#define UP_KEY				'k'
#define DOWN_KEY			'j'
#define LEFT_KEY			'h'
#define RIGHT_KEY			'l'
#define UP_ARROW			63232
#define LEFT_ARROW			63234
#define DOWN_ARROW			63233
#define RIGHT_ARROW			63235
#define UPLEFT_KEY			'y'
#define UPRIGHT_KEY			'u'
#define DOWNLEFT_KEY		'b'
#define DOWNRIGHT_KEY		'n'
#define DESCEND_KEY			'>'
#define ASCEND_KEY			'<'
#define REST_KEY			'z'
#define AUTO_REST_KEY		'Z'
#define SEARCH_KEY			's'
#define INVENTORY_KEY		'i'
#define ACKNOWLEDGE_KEY		' '
#define EQUIP_KEY			'e'
#define UNEQUIP_KEY			'r'
#define APPLY_KEY			'a'
#define THROW_KEY			't'
#define TRUE_COLORS_KEY		'\\'
#define DROP_KEY			'd'
#define CALL_KEY			'c'
//#define FIGHT_KEY			'f'
//#define FIGHT_TO_DEATH_KEY	'F'
#define QUIT_KEY			'Q'
#define MESSAGE_ARCHIVE_KEY	'M'
#define HELP_KEY			'?'
#define DISCOVERIES_KEY		'D'
#define EXPLORE_KEY			'x'
#define AUTOPLAY_KEY		'A'
#define SEED_KEY			'~'
#define EASY_MODE_KEY		'&'
#define ESCAPE_KEY			'\033'
#define RETURN_KEY			'\015'
#define ENTER_KEY			'\012'
#define DELETE_KEY			'\177'
#define TAB_KEY				'\t'
#define PERIOD_KEY			'.'
#define VIEW_RECORDING_KEY	'V'
#define LOAD_SAVED_GAME_KEY	'O'
#define SAVE_GAME_KEY		'S'
#define NEW_GAME_KEY		'N'
#define NUMPAD_0			48
#define NUMPAD_1			49
#define NUMPAD_2			50
#define NUMPAD_3			51
#define NUMPAD_4			52
#define NUMPAD_5			53
#define NUMPAD_6			54
#define NUMPAD_7			55
#define NUMPAD_8			56
#define NUMPAD_9			57
#define PAGE_UP_KEY			63276
#define PAGE_DOWN_KEY		63277

#define UNKNOWN_KEY			(128+19)

#define min(x, y)		(((x) < (y)) ? (x) : (y))
#define max(x, y)		(((x) > (y)) ? (x) : (y))
#define clamp(x, low, hi)	(min(hi, max(x, low))) // pins x to the [y, z] interval

#define terrainFlags(x, y)					(tileCatalog[pmap[x][y].layers[DUNGEON]].flags \
											| tileCatalog[pmap[x][y].layers[LIQUID]].flags \
											| tileCatalog[pmap[x][y].layers[SURFACE]].flags \
											| tileCatalog[pmap[x][y].layers[GAS]].flags)

#define terrainFlags2(x, y)					(tileCatalog[pmap[x][y].layers[DUNGEON]].flags2 \
											| tileCatalog[pmap[x][y].layers[LIQUID]].flags2 \
											| tileCatalog[pmap[x][y].layers[SURFACE]].flags2 \
											| tileCatalog[pmap[x][y].layers[GAS]].flags2)

#define terrainFlags3(x, y)					(tileCatalog[pmap[x][y].layers[DUNGEON]].flags3 \
											| tileCatalog[pmap[x][y].layers[LIQUID]].flags3 \
											| tileCatalog[pmap[x][y].layers[SURFACE]].flags3 \
											| tileCatalog[pmap[x][y].layers[GAS]].flags3)

#ifdef BROGUE_ASSERTS
boolean cellHasTerrainFlag(short x, short y, unsigned long flagMask);
#else
#define cellHasTerrainFlag(x, y, flagMask)	((flagMask) & terrainFlags((x), (y)) ? true : false)
#endif

#ifdef BROGUE_ASSERTS
boolean cellHasTerrainFlag2(short x, short y, unsigned long flagMask);
#else
#define cellHasTerrainFlag2(x, y, flagMask)	((flagMask) & terrainFlags2((x), (y)) ? true : false)
#endif

#ifdef BROGUE_ASSERTS
boolean cellHasTerrainFlag3(short x, short y, unsigned long flagMask);
#else
#define cellHasTerrainFlag3(x, y, flagMask)	((flagMask) & terrainFlags3((x), (y)) ? true : false)
#endif

#define cellHasTerrainType(x, y, terrain)	((pmap[x][y].layers[DUNGEON] == (terrain) \
											|| pmap[x][y].layers[LIQUID] == (terrain) \
											|| pmap[x][y].layers[SURFACE] == (terrain) \
											|| pmap[x][y].layers[GAS] == (terrain)) ? true : false)

#define cellIsPassableOrDoor(x, y)			(!cellHasTerrainFlag((x), (y), T_PATHING_BLOCKER) \
											|| (cellHasTerrainFlag((x), (y), (T_IS_SECRET | T_PROMOTES_WITH_KEY)) \
												&& cellHasTerrainFlag((x), (y), T_OBSTRUCTS_PASSABILITY))) // May not be perfect with hidden levers.

#define coordinatesAreInMap(x, y)			((x) >= 0 && (x) < DCOLS	&& (y) >= 0 && (y) < DROWS)
#define coordinatesAreInWindow(x, y)		((x) >= 0 && (x) < COLS		&& (y) >= 0 && (y) < ROWS)
#define mapToWindowX(x)						((x) + STAT_BAR_WIDTH + 1)
#define mapToWindowY(y)						((y) + MESSAGE_LINES)
#define windowToMapX(x)						((x) - STAT_BAR_WIDTH - 1)
#define windowToMapY(y)						((y) - MESSAGE_LINES)

#define playerCanDirectlySee(x, y)			(pmap[x][y].flags & VISIBLE)
#define playerCanSee(x, y)					(pmap[x][y].flags & ANY_KIND_OF_VISIBLE)
#define playerCanSeeOrSense(x, y)			((pmap[x][y].flags & ANY_KIND_OF_VISIBLE) \
											|| (rogue.playbackOmniscience && (pmap[x][y].layers[DUNGEON] != GRANITE)))

#define CYCLE_MONSTERS_AND_PLAYERS(x)		for ((x) = &player; (x) != NULL; (x) = ((x) == &player ? monsters->nextCreature : (x)->nextCreature))

#define assureCosmeticRNG					short oldRNG = rogue.RNG; rogue.RNG = RNG_COSMETIC;
#define restoreRNG							rogue.RNG = oldRNG;

#define MIN_COLOR_DIFF			500
// weighted sum of the squares of the component differences. Weights are according to color perception.
#define COLOR_DIFF(f, b)		 (((f).red - (b).red) * ((f).red - (b).red) * 0.2126 \
+ ((f).green - (b).green) * ((f).green - (b).green) * 0.7152 \
+ ((f).blue - (b).blue) * ((f).blue - (b).blue) * 0.0722)

// game data formulae:

#define boltDamageLow(enchant)				((int) (3 * (2 + (enchant)) / 4))
#define boltDamageHigh(enchant)				((int) (4 + 5 * (enchant) / 2))
#define boltDamage(enchant)					(randClumpedRange(boltDamageLow(enchant), boltDamageHigh(enchant), 1 + (enchant) / 3))
#define boltPoison(enchant)					((int) (5 * pow(1.53, (double) (enchant) - 2)))
#define shatteringChance(enchant)			(clamp((100 - (short) (100 * pow(0.95, (enchant)))), 1, 100))
#define detonationLifeSpanMinimum(enchant)	((int) (95 * pow(1.5, (double) -(enchant)) + 1))
#define detonationLifeSpanMaximum(enchant)	((int) (950 * pow(1.5, (double) -(enchant)) + 2))
#define staffTeleportDistance(enchant)		((int) ((enchant) * 2 + 2)) // hard coded in zap()
#define boltBlinkDistance(enchant)			((int) ((enchant) * 2 + 2)) // hard coded in zap()
#define staffBeckoningDistance(enchant)		((int) ((enchant) * 2 + 2)) // hard coded in zap(), subtle dependencies on B_DISTANCE power multiplier
#define staffNegationDuration(enchant)		((int) (pow(1.5, (double) (enchant)) * 2))
#define staffPlentyDuration(enchant)		((int) ((enchant) * 2))
#define staffDominationDuration(enchant)	((int) ((enchant) * 6))
#define staffPolymorphDuration(enchant)		((int) ((enchant) * 3))
#define boltInvisibilityDuration(enchant)	((int) (2.6 * pow(1.5, (enchant)) + 1))
#define boltHasteDuration(enchant)			((int) (2 + (enchant) * 4))
#define boltSlowDuration(enchant)			((int) max(2, (enchant)))
#define boltBladeCount(enchant)				((int) ((enchant) * 3 / 2))
#define boltDiscordDuration(enchant)		((int) ((enchant) * 4))
#define boltProtection(enchant)				((int) (100 * pow(1.35, (double) (enchant))))
#define boltEntrancementDuration(enchant)	((int) (enchant) * 3)
#define boltReflectionDuration(enchant)		((int) (enchant) * 2 + 2)
#define staffNatureMinimumGap(enchant)		((int) (56 / pow(1.2, (double) (enchant))))
#define boltSentryDuration(enchant)			((int) ((enchant) * 4))
#define boltSentryProtection(enchant)		((int) (50 * pow(1.53, (double) (enchant) - 2)))
#define boltZombieDuration(enchant)			((int) ((enchant) * 4))
#define staffZombieAflame(enchant)			(clamp((100 - (short) (100 * pow(0.9, (enchant)))), 1, 100))
//#define boltPhantomDuration(enchant)		((int) ((enchant) * 4))
//#define boltPhantomDarkness(enchant)		(clamp((100 - (short) (100 * pow(0.65, (enchant)))), 1, 100))
#define wandBloatDuration(enchant)			((int) ((enchant) * 2))
#define boltPixieDuration(enchant)			((int) ((enchant) * 4))
#define boltNagaDuration(enchant)			((int) ((enchant) * 6))
#define boltToadDuration(enchant)			((int) ((enchant) * 6))
#define boltSpiderDuration(enchant)			((int) ((enchant) * 4))
#define boltUnderwormDuration(enchant)		((int) ((enchant) * 8))
#define boltMandrakeDuration(enchant)		((int) ((enchant) * 6))
#define boltDeadMansEarDuration(enchant)	((int) ((enchant) * 10))
#define boltCrimsonCapDuration(enchant)		((int) ((enchant) * 30))
#define boltMirroredTotemDuration(enchant)	((int) ((enchant) * 20))

#define charmHealing(enchant)               ((int) clamp(20 * (enchant), 0, 100))
#define charmProtection(enchant)			((int) (150 * pow(1.35, (double) (enchant) - 1)))
#define charmShattering(enchant)            ((int) (4 + (enchant)))

#define boltDominate(monst)					(((monst)->currentHP * 5 < (monst)->info.maxHP) ? 100 : \
											100 * ((monst)->info.maxHP - (monst)->currentHP) / (monst)->info.maxHP)

#define weaponParalysisDuration(enchant)	(max(2, (int) (2 + (enchant / 2))))
#define weaponConfusionDuration(enchant)	(max(3, (int) (1.5 * (enchant))))
#define weaponForceDistance(enchant)		(max(4, (((int) (enchant)) * 2 + 2))) // Depends on definition of boltBlinkDistance() above.
#define weaponSlowDuration(enchant)			(max(3, (int) (((enchant) + 2) * ((enchant) + 2) / 3)))
#define weaponImageCount(enchant)			(clamp((int) (enchant) / 3, 1, 3))		//(max((int) (((enchant) + 1) / 2), 1))
#define weaponImageDuration(enchant)		3										//(max((int) (1 + (enchant) / 3), 2))

#define armorReprisalPercent(enchant)		(max(5, (int) (enchant * 5)))
#define armorAbsorptionMax(enchant)			(max(1, (int) (enchant)))
#define armorImmolationChance(enchant)		(clamp((int) abs(enchant) * 10, 1, 95))
#define armorImageCount(enchant)			((int) (clamp((int) (enchant) / 3, 1, 3)))		//(max((int) (((enchant) + 1) / 2), 1))
#define reflectionChance(enchant)			(clamp((100 - (short) (100 * pow(0.85, (enchant)))), 1, 100))
#define madnessBoost(enchant)				(pow(1.4, min(19, abs(enchant))))
#define madnessDuration(enchant)			((int) ((enchant) * 4))
#define poisonBoost(enchant)				(pow(1.5, min(16, abs(enchant))))
#define fireDancingBoost(enchant)			(pow(1.4, min(19, abs(enchant))))

#define turnsForFullRegen(bonus)			((long) (1000 * TURNS_FOR_FULL_REGEN * pow(0.75, (bonus)) + 2000))
											// This will max out at full regeneration in about two turns.
											// This is the Syd nerf, after Syd broke the game over his knee with a +18 ring of regeneration.

// structs

enum dungeonLayers {
	DUNGEON = 0,		// dungeon-level tile	(e.g. walls)
	LIQUID,				// liquid-level tile	(e.g. lava)
	GAS,				// gas-level tile		(e.g. fire, smoke, swamp gas)
	SURFACE,			// surface-level tile	(e.g. grass)
	NUMBER_TERRAIN_LAYERS
};

// keeps track of graphics so we only redraw if the cell has changed:
typedef struct cellDisplayBuffer {
	uchar character;
	char foreColorComponents[3];
	char backColorComponents[3];
	char opacity;
	boolean needsUpdate;
} cellDisplayBuffer;

typedef struct pcell {								// permanent cell; have to remember this stuff to save levels
	enum tileType layers[NUMBER_TERRAIN_LAYERS];	// terrain
	unsigned long flags;							// non-terrain cell flags
	unsigned short volume;							// quantity of volumetric medium in cell
	unsigned char machineNumber;
	cellDisplayBuffer rememberedAppearance;			// how the player remembers the cell to look
	enum itemCategory rememberedItemCategory;		// what category of item the player remembers lying there
	enum tileType rememberedTerrain;				// what the player remembers as the terrain (i.e. highest priority terrain upon last seeing)
} pcell;

typedef struct tcell {			// transient cell; stuff we don't need to remember between levels
	short light[3];				// RGB components of lighting
	short oldLight[3];			// compare with subsequent lighting to determine whether to refresh cell
	signed char connected;		// used in dungeon generation to keep track of connected regions
} tcell;

typedef struct randomRange {
	short lowerBound;
	short upperBound;
	short clumpFactor;
} randomRange;

typedef struct color {

	// base RGB components:
	short red;
	short green;
	short blue;

	// random RGB components to add to base components:
	short redRand;
	short greenRand;
	short blueRand;

	// random scalar to add to all components:
	short rand;

	// Flag: this color "dances" with every refresh:
	boolean colorDances;

} color;

typedef struct door {
	short x;
	short y;
	enum directions direction;
} door;

typedef struct room {
	short roomX;
	short roomY;
	short width;
	short height;
	short roomX2;
	short roomY2;
	short width2;
	short height2;
	short numberOfSiblings;
	struct door doors[20];
	struct room *siblingRooms[20];
	struct room *nextRoom;
	short pathNumber; // used to calculate the distance (in rooms) between rooms
} room;

typedef struct waypoint {
	short x;
	short y;
	short pointsTo[2];
	short connectionCount;
	short connection[10][2];
} waypoint;


// attackFlags must match both itemFlags and monster abilityFlags
enum attackFlags {
	ATTACKS_PENETRATE	= Fl(30),	// spear, pike
	ATTACKS_ALL_ADJACENT=Fl(31),	// axe, war axe
};

enum itemFlags {
	ITEM_IDENTIFIED			= Fl(0),
	ITEM_EQUIPPED			= Fl(1),
	ITEM_CURSED				= Fl(2),
	ITEM_PROTECTED			= Fl(3),
	ITEM_NO_PICKUP			= Fl(4),
	ITEM_RUNIC				= Fl(5),
	ITEM_RUNIC_HINTED		= Fl(6),
	ITEM_RUNIC_IDENTIFIED	= Fl(7),
	ITEM_CAN_BE_IDENTIFIED	= Fl(8),
	ITEM_PREPLACED			= Fl(9),
	ITEM_FLAMMABLE			= Fl(10),
	ITEM_MAGIC_DETECTED		= Fl(11),
	ITEM_NAMED				= Fl(12),
	ITEM_MAX_CHARGES_KNOWN	= Fl(13),
	ITEM_IS_KEY				= Fl(14),
	ITEM_OVERCHARGED		= Fl(15),	// item has more charges than normally permitted
	ITEM_KIND_AUTO_ID		= Fl(16),	// the item type will become known when the item is picked up.
	ITEM_PLAYER_AVOIDS		= Fl(17),	// explore and travel will try to avoid picking the item up
	ITEM_DORMANT			= Fl(18),	// item hidden until charges reduced to zero
	ITEM_BROKEN				= Fl(19),	// shield is broken
	ITEM_BACKSTAB_X2		= Fl(20),	// gets x2 additional bonus for stealth attacks per +1 enchantment
	ITEM_BACKSTAB_X1		= Fl(21),	// gets x1 additional bonus for stealth attacks per +1 enchantment
	ITEM_BACKSTAB_XHALF		= Fl(22),	// gets x1/2 additional bonus for stealth attacks per +1 enchantment
	ITEM_BACKSTAB_XQUARTER	= Fl(23),	// gets x1/4 additional bonus for stealth attacks per +1 enchantment
	ITEM_KNOWN_NOT_CURSED	= Fl(24),	// in inventory when scroll of negation read
	ITEM_KEY_DETECTED		= Fl(25),	// key is tracked like a magic item
	ITEM_ATTACKS_SLOWLY		= Fl(26),	// mace, hammer
	ITEM_ATTACKS_QUICKLY	= Fl(27),	// rapier, sabre
	ITEM_HIT_KNOCKBACK		= Fl(28),	// mace, hammer
	ITEM_LUNGE_ATTACKS		= Fl(29),	// rapier, sabre
	ITEM_ATTACKS_PENETRATE	= Fl(30),	// spear, pike
	ITEM_IMPALES			= ITEM_ATTACKS_PENETRATE, // extends into the next grid when stepping, enemies entering grid are auto-hit for x3 damage
	ITEM_ATTACKS_ALL_ADJACENT=Fl(31),	// axe, war axe, sabre
};

#define itemRunic(theItem)			(((theItem)->flags & (ITEM_RUNIC)) || \
										(rogue.talisman && rogue.talisman->kind == TALISMAN_RUNE_MASTERY && \
										(theItem)->hiddenRunicEnchantsRequired <= 0))
#define itemRunicKnown(theItem)		((((theItem)->flags & (ITEM_RUNIC)) || \
										(rogue.talisman && rogue.talisman->kind == TALISMAN_RUNE_MASTERY)) && \
										((theItem)->flags & ITEM_RUNIC_IDENTIFIED))
#define itemRune(theItem)			((((theItem)->flags & (ITEM_RUNIC)) || ((theItem)->category & KEY)) ? \
										((theItem)->enchant2) : ((theItem)->hiddenRunic))

enum boltFlags {
	BOLT_HIDE_DETAILS		= Fl(0),	// hide details because e.g. the bolt is from an unidentified items
	BOLT_FROM_WAND			= Fl(1),	// bolt is from a wand
	BOLT_FROM_STAFF			= Fl(2),	// bolt is from a staff
	BOLT_EXPLODES			= Fl(3),	// bolt 'explodes' when it hits a target, like obstruction
	BOLT_BOUNCES			= Fl(4),	// bolt passes through monsters and bounces off walls, like lightning
	BOLT_PENETRATING		= Fl(5),	// bolt penetrates targets until damage is exhausted, like firebolt
	BOLT_DISTANCE			= Fl(6),	// bolt range is limited, like blinking
	BOLT_CHAINING			= Fl(7),	// bolt fires again from target to a nearby monster
	BOLT_SELECTIVE			= Fl(8),	// bolt starts at target grid, skipping intermediate grids
	BOLT_PRECISION			= Fl(9),	// bolt stops at target grid, and does not continue further
	BOLT_X_RAY				= Fl(10),	// bolt passes through 1 wall grid
	BOLT_X_RAY_EXITS		= Fl(11),	// ... and exits the other side, potentially exploding in the grid immediately afterwards
	BOLT_QUICKLY			= Fl(12),	// wand or staff only takes 50 energy to use
	BOLT_SLOWLY				= Fl(13),	// wand or staff takes 200 energy to use
	BOLT_EASY_CHARGING		= Fl(14),	// wand gets one extra charge when recharged or enchanted; staff recharges 50% faster
	BOLT_PREVENT_ALL_BUT_ELEMENTAL	= Fl(15),	// wand or staff must be fire, lightning, force, poison, tunnelling or blinking
	BOLT_PREVENT_BLINKING	= Fl(16),	// wand or staff cannot be blinking
	BOLT_PREVENT_CONJURING	= Fl(17),	// wand or staff cannot be conjuring
	BOLT_PREVENT_ASSISTING	= Fl(18),	// wand or staff cannot be cursed other than summoning, sentry, beckoning, polymorph, plenty
	BOLT_PREVENT_SUMMONING	= Fl(19),	// wand or staff cannot be summoning, sentry
	BOLT_PREVENT_BECKONING	= Fl(20),	// wand or staff cannot be beckoning
	BOLT_PREVENT_POLYMORPH	= Fl(21),	// wand or staff cannot be polymorph
	BOLT_PREVENT_PLENTY		= Fl(22),	// wand or staff cannot be plenty
	BOLT_PREVENT_SENTRY		= Fl(23),	// wand or staff cannot be sentry, underworm
	BOLT_PREVENT_OBSTRUCTION = Fl(24),	// wand or staff cannot be obstruction
	BOLT_PREVENT_TUNNELING = Fl(25),	// wand or staff cannot be tunneling
	BOLT_PREVENT_NATURE		= Fl(26),	// wand or staff cannot be nature
	BOLT_NO_DAMAGE			= Fl(27),	// don't inflict damage

	BOLT_PREVENT_UNUSUAL	= (BOLT_PREVENT_CONJURING | BOLT_PREVENT_ASSISTING | BOLT_PREVENT_SUMMONING | BOLT_PREVENT_OBSTRUCTION),
	BOLT_PREVENT_ANY		= ((BOLT_PREVENT_UNUSUAL) | BOLT_PREVENT_BLINKING | BOLT_PREVENT_BECKONING | BOLT_PREVENT_POLYMORPH | BOLT_PREVENT_PLENTY |
								BOLT_PREVENT_SENTRY | BOLT_PREVENT_OBSTRUCTION | BOLT_PREVENT_TUNNELING | BOLT_PREVENT_NATURE),
};

typedef struct boltRunic {
	char *name;
	float power;
	short number;
	unsigned long flags;
	unsigned long forbiddenFlags;
	char *description;
} boltRunic;

#define KEY_ID_MAXIMUM	20

typedef struct keyLocationProfile {
	short x;
	short y;
	short machine;
	boolean disposableHere;
} keyLocationProfile;

typedef struct item {
	unsigned long category;
	short kind;
	unsigned long flags;
	randomRange damage;
	short armor;
	short shieldChance;
	short shieldMinBlow;
	short shieldBlows;
	short charges;
	short enchant1;
	short enchant2;
	short hiddenRunic;
	short hiddenRunicEnchantsRequired;
	enum monsterTypes vorpalEnemy;
	short numberOfBoltEnchants;
	short boltEnchants[3];
	short strengthRequired;
	unsigned short quiverNumber;
	uchar displayChar;
	color *foreColor;
	color *inventoryColor;
	short quantity;
	char inventoryLetter;
	char inscription[DCOLS];
	short xLoc;
	short yLoc;
	keyLocationProfile keyLoc[KEY_ID_MAXIMUM];
	short keyZ;
	short keyAdoptedBy;
	struct item *nextItem;
} item;

typedef struct itemTable {
	char *name;
	char *flavor;
	char callTitle[30];
	short frequency;
	short marketValue;
	short strengthRequired;
	randomRange range;
	boolean identified;
	boolean called;
	char description[1500];
} itemTable;

enum dungeonFeatureTypes {
	DF_GRANITE_COLUMN = 1,
	DF_CRYSTAL_WALL,
	DF_LUMINESCENT_FUNGUS,
	DF_GRASS,
	DF_DEAD_GRASS,
	DF_BONES,
	DF_RUBBLE,
	DF_FOLIAGE,
	DF_FUNGUS_FOREST,
	DF_DEAD_FOLIAGE,

	DF_SUNLIGHT,
	DF_DARKNESS,

	DF_SHOW_DOOR,
	DF_SHOW_POISON_GAS_TRAP,
	DF_SHOW_PARALYSIS_GAS_TRAP,
	DF_SHOW_TRAPDOOR_HALO,
	DF_SHOW_TRAPDOOR,
	DF_SHOW_CONFUSION_GAS_TRAP,
	DF_SHOW_FLAMETHROWER_TRAP,
	DF_SHOW_FLOOD_TRAP,

	DF_RED_BLOOD,
	DF_GREEN_BLOOD,
	DF_PURPLE_BLOOD,
	DF_WORM_BLOOD,
	DF_ACID_BLOOD,
	DF_ASH_BLOOD,
	DF_EMBER_BLOOD,
	DF_ECTOPLASM_BLOOD,
	DF_RUBBLE_BLOOD,
	DF_ROT_GAS_BLOOD,

	DF_VOMIT,
	DF_BLOAT_DEATH,
	DF_BLOAT_EXPLOSION,
	DF_BLOOD_EXPLOSION,
	DF_FLAMEDANCER_CORONA,

	DF_REPEL_CREATURES,
	DF_ROT_GAS_PUFF,
	DF_STEAM_PUFF,
	DF_WIND_PUFF,
	DF_STEAM_ACCUMULATION,
	DF_METHANE_GAS_PUFF,
	DF_SALAMANDER_FLAME,
	DF_URINE,
	DF_UNICORN_POOP,
	DF_PUDDLE,
	DF_ASH,
	DF_ECTOPLASM_DROPLET,
	DF_FORCEFIELD,
	DF_LICHEN_GROW,
	DF_TUNNELIZE,
	//DF_LICHEN_PLANTED,

	DF_TRAMPLED_FOLIAGE,
	DF_SMALL_DEAD_GRASS,
	DF_FOLIAGE_REGROW,
	DF_TRAMPLED_FUNGUS_FOREST,
	DF_FUNGUS_FOREST_REGROW,
	DF_TRAMPLED_CREEPER_FUNGUS,
	DF_CREEPER_FUNGUS_REGROW,
	DF_CREEPER_LICHEN_CLOUD,

	// brimstone
	DF_ACTIVE_BRIMSTONE,
	DF_INERT_BRIMSTONE,
	DF_BRIMSTONE_OUTCROP,

	// witch hazel
	DF_WITCH_HAZEL_PICKED,

	// mandrake roots
	DF_MANDRAKE_PLANTED,
	DF_MANDRAKE_ROOTS_GROW,
	DF_MANDRAKE_ROOTS_BUILD,
	DF_LUMINESCENT_FUNGUS_BORDER,
	DF_MANDRAKE_ROOT_DIES,
	DF_MANDRAKE_SAC_SPLITS,

	// stinkfruit bushes
    DF_STINKFRUIT_PODS_GROW_INITIAL,
    DF_STINKFRUIT_PODS_GROW,
	DF_STINKFRUIT_POD_BURST,

    // bloodwort
    DF_BLOODFLOWER_PODS_GROW_INITIAL,
    DF_BLOODFLOWER_PODS_GROW,
    DF_BLOODFLOWER_POD_BURST,

    // algae
    DF_BUILD_ALGAE_WELL,
    DF_ALGAE_1,
    DF_ALGAE_2,
    DF_ALGAE_REVERT,

	DF_OPEN_DOOR,
	DF_CLOSED_DOOR,
	DF_OPEN_IRON_DOOR_INERT,
	DF_OPEN_IRON_DOOR_ON,
	DF_OPEN_IRON_DOOR_OFF,
	DF_ALTAR_SWITCH_ON,
	DF_ALTAR_SWITCH_OFF,
	DF_ALTAR_SWITCH_OPEN,
	DF_ALTAR_SWITCH_CLOSE,
	DF_ITEM_CAGE_OPEN,
	DF_ITEM_CAGE_CLOSE,
	DF_DOOR_CAGE_OPEN,
	DF_DOOR_CAGE_CLOSE,
	DF_ALTAR_DETECT_KEY,
	DF_ALTAR_INERT,
	DF_ALTAR_RETRACT,
	DF_PORTAL_ACTIVATE,
    DF_INACTIVE_GLYPH,
    DF_ACTIVE_GLYPH,
    DF_SILENT_GLYPH_GLOW,
    DF_GUARDIAN_STEP,
    DF_MIRROR_TOTEM_STEP,
    DF_GLYPH_CIRCLE,
    DF_GLYPH_CIRCLE_SMALL,
    DF_REVEAL_LEVER,
    DF_PULL_LEVER,
    DF_CREATE_LEVER,

	DF_PLAIN_FIRE,
	DF_GAS_FIRE,
	DF_EXPLOSION_FIRE,
	DF_DART_EXPLOSION,
	DF_BRIMSTONE_FIRE,
	DF_BRIDGE_FIRE,
	DF_FLAMETHROWER,
	DF_EMBERS,
	DF_EMBERS_PATCH,
	DF_OBSIDIAN,
	DF_OBSIDIAN_CRACKING,
	DF_OBSIDIAN_RUPTURING,
	DF_LAVA,
	DF_FLOOD,
	DF_FLOOD_2,
	DF_FLOOD_DRAIN,
	DF_HOLE_2,
	DF_HOLE_DRAIN,

	DF_POISON_GAS_CLOUD,
	DF_CONFUSION_GAS_TRAP_CLOUD,
	DF_METHANE_GAS_ARMAGEDDON,

	// potions
	DF_POISON_GAS_CLOUD_POTION,
	DF_PARALYSIS_GAS_CLOUD_POTION,
	DF_CONFUSION_GAS_CLOUD_POTION,
	DF_INCINERATION_POTION,
	DF_LIGHT_ELIXIR,
	DF_DARKNESS_POTION,
	DF_HOLE_POTION,
	DF_LICHEN_PLANTED,
	DF_DEEP_WATER_POTION,
	DF_WINDS_POTION,
	DF_ROT_GAS_CLOUD_POTION,
	DF_METHANE_GAS_CLOUD_POTION,
	DF_POTION_EXPLOSION,
	DF_HEALING_POTION,
	DF_FIRE_EXTINGUISHING_POTION,

    // other items
    DF_ARMOR_IMMOLATION,
//	DF_BOLT_PHANTOM_DARKNESS,
	DF_BOLT_NAGA_DEEP_WATER,
	DF_BOLT_SPIDER_WEB,
	DF_BOLT_NATURE_BRIDGE,
	DF_BOLT_NATURE_WATER,
	DF_BOLT_DETONATION,
	DF_METHANE_GAS_PUFF_ZOMBIE,
	DF_DART_DARKNESS,
	DF_DART_GRAPPLING,
	DF_DART_EXTINGUISH,

	// vampire in coffin
	DF_COFFIN_BURSTS,
	DF_COFFIN_BURNS,
	DF_TRIGGER_AREA,

	// gamble with gods
	DF_SURROUND_OBSIDIAN,
	DF_GODS_REVEAL,
	DF_GODS_REWARD,
	DF_GODS_PUNISH,
	DF_GODS_GAMBLED,
	DF_GRAFFITI_1,
	DF_GRAFFITI_2,
	DF_GRAFFITI_3,
	DF_GRAFFITI_4,

	// coat darts
	DF_ALEMBIC_POTION_CLOSES,
	DF_CONTAINER_DARTS_OPENS,

	// make elixir
	DF_PRESS_POTION,
	DF_PRESS_POTION_BURN,
	DF_PRESS_STAMP_POTION,
	DF_PRESS_BURN_POTION,

	// make charm
	DF_PRESS_SCROLL_CLOSES,
	DF_ALTAR_CHARM,

	// make tome
	DF_PRESS_SCROLL,
	DF_PRESS_SCROLL_BURN,
	DF_PRESS_STAMP_SCROLL,
	DF_PRESS_BURN_SCROLL,

	// press runes
	DF_PRESS_WEAPON,
	DF_PRESS_ARMOR,
	DF_PRESS_SHIELD,
	DF_PRESS_WAND,
	DF_PRESS_STAFF,
	DF_PRESS_RUNE,
	DF_PRESS_RUNE_WAND,
	DF_PRESS_RUNE_STAFF,
	DF_PRESS_STAMP_WEAPON,
	DF_PRESS_STAMP_ARMOR,
	DF_PRESS_STAMP_SHIELD,
	DF_PRESS_STAMP_WAND,
	DF_PRESS_STAMP_STAFF,
	DF_PRESS_STAMP_RUNE,
	DF_PRESS_STAMP_RUNE_WAND,
	DF_PRESS_STAMP_RUNE_STAFF,

	// sacrifice items
	DF_MAKE_SACRIFICE,
	DF_SACRIFICE_REWARDED,

	// flood tutorial
	DF_CAGE_APPEARS,

	// throwing tutorial -- button in chasm
	DF_CAGE_DISAPPEARS,
	DF_MEDIUM_HOLE,
	DF_MEDIUM_LAVA_POND,
    DF_MACHINE_PRESSURE_PLATE_USED,

    // rat trap
    DF_WALL_CRACK,

	// wooden barricade at entrance
	DF_ADD_WOODEN_BARRICADE,
	DF_WOODEN_BARRICADE_BURN,

	// wooden barricade around altar, dead grass all around
	DF_SURROUND_WOODEN_BARRICADE,

	// statues around altar, rubble all around
	DF_SURROUND_STATUE,

	// pools of water that, when triggered, slowly expand to fill the room
	DF_SPREADABLE_WATER,
	DF_SHALLOW_WATER,
	DF_WATER_SPREADS,
	DF_SPREADABLE_WATER_POOL,
	DF_SPREADABLE_DEEP_WATER_POOL,

	// when triggered, the ground gradually turns into chasm:
	DF_SPREADABLE_COLLAPSE,
	DF_COLLAPSE,
	DF_COLLAPSE_SPREADS,
	DF_ADD_MACHINE_COLLAPSE_EDGE_DORMANT,

	// when triggered, a bridge appears:
    DF_BRIDGE_ACTIVATE,
    DF_BRIDGE_ACTIVATE_ANNOUNCE,
	DF_BRIDGE_APPEARS,
    DF_ADD_DORMANT_CHASM_HALO,

	// when triggered, the lava retracts:
	DF_LAVA_RETRACTABLE,
	DF_RETRACTING_LAVA,
	DF_OBSIDIAN_WITH_STEAM,

	// when triggered, the door seals and poison gas fills the room
	DF_SHOW_POISON_GAS_VENT,
	DF_POISON_GAS_VENT_OPEN,
	DF_ACTIVATE_PORTCULLIS,
	DF_OPEN_PORTCULLIS,
	DF_VENT_SPEW_POISON_GAS,

	// when triggered, pilot light ignites and explosive gas fills the room
	DF_SHOW_METHANE_VENT,
	DF_METHANE_VENT_OPEN,
	DF_VENT_SPEW_METHANE,
	DF_PILOT_LIGHT,

    // paralysis trap: trigger plate with gas vents nearby
	DF_DISCOVER_PARALYSIS_VENT,
	DF_PARALYSIS_VENT_SPEW,
	DF_REVEAL_PARALYSIS_VENT_SILENTLY,

	// thematic dungeon
	DF_AMBIENT_BLOOD,

	// statues crack for a few turns and then shatter, revealing the monster inside
	DF_CRACKING_STATUE,
	DF_STATUE_SHATTER,

	// a turret appears:
	DF_TURRET_EMERGE,

    // an elaborate worm catacomb opens up
    DF_WORM_TUNNEL_MARKER_DORMANT,
    DF_WORM_TUNNEL_MARKER_ACTIVE,
    DF_GRANITE_CRUMBLES,
    DF_WALL_OPEN,

	// the room gradually darkens
	DF_DARKENING_FLOOR,
	DF_DARK_FLOOR,
    DF_HAUNTED_TORCH_TRANSITION,
    DF_HAUNTED_TORCH,

	// bubbles rise from the mud and bog monsters spawn
	DF_MUD_DORMANT,
	DF_MUD_ACTIVATE,

	// arena
	DF_ARENA_CAGE_OPENS,
	DF_FLAMETHROWER_TRAP_HIDDEN,

	// prism
	DF_PRISM_SHATTERS,
	DF_SURROUND_CRYSTAL_PRISM,

	// chamber
	DF_CHAMBER_OPENS,
	DF_CHARGE_CAPACITOR,
	DF_DISCHARGE_CAPACITOR,

	// sticky bundles
	DF_BURNING_BUNDLE,
	DF_SPIDER_BURNS,
	DF_SPIDER_CLIMBS,

	// idyll:
	DF_WATER_POOL,
    DF_DEEP_WATER_POOL,

	// swamp:
	DF_SWAMP_WATER,
	DF_SWAMP,
	DF_SWAMP_MUD,

	// camp:
	DF_HAY,
	DF_JUNK,

	// remnants:
	DF_REMNANT,
	DF_REMNANT_ASH,

	// chasm catwalk:
	DF_CHASM_HOLE,
	DF_CATWALK_BRIDGE,

	// lake catwalk:
	DF_LAKE_CELL,
	DF_LAKE_HALO,

	// worm den:
	DF_WALL_SHATTER,

	// monster cages open:
	DF_MONSTER_CAGE_OPENS,

	NUMBER_DUNGEON_FEATURES,
};

typedef struct lightSource {
	const color *lightColor;
	randomRange lightRadius;
	short radialFadeToPercent;
	boolean passThroughCreatures; // generally no, but miner light does
} lightSource;

enum DFEffects {
	E_NOTHING = 0,
	E_DAMAGE,
	E_EXPLOSIVE_DAMAGE,
	E_POISON,
	E_CONFUSION,
	E_PARALYSIS,
	E_DESCENT,
	E_NAUSEA,
};

enum DFFlags {
	DFF_EVACUATE_CREATURES_FIRST	= Fl(0),	// Creatures in the DF area get moved outside of it
	DFF_SUBSEQ_EVERYWHERE			= Fl(1),	// Subsequent DF spawns in every cell that this DF spawns in, instead of only the origin
	DFF_TREAT_AS_BLOCKING			= Fl(2),	// If filling the footprint of this DF with walls would disrupt level connectivity, then abort.
	DFF_PERMIT_BLOCKING				= Fl(3),	// Generate this DF without regard to level connectivity.
	DFF_ACTIVATE_DORMANT_MONSTER	= Fl(4),	// Dormant monsters on this tile will appear -- e.g. when a statue bursts to reveal a monster.
	DFF_CLEAR_OTHER_TERRAIN			= Fl(5),	// Erase other terrain in the footprint of this DF.
	DFF_BLOCKED_BY_OTHER_LAYERS		= Fl(6),	// Will not propagate into a cell if any layer in that cell has a superior priority.
	DFF_SUPERPRIORITY				= Fl(7),	// Will overwrite terrain of a superior priority.
	DFF_ENRAGE_ALLIES				= Fl(8),	// Allies on this tile will be switched to enemies
	DFF_MERGE_ITEMS					= Fl(9),	// The item on this dungeon feature is merged with another
	DFF_DESTROY_ITEM				= Fl(10),	// The item on this dungeon feature is destroyed
	DFF_LAVA_BECOMES_OBSIDIAN		= Fl(11),	// Lava in the grid is replaced by obsidian
	DFF_DETECT_ADOPTED_KEY			= Fl(12),	// Key adopted by this room is detected
	DFF_ATTACK_SHALLOWS				= Fl(13),	// Eels, kraken will begin attacking monsters in shallow water
	DFF_RECHARGE_STAFFS_BY_ONE		= Fl(14),	// The player's staffs are recharged by one, overcharging allowed
	DFF_ALWAYS_MESSAGE				= Fl(15),	// display message even if terrain not visible
};

// Dungeon features, spawned from Architect.c:
typedef struct dungeonFeature {
	// tile info:
	enum tileType tile;
	enum dungeonLayers layer;

	// spawning pattern:
	short startProbability;
	short probabilityDecrement;
	unsigned long flags;
	char description[DCOLS];
	const color *flashColor;
	short flashRadius;
	enum tileType propagationTerrain;
	enum dungeonFeatureTypes subsequentDF;
	boolean messageDisplayed;
} dungeonFeature;

typedef struct floorTileType {
	// appearance:
	uchar displayChar;
	const color *foreColor;
	const color *backColor;
	// draw priority (lower number means higher priority):
	short drawPriority;
	// settings related to fire:
	char chanceToIgnite;					// doubles as chance to extinguish once ignited, if T_IS_FIRE set
	enum dungeonFeatureTypes fireType;		// doubles as terrain type remaining after extinguished, if T_IS_FIRE is set
	enum dungeonFeatureTypes discoverType;	// spawn this DF when successfully searched if T_IS_SECRET is set
	enum dungeonFeatureTypes promoteType;	// creates this dungeon spawn type
	short promoteChance;					// percent chance per turn to spawn the promotion type; will also vanish upon doing so if T_VANISHES_UPON_PROMOTION is set
	short glowLight;						// if it glows, this is the ID of the light type
	unsigned long flags;
	char description[COLS];
	char flavorText[COLS];
	unsigned long flags2;					// here to avoid having to rewrite every floorTileType entry
	unsigned long flags3;					// here to avoid having to rewrite every floorTileType entry
} floorTileType;

enum terrainFlagCatalog {
	T_OBSTRUCTS_PASSABILITY			= Fl(0),		// cannot be walked through
	T_OBSTRUCTS_VISION				= Fl(1),		// blocks line of sight
	T_OBSTRUCTS_ITEMS				= Fl(2),		// items can't be on this tile
	T_OBSTRUCTS_SURFACE_EFFECTS		= Fl(3),		// grass, blood, etc. cannot exist on this tile
	T_OBSTRUCTS_GAS					= Fl(4),		// blocks the permeation of gas
	T_OBSTRUCTS_DIAGONAL_MOVEMENT	= Fl(5),		// can't step diagonally around this tile
	T_PROMOTES_WITH_KEY				= Fl(6),		// promotes if the key is present on the tile (in your pack, carried by monster, or lying on the ground)
	T_PROMOTES_WITHOUT_KEY			= Fl(7),		// promotes if the key is NOT present on the tile (in your pack, carried by monster, or lying on the ground)
	T_SPONTANEOUSLY_IGNITES			= Fl(8),		// monsters avoid unless chasing player or immune to fire
	T_AUTO_DESCENT					= Fl(9),		// automatically drops creatures down a depth level and does some damage (2d6)
	T_PROMOTES_ON_STEP				= Fl(10),		// promotes when a creature, player or item is on the tile (whether or not levitating)
	T_PROMOTES_ON_PLAYER_ENTRY		= Fl(11),		// promotes when the player enters the tile (whether or not levitating)
	T_LAVA_INSTA_DEATH				= Fl(12),		// kills any non-levitating non-fire-immune creature instantly
	T_CAUSES_POISON					= Fl(13),		// any non-levitating creature gets 10 poison
	T_IS_FLAMMABLE					= Fl(14),		// terrain can catch fire
	T_IS_FIRE						= Fl(15),		// terrain is a type of fire; ignites neighboring flammable cells
	T_ENTANGLES						= Fl(16),		// entangles players and monsters like a spiderweb
	T_IS_DEEP_WATER					= Fl(17),		// steals items 50% of the time and moves them around randomly
	T_ALLOWS_SUBMERGING				= Fl(18),		// allows submersible monsters to submerge in this terrain
	T_IS_SECRET						= Fl(19),		// successful search or being stepped on while visible transforms it into discoverType
	T_IS_WIRED						= Fl(20),		// if wired, promotes when powered, and sends power when promoting
	T_GAS_DISSIPATES				= Fl(21),		// does not just hang in the air forever
	T_GAS_DISSIPATES_QUICKLY		= Fl(22),		// dissipates quickly
	T_CAUSES_DAMAGE					= Fl(23),		// anything on the tile takes max(1-2, 10%) damage per turn
	T_CAUSES_NAUSEA					= Fl(24),		// any creature on the tile becomes nauseous
	T_CAUSES_PARALYSIS				= Fl(25),		// anything caught on this tile is paralyzed
	T_CAUSES_CONFUSION				= Fl(26),		// causes creatures on this tile to become confused
	T_IS_DF_TRAP					= Fl(27),		// spews gas of type specified in fireType when stepped on
	T_VANISHES_UPON_PROMOTION		= Fl(28),		// vanishes when creating promotion dungeon feature;
													// can be overwritten anyway depending on priorities and layers of dungeon feature
	T_CAUSES_EXPLOSIVE_DAMAGE		= Fl(29),		// is an explosion; deals higher of 15-20 or 50% damage instantly, but not again for five turns
	T_CAUSES_FIERY_DAMAGE			= Fl(30),		// anything on the tile takes max(1-2, 10%) damage per turn, fiery monsters are immune
	T_STAND_IN_TILE					= Fl(31),		// earthbound creatures will be said to stand "in" the tile, not on it

	T_OBSTRUCTS_SCENT				= (T_OBSTRUCTS_PASSABILITY | T_OBSTRUCTS_VISION | T_AUTO_DESCENT | T_IS_DF_TRAP | T_LAVA_INSTA_DEATH | T_IS_DEEP_WATER | T_SPONTANEOUSLY_IGNITES),

	T_PATHING_BLOCKER				= (T_OBSTRUCTS_PASSABILITY | T_AUTO_DESCENT | T_IS_DF_TRAP | T_LAVA_INSTA_DEATH | T_IS_DEEP_WATER | T_IS_FIRE | T_SPONTANEOUSLY_IGNITES),
	T_LAKE_PATHING_BLOCKER			= (T_AUTO_DESCENT | T_LAVA_INSTA_DEATH | T_IS_DEEP_WATER | T_SPONTANEOUSLY_IGNITES),
	T_WAYPOINT_BLOCKER				= (T_OBSTRUCTS_PASSABILITY | T_AUTO_DESCENT | T_IS_DF_TRAP | T_LAVA_INSTA_DEATH | T_IS_DEEP_WATER | T_SPONTANEOUSLY_IGNITES),
	T_MOVES_ITEMS					= (T_IS_DEEP_WATER | T_LAVA_INSTA_DEATH),
	T_CAN_BE_BRIDGED				= (T_AUTO_DESCENT),
	T_OBSTRUCTS_EVERYTHING			= (T_OBSTRUCTS_PASSABILITY | T_OBSTRUCTS_VISION | T_OBSTRUCTS_ITEMS | T_OBSTRUCTS_GAS | T_OBSTRUCTS_SURFACE_EFFECTS | T_OBSTRUCTS_DIAGONAL_MOVEMENT),
	T_HARMFUL_TERRAIN				= (T_CAUSES_POISON | T_IS_FIRE | T_CAUSES_DAMAGE | T_CAUSES_PARALYSIS | T_CAUSES_CONFUSION | T_CAUSES_EXPLOSIVE_DAMAGE |
									   T_CAUSES_FIERY_DAMAGE),
	T_RESPIRATION_IMMUNITIES        = (T_CAUSES_DAMAGE | T_CAUSES_FIERY_DAMAGE | T_CAUSES_CONFUSION | T_CAUSES_PARALYSIS | T_CAUSES_NAUSEA),

};

enum terrainFlag2Catalog {
	T2_PROMOTES_WITH_FOOD			= Fl(0),		// promotes when food dropped here
	T2_PROMOTES_WITH_WEAPON			= Fl(1),		// promotes when weapon dropped here
	T2_PROMOTES_WITH_ARMOR			= Fl(2),		// promotes when armor dropped here
	T2_PROMOTES_WITH_SHIELD			= Fl(3),		// promotes when shield dropped here
	T2_PROMOTES_WITH_POTION			= Fl(4),		// promotes when potion dropped here
	T2_PROMOTES_WITH_ELIXIR			= Fl(5),		// promotes when elixir dropped here - unused
	T2_PROMOTES_WITH_SCROLL			= Fl(6),		// promotes when scroll dropped here
	T2_PROMOTES_WITH_TOME			= Fl(7),		// promotes when tome dropped here - unused
	T2_PROMOTES_WITH_STAFF			= Fl(8),		// promotes when staff dropped here
	T2_PROMOTES_WITH_WAND			= Fl(9),		// promotes when wand dropped here
	T2_PROMOTES_WITH_RING			= Fl(10),		// promotes when ring dropped here
	T2_PROMOTES_WITH_CHARM			= Fl(11),		// promotes when charm dropped here - unused
	T2_PROMOTES_WITH_TALISMAN		= Fl(12),		// promotes when talisman dropped here
	T2_PROMOTES_WITH_GOLD			= Fl(13),		// promotes when gold dropped here - unused, will need a hack (e.g. reduce score) implemented
	T2_PROMOTES_WITH_AMULET			= Fl(14),		// promotes when amulet dropped here - unused
	T2_PROMOTES_WITH_GEM			= Fl(15),		// promotes when gem dropped here
	T2_PROMOTES_WITH_KEY_DROPPED	= Fl(16),		// promotes when key dropped here
	T2_PROMOTES_ON_ITEM_PICKUP		= Fl(17),		// promotes when an item is lifted from the tile (primarily for altars)
	T2_REFLECTS_BOLTS				= Fl(18),		// reflects bolts
	T2_CONDUCTIVE_WALL				= Fl(19),		// lightning passes through this grid even if it normally obstructs passability or vision
	T2_PROMOTES_WITH_LIGHTNING		= Fl(20),		// lightning promotes this grid
	T2_CIRCUIT_BREAKER				= Fl(21),		// prevents room from powering up
	T2_PROMOTES_WITH_CIRCUIT_BROKEN	= Fl(22),		// promotes if last circuit breaker in the room promotes (including itself). Does not need the T_IS_WIRED flag for this.
	T2_PROMOTES_WITH_FIRE			= Fl(23),		// if set on fire, triggers other wired tiles in machine
	T2_TUNNELIZE_IGNORES_GRID		= Fl(24),		// do not tunnelize grid, tunnelling bolt passes through grid
	T2_PROMOTES_WITHOUT_ENTRY		= Fl(25),		// promotes if the tile does not have a monster or the player in it
	T2_PROMOTES_WITH_ENTRY			= Fl(26),		// promotes if the tile does has a monster or the player move onto it
	T2_CAN_CLIMB					= Fl(27),		// prevents player & monsters from falling into chasm, lava, water like spiderweb
	T2_GROUND_LIGHTNING				= Fl(28),		// if lightning hits a monster in this grid, it stops, and surrounds the grid with a shower of sparks
	T2_CONDUCTIVE_FLOOR				= Fl(29),		// sparks travel through this grid from grounded lightning or sparking terrain
	T2_IS_SPARKING					= Fl(30),		// terrain generates two 1 damage sparks each turn
	T2_EXTINGUISHES_FIRE			= Fl(31),		// extinguishes burning terrain or creatures

	T2_PROMOTES_ON_DROP				= (T2_PROMOTES_WITH_FOOD | T2_PROMOTES_WITH_WEAPON | T2_PROMOTES_WITH_ARMOR | T2_PROMOTES_WITH_SHIELD | T2_PROMOTES_WITH_POTION |
									   T2_PROMOTES_WITH_ELIXIR | T2_PROMOTES_WITH_SCROLL | T2_PROMOTES_WITH_TOME | T2_PROMOTES_WITH_STAFF | T2_PROMOTES_WITH_WAND |
									   T2_PROMOTES_WITH_RING | T2_PROMOTES_WITH_CHARM | T2_PROMOTES_WITH_TALISMAN | T2_PROMOTES_WITH_GOLD | T2_PROMOTES_WITH_GEM |
									   T2_PROMOTES_WITH_AMULET | T2_PROMOTES_WITH_KEY_DROPPED),
	T2_PROMOTES_WITH_GAMBLE			= ((T2_PROMOTES_ON_DROP) & ~(T2_PROMOTES_WITH_GOLD | T2_PROMOTES_WITH_GEM | T2_PROMOTES_WITH_AMULET | T2_PROMOTES_WITH_KEY_DROPPED)),

};

enum terrainFlag3Catalog {
    T3_CAUSES_HEALING               = Fl(0),		// heals 20% max HP per turn for any player or non-inanimate monsters
	T3_IS_PLANTED					= Fl(2),		// prevents staff of nature bolt taking effect within distance determined by enchantment, detected if this is the case
	T3_IS_FERTILE					= Fl(3),		// bolt of nature can plant in terrain after traversing 2 grids of same terrain
	T3_PROMOTES_ON_SHOT				= Fl(4),		// promotes if hit by a damaging bolt or thrown weapon
	T3_AVOID						= Fl(5),		// avoid stepping on this terrain
	T3_IS_WIND						= Fl(23),		// blocking throwing attacks, flying monsters move as if confused and scrolls get blown around randomly
};


enum statusEffects {
	STATUS_WEAKENED = 0,
	STATUS_STRONGER,
	STATUS_TELEPATHIC,
	STATUS_HALLUCINATING,
	STATUS_DREAMING,
	STATUS_LEVITATING,
	STATUS_LEVITATING_NOT_NEGATABLE,
	STATUS_SLOWED,
	STATUS_HASTED,
	STATUS_HASTED_NOT_NEGATABLE,
	STATUS_CONFUSED,
	STATUS_BURNING,
	STATUS_PARALYZED,
	STATUS_POISONED,
	STATUS_STUCK,
	STATUS_NAUSEOUS,
	STATUS_DISCORDANT,
	STATUS_IMMUNE_TO_FIRE,
	STATUS_IMMUNE_TO_FIRE_NOT_NEGATABLE,
	STATUS_EXPLOSION_IMMUNITY,
	STATUS_POISON_IMMUNITY,
	STATUS_CONFUSION_IMMUNITY,
	STATUS_PARALYSIS_IMMUNITY,
	STATUS_NUTRITION,
	STATUS_ENTERS_LEVEL_IN,
	STATUS_MAGICAL_FEAR,
	STATUS_ENTRANCED,
	STATUS_ENTRANCED_BY_WAND,
	STATUS_DARKNESS,
	STATUS_LIGHTENED,
	STATUS_LIFESPAN_REMAINING,
	STATUS_SHIELDED,
    STATUS_INVISIBLE,
	STATUS_IMPROVED_INVISIBLE,
	STATUS_REFLECTIVE,
	STATUS_MARKED,
	STATUS_BLESSED,
	STATUS_AGGRAVATED,
	STATUS_NEGATED,
	STATUS_POLYMORPHED,
	STATUS_DOMINATED,
	NUMBER_OF_STATUS_EFFECTS,
};

enum hordeFlags {
	HORDE_DIES_ON_LEADER_DEATH		= Fl(0),	// if the leader dies, the horde will die instead of electing new leader
	HORDE_IS_SUMMONED				= Fl(1),	// minions summoned when any creature is the same species as the leader and casts summon
	HORDE_LEADER_CAPTIVE			= Fl(2),	// the leader is in chains and the followers are guards
	HORDE_NO_PERIODIC_SPAWN			= Fl(3),	// can spawn only when the level begins -- not afterwards

	HORDE_MACHINE_BOSS				= Fl(4),	// used in machines for a boss challenge
	HORDE_MACHINE_WATER_MONSTER		= Fl(5),	// used in machines where the room floods with shallow water
	HORDE_MACHINE_CAPTIVE			= Fl(6),	// powerful captive monsters without any captors
	HORDE_MACHINE_STATUE			= Fl(7),	// the kinds of monsters that make sense in a statue
	HORDE_MACHINE_TURRET			= Fl(8),	// turrets, for hiding in walls
	HORDE_MACHINE_MUD				= Fl(9),	// bog monsters, for hiding in mud
	HORDE_MACHINE_KENNEL			= Fl(10),	// monsters that can appear in cages in kennels
	HORDE_VAMPIRE_FODDER			= Fl(11),	// monsters that are prone to capture and farming by vampires
	HORDE_MACHINE_LEGENDARY_ALLY	= Fl(12),	// legendary allies
    HORDE_NEVER_OOD                 = Fl(13),   // horde cannot spawn out of depth
	HORDE_SENTRY					= Fl(14),	// horde summoned by bolt of sentries
	//HORDE_PHANTOM					= Fl(14),	// horde summoned by bolt of phantoms
	HORDE_ZOMBIE					= Fl(15),	// horde summoned by bolt of zombies
	HORDE_BLOAT						= Fl(16),	// horde summoned by bolt of bloats
	HORDE_SPIDER					= Fl(17),	// horde summoned by bolt of spiders
	HORDE_NAGA						= Fl(18),	// horde summoned by bolt of nagas
	HORDE_PIXIE						= Fl(19),	// horde summoned by bolt of pixies
	HORDE_TOAD						= Fl(20),	// horde summoned by bolt of toads
	HORDE_UNDERWORM					= Fl(21),	// horde summoned by bolt of underworms
	HORDE_MACHINE_MANDRAKE			= Fl(22),	// horde planted in mandrake roots by bolt of nature, summoned by bolt of mandrakes
	HORDE_DEAD_MANS_EAR				= Fl(23),	// horde planted in bog/gray fungus by bolt of nature, summoned by bolt of dead man's ear
	HORDE_MACHINE_CRIMSON_CAP		= Fl(24),	// horde planted in luminescent fungus by bolt of nature, summoned by bolt of crimson cap
	HORDE_MIRRORED_TOTEM			= Fl(25),	// horde summoned by bolt of mirrored totems
	HORDE_MACHINE_ARENA				= Fl(26),	// monsters that can appear in cages in arenas
	HORDE_MACHINE_BUNDLE			= Fl(27),	// monsters that can be captured but not killed by spiders
	HORDE_MACHINE_PRISM				= Fl(28),	// monsters that can be found in giant crystal prisms
	HORDE_MACHINE_CHAMBER			= Fl(29),	// monsters that can be resurrected by lightning powered capacitors
	HORDE_MACHINE_THIEF				= Fl(30),	// monsters that are thieves
	HORDE_ASSASSINATION_TARGET		= Fl(31),	// horde is the target for an assassin

	HORDE_ALLIED_WITH_PLAYER		= (HORDE_MACHINE_LEGENDARY_ALLY | HORDE_MACHINE_MANDRAKE | HORDE_DEAD_MANS_EAR),
	HORDE_DORMANT					= (HORDE_UNDERWORM | HORDE_MACHINE_MANDRAKE),
	HORDE_MARKED					= (HORDE_MACHINE_CRIMSON_CAP),

	HORDE_MACHINE_ONLY				= (HORDE_MACHINE_BOSS | HORDE_MACHINE_WATER_MONSTER
									   | HORDE_MACHINE_CAPTIVE | HORDE_MACHINE_STATUE
									   | HORDE_MACHINE_TURRET | HORDE_MACHINE_MUD
									   | HORDE_MACHINE_KENNEL | HORDE_VAMPIRE_FODDER
									   | HORDE_MACHINE_LEGENDARY_ALLY | HORDE_MACHINE_ARENA
									   | HORDE_MACHINE_BUNDLE | HORDE_MACHINE_PRISM
									   | HORDE_MACHINE_CHAMBER | HORDE_MACHINE_THIEF
									   | HORDE_MACHINE_MANDRAKE | HORDE_MACHINE_CRIMSON_CAP),
};

enum monsterBehaviorFlags {
	MONST_INVISIBLE					= Fl(0),	// monster is invisible
	MONST_INANIMATE					= Fl(1),	// monster has abbreviated stat bar display and is immune to many things
	MONST_IMMOBILE					= Fl(2),	// monster won't move or perform melee attacks
	MONST_CARRY_ITEM_100			= Fl(3),	// monster carries an item 100% of the time
	MONST_CARRY_ITEM_25				= Fl(4),	// monster carries an item 25% of the time
	MONST_ALWAYS_HUNTING			= Fl(5),	// monster is never asleep or in wandering mode
	MONST_FLEES_NEAR_DEATH			= Fl(6),	// monster flees when under 25% health and re-engages when over 75%
	MONST_ATTACKABLE_THRU_WALLS		= Fl(7),	// can be attacked when embedded in a wall
	MONST_DEFEND_DEGRADE_WEAPON		= Fl(8),	// hitting the monster damages the weapon
	MONST_IMMUNE_TO_WEAPONS			= Fl(9),	// weapons ineffective
	MONST_FLIES						= Fl(10),	// permanent levitation
	MONST_FLITS						= Fl(11),	// moves randomly a third of the time
	MONST_IMMUNE_TO_FIRE			= Fl(12),	// won't burn, won't die in lava
	MONST_CAST_SPELLS_SLOWLY		= Fl(13),	// takes twice the attack duration to cast a spell
	MONST_IMMUNE_TO_WEBS			= Fl(14),	// monster passes freely through webs
	MONST_REFLECT_4					= Fl(15),	// monster reflects projectiles as though wearing +4 armor of reflection
	MONST_NEVER_SLEEPS				= Fl(16),	// monster is always awake
	MONST_FIERY						= Fl(17),	// monster carries an aura of flame (but no automatic fire light), immune to explosions and steam
	MONST_INTRINSIC_LIGHT			= Fl(18),	// monster carries an automatic light of the specified kind
	MONST_IMMUNE_TO_WATER			= Fl(19),	// monster moves at full speed in deep water and (if player) doesn't drop items
	MONST_RESTRICTED_TO_LIQUID		= Fl(20),	// monster can move only on tiles that allow submersion
	MONST_SUBMERGES					= Fl(21),	// monster can submerge in appropriate terrain
	MONST_MAINTAINS_DISTANCE		= Fl(22),	// monster tries to keep a distance of 3 tiles between it and player
	MONST_WILL_NOT_USE_STAIRS		= Fl(23),	// monster won't chase the player between levels
	MONST_DIES_IF_NEGATED			= Fl(24),	// monster will die if exposed to negation magic
	MONST_MALE						= Fl(25),	// monster is male (or 50% likely to be male if also has MONST_FEMALE)
	MONST_FEMALE					= Fl(26),	// monster is female (or 50% likely to be female if also has MONST_MALE)
    MONST_NOT_LISTED_IN_SIDEBAR     = Fl(27),   // monster doesn't show up in the sidebar
    MONST_GETS_TURN_ON_ACTIVATION   = Fl(28),   // monster never gets a turn, except when its machine is activated
    MONST_ALWAYS_USE_ABILITY        = Fl(29),   // monster will never fail to use special ability if eligible (no random factor)
	MONST_SHIELD_BLOCKS				= Fl(30),	// monster has a shield that blocks (defense/2)% + 3%/range of attacks. Enemy shields are only half as effective in melee.

	NEGATABLE_TRAITS				= (MONST_INVISIBLE | MONST_DEFEND_DEGRADE_WEAPON | MONST_IMMUNE_TO_WEAPONS | MONST_FLIES
									   | MONST_FLITS | MONST_IMMUNE_TO_FIRE | MONST_FIERY | MONST_MAINTAINS_DISTANCE | MONST_REFLECT_4),
	AGGRAVATED_TRAITS				= (MONST_FLEES_NEAR_DEATH | MONST_FLITS | MONST_MAINTAINS_DISTANCE),
	MONST_TURRET					= (MONST_IMMUNE_TO_WEBS | MONST_NEVER_SLEEPS | MONST_IMMOBILE | MONST_INANIMATE |
									   MONST_ALWAYS_HUNTING | MONST_ATTACKABLE_THRU_WALLS | MONST_WILL_NOT_USE_STAIRS),
	LEARNABLE_BEHAVIORS				= (MONST_INVISIBLE | MONST_FLIES | MONST_IMMUNE_TO_FIRE | MONST_REFLECT_4),
	MONST_NEVER_VORPAL_ENEMY		= (MONST_INANIMATE | MONST_IMMOBILE | MONST_RESTRICTED_TO_LIQUID | MONST_GETS_TURN_ON_ACTIVATION),
	CHAOTIC_TRAITS					= (LEARNABLE_BEHAVIORS) | (MONST_IMMUNE_TO_WEAPONS | MONST_FLITS | MONST_IMMUNE_TO_WEBS | MONST_FIERY |
										MONST_INTRINSIC_LIGHT | MONST_IMMUNE_TO_WATER | MONST_DIES_IF_NEGATED),
};

enum monsterAbilityFlags {
	MA_HIT_HALLUCINATE				= Fl(0),	// monster can hit to cause hallucinations
	MA_HIT_STEAL_FLEE				= Fl(1),	// monster can steal an item and then run away
	MA_ENTER_SUMMONS				= Fl(2),	// monster will "become" its summoned leader, reappearing when that leader is defeated
	MA_HIT_DEGRADE_ARMOR			= Fl(3),	// monster damages armor
	MA_CAST_HEAL					= Fl(4),
	MA_CAST_HASTE					= Fl(5),
	MA_CAST_PROTECTION				= Fl(6),
	MA_CAST_SUMMON					= Fl(7),	// requires that there be one or more summon hordes with this monster type as the leader
	MA_CAST_BLINK					= Fl(8),
	MA_CAST_NEGATION				= Fl(9),
	MA_CAST_SPARK					= Fl(10),
	MA_CAST_FIRE					= Fl(11),
	MA_CAST_SLOW					= Fl(12),
	MA_CAST_DISCORD					= Fl(13),
    MA_CAST_BECKONING               = Fl(14),
	MA_BREATHES_FIRE				= Fl(15),	// shoots dragonfire at player from a distance
	MA_SHOOTS_WEBS					= Fl(16),	// monster shoots webs at the player
	MA_ATTACKS_FROM_DISTANCE		= Fl(17),	// monster shoots from a distance for its attack
	MA_SEIZES						= Fl(18),	// monster seizes enemies before attacking and cannot attack flying enemies
	MA_POISONS						= Fl(19),	// monster's damage is dealt in the form of poison, and it flees a poisoned player
	MA_CONFUSES						= Fl(20),	// monster's damage is dealt in the form of confusion, and it keeps distance
	MA_DF_ON_DEATH					= Fl(20),	// monster spawns its DF when it dies
	MA_CLONE_SELF_ON_DEFEND			= Fl(21),	// monster splits in two when struck
	MA_KAMIKAZE						= Fl(22),	// monster dies instead of attacking
	MA_TRANSFERENCE					= Fl(23),	// monster recovers 90% of the damage that it inflicts as health / 40% if ally
	MA_CAUSES_WEAKNESS				= Fl(24),	// monster attacks cause weakness status in target
	MA_CAST_SENTRY					= Fl(25),
	MA_CALL_GUARDIAN				= Fl(26),	// call guardians towards the player
	MA_HIT_KNOCKBACK				= Fl(27),	// monster can hit to knock the defender back 2 grids, triple damage if hits a wall
	MA_CAST_INVISIBILITY			= Fl(28),
	MA_ATTACKS_PENETRATE			= Fl(30),	// monster can hit through two grids
	MA_ATTACKS_ALL_ADJACENT			= Fl(31),	// monster hits all adjacent enemies

	MAGIC_ATTACK					= (MA_CAST_HEAL | MA_CAST_HASTE | MA_CAST_PROTECTION | MA_CAST_NEGATION | MA_CAST_SPARK | MA_CAST_FIRE | MA_CAST_SUMMON
									   | MA_CAST_SLOW | MA_CAST_DISCORD | MA_BREATHES_FIRE | MA_SHOOTS_WEBS | MA_ATTACKS_FROM_DISTANCE | MA_CAST_BECKONING
									   | MA_CAST_SENTRY),
	NEGATABLE_ATTACKS				= ~(MA_ATTACKS_FROM_DISTANCE | MA_HIT_KNOCKBACK | MA_ATTACKS_PENETRATE | MA_ATTACKS_ALL_ADJACENT),
	AGGRAVATED_ATTACKS				= (MA_HIT_STEAL_FLEE), // consider MA_POISONS
	SPECIAL_HIT						= (MA_HIT_HALLUCINATE | MA_HIT_STEAL_FLEE | MA_HIT_DEGRADE_ARMOR | MA_POISONS | MA_TRANSFERENCE | MA_CAUSES_WEAKNESS),
	LEARNABLE_ABILITIES				= (MA_CAST_HASTE | MA_CAST_PROTECTION | MA_CAST_BLINK | MA_CAST_NEGATION | MA_CAST_SPARK | MA_CAST_FIRE
									   | MA_CAST_SLOW | MA_CAST_DISCORD | MA_TRANSFERENCE | MA_CAUSES_WEAKNESS | MA_HIT_KNOCKBACK/* | MA_ATTACKS_PENETRATE
									   | MA_ATTACKS_ALL_ADJACENT*/),
	MA_NEVER_VORPAL_ENEMY           = (MA_KAMIKAZE),
	CHAOTIC_ATTACKS					= (LEARNABLE_ABILITIES) | (MA_BREATHES_FIRE | MA_SHOOTS_WEBS | MA_CAST_BECKONING | MA_CAST_SENTRY | MA_POISONS
											| MA_HIT_KNOCKBACK | MA_ATTACKS_PENETRATE | MA_ATTACKS_ALL_ADJACENT),
	CHAOTIC_ACTIVATION				= (MA_CAST_HEAL | MA_CAST_HASTE | MA_CAST_PROTECTION | MA_CAST_NEGATION | MA_CAST_SPARK | MA_CAST_FIRE | MA_CAST_SUMMON
									   | MA_CAST_SLOW | MA_CAST_DISCORD | MA_BREATHES_FIRE | MA_SHOOTS_WEBS | MA_CAST_BLINK | MA_CAST_BECKONING | MA_CAST_SENTRY),

};

enum monsterBookkeepingFlags {
	MONST_WAS_VISIBLE				= Fl(0),	// monster was visible to player last turn
	// unused						= Fl(1),
	MONST_PREPLACED					= Fl(2),	// monster dropped onto the level and requires post-processing
	MONST_APPROACHING_UPSTAIRS		= Fl(3),	// following the player up the stairs
	MONST_APPROACHING_DOWNSTAIRS	= Fl(4),	// following the player down the stairs
	MONST_APPROACHING_PIT			= Fl(5),	// following the player down a pit
	MONST_LEADER					= Fl(6),	// monster is the leader of a horde
	MONST_FOLLOWER					= Fl(7),	// monster is a member of a horde
	MONST_CAPTIVE					= Fl(8),	// monster is all tied up
	MONST_SEIZED					= Fl(9),	// monster is being held
	MONST_SEIZING					= Fl(10),	// monster is holding another creature immobile
	MONST_SUBMERGED					= Fl(11),	// monster is currently submerged and hence invisible until it attacks
	MONST_JUST_SUMMONED				= Fl(12),	// used to mark summons so they can be post-processed
	MONST_WILL_FLASH				= Fl(13),	// this monster will flash as soon as control is returned to the player
	MONST_BOUND_TO_LEADER			= Fl(14),	// monster will die if the leader dies or becomes separated from the leader
	MONST_ABSORBING					= Fl(15),	// currently learning a skill by absorbing an enemy corpse
	MONST_DOES_NOT_TRACK_LEADER		= Fl(16),	// monster will not follow its leader around
	MONST_IS_FALLING				= Fl(17),	// monster is plunging downward at the end of the turn
	MONST_IS_DYING					= Fl(18),	// monster has already been killed and is awaiting the end-of-turn graveyard sweep.
	MONST_GIVEN_UP_ON_SCENT			= Fl(19),	// to help the monster remember that the scent map is a dead end
	MONST_IS_DORMANT				= Fl(20),	// lurking, waiting to burst out
    MONST_ALLY_ANNOUNCED_HUNGER     = Fl(21),   // player has gotten the message that the ally is ready to absorb a new power
	MONST_ASSASSINATION_TARGET		= Fl(22),	// monster is the assassination target for this level; lost if the amulet is removed
	MONST_ASSASSINATION_ALERT		= Fl(23),	// assassination target will become alarmed if injured by the player or allies, then loses this flag
	MONST_ASSASSINATION_ALARM		= Fl(24),	// monster will aggravate if not affected by negative status effects, then loses this flag
	MONST_ATTACK_SHALLOWS			= Fl(25),	// eels, kraken will attack in shallow as well as deep water
	MONST_NO_EXPERIENCE				= Fl(26),	// monster does not count towards weapon id learning if killed
	MONST_BOLT_CHAINED				= Fl(27),	// monster has been hit by a bolt in the chain
};

// Defines all creatures, which include monsters and the player:
typedef struct creatureType {
	enum monsterTypes monsterID; // index number for the monsterCatalog
	char monsterName[COLS];
	uchar displayChar;
	const color *foreColor;
	short maxHP;
	short defense;
	short accuracy;
	randomRange damage;
	long turnsBetweenRegen;		// turns to wait before regaining 1 HP
	short sightRadius;
	short scentThreshold;
	short movementSpeed;
	short attackSpeed;
	enum dungeonFeatureTypes bloodType;
	enum lightType intrinsicLightType;
	short DFChance;						// percent chance to spawn the dungeon feature per awake turn
	enum dungeonFeatureTypes DFType;	// kind of dungeon feature
	unsigned long flags;
	unsigned long abilityFlags;
	enum monsterTypes slayID;
} creatureType;

typedef struct monsterWords {
	char flavorText[COLS*5];
	char absorbing[40];
	char absorbStatus[40];
	char attack[5][30];
	char DFMessage[DCOLS];
	char summonMessage[DCOLS];
} monsterWords;

//#define PLAYER_BASE_MOVEMENT_SPEED		100
//#define PLAYER_BASE_ATTACK_SPEED		100

enum creatureStates {
	MONSTER_SLEEPING,
	MONSTER_TRACKING_SCENT,
	MONSTER_WANDERING,
	MONSTER_FLEEING,
	MONSTER_ALLY,
};

enum creatureModes {
	MODE_NORMAL,
	MODE_PERM_FLEEING
};

typedef struct hordeType {
	enum monsterTypes leaderType;

	// membership information
	short numberOfMemberTypes;
	enum monsterTypes memberType[5];
	randomRange memberCount[5];

	// spawning information
	short minLevel;
	short maxLevel;
	short frequency;
	enum tileType spawnsIn;
	short machine;

	enum hordeFlags flags;
} hordeType;

typedef struct creature {
	creatureType info;
	short xLoc;
	short yLoc;
	short depth;
	short currentHP;
	long turnsUntilRegen;
	short regenPerTurn;					// number of HP to regenerate every single turn
	short weaknessAmount;				// number of points of weakness that are inflicted by the weakness status
	short strengthAmount;				// number of points of strength that are added by the stronger status
	short protectionAmount;				// number of HP that protection protects against
	enum creatureStates creatureState;	// current behavioral state
	enum creatureModes creatureMode;	// current behavioral mode (higher-level than state)
	short destination[2][2];			// the waypoints the monster is walking towards
	short comingFrom[2];				// the location the monster is walking from when wandering to avoid going back and forth
	short targetCorpseLoc[2];			// location of the corpse that the monster is approaching to gain its abilities
	char targetCorpseName[30];			// name of the deceased monster that we're approaching to gain its abilities
	unsigned long absorptionFlags;		// ability/behavior flags that the monster will gain when absorption is complete
	boolean absorbBehavior;				// above flag is behavior instead of ability
	short corpseAbsorptionCounter;		// used to measure both the time until the monster stops being interested in the corpse,
										// and, later, the time until the monster finishes absorbing the corpse.
	short **mapToMe;					// if a pack leader, this is a periodically updated pathing map to get to the leader
	short **safetyMap;					// fleeing monsters store their own safety map when out of player FOV to avoid omniscience
	short ticksUntilTurn;				// how long before the creature gets its next move

	// Locally cached statistics that may be temporarily modified:
	short movementSpeed;
	short attackSpeed;

	short turnsSpentStationary;			// how many (subjective) turns it's been since the creature moved between tiles
	short flashStrength;				// monster will flash soon; this indicates the percent strength of flash
	color flashColor;					// the color that the monster will flash
	short status[NUMBER_OF_STATUS_EFFECTS];
	short maxStatus[NUMBER_OF_STATUS_EFFECTS]; // used to set the max point on the status bars
	unsigned long bookkeepingFlags;
	unsigned long aggravatedBehaviors;	// temporarily suppressed behaviors
	unsigned long aggravatedAbilities;	// temporarily suppressed abilities
	unsigned long negatedBehaviors;		// temporarily suppressed behaviors
	unsigned long negatedAbilities;		// temporarily suppressed abilities
	short polymorphedFrom;				// if polymorphed from another monster
	short spawnDepth;					// because monster doesn't earn xpxp on shallower levels than it spawned, and for activation monsters
    short machineHome;                  // monsters that spawn in a machine keep track of the machine number here
	short xpxp;							// exploration experience
	short absorbXPXP;                   // absorption experience (accrued like xpxp, but spent on absorbing new powers)
	struct creature *leader;			// only if monster is a follower
	struct creature *carriedMonster;	// when vampires turn into bats, one of the bats restores the vampire when it dies
	struct creature *nextCreature;
	struct item *carriedItem;			// only used for monsters
} creature;

enum NGCommands {
	NG_NOTHING = 0,
	NG_NEW_GAME,
	NG_NEW_GAME_WITH_SEED,
	NG_OPEN_GAME,
	NG_VIEW_RECORDING,
	NG_HIGH_SCORES,
	NG_QUIT,
};

// these are basically global variables pertaining to the game state and player's unique variables:
typedef struct playerCharacter {
	short depthLevel;					// which dungeon level are we on
    short deepestLevel;
	boolean disturbed;					// player should stop auto-acting
	boolean gameHasEnded;				// stop everything and go to death screen
	boolean highScoreSaved;				// so that it saves the high score only once
	boolean blockCombatText;			// busy auto-fighting
	boolean autoPlayingLevel;			// seriously, don't interrupt
	boolean automationActive;			// cut some corners during redraws to speed things up
	boolean justRested;					// previous turn was a rest -- used in stealth
	boolean cautiousMode;				// used to prevent careless deaths caused by holding down a key
	boolean receivedLevitationWarning;	// only warn you once when you're hovering dangerously over liquid
	boolean updatedSafetyMapThisTurn;	// so it's updated no more than once per turn
	boolean updatedAllySafetyMapThisTurn;	// so it's updated no more than once per turn
	boolean updatedMapToSafeTerrainThisTurn;// so it's updated no more than once per turn
	boolean updatedMapToShoreThisTurn;		// so it's updated no more than once per turn
	boolean easyMode;					// enables easy mode
	boolean inWater;					// helps with the blue water filter effect
	boolean heardCombatThisTurn;		// so you get only one "you hear combat in the distance" per turn
	boolean creaturesWillFlashThisTurn;	// there are creatures out there that need to flash before the turn ends
	boolean staleLoopMap;				// recalculate the loop map at the end of the turn
	boolean alreadyFell;				// so the player can fall only one depth per turn
	boolean eligibleToUseStairs;		// so the player uses stairs only when he steps onto them
	boolean trueColorMode;				// when activated via tab, monsters and items will display their original colors.
	boolean hideSeed;                   // whether seed is hidden when pressing SEED_KEY
	boolean quit;						// to skip the typical end-game theatrics when the player quits
	unsigned long seed;					// the master seed for generating the entire dungeon
	short RNG;							// which RNG are we currently using?
	unsigned long gold;					// how much gold we have
	unsigned long goldGenerated;		// how much gold has been generated on the levels, not counting gold held by monsters
	short strength;
	unsigned short monsterSpawnFuse;	// how much longer till a random monster spawns

	item *weapon;
	item *offhandWeapon;
	item *armor;
	item *shield;
	item *ringLeft;
	item *ringRight;
	item *ringThird;					// ring on the gripping hand
	item *talisman;

	short impaleDirection;				// spear or pike pointing in this direction
	color weaponBloodstainColor;		// last creature to die on this weapon
	lightSource minersLight;
	float minersLightRadius;
	short markedMonsters;				// how many marked monster on the level
	short ticksTillUpdateEnvironment;	// so that some periodic things happen in objective time
	unsigned short scentTurnNumber;		// helps make scent-casting work
	unsigned long turnNumber;
	signed long milliseconds;			// milliseconds since launch, to decide whether to engage cautious mode
	short xpxpThisTurn;					// how many squares the player explored this turn
	short previousHealthPercent;		// remembers what your health proportion was at the start of the turn,
										// to display percentage alerts

	short upLoc[2];						// upstairs location this level
	short downLoc[2];					// downstairs location this level

	short cursorLoc[2];					// used for the return key functionality
	creature *lastTarget;				// to keep track of the last monster the player has thrown at or zapped
	short rewardRoomsGenerated;			// to meter the number of reward rooms
	short machineNumber;				// so each machine on a level gets a unique number
	short sidebarLocationList[ROWS*2][2];	// to keep track of which location each line of the sidebar references

	// maps
	short **mapToShore;					// how many steps to get back to shore
	short **mapToSafeTerrain;			// so monsters can get to safety

	// recording info
	boolean playbackMode;				// whether we're viewing a recording instead of playing
	unsigned long currentTurnNumber;	// how many turns have elapsed
	unsigned long howManyTurns;			// how many turns are in this recording
	short howManyDepthChanges;			// how many times the player changes depths
	short playbackDelayPerTurn;			// base playback speed; modified per turn by events
	short playbackDelayThisTurn;		// playback speed as modified
	boolean playbackPaused;
	boolean playbackFastForward;		// for loading saved games and such -- disables drawing and prevents pauses
	boolean playbackOOS;				// playback out of sync -- no unpausing allowed
	boolean playbackOmniscience;		// whether to reveal all the map during playback
	boolean playbackBetweenTurns;		// i.e. waiting for a top-level input -- iff, permit playback commands
	unsigned long nextAnnotationTurn;	// the turn number during which to display the next annotation
	char nextAnnotation[5000];			// the next annotation
	unsigned long locationInAnnotationFile; // how far we've read in the annotations file

	// metered items
	long foodSpawned;					// amount of nutrition units spawned so far this game
	short lifePotionFrequency;
    short lifePotionsSpawned;
	short strengthPotionFrequency;
	short enchantScrollFrequency;

	// ring bonuses:
	short clairvoyance;
	short stealthBonus;
	short regenerationBonus;
	short lightMultiplier;
	short aggravating;
	short awarenessBonus;
	short transference;
	short wisdomBonus;
	short mightBonus;
	short telepathyBonus;

	// talisman tracking;
	short talismanFraction;
	boolean offhandWeaponNext;			// next blow is with the offhand weapon
	short assassinations;				// how many assassinations have been completed
	short assassinRewards;				// how many rewards have been paid out for assassinations
	short dungeoneeringDebt;
	short witchcraftChance;
	short charming;						// for restricting charm of charming to enchanting charms with less enchantments

	// cursor trail:
	short cursorPathIntensity;

	// What do you want to do, player -- play, play with seed, resume, recording, high scores or quit?
	enum NGCommands nextGame;
	char nextGamePath[BROGUE_FILENAME_MAX];
	unsigned long nextGameSeed;
} playerCharacter;

// Probably need to ditch this crap:
typedef struct levelProfile {
	short caveLevelChance;
	short crossRoomChance;
	short corridorChance;
	short doorChance;
	short maxNumberOfRooms;
	short maxNumberOfLoops;
} levelProfile;

// Stores the necessary info about a level so it can be regenerated:
typedef struct levelData {
	boolean visited;
	short numberOfRooms;
	room *roomStorage;
	pcell mapStorage[DCOLS][DROWS];
	struct item *items;
	struct creature *monsters;
	struct creature *dormantMonsters;
	unsigned long levelSeed;
	short upStairsLoc[2];
	short downStairsLoc[2];
	short playerExitedVia[2];
	unsigned long awaySince;
} levelData;

enum machineFeatureFlags {
	MF_GENERATE_ITEM				= Fl(0),	// feature entails generating an item (overridden if the machine is adopting an item)
	MF_OUTSOURCE_ITEM_TO_MACHINE	= Fl(1),	// item must be adopted by another machine
	MF_BUILD_VESTIBULE              = Fl(2),	// call this at the origin of a door room to create a new door guard machine there
	MF_ADOPT_ITEM					= Fl(3),	// this feature will take the adopted item (be it from another machine or a previous feature)
	MF_NO_THROWING_WEAPONS			= Fl(4),	// the generated item cannot be a throwing weapon
	MF_GENERATE_HORDE				= Fl(5),	// generate a monster horde that has all of the horde flags
	MF_BUILD_AT_ORIGIN				= Fl(6),	// generate this feature at the room entrance
	MF_WIRE_TO_MACHINE				= Fl(7),	// wire it up to the machine
	MF_PERMIT_BLOCKING				= Fl(8),	// permit the feature to block the map's passability (e.g. to add a locked door)
	MF_TREAT_AS_BLOCKING			= Fl(9),	// treat this terrain as though it blocks, for purposes of deciding whether it can be placed there
	MF_NEAR_ORIGIN					= Fl(10),	// feature must spawn in the rough quarter of tiles closest to the door
	MF_FAR_FROM_ORIGIN				= Fl(11),	// feature must spawn in the rough quarter of tiles farthest from the door
	MF_MONSTER_TAKE_ITEM			= Fl(12),	// the item associated with this feature (including if adopted) will be in possession of the horde leader that's generated
	MF_MONSTER_SLEEPING				= Fl(13),	// the monsters should be asleep when generated
    MF_MONSTER_FLEEING              = Fl(14),   // the monsters should be permanently fleeing when generated
	MF_MONSTER_LIFESPAN				= Fl(15),	// the monsters should have a limited lifespan (equal to their hp) when generated
	MF_EVERYWHERE					= Fl(16),	// generate the feature on every tile of the machine (e.g. carpeting)
	MF_ALTERNATIVE					= Fl(17),	// build only one feature that has this flag per machine; the rest are skipped. skip if alternative item has 0 frequency and not generate any item
	MF_ALTERNATIVE_2				= Fl(18),	// same as MF_ALTERNATIVE, but provides for a second set of alternatives of which only one will be chosen
	MF_REQUIRE_GOOD_RUNIC			= Fl(19),	// generated item must be uncursed runic
	MF_MONSTERS_DORMANT				= Fl(20),	// monsters are dormant, and appear when a dungeon feature with DFF_ACTIVATE_DORMANT_MONSTER spawns on their tile
	MF_GENERATE_MONSTER				= Fl(21),	// generate a single monster
	MF_BUILD_IN_WALLS				= Fl(22),	// build in an impassable tile that is adjacent to the interior
	MF_BUILD_ANYWHERE_ON_LEVEL		= Fl(23),	// build anywhere on the level, whether or not inside the machine
	MF_REPEAT_UNTIL_NO_PROGRESS		= Fl(24),	// keep trying to build this feature set until no changes are made
	MF_IMPREGNABLE					= Fl(25),	// this feature's location will be immune to tunneling
	MF_IN_VIEW_OF_ORIGIN			= Fl(26),	// this feature must be in view of the origin. Important: Use target (below) instead if placing multiple features and they block view.
	MF_IN_PASSABLE_VIEW_OF_ORIGIN	= Fl(27),	// this feature must be in view of the origin, where "view" is blocked by pathing blockers
	MF_NOT_IN_HALLWAY				= Fl(28),	// the feature location must have a passableArcCount of <= 1
	MF_NOT_ON_LEVEL_PERIMETER		= Fl(29),	// don't build it in the outermost walls of the level
	MF_SKELETON_KEY					= Fl(30),	// if a key is generated or adopted by this feature, it will open all locks in this machine.
	MF_KEY_DISPOSABLE				= Fl(31),	// if a key is generated or adopted, it will self-destruct after being used at this current location.
};

enum machineFeatureFlags2 {
	MF2_SET_AS_TARGET				= Fl(0),	// set this grid as the target for view/path calculations. Target defaults to origin if this is not set.
	MF2_IN_VIEW_OF_TARGET			= Fl(1),	// this feature must be in view of the target
	MF2_IN_PASSABLE_VIEW_OF_TARGET	= Fl(2),	// this feature must be in view of the target, where "view" is blocked by pathing blockers
	MF2_MUST_VIEW_ADJACENT_GRIDS	= Fl(3),	// the target uses the least permissive fov of any adjacent grid
	MF2_CAN_VIEW_ADJACENT_GRIDS		= Fl(4),	// the target uses the most permissive fov of any adjacent grid
	MF2_BLINK_FROM_TARGET			= Fl(5),	// build at least 4 grids from the target
	MF2_BLINK_TO_TARGET				= Fl(6),	// build no more than 8 grids from the target
	MF2_BRIDGE_TO_TARGET			= Fl(6),	// build no more than 5 grids from the target
	MF2_ADJACENT_TO_TARGET			= Fl(7),	// build 1 grid from the target, ignoring occupation restrictions
	MF2_ADJACENT_TO_ORIGIN			= Fl(8),	// build 1 grid from the origin, ignoring occupation restrictions
	MF2_CLOSER_TO_ORIGIN_THAN_TARGET = Fl(9),	// this feature must be closer to the origin than the target
	MF2_CREATE_HALO					= Fl(10),	// 1 grid radius around outside of required space will be cleared of occupation before remove halo feature placed
	MF2_REMOVE_HALO					= Fl(11),
	MF2_REQUIRE_ORIGIN_CANDIDATE	= Fl(12),	// fail unless the origin was a candidate for placement
	MF2_ADJACENT_TO_EXITS			= Fl(13),	// build 1 grid from any exit excluding the origin
	MF2_NEAR_EXITS					= Fl(14),	// build 2 grids from any exit excluding the origin
	MF2_MONSTER_DISCORDANT			= Fl(15),	// monster is set to permanently discordant
	MF2_NEAR_TO_TARGET				= Fl(16),	// build no more than 3 grids from the target
	MF2_REQUIRE_NOT_NEGATIVE		= Fl(17),	// requires that the item does not have a negative enchantment
	MF2_REQUIRE_ADJACENT_PASSABLE	= Fl(18),	// requires that adjacent grids must be passable
	MF2_ONLY_ONE_FEATURE			= Fl(19),	// generate only one feature but multiple items to e.g. place multiple keys around the level linked to the feature
	MF2_GENERATE_IN_ONE_ZONE		= Fl(20),	// generate anywhere on level outside machine or on border of machine
	MF2_GENERATE_IN_REMAINING_ZONES	= Fl(21),	// generate one in each additional disconnected area in the level outside the machine or on border of machine
	MF2_FORCE_GOOD_RUNIC			= Fl(22),	// generated item gets an uncursed runic even if it would not normally do so
	MF2_GENERATE_ANY_ITEM			= Fl(23),	// generate an item: item generated ignores usual rarity rules. required for potions of strength, life, scrolls of enchantment
	MF2_TERRITORIAL					= Fl(24),	// monster is territorial and does not left machine unless hunting
	MF2_MONSTER_SLEEPY				= Fl(25),	// monster 50% likely to be asleep, otherwise can fall asleep instead of wandering

	MF2_TARGET_CANDIDATES		= (MF2_BRIDGE_TO_TARGET | MF2_BLINK_FROM_TARGET | MF2_BLINK_TO_TARGET | MF2_ADJACENT_TO_TARGET),
												// calls candidate finding routine with target instead of origin. TODO: Change this so both are supported in one machine.
	MF2_DYNAMIC_CANDIDATES		= (MF2_IN_VIEW_OF_TARGET | MF2_IN_PASSABLE_VIEW_OF_TARGET |	MF2_BLINK_FROM_TARGET | MF2_ADJACENT_TO_TARGET
								   | MF2_CLOSER_TO_ORIGIN_THAN_TARGET /*| MF2_GENERATE_IN_REMAINING_ZONES*/),
												// recalculate candidates every time a feature is placed, instead of for every feature line
};

typedef struct machineFeature {
	// terrain
	enum dungeonFeatureTypes featureDF;	// generate this DF at the feature location (0 for none)
	enum tileType terrain;				// generate this terrain tile at the feature location (0 for none)
	enum dungeonLayers layer;			// generate the terrain tile in this layer

	short instanceCountRange[2];		// generate this range of instances of this feature
	short minimumInstanceCount;			// abort if fewer than this

	// items: these will be ignored if the feature is adopting an item
	unsigned long itemCategory;			// generate this category of item (or -1 for random)
	short itemKind;						// generate this kind of item (or -1 for random)
	short itemValueMinimum;				// generate an item worth at least this much

	short monsterID;					// generate a monster of this kind if MF_GENERATE_MONSTER is set

	short personalSpace;				// subsequent features must be generated more than this many tiles away from this feature
	unsigned long hordeFlags;			// choose a monster horde based on this
	unsigned long itemFlags;			// assign these flags to the item
	unsigned long flags;				// feature flags
	unsigned long flags2;				// feature flags2
} machineFeature;

enum blueprintFlags {
	BP_ADOPT_ITEM_KEY				= Fl(0),	// room requires on ITEM_IS_KEY item being outsourced
	BP_ADOPT_ITEM_NONKEY			= Fl(1),	// room requires non-ITEM_IS_KEY item to be outsourced
    BP_VESTIBULE                    = Fl(2),    // spawns in a doorway (location must be given) and expands outward, to guard the room
	BP_PURGE_PATHING_BLOCKERS		= Fl(3),	// clean out traps and other T_PATHING_BLOCKERs
	BP_PURGE_INTERIOR				= Fl(4),	// clean out all of the terrain in the interior before generating the machine
	BP_PURGE_LIQUIDS				= Fl(5),	// clean out all of the liquids in the interior before generating the machine
	BP_SURROUND_WITH_WALLS			= Fl(6),	// fill in any impassable gaps in the perimeter (e.g. water, lava, brimstone, traps) with wall
	BP_IMPREGNABLE					= Fl(7),	// impassable perimeter and interior tiles are locked; tunneling bolts will bounce off harmlessly
	BP_REWARD						= Fl(8),	// metered reward machines
	BP_OPEN_INTERIOR				= Fl(9),	// clear out walls in the interior, widen the interior until convex or bumps into surrounding areas
    BP_MAXIMIZE_INTERIOR            = Fl(10),    // same as BP_OPEN_INTERIOR but expands the room as far as it can go, potentially surrounding the whole level.
	BP_ROOM							= Fl(11),	// spawns in a dead-end room that is dominated by a chokepoint of the given size (as opposed to a random place of the given size)
	BP_TREAT_AS_BLOCKING			= Fl(12),	// abort the machine if, were it filled with wall tiles, it would disrupt the level connectivity
	BP_REQUIRE_BLOCKING				= Fl(13),	// abort the machine unless, were it filled with wall tiles, it would disrupt the level connectivity
	BP_NO_INTERIOR_FLAG				= Fl(14),	// don't flag the area as being part of a machine
	BP_REQUIRE_CHALLENGE_ADOPT		= Fl(15),	// require that outsourced items must be adopted by 'challenge' blueprints; act as 'challenge' blueprint for adoption
	BP_REQUIRE_CHALLENGE_PARENT		= Fl(16),	// require that adopted item come from 'challenge' blueprint; act as 'challenge' blueprint for outsourced items

	BP_ADOPT_ITEM					= (BP_ADOPT_ITEM_KEY | BP_ADOPT_ITEM_NONKEY),	// first feature MUST adopt an item
};

typedef struct blueprint {
	short depthRange[2];				// machine must be built between these dungeon depths
	short roomSize[2];					// machine must be generated in a room of this size
	short frequency;					// frequency (number of tickets this blueprint enters in the blueprint selection raffle)
	short featureCount;					// how many different types of features follow (max of 20)
	unsigned long flags;				// blueprint flags
	machineFeature feature[20];			// the features themselves
} blueprint;

enum machineTypes {
	// Reward rooms:
	MT_REWARD_MULTI_LIBRARY = 1,
	MT_REWARD_MONO_LIBRARY,
	MT_REWARD_APOTHECARY,
	MT_REWARD_ARCHIVE,
	MT_REWARD_PEDESTALS_PERMANENT,
	MT_REWARD_PEDESTALS_CONSUMABLE,
    MT_REWARD_ADOPTED_ITEM,
	MT_REWARD_DUNGEON,
	MT_REWARD_KENNEL,
	MT_REWARD_VAMPIRE_LAIR,
	MT_REWARD_ASTRAL_PORTAL,
	MT_REWARD_LABORATORY,
	MT_REWARD_CHARM_WORKSHOP,
	MT_REWARD_STAFF_WORKSHOP,
	MT_REWARD_WAND_WORKSHOP,
	MT_REWARD_CHALLENGE_RUNE_PRESS_WEAPON,
	MT_REWARD_CHALLENGE_RUNE_PRESS_ARMOR,
	MT_REWARD_CHALLENGE_LIBRARY,
	MT_REWARD_CHALLENGE_PEDESTALS,
	MT_REWARD_CHALLENGE_PEDESTALS2,
	MT_REWARD_CHALLENGE_ANY_STAFF_WORKSHOP,
	MT_REWARD_CHALLENGE_COMBAT_STAFF_WORKSHOP,
	MT_REWARD_CHALLENGE_ANY_WAND_WORKSHOP,

    // Door guard machines:
    MT_LOCKED_DOOR_VESTIBULE,
    MT_SECRET_DOOR_VESTIBULE,
    MT_SECRET_LEVER_VESTIBULE,
	MT_FLAMMABLE_BARRICADE_VESTIBULE,
	MT_STATUE_SHATTERING_VESTIBULE,
	MT_STATUE_MONSTER_VESTIBULE,
	MT_THROWING_TUTORIAL_VESTIBULE,
    MT_PIT_TRAPS_VESTIBULE,
	MT_DEEP_WATER_VESTIBULE,
    MT_BECKONING_OBSTACLE_VESTIBULE,
    MT_GUARDIAN_VESTIBULE,

	// Key guard machines:
	MT_KEY_REWARD_LIBRARY,
	MT_KEY_KITE_TUTORIAL_ROOM,
	MT_KEY_ALLY_TUTORIAL_ROOM,
	MT_KEY_SPARK_REFLECTION_ROOM,
	MT_KEY_FLOODING_TUTORIAL_ROOM,
	MT_KEY_BOMBS_TUTORIAL_ROOM,
	MT_KEY_PINBALL_CHALLENGE_ROOM,
	MT_KEY_GRAPPLING_CHALLENGE_ROOM,
	MT_KEY_CABLING_CHALLENGE_ROOM,
	MT_KEY_IONISED_CHALLENGE_ROOM,
	MT_KEY_CREEPING_LICHEN_ROOM,
	MT_KEY_SECRET_ROOM,
	MT_KEY_THROWING_TUTORIAL_AREA,
    MT_KEY_RAT_TRAP_ROOM,
	MT_KEY_FIRE_TRANSPORTATION_ROOM,
	MT_KEY_FLOOD_TRAP_ROOM,
    MT_KEY_FIRE_TRAP_ROOM,
    MT_KEY_THIEF_AREA,
	MT_KEY_COLLAPSING_FLOOR_AREA,
	MT_KEY_PIT_TRAP_ROOM,
	MT_KEY_LEVITATION_ROOM,
	MT_KEY_WEB_CLIMBING_ROOM,
	MT_KEY_LAVA_MOAT_ROOM,
	MT_KEY_LAVA_MOAT_AREA,
	MT_KEY_POISON_GAS_TRAP_ROOM,
	MT_KEY_EXPLOSIVE_TRAP_ROOM,
	MT_KEY_BURNING_TRAP_ROOM,
	MT_KEY_STATUARY_TRAP_AREA,
    MT_KEY_GUARDIAN_WATER_PUZZLE_ROOM,
    MT_KEY_GUARDIAN_GAUNTLET_ROOM,
	MT_KEY_GUARDIAN_CORRIDOR_ROOM,
    MT_KEY_SUMMONING_CIRCLE_ROOM,
    MT_KEY_BECKONING_OBSTACLE_ROOM,
	MT_KEY_WORM_TRAP_AREA,
	MT_KEY_MUD_TRAP_ROOM,
	MT_KEY_PHANTOM_TRAP_ROOM,
    MT_KEY_WORM_TUNNEL_ROOM,
	MT_KEY_TURRET_TRAP_ROOM,
	MT_KEY_BOSS_ROOM,
	MT_KEY_CHALLENGE_ARENA_ROOM,
	MT_KEY_CHALLENGE_STICKY_BUNDLE_AREA,
	MT_KEY_CHALLENGE_CRYSTAL_PRISM_AREA,
	MT_KEY_CHALLENGE_CAPACITOR_CHAMBER_ROOM,
	MT_KEY_CHALLENGE_IRON_GOLEM_ROOM,
	MT_KEY_CHALLENGE_LUMENSTONE,

	// Starter machines:
	MT_STARTER_STAFF_OR_MELEE,
	MT_STARTER_TALISMAN_LIBRARY,

	// Thematic machines:
	MT_CRYPT_AREA,
	MT_POTION_EXPERIMENT_AREA,
	MT_SCROLL_EXPERIMENT_AREA,
	MT_SACRIFICE_AREA,
	MT_CAPACITOR_AREA,
	MT_WITCH_HAZEL_AREA,
	MT_MANDRAKE_ROOT_AREA,
	MT_STINKFRUIT_AREA,
	MT_CRIMSON_CAP_AREA,
	MT_BLOODFLOWER_AREA,
	MT_IDYLL_AREA,
	MT_SWAMP_AREA,
	MT_CAMP_AREA,
	MT_REMNANT_AREA,
	MT_DISMAL_AREA,
	MT_BRIDGE_TURRET_AREA,
	MT_LAKE_PATH_TURRET_AREA,
    MT_PARALYSIS_TRAP_AREA,
	MT_TRICK_STATUE_AREA,
	MT_WORM_AREA,
	MT_SENTINEL_AREA,

	NUMBER_BLUEPRINTS,
};

typedef struct autoGenerator {
	// What spawns:
	enum tileType terrain;
	enum dungeonLayers layer;

	enum dungeonFeatureTypes DFType;

	enum machineTypes machine; // Machine placement also respects BP_ placement flags in the machine blueprint

	// Parameters governing when and where it spawns:
	enum tileType requiredDungeonFoundationType;
	enum tileType requiredLiquidFoundationType;
	short minDepth;
	short maxDepth;
	short frequency;
	short minNumberIntercept; // actually intercept * 100
	short minNumberSlope; // actually slope * 100
	short maxNumber;
} autoGenerator;

#define NUMBER_AUTOGENERATORS 48

#define NUMBER_LEVEL_PROFILES 1

#define PDS_FORBIDDEN   -1
#define PDS_OBSTRUCTION -2
#define PDS_CELL(map, x, y) ((map)->links + ((x) + DCOLS * (y)))

typedef struct pdsLink pdsLink;
typedef struct pdsMap pdsMap;

typedef struct brogueButton {
	char text[COLS];			// button label; can include color escapes
	short x;					// button's leftmost cell will be drawn at (x, y)
	short y;
	signed long hotkey[10];		// up to 10 hotkeys to trigger the button
	color buttonColor;			// background of the button; further gradient-ized when displayed
	short opacity;				// further reduced by 50% if not enabled
	uchar symbol[COLS];			// Automatically replace the nth asterisk in the button label text with
								// the nth character supplied here, if one is given.
								// (Primarily to display magic character and item symbols in the inventory display.)
	unsigned long flags;
} brogueButton;

enum buttonDrawStates {
	BUTTON_NORMAL = 0,
	BUTTON_HOVER,
	BUTTON_PRESSED,
};

enum BUTTON_FLAGS {
	B_DRAW					= Fl(0),
	B_ENABLED				= Fl(1),
	B_GRADIENT				= Fl(2),
	B_HOVER_ENABLED			= Fl(3),
	B_WIDE_CLICK_AREA		= Fl(4),
	B_KEYPRESS_HIGHLIGHT	= Fl(5),
};

typedef struct buttonState {
	// Indices of the buttons that are doing stuff:
	short buttonFocused;
	short buttonDepressed;

	// Index of the selected button:
	short buttonChosen;

	// The buttons themselves:
	short buttonCount;
	brogueButton buttons[50];

	// The window location, to determine whether a click is a cancelation:
	short winX;
	short winY;
	short winWidth;
	short winHeight;

	// Graphical buffers:
	cellDisplayBuffer dbuf[COLS][ROWS]; // Where buttons are drawn.
	cellDisplayBuffer rbuf[COLS][ROWS]; // Reversion screen state.
} buttonState;

#if defined __cplusplus
extern "C" {
#endif

	void rogueMain();
	void executeEvent(rogueEvent *theEvent);
	boolean fileExists(const char *pathname);
	boolean chooseFile(char *path, char *prompt, char *defaultName, char *suffix);
	boolean openFile(const char *path);
	boolean selectFile(char *prompt, char *defaultName, char *suffix);
	void initializeRogue(unsigned long seed);
	void gameOver(char *killedBy, boolean useCustomPhrasing);
	void victory();
	void notifyEvent(short eventId, int data1, int data2, const char *str1, const char *str2);
	void enableEasyMode();
	int rand_range(int lowerBound, int upperBound);
	unsigned long seedRandomGenerator(unsigned long seed);
	short randClumpedRange(short lowerBound, short upperBound, short clumpFactor);
	short randClump(randomRange theRange);
	boolean rand_percent(short percent);
	void shuffleList(short *list, short listLength);
	short unflag(unsigned long flag);
	void considerCautiousMode();
	void refreshScreen();
	void displayLevel();
	void storeColorComponents(char components[3], const color *theColor);
	boolean separateColors(color *fore, color *back);
	void bakeColor(color *theColor);
	void shuffleTerrainColors(short percentOfCells, boolean refreshCells);
	void getCellAppearance(short x, short y, uchar *returnChar, color *returnForeColor, color *returnBackColor);
	void logLevel();
	void logBuffer(char array[DCOLS][DROWS]);
	//void logBuffer(short **array);
	boolean search(short searchStrength);
	void routeTo(short x, short y, char *failureMessage);
	boolean useStairs(short stairDirection);
	short passableArcCount(short x, short y);
        boolean againstAWall(short x, short y);

	void analyzeMap(boolean calculateChokeMap);
	boolean buildAMachine(enum machineTypes bp,
						  short originX, short originY,
						  unsigned long requiredMachineFlags,
						  item *adoptiveItem,
						  item *parentSpawnedItems[50],
						  creature *parentSpawnedMonsters[50]);
	void digDungeon();
	boolean buildABridge();
	void updateMapToShore();
	void generateCave();
	short levelIsDisconnectedWithBlockingMap(char blockingMap[DCOLS][DROWS], boolean countRegionSize);
	boolean checkLakePassability(short lakeX, short lakeY, char connectedMap[DCOLS][DROWS]);
	void liquidType(short *deep, short *shallow, short *shallowWidth);
	void fillLake(short x, short y, short liquid, short scanWidth, char wreathMap[DCOLS][DROWS], char unfilledLakeMap[DCOLS][DROWS]);
	void resetDFMessageEligibility();
	boolean fillSpawnMap(enum dungeonLayers layer,
						 enum tileType surfaceTileType,
						 char spawnMap[DCOLS][DROWS],
						 boolean blockedByOtherLayers,
						 boolean refresh,
						 boolean superpriority);
	boolean spawnDungeonFeature(short x, short y, dungeonFeature *feat, boolean refreshCell, boolean abortIfBlocking);
	void restoreMonster(creature *monst, short **mapToStairs, short **mapToPit);
	void restoreItem(item *theItem);
	void cellularAutomata(short minBlobWidth, short minBlobHeight,
						  short maxBlobWidth, short maxBlobHeight, short percentSeeded,
						  char birthParameters[9], char survivalParameters[9]);
	short markBlobCellAndIterate(short xLoc, short yLoc, short blobNumber);
	boolean checkRoom(short roomX, short roomY, short roomWidth, short roomHeight);
	room *attemptRoom(short doorCandidateX, short doorCandidateY, short direction,
					  boolean isCorridor, boolean isCross, short numAttempts);
	void setUpWaypoints();
	void zeroOutGrid(char grid[DCOLS][DROWS]);
	void copyGrid(char to[DCOLS][DROWS], char from[DCOLS][DROWS]);
	void createWreath(short shallowLiquid, short wreathWidth, char wreathMap[DCOLS][DROWS]);
	short oppositeDirection(short theDir);
	void connectRooms(room *fromRoom, room *toRoom, short x, short y, short direction);
	room *allocateRoom(short roomX, short roomY, short width, short height,
					   short roomX2, short roomY2, short width2, short height2);
	room *roomContainingCell(short x, short y);
	short distanceBetweenRooms(room *fromRoom, room *toRoom);

	void carveRectangle(short roomX, short roomY, short roomWidth, short roomHeight);
	void markRectangle(short roomX, short roomY, short roomWidth, short roomHeight);
	void addWallToList(short direction, short xLoc, short yLoc);
	void removeWallFromList(short direction, short xLoc, short yLoc);
	void plotChar(uchar inputChar,
				  short xLoc, short yLoc,
				  short backRed, short backGreen, short backBlue,
				  short foreRed, short foreGreen, short foreBlue);
	void pausingTimerStartsNow();
	boolean pauseForMilliseconds(short milliseconds);
	void nextKeyOrMouseEvent(rogueEvent *returnEvent, boolean textInput, boolean colorsDance);
	boolean controlKeyIsDown();
	boolean shiftKeyIsDown();
	short getHighScoresList(rogueHighScoresEntry returnList[HIGH_SCORES_COUNT]);
	boolean saveHighScore(rogueHighScoresEntry theEntry);
	void initializeBrogueSaveLocation();
	fileEntry *listFiles(short *fileCount, char **dynamicMemoryBuffer);
	void initializeLaunchArguments(enum NGCommands *command, char *path, unsigned long *seed);

	char nextKeyPress(boolean textInput);
	void refreshSideBar(short focusX, short focusY, boolean focusedEntityMustGoFirst);
	void printHelpScreen();
  void printInstructionsScreen();
	void printDiscoveriesScreen();
  void printGameInfoScreen();
	void printHighScores(boolean hiliteMostRecent);
	void showWaypoints();
	void displayMap(short **map);
	void printSeed();
	void printProgressBar(short x, short y, const char barLabel[COLS], long amtFilled, long amtMax, color *fillColor, boolean dim);
	short printMonsterInfo(creature *monst, short y, boolean dim, boolean highlight);
	short printItemInfo(item *theItem, short y, boolean dim, boolean highlight);
	void rectangularShading(short x, short y, short width, short height,
							const color *backColor, short opacity, cellDisplayBuffer dbuf[COLS][ROWS]);
	short printTextBox(char *textBuf, short x, short y, short width,
					   color *foreColor, color *backColor,
					   cellDisplayBuffer rbuf[COLS][ROWS],
					   brogueButton *buttons, short buttonCount);
	void printMonsterDetails(creature *monst, cellDisplayBuffer rbuf[COLS][ROWS]);
	void printFloorItemDetails(item *theItem, cellDisplayBuffer rbuf[COLS][ROWS]);
	unsigned long printCarriedItemDetails(item *theItem,
										  short x, short y, short width,
										  boolean includeButtons,
										  cellDisplayBuffer rbuf[COLS][ROWS]);
	void funkyFade(cellDisplayBuffer displayBuf[COLS][ROWS], color *colorStart, color *colorEnd, short stepCount, short x, short y, boolean invert);
	void displayCenteredAlert(char *message);
	void flashMessage(char *message, short x, short y, int time, color *fColor, color *bColor);
	void flashTemporaryAlert(char *message, int time);
	void waitForAcknowledgment();
	void waitForKeystrokeOrMouseClick();
	boolean confirm(char *prompt, boolean alsoDuringPlayback);
	void refreshDungeonCell(short x, short y);
	void applyColorMultiplier(color *baseColor, color *multiplierColor);
	void applyColorAverage(color *baseColor, const color *newColor, short averageWeight);
	void applyColorAugment(color *baseColor, const color *augmentingColor, short augmentWeight);
    void applyColorScalar(color *baseColor, short scalar);
	void desaturate(color *baseColor, short weight);
	void randomizeColor(color *baseColor, short randomizePercent);
    void irisFadeBetweenBuffers(cellDisplayBuffer fromBuf[COLS][ROWS],
                                cellDisplayBuffer toBuf[COLS][ROWS],
                                short x, short y,
                                short frameCount,
                                boolean outsideIn);
	void colorBlendCell(short x, short y, color *hiliteColor, short hiliteStrength);
	void hiliteCell(short x, short y, const color *hiliteColor, short hiliteStrength, boolean distinctColors);
	void colorMultiplierFromDungeonLight(short x, short y, color *editColor);
	void plotCharWithColor(uchar inputChar, short xLoc, short yLoc, color cellForeColor, color cellBackColor);
	void plotCharToBuffer(uchar inputChar, short x, short y, color *foreColor, color *backColor, cellDisplayBuffer dbuf[COLS][ROWS]);
	void commitDraws();
	void dumpLevelToScreen();
	void hiliteGrid(char hiliteGrid[DCOLS][DROWS], color *hiliteColor, short hiliteStrength);
	void blackOutScreen();
	void copyDisplayBuffer(cellDisplayBuffer toBuf[COLS][ROWS], cellDisplayBuffer fromBuf[COLS][ROWS]);
	void clearDisplayBuffer(cellDisplayBuffer dbuf[COLS][ROWS]);
	color colorFromComponents(char rgb[3]);
	void overlayDisplayBuffer(cellDisplayBuffer overBuf[COLS][ROWS], cellDisplayBuffer previousBuf[COLS][ROWS]);
	void flashForeground(short *x, short *y, color **flashColor, short *flashStrength, short count, short frames);
	void flash(color *theColor, short frames, short x, short y);
	void lightFlash(const color *theColor, unsigned long reqTerrainFlags, unsigned long reqTileFlags, short frames, short maxRadius, short x, short y);
	void printString(const char *theString, short x, short y, color *foreColor, color*backColor, cellDisplayBuffer dbuf[COLS][ROWS]);
	short wrapText(char *to, const char *sourceText, short width);
	short printStringWithWrapping(char *theString, short x, short y, short width, color *foreColor,
								  color*backColor, cellDisplayBuffer dbuf[COLS][ROWS]);
	boolean getInputTextString(char *inputText,
							   const char *prompt,
							   short maxLength,
							   const char *defaultEntry,
							   const char *promptSuffix,
							   short textEntryType,
							   boolean useDialogBox);
	void displayChokeMap();
	void displayLoops();
	boolean pauseBrogue(short milliseconds);
	void nextBrogueEvent(rogueEvent *returnEvent, boolean textInput, boolean colorsDance, boolean realInputEvenInPlayback);
	void executeMouseClick(rogueEvent *theEvent);
	void executeKeystroke(signed long keystroke, boolean controlKey, boolean shiftKey);
	void initializeLevel();
	void startLevel (short oldLevelNumber, short stairDirection);
	void updateMinersLightRadius();
	void freeCreature(creature *monst);
	void emptyGraveyard();
	void freeEverything();
	boolean randomMatchingLocation(short *x, short *y, short dungeonType, short liquidType, short terrainType);
	enum dungeonLayers highestPriorityLayer(short x, short y, boolean skipGas);
	short layerWithFlag(short x, short y, unsigned long flag);
	char *tileFlavor(short x, short y);
	char *tileText(short x, short y);
	void describedItemCategory(unsigned long theCategory, char *buf);
	void describeLocation(char buf[DCOLS], short x, short y);
	void printLocationDescription(short x, short y);
	void playerRuns(short direction);
	void exposeCreatureToFire(creature *monst);
	void updateFlavorText();
	void applyInstantTileEffectsToCreature(creature *monst);
	void vomit(creature *monst);
	void becomeAllyWith(creature *monst);
	void freeCaptive(creature *monst);
	boolean freeCaptivesEmbeddedAt(short x, short y);
	short makeHitList(creature *hitList[8], unsigned long attackFlags, short newX, short newY, short direction);
	boolean diagonalBlocked(short x1, short y1, short x2, short y2);
	boolean playerMoves(short direction);
	void calculateDistances(short **distanceMap,
							short destinationX, short destinationY,
							unsigned long blockingTerrainFlags,
							creature *traveler,
							boolean canPenetrateStatues,
							boolean canUseSecretDoors,
							boolean eightWays);
	short pathingDistance(short x1, short y1, short x2, short y2, unsigned long blockingTerrainFlags);
	short nextStep(short **distanceMap, short x, short y, creature *monst, boolean preferDiagonals);
	void travelRoute(short path[1000][2], short steps);
	void travel(short x, short y, boolean autoConfirm);
    void populateGenericCostMap(short **costMap);
	void populateCreatureCostMap(short **costMap, creature *monst);
	void getExploreMap(short **map, boolean headingToStairs);
	boolean explore(short frameDelay);
	void clearCursorPath();
	void mainInputLoop();
	boolean isDisturbed(short x, short y);
	void discover(short x, short y);
	short randValidDirectionFrom(creature *monst, short x, short y, boolean respectAvoidancePreferences);
	boolean exposeTileToFire(short x, short y, boolean alwaysIgnite);
	boolean cellCanHoldGas(short x, short y);
	void monstersFall();
	void updateEnvironment();
	void updateAllySafetyMap();
	void updateSafetyMap();
	void updateSafeTerrainMap();
	void extinguishFireOnCreature(creature *monst);
	void autoRest();
	void startFighting(enum directions dir, boolean tillDeath);
	void autoFight(boolean tillDeath);
	void addXPXPToAlly(short XPXP, creature *monst);
	void handleXPXP();
	void playerTurnEnded();
	void resetScentTurnNumber();
	void displayMonsterFlashes(boolean flashingEnabled);
	void displayMessageArchive();
	void temporaryMessage(char *msg1, boolean requireAcknowledgment);
	void messageWithColor(char *msg, color *theColor, boolean requireAcknowledgment);
	void flavorMessage(char *msg);
	void message(const char *msg, boolean requireAcknowledgment);
	void displayMoreSign();
	short encodeMessageColor(char *msg, short i, const color *theColor);
	short decodeMessageColor(const char *msg, short i, color *returnColor);
	color *messageColorFromVictim(creature *monst);
	void upperCase(char *theChar);
	void updateMessageDisplay();
	void deleteMessages();
	void confirmMessages();
	void stripShiftFromMovementKeystroke(signed long *keystroke);

	void updateFieldOfViewDisplay(boolean updateDancingTerrain, boolean refreshDisplay);
	void updateFieldOfView(short xLoc, short yLoc, short radius, boolean paintScent,
						   boolean passThroughCreatures, boolean setFieldOfView, short theColor[3], short fadeToPercent);
	void betweenOctant1andN(short *x, short *y, short x0, short y0, short n);

	void getFOVMask(char grid[DCOLS][DROWS], short xLoc, short yLoc, float maxRadius,
					unsigned long forbiddenTerrain,	unsigned long forbiddenFlags, boolean cautiousOnWalls);
	void scanOctantFOV(char grid[DCOLS][DROWS], short xLoc, short yLoc, short octant, float maxRadius,
					   short columnsRightFromOrigin, long startSlope, long endSlope, unsigned long forbiddenTerrain,
					   unsigned long forbiddenFlags, boolean cautiousOnWalls);

	creature *generateMonster(short monsterID, boolean itemPossible);
	short chooseMonster(short forLevel);
	creature *spawnHorde(short hordeID, short x, short y, unsigned long forbiddenFlags, unsigned long requiredFlags);
	void fadeInMonster(creature *monst);
	boolean removeMonsterFromChain(creature *monst, creature *theChain);
	boolean monstersAreTeammates(creature *monst1, creature *monst2);
	boolean monstersAreEnemies(creature *monst1, creature *monst2);
	void initializeGender(creature *monst);
	boolean stringsMatch(const char *str1, const char *str2);
	void resolvePronounEscapes(char *text, creature *monst);
	short pickHordeType(short depth, enum monsterTypes summonerType, unsigned long forbiddenFlags, unsigned long requiredFlags);
	creature *cloneMonster(creature *monst, boolean announce, boolean placeClone);
	short **allocDynamicGrid();
	void freeDynamicGrid(short **array);
	void copyDynamicGrid(short **to, short **from);
	void fillDynamicGrid(short **grid, short fillValue);
	unsigned long forbiddenFlagsForMonster(creatureType *monsterType);
	boolean monsterCanSubmergeNow(creature *monst);
	void populateMonsters();
	void updateMonsterState(creature *monst);
	void decrementMonsterStatus(creature *monst);
	boolean specifiedPathBetween(short x1, short y1, short x2, short y2,
								 unsigned long blockingTerrain, unsigned long blockingFlags);
	boolean openPathBetween(short x1, short y1, short x2, short y2);
	creature *monsterAtLoc(short x, short y);
	creature *dormantMonsterAtLoc(short x, short y);
	void perimeterCoords(short returnCoords[2], short n);
	boolean monsterBlinkToPreferenceMap(creature *monst, short **preferenceMap, boolean blinkUphill);
	void unAlly(creature *monst);
	void monstersTurn(creature *monst);
	void spawnPeriodicHorde();
	void clearStatus(creature *monst);
	void monsterShoots(creature *attacker, short targetLoc[2], uchar projChar, color *projColor);
	void shootWeb(creature *breather, short targetLoc[2], short kindOfWeb);
	void moralAttack(creature *attacker, creature *defender);
	short runicWeaponChance(item *theItem, boolean customEnchantLevel, float enchantLevel);
	boolean magicWeaponHit(creature *defender, item *theItem, boolean backstabbed, boolean thrown);
	void teleport(creature *monst);
	void chooseNewWanderDestination(creature *monst);
	boolean canPass(creature *mover, creature *blocker);
	boolean isPassableOrSecretDoor(short x, short y);
	boolean moveMonster(creature *monst, short dx, short dy);
	unsigned long burnedTerrainFlagsAtLoc(short x, short y);
    unsigned long discoveredTerrainFlagsAtLoc(short x, short y);
	boolean monsterAvoids(creature *monst, short x, short y);
	short distanceDiagonal(short x1, short y1, short x2, short y2);
	short distanceManhattan(short x1, short y1, short x2, short y2);
	short distanceSquared(short x1, short y1, short x2, short y2);
	short distanceFastApproximation(short x1, short y1, short x2, short y2);
	void wakeUp(creature *monst);
	boolean canSeeMonster(creature *monst);
	boolean canDirectlySeeMonster(creature *monst);
	void monsterName(char *buf, creature *monst, boolean includeArticle);
	float strengthModifier(item *theItem);
	float netEnchant(item *theItem);
	short hitProbability(creature *attacker, creature *defender);
	boolean attackHit(creature *attacker, creature *defender);
	void applyArmorRunicEffect(item *theItem, char returnString[DCOLS], creature *attacker, short *damage, boolean melee);
	boolean attack(creature *attacker, creature *defender, boolean lungeAttack, boolean impaled);
	void inflictLethalDamage(creature *defender);
	boolean inflictDamage(creature *defender, short damage, const color *flashColor);
	void killCreature(creature *decedent, boolean administrativeDeath);
	void addScentToCell(short x, short y, short distance);
	void populateItems(short upstairsX, short upstairsY);
	item *placeItem(item *theItem, short x, short y);
	void removeItemFrom(short x, short y);
	void pickUpItemAt(short x, short y);
	item *addItemToPack(item *theItem);
	short getLineCoordinates(short listOfCoordinates[][2], short originLoc[2], short targetLoc[2]);
	void getImpactLoc(short returnLoc[2], short originLoc[2], short targetLoc[2],
					  short maxDistance, boolean returnLastEmptySpace);
	void negate(creature *monst, short turns);
    short monsterAccuracyAdjusted(const creature *monst);
    float monsterDamageAdjustmentAmount(const creature *monst);
    short monsterDefenseAdjusted(const creature *monst);
	void weaken(creature *monst, short maxDuration);
	boolean polymorph(creature *monst, short monsterID, short turns);
	void slow(creature *monst, short turns);
	void haste(creature *monst, short turns, boolean notNegatable);
	void heal(creature *monst, short percent);
	boolean shieldBlocks(creature *monst, short range, short damage, boolean degrade);
	boolean projectileReflects(creature *attacker, creature *defender);
	short reflectBolt(short targetX, short targetY, short listOfCoordinates[][2], short kinkCell, boolean retracePath);
	void checkForMissingKeys(short x, short y);
	void spark(short originLoc[2], short sparks, short damage);
	boolean zap(short originLoc[2], short targetLoc[2], enum boltType bolt, short boltLevel, float power, unsigned long boltHasFlags);
	boolean zapEffect(short originLoc[2], creature *shootingMonst, boolean boltInView, short x, short y, enum boltType bolt, short boltLevel, float power, long damage, unsigned long boltHasFlags);
	boolean nextTargetAfter(short *returnX,
                            short *returnY,
                            short targetX,
                            short targetY,
                            boolean targetEnemies,
                            boolean targetAllies,
                            boolean targetItems,
                            boolean requireOpenPath);
	boolean moveCursor(boolean *targetConfirmed,
					   boolean *canceled,
					   boolean *tabKey,
					   short targetLoc[2],
					   rogueEvent *event,
					   buttonState *state,
					   boolean colorsDance,
					   boolean keysMoveCursor,
					   boolean targetCanLeaveMap);
    void identifyItemKind(item *theItem);
    void autoIdentify(item *theItem);
	short numberOfItemsInPack();
	char nextAvailableInventoryCharacter();
    void updateFloorItems();
	void itemName(item *theItem, char *root, boolean includeDetails, boolean includeArticle, color *baseColor);
	char displayInventory(unsigned long categoryMask,
						  unsigned long requiredFlags,
						  unsigned long forbiddenFlags,
						  boolean waitForAcknowledge,
						  boolean includeButtons);
	short numberOfMatchingPackItems(unsigned long categoryMask,
									unsigned long requiredFlags, unsigned long forbiddenFlags,
									boolean displayErrors);
	void clearInventory(char keystroke);
	item *generateItem(unsigned long theCategory, short theKind);
	short chooseKind(itemTable *theTable, short numKinds);
	boolean boltRunicAllowedOnItem(short boltRune, short itemKind, item *theItem, boolean wizard);
	item *makeItemInto(item *theItem, unsigned long itemCategory, short itemKind);
	void updateEncumbrance();
    short displayedArmorValue();
	void strengthCheck(item *theItem);
	void recalculateEquipmentBonuses();
	void equipItem(item *theItem, boolean force);
	void equip(item *theItem);
	item *keyInPackFor(short x, short y);
	item *keyOnTileAt(short x, short y);
	void aggravateMonsters(short turns, short confusingTurns, boolean throughWalls, boolean driveMad, boolean ignoreAllies);
	void unequip(item *theItem);
	void drop(item *theItem);
	void findAlternativeHomeFor(creature *monst, short *x, short *y, boolean chooseRandomly);
	boolean getQualifyingLocNear(short loc[2],
								 short x, short y,
								 boolean hallwaysAllowed,
								 char blockingMap[DCOLS][DROWS],
								 unsigned long forbiddenTerrainFlags,
								 unsigned long forbiddenMapFlags,
								 boolean forbidLiquid,
								 boolean deterministic);
	boolean getQualifyingGridLocNear(short loc[2],
									 short x, short y,
									 boolean grid[DCOLS][DROWS],
									 boolean deterministic);
	void demoteMonsterFromLeadership(creature *monst);
	void toggleMonsterDormancy(creature *monst);
	void monsterDetails(char buf[], creature *monst);
  void makeIdle(creature *monst);
  void generateFellowAdventurer();
	void makeMonsterDropItem(creature *monst);
	void throwCommand(item *theItem);
	void mergeItems(item *theFirstItem, item *theSecondItem);
	void apply(item *theItem, boolean recordCommands);
	boolean itemCanBeCalled(item *theItem);
	void call(item *theItem);
	enum monsterTypes chooseVorpalEnemy();
	void identify(item *theItem);
	void updateIdentifiableItem(item *theItem);
	void updateIdentifiableItems();
  void magicMapCell(short x, short y);
	void readScroll(item *theItem);
	void updateRingBonuses();
	void updatePlayerRegenerationDelay();
	boolean removeItemFromChain(item *theItem, item *theChain);
	void drinkPotion(item *theItem);
	item *promptForItemOfType(unsigned long category,
							  unsigned long requiredFlags,
							  unsigned long forbiddenFlags,
							  char *prompt,
							  boolean allowInventoryActions);
	item *itemOfPackLetter(char letter);
	void unequipItem(item *theItem, boolean force);
	short magicCharDiscoverySuffix(unsigned long category, short kind);
	uchar itemMagicChar(item *theItem);
	item *itemAtLoc(short x, short y);
	item *dropItem(item *theItem);
	itemTable *tableForItemCategory(enum itemCategory theCat);
	itemTable *inheritedTableForItemCategory(enum itemCategory theCat);
	boolean isVowel(char *theChar);
    short charmEffectDuration(short charmKind, short enchant);
    short charmRechargeDelay(short charmKind, short enchant);
	boolean itemIsCarried(item *theItem);
	void itemDetails(char *buf, item *theItem);
	void deleteItem(item *theItem);
	void shuffleFlavors();
	unsigned long itemValue(item *theItem);
    void causeFear(const char *emitterName, boolean throughWalls, boolean ignoreAllies);
    void debugWish(char *wishText);
	short strLenWithoutEscapes(const char *str);
	void combatMessage(char *theMsg, color *theColor);
	void displayCombatText();
	void flashMonster(creature *monst, const color *theColor, short strength);

	void paintLight(lightSource *theLight, short x, short y, boolean isMinersLight, boolean maintainShadows);
	void updateLighting();
	boolean playerInDarkness();
	void demoteVisibility();
	void updateVision(boolean refreshDisplay);
	void burnItem(item *theItem);
	void activateMonstersinMachine(short machineNumber, boolean called);
	void promoteTile(short x, short y, enum dungeonLayers layer, boolean useFireDF);
	void autoPlayLevel(boolean fastForward);
	void updateClairvoyance();
	void updateTelepathy();

	void initRecording();
	void flushBufferToFile();
	void fillBufferFromFile();
	void recordEvent(rogueEvent *event);
	void recallEvent(rogueEvent *event);
	void pausePlayback();
	void displayAnnotation();
	void loadSavedGame();
	void recordKeystroke(uchar keystroke, boolean controlKey, boolean shiftKey);
	void recordKeystrokeSequence(unsigned char *commandSequence);
	void recordMouseClick(short x, short y, boolean controlKey, boolean shiftKey);
	void OOSCheck(unsigned long x, short numberOfBytes);
	void RNGCheck();
	boolean executePlaybackInput(rogueEvent *recordingInput);
	void getAvailableFilePath(char *filePath, const char *defaultPath, const char *suffix);
	void saveGame();
	void saveRecording();
	void saveRecordingNoPrompt();
	void parseFile();
	void RNGLog(char *message);

	void checkForDungeonErrors();

	boolean dialogChooseFile(char *path, const char *suffix, const char *prompt);
	void dialogAlert(char *message);
	void mainBrogueJunction();

	void initializeButton(brogueButton *button);
	void drawButtonsInState(buttonState *state);
	void initializeButtonState(buttonState *state,
							   brogueButton *buttons,
							   short buttonCount,
							   short winX,
							   short winY,
							   short winWidth,
							   short winHeight);
	short processButtonInput(buttonState *state, boolean *canceled, rogueEvent *event);
	void drawButton(brogueButton *button, enum buttonDrawStates highlight, cellDisplayBuffer dbuf[COLS][ROWS]);
	short buttonInputLoop(brogueButton *buttons,
						  short buttonCount,
						  short winX,
						  short winY,
						  short winWidth,
						  short winHeight,
						  rogueEvent *returnEvent);

	void dijkstraScan(short **distanceMap, short **costMap, boolean useDiagonals);
	void pdsClear(pdsMap *map, short maxDistance, boolean eightWays);
	void pdsSetDistance(pdsMap *map, short x, short y, short distance);
	void pdsBatchOutput(pdsMap *map, short **distanceMap);

#if defined __cplusplus
}
#endif
