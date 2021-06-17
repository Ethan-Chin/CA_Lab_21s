.section .text
.globl draw
.type draw, @function
draw:

	li	a0,	52
	li	a1,	33
	li	a2,	14
	li	a3, 0X01CF
	jal LCD_DrawCircle

	li	a0,	80
	li	a1,	33
	li	a2,	14
	li	a3, 0x0000
	jal LCD_DrawCircle

	li	a0,	108
	li	a1,	33
	li	a2,	14
	li	a3, 0xF800
	jal LCD_DrawCircle

	li	a0,	66
	li	a1,	47
	li	a2,	14
	li	a3, 0xFFE0
	jal LCD_DrawCircle

	li	a0,	94
	li	a1,	47
	li	a2,	14
	li	a3, 0x07E0
	jal LCD_DrawCircle