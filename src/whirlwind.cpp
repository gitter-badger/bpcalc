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

#include <whirlwind.hpp>

float Whirlwind::get_attacks_per_second()
{
	return (this->weapon_speed * (1.0f + this->increased_attack_speed)) * (this->bul_kathos ? 1.3f : 1.0f);
}

float Whirlwind::get_breakpoint(float divider, bool next)
{
	auto breakpoint = 0.0f;
	auto ias = this->increased_attack_speed;
	auto tps = this->get_ticks_per_second(divider);

	while(tps == this->get_ticks_per_second(divider))
		this->increased_attack_speed += (next ? 0.0001f : -0.0001f);

	breakpoint = this->increased_attack_speed - (next ? 0.0f : 0.001f);
	this->increased_attack_speed = ias;

	return breakpoint;
}

float &Whirlwind::get_increased_attack_speed()
{
	return this->increased_attack_speed;
}

float Whirlwind::get_ticks_per_second(float divider)
{
	return 60.0f / floor(divider / this->get_attacks_per_second());
}

float &Whirlwind::get_weapon_speed()
{
	return this->weapon_speed;
}

Whirlwind::Whirlwind()
{
	this->bul_kathos = false;
	this->increased_attack_speed = 0.0f;
	this->weapon_speed = 0.0f;
}

Whirlwind::Whirlwind(float &weapon_speed, float &increased_attack_speed, bool &bul_kathos)
{
	this->bul_kathos = bul_kathos;
	this->increased_attack_speed = increased_attack_speed;
	this->weapon_speed = weapon_speed;
}
