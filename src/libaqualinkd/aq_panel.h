
#ifndef INIT_BUTTONS_H_
#define INIT_BUTTONS_H_

#include "aqualink.h"
#include "config.h"
#include "types/panel_buttons.h"

#define PUMP_INDEX      0
#define SPA_INDEX       1
/*
#define POOL_HEAT_INDEX 9
#define SPA_HEAT_INDEX  10
*/

//void initButtons(struct aqualinkdata *aqdata);
void setPanelByName(struct aqualinkdata *aqdata, const char *str);
void setPanel(struct aqualinkdata *aqdata, bool rs, int size, bool combo, bool dual);

void changePanelToMode_Only();
void addPanelOneTouchInterface();
void addPanelIAQTouchInterface();
void addPanelRSserialAdapterInterface();
void changePanelToExtendedIDProgramming();
//void panneltest();

int PANEL_SIZE(); 
//
//#define PANEL_SIZE PANEL_SIZE()
/*
#define PANEL_SIZE ((_aqconfig_.paneltype_mask & RSP_4) == RSP_4)?4:(\
                      ((_aqconfig_.paneltype_mask & RSP_6) == RSP_6)?6:(\
                       ((_aqconfig_.paneltype_mask & RSP_8) == RSP_8)?8:(\
                        ((_aqconfig_.paneltype_mask & RSP_10) == RSP_10)?10:(\
                         ((_aqconfig_.paneltype_mask & RSP_12) == RSP_12)?12:(\
                          ((_aqconfig_.paneltype_mask & RSP_14) == RSP_14)?14:(\
                           ((_aqconfig_.paneltype_mask & RSP_16) == RSP_16)?16:0))))))
*/

#endif
