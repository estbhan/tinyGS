/*
  Satellites.cpp - Satellites class
  
  Copyright (C) 2022 -2026 @estbhan

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

/* 
  Allow to track satellites will be controlled at Mqtt_Client
*/
bool Satellites::allowTrackSatelliteName(char name[25]){
    if (   strcmp(name,"Norbi")==0 
        || strcmp(name,"Norby-2")==0 
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
        || strcmp(name,"Geoscan-1")==0 
        || strcmp(name,"Geoscan-2")==0 
        || strcmp(name,"Geoscan-3")==0 
        || strcmp(name,"Geoscan-4")==0 
        || strcmp(name,"Geoscan-5")==0 
        || strcmp(name,"Geoscan-6")==0 
        || strcmp(name,"InnoSat3")==0 
        || strcmp(name,"InnoSat16")==0 
        || strcmp(name,"239Alferov")==0 
        || strcmp(name,"UMKA-1")==0 
        || strcmp(name,"INSPIRESAT-1")==0 
        || strcmp(name,"CUTE")==0 
        || strcmp(name,"BOTAN")==0 
        || strcmp(name,"ARTICSAT-1")==0 
        || strcmp(name,"LASARSAT")==0 
        || strcmp(name,"UWE-4")==0 
        || strcmp(name,"SPIRONE")==0 
        || strcmp(name,"CornellLightSail")==0 //CornellLightSail
        || strcmp(name,"Hunity")==0 //Hunity
        || strcmp(name,"CUBEBEL-2")==0
        || strcmp(name,"CROCUBE")==0
        || strcmp(name,"SNUGLITE-III")==0 
        || strcmp(name,"RSP-03")==0 
        || strcmp(name,"LILACSAT-2")==0 
        || strcmp(name,"GRBBETA")==0 
        || strcmp(name,"Norby-2_FSK")==0
        || strcmp(name,"SNUGLITE-III Duri")==0
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}

/* 
  Allow to distribute satellites will be controlled at Radio
*/
bool Satellites::allowDistributeSatelliteNameData(char name[25]){
    if (   strcmp(name,"Norbi")==0 
        || strcmp(name,"Norby-2")==0 
        || strcmp(name,"ONDOSAT-OWL-1")==0 
        || strcmp(name,"ONDOSAT-OWL-2")==0 
        || strcmp(name,"HYPE")==0 
        || strcmp(name,"PROMETHEUS-1")==0 
        || strcmp(name,"ASTROCAST 0.1")==0 
        || strcmp(name,"UPMSAT-2")==0 
        || strcmp(name,"StratoSat-TK1")==0 
        || strcmp(name,"Colibri-S")==0 
        || strcmp(name,"RTU MIREA1")==0 
        || strcmp(name,"SAMSAT-IONOSPHERE")==0         
        || strcmp(name,"239Alferov")==0 
        || strcmp(name,"UMKA-1")==0 
        || strcmp(name,"BOTAN")==0 
        || strcmp(name,"ARTICSAT-1")==0 
        || strcmp(name,"LASARSAT")==0 
        || strcmp(name,"UWE-4")==0 
        || strcmp(name,"SPIRONE")==0 
        || strcmp(name,"CornellLightSail")==0 //CornellLightSail
        || strcmp(name,"Hunity")==0 //Hunity
        || strcmp(name,"CUBEBEL-2")==0
        || strcmp(name,"Norby-2_FSK")==0
        || strcmp(name,"SNUGLITE-III Duri")==0
        
        )
        {
          return true;
        } else { //Filtro de satélites
          return false;
        }
}