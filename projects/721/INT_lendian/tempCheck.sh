#!/bin/bash
rm -rf Results
cd go
echo For $i >>../Results
env -i sim_little -P -o job>../p$i
diff ../out/out.$i-perfect ../p$i >> ../Results
rm rf ../p$i
cd ..
for i in gcc gzip parser twolf vortex
do 	
	cd $i
	echo For $i >>../Results
	env -i sim_little -P -o -Z1000000000 -z100000000 job>../p$i
	diff ../out/out.$i-perfect ../p$i >> ../Results
	rm rf ../p$i
	echo ==================================================== >>../Results
	cd .. 
done
echo ======================================================>> Results
echo ===============      Now for real         ============>> Results
echo ======================================================>> Results
cd go
echo For $i >>../Results
env -i sim_little -o job>../p$i
diff ../out/out.$i-perfect ../p$i >> ../Results
rm rf ../p$i
cd ..
for i in gcc gzip parser twolf vortex
do 	
	cd $i
	echo For $i >>../Results
	env -i sim_little -P -o -Z1000000000 -z100000000 job>../r$i
	diff ../out/out.$i-real ../r$i >> ../Results
	rm rf ../r$i
	echo ==================================================== >>../Results
	cd ..
done 
