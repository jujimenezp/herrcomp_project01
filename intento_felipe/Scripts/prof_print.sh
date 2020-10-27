for N in 20000 50000 100000 250000 500000 750000 1000000 2000000 4000000 6000000; do

    sed -i "/tmax/c $N   #tmax" ../Data/init_data.txt

    for M in 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50; do

        sed -i "/seed/c $M   #seed" ../Data/init_data.txt

        ./p_print.out > data_0.txt

        COUT=$(sed -n 1p data_1.txt | tr -d -c '0-9.' )
        OFSTREAM=$(sed -n 2p data_1.txt | tr -d -c '0-9.' )
        echo -e "$COUT \n$OFSTREAM"

    done > data_2.txt

    echo -n "$N"

    ./stats.x

done > ../Data/prof_print.txt

sed -i "/tmax/c 10000000   #tmax" ../Data/init_data.txt
sed -i "/seed/c 0   #seed" ../Data/init_data.txt

rm data_0.txt data_1.txt data_2.txt ../Data/data_entropy.txt
