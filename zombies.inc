#if defined _zombies_included
  #endinput
#endif
#define _zombies_included

#pragma reqlib zombies

#include "include/zm/extension_consts.inc"
#include "include/zm/zm_cfg.inc"
#include "include/zm/zm_debug.inc"
#include "include/zm/zm_i18n.inc"
#include "include/zm/zm_misc.inc"
#include "include/zm/zm_version.inc"
#include "include/zm/zm_teams.inc"

/*******************************************************************************
 * FORWARDS
 ******************************************************************************/

/**
 * Called after ZM has initialized its resources. Extensions should override
 * this function to precache their own dependencies.
 * 
 * @noreturn
 */
forward zm_onPrecache();

/**
 * Called after {@link #zm_onPrecache} when ZM has initialized. Extensions
 * should override this function to initialize any data structures or variables
 * that they rely upon, so that any extensions which in turn depend upon them
 * can access the extension's state within {@link #zm_onInitExtension}.
 * 
 * @noreturn
 */
forward zm_onInit();

/**
 * Called after {@link #zm_onInit}. Extensions should override this function to
 * {@link #zm_registerExtension register themselves} with ZM and initialize.
 * 
 * @noreturn
 */
forward zm_onInitExtension();

/**
 * Called after an extension has been registered.
 * 
 * @param extension The trie containing the extension's info. Keys are located
 *                    within {@code extension_consts.inc}.
 * @param filename  The file name of the registering plugin.
 * 
 * @noreturn
 */
forward zm_onExtensionRegistered(const Trie: extension, const filename[]);

/*******************************************************************************
 * NATIVES
 ******************************************************************************/

/**
 * Returns the plugin ID of ZM, or {@code INVALID_PLUGIN_ID} if an error
 * occurred. This is used by all core extensions. Extensions which log
 * a lot of information should use their own logs instead.
 */
native zm_getPluginId();

/**
 * Registers an extension of zombies. Extensions should be registered in an
 * effort to maintain good house-keeping of a server and to keep track of
 * plugins which rely on zombies. Extensions should be registered during
 * {@link #zm_onInitExtension}.
 * 
 * @param name    The name of the extension, or {@code ""} to use the file name
 *                  of the registering plugin as the extension name (without
 *                  {@code .amxx})
 * @param desc    A brief description of what the extension does
 * @param version The version of the extension
 * 
 * @return The trie containing the extension's data, or {@code Invalid_Trie} if
 *         an error occured while registering it.
 * 
 * @throws IllegalStateException if the registering plugin has already
 *         registered itself as an extension.
 */
native Trie: zm_registerExtension(const name[] = "",
                                  const version[] = "",
                                  const desc[] = "");

/**
 * Returns an iterator over the registered extensions.
 */
native TrieIter: zm_getExtensionsIter();

/**
 * Returns the number of extensions registered with ZM.
 */
native zm_getNumExtensions();

/**
 * Returns the extension with the given file name, or {@code Invalid_Trie} if no
 * extension with the specified file name was found.
 */
native Trie: zm_findExtension(const filename[]);

/**
 * Returns the extension belonging to the given plugin index, or
 * {@code Invalid_Trie} if no extension was registered by it.
 */
native Trie: zm_findExtensionById(const plugin);

/**
 * Indicates whether or not the specified identifier is a trie belonging to an
 * extension.
 */
native bool: zm_isValidExtension(const any: extension);
