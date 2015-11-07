set terminal postscript eps color enhanced size 10,5
set output 'plot.eps';
set multiplot layout 1, 2;
set title "pi estimate"
set xlabel "Iterations"
set ylabel "Pi estimation"
plot "out_normal.dat" w lp
set title "pi estimate normalised by actual pi"
set xlabel "Iterations"
set ylabel "Pi estimation divided by pi"
plot "out_div_pi.dat" w lp
unset multiplot
