#if defined _zm_gun_menu_included
  #endinput
#endif
#define _zm_gun_menu_included

#pragma reqlib zm_gun_menu

#include <amxconst>

/*******************************************************************************
 * FORWARDS
 ******************************************************************************/

forward zm_onBeforeGunMenuDisplayed(const id, &weapons);
forward zm_onGunMenuBlocked(const id, const reason[]);
forward zm_onGunMenuDisplayed(const id, const weapons);

/*******************************************************************************
 * NATIVES
 ******************************************************************************/

native zm_showGunMenu(const id, const weapons, ...);
native zm_setGunMenuBlockedReason(const reason[]);
