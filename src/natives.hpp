#ifndef MAPANDREAS_NATIVES_H
#define MAPANDREAS_NATIVES_H

#include <string>

#include <amx/amx2.h>

#include "common.hpp"

namespace Natives {
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL Init(AMX* amx, cell* params);
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL FindZ_For2DCoord(AMX* amx, cell* params);
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL FindAverageZ(AMX* amx, cell* params);
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL _Unload(AMX* amx, cell* params); // prefixed with _ to solve a linker issue with ambiguous "Unload" function
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL SetZ_For2DCoord(AMX* amx, cell* params);
PLUGIN_EXTERN_C cell AMX_NATIVE_CALL SaveCurrentHMap(AMX* amx, cell* params);
}

#endif
