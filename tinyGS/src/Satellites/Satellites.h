/*
  Satellites.h - Satellites class
  
  Copyright (C) 2022 -2023 @estbhan

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
#include <cstdint>
#ifndef SATELLITES_H
#define SATELLITES_H
class Satellites{
    public:
    static int coding(int noradid);
    static bool isValidSatellite(int norad);
    static float estimatedSatelliteFrequency(int noradid, float freq);
    static bool allowDistributeSatelliteData(int norad);
    static bool isNotValidSatellite(int norad);
    static int whitening_params(int noradid, uint16_t *seed);
    //static int crc_params(int noradid);
    static int crc_params(int noradid, uint8_t *nbytes, uint16_t *initial, uint16_t *finalxor, uint16_t *poly, bool *inverted);
};
#endif