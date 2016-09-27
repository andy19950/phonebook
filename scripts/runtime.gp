reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:.1]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.1):(0.01):2 with labels title ' ', \
'' using 3:xtic(1) with histogram title 'struct reduction'  , \
'' using ($0+0.1):(0.015):3 with labels title ' ', \
'' using 4:xtic(1) with histogram title 'hash function' , \
'' using ($0+0.4):(0.01):4 with labels title ' '
