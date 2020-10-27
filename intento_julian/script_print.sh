echo -e "tmax \t cout time \t ofstream time" > data_seed.txt
for N in 20000 50000 100000 250000 500000 750000 1000000 2000000 4000000; do
    
    PROMC="0"
    PROMO="0"
    
    sed -i "/tmax/c $N   #tmax" ../Data/init_data.txt
    
    for M in 1 3 5 6 7 10 11 21 33 37 40 42 45; do
        sed -i "/seed/c $M   #seed" ../Data/init_data.txt
        
        ./print.x > a.txt
        
        COUT=$(sed -n 2p ../Data/prof_print.txt | tr -d -c '0-9.' )
        PROMC=$(echo "$PROMC+$COUT" | bc -l )
        OFSTREAM=$(sed -n 3p ../Data/prof_print.txt | tr -d -c '0-9.' )
        PROMO=$(echo "$PROMO+$OFSTREAM" | bc -l )
        
        rm a.txt
    done
    
    PROMC=$(echo "$PROMC/13" | bc -l)
    PROMO=$(echo "$PROMO/13" | bc -l)
    
    sed -i "$ a $N \t $PROMC \t $PROMO" data_seed.txt
    
done
