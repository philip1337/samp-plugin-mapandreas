# Map Andreas Plugin  #
This plugin was initiali made by Kalcor and extended bv Mauzen.
It allows you to load different height maps and check the min height for x,y coordinates.
You can us it as example for an anti cheat to detect airbreaks easier or to prevent falling through the ground.

## Features
- Load height map
- You can also implement it in your sampgdk plugins.

## Themes about this plugin:
- [MapAndreas v1.2.1 Updated @ sa-mp.com](http://forum.sa-mp.com/showthread.php?t=275492)
- [MapAndreas v1.2.1 Updated @ sa-mp.com](http://forum.sa-mp.com/showpost.php?p=3130004&postcount=153)
- [MapAndreas v1.0 beta @ sa-mp.com]http://forum.sa-mp.com/showthread.php?t=120013)

## Functions
|native|params|return|
|-------|-------|:-----:|
|MapAndreas_Init|mode, const name[]|int (0 failed/1 success)|
|MapAndreas_Unload|const name[], const message[]|int (0 failed/1 success)|
|MapAndreas_SaveCurrentHMap|const name[]|int (0 failed/1 success)|
|MapAndreas_FindZ_For2DCoord|Float:X, Float:Y, &Float:Z|int (0 failed/1 success)|
|MapAndreas_FindAverageZ|Float:X, Float:Y, &Float:Z|int (0 failed/1 success)|
|MapAndreas_SetZ_For2DCoord|Float:X, Float:Y, Float:Z|int (0 failed/1 success)|

- [Pawno include file: mapandreas.inc](include/mapandreas.inc)

### Example
Initialize MapAndreas and get a position.

    public OnGameModeInit(playerid, cmdtext[])
    {
        MapAndreas_Init(MAP_ANDREAS_MODE_FULL, "scriptfiles/SAFull.hmap");
        new Float:pos;
        if (MapAndreas_FindAverageZ(20.001, 25.006, pos)) {
            // Found position - position saved in 'pos'
        }
        return 0;
    }
    
    
## Build
#### Requirements
- [Modified version of gclient](https://github.com/timniederhausen/gclient)
- CMake >=3.1
- C++11
  - debian package: libc6-dev-i386

Synchronize dependencies from [DEPS](DEPS) File.

    gclient.py sync -v -f

You can also download it manually and place it into the external directory.

    mkdir build
    cd build
    cmake ..\samp-log-spdlog
    make

- [How to use cmake](https://github.com/bast/cmake-example)

## License
- [License](LICENSE)