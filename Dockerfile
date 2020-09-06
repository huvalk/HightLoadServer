FROM ubuntu:18.04

RUN apt-get update
RUN apt-get -y install libboost-all-dev && apt -y install g++ && apt-get -y install cmake

WORKDIR /hh
COPY . /hh

COPY ./httpd.conf /etc/httpd.conf

RUN cmake .
RUN make

EXPOSE 80

CMD ./highload