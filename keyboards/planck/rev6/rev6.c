/* Copyright 2018 Jack Humbert <jack.humb@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "rev6.h"
#include "qwiic.h"

void matrix_init_kb(void) {
	matrix_init_user();
}

void matrix_scan_kb(void) {
	matrix_scan_user();
}

void joystiic_trigger_kb(uint8_t trigger, bool active) {
  switch (trigger) {
    case JOYSTIIC_LEFT: active ? register_code(KC_L) : unregister_code(KC_L); break;
    case JOYSTIIC_RIGHT: active ? register_code(KC_R) : unregister_code(KC_R); break;
    case JOYSTIIC_UP: active ? register_code(KC_U) : unregister_code(KC_U); break;
    case JOYSTIIC_DOWN: active ? register_code(KC_D) : unregister_code(KC_D); break;
    case JOYSTIIC_PRESS: active ? register_code(KC_P) : unregister_code(KC_P); break;
  }
}
