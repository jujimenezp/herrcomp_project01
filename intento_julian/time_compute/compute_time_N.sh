tr -d [:alnum:] < data/data_compute_N.txt > data/data_compute_N.txt
for N in 100 200 400 800 1200 1600 2400 3200 4000 5000 6000 8000 10000 20000; do
    sed -i "/nmolecules/c $N   #nmolecules" data/init_data.txt
    /usr/bin/time -ao data/data_compute_N.txt -f "$N \t %e" ./programs/intento1.x
done

sed -i "/nmolecules/c 400   #nmolecules" data/init_data.txt
