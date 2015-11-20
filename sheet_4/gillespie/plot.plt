set terminal png
set output "plot.png"
set autoscale
set xrange[0:60]
set xlabel "time"
set ylabel "Number of particles"
set key outside;
set key right top;

plot "data/out_x.dat" ps 0.1 title "nx", \
	"data/out_y.dat" ps 0.1 title "ny"
