binwidth=0.05
bin(x,width)=width*floor(x/width)

plot 'out.dat' using (bin($1,binwidth)):(1.0) smooth freq with boxes, 2*exp(-2*x)

set term png
set output "p-val.png"
replot
set term x11

