
/*
 * pic18f248.h - 18F248 Device Library Header
 *
 * This file is part of the GNU PIC Library.
 *
 * January, 2004
 * The GNU PIC Library is maintained by,
 * 	Vangelis Rokas <vrokas@otenet.gr>
 *
 * $Id$
 *
 */

#ifndef __PIC18F248_H__
#define __PIC18F248_H__

extern sfr at 0xf00 RXF0SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF0SIDHbits_t;

extern volatile RXF0SIDHbits_t at 0xf00 RXF0SIDHbits;

extern sfr at 0xf01 RXF0SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF0SIDLbits_t;

extern volatile RXF0SIDLbits_t at 0xf01 RXF0SIDLbits;

extern sfr at 0xf02 RXF0EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF0EIDHbits_t;

extern volatile RXF0EIDHbits_t at 0xf02 RXF0EIDHbits;

extern sfr at 0xf03 RXF0EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF0EIDLbits_t;

extern volatile RXF0EIDLbits_t at 0xf03 RXF0EIDLbits;

extern sfr at 0xf04 RXF1SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF1SIDHbits_t;

extern volatile RXF1SIDHbits_t at 0xf04 RXF1SIDHbits;

extern sfr at 0xf05 RXF1SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF1SIDLbits_t;

extern volatile RXF1SIDLbits_t at 0xf05 RXF1SIDLbits;

extern sfr at 0xf06 RXF1EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF1EIDHbits_t;

extern volatile RXF1EIDHbits_t at 0xf06 RXF1EIDHbits;

extern sfr at 0xf07 RXF1EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF1EIDLbits_t;

extern volatile RXF1EIDLbits_t at 0xf07 RXF1EIDLbits;

extern sfr at 0xf08 RXF2SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF2SIDHbits_t;

extern volatile RXF2SIDHbits_t at 0xf08 RXF2SIDHbits;

extern sfr at 0xf09 RXF2SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF2SIDLbits_t;

extern volatile RXF2SIDLbits_t at 0xf09 RXF2SIDLbits;

extern sfr at 0xf0a RXF2EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF2EIDHbits_t;

extern volatile RXF2EIDHbits_t at 0xf0a RXF2EIDHbits;

extern sfr at 0xf0b RXF2EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF2EIDLbits_t;

extern volatile RXF2EIDLbits_t at 0xf0b RXF2EIDLbits;

extern sfr at 0xf0c RXF3SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF3SIDHbits_t;

extern volatile RXF3SIDHbits_t at 0xf0c RXF3SIDHbits;

extern sfr at 0xf0d RXF3SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF3SIDLbits_t;

extern volatile RXF3SIDLbits_t at 0xf0d RXF3SIDLbits;

extern sfr at 0xf0e RXF3EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF3EIDHbits_t;

extern volatile RXF3EIDHbits_t at 0xf0e RXF3EIDHbits;

extern sfr at 0xf0f RXF3EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF3EIDLbits_t;

extern volatile RXF3EIDLbits_t at 0xf0f RXF3EIDLbits;

extern sfr at 0xf10 RXF4SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF4SIDHbits_t;

extern volatile RXF4SIDHbits_t at 0xf10 RXF4SIDHbits;

extern sfr at 0xf11 RXF4SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF4SIDLbits_t;

extern volatile RXF4SIDLbits_t at 0xf11 RXF4SIDLbits;

extern sfr at 0xf12 RXF4EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF4EIDHbits_t;

extern volatile RXF4EIDHbits_t at 0xf12 RXF4EIDHbits;

extern sfr at 0xf13 RXF4EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF4EIDLbits_t;

extern volatile RXF4EIDLbits_t at 0xf13 RXF4EIDLbits;

extern sfr at 0xf14 RXF5SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXF5SIDHbits_t;

extern volatile RXF5SIDHbits_t at 0xf14 RXF5SIDHbits;

extern sfr at 0xf15 RXF5SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXF5SIDLbits_t;

extern volatile RXF5SIDLbits_t at 0xf15 RXF5SIDLbits;

extern sfr at 0xf16 RXF5EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXF5EIDHbits_t;

extern volatile RXF5EIDHbits_t at 0xf16 RXF5EIDHbits;

extern sfr at 0xf17 RXF5EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXF5EIDLbits_t;

extern volatile RXF5EIDLbits_t at 0xf17 RXF5EIDLbits;

extern sfr at 0xf18 RXM0SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXM0SIDHbits_t;

extern volatile RXM0SIDHbits_t at 0xf18 RXM0SIDHbits;

extern sfr at 0xf19 RXM0SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXM0SIDLbits_t;

extern volatile RXM0SIDLbits_t at 0xf19 RXM0SIDLbits;

extern sfr at 0xf1a RXM0EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXM0EIDHbits_t;

extern volatile RXM0EIDHbits_t at 0xf1a RXM0EIDHbits;

extern sfr at 0xf1b RXM0EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXM0EIDLbits_t;

extern volatile RXM0EIDLbits_t at 0xf1b RXM0EIDLbits;

extern sfr at 0xf1c RXM1SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXM1SIDHbits_t;

extern volatile RXM1SIDHbits_t at 0xf1c RXM1SIDHbits;

extern sfr at 0xf1d RXM1SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDEN:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXM1SIDLbits_t;

extern volatile RXM1SIDLbits_t at 0xf1d RXM1SIDLbits;

extern sfr at 0xf1e RXM1EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXM1EIDHbits_t;

extern volatile RXM1EIDHbits_t at 0xf1e RXM1EIDHbits;

extern sfr at 0xf1f RXM1EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXM1EIDLbits_t;

extern volatile RXM1EIDLbits_t at 0xf1f RXM1EIDLbits;

extern sfr at 0xf20 TXB2CON;
typedef union {
	struct {
		unsigned TXPRI0:1;
		unsigned TXPRI1:1;
		unsigned :1;
		unsigned TXREQ:1;
		unsigned TXERR:1;
		unsigned TXLARB:1;
		unsigned TXABT:1;
		unsigned :1;
	};
} TXB2CONbits_t;

extern volatile TXB2CONbits_t at 0xf20 TXB2CONbits;

extern sfr at 0xf21 TXB2SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} TXB2SIDHbits_t;

extern volatile TXB2SIDHbits_t at 0xf21 TXB2SIDHbits;

extern sfr at 0xf22 TXB2SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDEN:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} TXB2SIDLbits_t;

extern volatile TXB2SIDLbits_t at 0xf22 TXB2SIDLbits;

extern sfr at 0xf23 TXB2EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} TXB2EIDHbits_t;

extern volatile TXB2EIDHbits_t at 0xf23 TXB2EIDHbits;

extern sfr at 0xf24 TXB2EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} TXB2EIDLbits_t;

extern volatile TXB2EIDLbits_t at 0xf24 TXB2EIDLbits;

extern sfr at 0xf25 TXB2DLC;
typedef union {
	struct {
		unsigned TXB2DLC0:1;
		unsigned TXB2DLC1:1;
		unsigned TXB2DLC2:1;
		unsigned TXB2DLC3:1;
		unsigned :1;
		unsigned :1;
		unsigned TXB2TXRTR:1;
		unsigned :1;
	};
} TXB2DLCbits_t;

extern volatile TXB2DLCbits_t at 0xf25 TXB2DLCbits;

extern sfr at 0xf26 TXB2D0;
typedef union {
	struct {
		unsigned TXB2D00:1;
		unsigned TXB2D01:1;
		unsigned TXB2D02:1;
		unsigned TXB2D03:1;
		unsigned TXB2D04:1;
		unsigned TXB2D05:1;
		unsigned TXB2D06:1;
		unsigned TXB2D07:1;
	};
} TXB2D0bits_t;

extern volatile TXB2D0bits_t at 0xf26 TXB2D0bits;

extern sfr at 0xf27 TXB2D1;
typedef union {
	struct {
		unsigned TXB2D10:1;
		unsigned TXB2D11:1;
		unsigned TXB2D12:1;
		unsigned TXB2D13:1;
		unsigned TXB2D14:1;
		unsigned TXB2D15:1;
		unsigned TXB2D16:1;
		unsigned TXB2D17:1;
	};
} TXB2D1bits_t;

extern volatile TXB2D1bits_t at 0xf27 TXB2D1bits;

extern sfr at 0xf28 TXB2D2;
typedef union {
	struct {
		unsigned TXB2D20:1;
		unsigned TXB2D21:1;
		unsigned TXB2D22:1;
		unsigned TXB2D23:1;
		unsigned TXB2D24:1;
		unsigned TXB2D25:1;
		unsigned TXB2D26:1;
		unsigned TXB2D27:1;
	};
} TXB2D2bits_t;

extern volatile TXB2D2bits_t at 0xf28 TXB2D2bits;

extern sfr at 0xf29 TXB2D3;
typedef union {
	struct {
		unsigned TXB2D30:1;
		unsigned TXB2D31:1;
		unsigned TXB2D32:1;
		unsigned TXB2D33:1;
		unsigned TXB2D34:1;
		unsigned TXB2D35:1;
		unsigned TXB2D36:1;
		unsigned TXB2D37:1;
	};
} TXB2D3bits_t;

extern volatile TXB2D3bits_t at 0xf29 TXB2D3bits;

extern sfr at 0xf2a TXB2D4;
typedef union {
	struct {
		unsigned TXB2D40:1;
		unsigned TXB2D41:1;
		unsigned TXB2D42:1;
		unsigned TXB2D43:1;
		unsigned TXB2D44:1;
		unsigned TXB2D45:1;
		unsigned TXB2D46:1;
		unsigned TXB2D47:1;
	};
} TXB2D4bits_t;

extern volatile TXB2D4bits_t at 0xf2a TXB2D4bits;

extern sfr at 0xf2b TXB2D5;
typedef union {
	struct {
		unsigned TXB2D50:1;
		unsigned TXB2D51:1;
		unsigned TXB2D52:1;
		unsigned TXB2D53:1;
		unsigned TXB2D54:1;
		unsigned TXB2D55:1;
		unsigned TXB2D56:1;
		unsigned TXB2D57:1;
	};
} TXB2D5bits_t;

extern volatile TXB2D5bits_t at 0xf2b TXB2D5bits;

extern sfr at 0xf2c TXB2D6;
typedef union {
	struct {
		unsigned TXB2D60:1;
		unsigned TXB2D61:1;
		unsigned TXB2D62:1;
		unsigned TXB2D63:1;
		unsigned TXB2D64:1;
		unsigned TXB2D65:1;
		unsigned TXB2D66:1;
		unsigned TXB2D67:1;
	};
} TXB2D6bits_t;

extern volatile TXB2D6bits_t at 0xf2c TXB2D6bits;

extern sfr at 0xf2d TXB2D7;
typedef union {
	struct {
		unsigned TXB2D70:1;
		unsigned TXB2D71:1;
		unsigned TXB2D72:1;
		unsigned TXB2D73:1;
		unsigned TXB2D74:1;
		unsigned TXB2D75:1;
		unsigned TXB2D76:1;
		unsigned TXB2D77:1;
	};
} TXB2D7bits_t;

extern volatile TXB2D7bits_t at 0xf2d TXB2D7bits;

extern sfr at 0xf2e CANSTATRO4;
typedef union {
	struct {
		unsigned :1;
		unsigned ICODE0:1;
		unsigned ICODE1:1;
		unsigned ICODE2:1;
		unsigned :1;
		unsigned OPMODE0:1;
		unsigned OPMODE1:1;
		unsigned OPMODE2:1;
	};
} CANSTATRO4bits_t;

extern volatile CANSTATRO4bits_t at 0xf2e CANSTATRO4bits;

extern sfr at 0xf30 TXB1CON;
typedef union {
	struct {
		unsigned TXPRI0:1;
		unsigned TXPRI1:1;
		unsigned :1;
		unsigned TXREQ:1;
		unsigned TXERR:1;
		unsigned TXLARB:1;
		unsigned TXABT:1;
		unsigned :1;
	};
} TXB1CONbits_t;

extern volatile TXB1CONbits_t at 0xf30 TXB1CONbits;

extern sfr at 0xf31 TXB1SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} TXB1SIDHbits_t;

extern volatile TXB1SIDHbits_t at 0xf31 TXB1SIDHbits;

extern sfr at 0xf32 TXB1SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} TXB1SIDLbits_t;

extern volatile TXB1SIDLbits_t at 0xf32 TXB1SIDLbits;

extern sfr at 0xf33 TXB1EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} TXB1EIDHbits_t;

extern volatile TXB1EIDHbits_t at 0xf33 TXB1EIDHbits;

extern sfr at 0xf34 TXB1EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} TXB1EIDLbits_t;

extern volatile TXB1EIDLbits_t at 0xf34 TXB1EIDLbits;

extern sfr at 0xf35 TXB1DLC;
typedef union {
	struct {
		unsigned DLC0:1;
		unsigned DLC1:1;
		unsigned DLC2:1;
		unsigned DLC3:1;
		unsigned :1;
		unsigned :1;
		unsigned TXRTR:1;
		unsigned :1;
	};
} TXB1DLCbits_t;

extern volatile TXB1DLCbits_t at 0xf35 TXB1DLCbits;

extern sfr at 0xf36 TXB1D0;
typedef union {
	struct {
		unsigned TXB1D00:1;
		unsigned TXB1D01:1;
		unsigned TXB1D02:1;
		unsigned TXB1D03:1;
		unsigned TXB1D04:1;
		unsigned TXB1D05:1;
		unsigned TXB1D06:1;
		unsigned TXB1D07:1;
	};
} TXB1D0bits_t;

extern volatile TXB1D0bits_t at 0xf36 TXB1D0bits;

extern sfr at 0xf37 TXB1D1;
typedef union {
	struct {
		unsigned TXB1D10:1;
		unsigned TXB1D11:1;
		unsigned TXB1D12:1;
		unsigned TXB1D13:1;
		unsigned TXB1D14:1;
		unsigned TXB1D15:1;
		unsigned TXB1D16:1;
		unsigned TXB1D17:1;
	};
} TXB1D1bits_t;

extern volatile TXB1D1bits_t at 0xf37 TXB1D1bits;

extern sfr at 0xf38 TXB1D2;
typedef union {
	struct {
		unsigned TXB1D20:1;
		unsigned TXB1D21:1;
		unsigned TXB1D22:1;
		unsigned TXB1D23:1;
		unsigned TXB1D24:1;
		unsigned TXB1D25:1;
		unsigned TXB1D26:1;
		unsigned TXB1D27:1;
	};
} TXB1D2bits_t;

extern volatile TXB1D2bits_t at 0xf38 TXB1D2bits;

extern sfr at 0xf39 TXB1D3;
typedef union {
	struct {
		unsigned TXB1D30:1;
		unsigned TXB1D31:1;
		unsigned TXB1D32:1;
		unsigned TXB1D33:1;
		unsigned TXB1D34:1;
		unsigned TXB1D35:1;
		unsigned TXB1D36:1;
		unsigned TXB1D37:1;
	};
} TXB1D3bits_t;

extern volatile TXB1D3bits_t at 0xf39 TXB1D3bits;

extern sfr at 0xf3a TXB1D4;
typedef union {
	struct {
		unsigned TXB1D40:1;
		unsigned TXB1D41:1;
		unsigned TXB1D42:1;
		unsigned TXB1D43:1;
		unsigned TXB1D44:1;
		unsigned TXB1D45:1;
		unsigned TXB1D46:1;
		unsigned TXB1D47:1;
	};
} TXB1D4bits_t;

extern volatile TXB1D4bits_t at 0xf3a TXB1D4bits;

extern sfr at 0xf3b TXB1D5;
typedef union {
	struct {
		unsigned TXB1D50:1;
		unsigned TXB1D51:1;
		unsigned TXB1D52:1;
		unsigned TXB1D53:1;
		unsigned TXB1D54:1;
		unsigned TXB1D55:1;
		unsigned TXB1D56:1;
		unsigned TXB1D57:1;
	};
} TXB1D5bits_t;

extern volatile TXB1D5bits_t at 0xf3b TXB1D5bits;

extern sfr at 0xf3c TXB1D6;
typedef union {
	struct {
		unsigned TXB1D60:1;
		unsigned TXB1D61:1;
		unsigned TXB1D62:1;
		unsigned TXB1D63:1;
		unsigned TXB1D64:1;
		unsigned TXB1D65:1;
		unsigned TXB1D66:1;
		unsigned TXB1D67:1;
	};
} TXB1D6bits_t;

extern volatile TXB1D6bits_t at 0xf3c TXB1D6bits;

extern sfr at 0xf3d TXB1D7;
typedef union {
	struct {
		unsigned TXB1D70:1;
		unsigned TXB1D71:1;
		unsigned TXB1D72:1;
		unsigned TXB1D73:1;
		unsigned TXB1D74:1;
		unsigned TXB1D75:1;
		unsigned TXB1D76:1;
		unsigned TXB1D77:1;
	};
} TXB1D7bits_t;

extern volatile TXB1D7bits_t at 0xf3d TXB1D7bits;

extern sfr at 0xf3e CANSTATRO3;
typedef union {
	struct {
		unsigned :1;
		unsigned ICODE0:1;
		unsigned ICODE1:1;
		unsigned ICODE2:1;
		unsigned :1;
		unsigned OPMODE0:1;
		unsigned OPMODE1:1;
		unsigned OPMODE2:1;
	};
} CANSTATRO3bits_t;

extern volatile CANSTATRO3bits_t at 0xf3e CANSTATRO3bits;

extern sfr at 0xf40 TXB0CON;
typedef union {
	struct {
		unsigned TXPRI0:1;
		unsigned TXPRI1:1;
		unsigned :1;
		unsigned TXREQ:1;
		unsigned TXERR:1;
		unsigned TXLARB:1;
		unsigned TXABT:1;
		unsigned :1;
	};
} TXB0CONbits_t;

extern volatile TXB0CONbits_t at 0xf40 TXB0CONbits;

extern sfr at 0xf41 TXB0SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} TXB0SIDHbits_t;

extern volatile TXB0SIDHbits_t at 0xf41 TXB0SIDHbits;

extern sfr at 0xf42 TXB0SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned :1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} TXB0SIDLbits_t;

extern volatile TXB0SIDLbits_t at 0xf42 TXB0SIDLbits;

extern sfr at 0xf43 TXB0EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} TXB0EIDHbits_t;

extern volatile TXB0EIDHbits_t at 0xf43 TXB0EIDHbits;

extern sfr at 0xf44 TXB0EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} TXB0EIDLbits_t;

extern volatile TXB0EIDLbits_t at 0xf44 TXB0EIDLbits;

extern sfr at 0xf45 TXB0DLC;
typedef union {
	struct {
		unsigned DLC0:1;
		unsigned DLC1:1;
		unsigned DLC2:1;
		unsigned DLC3:1;
		unsigned :1;
		unsigned :1;
		unsigned TXRTR:1;
		unsigned :1;
	};
} TXB0DLCbits_t;

extern volatile TXB0DLCbits_t at 0xf45 TXB0DLCbits;

extern sfr at 0xf46 TXB0D0;
typedef union {
	struct {
		unsigned TXB0D00:1;
		unsigned TXB0D01:1;
		unsigned TXB0D02:1;
		unsigned TXB0D03:1;
		unsigned TXB0D04:1;
		unsigned TXB0D05:1;
		unsigned TXB0D06:1;
		unsigned TXB0D07:1;
	};
} TXB0D0bits_t;

extern volatile TXB0D0bits_t at 0xf46 TXB0D0bits;

extern sfr at 0xf47 TXB0D1;
typedef union {
	struct {
		unsigned TXB0D10:1;
		unsigned TXB0D11:1;
		unsigned TXB0D12:1;
		unsigned TXB0D13:1;
		unsigned TXB0D14:1;
		unsigned TXB0D15:1;
		unsigned TXB0D16:1;
		unsigned TXB0D17:1;
	};
} TXB0D1bits_t;

extern volatile TXB0D1bits_t at 0xf47 TXB0D1bits;

extern sfr at 0xf48 TXB0D2;
typedef union {
	struct {
		unsigned TXB0D20:1;
		unsigned TXB0D21:1;
		unsigned TXB0D22:1;
		unsigned TXB0D23:1;
		unsigned TXB0D24:1;
		unsigned TXB0D25:1;
		unsigned TXB0D26:1;
		unsigned TXB0D27:1;
	};
} TXB0D2bits_t;

extern volatile TXB0D2bits_t at 0xf48 TXB0D2bits;

extern sfr at 0xf49 TXB0D3;
typedef union {
	struct {
		unsigned TXB0D30:1;
		unsigned TXB0D31:1;
		unsigned TXB0D32:1;
		unsigned TXB0D33:1;
		unsigned TXB0D34:1;
		unsigned TXBD035:1;
		unsigned TXBD0D36:1;
		unsigned TXB0D37:1;
	};
} TXB0D3bits_t;

extern volatile TXB0D3bits_t at 0xf49 TXB0D3bits;

extern sfr at 0xf4a TXB0D4;
typedef union {
	struct {
		unsigned TXB0D40:1;
		unsigned TXB0D41:1;
		unsigned TXB0D42:1;
		unsigned TXB0D43:1;
		unsigned TXB0D44:1;
		unsigned TXB0D45:1;
		unsigned TXB0D46:1;
		unsigned TXB0D47:1;
	};
} TXB0D4bits_t;

extern volatile TXB0D4bits_t at 0xf4a TXB0D4bits;

extern sfr at 0xf4b TXB0D5;
typedef union {
	struct {
		unsigned TXB0D50:1;
		unsigned TXB0D51:1;
		unsigned TXB0D52:1;
		unsigned TXB0D53:1;
		unsigned TXB0D54:1;
		unsigned TXB0D55:1;
		unsigned TXB0D56:1;
		unsigned TXB0D57:1;
	};
} TXB0D5bits_t;

extern volatile TXB0D5bits_t at 0xf4b TXB0D5bits;

extern sfr at 0xf4c TXB0D6;
typedef union {
	struct {
		unsigned TXB0D60:1;
		unsigned TXB0D61:1;
		unsigned TXB0D62:1;
		unsigned TXB0D63:1;
		unsigned TXB0D64:1;
		unsigned TXB0D65:1;
		unsigned TXB0D66:1;
		unsigned TXB0D67:1;
	};
} TXB0D6bits_t;

extern volatile TXB0D6bits_t at 0xf4c TXB0D6bits;

extern sfr at 0xf4d TXB0D7;
typedef union {
	struct {
		unsigned TXB0D70:1;
		unsigned TXB0D71:1;
		unsigned TXB0D72:1;
		unsigned TXB0D73:1;
		unsigned TXB0D74:1;
		unsigned TXB0D75:1;
		unsigned TXB0D76:1;
		unsigned TXB0D77:1;
	};
} TXB0D7bits_t;

extern volatile TXB0D7bits_t at 0xf4d TXB0D7bits;

extern sfr at 0xf4e CANSTATRO2;
typedef union {
	struct {
		unsigned :1;
		unsigned ICODE0:1;
		unsigned ICODE1:1;
		unsigned ICODE2:1;
		unsigned :1;
		unsigned OPMODE0:1;
		unsigned OPMODE1:1;
		unsigned OPMODE2:1;
	};
} CANSTATRO2bits_t;

extern volatile CANSTATRO2bits_t at 0xf4e CANSTATRO2bits;

extern sfr at 0xf50 RXB1CON;
typedef union {
	struct {
		unsigned FILHIT0:1;
		unsigned FILHIT1:1;
		unsigned FILHIT2:1;
		unsigned RXRTRRO:1;
		unsigned :1;
		unsigned RXM0:1;
		unsigned RXM1:1;
		unsigned RXFUL:1;
	};
} RXB1CONbits_t;

extern volatile RXB1CONbits_t at 0xf50 RXB1CONbits;

extern sfr at 0xf51 RXB1SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXB1SIDHbits_t;

extern volatile RXB1SIDHbits_t at 0xf51 RXB1SIDHbits;

extern sfr at 0xf52 RXB1SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXIDE:1;
		unsigned SRR:1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXB1SIDLbits_t;

extern volatile RXB1SIDLbits_t at 0xf52 RXB1SIDLbits;

extern sfr at 0xf53 RXB1EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EID9:1;
		unsigned EID10:1;
		unsigned EID11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXB1EIDHbits_t;

extern volatile RXB1EIDHbits_t at 0xf53 RXB1EIDHbits;

extern sfr at 0xf54 RXB1EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXB1EIDLbits_t;

extern volatile RXB1EIDLbits_t at 0xf54 RXB1EIDLbits;

extern sfr at 0xf55 RXB1DLC;
typedef union {
	struct {
		unsigned DLC0:1;
		unsigned DLC1:1;
		unsigned DLC2:1;
		unsigned DLC3:1;
		unsigned RESB0:1;
		unsigned RESB1:1;
		unsigned RXRTR:1;
		unsigned :1;
	};
} RXB1DLCbits_t;

extern volatile RXB1DLCbits_t at 0xf55 RXB1DLCbits;

extern sfr at 0xf56 RXB1D0;
typedef union {
	struct {
		unsigned RXB1D00:1;
		unsigned RXB1D01:1;
		unsigned RXB1D02:1;
		unsigned RXB1D03:1;
		unsigned RXB1D04:1;
		unsigned RXB1D05:1;
		unsigned RXB1D06:1;
		unsigned RXB1D07:1;
	};
} RXB1D0bits_t;

extern volatile RXB1D0bits_t at 0xf56 RXB1D0bits;

extern sfr at 0xf57 RXB1D1;
typedef union {
	struct {
		unsigned RXB1D10:1;
		unsigned RXB1D11:1;
		unsigned RXB1D12:1;
		unsigned RXB1D13:1;
		unsigned RXB1D14:1;
		unsigned RXB1D15:1;
		unsigned RXB1D16:1;
		unsigned RXB1D17:1;
	};
} RXB1D1bits_t;

extern volatile RXB1D1bits_t at 0xf57 RXB1D1bits;

extern sfr at 0xf58 RXB1D2;
typedef union {
	struct {
		unsigned RXB1D20:1;
		unsigned RXB1D21:1;
		unsigned RXB1D22:1;
		unsigned RXB1D23:1;
		unsigned RXB1D24:1;
		unsigned RXB1D25:1;
		unsigned RXB1D26:1;
		unsigned RXB1D27:1;
	};
} RXB1D2bits_t;

extern volatile RXB1D2bits_t at 0xf58 RXB1D2bits;

extern sfr at 0xf59 RXB1D3;
typedef union {
	struct {
		unsigned RXB1D30:1;
		unsigned RXB1D31:1;
		unsigned RXB1D32:1;
		unsigned RXB1D33:1;
		unsigned RXB1D34:1;
		unsigned RXB1D35:1;
		unsigned RXB1D36:1;
		unsigned RXB1D37:1;
	};
} RXB1D3bits_t;

extern volatile RXB1D3bits_t at 0xf59 RXB1D3bits;

extern sfr at 0xf5a RXB1D4;
typedef union {
	struct {
		unsigned RXB1D40:1;
		unsigned RXB1D41:1;
		unsigned RXB1D42:1;
		unsigned RXB1D43:1;
		unsigned RXB1D44:1;
		unsigned RXB1D45:1;
		unsigned RXB1D46:1;
		unsigned RXB1D47:1;
	};
} RXB1D4bits_t;

extern volatile RXB1D4bits_t at 0xf5a RXB1D4bits;

extern sfr at 0xf5b RXB1D5;
typedef union {
	struct {
		unsigned RXB1D50:1;
		unsigned RXB1D51:1;
		unsigned RXB1D52:1;
		unsigned RXB1D53:1;
		unsigned RXB1D54:1;
		unsigned RXB1D55:1;
		unsigned RXB1D56:1;
		unsigned RXB1D57:1;
	};
} RXB1D5bits_t;

extern volatile RXB1D5bits_t at 0xf5b RXB1D5bits;

extern sfr at 0xf5c RXB1D6;
typedef union {
	struct {
		unsigned RXB1D60:1;
		unsigned RXB1D61:1;
		unsigned RXB1D62:1;
		unsigned RXB1D63:1;
		unsigned RXB1D64:1;
		unsigned RXB1D65:1;
		unsigned RXB1D66:1;
		unsigned RXB1D67:1;
	};
} RXB1D6bits_t;

extern volatile RXB1D6bits_t at 0xf5c RXB1D6bits;

extern sfr at 0xf5d RXB1D7;
typedef union {
	struct {
		unsigned RXB1D70:1;
		unsigned RXB1D71:1;
		unsigned RXB1D72:1;
		unsigned RXB1D73:1;
		unsigned RXB1D74:1;
		unsigned RXB1D75:1;
		unsigned RXB1D76:1;
		unsigned RXB1D77:1;
	};
} RXB1D7bits_t;

extern volatile RXB1D7bits_t at 0xf5d RXB1D7bits;

extern sfr at 0xf5e CANSTATRO1;
typedef union {
	struct {
		unsigned :1;
		unsigned ICODE0:1;
		unsigned ICODE1:1;
		unsigned ICODE2:1;
		unsigned :1;
		unsigned OPMODE0:1;
		unsigned OPMODE1:1;
		unsigned OPMODE2:1;
	};
} CANSTATRO1bits_t;

extern volatile CANSTATRO1bits_t at 0xf5e CANSTATRO1bits;

extern sfr at 0xf60 RXB0CON;
typedef union {
	struct {
		unsigned FILHIT0:1;
		unsigned RXB0DBEN_R:1;
		unsigned RXB0DBEN:1;
		unsigned RXRTRR0:1;
		unsigned :1;
		unsigned RXM0:1;
		unsigned RXM1:1;
		unsigned RXFUL:1;
	};
} RXB0CONbits_t;

extern volatile RXB0CONbits_t at 0xf60 RXB0CONbits;

extern sfr at 0xf61 RXB0SIDH;
typedef union {
	struct {
		unsigned SID3:1;
		unsigned SID4:1;
		unsigned SID5:1;
		unsigned SID6:1;
		unsigned SID7:1;
		unsigned SID8:1;
		unsigned SID9:1;
		unsigned SID10:1;
	};
} RXB0SIDHbits_t;

extern volatile RXB0SIDHbits_t at 0xf61 RXB0SIDHbits;

extern sfr at 0xf62 RXB0SIDL;
typedef union {
	struct {
		unsigned EID16:1;
		unsigned EID17:1;
		unsigned :1;
		unsigned EXID:1;
		unsigned SRR:1;
		unsigned SID0:1;
		unsigned SID1:1;
		unsigned SID2:1;
	};
} RXB0SIDLbits_t;

extern volatile RXB0SIDLbits_t at 0xf62 RXB0SIDLbits;

extern sfr at 0xf63 RXB0EIDH;
typedef union {
	struct {
		unsigned EID8:1;
		unsigned EDI9:1;
		unsigned EID10:1;
		unsigned ED11:1;
		unsigned EID12:1;
		unsigned EID13:1;
		unsigned EID14:1;
		unsigned EID15:1;
	};
} RXB0EIDHbits_t;

extern volatile RXB0EIDHbits_t at 0xf63 RXB0EIDHbits;

extern sfr at 0xf64 RXB0EIDL;
typedef union {
	struct {
		unsigned EID0:1;
		unsigned EID1:1;
		unsigned EID2:1;
		unsigned EID3:1;
		unsigned EID4:1;
		unsigned EID5:1;
		unsigned EID6:1;
		unsigned EID7:1;
	};
} RXB0EIDLbits_t;

extern volatile RXB0EIDLbits_t at 0xf64 RXB0EIDLbits;

extern sfr at 0xf65 RXB0DLC;
typedef union {
	struct {
		unsigned DLC0:1;
		unsigned DLC1:1;
		unsigned DLC2:1;
		unsigned DLC3:1;
		unsigned RESB0:1;
		unsigned RESB1:1;
		unsigned RTR:1;
		unsigned :1;
	};
} RXB0DLCbits_t;

extern volatile RXB0DLCbits_t at 0xf65 RXB0DLCbits;

extern sfr at 0xf66 RXB0D0;
extern sfr at 0xf67 RXB0D1;
extern sfr at 0xf68 RXB0D2;
extern sfr at 0xf69 RXB0D3;
extern sfr at 0xf6a RXB0D4;
extern sfr at 0xf6b RXB0D5;
extern sfr at 0xf6c RXB0D6;
extern sfr at 0xf6d RXB0D7;
extern sfr at 0xf6e CANSTAT;
typedef union {
	struct {
		unsigned :1;
		unsigned ICODE0:1;
		unsigned ICODE1:1;
		unsigned ICODE2:1;
		unsigned :1;
		unsigned OPMODE0:1;
		unsigned OPMODE1:1;
		unsigned OPMODE2:1;
	};
} CANSTATbits_t;

extern volatile CANSTATbits_t at 0xf6e CANSTATbits;

extern sfr at 0xf6f CANCON;
typedef union {
	struct {
		unsigned WIN0:1;
		unsigned WIN1:1;
		unsigned WIN2:1;
		unsigned WIN3:1;
		unsigned ABAT:1;
		unsigned REQOP0:1;
		unsigned REQOP1:1;
		unsigned REQOP2:1;
	};
} CANCONbits_t;

extern volatile CANCONbits_t at 0xf6f CANCONbits;

extern sfr at 0xf70 BRGCON1;
typedef union {
	struct {
		unsigned BRP0:1;
		unsigned BRP1:1;
		unsigned BRP2:1;
		unsigned BRP3:1;
		unsigned BRP4:1;
		unsigned BRP5:1;
		unsigned SJW0:1;
		unsigned SJW1:1;
	};
} BRGCON1bits_t;

extern volatile BRGCON1bits_t at 0xf70 BRGCON1bits;

extern sfr at 0xf71 BRGCON2;
typedef union {
	struct {
		unsigned PRSEG0:1;
		unsigned PRSEG1:1;
		unsigned PRSEG2:1;
		unsigned SEG1PH0:1;
		unsigned SEG1PH1:1;
		unsigned SEG1PH2:1;
		unsigned SAM:1;
		unsigned SEG2PHTS:1;
	};
} BRGCON2bits_t;

extern volatile BRGCON2bits_t at 0xf71 BRGCON2bits;

extern sfr at 0xf72 BRGCON3;
typedef union {
	struct {
		unsigned SEG2PH0:1;
		unsigned SEG2PH1:1;
		unsigned SEG2PH2:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned WAKFIL:1;
		unsigned :1;
	};
} BRGCON3bits_t;

extern volatile BRGCON3bits_t at 0xf72 BRGCON3bits;

extern sfr at 0xf73 CIOCON;
typedef union {
	struct {
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned CANCAP:1;
		unsigned ENDRHI:1;
		unsigned :1;
		unsigned :1;
	};
} CIOCONbits_t;

extern volatile CIOCONbits_t at 0xf73 CIOCONbits;

extern sfr at 0xf74 COMSTAT;
typedef union {
	struct {
		unsigned EWARN:1;
		unsigned RXWARN:1;
		unsigned TXWARN:1;
		unsigned RXBP:1;
		unsigned TXBP:1;
		unsigned TXBO:1;
		unsigned RXB1OVFL:1;
		unsigned RXB0OVFL:1;
	};
} COMSTATbits_t;

extern volatile COMSTATbits_t at 0xf74 COMSTATbits;

extern sfr at 0xf75 RXERRCNT;
typedef union {
	struct {
		unsigned REC0:1;
		unsigned REC1:1;
		unsigned REC2:1;
		unsigned REC3:1;
		unsigned REC4:1;
		unsigned REC5:1;
		unsigned REC6:1;
		unsigned REC7:1;
	};
} RXERRCNTbits_t;

extern volatile RXERRCNTbits_t at 0xf75 RXERRCNTbits;

extern sfr at 0xf76 TXERRCNT;
typedef union {
	struct {
		unsigned TEC0:1;
		unsigned TEC1:1;
		unsigned TEC2:1;
		unsigned TEC3:1;
		unsigned TEC4:1;
		unsigned TEC5:1;
		unsigned TEC6:1;
		unsigned TEC7:1;
	};
} TXERRCNTbits_t;

extern volatile TXERRCNTbits_t at 0xf76 TXERRCNTbits;

extern sfr at 0xf80 PORTA;
typedef union {
	struct {
		unsigned RA0:1;
		unsigned RA1:1;
		unsigned RA2:1;
		unsigned RA3:1;
		unsigned RA4:1;
		unsigned RA5:1;
		unsigned RA6:1;
		unsigned :1;
	};

	struct {
		unsigned AN0:1;
		unsigned AN1:1;
		unsigned AN2:1;
		unsigned AN3:1;
		unsigned :1;
		unsigned AN4:1;
		unsigned OSC2:1;
		unsigned :1;
	};

	struct {
		unsigned :1;
		unsigned :1;
		unsigned VREFM:1;
		unsigned VREFP:1;
		unsigned T0CKI:1;
		unsigned SS:1;
		unsigned CLK0:1;
		unsigned :1;
	};

	struct {
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned LVDIN:1;
		unsigned :1;
		unsigned :1;
	};
} PORTAbits_t;

extern volatile PORTAbits_t at 0xf80 PORTAbits;

extern sfr at 0xf81 PORTB;
typedef union {
	struct {
		unsigned RB0:1;
		unsigned RB1:1;
		unsigned RB2:1;
		unsigned RB3:1;
		unsigned RB4:1;
		unsigned RB5:1;
		unsigned RB6:1;
		unsigned RB7:1;
	};

	struct {
		unsigned INT0:1;
		unsigned INT1:1;
		unsigned INT2:1;
		unsigned INT3:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
	};
} PORTBbits_t;

extern volatile PORTBbits_t at 0xf81 PORTBbits;

extern sfr at 0xf82 PORTC;
typedef union {
	struct {
		unsigned RC0:1;
		unsigned RC1:1;
		unsigned RC2:1;
		unsigned RC3:1;
		unsigned RC4:1;
		unsigned RC5:1;
		unsigned RC6:1;
		unsigned RC7:1;
	};

	struct {
		unsigned T1OSO:1;
		unsigned T1OSI:1;
		unsigned :1;
		unsigned SCK:1;
		unsigned SDI:1;
		unsigned SDO:1;
		unsigned TX:1;
		unsigned RX:1;
	};

	struct {
		unsigned T1CKI:1;
		unsigned CCP2:1;
		unsigned CCP1:1;
		unsigned SCL:1;
		unsigned SDA:1;
		unsigned :1;
		unsigned CK:1;
		unsigned DT:1;
	};
} PORTCbits_t;

extern volatile PORTCbits_t at 0xf82 PORTCbits;

extern sfr at 0xf89 LATA;
typedef union {
	struct {
		unsigned LATA0:1;
		unsigned LATA1:1;
		unsigned LATA2:1;
		unsigned LATA3:1;
		unsigned LATA4:1;
		unsigned LATA5:1;
		unsigned LATA6:1;
		unsigned :1;
	};
} LATAbits_t;

extern volatile LATAbits_t at 0xf89 LATAbits;

extern sfr at 0xf8a LATB;
typedef union {
	struct {
		unsigned LATB0:1;
		unsigned LATB1:1;
		unsigned LATB2:1;
		unsigned LATB3:1;
		unsigned LATB4:1;
		unsigned LATB5:1;
		unsigned LATB6:1;
		unsigned LATB7:1;
	};
} LATBbits_t;

extern volatile LATBbits_t at 0xf8a LATBbits;

extern sfr at 0xf8b LATC;
typedef union {
	struct {
		unsigned LATC0:1;
		unsigned LATC1:1;
		unsigned LATC2:1;
		unsigned LATC3:1;
		unsigned LATC4:1;
		unsigned LATC5:1;
		unsigned LATC6:1;
		unsigned LATC7:1;
	};
} LATCbits_t;

extern volatile LATCbits_t at 0xf8b LATCbits;

extern sfr at 0xf92 TRISA;
typedef union {
	struct {
		unsigned TRISA0:1;
		unsigned TRISA1:1;
		unsigned TRISA2:1;
		unsigned TRISA3:1;
		unsigned TRISA4:1;
		unsigned TRISA5:1;
		unsigned TRISA6:1;
		unsigned :1;
	};
} TRISAbits_t;

extern volatile TRISAbits_t at 0xf92 TRISAbits;

extern sfr at 0xf93 TRISB;
typedef union {
	struct {
		unsigned TRISB0:1;
		unsigned TRISB1:1;
		unsigned TRISB2:1;
		unsigned TRISB3:1;
		unsigned TRISB4:1;
		unsigned TRISB5:1;
		unsigned TRISB6:1;
		unsigned TRISB7:1;
	};
} TRISBbits_t;

extern volatile TRISBbits_t at 0xf93 TRISBbits;

extern sfr at 0xf94 TRISC;
typedef union {
	struct {
		unsigned TRISC0:1;
		unsigned TRISC1:1;
		unsigned TRISC2:1;
		unsigned TRISC3:1;
		unsigned TRISC4:1;
		unsigned TRISC5:1;
		unsigned TRISC6:1;
		unsigned TRISC7:1;
	};
} TRISCbits_t;

extern volatile TRISCbits_t at 0xf94 TRISCbits;

extern sfr at 0xf9d PIE1;
typedef union {
	struct {
		unsigned TMR1IE:1;
		unsigned TMR2IE:1;
		unsigned CCP1IE:1;
		unsigned SSPIE:1;
		unsigned TXIE:1;
		unsigned RCIE:1;
		unsigned ADIE:1;
		unsigned PSPIE:1;
	};
} PIE1bits_t;

extern volatile PIE1bits_t at 0xf9d PIE1bits;

extern sfr at 0xf9e PIR1;
typedef union {
	struct {
		unsigned TMR1IF:1;
		unsigned TMR2IF:1;
		unsigned CCP1IF:1;
		unsigned SSPIF:1;
		unsigned TXIF:1;
		unsigned RCIF:1;
		unsigned ADIF:1;
		unsigned PSPIF:1;
	};
} PIR1bits_t;

extern volatile PIR1bits_t at 0xf9e PIR1bits;

extern sfr at 0xf9f IPR1;
typedef union {
	struct {
		unsigned TMR1IP:1;
		unsigned TMR2IP:1;
		unsigned CCP1IP:1;
		unsigned SSPIP:1;
		unsigned TXIP:1;
		unsigned RCIP:1;
		unsigned ADIP:1;
		unsigned PSPIP:1;
	};
} IPR1bits_t;

extern volatile IPR1bits_t at 0xf9f IPR1bits;

extern sfr at 0xfa0 PIE2;
typedef union {
	struct {
		unsigned CCP2IE:1;
		unsigned TMR3IE:1;
		unsigned LVDIE:1;
		unsigned BCLIE:1;
		unsigned EEIE:1;
		unsigned :1;
		unsigned CMIE:1;
		unsigned :1;
	};
} PIE2bits_t;

extern volatile PIE2bits_t at 0xfa0 PIE2bits;

extern sfr at 0xfa1 PIR2;
typedef union {
	struct {
		unsigned CCP2IF:1;
		unsigned TMR3IF:1;
		unsigned LVDIF:1;
		unsigned BCLIF:1;
		unsigned EEIF:1;
		unsigned :1;
		unsigned CMIF:1;
		unsigned :1;
	};
} PIR2bits_t;

extern volatile PIR2bits_t at 0xfa1 PIR2bits;

extern sfr at 0xfa2 IPR2;
typedef union {
	struct {
		unsigned CCP2IP:1;
		unsigned TMR3IP:1;
		unsigned LVDIP:1;
		unsigned BCLIP:1;
		unsigned EEIP:1;
		unsigned :1;
		unsigned CMIP:1;
		unsigned :1;
	};
} IPR2bits_t;

extern volatile IPR2bits_t at 0xfa2 IPR2bits;

extern sfr at 0xfa3 PIE3;
typedef union {
	struct {
		unsigned RX0IE:1;
		unsigned RX1IE:1;
		unsigned TX0IE:1;
		unsigned TX1IE:1;
		unsigned TX2IE:1;
		unsigned ERRIE:1;
		unsigned WAKIE:1;
		unsigned IVRE:1;
	};
} PIE3bits_t;

extern volatile PIE3bits_t at 0xfa3 PIE3bits;

extern sfr at 0xfa4 PIR3;
typedef union {
	struct {
		unsigned RX0IF:1;
		unsigned RX1IF:1;
		unsigned TX0IF:1;
		unsigned TX1IF:1;
		unsigned TX2IF:1;
		unsigned ERRIF:1;
		unsigned WAKIF:1;
		unsigned IVRF:1;
	};
} PIR3bits_t;

extern volatile PIR3bits_t at 0xfa4 PIR3bits;

extern sfr at 0xfa5 IPR3;
typedef union {
	struct {
		unsigned RX0IP:1;
		unsigned RX1IP:1;
		unsigned TX0IP:1;
		unsigned TX1IP:1;
		unsigned TX2IP:1;
		unsigned ERRIP:1;
		unsigned WAKIP:1;
		unsigned IVRP:1;
	};
} IPR3bits_t;

extern volatile IPR3bits_t at 0xfa5 IPR3bits;

extern sfr at 0xfa6 EECON1;
typedef union {
	struct {
		unsigned RD:1;
		unsigned WR:1;
		unsigned WREN:1;
		unsigned WRERR:1;
		unsigned FREE:1;
		unsigned :1;
		unsigned CFGS:1;
		unsigned EEPGD:1;
	};
} EECON1bits_t;

extern volatile EECON1bits_t at 0xfa6 EECON1bits;

extern sfr at 0xfa7 EECON2;
extern sfr at 0xfa8 EEDATA;
extern sfr at 0xfa9 EEADR;
extern sfr at 0xfab RCSTA;
typedef union {
	struct {
		unsigned RX9D:1;
		unsigned OERR:1;
		unsigned FERR:1;
		unsigned ADDEN:1;
		unsigned CREN:1;
		unsigned SREN:1;
		unsigned RX9:1;
		unsigned SPEN:1;
	};
} RCSTAbits_t;

extern volatile RCSTAbits_t at 0xfab RCSTAbits;

extern sfr at 0xfac TXSTA;
typedef union {
	struct {
		unsigned TX9D:1;
		unsigned TRMT:1;
		unsigned BRGH:1;
		unsigned :1;
		unsigned SYNC:1;
		unsigned TXEN:1;
		unsigned TX9:1;
		unsigned CSRC:1;
	};
} TXSTAbits_t;

extern volatile TXSTAbits_t at 0xfac TXSTAbits;

extern sfr at 0xfad TXREG;
extern sfr at 0xfae RCREG;
extern sfr at 0xfaf SPBRG;
extern sfr at 0xfb1 T3CON;
typedef union {
	struct {
		unsigned TMR3ON:1;
		unsigned TMR3CS:1;
		unsigned T3SYNC:1;
		unsigned T3CCP1:1;
		unsigned T3CKPS0:1;
		unsigned T3CKPS1:1;
		unsigned T3CCP2:1;
		unsigned RD16:1;
	};
} T3CONbits_t;

extern volatile T3CONbits_t at 0xfb1 T3CONbits;

extern sfr at 0xfb2 TMR3L;
extern sfr at 0xfb3 TMR3H;
extern sfr at 0xfbd CCP1CON;
typedef union {
	struct {
		unsigned CCP1M0:1;
		unsigned CCP1M1:1;
		unsigned CCP1M2:1;
		unsigned CCP1M3:1;
		unsigned DCCP1Y:1;
		unsigned DCCP1X:1;
		unsigned :1;
		unsigned :1;
	};
} CCP1CONbits_t;

extern volatile CCP1CONbits_t at 0xfbd CCP1CONbits;

extern sfr at 0xfbe CCPR1L;
extern sfr at 0xfbf CCPR1H;
extern sfr at 0xfc1 ADCON1;
typedef union {
	struct {
		unsigned PCFG0:1;
		unsigned PCFG1:1;
		unsigned PCFG2:1;
		unsigned PCFG3:1;
		unsigned :1;
		unsigned :1;
		unsigned ADCS2:1;
		unsigned ADFM:1;
	};
} ADCON1bits_t;

extern volatile ADCON1bits_t at 0xfc1 ADCON1bits;

extern sfr at 0xfc2 ADCON0;
typedef union {
	struct {
		unsigned ADON:1;
		unsigned :1;
		unsigned GO:1;
		unsigned CHS0:1;
		unsigned CHS1:1;
		unsigned CHS2:1;
		unsigned ADCS0:1;
		unsigned ADCS1:1;
	};
} ADCON0bits_t;

extern volatile ADCON0bits_t at 0xfc2 ADCON0bits;

extern sfr at 0xfc3 ADRESL;
extern sfr at 0xfc4 ADRESH;
extern sfr at 0xfc5 SSPCON2;
typedef union {
	struct {
		unsigned SEN:1;
		unsigned RSEN:1;
		unsigned PEN:1;
		unsigned RCEN:1;
		unsigned ACKEN:1;
		unsigned ACKDT:1;
		unsigned ACKSTAT:1;
		unsigned GCEN:1;
	};
} SSPCON2bits_t;

extern volatile SSPCON2bits_t at 0xfc5 SSPCON2bits;

extern sfr at 0xfc6 SSPCON1;
typedef union {
	struct {
		unsigned SSPM0:1;
		unsigned SSPM1:1;
		unsigned SSPM2:1;
		unsigned SSPM3:1;
		unsigned CKP:1;
		unsigned SSPEN:1;
		unsigned SSPOV:1;
		unsigned WCOL:1;
	};
} SSPCON1bits_t;

extern volatile SSPCON1bits_t at 0xfc6 SSPCON1bits;

extern sfr at 0xfc7 SSPSTAT;
typedef union {
	struct {
		unsigned BF:1;
		unsigned UA:1;
		unsigned R_W:1;
		unsigned S:1;
		unsigned P:1;
		unsigned D_A:1;
		unsigned CKE:1;
		unsigned SMP:1;
	};
} SSPSTATbits_t;

extern volatile SSPSTATbits_t at 0xfc7 SSPSTATbits;

extern sfr at 0xfc8 SSPADD;
extern sfr at 0xfc9 SSPBUF;
extern sfr at 0xfca T2CON;
typedef union {
	struct {
		unsigned T2CKPS0:1;
		unsigned T2CKPS1:1;
		unsigned TMR2ON:1;
		unsigned TOUTPS0:1;
		unsigned TOUTPS1:1;
		unsigned TOUTPS2:1;
		unsigned TOUTPS3:1;
		unsigned :1;
	};
} T2CONbits_t;

extern volatile T2CONbits_t at 0xfca T2CONbits;

extern sfr at 0xfcb PR2;
extern sfr at 0xfcc TMR2;
extern sfr at 0xfcd T1CON;
typedef union {
	struct {
		unsigned TMR1ON:1;
		unsigned TMR1CS:1;
		unsigned NOT_T1SYNC:1;
		unsigned T1OSCEN:1;
		unsigned T1CKPS0:1;
		unsigned T1CKPS1:1;
		unsigned :1;
		unsigned RD16:1;
	};
} T1CONbits_t;

extern volatile T1CONbits_t at 0xfcd T1CONbits;

extern sfr at 0xfce TMR1L;
extern sfr at 0xfcf TMR1H;
extern sfr at 0xfd0 RCON;
typedef union {
	struct {
		unsigned BOR:1;
		unsigned POR:1;
		unsigned PD:1;
		unsigned TO:1;
		unsigned RI:1;
		unsigned :1;
		unsigned :1;
		unsigned IPEN:1;
	};
} RCONbits_t;

extern volatile RCONbits_t at 0xfd0 RCONbits;

extern sfr at 0xfd1 WDTCON;
typedef union {
	struct {
		unsigned SWDTEN:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
	};

	struct {
		unsigned SWDTE:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
	};
} WDTCONbits_t;

extern volatile WDTCONbits_t at 0xfd1 WDTCONbits;

extern sfr at 0xfd2 LVDCON;
typedef union {
	struct {
		unsigned LVDL0:1;
		unsigned LVDL1:1;
		unsigned LVDL2:1;
		unsigned LVDL3:1;
		unsigned LVDEN:1;
		unsigned VRST:1;
		unsigned :1;
		unsigned :1;
	};

	struct {
		unsigned LVV0:1;
		unsigned LVV1:1;
		unsigned LVV2:1;
		unsigned LVV3:1;
		unsigned :1;
		unsigned BGST:1;
		unsigned :1;
		unsigned :1;
	};
} LVDCONbits_t;

extern volatile LVDCONbits_t at 0xfd2 LVDCONbits;

extern sfr at 0xfd3 OSCCON;
typedef union {
	struct {
		unsigned SCS:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
	};
} OSCCONbits_t;

extern volatile OSCCONbits_t at 0xfd3 OSCCONbits;

extern sfr at 0xfd5 T0CON;
extern sfr at 0xfd6 TMR0L;
extern sfr at 0xfd7 TMR0H;
extern sfr at 0xfd8 STATUS;
typedef union {
	struct {
		unsigned C:1;
		unsigned DC:1;
		unsigned Z:1;
		unsigned OV:1;
		unsigned N:1;
		unsigned :1;
		unsigned :1;
		unsigned :1;
	};
} STATUSbits_t;

extern volatile STATUSbits_t at 0xfd8 STATUSbits;

extern sfr at 0xfd9 FSR2L;
extern sfr at 0xfda FSR2H;
extern sfr at 0xfdb PLUSW2;
extern sfr at 0xfdc PREINC2;
extern sfr at 0xfdd POSTDEC2;
extern sfr at 0xfde POSTINC2;
extern sfr at 0xfdf INDF2;
extern sfr at 0xfe0 BSR;
extern sfr at 0xfe1 FSR1L;
extern sfr at 0xfe2 FSR1H;
extern sfr at 0xfe3 PLUSW1;
extern sfr at 0xfe4 PREINC1;
extern sfr at 0xfe5 POSTDEC1;
extern sfr at 0xfe6 POSTINC1;
extern sfr at 0xfe7 INDF1;
extern sfr at 0xfe8 WREG;
extern sfr at 0xfe9 FSR0L;
extern sfr at 0xfea FSR0H;
extern sfr at 0xfeb PLUSW0;
extern sfr at 0xfec PREINC0;
extern sfr at 0xfed POSTDEC0;
extern sfr at 0xfee POSTINC0;
extern sfr at 0xfef INDF0;
extern sfr at 0xff0 INTCON3;
typedef union {
	struct {
		unsigned INT1F:1;
		unsigned :1;
		unsigned :1;
		unsigned INT1E:1;
		unsigned :1;
		unsigned :1;
		unsigned INT1P:1;
		unsigned :1;
	};

	struct {
		unsigned INT1IF:1;
		unsigned :1;
		unsigned :1;
		unsigned INT2IE:1;
		unsigned :1;
		unsigned :1;
		unsigned INT1IP:1;
		unsigned :1;
	};
} INTCON3bits_t;

extern volatile INTCON3bits_t at 0xff0 INTCON3bits;

extern sfr at 0xff1 INTCON2;
typedef union {
	struct {
		unsigned RBIP:1;
		unsigned :1;
		unsigned T0IP:1;
		unsigned :1;
		unsigned :1;
		unsigned INTEDG1:1;
		unsigned INTEDG0:1;
		unsigned RBPU:1;
	};
} INTCON2bits_t;

extern volatile INTCON2bits_t at 0xff1 INTCON2bits;

extern sfr at 0xff2 INTCON;
typedef union {
	struct {
		unsigned RBIF:1;
		unsigned INT0F:1;
		unsigned T0IF:1;
		unsigned RBIE:1;
		unsigned INT0E:1;
		unsigned T0IE:1;
		unsigned PEIE:1;
		unsigned GIE:1;
	};
} INTCONbits_t;

extern volatile INTCONbits_t at 0xff2 INTCONbits;

extern sfr at 0xff3 PRODL;
extern sfr at 0xff4 PRODH;
extern sfr at 0xff5 TABLAT;
extern sfr at 0xff6 TBLPTRL;
extern sfr at 0xff7 TBLPTRH;
extern sfr at 0xff8 TBLPTRU;
extern sfr at 0xff9 PCL;
extern sfr at 0xffa PCLATH;
extern sfr at 0xffb PCLATU;
extern sfr at 0xffc STKPTR;
typedef union {
	struct {
		unsigned STKPTR0:1;
		unsigned STKPTR1:1;
		unsigned STKPTR2:1;
		unsigned STKPTR3:1;
		unsigned STKPTR4:1;
		unsigned :1;
		unsigned STKUNF:1;
		unsigned STKFUL:1;
	};
} STKPTRbits_t;

extern volatile STKPTRbits_t at 0xffc STKPTRbits;

extern sfr at 0xffd TOSL;
extern sfr at 0xffe TOSH;
extern sfr at 0xfff TOSU;


#endif

