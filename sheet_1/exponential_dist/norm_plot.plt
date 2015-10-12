binwidth = 0.1
set boxwidth binwidth
sum = 0

s(x)          = ((sum=sum+1), 0)
bin(x, width) = width*floor(x/width) + binwidth/2.0

plot "out.dat" u ($1):(s($1))
plot "out.dat" u (bin($1, binwidth)):(1.0/(binwidth*sum)) smooth freq w boxes, 2*exp(-2*x)

set term png
set output "p-val.png"
replot
set term x11

