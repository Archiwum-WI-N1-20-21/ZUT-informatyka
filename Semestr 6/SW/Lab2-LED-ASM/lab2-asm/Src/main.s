//.thumb	// Cortex-M4 works in THUMB mode, check whether it is required

// RM0090 - Reference Manual - (...) STM32F407/417 (...) advanced ARM-based 32 MCUs
.equ PERIPHERAL_BASE,		(0x40000000)	// Base addres for peripheral modules

.equ AHB_OFFSET,			(0x00020000)	// Advanced High-performance BUS offset
.equ RCC_F4_OFFSET,			(0x00023800)	// Reset and Clock Control offset
.equ GPIOD_OFFSET,			(0x00000C00)	// GPIO port D offset
.equ RCC_AHB1ENR_OFFSET,	(0x00000030)	// AHB peripheral clock enable register (RCC_AHB1ENR) offset

.equ MODER_OFFSET,			(0x00000000)	// Mode register
.equ OTYPER_OFFSET,			(0x00000004)	// Output Type register offset
.equ OSPEEDR_OFFSET,		(0x00000008)	// Output Speed register offset
.equ PUPDR_OFFSET,			(0x0000000C)	// Pull-up Pull-down register offset
.equ ODR_OFFSET,			(0x00000014)	// Output Data register offset

.equ RCC_AHB1ENR,			(PERIPHERAL_BASE + RCC_F4_OFFSET + RCC_AHB1ENR_OFFSET)	// RCC address
.equ AHB_BASE,				(PERIPHERAL_BASE + AHB_OFFSET)							// AHB address
.equ GPIOD_BASE,			(AHB_BASE + GPIOD_OFFSET)								// Port D base address

.equ GPIOD_MODER,			(GPIOD_BASE + MODER_OFFSET)		// Mode register for PORTD
.equ GPIOD_OTYPER,			(GPIOD_BASE + OTYPER_OFFSET)	// Output Type register for PORTD
.equ GPIOD_OSPEEDR,			(GPIOD_BASE + OSPEEDR_OFFSET)	// Output Speed register for PORTD
.equ GPIOD_PUPDR,			(GPIOD_BASE + PUPDR_OFFSET)		// Pull-up Pull-down register for PORTD
.equ GPIOD_ODR,				(GPIOD_BASE + ODR_OFFSET)		// Output Data register for PORTD

.equ LOOP_DELAY,			(0x00200000)	// Delay loop counter

// Set main function as global for linker
.global main

// Vector table
//.word               0x20001000	// Vector #0 - Stack pointer init value (0x20000000 is RAM address and 0x1000 is 4kB size, stack grows "downwards")
//.word               main        // Vector #1 - Reset vector - code start
                                // Vector #3..#n - other innterrupts vectors, not used in this code

//.thumb_func                		@ Force the assembler to call this function in Thumb mode, that means the least significant bit in address is set
                        		@ Using this bit, the ARM core knows whether is jumping to the ARM or Thumb code, Cortex supports only Thumb
                        		@ Also you can use ".type    _start, %function"
main:
	LDR		R1,  =RCC_AHB1ENR	// RCC enable for PORTD on AHB. Load RCC address to register R1
	LDR		R0,  [R1]			// Read current value from RCC_AHB1ENR (using address in register R1)
	LDR		R2,  =(1 << 3)		// Prepare the immediate value in R2 (3rd bit should be set for PORTD)
	ORR		R0,  R2				// ORR with previously read value
	STR		R0,  [R1]			// Store new value to RCC_AHB1ENR

	LDR		R1,  =GPIOD_MODER	// Similar as above but for MODER
	LDR		R0,  [R1]
	LDR		R2,  =0x55000000
	ORR		R0,  R2
	LDR		R2,  =0x55FFFFFF	// For readability should be replaced by (x << n) statement
	AND		R0,  R2
	STR		R0,  [R1]

	LDR		R1,  =GPIOD_OTYPER	// Similar as above but for OTYPER
	LDR		R0,  [R1]
	LDR		R2,  =0xFFFF0FFF
	AND		R0,  R2
	STR		R0,  [R1]

	LDR		R1,  =GPIOD_OSPEEDR	// Similar as above but for OSPEEDR
	LDR		R0,  [R1]
	LDR		R2,  =0x00FFFFFF
	AND		R0,  R2
	STR		R0,  [R1]

	LDR		R1,  =GPIOD_PUPDR	// Similar as above but for PUPDR
	LDR		R0,  [R1]
	LDR		R2,  =0x00FFFFFF
	AND		R0,  R2
	STR		R0,  [R1]

loop:

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delay1:
    CBZ		R2,  led_ON1			// delay loop
    SUB		R2,  R2, #1
    B 	    delay1

led_ON1:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0x00001000
    ORR		R0,  R2
    STR		R0,  [R1]

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delay2:
    CBZ		R2,  led_ON2			// delay loop
    SUB		R2,  R2, #1
    B 	    delay2

led_ON2:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0x00002000
    ORR		R0,  R2
    STR		R0,  [R1]

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delay3:
    CBZ		R2,  led_ON3			// delay loop
    SUB		R2,  R2, #1
    B 	    delay3

led_ON3:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0x00004000
    ORR		R0,  R2
    STR		R0,  [R1]

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delay4:
    CBZ		R2,  led_ON4			// delay loop
    SUB		R2,  R2, #1
    B 	    delay4

led_ON4:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0x0000F000
    ORR		R0,  R2
    STR		R0,  [R1]

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delayOFF1:
    CBZ		R2,  led_OFF1
    SUB		R2,  R2, #1
    B		delayOFF1

led_OFF1:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0xFFFEFFF
    AND		R0,  R2
    STR		R0,  [R1]

   	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delayOFF2:
    CBZ		R2,  led_OFF2
    SUB		R2,  R2, #1
    B		delayOFF2

led_OFF2:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0xFFFFCFFF
    AND		R0,  R2
    STR		R0,  [R1]

    LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delayOFF3:
    CBZ		R2,  led_OFF3
    SUB		R2,  R2, #1
    B		delayOFF3

led_OFF3:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0xFFFF9FFF
    AND		R0,  R2
    STR		R0,  [R1]

	LDR		R2,  =LOOP_DELAY	// Set initial delay counter

delayOFF4:
    CBZ		R2,  led_OFF4
    SUB		R2,  R2, #1
    B		delayOFF4

led_OFF4:
    LDR		R1,  =GPIOD_ODR
    LDR		R0,  [R1]
    LDR		R2,  =0xFFFF0FFF
    AND		R0,  R2
    STR		R0,  [R1]

	B		loop				// infinite loop
