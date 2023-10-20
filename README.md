# 5plusbuttonsJoystick
5+1 Buttons Joystick for CBM 64/Vic 20

![Alt text](snap.png?raw=true "Screen")
[Joystik Tester PRG](Joystick5plus1Test.prg)

![Alt text](joy5plus.PNG?raw=true "Schematic")
[Pdf](Joy5Plus2.0.pdf)

## DIY a modern multi button joystick for your C64
Since many, many years, a 3 button joystick for C64 is well known, but unfortunately not very widespread.
Only the C64GS had some games which officially supported a second joystick button, and since the C64GS came out very late in the C64's lifespan, it never became common.
Standard joystick ports on C64 (and Vic20) has the necessary hardware for 3 fire buttons, using the standard fire and the two connections POTX and POTY.
This simple project adds two more buttons that uses two additional logic states to use them in two buttons "Select" and "Start".

These two logic states are the simultaneousonly closing of the "UP" and "Down" circuits for the "Select" state/button and the simultaneous closing of the "Right" and "Left" circuits for the "Start" state/button, impossible to obtain in reality using the movement stick but identifiable by software. In this case the "Start" and "Select" buttons are perfectly usable for menus and choices to make when you are out of the action.

## Some games that support additional buttons
Many early home computers and game consoles came with the classic one button joystick, and supporting more than that was rare. The following list omits the later released systems where controllers with two or more buttons became standard. (like MSX, SEGA Mastersystem, etc)

* Alien 8 by Rod & Emu - 2nd button can be used for pick/drop in directional mode.
* Battle Command (Ocean Cartridge) - 2nd button toggles between tank- and menu control, hold for menu bar
* Chase HQ2 (C64GS Cartridge) - 2nd button enables turbo boost
* Double Dragon (Ocean)
* Giana Sisters 30th Anniversary Hack by The Seven-A-Three (WIP)
* Last Ninja Remix (C64GS Cartridge) - The button used to start the game becomes the "fighting moves" button, the other button becomes the "weapon select" button. The selection can be changed at the beginning of each level by pressing the respective button to start it.
* Navy Seals (Ocean) - 2nd button restarts the game
* +Myth (C64GS Cartridge) - hold 2nd button to change weapon with left+right
* Pang (Ocean) - 2nd button pauses the game
* Paradroid Redux - "Press 2nd button while title screen is shown to start game in two-button mode. Use second button to go into transfer mode, first button for everything else."
* Robocop 2 (C64GS Cartridge) - optionally use 2nd button for "jump"
* Spacegun - 2nd button to change weapon
* Super Mario Bros (Zeropaige version) - optionally use 2nd button for "jump"
* Turbo Charge - 2nd button enables turbo boost
etc etc

## Some games modded by me
* Commando (second fire to throw a granate) [Commando](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/commando.d64);
* Retaliate64-CE (second fire activate shield, third fire launch missile) [Retaliate64-CE](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/retaliate-ce.prg);
* 1942 (second fire to pull up)[1942](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/1942-2ndfire.prg);
* Scramble - 2015 version (separate fire and second fire for bombs, as in the arcade version) [Scramble](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/scramble%5B2015%5D_2nd_fire.prg);
* Blue Max (Only second fire to drop boms) [Blue Max](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/BlueMax_2nd_fire.prg);
* Wizball (2nd fire to choose the extra that is flashing at the upper border of the screen) [Wizball](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/wizball-2nd-fire.prg);
* Rambo: First Blood Part II (2nd fire to choose weapon and to make action) [Rambo: First Blood Part II](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/rambo-first-blood-2nd-fire.prg);
* Green Beret: (2nd fire to use additional weapon) [Green Beret](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/green-beret-2nd-fire.prg);
* Gryzor: (2nd fire to jump) [Gryzor](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/gryzor-2nd-fire.prg);
* Turrican: (2nd fire to activate two energy lines) [Turrican](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/turrican-2nd-fire.zip);
* Turrican II: (2nd fire to activate two energy lines) [Turrican II](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/Turrican2-2nd-fire.zip);
* Turbo Girl: (2nd fire to jump) [Turbo Girl](https://github.com/crystalct/5plusbuttonsJoystick/raw/main/turbogirl-2nd-fire.prg);
* Look here for the complete and updated [list](http://wiki.icomp.de/wiki/DE-9_Joystick#C64).
