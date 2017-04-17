#if defined _zm_cfg_included
  #endinput
#endif
#define _zm_cfg_included

#include <amxmodx>

#tryinclude "include/stocks/path_stocks.inc"
#if !defined _path_stocks_included
  #include <path_stocks>
#endif

/** The name of ZM. This value will be used before the i18n dictionaries have been loaded. */
#define ZM_MOD_NAME "Zombie Mod"
/** The path (relative to {@code amxmodx/configs/}) where the ZM configs are located. */
#define ZM_CONFIGS_DIR "zm"
/** The name of the ZM CFG file. */
#define ZM_CFG_FILE "zombies.cfg"

/**
 * Returns the path to the ZM configs directory.
 */
stock zm_getConfigsDir(dst[], len) {
  get_localinfo("amxx_configsdir", dst, len);
  return BuildPath(dst, len, dst, ZM_CONFIGS_DIR);
}

/**
 * Returns the path to the ZM config file.
 */
stock zm_getConfigsFile(dst[], len) {
  zm_getConfigsDir(dst, len);
  return BuildPath(dst, len, dst, ZM_CFG_FILE);
}
