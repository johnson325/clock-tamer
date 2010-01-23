/*
        ClockTamer - a software for configurable reference clock
                  Copyright (C) 2009, Fairwaves
          by Sergey Kostanbaev <Sergey.Kostanbaev@fairwaves.ru>
*/

/*
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#include "Tamer.h"
#include "TamerBoard.h"

#define INCLUDE_FROM_TAMER_HWISTR_H
#include "TamerControl.h"



#ifndef HWISTR_CUSTOM

#ifdef LMX2531_TYPE
#define HWISTR_LMX		"LMX=" STRINGIFY(LMX2531_TYPE) " "
#else
#define HWISTR_LMX
#endif

#ifdef LMK_TYPE
#define HWISTR_LMK		"LMK=" STRINGIFY(LMK_TYPE) " "
#else
#define HWISTR_LMK
#endif

#define HWISTR_OSC      "OSC=" STRINGIFY(TAMER_OSC) " "

#ifdef PRESENT_DAC12
#define HWISTR_DAC		"VCTXCO "
#else
#define HWISTR_DAC
#endif

#ifdef PRESENT_GPS
#define HWISTR_GPS		"GPS "
#else
#define HWISTR_GPS
#endif


#define HWISTR    		HWISTR_LMX HWISTR_LMK HWISTR_OSC HWISTR_DAC HWISTR_GPS

#else

#define HWISTR			STRINGIFY(HWISTR_CUSTOM)

#endif




#ifndef HWISTR
#   error "HWISTR macro must be defined!"
#endif
char    eeHWInfo[] HWIEEMEM  = HWISTR;



