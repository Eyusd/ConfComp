# Copyright (c) Open Enclave SDK contributors.
# Licensed under the MIT License.

include ../config.mk

OE_CRYPTO_LIB := mbedtls
CRYPTO_LDFLAGS := $(shell pkg-config oeenclave-$(COMPILER) --variable=${OE_CRYPTO_LIB}libs)

CFLAGS=$(shell pkg-config oeenclave-$(COMPILER) --cflags)
CXXFLAGS=$(shell pkg-config oeenclave-$(CXX_COMPILER) --cflags)
LDFLAGS=$(shell pkg-config oeenclave-$(COMPILER) --libs)
INCDIR=$(shell pkg-config oeenclave-$(COMPILER) --variable=includedir)

all:
	$(MAKE) build
	$(MAKE) keys
	$(MAKE) sign

build:
	@ echo "LDFLAGS used : $(LDFLAGS)"
	@ echo "CRYPTO_LDFLAGS used : $(CRYPTO_LDFLAGS)"
	@ echo "Compilers used: $(CC), $(CXX)"
	oeedger8r ../guess.edl --trusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CXX) -g -c $(CXXFLAGS) -DOE_API_VERSION=2 -std=c++11 enc.cpp guess.cpp
	$(CC) -g -c $(CFLAGS) -DOE_API_VERSION=2 guess_t.c -o guess_t.o
	$(CXX) -o guessenc guess_t.o enc.o guess.o $(LDFLAGS) $(CRYPTO_LDFLAGS)

sign:
	oesign sign -e guessenc -c guess.conf -k private.pem

clean:
	rm -f enc.o guessenc guessenc.signed private.pem public.pem guess_t.o guess_t.h guess_t.c guess_args.h

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem
