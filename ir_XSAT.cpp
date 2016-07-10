#include "IRremote.h"
#include "IRremoteInt.h"

//==============================================================================
//
//
//                               XSAT                            
//
//
//==============================================================================

#define HDR_MARK    8000  // The length of the Header:Mark
#define HDR_SPACE   4000  // The lenght of the Header:Space

#define BIT_MARK    500  // The length of a Bit:Mark
#define ONE_SPACE   1500  // The length of a Bit:Space for 1's
#define ZERO_SPACE  500  // The length of a Bit:Space for 0's

#define MID_SPACE   4000 // The length of the space between adress and command
#define BYTE_END    500  // The length of the pulse after 8 bits


//+=============================================================================
//
#if SEND_XSAT
void  IRsend::sendXSAT (unsigned char address, unsigned char command)
{
  enableIROut(38);
  
  mark(HDR_MARK);
  space(HDR_SPACE);
  
  // Address
  int mask = 1;
  for (int i = 0; i < 8; ++i) {
    if (address & mask) {
      mark(BIT_MARK);
      space(ONE_SPACE);
    } else {
      mark(BIT_MARK);
      space(ZERO_SPACE);
    }
    mask <<= 1;
  }
  
  mark(BYTE_END);
  space(MID_SPACE);
  
  // Command
  mask = 1;
  for (int i = 0; i < 8; ++i) {
    if (command & mask) {
      mark(BIT_MARK);
      space(ONE_SPACE);
    } else {
      mark(BIT_MARK);
      space(ZERO_SPACE);
    }
    mask <<= 1;
  }
  
  mark(BYTE_END);
  space(0); // End with LED off
}
 
 
#endif

