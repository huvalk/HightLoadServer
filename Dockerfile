FROM gcc:latest as build

RUN apt-get update && \
    apt-get install -y \
      libboost-dev libboost-program-options-dev \
      libgtest-all-dev \
      cmake

WORKDIR /hh
COPY . /hh

COPY ./httpd.conf /etc/httpd.conf

RUN cmake . -DCMAKE_CXX_COMPILER=g++
RUN make CXX=g++

EXPOSE 80

CMD ./bin/highload