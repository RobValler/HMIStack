#!/bin/bash

cd build
echo -n "Press any key to continue..."
./hmistack &
read -n 1 -s -r
killall -9 hmistack
ps -aux | grep hmistack
