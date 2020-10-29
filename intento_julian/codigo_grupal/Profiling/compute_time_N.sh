echo -e "nmolecules \t computing time" > Data/data_compute_N.txt
for N in 100 200 400 800 1200 1600 2401 3136 4096 5041 6084 8100 10000 20164 24964; do
    sed -i "/nmolecules/c $N   #nmolecules" Data/init_data.txt
    /usr/bin/time -ao Data/data_compute_N.txt -f "$N \t %e" ./main.x
done

sed -i "/nmolecules/c 400   #nmolecules" Data/init_data.txt
