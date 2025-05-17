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
#include <string.h>


//////////////////////////////////
//18/09/2022 - Filtro de satelites
//////////////////////////////////
//Satélite		          Norad ID
//////////////////////////////////
//Norbi....................46494
//SATLLA-B.................51014
//FEES.....................48082 
//UPMSAT-2.................46276
//INS-2TD..................51658
//ASTROCAST 0.1............43798
//HYPE.....................62687
//ONDOSAT OWL-1............59111
//ONDOSAT OWL-2............59113
//STRATOSAT TK-1...........57167

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

//Monitor 3................57180 
//Norby-2..................57181 
//POLYTECH-3...............53191 
//CSTP-1.1.................57202 
//CSTP-1.2.................57186 
//RS52XX...................57167 
//Monitor 4................57182 
//RS39S....................57184 


bool Satellites::isValidSatellite(int norad){
//Norbi....................46494
//UPMSAT-2.................46276
//INS-2TD..................51658
//ASTROCAST 0.1............43798
//HYPE.....................62687
//ONDOSAT OWL-1............59111
//ONDOSAT OWL-2............59113
//STRATOSAT TK-1...........57167
    if (   norad==46494 // Norbi 
        || norad==46276 // UPMSAT-2  
        || norad==43798 // ASTROCAST 0.1
        || norad==59114 || norad==59117 //ONDOSAT OWL 1 & 2
        || norad==62687 // HYPE
        || norad==57208 // RS52SD
        || norad==57181 || norad==58665 // Norby-2 -- MDQubeSAT-2 
        || norad==61745 || norad==61747 || norad==57191 //  Polytech
        || norad==56213 || norad==57180 || norad==57168 // -- -- ReshUCube-2
        || norad==53191 || norad==57202 || norad==57205 // -- -- RS52SE
        || norad==57186 || norad==57167 || norad==57169 // -- -- RS52SV
        || norad==57200 || norad==57170 // RS52SB -- RS52SG
        || norad==57183 // 2023-091T
        || norad==61750 //MTUSI-1
        || norad==61751 //VLADIVOSTOK
        || norad==58665 //MDQUBESAT 2
        || norad==61768 //HOD HOD 1-A
        || norad==57186 || norad==57202 || norad==61744 || norad==61775 || norad==61777 //CSPT
        || norad==99999 //VARIOS
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

bool Satellites::isValidSatelliteName(char name[25]){
    if (   strcmp(name,"Norbi")==0 
        //|| strcmp(name,"Norby-2")==0 
        //|| strcmp(name,"Polytech_Universe-3")==0 
        //|| strcmp(name,"Polytech_Universe-4")==0 
        //|| strcmp(name,"Polytech_Universe-5")==0 
        //|| strcmp(name,"CSTP-2.1")==0 || strcmp(name,"CSTP-2.2")==0 || strcmp(name,"CSTP-2.11")==0 
        //|| strcmp(name,"CSTP-1.1")==0 || strcmp(name,"CSTP-1.2")==0 
        //|| strcmp(name,"RS52SB")==0 || strcmp(name,"RS52SV")==0 || strcmp(name,"RS52SG")==0 
        //|| strcmp(name,"RS52SD")==0 || strcmp(name,"RS52SE")==0 
        //|| strcmp(name,"Vladivostok-1")==0 
        //|| strcmp(name,"Norby-3")==0 
        //|| strcmp(name,"MDQubeSAT-2")==0 
        //|| strcmp(name,"ReshUCube-2")==0 
        //|| strcmp(name,"MTUSI-1")==0 
        //|| strcmp(name,"HOD-HOD-1A")==0 
        || strcmp(name,"ONDOSAT-OWL-1")==0 
        || strcmp(name,"ONDOSAT-OWL-2")==0 
        || strcmp(name,"HYPE")==0 
        || strcmp(name,"PROMETHEUS-1")==0 
        || strcmp(name,"ASTROCAST 0.1")==0 
        || strcmp(name,"UPMSAT-2")==0 
        || strcmp(name,"StratoSat-TK1")==0 
        || strcmp(name,"TUSUR GO")==0 
        || strcmp(name,"Colibri-S")==0 
        || strcmp(name,"RTU MIREA1")==0 
        || strcmp(name,"HORIZON")==0 
        || strcmp(name,"VIZARD-ION")==0 
        || strcmp(name,"SAMSAT-IONOSPHERE")==0 
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
        || norad==46276 // UPMSAT-2 
        || norad==51658 // INS-2TD
        || norad==43798 // ASTROCAST 0.1
        || norad==59114 || norad==59117 //ONDOSAT OWL 1 & 2 
        || norad==62687 // HYPE
        //|| norad==57167 // StratoSat-TK1
        //|| norad==48082 // FEES 
        //|| norad==57169 // RS52SV
        //|| norad==57170 // RS52SG
        //|| norad==57200 // RS52SB
        //|| norad==57205 // RS52SE
        //|| norad==57208 // RS52SD
        //|| norad==57181 || norad==58665 || norad==57191 // MDQubeSAT-2 -- Polytech-3
        //|| norad==57202 || norad==57186   // CSPT 1&2
        //|| norad==57179 // Norby-2 --
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

bool Satellites::allowDistributeSatelliteNameData(char name[25]){
    if (   strcmp(name,"Norbi")==0 
        || strcmp(name,"ONDOSAT-OWL-1")==0 
        || strcmp(name,"ONDOSAT-OWL-2")==0 
        || strcmp(name,"HYPE")==0 
        || strcmp(name,"PROMETHEUS-1")==0 
        || strcmp(name,"ASTROCAST 0.1")==0 
        || strcmp(name,"UPMSAT-2")==0 
        || strcmp(name,"StratoSat-TK1")==0 
        //|| strcmp(name,"TUSUR GO")==0 
        || strcmp(name,"Colibri-S")==0 
        || strcmp(name,"RTU MIREA1")==0 
        //|| strcmp(name,"HORIZON")==0 
        //|| strcmp(name,"VIZARD-ION")==0 
        //|| strcmp(name,"RS52SB")==0 || strcmp(name,"RS52SV")==0 || strcmp(name,"RS52SG")==0 
        //|| strcmp(name,"RS52SD")==0 || strcmp(name,"RS52SE")==0 
        || strcmp(name,"SAMSAT-IONOSPHERE")==0         
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}
