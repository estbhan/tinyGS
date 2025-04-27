/*
  Satellites.cpp - Satellites class
  
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

#include "Satellites.h"

//////////////////////////////////
//18/09/2022 - Filtro de satelites
//////////////////////////////////
//Satélite		          Norad ID
//////////////////////////////////
//Norbi....................46494
//SATLLA-B.................51014
//FEES.....................48082 -- IARU COORDINATED
//UPMSAT-2.................46276
//INST-2TD.................51658
//ASTROCAST 0.1............43798

//BZLORA-6, Upape, DATESat 99999
//FOSSASAT-1B..............99333
//POLYTECH-1...............53371
//DELPHI-PQ................51074
//AZAADISAT 2 .............55563
//SAPLING..................10750
//PROVES...................70380
//FUTURA_SM1...............55105
//Fossasat 2E8, 2E9, 2E10 Y 2E13 = 99991
//Grizu-263a...............99488
//Sapling2.................56214 / 56213

//Monitor 3................57180 (IARU Uncoordinated 12/07/2023) RS58S
//Norby-2..................57181 (IARU Uncoordinated 12/07/2023)
//POLYTECH-3...............53191 (IARU Uncoordinated 12/07/2023) RS46S
//CSTP-1.1.................57202 (IARU Uncoordinated 12/07/2023)
//CSTP-1.2.................57186 (IARU Uncoordinated 12/07/2023)
//RS52XX...................57167 (IARU Uncoordinated 12/07/2023)
//Monitor 4................57182 (IARU Uncoordinated 12/07/2023) RS57S 
//RS39S....................57184 


bool Satellites::isValidSatellite(int norad){
    if (   norad==46494 // Norbi --
        || norad==48082 // FEES --
        || norad==46276 // UPMSAT-2 -- 
        || norad==51658 || norad==43798 || norad==57208 // INS-2TD -- ASTROCAST 0.1 - RS52SD
        || norad==57181 || norad==58665 || norad==57191 // Norby-2 -- MDQubeSAT-2 -- Polytech-3
        || norad==56213 || norad==57180 || norad==57168 // -- -- ReshUCube-2
        || norad==53191 || norad==57202 || norad==57205 // -- -- RS52SE
        || norad==57186 || norad==57167 || norad==57169 // -- -- RS52SV
        || norad==57200 || norad==57170 // RS52SB -- RS52SG
        || norad==57183 // 2023-091T
        || norad==59114 || norad==59117 //ONDOSAT OWL 1 & 2
        || norad==98866 // SR0-DEMOSAT 60455
        || norad==44406 // LUCKY-7
        || norad==57179 // Norby-2 --

        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

bool Satellites::isNotValidSatellite(int norad){
    if (   norad==99999
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

bool Satellites::allowDistributeSatelliteData(int norad){
    if (   norad==46494 // Norbi 
        || norad==48082 // FEES 
        || norad==46276 // UPMSAT-2 
        || norad==51658 // INS-2TD
        || norad==43798 // ASTROCAST 0.1
        || norad==59114 || norad==59117 //ONDOSAT OWL 1 & 2 
        //|| norad==57169 // RS52SV
        //|| norad==57170 // RS52SG
        //|| norad==57200 // RS52SB
        //|| norad==57205 // RS52SE
        //|| norad==57208 // RS52SD
        //|| norad==57181 || norad==58665 || norad==57191 // MDQubeSAT-2 -- Polytech-3
        //|| norad==57202 || norad==57186   // CSPT 1&2
        //|| norad==57179 // Norby-2 --
        || norad==98866 // SR0-DEMOSAT 60455 
        || norad==44406 // LUCKY-7 
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

/*
If the satellite is not transmitting at the published frequency, with this adjustment
the receiver satellite frequency could be corrected. The method will provide the 
estimated satellite transmitter frequency.  
*/
float Satellites::estimatedSatelliteFrequency(int noradid, float freq){
  float aux=freq;
  switch (noradid)
  {
  case 48082://FEES
    aux=437.203;
    break;
  
  case 51014://SATLLA-B
    aux=437.255;
    break;
  
  case 56214://SAPLING2
    aux=437.395;
    break;

  case 56213://SAPLING2
    aux=437.395;
    break;

  case 57168://Reshucube
    aux=436.001;
    break;

  case 57191://Polytech_Universe-3
    aux=436.556;
    break;

  case 57205://RS52SE
    aux=436.2622;
    break;

  case 98866://SR-0
    aux=437.402;
    break;

  default:
    break;
  }  
  return aux;
}

/*
Output:
0: Raw
1: AX25
*/
int Satellites::coding(int noradid){
    int aux=0;
  switch (noradid)
  {
  case 46276://UPMSAT-2
    aux=1;
    /* code */
    break;
  
  case 51658://INS-2TD
    aux=1;
    /* code */
    break;

  case 43798://ASTROCAST 0.1
    aux=1;
    /* code */
    break;

  case 56188://CIRBE
    aux=1;
    /* code */
    break;

  case 98866://SR-0
    aux=1;
    /* code */
    break;

  default:
    aux=0;
    break;
  }
  return aux;
}

/*
------------- 
10/06/2024
-------------
Output:
0: No Scramble
1: Whitening
*/
int Satellites::whitening_params(int noradid, uint16_t *seed){
    int aux=0;
  switch (noradid)
  {
  case 44406://LUCKY-7
    aux=1;
    *seed=0x01E1;
    break;

  default:
    aux=0;
    *seed=0;
    break;
  }
  return aux;
}

/*
------------- 
11/09/2024
-------------
Output:
0: No CRC Check
1: CRC Check by Software: Check performed over the data stream recieved and using the 
                          last two bytes as the transmitted CRC.
2: CRC Check by Hardware: Configured at the RF Board configuration time. The board will
                          perform the CRC check transparently to the user.
*/

int Satellites::crc_params(int noradid, uint8_t *nbytes, uint16_t *initial, uint16_t *finalxor,  uint16_t *poly, bool *inverted){
    int aux=0;
  switch (noradid)
  {
  case 44406://LUCKY-7
    aux=1;
    *nbytes=2;
    *initial=0xFFFF;
    *finalxor=0x0000;
    *poly=0x8005;
    switch (aux) 
    {
      case 1: *inverted=false;break;
      case 2: *inverted=true;break;
    }
    break;

  default:
    aux=0;
    *nbytes=0;
    *initial=0xFFFF;
    *finalxor=0x0000;
    *poly=0x8005;
    *inverted=false;
    break;
  }
  return aux;
}