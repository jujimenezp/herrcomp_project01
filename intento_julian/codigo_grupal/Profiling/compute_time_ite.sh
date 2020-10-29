echo -e "tmax \t computeing time" > Data/data_compute_ite.txt
for N in 20000 50000 100000 250000 500000 750000 1000000 2000000 4000000 6000000 10000000 15000000 20000000; do

    sed -i "/tmax/c $N   #tmax" Data/init_data.txt
    /usr/bin/time -ao Data/data_compute_ite.txt -f "$N \t %e" ./main.x
done

sed -i "/tmax/c 6000000   #tmax" Data/init_data.txt
