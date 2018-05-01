#define RUN_TESTS

#include <a_samp>
#include <YSI\y_testing>

#include "mapandreas.inc"

main() {
    new ret = MapAndreas_Init(MAP_ANDREAS_MODE_FULL);
    printf("MapAndreas_Init: %d", ret);
    ASSERT(ret == MAP_ANDREAS_ERROR_SUCCESS);
}

Test:MapAndreas_FindZ_For2DCoord() {
    new Float:z;
    new ret;

    ret = MapAndreas_FindZ_For2DCoord(0.0, 0.0, z);
    ASSERT(ret == 1);
    ASSERT(z - 2.109999 < 0.0001);
}

Test:MapAndreas_FindAverageZ() {
    new Float:z;
    new ret;

    ret = MapAndreas_FindAverageZ(-2500.0, -2500.0, z);
    ASSERT(ret == 1);
    ASSERT(z - 43.750000 < 0.0001);
}
