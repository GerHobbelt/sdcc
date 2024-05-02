;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.2.14 # (Linux)
;--------------------------------------------------------
	.module testcode
	.optsdcc -mhc08
	
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
	.area XINIT   (CODE)
	.area CONST   (CODE)
	.area DSEG    (PAG)
	.area OSEG    (PAG, OVR)
	.area XSEG
	.area XISEG
	.area	CODEIVT (ABS)
	.org	0xfffe
	.dw	__sdcc_gs_init_startup

	.area GSINIT0
__sdcc_gs_init_startup:
	ldhx	#0x8000
	txs
	jsr	___sdcc_external_startup
	beq	__sdcc_init_data
	jmp	__sdcc_program_startup
__sdcc_init_data:
; _hc08_genXINIT() start
        ldhx #0
00001$:
        cphx #l_XINIT
        beq  00002$
        lda  s_XINIT,x
        sta  s_XISEG,x
        aix  #1
        bra  00001$
00002$:
; _hc08_genXINIT() end
	.area GSFINAL
	jmp	__sdcc_program_startup

	.area CSEG
__sdcc_program_startup:
	jsr	_main
	bra	.
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _main
;--------------------------------------------------------
; ram data
;--------------------------------------------------------
	.area DSEG    (PAG)
_main_sloc0_1_0:
	.ds 2
_main_sloc1_1_0:
	.ds 2
_main_sloc2_1_0:
	.ds 2
_main_sloc3_1_0:
	.ds 2
;--------------------------------------------------------
; overlayable items in ram
;--------------------------------------------------------
;--------------------------------------------------------
; absolute ram data
;--------------------------------------------------------
	.area IABS    (ABS)
	.area IABS    (ABS)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS)
;--------------------------------------------------------
; initialized external ram data
;--------------------------------------------------------
	.area XISEG
;--------------------------------------------------------
; extended address mode data
;--------------------------------------------------------
	.area XSEG
_main_a_65536_11:
	.ds 2
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'main'
;------------------------------------------------------------
;sloc0                     Allocated with name '_main_sloc0_1_0'
;sloc1                     Allocated with name '_main_sloc1_1_0'
;sloc2                     Allocated with name '_main_sloc2_1_0'
;sloc3                     Allocated with name '_main_sloc3_1_0'
;a                         Allocated with name '_main_a_65536_11'
;b                         Allocated to registers x h 
;n                         Allocated to registers 
;------------------------------------------------------------
;testcode.c:4: int main(){
;	-----------------------------------------
;	 function main
;	-----------------------------------------
;	Register assignment might be sub-optimal.
;	Stack space usage: 0 bytes.
_main:
;testcode.c:5: int a = 1;
	ldhx	#0x0001
	sthx	*_main_sloc0_1_0
;testcode.c:6: int b = 10;
	ldx	#0x0a
	sthx	*_main_sloc1_1_0
;testcode.c:8: while (n > 0) {
	mov	#0x00,*_main_sloc2_1_0
	mov	#0x64,*(_main_sloc2_1_0 + 1)
00101$:
;testcode.c:9: a = a*3+ b;
	lda	*_main_sloc0_1_0
	sta	__mulint_PARM_2
	lda	*(_main_sloc0_1_0 + 1)
	sta	(__mulint_PARM_2 + 1)
;testcode.c:10: b = a*4 + 5*b+ 1;
	pshx
	lda	#0x03
	clrx
	jsr	__mulint
	pshx
	pulh
	pulx
	psha
	lda	*_main_sloc1_1_0
	sta	__mulint_PARM_2
	lda	*(_main_sloc1_1_0 + 1)
	sta	(__mulint_PARM_2 + 1)
	pula
;testcode.c:9: a = a*3+ b;
	psha
	pshx
	pshh
	lda	#0x05
	clrx
	jsr	__mulint
	sta	*(_main_sloc3_1_0 + 1)
	stx	*_main_sloc3_1_0
	pulh
	pulx
	pula
	add	*(_main_sloc1_1_0 + 1)
	psha
	pshh
	pula
	adc	*_main_sloc1_1_0
	tax
;testcode.c:8: while (n > 0) {
	clra
	sub	*(_main_sloc2_1_0 + 1)
	clra
	sbc	*_main_sloc2_1_0
	pula
	bge	00103$
;testcode.c:9: a = a*3+ b;
	stx	*_main_sloc0_1_0
	sta	*(_main_sloc0_1_0 + 1)
;testcode.c:10: b = a*4 + 5*b+ 1;
	psha
	lda	*(_main_sloc0_1_0 + 1)
	ldx	*_main_sloc0_1_0
	lsla
	rolx
	lsla
	rolx
	pshx
	pulh
	tax
	pula
	psha
	txa
	add	*(_main_sloc3_1_0 + 1)
	tax
	pshh
	pula
	adc	*_main_sloc3_1_0
	psha
	pulh
	pula
	aix	#1
	sthx	*_main_sloc1_1_0
;testcode.c:11: n = n-1;
	pshx
	ldhx	*_main_sloc2_1_0
	aix	#-1
	sthx	*_main_sloc2_1_0
	pulx
	bra	00101$
00103$:
;testcode.c:13: a = a*3+ b;
	stx	_main_a_65536_11
	sta	(_main_a_65536_11 + 1)
;testcode.c:14: b = a*4 + 5*b+ 1;
	psha
	lda	(_main_a_65536_11 + 1)
	ldx	_main_a_65536_11
	lsla
	rolx
	lsla
	rolx
	pshx
	pulh
	tax
	pula
	psha
	txa
	add	*(_main_sloc3_1_0 + 1)
	tax
	pshh
	pula
	adc	*_main_sloc3_1_0
	psha
	pulh
	pula
	aix	#1
;testcode.c:15: return a + b;
	txa
	add	(_main_a_65536_11 + 1)
	psha
	pshh
	pula
	adc	_main_a_65536_11
	tax
	pula
;testcode.c:16: }
	rts
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
