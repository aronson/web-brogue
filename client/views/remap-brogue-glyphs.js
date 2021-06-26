define([
    'jquery',
    'underscore',
    'backbone'
], function($, _, Backbone) {

    const TEXT_GRAPHICS = 0;
    const TILES_GRAPHICS = 1;
    const HYBRID_GRAPHICS = 2;

    const G_UP_ARROW = 128;
    const G_DOWN_ARROW = 129;
    const G_POTION = 130;
    const G_GRASS = 131;
    const G_WALL = 132;
    const G_DEMON = 133;
    const G_OPEN_DOOR = 134;
    const G_GOLD = 135;
    const G_CLOSED_DOOR = 136;
    const G_RUBBLE = 137;
    const G_KEY = 138;
    const G_BOG = 139;
    const G_CHAIN_TOP_LEFT = 140;
    const G_CHAIN_BOTTOM_RIGHT = 141;
    const G_CHAIN_TOP_RIGHT = 142;
    const G_CHAIN_BOTTOM_LEFT = 143;
    const G_CHAIN_TOP = 144;
    const G_CHAIN_BOTTOM = 145;
    const G_CHAIN_LEFT = 146;
    const G_CHAIN_RIGHT = 147;
    const G_FOOD = 148;
    const G_UP_STAIRS = 149;
    const G_VENT = 150;
    const G_DOWN_STAIRS = 151;
    const G_PLAYER = 152;
    const G_BOG_MONSTER = 153;
    const G_CENTAUR = 154;
    const G_DRAGON = 155;
    const G_FLAMEDANCER = 156;
    const G_GOLEM = 157;
    const G_TENTACLE_HORROR = 158;
    const G_IFRIT = 159;
    const G_JELLY = 160;
    const G_KRAKEN = 161;
    const G_LICH = 162;
    const G_NAGA = 163;
    const G_OGRE = 164;
    const G_PHANTOM = 165;
    const G_REVENANT = 166;
    const G_SALAMANDER = 167;
    const G_TROLL = 168;
    const G_UNDERWORM = 169;
    const G_VAMPIRE = 170;
    const G_WRAITH = 171;
    const G_ZOMBIE = 172;
    const G_ARMOR = 173;
    const G_STAFF = 174;
    const G_WEB = 175;
    const G_MOUND = 176;
    const G_BLOAT = 177;
    const G_CENTIPEDE = 178;
    const G_DAR_BLADEMASTER = 179;
    const G_EEL = 180;
    const G_FURY = 181;
    const G_GOBLIN = 182;
    const G_IMP = 183;
    const G_JACKAL = 184;
    const G_KOBOLD = 185;
    const G_MONKEY = 186;
    const G_PIXIE = 187;
    const G_RAT = 188;
    const G_SPIDER = 189;
    const G_TOAD = 190;
    const G_BAT = 191;
    const G_WISP = 192;
    const G_PHOENIX = 193;
    const G_ALTAR = 194;
    const G_LIQUID = 195;
    const G_FLOOR = 196;
    const G_CHASM = 197;
    const G_TRAP = 198;
    const G_FIRE = 199;
    const G_FOLIAGE = 200;
    const G_AMULET = 201;
    const G_SCROLL = 202;
    const G_RING = 203;
    const G_WEAPON = 204;
    const G_GEM = 205;
    const G_TOTEM = 206;
    const G_GOOD_MAGIC = 207;
    const G_BAD_MAGIC = 208;
    const G_DOORWAY = 209;
    const G_CHARM = 210;
    const G_WALL_TOP = 211;
    const G_DAR_PRIESTESS = 212;
    const G_DAR_BATTLEMAGE = 213;
    const G_GOBLIN_MAGIC = 214;
    const G_GOBLIN_CHIEFTAN = 215;
    const G_OGRE_MAGIC = 216;
    const G_GUARDIAN = 217;
    const G_WINGED_GUARDIAN = 218;
    const G_EGG = 219;
    const G_WARDEN = 220;
    const G_DEWAR = 221;
    const G_ANCIENT_SPIRIT = 222;
    const G_LEVER = 223;
    const G_LEVER_PULLED = 224;
    const G_BLOODWORT_STALK = 225;
    const G_FLOOR_ALT = 226;
    const G_UNICORN = 227;
    const G_TURRET = 228;
    const G_WAND = 229;
    const G_GRANITE = 230;
    const G_CARPET = 231;
    const G_CLOSED_IRON_DOOR = 232;
    const G_OPEN_IRON_DOOR = 233;
    const G_TORCH = 234;
    const G_CRYSTAL = 235;
    const G_PORTCULLIS = 236;
    const G_BARRICADE = 237;
    const G_STATUE = 238;
    const G_CRACKED_STATUE = 239;
    const G_CLOSED_CAGE = 240;
    const G_OPEN_CAGE = 241;
    const G_PEDESTAL = 242;
    const G_CLOSED_COFFIN = 243;
    const G_OPEN_COFFIN = 244;
    const G_MAGIC_GLYPH = 245;
    const G_BRIDGE = 246;
    const G_BONES = 247;
    const G_ELECTRIC_CRYSTAL = 248;
    const G_ASHES = 249;
    const G_BEDROLL = 250;
    const G_BLOODWORT_POD = 251;
    const G_VINE = 252;
    const G_NET = 253;
    const G_LICHEN = 254;
    const G_PIPES = 255;
    const G_SAC_ALTAR = 256;
    const G_ORB_ALTAR = 257;

    const U_CURRENCY = '\u00a4';
    const U_U_ACUTE = '\u00da';
    const U_ESZETT = '\u00df';
    const U_MIDDLE_DOT = '\u00b7';
    const U_FOUR_DOTS = '\u2237';
    const U_DIAMOND = '\u25c7';
    const U_FLIPPED_V = '\u22cf';
    const U_ARIES = '\u03c8';
    const U_ANKH = '\u2640';
    const U_MUSIC_NOTE = '\u266a';
    const U_CIRCLE = '\u25cb';
    const U_FILLED_CIRCLE = '\u25cf';
    const U_NEUTER = '\u26b2';
    const U_CIRCLE_BARS = '\u29f2';
    const U_FILLED_CIRCLE_BARS = '\u29f3';
    const U_UP_ARROW = '\u2191';
    const U_DOWN_ARROW = '\u2193';
    const U_LEFT_ARROW = '\u2190';
    const U_RIGHT_ARROW = '\u2192';
    const U_OMEGA = '\u03a9';
    const U_LIGHTNING_BOLT = '\u03df';

    var remapGlyphsToText = function(glyphCode, graphics) {

        //Map between brogue glyphs and unicode if we are in font-rendering
        //or use directly (mapping in display) in tile-rendering mode
        if (glyphCode < 128) return String.fromCharCode(glyphCode);

        switch (glyphCode) {
            case G_UP_ARROW: return U_UP_ARROW;
            case G_DOWN_ARROW: return U_DOWN_ARROW;
            case G_POTION: return '!';
            case G_GRASS: return '"';
            case G_WALL: return '#';
            case G_DEMON: return '&';
            case G_OPEN_DOOR: return '\'';
            case G_GOLD: return '*';
            case G_CLOSED_DOOR: return '+';
            case G_RUBBLE: return ',';
            case G_KEY: return '-';
            case G_BOG: return '~';
            case G_CHAIN_TOP_LEFT:
            case G_CHAIN_BOTTOM_RIGHT:
                return '\\';
            case G_CHAIN_TOP_RIGHT:
            case G_CHAIN_BOTTOM_LEFT:
                return '/';
            case G_CHAIN_TOP:
            case G_CHAIN_BOTTOM:
                return '|';
            case G_CHAIN_LEFT:
            case G_CHAIN_RIGHT:
                return '-';
            case G_FOOD: return ';';
            case G_UP_STAIRS: return '<';
            case G_VENT: return '=';
            case G_DOWN_STAIRS: return '>';
            case G_PLAYER: return '@';
            case G_BOG_MONSTER: return 'B';
            case G_CENTAUR: return 'C';
            case G_DRAGON: return 'D';
            case G_FLAMEDANCER: return 'F';
            case G_GOLEM: return 'G';
            case G_TENTACLE_HORROR: return 'H';
            case G_IFRIT: return 'I';
            case G_JELLY: return 'J';
            case G_KRAKEN: return 'K';
            case G_LICH: return 'L';
            case G_NAGA: return 'N';
            case G_OGRE: return 'O';
            case G_PHANTOM: return 'P';
            case G_REVENANT: return 'R';
            case G_SALAMANDER: return 'S';
            case G_TROLL: return 'T';
            case G_UNDERWORM: return 'U';
            case G_VAMPIRE: return 'V';
            case G_WRAITH: return 'W';
            case G_ZOMBIE: return 'Z';
            case G_ARMOR: return '[';
            case G_STAFF: return '/';
            case G_WEB: return ':';
            case G_MOUND: return 'a';
            case G_BLOAT: return 'b';
            case G_CENTIPEDE: return 'c';
            case G_DAR_BLADEMASTER: return 'd';
            case G_EEL: return 'e';
            case G_FURY: return 'f';
            case G_GOBLIN: return 'g';
            case G_IMP: return 'i';
            case G_JACKAL: return 'j';
            case G_KOBOLD: return 'k';
            case G_MONKEY: return 'm';
            case G_PIXIE: return 'p';
            case G_RAT: return 'r';
            case G_SPIDER: return 's';
            case G_TOAD: return 't';
            case G_BAT: return 'v';
            case G_WISP: return 'w';
            case G_PHOENIX: return 'P';
            case G_ALTAR: return '|';
            case G_LIQUID: return '~';
            case G_FLOOR: return U_MIDDLE_DOT;
            case G_CHASM: return U_FOUR_DOTS;
            case G_TRAP: return U_DIAMOND;
            case G_FIRE: return U_FLIPPED_V;
            case G_FOLIAGE: return U_ARIES;
            case G_AMULET: return U_ANKH;
            case G_SCROLL: return U_MUSIC_NOTE;
            case G_RING: return U_CIRCLE;
            case G_WEAPON: return U_UP_ARROW;
            case G_GEM: return U_FILLED_CIRCLE;
            case G_TOTEM: return U_NEUTER;
            case G_GOOD_MAGIC: return U_FILLED_CIRCLE_BARS;
            case G_BAD_MAGIC: return U_CIRCLE_BARS;
            case G_DOORWAY: return U_OMEGA;
            case G_CHARM: return U_LIGHTNING_BOLT;
            case G_WALL_TOP: return '#';
            case G_DAR_PRIESTESS: return 'd';
            case G_DAR_BATTLEMAGE: return 'd';
            case G_GOBLIN_MAGIC: return 'g';
            case G_GOBLIN_CHIEFTAN: return 'g';
            case G_OGRE_MAGIC: return 'O';
            case G_GUARDIAN: return U_ESZETT;
            case G_WINGED_GUARDIAN: return U_ESZETT;
            case G_EGG: return U_FILLED_CIRCLE;
            case G_WARDEN: return 'Y';
            case G_DEWAR: return '&';
            case G_ANCIENT_SPIRIT: return 'M';
            case G_LEVER: return '/';
            case G_LEVER_PULLED: return '\\';
            case G_BLOODWORT_STALK: return U_ARIES;
            case G_FLOOR_ALT: return U_MIDDLE_DOT;
            case G_UNICORN: return U_U_ACUTE;
            case G_TURRET: return U_FILLED_CIRCLE;
            case G_WAND: return '~';
            case G_GRANITE: return '#';
            case G_CARPET: return U_MIDDLE_DOT;
            case G_CLOSED_IRON_DOOR: return '+';
            case G_OPEN_IRON_DOOR: return '\'';
            case G_TORCH: return '#';
            case G_CRYSTAL: return '#';
            case G_PORTCULLIS: return '#';
            case G_BARRICADE: return '#';
            case G_STATUE: return U_ESZETT;
            case G_CRACKED_STATUE: return U_ESZETT;
            case G_CLOSED_CAGE: return '#';
            case G_OPEN_CAGE: return '|';
            case G_PEDESTAL: return '|';
            case G_CLOSED_COFFIN: return '-';
            case G_OPEN_COFFIN: return '-';
            case G_MAGIC_GLYPH: return U_FOUR_DOTS;
            case G_BRIDGE: return '=';
            case G_BONES: return ',';
            case G_ELECTRIC_CRYSTAL: return U_CURRENCY;
            case G_ASHES: return '\'';
            case G_BEDROLL: return '=';
            case G_BLOODWORT_POD: return '*';
            case G_VINE: return ':';
            case G_NET: return ':';
            case G_LICHEN: return '"';
            case G_PIPES: return '+';
            case G_SAC_ALTAR: return '|';
            case G_ORB_ALTAR: return '|';
        } 
        
        return String.fromCharCode(glyphCode);
    }
 
    var remapGlyphsToGraphics = function(glyphCode) {
        // Map Brogue glyphs to BrogueCE font
        if (glyphCode <= 127) return String.fromCharCode(glyphCode);
        if (glyphCode == 128) return U_UP_ARROW;
        if (glyphCode == 129) return U_DOWN_ARROW;
        if (glyphCode >= 130) return String.fromCharCode(glyphCode - 130 + 0x4000); // graphic tiles
    }

    var isEnvironmentGlyph = function(glyphCode) {
        switch (glyphCode) {
            // items
            case G_AMULET: case G_ARMOR: case G_BEDROLL: case G_CHARM:
            case G_DEWAR: case G_EGG: case G_FOOD: case G_GEM: case G_BLOODWORT_POD:
            case G_GOLD: case G_KEY: case G_POTION: case G_RING:
            case G_SCROLL: case G_STAFF: case G_WAND: case G_WEAPON:
                return false;
    
            // creatures
            case G_ANCIENT_SPIRIT: case G_BAT: case G_BLOAT: case G_BOG_MONSTER:
            case G_CENTAUR: case G_CENTIPEDE: case G_DAR_BATTLEMAGE: case G_DAR_BLADEMASTER:
            case G_DAR_PRIESTESS: case G_DEMON: case G_DRAGON: case G_EEL:
            case G_FLAMEDANCER: case G_FURY: case G_GOBLIN: case G_GOBLIN_CHIEFTAN:
            case G_GOBLIN_MAGIC: case G_GOLEM: case G_GUARDIAN: case G_IFRIT:
            case G_IMP: case G_JACKAL: case G_JELLY: case G_KOBOLD:
            case G_KRAKEN: case G_LICH: case G_MONKEY: case G_MOUND:
            case G_NAGA: case G_OGRE: case G_OGRE_MAGIC: case G_PHANTOM:
            case G_PHOENIX: case G_PIXIE: case G_PLAYER: case G_RAT:
            case G_REVENANT: case G_SALAMANDER: case G_SPIDER: case G_TENTACLE_HORROR:
            case G_TOAD: case G_TROLL: case G_UNDERWORM: case G_UNICORN:
            case G_VAMPIRE: case G_WARDEN: case G_WINGED_GUARDIAN: case G_WISP:
            case G_WRAITH: case G_ZOMBIE:
                return false;
    
            // everything else is considered part of the environment
            default:
                return true;
        }
    }

    var remapGlyphs = function(glyphCode, graphics) {
        if (graphics == HYBRID_GRAPHICS) {
            if (isEnvironmentGlyph(glyphCode)) {
                return remapGlyphsToGraphics(glyphCode);
            }
            return remapGlyphsToText(glyphCode);
        }
        else if (graphics == TILES_GRAPHICS) {
            return remapGlyphsToGraphics(glyphCode);
        }
        else {
            return remapGlyphsToText(glyphCode);
        }
    }

    return remapGlyphs;
});