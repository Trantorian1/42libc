FROM ubuntu:20.04

# install dependencies
RUN apt-get update 
RUN apt-get install -y clang
RUN apt-get install -y wget
RUN apt-get install -y make

# install criterion
RUN wget https://github.com/Snaipe/Criterion/releases/download/v2.4.1/criterion-2.4.1-linux-x86_64.tar.xz
RUN tar -xvf criterion-2.4.1-linux-x86_64.tar.xz
RUN cp -r criterion-2.4.1/lib/* /usr/lib
RUN cp -r criterion-2.4.1/include/* /usr/include
RUN rm -rf criterion-2.4.1-linux-x86_64.tar.xz
RUN rm -rf criterion-2.4.1

WORKDIR /app

ENTRYPOINT ["make"]
