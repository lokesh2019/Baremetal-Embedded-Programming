FROM debian:trixie
# Basic setup
RUN apt -y update
RUN apt -y install curl build-essential gcc-arm-none-eabi gdb-multiarch openocd sudo

# Setup default user
ENV USER=devel
RUN useradd --create-home -s /bin/bash -m ${USER} && echo "${USER}:${USER}" | chpasswd && usermod -aG sudo ${USER}
USER $USER

# Mount project directory
ENV WORKING_DIR=/home/${USER}/work
ENV PATH=$PATH:/work/tools/rust-1.89.0/bin
COPY . /home/${USER}/work
WORKDIR ${WORKING_DIR}

# Install rust
RUN curl https://sh.rustup.rs -sSf | bash -s -- -y
RUN echo 'source $HOME/.cargo/env' >> $HOME/.bashrc
RUN $HOME/.cargo/bin/rustup target add thumbv7em-none-eabihf

CMD tail -f /dev/null
