#!/bin/sh

a=0

while [ $a -lt 20 ]
do
	echo $a
	./fractol ju -i &
	PID1=$!
	./fractol man  -i &
	PID2=$!
	./fractol bur -i &
	PID3=$!
	./fractol sier -i &
	PID4=$!
	./fractol new -i &
	PID5=$!
	sleep 1
	a=`expr $a + 1`
	kill $PID1
	kill $PID2
	kill $PID3
	kill $PID4
	kill $PID5
done
