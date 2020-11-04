for N in 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000; do

    sed -i "/latticesize/c $N   #latticesize" Data/init_data.txt

    ./main_stability.x

done > Data/data_stability.txt

sed -i "/latticesize/c 200   #latticesize" Data/init_data.txt
