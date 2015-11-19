set terminal png
set output "plots.png"
set autoscale
set ylabel "n"
set xlabel "t"
set xrange[0:8]
set key outside;
set key right top;

plot "0.05out.dat" with points title "n0 = 0.05", \
	"0.1out.dat" title "n0 = 0.1", \
	"0.15out.dat" title "n0 = 0.15", \
	"0.2out.dat" title "n0 = 0.2", \
	"0.25out.dat" title "n0 = 0.25", \
	"0.3out.dat" title "n0 = 0.3", \
	"0.35out.dat" title "n0 = 0.35", \
	"0.4out.dat" title "n0 = 0.4", \
	"0.45out.dat" title "n0 = 0.45", \
	"0.5out.dat" title "n0 = 0.5", \
	"0.55out.dat" title "n0 = 0.55", \
	"0.6out.dat" title "n0 = 0.6", \
	"0.65out.dat" title "n0 = 0.65", \
	"0.7out.dat" title "n0 = 0.7", \
	"0.75out.dat" title "n0 = 0.75", \
	"0.8out.dat" title "n0 = 0.8", \
	"0.85out.dat" title "n0 = 0.85", \
	"0.9out.dat" title "n0 = 0.9", \
	"0.95out.dat" title "n0 = 0.95"
