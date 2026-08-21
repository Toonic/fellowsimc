// ==========================================================================
// Dedmonwakeen's Raid DPS/TPS Simulator.
// Send questions to natehieter@gmail.com
// ==========================================================================

#include "color.hpp"

#include "fmt/format.h"

namespace color
{

std::string rgb::rgb_str() const
{
  return fmt::format("rgba({}, {}, {}, {})", r_, g_, b_, a_ );
}

std::string rgb::str() const
{
  return fmt::to_string( *this );
}

std::string rgb::hex_str() const
{
  return fmt::format( "{:02X}{:02X}{:02X}", r_, g_, b_ );
}

rgb::operator std::string() const
{
  return str();
}

rgb class_color( player_e type )
{
  switch ( type )
  {
    case PLAYER_NONE:
    case PLAYER_GUARDIAN:
    case PLAYER_PET:
      return color::GREY;
    case MARA:
      return color::COLOR_MARA;
    case RIME:
      return color::COLOR_RIME;
    case ARDEOS:
      return color::COLOR_ARDEOS;
    case ELARION:
      return color::COLOR_ELARION;
    case GUNDE:
      return color::COLOR_GUNDE;
    case TARIQ:
      return color::COLOR_TARIQ;
    case AEONA:
      return color::COLOR_AEONA;
    case XAVIAN:
      return color::COLOR_XAVIAN;
    case MEIKO:
      return color::COLOR_MEIKO;
    case HELENA:
      return color::COLOR_HELENA;
    case SYLVIE:
      return color::COLOR_SYLVIE;
    case VIGOUR:
      return color::COLOR_VIGOUR;
    case PLAYER_SIMPLIFIED:
      return color::COLOR_PLAYER_SIMPLIFIED;
    case ENEMY:
    case ENEMY_ADD:
    case ENEMY_ADD_PRIO:
    case ENEMY_ADD_BOSS:
    case HEALING_ENEMY:
    case TANK_DUMMY:
      return color::GREY;
    default:
      return color::GREY2;
  }
}

rgb resource_color( resource_e type )
{
  switch ( type )
  {
    case RESOURCE_HEALTH:
      return color::GREEN;

    case RESOURCE_MANA:
      return color::BLUE;

    case RESOURCE_ENERGY:
    case RESOURCE_FOCUS:
    case RESOURCE_COMBO_POINT:
      return color::YELLOW;

    case RESOURCE_RAGE:
    case RESOURCE_RUNIC_POWER:
      return color::RED;

    case RESOURCE_HOLY_POWER:
      return color::HOLY;

    case RESOURCE_SOUL_SHARD:
      return color::PURPLE;

    case RESOURCE_ASTRAL_POWER:
      return color::rgb( "FF7D0A" );

    case RESOURCE_CHI:
      return color::rgb( "00FF96" );

    case RESOURCE_MAELSTROM:
      return { "FF9900" };

    case RESOURCE_RUNE:
      return color::ARCANE;

    case RESOURCE_ESSENCE:
      return color::rgb( "33937F" );

    case RESOURCE_NONE:
    default:
      return GREY2;
  }
}

rgb stat_color( stat_e type )
{
  switch ( type )
  {
    case STAT_STRENGTH:
      return color::PHYSICAL;
    case STAT_AGILITY:
      return color::NATURE;
    case STAT_INTELLECT:
      return color::ARCANE;
    case STAT_SPIRIT:
      return color::GREY3;
    case STAT_ATTACK_POWER:
      return color::YELLOW;
    case STAT_SPELL_POWER:
      return color::PURPLE;
    case STAT_CRIT_RATING:
      return color::rgb( "F58CBA" );
    case STAT_HASTE_RATING:
      return color::BLUE;
    case STAT_MASTERY_RATING:
      return color::YELLOW.dark();
    case STAT_DODGE_RATING:
      return color::rgb( "00FF96" );
    case STAT_PARRY_RATING:
      return color::TEAL;
    case STAT_ARMOR:
      return color::WHITE;
    case STAT_BONUS_ARMOR:
      return color::WHITE;
    case STAT_VERSATILITY_RATING:
      return color::PURPLE.dark();
    default:
      return color::GREY2;
  }
}

/* Blizzard shool colors:
 * http://wowprogramming.com/utils/xmlbrowser/live/AddOns/Blizzard_CombatLog/Blizzard_CombatLog.lua
 * search for: SchoolStringTable
 */
// These colors are picked to sort of line up with classes, but match the "feel"
// of the spell class' color
rgb school_color( school_e school )
{
  switch ( school )
  {
    // -- Single Schools
    case SCHOOL_NONE:
      return color::COLOR_NONE;
    case SCHOOL_PHYSICAL:
      return color::PHYSICAL;
    case SCHOOL_HOLY:
      return color::HOLY;
    case SCHOOL_FIRE:
      return color::FIRE;
    case SCHOOL_NATURE:
      return color::NATURE;
    case SCHOOL_FROST:
      return color::FROST;
    case SCHOOL_SHADOW:
      return color::SHADOW;
    case SCHOOL_ARCANE:
      return color::ARCANE;
    // -- Physical and a Magical
    case SCHOOL_FLAMESTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_FIRE );
    case SCHOOL_FROSTSTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_FROST );
    case SCHOOL_SPELLSTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_ARCANE );
    case SCHOOL_STORMSTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_NATURE );
    case SCHOOL_SHADOWSTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_SHADOW );
    case SCHOOL_HOLYSTRIKE:
      return school_color( SCHOOL_PHYSICAL ) + school_color( SCHOOL_HOLY );
    // -- Two Magical Schools
    case SCHOOL_FROSTFIRE:
      return color::FROSTFIRE;
    case SCHOOL_SPELLFIRE:
      return school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_FIRE );
    case SCHOOL_FIRESTORM:
      return school_color( SCHOOL_FIRE ) + school_color( SCHOOL_NATURE );
    case SCHOOL_SHADOWFLAME:
      return school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_FIRE );
    case SCHOOL_HOLYFIRE:
      return school_color( SCHOOL_HOLY ) + school_color( SCHOOL_FIRE );
    case SCHOOL_SPELLFROST:
      return school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_FROST );
    case SCHOOL_FROSTSTORM:
      return school_color( SCHOOL_FROST ) + school_color( SCHOOL_NATURE );
    case SCHOOL_SHADOWFROST:
      return school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_FROST );
    case SCHOOL_HOLYFROST:
      return school_color( SCHOOL_HOLY ) + school_color( SCHOOL_FROST );
    case SCHOOL_ASTRAL:
      return school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_NATURE );
    case SCHOOL_SPELLSHADOW:
      return school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_SHADOW );
    case SCHOOL_DIVINE:
      return school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_HOLY );
    case SCHOOL_SHADOWSTORM:
      return school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_NATURE );
    case SCHOOL_HOLYSTORM:
      return school_color( SCHOOL_HOLY ) + school_color( SCHOOL_NATURE );
    case SCHOOL_SHADOWLIGHT:
      return school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_HOLY );
    //-- Three or more schools
    case SCHOOL_ELEMENTAL:
      return color::ELEMENTAL;
    case SCHOOL_COSMIC:
      return school_color( SCHOOL_HOLY ) + school_color( SCHOOL_NATURE ) +
             school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_ARCANE );
    case SCHOOL_CHROMATIC:
      return school_color( SCHOOL_FIRE ) + school_color( SCHOOL_FROST ) +
             school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_NATURE ) +
             school_color( SCHOOL_SHADOW );
    case SCHOOL_CHROMASTRIKE:
      return school_color( SCHOOL_FIRE ) + school_color( SCHOOL_FROST ) +
             school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_NATURE ) +
             school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_PHYSICAL );
    case SCHOOL_MAGIC:
      return school_color( SCHOOL_FIRE ) + school_color( SCHOOL_FROST ) +
             school_color( SCHOOL_ARCANE ) + school_color( SCHOOL_NATURE ) +
             school_color( SCHOOL_SHADOW ) + school_color( SCHOOL_HOLY );
    case SCHOOL_CHAOS:
      return color::CHAOS;

    default:
      return GREY2;
  }
}
} /* namespace color */
