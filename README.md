# bpcalc
Whirlwind breakpoint calculator for Diablo 3

## Overview
bpcalc is a command-line utility for calculating Whirlwind and Dust Devil breakpoints for Barbarians in Diablo 3. The program will also show the required `increased attack speed` to reach the previous or next breakpoint. Read: it shows wasted IAS.

`Note:` binary packages were built for Windows 10 x64 only. You will need to download and install the Visual C++ 2015 runtime located here in order to run bpcalc: [http://www.microsoft.com/en-us/download/details.aspx?id=48145](http://www.microsoft.com/en-us/download/details.aspx?id=48145)

## Usage
Using `bpcalc` is really easy, simply type `bpcalc [options]` in a command prompt where options correspond to the following options:
``
    Option       Argument     Description
    ------       --------     -----------
    -bk                       Bul-Kathos set's 30% IAS multiplier
    -frenzied                 Frenzied Shrine's 25% IAS bonus
    -gogok                    Gogok of Swiftness's 15% IAS bonus
    -ias         <number>     Increased attack speed (shown on character sheet)
    -pe          <enemies>    Pain Enhancer's 3% IAS bonus per bleeding enemy
    -wep         <number>     Weapon speed
    -wotb                     Wrath of the Berserker's 25% IAS bonus
``
An example might look something like this, assuming WoTB is up and you have BK weapons with 7% native IAS on them and 30% IAS from gear: `bpcalc -bk -ias 30 -wep 3.9` which would output the following:
``
Weapon speed            IAS                   APS
------------            ---                   ---
3.90                    30.0%                 6.59

Ticks per second        IAS to previous BP    IAS to next BP
----------------        ------------------    --------------
20.00                   -1.5% (-31.5%)        31.5% (+1.5%)

Tornadoes per second    IAS to previous BP    IAS to next BP
--------------------    ------------------    --------------
15.00                   18.2% (-11.8%)        47.9% (+17.9%)
``

## Building from source
To build from the source, run `git clone https://github.com/snailsoft/bpcalc.git` and then open the sln file.
`Note:` Visual Studio 2015 is required to build bpcalc from the source files.
