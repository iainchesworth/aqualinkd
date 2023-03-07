#ifndef PANEL_BUTTONS_H_
#define PANEL_BUTTONS_H_

// Defined as int16_t so 16 bits to mask
#define RSP_4      (1 << 0) // 1
#define RSP_6      (1 << 1) // 16
#define RSP_8      (1 << 2) // 4
#define RSP_10     (1 << 3) // 2
#define RSP_12     (1 << 4) // 32
#define RSP_14     (1 << 5) // 8
#define RSP_16     (1 << 6) // 64
#define RSP_COMBO  (1 << 7) // 128
#define RSP_SINGLE (1 << 8) // 128
#define RSP_DUAL_EQPT (1 << 9) // 128
#define RSP_RS     (1 << 10) // 128
#define RSP_PDA    (1 << 11) // 128
#define RSP_ONET   (1 << 12) // 128
#define RSP_IAQT   (1 << 13) // 128
#define RSP_RSSA   (1 << 14) // 128
#define RSP_EXT_PROG (1 << 15) // 128

#define isPDA_PANEL ((_aqconfig_.paneltype_mask & RSP_PDA) == RSP_PDA)
#define isRS_PANEL ((_aqconfig_.paneltype_mask & RSP_RS) == RSP_RS)
#define isCOMBO_PANEL ((_aqconfig_.paneltype_mask & RSP_COMBO) == RSP_COMBO)
#define isSINGLE_DEV_PANEL ((_aqconfig_.paneltype_mask & RSP_SINGLE) == RSP_SINGLE)
#define isDUAL_EQPT_PANEL ((_aqconfig_.paneltype_mask & RSP_DUAL_EQPT) == RSP_DUAL_EQPT)
#define isONET_ENABLED ((_aqconfig_.paneltype_mask & RSP_ONET) == RSP_ONET)
#define isIAQT_ENABLED ((_aqconfig_.paneltype_mask & RSP_IAQT) == RSP_IAQT)
#define isRSSA_ENABLED ((_aqconfig_.paneltype_mask & RSP_RSSA) == RSP_RSSA)
#define isEXTP_ENABLED ((_aqconfig_.paneltype_mask & RSP_EXT_PROG) == RSP_EXT_PROG)

#ifndef AQ_RS16
#define TOTAL_BUTTONS 12
#else
#define TOTAL_BUTTONS 20
#endif

#endif // PANEL_BUTTONS_H_
