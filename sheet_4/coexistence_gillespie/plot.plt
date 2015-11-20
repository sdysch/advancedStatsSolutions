set terminal png
set output "plot.png"
set autoscale
set xtics 0, 500, 5000
set xlabel "Time"
set ylabel "Number / 100"
set key outside;
set key right top;
plot "data/out.dat" ps 1 title "n0 = 0.1", \
	"data/out_0p9.dat" ps 1 title "n0 = 0.9"
