#!/bin/bash

cmake -S . -B ./build
cd ./build
make
./katas/int32_to_ipv4