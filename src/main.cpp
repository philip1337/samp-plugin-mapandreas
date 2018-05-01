#include <amx/amx.h>
#include <plugincommon.h>

#include "common.hpp"
#include "natives.hpp"

logprintf_t logprintf;

extern "C" AMX_NATIVE_INFO nativeList[] = {
    { "MapAndreas_Init", Natives::Init },
    { "MapAndreas_FindZ_For2DCoord", Natives::FindZ_For2DCoord },
    { "MapAndreas_FindAverageZ", Natives::FindAverageZ },
    { "MapAndreas_Unload", Natives::_Unload },
    { "MapAndreas_SetZ_For2DCoord", Natives::SetZ_For2DCoord },
    { "MapAndreas_SaveCurrentHMap", Natives::SaveCurrentHMap },
    { 0, 0 }
};
AMX* gAmx;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];
    return true;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    gAmx = amx;
    return amx_Register(amx, nativeList, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
    Natives::_Unload(gAmx, 0);
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload()
{
    return 1;
}
