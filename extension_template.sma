#include <amxmodx>
#include <amxmisc>
#include <logger>

#include "include/zm/zombies.inc"

#if defined ZM_COMPILE_FOR_DEBUG
#else
#endif

#define EXTENSION_NAME "${name}"
#define VERSION_STRING "1.0.0"

public zm_onInit() {
#if defined ZM_COMPILE_FOR_DEBUG
  LoggerSetVerbosity(This_Logger, Severity_Lowest);
#endif
}

public zm_onInitExtension() {
  new name[32];
  formatex(name, charsmax(name), "[%L] %s", LANG_SERVER, ZM_NAME_SHORT, EXTENSION_NAME);
  
  new buildId[32];
  getBuildId(buildId, charsmax(buildId));
  register_plugin(name, buildId, "${user}");
  zm_registerExtension(
      .name = EXTENSION_NAME,
      .version = buildId,
      .desc = "");
}

stock getBuildId(buildId[], len) {
  return formatex(buildId, len, "%s [%s]", VERSION_STRING, __DATE__);
}
