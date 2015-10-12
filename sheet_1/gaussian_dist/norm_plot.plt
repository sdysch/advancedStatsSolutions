binwidth = 0.01
set boxwidth binwidth
sum = 0

s(x)          = ((sum=sum+1), 0)
bin(x, width) = width*floor(x/width) + binwidth/2.0

plot "out_10.dat" u ($1):(s($1))
plot "out_10.dat" u (bin($1, binwidth)):(1.0/(binwidth*sum)) smooth freq w boxes

set term png
set output "hist_10.png"
replot
set term x11

