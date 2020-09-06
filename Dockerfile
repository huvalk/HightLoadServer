FROM ubuntu:18.04

RUN apt-get update
RUN apt-get -y install libboost-all-dev && apt -y install g++ && apt-get -y install cmake

WORKDIR /hh
COPY . /hh

COPY ./httpd.conf /etc/httpd.conf


RUN g++ --version
RUN gcc --version

RUN cmake . -DCMAKE_CXX_COMPILER=g++
RUN make CXX=g++

EXPOSE 80

CMD ./bin/highload