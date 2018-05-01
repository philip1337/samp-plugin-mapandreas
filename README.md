# Map Andreas Plugin

[![sampctl](https://shields.southcla.ws/badge/sampctl-mapandreas-2f2f2f.svg?style=for-the-badge)](https://github.com/Southclaws/samp-plugin-mapandreas)

This plugin was initially made by Kalcor and extended by Mauzen. It allows you
to load different height maps and check the min height for x,y coordinates. You
can us it as example for an anti cheat to detect airbreaks easier or to prevent
falling through the ground.

Features:

*   Load height map
*   You can also implement it in your sampgdk plugins.

Topics:

*   [MapAndreas v1.2.1 Updated @ sa-mp.com](http://forum.sa-mp.com/showthread.php?t=275492)
*   [MapAndreas v1.2.1 Updated @ sa-mp.com](http://forum.sa-mp.com/showpost.php?p=3130004&postcount=153)
*   [MapAndreas v1.0 beta @ sa-mp.com](http://forum.sa-mp.com/showthread.php?t=120013)

## Installation

Simply install to your project:

```bash
sampctl package install Southclaws/samp-plugin-mapandreas
```

Include in your code and begin using the library:

```pawn
#include <mapandreas>
```

## Usage

| native                      | params                        |           return           |
| --------------------------- | ----------------------------- | :------------------------: |
| MapAndreas_Init             | mode, const name[]            | Error code or 0 on success |
| MapAndreas_Unload           | const name[], const message[] |  int (0 failed/1 success)  |
| MapAndreas_SaveCurrentHMap  | const name[]                  |  int (0 failed/1 success)  |
| MapAndreas_FindZ_For2DCoord | Float:X, Float:Y, &Float:Z    |  int (0 failed/1 success)  |
| MapAndreas_FindAverageZ     | Float:X, Float:Y, &Float:Z    |  int (0 failed/1 success)  |
| MapAndreas_SetZ_For2DCoord  | Float:X, Float:Y, Float:Z     |  int (0 failed/1 success)  |

### Example

Initialize MapAndreas and get a position.

```pawn
public OnGameModeInit(playerid, cmdtext[])
{
    MapAndreas_Init(MAP_ANDREAS_MODE_FULL, "scriptfiles/SAFull.hmap");
    new Float:pos;
    if (MapAndreas_FindAverageZ(20.001, 25.006, pos)) {
        // Found position - position saved in 'pos'
    }
    return 0;
}
```

## Testing

Test with make:

```bash
make test-windows
```

If you want to build/test the Linux version, use Docker:

```bash
make build-linux
make test-linux
```

This will spin up a Debian container to build and then run sampctl with
`--container` to run the test package in a Linux environment.
