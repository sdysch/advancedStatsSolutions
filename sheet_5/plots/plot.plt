set terminal png
set output "avg_x_xSq.png"
set autoscale
set xtics 0, 500, 5000
set xlabel "Time"
set ylabel "<x> and <x^2>"
set key outside;
set key right top;
plot "out.dat" ps 0.25 title "<x>", \
	"out2.dat" ps 0.25 title "<x^2>"
