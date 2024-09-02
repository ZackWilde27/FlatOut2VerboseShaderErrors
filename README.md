# FlatOut2VerboseShaderErrors
A mod for FlatOut 2 in the same vein as VerboseLUAErrors, except it shows shader errors

## Using
*This mod requires the xnya mod loader*

You'll need the ```winmm.dll``` and ```xnya_modloader.toml``` from one of Chloe's FlatOut 2 mods, such as [VerboseLUAErrors](https://github.com/gaycoderprincess/FlatOut2VerboseLUAErrors)

Once the mod loader is installed, copy the dll to the game's directory.


## Building
I used Visual Studio on Windows

Start with a Dynamic-Link-Library template and replace the generated ```dllmain.cpp``` with this one
