tr -d [:alnum:] < data/data_compute_ite.txt > data/data_compute_ite.txt
for N in 20000 50000 100000 250000 500000 750000 1000000 2000000 4000000; do

    sed -i "/niterations/c $N   #niterations" data/init_data.txt
    /usr/bin/time -ao data/data_compute_ite.txt -f "$N \t %e" ./programs/intento1.x
done

sed -i "/niterations/c 1000000   #niterations" data/init_data.txt
