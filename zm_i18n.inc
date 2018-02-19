#if defined _zm_i18n_included
  #endinput
#endif
#define _zm_i18n_included

#include "include/stocks/resource_stocks.inc"

#include "include/zm/zm_debug.inc"

#if defined DEBUG_I18N
  #include <logger>
  #include "include/stocks/simple_logger_stocks.inc"
#endif

/** The dictionary file of zombies. */
#define ZOMBIES_DICTIONARY "zombiemod.txt"

// TODO: Documentation
#define class_prop_key_length 31
// TODO: Documentation
#define class_prop_value_length 511

/** The name of ZM (default: {@code "Zombie Mod"}). */
stock const ZM_NAME[] = "ZM_NAME";
/** The short name of ZM (default: {@code "ZM"}). */
stock const ZM_NAME_SHORT[] = "ZM_NAME_SHORT";

/**
 * Returns the path to the zombies dictionary.
 */
stock zm_getDictionary(dst[], len) {
  return copy(dst, len, ZOMBIES_DICTIONARY);
}

stock zm_registerDictionary(const filename[]) {
  register_dictionary(filename);
#if defined DEBUG_I18N
  logd("Registered dictionary \"%s\"", filename);
#endif
}
