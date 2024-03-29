/* Represents a generic submodule for a Teensy Unit in Series 3
 *
 * author: David Kadish (david.kadish@gmail.com)
 * created: Feb 13, 2016
 *
 */

#ifndef __SUBMODULE_H
#define __SUBMODULE_H

#include <map>

#include "device.h"

class SubNode {
    
    public:
        
        // Constructor
        SubNode(char port);
        
        virtual void init() = 0;
        virtual void loop() = 0;
        
        // 
        virtual void getDeviceList(char* devList) = 0;
        
        // Corresponding to the defined communcations protocol
        bool fade(int address, int target, int duration);
        int  read(int address, int preprocessType);
        
    protected:
        char _port;
        std::map<int,Device*> devices;
};

#endif
