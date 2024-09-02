# FlatOut2VerboseShaderErrors
A mod for FlatOut 2 in the same vein as VerboseLUAErrors, except it shows shader errors

It's the ShaderValidator from my HLSLToFlatOutShader, but built into the game

<br>

## Using
*This mod requires the xnya mod loader*

You'll need the ```winmm.dll``` and ```xnya_modloader.toml``` from one of Chloe's FlatOut 2 mods, I'd recommend pairing it with [VerboseLUAErrors](https://github.com/gaycoderprincess/FlatOut2VerboseLUAErrors)

Once the mod loader is installed, copy the dll to the game's directory.

<br>

## Building
I used Visual Studio on Windows

Create a project based on the Dynamic-Link-Library template and replace the generated ```dllmain.cpp``` with this one

There are some prerequisites you'll need:

### nya-common

Clone it from [here](https://github.com/gaycoderprincess/nya-common)

### d3dx9

Run this command in visual studio's nuget console:

      NuGet\Install-Package Microsoft.DXSDK.D3DX -Version 9.29.952.8

Then, under ```Properties->Linker->Input``` add the various .lib files related to direct x, like D3D9.lib and D3dx9.lib

*You might need to use the full path instead of just the filename*
