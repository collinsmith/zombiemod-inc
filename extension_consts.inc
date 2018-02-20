#if defined _extension_consts_included
  #endinput
#endif
#define _extension_consts_included

/** Suggested max length for extension filename */
#define ZM_EXT_FILENAME_length 32
/** Suggested max length for extension name */
#define ZM_EXT_NAME_length 32
/** Suggested max length for extension version */
#define ZM_EXT_VERSION_length 32
/** Suggested max length for extension description */
#define ZM_EXT_DESC_length 128

/**
 * The following are keys used to access stored data within an extension's trie.
 */
/** Plugin ID */
stock const ZM_EXT_PLUGIN[] = "plugin"; // cell
/** File name of extension */
stock const ZM_EXT_FILENAME[] = "filename"; // string
/** Name of the extension */
stock const ZM_EXT_NAME[] = "name"; // string
/** Version string of the extension */
stock const ZM_EXT_VERSION[] = "version"; // string
/** Description of the extension */
stock const ZM_EXT_DESC[] = "desc"; // string
