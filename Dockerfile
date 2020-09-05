FROM ubuntu:18.04

RUN apt-get update
RUN apt-get -y install libboost-all-dev

WORKDIR ./
COPY . ./


RUN cmake .
RUN make

EXPOSE 80

CMD ./highload