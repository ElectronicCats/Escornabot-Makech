// CatNINAInterface.h
/*

Copyright (C) 2014-2019 Escornabot - http://escornabot.com

Andrés Sabas @ Electronic Cats

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301,
USA.

See LICENSE.txt for details

*/

#ifndef _CATNINA_INTERFACE_H
#define _CATNINA_INTERFACE_H

#include "ButtonSet.h"
#include <String.h>
#include "EventListener.h"
#include <Arduino.h>

//#define COMMAND_MAX_LENGTH 10

/**
 * \brief Interface to use a CatNINA BLE and WiFi module over SPI interface
 * \author @sabasacustico
 */
class CatNINAInterface : public ButtonSet
{
public:

    typedef struct {  
    } Config;

    /**
     * Constructor.
     */
    CatNINAInterface(const Config* cfg);

    ////////////////////////////////////////////////////////////
    // ButtonSet interface
    ////////////////////////////////////////////////////////////

    /**
     * Does the hardware initialization.
     */
    virtual void init();

    /**
     * Reads the buttons
     * @return The button being pressed.
     */
    virtual void scanButtons();

    ////////////////////////////////////////////////////////////
    // EventListener interface
    ////////////////////////////////////////////////////////////

    /**
     * Handles when a movement from the program was executed.
     */
    virtual void MoveExecuting(MOVE move);

    /**
     * Handles when a movement from the program was executed.
     */
    virtual void MoveExecuted(MOVE move);

    /**
     * Handles when a new movement was added to the program.
     */
    virtual void MoveAdded(MOVE move);

    /**
     * Handles when the program has stated.
     */
    virtual void ProgramStarted(uint8_t total_moves);

    /**
     * Handles when the program has finished.
     */
    virtual void ProgramFinished();

    /**
     * Handles when the program has reset.
     */
    virtual void ProgramReset();

    /**
     * Handles when the program was aborted.
     */
    virtual void ProgramAborted(uint8_t executed, uint8_t total);

private:

    const Config* _config;

    uint8_t _command_idx;

    bool _readLine();

};

#endif // _CATNINA_INTERFACE_H

// EOF
