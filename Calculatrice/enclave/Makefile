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
	oeedger8r ../calc.edl --trusted \
		--search-path $(INCDIR) \
		--search-path $(INCDIR)/openenclave/edl/sgx
	$(CXX) -g -c $(CXXFLAGS) -DOE_API_VERSION=2 -std=c++11 enc.cpp calc.cpp
	$(CC) -g -c $(CFLAGS) -DOE_API_VERSION=2 calc_t.c -o calc_t.o
	$(CXX) -o calcenc calc_t.o enc.o calc.o $(LDFLAGS) $(CRYPTO_LDFLAGS)

sign:
	oesign sign -e calcenc -c calc.conf -k private.pem

clean:
	rm -f enc.o calcenc calcenc.signed private.pem public.pem calc_t.o calc_t.h calc_t.c calc_args.h calc.o

keys:
	openssl genrsa -out private.pem -3 3072
	openssl rsa -in private.pem -pubout -out public.pem