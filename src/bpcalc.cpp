/*
* Copyright (C) 2015 Snailsoft <https://github.com/snailsoft/bpcalc/>
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <bpcalc.hpp>
#include <version.hpp>

bool get_argument(int &argc, char **&argv, int &argument, float &value)
{
	if((argument + 1) <= (argc - 1))
	{
		value = static_cast<float>(atof(argv[++argument]));

		return true;
	}

	return false;
}

int main(int argc, char *argv[])
{
	std::cout << BPCALC_NAME << " - " << BPCALC_DESCRIPTION << std::endl;
	std::cout << "Version " << BPCALC_VERSION << std::endl;
	std::cout << std::endl;
	std::cout << "Copyright(C) 2015 " << BPCALC_AUTHOR << " <https://github.com/snailsoft/bpcalc/>" << std::endl;
	std::cout << std::endl;

	if(argc > 1)
	{
		auto bul_kathos = false;
		auto increased_attack_speed = 0.0f;
		auto weapon_speed = 0.0f;

		for(int i = 1; i < argc; ++i)
		{
			if(!strcmp(argv[i], "-bk"))
				bul_kathos = true;

			else if(!strcmp(argv[i], "-frenzied") || !strcmp(argv[i], "-wotb"))
				increased_attack_speed += 0.25f;

			else if(!strcmp(argv[i], "-gogok"))
				increased_attack_speed += 0.15f;

			else if(!strcmp(argv[i], "-ias"))
			{
				float ias = 0.0f;

				if(!get_argument(argc, argv, i, ias))
				{
					std::cout << "Error: Incorrect usage of -ias <number>" << std::endl;

					return 0;
				}

				increased_attack_speed += ias * 0.01f;
			}
			else if(!strcmp(argv[i], "-pe"))
			{
				float enemies = 0.0f;

				if(!get_argument(argc, argv, i, enemies))
				{
					std::cout << "Error: Incorrect usage of -pe <enemies>" << std::endl;

					return 0;
				}

				increased_attack_speed += enemies * 0.03f;
			}
			else if(!strcmp(argv[i], "-wep"))
			{
				if(!get_argument(argc, argv, i, weapon_speed))
				{
					std::cout << "Error: Incorrect usage of -wep <number>" << std::endl;

					return 0;
				}
			}
			else
				std::cout << "Warning: Invalid option: " << argv[i] << std::endl;
		}

		Whirlwind ww(weapon_speed, increased_attack_speed, bul_kathos);

		std::cout << "Weapon speed            IAS                   APS" << std::endl;
		std::cout << "------------            ---                   ---" << std::endl;

		printf("%.02f\t                %.01f%%\t              %.02f\n\n", ww.get_weapon_speed(), ww.get_increased_attack_speed() * 100.0f, ww.get_attacks_per_second());
		
		std::cout << "WW ticks per second     IAS to previous BP    IAS to next BP" << std::endl;
		std::cout << "-------------------     ------------------    --------------" << std::endl;
		
		printf("%.02f\t                %.01f%% (-%.01f%%)\t      %.01f%% (+%.01f%%)\n\n", ww.get_ticks_per_second(20.0f), ww.get_breakpoint(20.0f) * 100.0f, (ww.get_increased_attack_speed() - ww.get_breakpoint(20.0f)) * 100.0f, ww.get_breakpoint(20.0f, true) * 100.0f, (ww.get_breakpoint(20.0f, true) - ww.get_increased_attack_speed()) * 100.0f);

		std::cout << "Tornadoes per second    IAS to previous BP    IAS to next BP" << std::endl;
		std::cout << "--------------------    ------------------    --------------" << std::endl;

		printf("%.02f\t                %.01f%% (-%.01f%%)\t      %.01f%% (+%.01f%%)\n", ww.get_ticks_per_second(30.0f), ww.get_breakpoint(30.0f) * 100.0f, (ww.get_increased_attack_speed() - ww.get_breakpoint(30.0f)) * 100.0f, ww.get_breakpoint(30.0f, true) * 100.0f, (ww.get_breakpoint(30.0f, true) - ww.get_increased_attack_speed()) * 100.0f);
	}
	else
	{
		std::cout << "Usage:" << std::endl;
		std::cout << "    " << argv[0] << " [options]" << std::endl;
		std::cout << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "    Option       Argument     Description" << std::endl;
		std::cout << "    ------       --------     -----------" << std::endl;
		std::cout << "    -bk                       Bul-Kathos set's 30% IAS multiplier" << std::endl;
		std::cout << "    -frenzied                 Frenzied Shrine's 25% IAS bonus" << std::endl;
		std::cout << "    -gogok                    Gogok of Swiftness's 15% IAS bonus" << std::endl;
		std::cout << "    -ias         <number>     Increased attack speed (shown on character sheet)" << std::endl;
		std::cout << "    -pe          <enemies>    Pain Enhancer's 3% IAS bonus per bleeding enemy" << std::endl;
		std::cout << "    -wep         <number>     Weapon speed" << std::endl;
		std::cout << "    -wotb                     Wrath of the Berserker's 25% IAS bonus" << std::endl;
	}

	return 0;
}
