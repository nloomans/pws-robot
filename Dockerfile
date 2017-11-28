FROM debian:stretch

RUN apt-get update
RUN apt-get install -y curl gnupg2
RUN curl -sL https://deb.nodesource.com/setup_8.x | bash -
RUN apt-get install -y nodejs dphys-swapfile build-essential libgmp3-dev golang git python
WORKDIR /project
RUN git clone https://github.com/ethereum/go-ethereum
WORKDIR /project/go-ethereum
RUN make geth
WORKDIR /project
COPY . /project/code
COPY ./start /project/start

RUN mkdir /root/.ethereum
RUN ln -s /root/.ethereum /ethereum

EXPOSE 3000

CMD /project/start
