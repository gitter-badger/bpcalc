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

#include <cmath>

class Whirlwind
{
	private:
		bool bul_kathos;

		float increased_attack_speed;
		float weapon_speed;

	public:
		float get_attacks_per_second();
		float get_breakpoint(float divider, bool next = false);
		float &get_increased_attack_speed();
		float get_ticks_per_second(float divider);
		float &get_weapon_speed();

		Whirlwind();
		Whirlwind(float &weapon_speed, float &increased_attack_speed, bool &bul_kathos);
};
