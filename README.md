<h1> Baremetal-Embedded-Programming </h1>
Following this book to learn bare-metal embedded programming in both C and Rust: https://www.packtpub.com/en-us/product/bare-metal-embedded-c-programming-9781835460818 <br>

<h2> Hardware Required </h2>
<li> NUCLEO-F411RE board
<li> 10kΩ potentiometer

<h2> Software setup </h2>
Make sure all the tools other than VS Code are downloaded and extracted to PROJECT_ROOT/tools
<li> IDE: VS Code (Irrelevant as building will happen on Linux cli)
<li> Arm C compiler toolchain: https://developer.arm.com/downloads/-/gnu-rm
<li> Dockerfile installs rust toolchain using rustup.
<li> Download OpenOCD to program the board: https://github.com/xpack-dev-tools/openocd-xpack/releases

<h2> Reference Documents </h2>
<li> NUCLEO-F411 user manual: https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf
<li> STM32F411 datasheet: https://www.st.com/resource/en/datasheet/stm32f411ce.pdf
<li> STM32F411 reference manual: https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
<li> Cortex-M4 generic user guide: https://developer.arm.com/documentation/dui0553/latest/
