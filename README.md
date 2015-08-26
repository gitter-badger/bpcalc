# bpcalc
Whirlwind breakpoint calculator for Diablo 3

## Overview
bpcalc is a command-line utility for calculating Whirlwind and Dust Devil breakpoints for Barbarians in Diablo 3. The program will also show the required `increased attack speed` to reach the previous or next breakpoint. Read: it shows wasted IAS.

## Usage
Using `bpcalc` is really easy, simply type `bpcalc [options]` in a command prompt where options correspond to the following options:
`
    Option       Argument     Description
    ------       --------     -----------
    -bk                       Bul-Kathos set's 30% IAS multiplier
    -frenzied                 Frenzied Shrine's 25% IAS bonus
    -gogok                    Gogok of Swiftness's 15% IAS bonus
    -ias         <number>     Increased attack speed (shown on character sheet)
    -pe          <enemies>    Pain Enhancer's 3% IAS bonus per bleeding enemy
    -wep         <number>     Weapon speed
    -wotb                     Wrath of the Berserker's 25% IAS bonus
`
