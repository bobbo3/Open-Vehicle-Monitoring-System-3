/*
;    Project:       Open Vehicle Monitor System
;    Date:          14th March 2017
;
;    Changes:
;    1.0  Initial release
;
;    (C) 2011       Michael Stegen / Stegen Electronics
;    (C) 2011-2017  Mark Webb-Johnson
;    (C) 2011        Sonny Chen @ EPRO/DX
;
; Permission is hereby granted, free of charge, to any person obtaining a copy
; of this software and associated documentation files (the "Software"), to deal
; in the Software without restriction, including without limitation the rights
; to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
; copies of the Software, and to permit persons to whom the Software is
; furnished to do so, subject to the following conditions:
;
; The above copyright notice and this permission notice shall be included in
; all copies or substantial portions of the Software.
;
; THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
; IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
; FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
; AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
; LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
; OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
; THE SOFTWARE.
*/

#include "esp_log.h"
static const char *TAG = "script";

#include <string.h>
#include <stdio.h>
#include "ovms_script.h"
#include "ovms_command.h"

OvmsScripts MyScripts __attribute__ ((init_priority (1600)));

OvmsScripts::OvmsScripts()
  {
  ESP_LOGI(TAG, "Initialising SCRIPTS (1600)");
#ifdef CONFIG_OVMS_SC_JAVASCRIPT_NONE
  ESP_LOGI(TAG, "No javascript engines enabled (command scripting only)");
#endif //#ifdef CONFIG_OVMS_SC_JAVASCRIPT_NONE
#ifdef CONFIG_OVMS_SC_JAVASCRIPT_DUKTAPE
  ESP_LOGI(TAG, "Using DUKTAPE javascript engine");
#endif //#ifdef CONFIG_OVMS_SC_JAVASCRIPT_DUKTAPE
#ifdef CONFIG_OVMS_SC_JAVASCRIPT_MJS
  ESP_LOGI(TAG, "Using MJS javascript engine");
#endif //#ifdef CONFIG_OVMS_SC_JAVASCRIPT_MJS
  }

OvmsScripts::~OvmsScripts()
  {
  }
