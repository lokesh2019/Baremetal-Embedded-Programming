<h1> Baremetal-Embedded-Programming </h1>
Following this book to learn bare-metal embedded programming in both C and Rust: https://www.packtpub.com/en-us/product/bare-metal-embedded-c-programming-9781835460818 <br>

<h2> Hardware Required </h2>
<li> NUCLEO-F411RE board
<li> 10kΩ potentiometer

<h2> Software setup </h2>
Make sure all the tools other than VS Code are downloaded and extracted to PROJECT_ROOT/tools
<li> IDE: VS Code (Irrelevant as building will happen on Linux cli)
<li> Docker builder will take care of all the required tools.

<h2> Reference Documents </h2>
<li> NUCLEO-F411 user manual: https://www.st.com/resource/en/user_manual/um1724-stm32-nucleo64-boards-mb1136-stmicroelectronics.pdf
<li> STM32F411 datasheet: https://www.st.com/resource/en/datasheet/stm32f411ce.pdf
<li> STM32F411 reference manual: https://www.st.com/resource/en/reference_manual/rm0383-stm32f411xce-advanced-armbased-32bit-mcus-stmicroelectronics.pdf
<li> Cortex-M4 generic user guide: https://developer.arm.com/documentation/dui0553/latest/


<h2> Build instructions </h2>
<h3> Build docker container if not built already </h3>
<li> Build container (once only): `docker build -t baremetal-builder:latest .`
<li> Run container: `docker run -it --privileged -v $(pwd):/work -w /work baremetal-builder:latest bash` (The container is privileged to access host's devices. It can be restricted to specific devices but meh.)
<li> To join the same container from another tab, `docker exec -it $COINTAINER_NAME bash` (This is required to connect to the local GDB server running inside the container)
<li> Make all binaries with one command:

    make all

<h2> To load application on board</h2>
<li> In the build container, start GDB server in the container (password:devel): 

    sudo openocd -f /usr/share/openocd/scripts/board/st_nucleo_f4.cfg
<li> Open another terminal window and join the SAME container
<li> Connect to the local GDB server. This also helps debugging the code if neeeded. Press "Ctrl+X 2" to swich GDB views .

    gdb-multiarch -tui $ABSOLUTE_PATH_TO_ELF_FILE
    target remote localhost:3333
    monitor reset halt
    load
    continue
