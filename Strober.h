/*******************************************************************************
* Copyright (c) 2018 Elhay Rauper
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted (subject to the limitations in the disclaimer
* below) provided that the following conditions are met:
*
*     * Redistributions of source code must retain the above copyright notice,
*     this list of conditions and the following disclaimer.
*
*     * Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*
*     * Neither the name of the copyright holder nor the names of its
*     contributors may be used to endorse or promote products derived from this
*     software without specific prior written permission.
*
* NO EXPRESS OR IMPLIED LICENSES TO ANY PARTY'S PATENT RIGHTS ARE GRANTED BY
* THIS LICENSE. THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND
* CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
* CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
* EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
* IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/

#ifndef LED_H
#define LED_H

#include "SandTimer.h"

class Strober
{

public:
  enum Notes 
  {
    BLINK_FAST,
    BLINK_SLOW,
    STROBE
  };
  Strober(uint16_t pin);
  void play();
  void setNotes(uint16_t* notes, size_t notes_size);
  void setNotes(Notes notes);
  void reset();

  const static size_t SLOW_BLINK_SIZE = 4;
  const static size_t FAST_BLINK_SIZE = 4;
  const static size_t STROBE_BLINK_SIZE = 12;

private:
  SandTimer timer_;
  int16_t pin_;
  uint16_t* notes_;
  size_t notes_size_ = 0;
  uint16_t index_ = 0;
  Notes curr_notes_;

  const static uint16_t SLOW_BLINK_ARR[SLOW_BLINK_SIZE];
  const static uint16_t FAST_BLINK_ARR[FAST_BLINK_SIZE];
  const static uint16_t STROBE_BLINK_ARR[STROBE_BLINK_SIZE];

  
};
#endif
