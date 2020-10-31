for N in 100 200 300 400 500 600 700 800 900 1000; do

    sed -i "/latticesize/c $N   #latticesize" Data/init_data.txt

    ./main_stability.x

done > Data/data_stability.txt

sed -i "/latticesize/c 200   #latticesize" Data/init_data.txt
