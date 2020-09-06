FROM ubuntu:18.04

RUN apt-get update
RUN apt-get -y install libboost-all-dev && apt -y install g++ && apt-get -y install cmake

WORKDIR ./
COPY . ./

COPY ./httpd.conf /etc/httpd.conf

RUN cmake .
RUN make

EXPOSE 80

CMD ./highload