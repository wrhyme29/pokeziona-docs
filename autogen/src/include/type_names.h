#ifndef GUARD_TYPE_NAMES_H
#define TYPE_NAMES_H

#include "pokemon.h"

#define TYPE_NAME_LENGTH 9

const u8 gTypeNames[NUMBER_OF_MON_TYPES][TYPE_NAME_LENGTH + 1] =
{
    [TYPE_NORMAL] = _("NORMAL"),
    [TYPE_FIGHTING] = _("FIGHT"),
    [TYPE_FLYING] = _("FLYING"),
    [TYPE_POISON] = _("POISON"),
    [TYPE_GROUND] = _("GROUND"),
    [TYPE_ROCK] = _("ROCK"),
    [TYPE_BUG] = _("BUG"),
    [TYPE_GHOST] = _("GHOST"),
    [TYPE_STEEL] = _("STEEL"),
    [TYPE_MYSTERY] = _("???"),
    [TYPE_FIRE] = _("FIRE"),
    [TYPE_WATER] = _("WATER"),
    [TYPE_GRASS] = _("GRASS"),
    [TYPE_ELECTRIC] = _("ELECTRIC"),
    [TYPE_PSYCHIC] = _("PSYCHIC"),
    [TYPE_ICE] = _("ICE"),
    [TYPE_DRAGON] = _("DRAGON"),
    [TYPE_DARK] = _("DARK"),
    [TYPE_FAIRY] = _("FAIRY"),
};

#endif // TYPE_NAMES_H