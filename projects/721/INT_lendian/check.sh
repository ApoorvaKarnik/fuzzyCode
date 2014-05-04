#!/bin/bash

mkdir $1

for i in gcc gzip parser twolf vortex
do 	
	cd $i
	mkdir ../$1/$i
        rm -rf mt.*
	env -i sim_little -a -d -Z1000000000 -z100000000 job
	env -i sim_little -a  -Z1000000000 -z100000000 job
	env -i sim_little  -Z1000000000 -z100000000 job
	#diff ../out/out.$i-perfect ../p$i >> ../Results
	cp mt.* ../$1/$i/

	echo ==================================================== 
	cd .. 
done

cd go
  rm -rf mt.*
  env -i sim_little -a -d  job
  env -i sim_little -a job
  env -i sim_little  job
  mkdir ../$1/$i
  cp mt.* ../$1/$i  
cd ..

echo ======================================================>> Results
echo ===============       The    End          ============>> Results
echo ======================================================>> Results
