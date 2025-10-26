<h1> Aide-mémoire </h1>
General notes for future reference. Our board is NUCLEO-411RE
<h2> Chapter 2 </h2>

<h3> User LED pin connection </h3>
<li> User LD2 -> D13 -> PA5

<h3> User push button connection </h3>
<li> User B1 -> PC13 (pin-2)

<h3> Arduino compatible headers</h3>
<li> User guide, table 16.

<h3> Memory Mapping to find peripheral register addresses</h3>
This is specific to the microprocessor itself, not the board. Look up microprocessor manual.
<li> Peripheral addresses are between 0x4000_0000 - 0x5FFF_FFFF.
<li> Hence, peripheral base address is: 0x4000_0000 (Required to calculate address of the peripherals.)
<h4> Find GPIO port for LED</h4>
<li> APB = Advanced Peripheral Bus (for low bandwidth peripherals), AHB = Advanced High-performance Bus (for high bandwidth peripherals)
<li> GPIOA (GPIO PORTA) registers are in range 0x4002_0000 - 0x4002_03FF
<li> GPIOC (GPIO PORTC) registers are in range 0x4002_0800 - 0x4002_0BFF
<h4> Find clock signal for GPIO port </h4>
<li> To use the peripheral, clock signal has to be enabled first.
<li> RCC peripheral on the same  bus is the clock peripheral, with range: 0x4002_3800 - 0x4002_3BFF
<h4> Find clock register address </h4>
<li> In board reference manual, look for RCC_AHB1ENR (Three part name: RCC + AHB1 + ENR).
<li> It has 0x30 offser from RCC base. Bit-0 enables/disables clock signal to GPIOA.
<li> Clock address = 0x4002_3800 + 0x30 = 0x4002_3830, bit-1 for GPIOA.
<h4> GPIO port mode register </h4>
<li> GPIO pins can be set in input and output modes depending on how they are to be used. This can be set by the GPIO port mode register.
<li> Information is found in the board reference manual. 
<li> GPIO port mode register is set at offset 0x00, i.e. at the beginning of the GPIOA section: 0x4002_0000
<li> In the 32-bit register, two bits make up state for each GPIO pin.
<li> MODER5 controls state of pin PA5, i.e. bits 11,10 neet to be set to 0,1 respectively to be set in output mode.

<h4> GPIO output port data register </h4>
Final step is to know which bit to flip to set/clear the GPIO pin.
<li> The GPIO output port data register is located at offset 0x14 from the GPIO port base
<li> i.e. 0x4002_0000 + 0x14 = 0x4002_0014