#if defined _zm_version_included
  #endinput
#endif
#define _zm_version_included

#include "include/zm/zm_version_codes.inc"
#include "include/zm/zm_debug.inc"

/** The version code of ZM. */
#define ZM_VERSION 1
/** The string representation for this version of ZM. */
#define ZM_VERSION_STRING "1.0.0"

#define ZM_LATEST_VERSION_URL "https://raw.githubusercontent.com/collinsmith/zombies-inc/master/version"
#define ZM_LATEST_VERSION_PORT 443

/**
 * Returns the version code of ZM.
 */
stock zm_getVersionId() {
  return ZM_VERSION;
}

/**
 * Returns the string representation for the version of ZM.
 */
stock zm_getVersion(version[], len) {
  return copy(version, len, ZM_VERSION_STRING);
}

/**
 * Returns the build identifier string for the version of ZM.
 */
stock zm_getBuildId(buildId[], len) {
#if defined ZM_COMPILE_FOR_DEBUG
  return formatex(buildId, len, "%s [%s] [DEBUG]", ZM_VERSION_STRING, __DATE__);
#else
  return formatex(buildId, len, "%s [%s]", ZM_VERSION_STRING, __DATE__);
#endif
}

/**
 * Contacts the remote repository and returns the most recent verison code of
 * ZM.
 * 
 * @param version Destination buffer to copy version's string representation into
 * 
 * @return The version code for the latest version of ZM
 */
stock zm_getLatestVersion(version[] = "", len = 0, Logger: logger = Invalid_Logger) {
  new error, socket = socket_open(ZM_LATEST_VERSION_URL, ZM_LATEST_VERSION_PORT, ._error = error);
  if (error) {
    switch (error) {
      case 1: LoggerLogWarning(logger, "Socket could not be created due to an unspecified error");
      case 2: LoggerLogWarning(logger, "Failed to resolve remote hostname: %s", ZM_LATEST_VERSION_URL);
      case 3: LoggerLogWarning(logger, "Failed to connect to %s on port %d", ZM_LATEST_VERSION_URL, ZM_LATEST_VERSION_PORT);
    }

    return ZM_VERSION;
  }

  new data[32];
  socket_recv(socket, data, charsmax(data));
  socket_close(socket);

  new tmp[32];
  new offset = copyc(tmp, charsmax(tmp), data, ' ');
  new const versionId = str_to_num(tmp);
  if (versionId == 0) {
    LoggerLogWarning(logger, "Error parsing version info: %s", data);
    return ZM_VERSION;
  }

  if (len > 0) {
    copy(version, len, data[offset + 1]);
  }
  
  return versionId;
}
