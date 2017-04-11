#! /bin/bash

JLinkGDBServer -device atsame70q21 -if swd -speed 12000 -nogui -xc connect.gdb
