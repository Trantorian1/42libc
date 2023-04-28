FROM ubuntu:20.04

# install dependencies
RUN apt-get update 
RUN apt-get install -y clang && \
    apt-get install -y wget && \
	apt-get install -y make

# install criterion
RUN wget https://github.com/Snaipe/Criterion/releases/download/v2.4.1/criterion-2.4.1-linux-x86_64.tar.xz && \
    tar -xvf criterion-2.4.1-linux-x86_64.tar.xz && \
	cp -r criterion-2.4.1/lib/* /usr/lib && \
	cp -r criterion-2.4.1/include/* /usr/include && \
	rm -rf criterion-2.4.1-linux-x86_64.tar.xz && \
	rm -rf criterion-2.4.1

WORKDIR /app

ENTRYPOINT ["make"]
