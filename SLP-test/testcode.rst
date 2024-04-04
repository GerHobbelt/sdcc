                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ISO C Compiler 
                              3 ; Version 4.2.14 # (Linux)
                              4 ;--------------------------------------------------------
                              5 	.module testcode
                              6 	.optsdcc -mhc08
                              7 	
                              8 	.area HOME    (CODE)
                              9 	.area GSINIT0 (CODE)
                             10 	.area GSINIT  (CODE)
                             11 	.area GSFINAL (CODE)
                             12 	.area CSEG    (CODE)
                             13 	.area XINIT   (CODE)
                             14 	.area CONST   (CODE)
                             15 	.area DSEG    (PAG)
                             16 	.area OSEG    (PAG, OVR)
                             17 	.area XSEG
                             18 	.area XISEG
                             19 	.area	CODEIVT (ABS)
   FFFFFFFE                      20 	.org	0xfffe
   FFFFFFFEr00r00                21 	.dw	__sdcc_gs_init_startup
                             22 
                             23 	.area GSINIT0
   FFFE                      24 __sdcc_gs_init_startup:
   FFFE 80 00 00      [ 3]   25 	ldhx	#0x8000
   8000 94            [ 2]   26 	txs
   8000 45 80 00      [ 5]   27 	jsr	___sdcc_external_startup
   8003 94 CD         [ 3]   28 	beq	__sdcc_init_data
   8005 80 FE 27      [ 3]   29 	jmp	__sdcc_program_startup
   000C                      30 __sdcc_init_data:
                             31 ; _hc08_genXINIT() start
   8008 03 CC 80      [ 3]   32         ldhx #0
   000F                      33 00001$:
   800B 21r00r00      [ 3]   34         cphx #l_XINIT
   800C 27 0A         [ 3]   35         beq  00002$
   800C 45 00 00      [ 4]   36         lda  s_XINIT,x
   800F D7r00r00      [ 4]   37         sta  s_XISEG,x
   800F 65 00         [ 2]   38         aix  #1
   8011 00 27         [ 3]   39         bra  00001$
   001E                      40 00002$:
                             41 ; _hc08_genXINIT() end
                             42 	.area GSFINAL
   8013 0A D6 81      [ 3]   43 	jmp	__sdcc_program_startup
                             44 
                             45 	.area CSEG
   0000                      46 __sdcc_program_startup:
   8016 00 D7 00      [ 5]   47 	jsr	_main
   8019 8C AF         [ 3]   48 	bra	.
                             49 ;--------------------------------------------------------
                             50 ; Public variables in this module
                             51 ;--------------------------------------------------------
                             52 	.globl _main
                             53 ;--------------------------------------------------------
                             54 ; ram data
                             55 ;--------------------------------------------------------
                             56 	.area DSEG    (PAG)
   0000                      57 _main_sloc0_1_0:
   0000                      58 	.ds 2
   0002                      59 _main_sloc1_1_0:
   0002                      60 	.ds 2
   0004                      61 _main_sloc2_1_0:
   0004                      62 	.ds 2
   0006                      63 _main_sloc3_1_0:
   0006                      64 	.ds 2
                             65 ;--------------------------------------------------------
                             66 ; overlayable items in ram
                             67 ;--------------------------------------------------------
                             68 ;--------------------------------------------------------
                             69 ; absolute ram data
                             70 ;--------------------------------------------------------
                             71 	.area IABS    (ABS)
                             72 	.area IABS    (ABS)
                             73 ;--------------------------------------------------------
                             74 ; absolute external ram data
                             75 ;--------------------------------------------------------
                             76 	.area XABS    (ABS)
                             77 ;--------------------------------------------------------
                             78 ; initialized external ram data
                             79 ;--------------------------------------------------------
                             80 	.area XISEG
                             81 ;--------------------------------------------------------
                             82 ; extended address mode data
                             83 ;--------------------------------------------------------
                             84 	.area XSEG
   0000                      85 _main_a_65536_11:
   0000                      86 	.ds 2
                             87 ;--------------------------------------------------------
                             88 ; global & static initialisations
                             89 ;--------------------------------------------------------
                             90 	.area HOME    (CODE)
                             91 	.area GSINIT  (CODE)
                             92 	.area GSFINAL (CODE)
                             93 	.area GSINIT  (CODE)
                             94 ;--------------------------------------------------------
                             95 ; Home
                             96 ;--------------------------------------------------------
                             97 	.area HOME    (CODE)
                             98 	.area HOME    (CODE)
                             99 ;--------------------------------------------------------
                            100 ; code
                            101 ;--------------------------------------------------------
                            102 	.area CSEG    (CODE)
                            103 ;------------------------------------------------------------
                            104 ;Allocation info for local variables in function 'main'
                            105 ;------------------------------------------------------------
                            106 ;sloc0                     Allocated with name '_main_sloc0_1_0'
                            107 ;sloc1                     Allocated with name '_main_sloc1_1_0'
                            108 ;sloc2                     Allocated with name '_main_sloc2_1_0'
                            109 ;sloc3                     Allocated with name '_main_sloc3_1_0'
                            110 ;a                         Allocated with name '_main_a_65536_11'
                            111 ;b                         Allocated to registers x h 
                            112 ;n                         Allocated to registers 
                            113 ;------------------------------------------------------------
                            114 ;testcode.c:4: int main(){
                            115 ;	-----------------------------------------
                            116 ;	 function main
                            117 ;	-----------------------------------------
                            118 ;	Register assignment might be sub-optimal.
                            119 ;	Stack space usage: 0 bytes.
   0005                     120 _main:
                            121 ;testcode.c:5: int a = 1;
   801B 01 20 F1      [ 3]  122 	ldhx	#0x0001
   801E 35*00         [ 4]  123 	sthx	*_main_sloc0_1_0
                            124 ;testcode.c:6: int b = 10;
   801E CC 80         [ 2]  125 	ldx	#0x0a
   8020 21*02         [ 4]  126 	sthx	*_main_sloc1_1_0
                            127 ;testcode.c:8: while (n > 0) {
   8021 6E 00*04      [ 4]  128 	mov	#0x00,*_main_sloc2_1_0
   8021 CD 80 26      [ 4]  129 	mov	#0x64,*(_main_sloc2_1_0 + 1)
   0014                     130 00101$:
                            131 ;testcode.c:9: a = a*3+ b;
   8024 20 FE         [ 3]  132 	lda	*_main_sloc0_1_0
   0080 C7r00r00      [ 4]  133 	sta	__mulint_PARM_2
   0080 B6*01         [ 3]  134 	lda	*(_main_sloc0_1_0 + 1)
   0082 C7r00r01      [ 4]  135 	sta	(__mulint_PARM_2 + 1)
                            136 ;testcode.c:10: b = a*4 + 5*b+ 1;
   0082 89            [ 2]  137 	pshx
   0084 A6 03         [ 2]  138 	lda	#0x03
   0084 5F            [ 1]  139 	clrx
   0086 CDr00r00      [ 5]  140 	jsr	__mulint
   0086 89            [ 2]  141 	pshx
   0088 8A            [ 2]  142 	pulh
   0088 88            [ 2]  143 	pulx
   8026 87            [ 2]  144 	psha
   8026 45 00         [ 3]  145 	lda	*_main_sloc1_1_0
   8028 01 35 80      [ 4]  146 	sta	__mulint_PARM_2
   802B AE 0A         [ 3]  147 	lda	*(_main_sloc1_1_0 + 1)
   802D 35 82 6E      [ 4]  148 	sta	(__mulint_PARM_2 + 1)
   8030 00            [ 2]  149 	pula
                            150 ;testcode.c:9: a = a*3+ b;
   8031 84            [ 2]  151 	psha
   8032 6E            [ 2]  152 	pshx
   8033 64            [ 2]  153 	pshh
   8034 85 05         [ 2]  154 	lda	#0x05
   8035 5F            [ 1]  155 	clrx
   8035 B6 80 C7      [ 5]  156 	jsr	__mulint
   8038 00 8A         [ 3]  157 	sta	*(_main_sloc3_1_0 + 1)
   803A B6 81         [ 3]  158 	stx	*_main_sloc3_1_0
   803C C7            [ 2]  159 	pulh
   803D 00            [ 2]  160 	pulx
   803E 8B            [ 2]  161 	pula
   803F 89 A6         [ 3]  162 	add	*(_main_sloc1_1_0 + 1)
   8041 03            [ 2]  163 	psha
   8042 5F            [ 2]  164 	pshh
   8043 CD            [ 2]  165 	pula
   8044 80 D1         [ 3]  166 	adc	*_main_sloc1_1_0
   8046 89            [ 1]  167 	tax
                            168 ;testcode.c:8: while (n > 0) {
   8047 8A            [ 1]  169 	clra
   8048 88 87         [ 3]  170 	sub	*(_main_sloc2_1_0 + 1)
   804A B6            [ 1]  171 	clra
   804B 82 C7         [ 3]  172 	sbc	*_main_sloc2_1_0
   804D 00            [ 2]  173 	pula
   804E 8A B6         [ 3]  174 	bge	00103$
                            175 ;testcode.c:9: a = a*3+ b;
   8050 83 C7         [ 3]  176 	stx	*_main_sloc0_1_0
   8052 00 8B         [ 3]  177 	sta	*(_main_sloc0_1_0 + 1)
                            178 ;testcode.c:10: b = a*4 + 5*b+ 1;
   8054 86            [ 2]  179 	psha
   8055 87 89         [ 3]  180 	lda	*(_main_sloc0_1_0 + 1)
   8057 8B A6         [ 3]  181 	ldx	*_main_sloc0_1_0
   8059 05            [ 1]  182 	lsla
   805A 5F            [ 1]  183 	rolx
   805B CD            [ 1]  184 	lsla
   805C 80            [ 1]  185 	rolx
   805D D1            [ 2]  186 	pshx
   805E B7            [ 2]  187 	pulh
   805F 87            [ 1]  188 	tax
   8060 BF            [ 2]  189 	pula
   8061 86            [ 2]  190 	psha
   8062 8A            [ 1]  191 	txa
   8063 88 86         [ 3]  192 	add	*(_main_sloc3_1_0 + 1)
   8065 BB            [ 1]  193 	tax
   8066 83            [ 2]  194 	pshh
   8067 87            [ 2]  195 	pula
   8068 8B 86         [ 3]  196 	adc	*_main_sloc3_1_0
   806A B9            [ 2]  197 	psha
   806B 82            [ 2]  198 	pulh
   806C 97            [ 2]  199 	pula
   806D 4F B0         [ 2]  200 	aix	#1
   806F 85 4F         [ 4]  201 	sthx	*_main_sloc1_1_0
                            202 ;testcode.c:11: n = n-1;
   8071 B2            [ 2]  203 	pshx
   8072 84 86         [ 4]  204 	ldhx	*_main_sloc2_1_0
   8074 90 2B         [ 2]  205 	aix	#-1
   8076 BF 80         [ 4]  206 	sthx	*_main_sloc2_1_0
   8078 B7            [ 2]  207 	pulx
   8079 81 87         [ 3]  208 	bra	00101$
   0080                     209 00103$:
                            210 ;testcode.c:13: a = a*3+ b;
   807B B6 81 BE      [ 4]  211 	stx	_main_a_65536_11
   807E 80 48 59      [ 4]  212 	sta	(_main_a_65536_11 + 1)
                            213 ;testcode.c:14: b = a*4 + 5*b+ 1;
   8081 48            [ 2]  214 	psha
   8082 59 89 8A      [ 4]  215 	lda	(_main_a_65536_11 + 1)
   8085 97 86 87      [ 4]  216 	ldx	_main_a_65536_11
   8088 9F            [ 1]  217 	lsla
   8089 BB            [ 1]  218 	rolx
   808A 87            [ 1]  219 	lsla
   808B 97            [ 1]  220 	rolx
   808C 8B            [ 2]  221 	pshx
   808D 86            [ 2]  222 	pulh
   808E B9            [ 1]  223 	tax
   808F 86            [ 2]  224 	pula
   8090 87            [ 2]  225 	psha
   8091 8A            [ 1]  226 	txa
   8092 86 AF         [ 3]  227 	add	*(_main_sloc3_1_0 + 1)
   8094 01            [ 1]  228 	tax
   8095 35            [ 2]  229 	pshh
   8096 82            [ 2]  230 	pula
   8097 89 55         [ 3]  231 	adc	*_main_sloc3_1_0
   8099 84            [ 2]  232 	psha
   809A AF            [ 2]  233 	pulh
   809B FF            [ 2]  234 	pula
   809C 35 84         [ 2]  235 	aix	#1
                            236 ;testcode.c:15: return a + b;
   809E 88            [ 1]  237 	txa
   809F 20 94r01      [ 4]  238 	add	(_main_a_65536_11 + 1)
   80A1 87            [ 2]  239 	psha
   80A1 CF            [ 2]  240 	pshh
   80A2 00            [ 2]  241 	pula
   80A3 88 C7 00      [ 4]  242 	adc	_main_a_65536_11
   80A6 89            [ 1]  243 	tax
   80A7 87            [ 2]  244 	pula
                            245 ;testcode.c:16: }
   80A8 C6            [ 4]  246 	rts
                            247 	.area CSEG    (CODE)
                            248 	.area CONST   (CODE)
                            249 	.area XINIT   (CODE)
                            250 	.area CABS    (ABS,CODE)
