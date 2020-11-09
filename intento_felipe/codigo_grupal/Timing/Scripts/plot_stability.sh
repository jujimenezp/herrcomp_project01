for N in 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000; do

    sed -i "/latticesize/c $N   #latticesize" ../Data/init_data.txt

    ./main_stability_0.x

done > Data/data_stability_0.txt

for N in 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000; do

    sed -i "/latticesize/c $N   #latticesize" ../Data/init_data.txt

    ./main_stability_1.x

done > Data/data_stability_1.txt

for N in 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000; do

    sed -i "/latticesize/c $N   #latticesize" ../Data/init_data.txt

    ./main_stability_2.x

done > Data/data_stability_2.txt

for N in 100 150 200 250 300 350 400 450 500 550 600 650 700 750 800 850 900 950 1000; do

    sed -i "/latticesize/c $N   #latticesize" ../Data/init_data.txt

    ./main_stability_3.x

done > Data/data_stability_3.txt

sed -i "/latticesize/c 200   #latticesize" ../Data/init_data.txt
