FROM ubuntu:22.04
# main

RUN cd ~ && mkdir Desktop && cd Desktop && apt update && apt install git -y && git clone https://github.com/leon123858/lab0-c.git && cd lab0-c && git checkout master && git pull
RUN apt-get update
RUN apt-get -y upgrade
RUN apt-get -y install build-essential valgrind curl
RUN apt-get -y install cppcheck clang-format aspell colordiff
# (optional)
## vim
RUN apt-get install vim -y

EXPOSE 22
EXPOSE 80