FROM ubuntu:18.04

RUN apt-get update
RUN apt-get -y install libboost-all-dev && apt -y install g++ && apt-get -y install cmake
RUN apt-get -y install software-properties-common && add-apt-repository ppa:ubuntu-toolchain-r/test
RUN apt-get -y install gcc-9 g++-9
RUN update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9

WORKDIR /hh
COPY . /hh

COPY ./httpd.conf /etc/httpd.conf
COPY ./httptest /var/www/html/httptest


RUN g++ --version
RUN gcc --version

RUN cmake .
RUN make
RUN echo 'document_root /var/www/html/' >> /etc/httpd.conf

EXPOSE 80

CMD ./highload /etc/httpd.conf 80