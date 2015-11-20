#!/bin/bash
make clean
make
./gillespie
gnuplot < plot.plt
gnome-open plot.png
